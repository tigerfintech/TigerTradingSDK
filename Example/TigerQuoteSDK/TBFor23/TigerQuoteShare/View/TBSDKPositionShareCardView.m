//
//  TBSDKPositionShareCardView.m
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/12.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)

#import "TBSDKPositionShareCardView.h"
#import <TBBaseKit/TBBaseKit.h>
#import <TBUIKit/TBUIKit.h>
#import "TBSDKPositionShareTitleValueView.h"
#import <TBTradeBusinessBaseKit/TBTradeAPIPositionModel.h>
#import <TBStockKit/NSString+TBStock.h>
#import <TBStockKit/TBStock+TBColor.h>
#import <TBTradeBusinessBaseKit/TBTradePositionSettingManager.h>
#import <TBBusinessSupportKit/TBStock+TBFormat.h>
#import <TBTradeBusinessBaseKit/TBTradeAPIPositionModel+CostType.h>
#import <TBShareKit/TBCardShareUtil.h>
#import <TBTradeBusinessBaseKit/TBExchangeRateManager.h>
#import <TBTradeBusinessBaseKit/TBTradeUtils.h>
#import <TBTradeBusinessBaseKit/TBTradeAssetTodayPnLShareInfoModel.h>

@interface TBSDKPositionShareCardView ()

@property (nonatomic, strong) UIView *titleMarkView;
@property (nonatomic, strong) UILabel *titleLabel; // 标题（浮动收益）
@property (nonatomic, strong) UIButton *longOrShortButton; // (做多，做空)
@property (nonatomic, strong) UILabel *mainValueLabel;
@property (nonatomic, strong) UIView *line_1;
@property (nonatomic, strong) UIView *line_2;
@property (nonatomic, strong) TBSDKPositionShareTitleValueView *symbolView; // 标的信息
@property (nonatomic, strong) TBSDKPositionShareTitleValueView *lastPriceView; // 最新价
@property (nonatomic, strong) TBSDKPositionShareTitleValueView *costPriceView; // 成本价
@property (nonatomic, strong) UIView *titleView;

@end

@implementation TBSDKPositionShareCardView

// 重写父类方法，返回分享值type
- (TBCardShareValueType)cardShareValueType {
    TBCardShareValueType type = TBCardShareValueTypeNone;
    
    if (self.shareType == TBCardShareTypePortfolioShareProfitLossRatio ||
        self.shareType == TBCardShareTypePortfolioUnrealizedProfitLossRatio) { // 比例
        type = TBCardShareValueTypeRatio;
    } else if (self.shareType == TBCardShareTypePortfolioShareProfitLossAmount ||
               self.shareType == TBCardShareTypePortfolioUnrealizedProfitLossAmount ||
               self.shareType == TBCardShareTypePortfolioRealizedProfitLossAmount) { // 金额
        type = TBCardShareValueTypeAmount;
    }
    return type;
}

-(instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        [self setupViews];
    }
    return self;
}

