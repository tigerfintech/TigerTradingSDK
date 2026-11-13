//
//  TBDemoQuoteProvider.m
//  TigerQuoteSDK
//

#import "TBDemoQuoteProvider.h"

#import <TBBaseKit/TBWeakProxy.h>

/// 模拟行情长连接的推送间隔
static NSTimeInterval const kTBDemoQuotePushInterval = 1.5;

@interface TBDemoQuoteProvider ()

@property (nonatomic, copy) TBDemoQuoteTypeProvider quoteTypeProvider;
/// 模拟行情长连接的推送定时器，key 为 TigerTradingSDKQuoteComponentType 装箱值
@property (nonatomic, strong) NSMutableDictionary<NSNumber *, NSTimer *> *quoteSubscriptionTimers;

@end

@implementation TBDemoQuoteProvider

- (instancetype)initWithQuoteTypeProvider:(TBDemoQuoteTypeProvider)quoteTypeProvider {
    self = [super init];
    if (self) {
        _quoteTypeProvider = [quoteTypeProvider copy];
    }
    return self;
}

- (void)dealloc {
    for (NSTimer *timer in _quoteSubscriptionTimers.allValues) {
        [timer invalidate];
    }
}

- (NSArray<TigerTradingContractQuoteModel *> *)quotesForContracts:(NSArray<TigerTradingContractInfoModel *> *)contracts {
    return [self mockQuotesForContracts:contracts component:NSNotFound];
}

- (void)subscribeContracts:(NSArray<TigerTradingContractInfoModel *> *)contracts
                 component:(TigerTradingSDKQuoteComponentType)component
                  callback:(TBDemoQuoteCallback)callback {
    // 同一个 component 重复订阅时，先把上一轮推送停掉，避免叠加
    [self stopQuotePushForComponent:component];
    if (contracts.count == 0 || callback == nil) {
        return;
    }

    // 订阅后先立即回推一次，随后由定时器模拟长连接按间隔持续推送。
    // 真实接入这里应把 callback 按 component 存起来，每次自己的长连接收到推送时调用一次
    callback([self mockQuotesForContracts:contracts component:component]);

    NSTimer *timer = [NSTimer scheduledTimerWithTimeInterval:kTBDemoQuotePushInterval
                                                      target:[TBWeakProxy proxyWithTarget:self]
                                                    selector:@selector(handleQuotePushTimer:)
                                                    userInfo:@{@"contracts": contracts,
                                                               @"callback": [callback copy],
                                                               @"component": @(component)}
                                                     repeats:YES];
    self.quoteSubscriptionTimers[@(component)] = timer;
}

- (void)unsubscribeContracts:(NSArray<TigerTradingContractInfoModel *> *)contracts
                   component:(TigerTradingSDKQuoteComponentType)component {
    [self stopQuotePushForComponent:component];
}

- (void)handleQuotePushTimer:(NSTimer *)timer {
    NSArray<TigerTradingContractInfoModel *> *contracts = timer.userInfo[@"contracts"];
    TBDemoQuoteCallback callback = timer.userInfo[@"callback"];
    NSNumber *component = timer.userInfo[@"component"];
    if (callback) {
        callback([self mockQuotesForContracts:contracts component:component.integerValue]);
    }
}

- (void)stopQuotePushForComponent:(TigerTradingSDKQuoteComponentType)component {
    NSTimer *timer = self.quoteSubscriptionTimers[@(component)];
    if (timer) {
        [timer invalidate];
        [self.quoteSubscriptionTimers removeObjectForKey:@(component)];
    }
}

- (NSMutableDictionary<NSNumber *, NSTimer *> *)quoteSubscriptionTimers {
    if (!_quoteSubscriptionTimers) {
        _quoteSubscriptionTimers = [[NSMutableDictionary alloc] init];
    }
    return _quoteSubscriptionTimers;
}

/// component 传 NSNotFound 表示调用方没给出组件（getQuoteInfo 就没有这个参数）——
/// 这种情况回传全量，价格带上、档位给满，由 SDK 侧各组件各取所需：
/// 行情条只读第一档当买卖一档，买卖盘读完整档位。
/// 给了组件就按约定只回传该组件需要的字段：行情条带价格和买卖一档，买卖盘只带多档深度
- (NSArray<TigerTradingContractQuoteModel *> *)mockQuotesForContracts:(NSArray<TigerTradingContractInfoModel *> *)contracts
                                                            component:(NSInteger)component {
    NSMutableArray *models = [[NSMutableArray alloc] init];
    for (TigerTradingContractInfoModel *contract in contracts) {
        if (component == TigerTradingSDKQuoteComponentTypeTradePageAskBid) {
            [models addObject:[self mockAskBidQuoteForContract:contract]];
        } else {
            [models addObjectsFromArray:[self mockQuotesForContract:contract
                                                          fullDepth:(component == NSNotFound)]];
        }
    }
    return models;
}

