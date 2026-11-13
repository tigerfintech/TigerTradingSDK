//
//  TBSDKOrderShareCardView.m
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/17.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)

#import "TBSDKOrderShareCardView.h"
#import <TBTradeBusinessBaseKit/TBTradeAPIOrderModel.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBUIKit/TBUIKit.h>
#import "TBSDKPositionShareTitleValueView.h"
#import <TBStockKit/NSString+TBStock.h>
#import <TBBusinessSupportKit/TBStock+TBFormat.h>
#import <TBTradeBusinessBaseKit/TBExchangeRateManager.h>
#import <TBShareKit/TBCardShareUtil.h>
#import <TBTradeBusinessBaseKit/TBTradeUtils.h>
#import <TBTradeBusinessBaseKit/TBTradeAPIPositionModel.h>
#import <TBTradeBusinessBaseKit/TBTradeAPIPositionModel+CostType.h>
#import <TBUIKit/TBPaddingLabel.h>
#import <TBStockKit/TBStockInfoConstantString.h>
#import <TBTradeBusinessBaseKit/TBTradePositionSettingManager.h>

@interface TBSDKOrderShareCardView ()

@property (nonatomic, strong) UILabel *titleLabel; // 标题（浮动收益）
@property (nonatomic, strong) TBPaddingLabel *suffixTitleTagLabel; // 标题后面的tag（901 组合期权下单用到）
@property (nonatomic, strong) UILabel *mainValueLabel;
@property (nonatomic, strong) TBSDKPositionShareTitleValueView *symbolView; // 标的信息
@property (nonatomic, strong) TBSDKPositionShareTitleValueView *lastPriceView; // 最新价
@property (nonatomic, strong) TBSDKPositionShareTitleValueView *costPriceView; // 成本价
@property (nonatomic, strong) UIView *line_1;
@property (nonatomic, strong) UIView *line_2;

//部分平仓的时候
@property (nonatomic, strong) UILabel *realizedPnlTitleLabel; // 已实现盈亏
@property (nonatomic, strong) UILabel *realizedPnlValueLabel;
@property (nonatomic, strong) UILabel *unRealizedPnlTitleLabel; // 未实现盈亏
@property (nonatomic, strong) UILabel *unRealizedPnlValueLabel;

@end

@implementation TBSDKOrderShareCardView