- (void)setupViews {
    UIView *titleView = [[UIView alloc] init];
    titleView.backgroundColor = [UIColor clearColor];
    [self addSubview:titleView];
    [titleView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.equalTo(@15);
        make.top.equalTo(self.stickerImageView.mas_bottom).offset(20);
        make.centerX.equalTo(self);
    }];
    self.titleView = titleView;
    _titleLabel = [[UILabel alloc] initWithFont:MEDFONTO(12) color:COLOR_CARD_SHARE(0.6)];
    [titleView addSubview:_titleLabel];
    [_titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(titleView);
        make.centerY.equalTo(titleView.mas_centerY).offset(0);
    }];
    
    _longOrShortButton  = [UIButton buttonWithType:UIButtonTypeCustom];
    [_longOrShortButton setTitleColor:COLOR_CARD_SHARE(0.5) forState:UIControlStateNormal];
    _longOrShortButton.layer.cornerRadius = 8;
    [_longOrShortButton.titleLabel setFont:MEDFONTO(9)];
    _longOrShortButton.titleLabel.adjustsFontSizeToFitWidth = YES;
    _longOrShortButton.layer.borderColor = COLOR_CARD_SHARE(0.24).CGColor;
    
    _longOrShortButton.layer.borderWidth = 0.5;
    [titleView addSubview:_longOrShortButton];
    [_longOrShortButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.bottom.trailing.equalTo(titleView);
        make.width.equalTo(@34);
        make.leading.equalTo(_titleLabel.mas_trailing).offset(6);
    }];
    
    _mainValueLabel = [[UILabel alloc] initWithFont:MEDFONTO(42) color:COLOR_CARD_SHARE(1)];
    _mainValueLabel.textAlignment = NSTextAlignmentCenter;
    [self addSubview:_mainValueLabel];
    [_mainValueLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(titleView.mas_bottom);
        make.height.equalTo(@54);
        make.centerX.equalTo(self);
        make.leading.equalTo(self.mas_leading).offset(20);
        make.trailing.equalTo(self.mas_trailing).offset(-20);
    }];
    
    CGFloat firstItemLeftOffset = 4;
    _symbolView = [[TBSDKPositionShareTitleValueView alloc] init];
    [self addSubview:_symbolView];
    [_symbolView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self.mas_leading).offset(firstItemLeftOffset);
        make.top.equalTo(_mainValueLabel.mas_bottom).offset(18);
    }];
    
    UIView *line_1 = [[UIView alloc] init];
    line_1.backgroundColor = COLOR_CARD_SHARE(0.12);
    [self addSubview:line_1];
    [line_1 mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(_symbolView.mas_trailing);
        make.top.equalTo(_symbolView.mas_top);
        make.width.equalTo(@1);
        make.height.equalTo(@30);
    }];
    self.line_1 = line_1;
    
    _lastPriceView = [[TBSDKPositionShareTitleValueView alloc] init];
    [self addSubview:_lastPriceView];
    [_lastPriceView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(line_1.mas_trailing).offset(0);
        make.width.equalTo(_symbolView);
        make.top.equalTo(_symbolView);
    }];
    
    UIView *line_2 = [[UIView alloc] init];
    line_2.backgroundColor = COLOR_CARD_SHARE(0.12);
    [self addSubview:line_2];
    [line_2 mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(_lastPriceView.mas_trailing);
        make.top.equalTo(_symbolView.mas_top);
        make.width.equalTo(@1);
        make.height.equalTo(@30);
    }];
    self.line_2 = line_2;
    
    _costPriceView = [[TBSDKPositionShareTitleValueView alloc] init];
    [self addSubview:_costPriceView];
    [_costPriceView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(line_2.mas_trailing).offset(0);
        make.trailing.equalTo(self.mas_trailing).offset(-firstItemLeftOffset);
        make.width.equalTo(_symbolView);
        make.top.equalTo(_symbolView);
        
    }];
}

// 因为有symbol 、价格信息，所以卡片高度，比默认高
- (CGFloat)cardViewHeightWithWidth:(CGFloat)width {
    CGFloat height = [super cardViewHeightWithWidth:width] + 20;
    return height;
}

