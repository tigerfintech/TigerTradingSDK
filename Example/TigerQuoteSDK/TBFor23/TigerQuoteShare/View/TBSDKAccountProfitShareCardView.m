//
//  TBSDKAccountProfitShareCardView.m
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/18.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)

#import "TBSDKAccountProfitShareCardView.h"
#import <TBBaseKit/TBBaseKit.h>
#import <TBUIKit/TBUIKit.h>
#import <TBTradeBusinessBaseKit/TBTradeAssetTodayPnLShareInfoModel.h>
#import <TBBusinessSupportKit/TBStock+TBFormat.h>
#import <TBShareKit/TBCardShareUtil.h>

@interface TBSDKAccountProfitShareCardView ()

@property (nonatomic, strong) UILabel *titleLabel; // 标题（浮动收益）
@property (nonatomic, strong) UILabel *mainValueLabel;

@end

@implementation TBSDKAccountProfitShareCardView

// 重写父类方法，返回分享值type
- (TBCardShareValueType)cardShareValueType {
    TBCardShareValueType type = TBCardShareValueTypeAmount;
    
    if (self.shareType == TBCardShareTypeAccountShareTradeCount) {
        type = TBCardShareValueTypeCount;
    } else if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossRatio) { // 比例
        type = TBCardShareValueTypeRatio;
    } else if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossAmount ||
               self.shareType == TBCardShareTypeAccountSharePortfolioProfitLoss ||
               self.shareType == TBCardShareTypeAccountShareSecuritiesTotal) { // 金额
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
        make.top.equalTo(self.stickerImageView.mas_bottom).offset(30);
        make.centerX.equalTo(self);
    }];
    
    _mainValueLabel = [[UILabel alloc] initWithFont:MEDFONTO(42) color:COLOR_CARD_SHARE(1)];
    _mainValueLabel.textAlignment = NSTextAlignmentCenter;
    [self addSubview:_mainValueLabel];
    [_mainValueLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(_titleLabel.mas_bottom);
        make.height.equalTo(@54);
        make.centerX.equalTo(self);
    }];
}

- (void)setTodayPnLInfoModel:(TBTradeAssetTodayPnLShareInfoModel *)todayPnLInfoModel {
    _todayPnLInfoModel = todayPnLInfoModel;
    NSNumber *imageAndDescDependsValue = nil;
    NSNumber *value = nil;
    NSString *labelTitle = nil;
    NSString *currency = self.todayPnLInfoModel.currency;
    if (!TextValid(currency)) {
        currency = @"";
    }
    if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossAmount) {
        value = self.todayPnLInfoModel.shareAmount;
        imageAndDescDependsValue = self.todayPnLInfoModel.originShareAmount;
        labelTitle = _todayPnLInfoModel.shareAmountTitle;
    } else if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossRatio) {// 今日盈亏比例
        imageAndDescDependsValue = self.todayPnLInfoModel.pnlPercent;
        labelTitle = TBResourcesLocalizedString(@"mobile_comm_common_daily_pnlx", nil);
        currency = @"";// 分享盈亏比例时不显示币种
    } else if (self.shareType == TBCardShareTypeAccountSharePortfolioProfitLoss || self.shareType == TBCardShareTypePortfolioUnrealizedProfitLossAmount) {
        value = self.todayPnLInfoModel.portfolioPnlValue;
        imageAndDescDependsValue = self.todayPnLInfoModel.originPortfolioPnlValue;
        labelTitle = todayPnLInfoModel.portfolioPnlTitle;
    } else if (self.shareType == TBCardShareTypeAccountShareSecuritiesTotal) {
        value = self.todayPnLInfoModel.securitiesTotalValue;
        imageAndDescDependsValue = self.todayPnLInfoModel.originSecuritiesTotalValue;
        labelTitle = todayPnLInfoModel.securitiesTotalTitle;
    } else if (self.shareType == TBCardShareTypeAccountShareTradeCount) {
        value = self.todayPnLInfoModel.tradeCount;
        imageAndDescDependsValue = self.todayPnLInfoModel.tradeCount;
        labelTitle = todayPnLInfoModel.tradeCountTitle;
        currency = TBResourcesLocalizedString(@"mobile_comm_common_trades_orders", nil);
    }
    [self setImageAndDescWithNumber:imageAndDescDependsValue.doubleValue];
    self.titleLabel.text = labelTitle;
    NSString *title = DEFAULT_PRICE_VALUE;
    if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossRatio) {
        title = [[TBStock sharedPercentFormatter] stringForObjectValue:self.todayPnLInfoModel.pnlPercent];
    } else if (self.shareType == TBCardShareTypeAccountShareTradeCount) {
        title = value ? [NSString stringWithFormat:@"%@",value] : @"0";
    } else {
        if (value.doubleValue != 0) {
            title = [TBStock emptyCurrencyPnlStyleNumberFormatString:value.doubleValue];
        } else {
            title = @"0.00";
        }
    }
    currency = TextValid(currency) ? [NSString stringWithFormat:@" %@",currency] : currency;
    NSString *string = [NSString stringWithFormat:@"%@%@",title,currency];
    if (self.shareType == TBCardShareTypeAccountShareTradeCount) {
        self.mainValueLabel.attributedText = [self countAttributedStringWithString:string];
    } else {
        self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
    }
}