// 重写父类方法，返回分享值type
- (TBCardShareValueType)cardShareValueType {
    TBCardShareValueType type = TBCardShareValueTypeAmount;
    
    if (self.shareType == TBCardShareTypeOrderProfitLossRatio) { // 比例
        type = TBCardShareValueTypeRatio;
    } else if (self.shareType == TBCardShareTypeOrderProfitLossAmount) { // 金额
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
    _titleLabel = [[UILabel alloc] initWithFont:MEDFONTO(12) color:COLOR_CARD_SHARE(0.6)];
    [self addSubview:_titleLabel];
    [_titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.equalTo(@15);
        make.top.equalTo(self.stickerImageView.mas_bottom).offset(20);
        make.centerX.equalTo(self);
    }];
    
    [self addSubview:self.suffixTitleTagLabel];
    [self.suffixTitleTagLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(_titleLabel.mas_trailing).with.offset(4);
        make.centerY.equalTo(_titleLabel);
        make.height.equalTo(@15);
    }];
    
    _mainValueLabel = [[UILabel alloc] initWithFont:MEDFONTO(42) color:COLOR_CARD_SHARE(1)];
    _mainValueLabel.textAlignment = NSTextAlignmentCenter;
    [self addSubview:_mainValueLabel];
    [_mainValueLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_titleLabel.mas_bottom);
        make.height.equalTo(@54);
        make.centerX.equalTo(self);
    }];
    
    CGFloat firstItemLeftOffset = 4;
    _symbolView = [[TBSDKPositionShareTitleValueView alloc] init];
    [self addSubview:_symbolView];
    [_symbolView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self.mas_leading).offset(firstItemLeftOffset);
        make.top.equalTo(_mainValueLabel.mas_bottom).offset(18);
    }];
    
    UIView *line_1 = [[UIView alloc] init];
    line_1.backgroundColor = RGBACOLOR_HEX(0x1F1F1F, 0.12);
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
    
    // 部分平仓时
    self.realizedPnlValueLabel = [[UILabel alloc] initWithFont:MEDFONTO(24) color:COLOR_CARD_SHARE(1)];
    [self addSubview:self.realizedPnlValueLabel];
    [self.realizedPnlValueLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.trailing.equalTo(self.mas_trailing).offset(-10);
        make.leading.equalTo(self.mas_centerX).offset(0);
        make.height.equalTo(@31);
        make.top.equalTo(self.stickerImageView.mas_bottom).offset(20);
    }];
    self.realizedPnlTitleLabel = [[UILabel alloc] initWithFont:MEDFONTO(10) color:COLOR_CARD_SHARE(0.6)];
    self.realizedPnlTitleLabel.textAlignment = NSTextAlignmentRight;
    self.realizedPnlTitleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_realized_p_l", nil);
    [self addSubview:self.realizedPnlTitleLabel];
    [self.realizedPnlTitleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self.mas_leading).offset(20);
        make.centerY.equalTo(self.realizedPnlValueLabel.mas_centerY).offset(4);
        make.trailing.equalTo(self.realizedPnlValueLabel.mas_leading).offset(-15);
    }];
    self.unRealizedPnlValueLabel = [[UILabel alloc] initWithFont:MEDFONTO(24) color:COLOR_CARD_SHARE(1)];
    [self addSubview:self.unRealizedPnlValueLabel];
    [self.unRealizedPnlValueLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.height.leading.trailing.equalTo(self.realizedPnlValueLabel);
        make.top.equalTo(self.realizedPnlValueLabel.mas_bottom).offset(0);
    }];
    self.unRealizedPnlTitleLabel = [[UILabel alloc] initWithFont:MEDFONTO(10) color:COLOR_CARD_SHARE(0.6)];
    self.unRealizedPnlTitleLabel.textAlignment = NSTextAlignmentRight;
    self.unRealizedPnlTitleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l", nil);
    [self addSubview:self.unRealizedPnlTitleLabel];
    [self.unRealizedPnlTitleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.trailing.height.equalTo(self.realizedPnlTitleLabel);
        make.centerY.equalTo(self.unRealizedPnlValueLabel.mas_centerY).offset(4);
    }];
    self.realizedPnlTitleLabel.hidden = YES;
    self.realizedPnlValueLabel.hidden = YES;
    self.unRealizedPnlTitleLabel.hidden = YES;
    self.unRealizedPnlValueLabel.hidden = YES;
}

// 因为有symbol 、价格信息，所以卡片高度，比默认高
- (CGFloat)cardViewHeightWithWidth:(CGFloat)width {
    CGFloat height = [super cardViewHeightWithWidth:width] + 20;
    return height;
}