// 常规持仓分享（非老虎钱袋子）
- (void)setTradePositionItem:(TBTradeAPIPositionItemModel *)tradePositionItem {
    _tradePositionItem = tradePositionItem;
    
    // 做少/做多、收入/支出标识
    NSString *longOrShortString = nil;
    if ([_tradePositionItem.secType tb_isMlegOption]) {
        longOrShortString = (_tradePositionItem.marketValue.doubleValue < 0) ? TBResourcesLocalizedString(@"mobile_comm_common_credit", nil) : TBResourcesLocalizedString(@"mobile_comm_common_debit", nil);
    }
    else if (_tradePositionItem.position.longValue < 0) {
        longOrShortString = TBResourcesLocalizedString(@"mobile_ios_common_short", nil);
    }
    else if(_tradePositionItem.position.longValue > 0){
        longOrShortString = TBResourcesLocalizedString(@"mobile_ios_common_long", nil);
    }
    [_longOrShortButton setTitle:longOrShortString forState:UIControlStateNormal];
    CGFloat longOrShortStringWidth = [TBStringUtility getStringRectWithFont:longOrShortString withFont:MEDFONTO(9)].width;
    [_longOrShortButton mas_updateConstraints:^(MASConstraintMaker *make) {
        make.width.equalTo(@(longOrShortStringWidth+12));
    }];
    self.longOrShortButton.hidden = [tradePositionItem isZeroPosition]; // 0持仓不显示做多/做空
    
    NSNumber *exchangeRateNumber = @1;
    NSNumber *displayValueAmount = nil;
    NSNumber *displayValueRatio = nil;
    NSString *displayValueType = nil;
    
    NSString *currency = self.tradePositionItem.currency;
    if (!TextValid(currency)) {
        currency = @"";
    }
    else {
        if ([self.tradePositionItem.secType tb_isCFD]) {
            // CFD目前写死用USD
            currency = @"USD";
        }
        exchangeRateNumber = [[TBExchangeRateManager sharedInstance].exchangeRateDictionary valueForKey:currency];
        currency = [NSString stringWithFormat:@" %@", currency];
    }
    
    if (self.shareType == TBCardShareTypePortfolioShareProfitLossRatio) { // 持仓盈亏比例
        displayValueType = @"Ratio";
        self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_p_a_l_ratio", nil);
        NSNumber *rateNumber = nil;
        if ([tradePositionItem.secType tb_isBond]) { // 持仓盈亏率，BOND以及新增类型使用
            rateNumber = tradePositionItem.positionPnlPercent;
        } else {
            rateNumber = tradePositionItem.unrealPnlPercentByCostOfCarry;
        }
        
        double rate = 0.0;
        double agarageCost = [_tradePositionItem.averageCostBasedOnCostType doubleValue];
        double cost = agarageCost * ABS([_tradePositionItem.realPosition doubleValue]);
        BOOL showPnlRate = YES;//无盈亏比例不显示
        if (rateNumber) {
            rate = rateNumber.doubleValue;
        }
        else {
            if (agarageCost >= 0 && fabs(cost) > 0) {
                rate = [_tradePositionItem.positionPnl doubleValue] / cost;
            }
            //无unrealPnlPercent字段且成本<0盈亏比例不显示
            else {
                showPnlRate = NO;
            }
        }
        if (showPnlRate) {
            self.titleLabel.hidden = NO;
            NSString *valueString = [TBStock formatterFromPercentNumber:@(rate) needValuePrefix:YES];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
            displayValueRatio = @(rate);
        }
        else {
            self.longOrShortButton.hidden = YES;
            self.titleLabel.hidden = YES;
            NSString *mainValueString = @"";
            if (agarageCost == 0) {
                mainValueString = TBResourcesLocalizedString(@"mobile_comm_common_cost_ratio_zero", nil);
            } else if (agarageCost < 0) {
                mainValueString = TBResourcesLocalizedString(@"mobile_comm_common_cost_ratio_lower_zero", nil);
            }
            self.mainValueLabel.text = mainValueString;
            self.mainValueLabel.font = MEDFONTO(18);
        }
        
        // 表情 & 文案
        [self setImageAndDescWithNumber:rate];
    } else if (self.shareType == TBCardShareTypePortfolioShareProfitLossAmount) { // 持仓盈亏金额
        displayValueType = @"Amount";
        self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_p_l", nil);
        
        NSNumber *positionPnl = self.tradePositionItem.positionPnl;
        displayValueAmount = self.tradePositionItem.positionPnl;
        NSString *price = positionPnl ? [TBStock formatterPrefixPrice:positionPnl market:@""] : DEFAULT_PRICE_VALUE;
        NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
        self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
        /*将货币按汇率换成美元*/
        double positionPnlValue = positionPnl.doubleValue;
//        if ([_tradePositionItem.secType tb_isFutures]) {
//            positionPnlValue = _tradePositionItem.futuresRealPnl.doubleValue;
//        }
        if (exchangeRateNumber) {
            positionPnlValue = exchangeRateNumber.doubleValue * positionPnl.doubleValue;
        }
        [self setImageAndDescWithNumber:positionPnlValue];
    } else if (self.shareType == TBCardShareTypePortfolioUnrealizedProfitLossAmount) { // 未实现盈亏金额
        displayValueType = @"Amount";
        self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l", nil);
        
        NSNumber *unrealPnl = self.tradePositionItem.unrealPnlBasedOnCostType;
        displayValueAmount = self.tradePositionItem.unrealPnlBasedOnCostType;
        NSString *price = unrealPnl ? [TBStock formatterPrefixPrice:unrealPnl market:@""] : DEFAULT_PRICE_VALUE;
        NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
        self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
        [self setImageAndDescWithNumber:unrealPnl.doubleValue*exchangeRateNumber.doubleValue];
    } else if (self.shareType == TBCardShareTypePortfolioUnrealizedProfitLossRatio) { // 未实现盈亏率
        displayValueType = @"Ratio";
        self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l_ratio", nil);
        double rate = 0.0f;
        double agarageCost = [_tradePositionItem.averageCostBasedOnCostType doubleValue];
        double cost = agarageCost * ABS([_tradePositionItem.realPosition doubleValue]);
        BOOL showPnlRate = YES;//无盈亏比例不显示
        if (_tradePositionItem.unrealPnlPercentBasedOnCostType) {
            rate = _tradePositionItem.unrealPnlPercentBasedOnCostType.doubleValue;
        }
        else {
            if (agarageCost >= 0 && fabs(cost) > 0) {
                rate = [_tradePositionItem.unrealPnlBasedOnCostType doubleValue] / cost;
            }
            //无unrealPnlPercent字段且成本<0盈亏比例不显示
            else {
                showPnlRate = NO;
            }
        }
        if (showPnlRate) {
            self.titleLabel.hidden = NO;
            NSString *valueString = [TBStock formatterFromPercentNumber:@(rate) needValuePrefix:YES];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
            displayValueRatio = @(rate);
        }
        else {
            self.longOrShortButton.hidden = YES;
            self.titleLabel.hidden = YES;
            NSString *mainValueString = @"";
            if (agarageCost == 0) {
                mainValueString = TBResourcesLocalizedString(@"mobile_comm_common_cost_ratio_zero", nil);
            } else if (agarageCost < 0) {
                mainValueString = TBResourcesLocalizedString(@"mobile_comm_common_cost_ratio_lower_zero", nil);
            }
            self.mainValueLabel.text = mainValueString;
            self.mainValueLabel.font = MEDFONTO(18);
        }
        
        // 表情 & 文案
        [self setImageAndDescWithNumber:rate];
    } else if (self.shareType == TBCardShareTypePortfolioRealizedProfitLossAmount) { // 已实现盈亏金额
        displayValueType = @"Amount";
        self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_realized_p_l", nil);
        
        NSNumber *realPnl = self.tradePositionItem.realizedPnlBasedOnCostType;
        displayValueAmount = self.tradePositionItem.realizedPnlBasedOnCostType;
        NSString *price = realPnl ? [TBStock formatterPrefixPrice:realPnl market:@""] : DEFAULT_PRICE_VALUE;
        
        NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
        self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
        [self setImageAndDescWithNumber:realPnl.doubleValue*exchangeRateNumber.doubleValue];
    }
    
    // symbol信息
    _symbolView.valueLabel.text  = [_tradePositionItem.symbol tb_displaySymbol];
    _symbolView.titleLabel.text = _tradePositionItem.nameCN;
    
    // 最新价
    _lastPriceView.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_portfolio_share3", nil);
    double lastPrice = [_tradePositionItem.realLatestPrice doubleValue];
    if ([_tradePositionItem.secType tb_isFutures] && TextValid(_tradePositionItem.futuresLatestPrice)) {
        _lastPriceView.valueLabel.text = _tradePositionItem.futuresLatestPrice;
    } else {
        _lastPriceView.valueLabel.text = [TBStock formatterPrice:lastPrice market:_tradePositionItem.market secType:_tradePositionItem.secType];
    }
    
    // 成本价
    double averageCost = [_tradePositionItem.averageCostBasedOnCostType doubleValue];
    BOOL isOption = NO; // 是否是期权
    if ([_tradePositionItem.secType tb_isOption] && [_tradePositionItem isKindOfClass:[TBTradeAPIPositionItemModel class]]) {
        isOption = YES;
    }
    if ([_tradePositionItem.secType tb_isMlegOption]) {
        if ([tradePositionItem isCoveredCallPositionItemModel]) {
            _symbolView.valueLabel.text = _tradePositionItem.contractMajorDescription ?: @"";
        }
        _symbolView.titleLabel.text = [self getCombinedOptionValue:_tradePositionItem.legPositions];
    }
    else if (isOption) {
        if ([_tradePositionItem.market tb_isHK]) {
            _symbolView.valueLabel.text = [TBTradeUtils getHKNameCN:_tradePositionItem.nameCN right:_tradePositionItem.right];
            NSString *strike = _tradePositionItem.strike;
            NSString *strikeRightString = [NSString stringWithFormat:@"%@ %@",_tradePositionItem.expiry, strike];
            _symbolView.titleLabel.text = strikeRightString;
            averageCost = averageCost/_tradePositionItem.multiplier.doubleValue;
        } else {
            _symbolView.valueLabel.text = [NSString stringWithFormat:@"%@ %@",_tradePositionItem.symbol,_tradePositionItem.right];
            NSString *strike = _tradePositionItem.strike;
            NSString *strikeRightString = [NSString stringWithFormat:@"%@  %@",_tradePositionItem.expiry, strike];
            _symbolView.titleLabel.text = strikeRightString;
            averageCost = averageCost/100.0;
        }
    }
    self.costPriceView.titleLabel.text = [self costPriceTitle:self.tradePositionItem.secType];
    if ([_tradePositionItem.secType tb_isFutures] && TextValid(_tradePositionItem.futuresAverageCost)) {
        self.costPriceView.valueLabel.text = _tradePositionItem.futuresAverageCost;
    } else {
        self.costPriceView.valueLabel.text = [TBStock formatterPrice:averageCost market:_tradePositionItem.market secType:_tradePositionItem.secType];
    }
    
    // 组装数据（分享到老虎社区使用）
    NSMutableDictionary *dataForTigerCommunity = [[NSMutableDictionary alloc] init];
    [dataForTigerCommunity tb_safeSetObject:displayValueAmount forKey:@"displayValueAmount"];
    [dataForTigerCommunity tb_safeSetObject:displayValueRatio forKey:@"displayValueRatio"];
    NSString *displayCostType = nil;
    if ([TBTradePositionSettingManager isFIFOCostTypeWithSegType:[tradePositionItem.secType tb_toSegType]]) {
        displayCostType = @"FIFO";
    } else if ([TBTradePositionSettingManager isAVERAGECostTypeWithSegType:[tradePositionItem.secType tb_toSegType]]) {
        displayCostType = @"AVERAGE";
    } else if ([TBTradePositionSettingManager isDILUTEDCostTypeWithSegType:[tradePositionItem.secType tb_toSegType]]) {
        displayCostType = @"DILUTED";
    }
    [dataForTigerCommunity tb_safeSetObject:displayCostType forKey:@"displayCostType"];
    [dataForTigerCommunity tb_safeSetObject:displayValueType forKey:@"displayValueType"];
    if (dataForTigerCommunity.count>0) {
        self.dicForTigerCommunity = [dataForTigerCommunity copy];
    }
    
    [self updateSaDictionary];
}