#pragma mark - tool

- (void)updateCardBackgroundColorAndTextColorWithStickerIndex:(NSInteger)index {
    [super updateCardBackgroundColorAndTextColorWithStickerIndex:index];
    NSInteger colorValue = [self textColorWithIndex:index withShareType:self.shareType];
    self.titleLabel.textColor = RGBACOLOR_HEX(colorValue, 0.6);
    self.mainValueLabel.textColor = RGBACOLOR_HEX(colorValue, 1);
}

- (NSAttributedString *)countAttributedStringWithString:(NSString *)string {
    if (!TextValid(string)) {
        return nil;
    }
    NSMutableAttributedString *attributedStr = [[NSMutableAttributedString alloc] initWithString:string];
    NSString *key = TBResourcesLocalizedString(@"mobile_comm_common_trades_orders", nil);
    NSRange keyRange = [string rangeOfString:key];
    if(keyRange.location != NSNotFound) {
        [attributedStr addAttribute:NSFontAttributeName value:MEDFONTO(42) range:NSMakeRange(0, keyRange.location)];
        [attributedStr addAttribute:NSFontAttributeName value:MEDFONTO(24) range:keyRange];
    }
    return attributedStr;
}

// 更新埋点数据
- (void)updateSaDictionary {
    if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossRatio) {
        [self.saDicationary tb_safeSetObject:@"盈亏比例" forKey:@"sub_type"];
    } else if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossAmount){
        [self.saDicationary tb_safeSetObject:@"盈亏金额" forKey:@"sub_type"];
    } else if (self.shareType == TBCardShareTypeAccountSharePortfolioProfitLoss){
        [self.saDicationary tb_safeSetObject:@"持仓盈亏" forKey:@"sub_type"];
    } else if (self.shareType == TBCardShareTypeAccountSharePortfolioRatio){
        [self.saDicationary tb_safeSetObject:@"持仓占比" forKey:@"sub_type"];
    } else if (self.shareType == TBCardShareTypeAccountShareSecuritiesTotal){
        [self.saDicationary tb_safeSetObject:@"证券价值" forKey:@"sub_type"];
    } else if (self.shareType == TBCardShareTypeAccountShareTradeCount){
        [self.saDicationary tb_safeSetObject:@"交易笔数" forKey:@"sub_type"];
    }
}

//stickerTest
- (void)updateMainValue {
    if (TextValid(self.valueTextField.text)) {
        [self setImageAndDescWithNumber:[self.valueTextField.text doubleValue]];
        
        NSString *currency = self.todayPnLInfoModel.currency;
        if (!TextValid(currency)) {
            currency = @"";
        }
        if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossAmount) {
        } else if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossRatio) {// 今日盈亏比例
            currency = @"";// 分享盈亏比例时不显示币种
        } else if (self.shareType == TBCardShareTypeAccountSharePortfolioProfitLoss) {
            
        } else if (self.shareType == TBCardShareTypeAccountShareSecuritiesTotal) {
            
        } else if (self.shareType == TBCardShareTypeAccountShareTradeCount) {
        
            currency = TBResourcesLocalizedString(@"mobile_comm_common_trades_orders", nil);
        }
        NSNumber *value = [NSNumber numberWithString:self.valueTextField.text];
        NSString *title = DEFAULT_PRICE_VALUE;
        if (self.shareType == TBCardShareTypeAccountShareTodayProfitLossRatio) {
            title = [[TBStock sharedPercentFormatter] stringForObjectValue:value];
        } else if (self.shareType == TBCardShareTypeAccountShareTradeCount) {
            title = value ? [NSString stringWithFormat:@"%@",value] : @"0";
        } else {
            if (value.doubleValue != 0) {
                title = [TBStock emptyCurrencyPnlStyleNumberFormatString:value.doubleValue];
            } else {
                title = @"0.00";
            }
        }
        currency = TextValid(currency) ? [NSString stringWithFormat:@" %@",currency] : currency;
        NSString *string = [NSString stringWithFormat:@"%@%@",title,currency];
        self.mainValueLabel.attributedText = [self mainValueAttributedStringWithValueString:string];
    }
}
@end
#endif