- (void)setOrderModel:(TBTradeAPIOrderItemModel *)orderModel {
    _orderModel = orderModel;
    self.symbolView.valueLabel.text = [orderModel.symbol tb_displaySymbol];
    self.symbolView.titleLabel.text = orderModel.nameCN;
    if ([orderModel.secType tb_isOption]) {
        if ([orderModel.market tb_isHK]) {
            self.symbolView.valueLabel.text = [TBTradeUtils getHKNameCN:orderModel.nameCN right:orderModel.right];
            //NSString *right = orderModel.right;
            NSString *strike = orderModel.strike;
            NSString *strikeRightString = [NSString stringWithFormat:@"%@ %@", orderModel.expiry, strike];
            self.symbolView.titleLabel.text = strikeRightString;
            //averageCost = orderModel.avgFillPrice.doubleValue/orderModel.multiplier.doubleValue;
        } else {
            
            self.symbolView.valueLabel.text = [NSString stringWithFormat:@"%@ %@",orderModel.symbol,orderModel.right];
            
            //NSString *right = orderModel.right;
            NSString *strike = orderModel.strike;
            NSString *strikeRightString = [NSString stringWithFormat:@"%@  %@",orderModel.expiry, strike];
            self.symbolView.titleLabel.text = strikeRightString;
            //averageCost = averageCost/100.0;
        }
    } else if ([orderModel.secType tb_isMlegOption]) {
        self.suffixTitleTagLabel.hidden = !TextValid(orderModel.comboTypeName);
        self.suffixTitleTagLabel.text = orderModel.comboTypeName;
        if ([orderModel.market tb_isUS]) {
            NSString *expiryInfo = @"";
            NSString *strikeInfo = @"";
            for (TBOmnibuAPIOrderLegInfoModel *legModel in orderModel.legs) {
                expiryInfo = [NSString stringWithFormat:@"%@%@%@", expiryInfo, TextValid(expiryInfo) ? @"/" : @"" ,legModel.expiry];
                strikeInfo = [NSString stringWithFormat:@"%@%@%@%@", strikeInfo, TextValid(strikeInfo) ? @"/" : @"" , legModel.strike, [[legModel.right uppercaseString] isEqualToString:@"CALL"] ? @"C" : @"P"];
            }
            self.symbolView.titleLabel.text = [NSString stringWithFormat:@"%@\n%@",expiryInfo, strikeInfo];
        }
    }
    
    self.costPriceView.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_filled_price", nil);
    if ([orderModel.secType tb_isFutures]) {
        self.costPriceView.valueLabel.text = orderModel.futureAvgFillPrice ?: DEFAULT_PRICE_VALUE;
    }
    else {
        self.costPriceView.valueLabel.text = orderModel.avgFillPrice ? [TBStock formatterPrice:orderModel.avgFillPrice.doubleValue market:orderModel.market secType:orderModel.secType] : DEFAULT_PRICE_VALUE;
    }
    //汇率转换成美元
    NSNumber *exchangeRateNumber = [[TBExchangeRateManager sharedInstance].exchangeRateDictionary valueForKey:orderModel.currency];
    
    NSString *titleString = @"";
    if (self.shareType == TBCardShareTypeOrderProfitLossAmount) {
        titleString = TBResourcesLocalizedString(@"mobile_ios_common_pl_4", nil);
    } else if (self.shareType == TBCardShareTypeOrderProfitLossRatio) {
        titleString = TBResourcesLocalizedString(@"mobile_comm_common_p_l_ratio", nil);
    }
    self.titleLabel.text = titleString;
    self.lastPriceView.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_portfolio_share3", nil);
    self.lastPriceView.valueLabel.text = orderModel.latestPrice ? [TBStock formatterPrice:orderModel.latestPrice.doubleValue market:orderModel.market secType:orderModel.secType] : DEFAULT_PRICE_VALUE;
    
    NSString *currency = [orderModel.secType tb_isCFD] ? CURRENCY_USD : (TextValid(orderModel.currency) ? orderModel.currency : @"");
    //新增字段有值代表是开仓订单
    BOOL orderIsOpen = orderModel.openRealizedPnl || orderModel.openUnrealizedPnl;
    BOOL orderIsOmnibusOpen = orderIsOpen && OMNIBUS;
    
    if (!orderIsOmnibusOpen || !orderModel.latestPrice) {
        [self hideLastPriceItem];
    }
    
    NSNumber *displayValueAmount = nil;
    NSNumber *displayValueRatio = nil;
    
    //部分平仓
    if (orderModel.openUnrealizedPnl.doubleValue != 0 && orderModel.openRealizedPnl.doubleValue != 0 && orderIsOmnibusOpen) {
        self.titleLabel.hidden = YES;
        self.realizedPnlTitleLabel.hidden = NO;
        self.realizedPnlValueLabel.hidden = NO;
        self.unRealizedPnlTitleLabel.hidden = NO;
        self.unRealizedPnlValueLabel.hidden = NO;
        if (self.shareType == TBCardShareTypeOrderProfitLossAmount) {
            self.realizedPnlTitleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_realized_p_l", nil);
            self.unRealizedPnlTitleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l", nil);
            self.realizedPnlValueLabel.attributedText = [self mainValueAttributedStringWithValueString:[self displayStringWithCurrency:currency profitValue:orderModel.openRealizedPnl]];
            self.unRealizedPnlValueLabel.attributedText = [self mainValueAttributedStringWithValueString:[self displayStringWithCurrency:currency profitValue:orderModel.openUnrealizedPnl]];
            [self setImageAndDescWithNumber:orderModel.openRealizedPnl.doubleValue * exchangeRateNumber.doubleValue];
            displayValueAmount = orderModel.openRealizedPnl;
            
            // 如果是平均成本Avg Cost ,只支持 未实现盈亏金额
            if ([TBService(TBTradeBusinessComponentService) tbTradeBusiness_isAVERAGECostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
                self.titleLabel.hidden = NO;
                self.mainValueLabel.hidden = NO;
                self.realizedPnlTitleLabel.hidden = YES;
                self.realizedPnlValueLabel.hidden = YES;
                self.unRealizedPnlTitleLabel.hidden = YES;
                self.unRealizedPnlValueLabel.hidden = YES;
                self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l", nil);

                NSString *string = [self displayStringWithCurrency:currency profitValue:orderModel.openUnrealizedPnl];
                self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
                [self setImageAndDescWithNumber:orderModel.openUnrealizedPnl.doubleValue * exchangeRateNumber.doubleValue];
                displayValueAmount = orderModel.openUnrealizedPnl;
            }
        }
        else if (self.shareType == TBCardShareTypeOrderProfitLossRatio) {
            self.realizedPnlTitleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_realized_p_l_ratio", nil);
            self.unRealizedPnlTitleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l_ratio", nil);

            double realizedPnlRate = orderModel.orderPnlResp.openRealizedPnlPercent.doubleValue;
            double unRealizedPnlRate = orderModel.orderPnlResp.openUnrealizedPnlPercent.doubleValue;

            NSString *valueString = [TBStock formatterFromPercentNumber:@(realizedPnlRate) needValuePrefix:YES];
            self.realizedPnlValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
            valueString = [TBStock formatterFromPercentNumber:@(unRealizedPnlRate) needValuePrefix:YES];
            self.unRealizedPnlValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
            [self setImageAndDescWithNumber:realizedPnlRate];
            displayValueRatio = orderModel.orderPnlResp.openRealizedPnlPercent;
            // 如果是平均成本Avg Cost ,只支持 未实现盈亏比例
            if ([TBService(TBTradeBusinessComponentService) tbTradeBusiness_isAVERAGECostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
                self.titleLabel.hidden = NO;
                self.mainValueLabel.hidden = NO;
                self.realizedPnlTitleLabel.hidden = YES;
                self.realizedPnlValueLabel.hidden = YES;
                self.unRealizedPnlTitleLabel.hidden = YES;
                self.unRealizedPnlValueLabel.hidden = YES;
                self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l_ratio", nil);
                
                double unRealizedPnlRate = orderModel.orderPnlResp.openUnrealizedPnlPercent.doubleValue;
                NSString *valueString = [TBStock formatterFromPercentNumber:@(unRealizedPnlRate) needValuePrefix:YES];
                self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
                [self setImageAndDescWithNumber:unRealizedPnlRate];
                displayValueRatio = orderModel.orderPnlResp.openUnrealizedPnlPercent;
            }
        }
    }
    //未平仓
    else if (orderModel.openUnrealizedPnl.doubleValue != 0 && orderModel.openRealizedPnl.doubleValue == 0 && orderIsOmnibusOpen) {
        self.titleLabel.hidden = NO;
        self.mainValueLabel.hidden = NO;
        if (self.shareType == TBCardShareTypeOrderProfitLossAmount) {
            self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l", nil);

            NSString *string = [self displayStringWithCurrency:currency profitValue:orderModel.openUnrealizedPnl];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
            [self setImageAndDescWithNumber:orderModel.openUnrealizedPnl.doubleValue * exchangeRateNumber.doubleValue];
            displayValueAmount = orderModel.openUnrealizedPnl;
        } else if (self.shareType == TBCardShareTypeOrderProfitLossRatio) {
            self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l_ratio", nil);

            double unRealizedPnlRate = orderModel.orderPnlResp.openUnrealizedPnlPercent.doubleValue;
            NSString *valueString = [TBStock formatterFromPercentNumber:@(unRealizedPnlRate) needValuePrefix:YES];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
            [self setImageAndDescWithNumber:unRealizedPnlRate];
            displayValueRatio = orderModel.orderPnlResp.openUnrealizedPnlPercent;
        }
    } else {
        //全部平仓
        if (orderModel.openRealizedPnl.doubleValue != 0 && orderModel.openUnrealizedPnl.doubleValue == 0 && orderIsOmnibusOpen) {
            // 如果是平均成本Avg Cost 算法 :只有未实现盈亏，且提示该订单已清仓
            if ([TBService(TBTradeBusinessComponentService) tbTradeBusiness_isAVERAGECostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
                if (self.shareType == TBCardShareTypeOrderProfitLossAmount) {
                    self.titleLabel.hidden = NO;
                    self.mainValueLabel.hidden = NO;
                    self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l", nil);
                    [self setImageAndDescWithNumber:orderModel.openUnrealizedPnl.doubleValue * exchangeRateNumber.doubleValue];
                    displayValueAmount = orderModel.openUnrealizedPnl;
                } else if (self.shareType == TBCardShareTypeOrderProfitLossRatio) {
                    self.titleLabel.hidden = NO;
                    self.mainValueLabel.hidden = NO;
                    self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_unrealized_p_l_ratio", nil);
                    double unRealizedPnlRate = orderModel.orderPnlResp.openUnrealizedPnlPercent.doubleValue;
                    [self setImageAndDescWithNumber:unRealizedPnlRate];
                    displayValueRatio = orderModel.orderPnlResp.openUnrealizedPnlPercent;
                }
                self.mainValueLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_order_closed", nil);
                self.mainValueLabel.font = MEDFONTO(18);
            } else {
                if (self.shareType == TBCardShareTypeOrderProfitLossAmount) {
                    self.titleLabel.hidden = NO;
                    self.mainValueLabel.hidden = NO;
                    self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_realized_p_l", nil);
                    
                    NSString *string = [self displayStringWithCurrency:currency profitValue:orderModel.openRealizedPnl];
                    self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
                    [self setImageAndDescWithNumber:orderModel.openRealizedPnl.doubleValue * exchangeRateNumber.doubleValue];
                    displayValueAmount = orderModel.openRealizedPnl;
                } else if (self.shareType == TBCardShareTypeOrderProfitLossRatio) {
                    self.titleLabel.hidden = NO;
                    self.mainValueLabel.hidden = NO;
                    self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_realized_p_l_ratio", nil);
                    
                    double realizedPnlRate = orderModel.orderPnlResp.openRealizedPnlPercent.doubleValue;
                    NSString *valueString = [TBStock formatterFromPercentNumber:@(realizedPnlRate) needValuePrefix:YES];
                    self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
                    [self setImageAndDescWithNumber:realizedPnlRate];
                    displayValueRatio = orderModel.orderPnlResp.openRealizedPnlPercent;
                }
            }
        }
        else {
            if (self.shareType == TBCardShareTypeOrderProfitLossAmount) {
                self.titleLabel.hidden = NO;
                self.mainValueLabel.hidden = NO;
                NSString *string = [self displayStringWithCurrency:currency profitValue:[orderModel realizedPnlBaseOnCurrentCostType]];
                if (orderModel.realizedPNL.doubleValue == 0 && orderIsOpen && IBTrade) {
                    orderModel.realizedPNL = @((orderModel.latestPrice.doubleValue - orderModel.avgFillPrice.doubleValue) * orderModel.realTotalQuantity.doubleValue);
                    string = [self displayStringWithCurrency:currency profitValue:orderModel.realizedPNL];
                }
                self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
                [self setImageAndDescWithNumber:[orderModel realizedPnlBaseOnCurrentCostType].doubleValue * exchangeRateNumber.doubleValue];
                displayValueAmount = [orderModel realizedPnlBaseOnCurrentCostType];
            } else if (self.shareType == TBCardShareTypeOrderProfitLossRatio) {
                self.titleLabel.hidden = NO;
                self.mainValueLabel.hidden = NO;
                self.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_p_l_ratio", nil);
                
                double realizedPnlRate = 0.0;
                if ([TBService(TBTradeBusinessComponentService) tbTradeBusiness_isFIFOCostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
                    // 先进先出 算法
                    realizedPnlRate = orderModel.orderPnlResp.realizedPnlPercent.doubleValue;
                    displayValueRatio = orderModel.orderPnlResp.realizedPnlPercent;
                } else if ([TBService(TBTradeBusinessComponentService) tbTradeBusiness_isAVERAGECostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
                    // 平均成本 算法
                    realizedPnlRate = orderModel.orderPnlResp.realizedPnlByAveragePercent.doubleValue;
                    displayValueRatio = orderModel.orderPnlResp.realizedPnlByAveragePercent;
                }
                
                NSString *valueString = [TBStock formatterFromPercentNumber:@(realizedPnlRate) needValuePrefix:YES];
                self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:valueString];
                [self setImageAndDescWithNumber:realizedPnlRate];
            }
            
        }
    }
    
    // 组装数据（分享到老虎社区使用）
    NSMutableDictionary *dataForTigerCommunity = [[NSMutableDictionary alloc] init];
    [dataForTigerCommunity tb_safeSetObject:displayValueAmount forKey:@"displayValueAmount"];
    [dataForTigerCommunity tb_safeSetObject:displayValueRatio forKey:@"displayValueRatio"];
    NSString *displayCostType = nil;
    if ([TBTradePositionSettingManager isFIFOCostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
        displayCostType = @"FIFO";
    } else if ([TBTradePositionSettingManager isAVERAGECostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
        displayCostType = @"AVERAGE";
    } else if ([TBTradePositionSettingManager isDILUTEDCostTypeWithSegType:[orderModel.secType tb_toSegType]]) {
        displayCostType = @"DILUTED";
    }
    [dataForTigerCommunity tb_safeSetObject:displayCostType forKey:@"displayCostType"];
    NSString *displayValueType = nil;
    if (self.shareType == TBCardShareTypeOrderProfitLossRatio) {
        displayValueType = @"Ratio";
    } else if (self.shareType == TBCardShareTypeOrderProfitLossAmount) {
        displayValueType = @"Amount";
    }
    [dataForTigerCommunity tb_safeSetObject:displayValueType forKey:@"displayValueType"];
    if (dataForTigerCommunity.count>0) {
        self.dicForTigerCommunity = [dataForTigerCommunity copy];
    }
}

- (void)setTradePositionItem:(TBTradeAPIPositionItemModel *)tradePositionItem {
    _tradePositionItem = tradePositionItem;
    
    [self hideLastPriceItem];
    
    // 盈亏金额 标题
    self.titleLabel.text = TBResourcesLocalizedString(@"mobile_ios_common_pl_4", nil);
    
    // 盈亏金额值
    NSString *currency = self.tradePositionItem.currency;
    if (!TextValid(self.tradePositionItem.currency)) {
        currency = @"";
    }
    currency = TextValid(currency) ? [NSString stringWithFormat:@" %@",currency] : currency;
    NSString *price = self.tradePositionItem.unrealPnlBasedOnCostType ? [TBStock formatterPrefixPrice:self.tradePositionItem.unrealPnlBasedOnCostType market:@""] : DEFAULT_PRICE_VALUE;
    NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
    self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
    //值的颜色暂不区分
    //        [self.mainValueLabel setTextColor:[self getCorrectColorWithChange:self.tradePositionItem.unrealPnlBasedOnCostType.doubleValue]];
    
    // 表情 & 文案
    NSNumber *exchangeRateNumber = [[TBExchangeRateManager sharedInstance].exchangeRateDictionary valueForKey:self.tradePositionItem.currency];
    /*将货币按汇率换成美元*/
    double unrealPnl = self.tradePositionItem.unrealPnlBasedOnCostType.doubleValue;
    if ([_tradePositionItem.secType tb_isFutures]) {
        unrealPnl = _tradePositionItem.futuresRealPnl.doubleValue;
    }
    if (exchangeRateNumber) {
        unrealPnl = exchangeRateNumber.doubleValue * self.tradePositionItem.unrealPnlBasedOnCostType.doubleValue;
    }
    [self setImageAndDescWithNumber:unrealPnl];
    
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
    if (isOption) {
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
    self.costPriceView.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_filled_price", nil);
    if ([_tradePositionItem.secType tb_isFutures] && TextValid(_tradePositionItem.futuresAverageCost)) {
        self.costPriceView.valueLabel.text = _tradePositionItem.futuresAverageCost;
    } else {
        self.costPriceView.valueLabel.text = [TBStock formatterPrice:averageCost market:_tradePositionItem.market secType:_tradePositionItem.secType];
    }
}


#pragma mark - tool
// 隐藏最新价格模块
- (void)hideLastPriceItem {
    self.lastPriceView.hidden = YES;
    
    CGFloat firstItemLeftOffset = 4;
    [_costPriceView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self.line_1.mas_trailing).offset(0);
        make.trailing.equalTo(self.mas_trailing).offset(-firstItemLeftOffset);
        make.width.equalTo(_symbolView);
        make.top.equalTo(_symbolView);
    }];
}

- (NSString *)displayStringWithCurrency:(NSString *)currency profitValue:(NSNumber *)profitValue {
    currency = TextValid(currency) ? [NSString stringWithFormat:@" %@",currency] : currency;
    NSString *price = profitValue ? [TBStock formatterPrefixPrice:profitValue market:@""] : DEFAULT_PRICE_VALUE;
    NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
    return string;
}

- (void)updateCardBackgroundColorAndTextColorWithStickerIndex:(NSInteger)index {
    [super updateCardBackgroundColorAndTextColorWithStickerIndex:index];
    NSInteger colorValue = [self textColorWithIndex:index withShareType:self.shareType];
    self.titleLabel.textColor = RGBACOLOR_HEX(colorValue, 0.6);
    self.suffixTitleTagLabel.textColor = RGBACOLOR_HEX(colorValue, 0.6);
    self.suffixTitleTagLabel.layer.borderColor =  RGBACOLOR_HEX(colorValue, 0.6).CGColor;
    self.mainValueLabel.textColor = RGBACOLOR_HEX(colorValue, 1);
    self.line_1.backgroundColor = RGBACOLOR_HEX(colorValue, 0.12);
    self.line_2.backgroundColor = RGBACOLOR_HEX(colorValue, 0.12);
    self.realizedPnlValueLabel.textColor = RGBACOLOR_HEX(colorValue, 1);
    self.realizedPnlTitleLabel.textColor = RGBACOLOR_HEX(colorValue, 0.6);
    self.unRealizedPnlValueLabel.textColor = RGBACOLOR_HEX(colorValue, 1);
    self.unRealizedPnlTitleLabel.textColor = RGBACOLOR_HEX(colorValue, 0.6);
    self.symbolView.textColorValue = colorValue;
    self.lastPriceView.textColorValue = colorValue;
    self.costPriceView.textColorValue = colorValue;
}

//stickerTest
- (void)updateMainValue {
    if (TextValid(self.valueTextField.text)) {
        [self setImageAndDescWithNumber:[self.valueTextField.text doubleValue]];
        if (self.orderModel) {
            NSString *currency = self.orderModel.currency;
            if (!TextValid(self.orderModel.currency)) {
                currency = @"";
            }
            NSString *price = self.valueTextField.text;
            NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
        } else if (self.tradePositionItem) {
            // 盈亏金额值
            NSString *currency = self.tradePositionItem.currency;
            if (!TextValid(self.tradePositionItem.currency)) {
                currency = @"";
            }
            NSString *price = self.valueTextField.text;
            NSString *string = [NSString stringWithFormat:@"%@%@",price,currency];
            self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
        }
    }
}

- (TBPaddingLabel *)suffixTitleTagLabel {
    if (!_suffixTitleTagLabel) {
        _suffixTitleTagLabel = [[TBPaddingLabel alloc] initWithFrame:CGRectZero font:FONTO(10) color:COLOR_CARD_SHARE(0.6) text:@""];
        _suffixTitleTagLabel.contentInsets = UIEdgeInsetsMake(0, 4, 0, 4);
        _suffixTitleTagLabel.layer.borderColor = COLOR_CARD_SHARE(0.6).CGColor;
        _suffixTitleTagLabel.layer.borderWidth = K_1PX;
        _suffixTitleTagLabel.layer.cornerRadius = 2;
        _suffixTitleTagLabel.clipsToBounds = YES;
        _suffixTitleTagLabel.textAlignment = NSTextAlignmentCenter;
        _suffixTitleTagLabel.hidden = YES;
    }
    return _suffixTitleTagLabel;
}

@end
#endif