- (NSString *)getCombinedOptionValue:(NSArray <TBTradeAPIPositionItemModel *> *)legPositions {
    NSString *dateString = @"";
    NSString *priceRightString = @"";
    for (int i=0; i<legPositions.count; i++) {
        TBTradeAPIPositionItemModel *model = legPositions[i];
        if ([model.secType tb_isStock]) {
            continue;
        }
        dateString = [dateString stringByAppendingFormat:@"%@", model.expiry];
        priceRightString = [priceRightString stringByAppendingFormat:@"%@%@", model.strike, [model.right substringToIndex:1]];
        if (i < (legPositions.count - 1)) {
            BOOL nextIsStock = [legPositions[i+1].secType tb_isStock];
            if (!nextIsStock) {
                dateString = [dateString stringByAppendingString:@"/"];
                priceRightString = [priceRightString stringByAppendingString:@"/"];
            }
        }
    }
    
    return [dateString stringByAppendingFormat:@"\n%@", priceRightString];
}

// 老虎钱袋子持仓分享
- (void)setTodayPnLInfoModel:(TBTradeAssetTodayPnLShareInfoModel *)todayPnLInfoModel {
    [self.titleView mas_updateConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.stickerImageView.mas_bottom).offset(30);
    }];
    self.symbolView.hidden = YES;
    self.lastPriceView.hidden = YES;
    self.costPriceView.hidden = YES;
    self.line_1.hidden = YES;
    self.line_2.hidden = YES;
    [_longOrShortButton mas_updateConstraints:^(MASConstraintMaker *make) {
        make.width.equalTo(@0);
    }];
    _longOrShortButton.hidden = YES;
    
    _todayPnLInfoModel = todayPnLInfoModel;
    NSString *currency = self.todayPnLInfoModel.currency;
    if (!TextValid(currency)) {
        currency = @"";
    }
    NSNumber *value = self.todayPnLInfoModel.shareAmount;
    [self setImageAndDescWithNumber:self.todayPnLInfoModel.originShareAmount.doubleValue];
    self.titleLabel.text = todayPnLInfoModel.shareAmountTitle;//[NSString stringWithFormat:@"%@%@%@%@",TBResourcesLocalizedString(@"mobile_comm_common_accum_pl", nil),@"「",[TBService(TBFundMallComponentService) tbFund_TigerVaultName],@"」"];
    NSString *amountString = DEFAULT_PRICE_VALUE;
    if (value.doubleValue != 0) {
        amountString = [TBStock emptyCurrencyPnlStyleNumberFormatString:value.doubleValue];
    } else {
        amountString = @"0.00";
    }
    currency = TextValid(currency) ? [NSString stringWithFormat:@" %@",currency] : currency;
    NSString *string = [NSString stringWithFormat:@"%@%@",amountString,currency];
    self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
}