/// 股票下单页买卖盘：只回传 askBids，价格字段留空
- (TigerTradingContractQuoteModel *)mockAskBidQuoteForContract:(TigerTradingContractInfoModel *)contract {
    TigerTradingContractQuoteModel *quote = [[TigerTradingContractQuoteModel alloc] init];
    quote.symbol = contract.symbol;
    quote.market = contract.market;
    quote.secType = contract.secType;
    quote.askBids = [self mockAskBidsWithBasePrice:100 + ((double)arc4random_uniform(201) / 100.0 - 1.0)];
    return quote;
}

/// 造一组假行情。下单页行情条按交易时段分行展示，同一个 symbol 要按 tag 分别回传盘中、盘后两条，
/// SDK 靠 tag 把每条行情落到对应的那一行
/// fullDepth 为 YES 时档位给满（调用方没声明组件，回传全量让各组件自取），
/// 否则只给买卖一档 —— 行情条这一路只用得上第一档
- (NSArray<TigerTradingContractQuoteModel *> *)mockQuotesForContract:(TigerTradingContractInfoModel *)contract
                                                           fullDepth:(BOOL)fullDepth {
    NSNumber *nowTimestamps = @([[NSDate date] timeIntervalSince1970] * 1000);
    // 每次取数价格都抖一下，长连接推送时能直观看出界面确实在刷新
    double regularPrice = 100 + ((double)arc4random_uniform(201) / 100.0 - 1.0);
    double postPrice = regularPrice + 1;

    TigerTradingContractQuoteModel *regular = [[TigerTradingContractQuoteModel alloc] init];
    regular.symbol = contract.symbol;
    regular.market = contract.market;
    regular.secType = contract.secType;
    regular.latestPrice = @(regularPrice);
    regular.priceChange = @(regularPrice - 80);
    regular.preClose = @80;
    regular.total = @10;
    regular.prices = @[@100, @120, @100, @80, @(regularPrice)];
    regular.status = @"盘中";
    regular.tag = @"regular";
    regular.tradingTime = @"16:00 EDT";
    regular.tradingTimestamps = nowTimestamps;
    regular.askBids = fullDepth ? [self mockAskBidsWithBasePrice:regularPrice] : [self mockLevel1WithBasePrice:regularPrice];

    TigerTradingContractQuoteModel *post = [[TigerTradingContractQuoteModel alloc] init];
    post.symbol = contract.symbol;
    post.market = contract.market;
    post.secType = contract.secType;
    post.latestPrice = @(postPrice);
    post.priceChange = @(postPrice - regularPrice);
    post.preClose = @(regularPrice);
    post.status = @"盘后";
    post.tag = @"post";
    post.tradingTime = @"19:30 EDT";
    post.tradingTimestamps = nowTimestamps;
    post.askBids = fullDepth ? [self mockAskBidsWithBasePrice:postPrice] : [self mockLevel1WithBasePrice:postPrice];

    return @[regular, post];
}

/// 造买卖一档，跟着实时行情回传 —— 下单页的买卖一档行、表头、限价单填价都读它。
/// 与 TT 一致：一档跟着行情走，深度是另一条订阅
- (NSArray<TigerTradingQuoteAskBidModel *> *)mockLevel1WithBasePrice:(double)basePrice {
    return @[[self mockAskBidWithBasePrice:basePrice level:0]];
}

/// 造深度档位，档位数跟着「APP 行情权限」走，模拟真实客户的行为：
/// Lv2 才有多档深度，Lv1 根本不会被订到这一路。
/// 价格和数量每次都抖一下，便于确认推送真的刷到了界面上
- (NSArray<TigerTradingQuoteAskBidModel *> *)mockAskBidsWithBasePrice:(double)basePrice {
    TigerTradingSDKQuoteType quoteType = self.quoteTypeProvider ? self.quoteTypeProvider() : TigerTradingSDKQuoteTypeUSStockLv2;
    NSInteger levelCount = (quoteType == TigerTradingSDKQuoteTypeUSStockLv2) ? 5 : 1;
    NSMutableArray *askBids = [[NSMutableArray alloc] init];
    for (NSInteger index = 0; index < levelCount; index++) {
        [askBids addObject:[self mockAskBidWithBasePrice:basePrice level:index]];
    }
    return askBids;
}

- (TigerTradingQuoteAskBidModel *)mockAskBidWithBasePrice:(double)basePrice level:(NSInteger)level {
    TigerTradingQuoteAskBidModel *askBid = [[TigerTradingQuoteAskBidModel alloc] init];
    askBid.askPrice = @(basePrice + 0.01 * (level + 1));
    askBid.askCount = @((level + 1) * 100 + arc4random_uniform(100));
    askBid.bidPrice = @(basePrice - 0.01 * (level + 1));
    askBid.bidCount = @((level + 1) * 200 + arc4random_uniform(100));
    return askBid;
}

@end
