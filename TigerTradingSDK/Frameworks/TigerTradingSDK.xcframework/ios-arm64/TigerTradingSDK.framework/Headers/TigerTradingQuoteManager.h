//
//  TigerTradingQuoteManager.h
//  TigerTradingSDK
//
//  Created by 骆鹏飞 on 2024/9/19.
//

#import <Foundation/Foundation.h>

UIKIT_EXTERN NSString * _Nonnull const TigerTradingMarketUS;
UIKIT_EXTERN NSString * _Nonnull const TigerTradingMarketHK;
UIKIT_EXTERN NSString * _Nonnull const TigerTradingMarketSG;


NS_ASSUME_NONNULL_BEGIN
/// 行情SDK
@interface TigerTradingQuoteManager : NSObject


/// 打开个股详情页
/// - Parameters:
///   - symbol: 个股页symbol
///   - market: 个股页市场
///   - fromViewController: 跳转的起始控制器
+ (void)openStockDetailPageWithSymbol:(NSString *)symbol market:(NSString *)market fromViewController:(UIViewController *)fromViewController;


/// 打开期权详情页
/// - Parameters:
///   - symbol: 期权symbol
///   - right: 期权right（CALL/PUT）
///   - strike: 期权行权价
///   - expiry: 期权到期日
///   - market: 期权所属市场（US/HK）
///   - fromViewController: 跳转的起始控制器
+ (void)openOptionDetailPageWithSymbol:(NSString *)symbol right:(NSString *)right strike:(NSString *)strike expiry:(NSNumber *)expiry market:(NSString *)market fromViewController:(UIViewController *)fromViewController;

/// 打开多腿期权详情页，与上面单腿期权不同，多腿有六要素
/// -  optionItems: 多腿期权入参，下面示例两腿期权
/// - fromViewController: 跳转的起始控制器
/// e.g
/// [{
///     "symbol": "AAPL",
///     "right": "PUT",
///     "expiry": 1688097600000,
///     "strike": "180.0",
///     "direction": "buy",
///     "size": 1
///    },
///    {
///     "symbol": "AAPL",
///     "right": "PUT",
///     "expiry": 1688097600000,
///     "strike": "180.0",
///     "direction": "sell",
///     "size": 2
///  }]
+ (void)openMultiLegOptionDetailPage:(NSArray *)optionItems fromViewController:(UIViewController *)fromViewController;

/// 行情订阅，订阅后会收到行情推送
/// - Parameters:
///   - symbols: 需要订阅的symbol数组，e.g ["AAPL","TSLA"]
///   - quotesCallback: 行情回调，返回行情数据
+ (void)subscribeQuote:(NSArray *)symbols callBack:(void(^)(NSDictionary *))quotesCallback;

/// 取消行情订阅
/// - Parameter symbols: 需要取消订阅的symbol数组，e.g ["AAPL","TSLA"]
+ (void)unSubscribeQuote:(NSArray *)symbols;


/// 批量获取指定合约的价格信息
/// - Parameters:
///   - symbols: 请求行情symbol数组，e.g ["AAPL","TSLA"]
///   - successed: 成功回调
///   - failed: 失败回调
+ (void)fetchContractBriefInfo:(NSArray *)symbols successed:(void(^)(id))successed failed:(void(^)(NSError *))failed;


/// 行情页面
/// - Parameter market: 所属于市场（e.g US/HK/SI/AU）
+ (UIViewController *)quotePageViewController:(NSString *)market;

/// 期权列表页面（Tiger Trade 行情tab 期权页）
+ (UIViewController *)optionPageController;


/// 下单页行情视图，iOS通过UIViewController 实现
/// - Parameters:
///   - symbol: 合约symbol
///   - secType: 合约类型
///   - market: 合约所属市场
+ (UIViewController *)placeOrderBriefQuoteViewWithSymbol:(NSString *)symbol secType:(NSString *)secType market:(NSString *)market;

@end

NS_ASSUME_NONNULL_END