#pragma mark - tool
- (NSString *)costPriceTitle:(NSString *)secType {
    NSString *segType = [secType tb_toSegType];
    if ([secType tb_isCFD]) {
        return TBResourcesLocalizedString(@"mobile_comm_common_open_price", nil);
    }
    
    if ([TBTradePositionSettingManager isDILUTEDCostTypeWithSegType:segType]) {
        return TBResourcesLocalizedString(@"mobile_ios_common_diluted_cost", nil);
    } else if ([TBTradePositionSettingManager isAVERAGECostTypeWithSegType:segType]) {
        return TBResourcesLocalizedString(@"mobile_ios_common_avg_cost", nil);
    } else {
        return TBResourcesLocalizedString(@"mobile_comm_common_cost_price", nil);
    }
}

- (UIColor *)getCorrectColorWithChange:(double)change {
    return  [TBStock getIncreaseOrDecreaseColorWithRedColor:RGBCOLOR_HEX(0xf20642) greenColor:RGBCOLOR_HEX(0x00ba5d) equalColor:RGBCOLOR_HEX(0x2C2E3B) change:change];
}

- (void)updateCardBackgroundColorAndTextColorWithStickerIndex:(NSInteger)index {
    [super updateCardBackgroundColorAndTextColorWithStickerIndex:index];
    NSInteger colorValue = [self textColorWithIndex:index withShareType:self.shareType];
    self.titleLabel.textColor = RGBACOLOR_HEX(colorValue, 0.6);
    [_longOrShortButton setTitleColor:RGBACOLOR_HEX(colorValue, 0.5) forState:UIControlStateNormal];
    _longOrShortButton.layer.borderColor = RGBACOLOR_HEX(colorValue, 0.24).CGColor;
    _mainValueLabel.textColor = RGBACOLOR_HEX(colorValue, 1);
    self.line_1.backgroundColor = RGBACOLOR_HEX(colorValue, 0.12);
    self.line_2.backgroundColor = RGBACOLOR_HEX(colorValue, 0.12);
    self.symbolView.textColorValue = colorValue;
    self.lastPriceView.textColorValue = colorValue;
    self.costPriceView.textColorValue = colorValue;
}

- (void)showString:(NSString *)string inLabel:(UILabel *)label {
    NSArray *components = [string componentsSeparatedByString:@"."];
    
    NSMutableAttributedString *attributedStr = [[NSMutableAttributedString alloc] initWithString:string];
    
    // 设置小数点前的字体大小
    NSRange range1 = NSMakeRange(0, [components[0] length]);
    [attributedStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:20] range:range1];
    
    // 如果存在小数点，设置小数点后的字体大小
    if ([components count] > 1) {
        NSRange range2 = NSMakeRange([components[0] length], 1);
        NSRange range3 = NSMakeRange([components[0] length] + 1, [components[1] length]);
        [attributedStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:10] range:range2];
        [attributedStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:10] range:range3];
    }
    
    [label setAttributedText:attributedStr];
}

// 更新埋点数据
- (void)updateSaDictionary {
    if (self.shareType == TBCardShareTypePortfolioShareProfitLossRatio) {
        [self.saDicationary tb_safeSetObject:@"盈亏比例" forKey:@"sub_type"];
    } else if (self.shareType == TBCardShareTypePortfolioShareProfitLossAmount){
        [self.saDicationary tb_safeSetObject:@"盈亏金额" forKey:@"sub_type"];
    }
}

//stickerTest
- (void)updateMainValue {
    if (TextValid(self.valueTextField.text)) {
        // 盈亏比例（或盈亏金额）值
        if (self.shareType == TBCardShareTypePortfolioShareProfitLossRatio) { // 盈亏比例
            // 盈亏比例值
            double rate = [self.valueTextField.text doubleValue];
            NSString *valueString = [TBStock formatterFromPercentNumber:@(rate) needValuePrefix:YES];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
            
            // 表情 & 文案
            [self setImageAndDescWithNumber:rate];
        } else if (self.shareType == TBCardShareTypePortfolioShareProfitLossAmount) { // 盈亏金额
            // 盈亏金额值
            NSString *currency = self.tradePositionItem.currency;
            if (!TextValid(self.tradePositionItem.currency)) {
                currency = @"";
            }
            currency = TextValid(currency) ? [NSString stringWithFormat:@" %@",currency] : currency;
            NSString *price = self.valueTextField.text;
            NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
            
            // 表情 & 文案
            [self setImageAndDescWithNumber:[self.valueTextField.text doubleValue]];
        } else if (self.shareType == TBCardShareTypeTigerVaultPortfolioShare) {
            NSNumber *value = [NSNumber numberWithString:self.valueTextField.text];
            [self setImageAndDescWithNumber:value.doubleValue];
            
            NSString *amountString = DEFAULT_PRICE_VALUE;
            if (value.doubleValue != 0) {
                amountString = [TBStock emptyCurrencyPnlStyleNumberFormatString:value.doubleValue];
            } else {
                amountString = @"0.00";
            }
            NSString *currency = self.todayPnLInfoModel.currency;
            if (!TextValid(currency)) {
                currency = @"";
            }
            currency = TextValid(currency) ? [NSString stringWithFormat:@" %@",currency] : currency;
            NSString *string = [NSString stringWithFormat:@"%@%@",amountString,currency];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
        }
    }
}
@end
#endif
