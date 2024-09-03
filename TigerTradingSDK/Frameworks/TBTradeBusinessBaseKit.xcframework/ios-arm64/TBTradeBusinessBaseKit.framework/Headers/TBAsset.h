//
//  TBAsset.h
//  Stock
//
//  Created by 董恭甫 on 2017/8/23.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#ifndef TBAsset_h
#define TBAsset_h

#import <UIKit/UIKit.h>
#import "TBOmnibusContraAssetInfoModel.h"

@protocol TBOmnibusAnalysisAssetItemAllocationModel;
@protocol TBOmnibusAssetsByCurrencyModel;
@protocol TBOmnibusDelayQuoteInfo;

//隔夜风控度
typedef NS_ENUM(NSInteger, TBAccountRiskLevel) {
    TBAccountRiskLevel_None = -1,
    TBAccountRiskLevel_VerySafe = 0,    //0
    TBAccountRiskLevel_Safe,            //0-50]
    TBAccountRiskLevel_Normal,          //50-70]
    TBAccountRiskLevel_EaryWarning,     //70-85]
    TBAccountRiskLevel_Warning,         //85-90]
    TBAccountRiskLevel_SeriousWarning   //90-100]
};

typedef NS_ENUM(NSUInteger, TBAccountType) {
    TBAccountIBCash = 1,             //!< IB现金账户
    TBAccountIBMargin,               //!< IB保证金账户
    TBAccountIBMarginLimit,          //!< IB保证金限制账户
    TBAccountOmnibusCash,            //!< Omnibus现金账户
    TBAccountOmnibusMargin,          //!< Omnibus保证金账户
    TBAccountOmnibusMarginLimit,     //!< Omnibus保证限制金账户
};

static NSString * const TBAssetCapabilityRegTMargin = @"Reg T Margin";
static NSString * const TBAssetCapabilityCash = @"Cash";

@protocol TBAsset <NSObject>

@property (nonatomic, readonly) NSNumber *netLiquidation;
@property (nonatomic, readonly) NSNumber *equityWithLoan;
@property (nonatomic, readonly) NSNumber *initialMarginReq;
@property (nonatomic, readonly) NSNumber *maintenanceMarginReq;
@property (nonatomic, readonly) NSNumber *availableFunds;
@property (nonatomic, readonly) NSNumber *dayTradesRemaining;
@property (nonatomic, readonly) NSNumber *dayTradesRemainingT1;
@property (nonatomic, readonly) NSNumber *dayTradesRemainingT2;
@property (nonatomic, readonly) NSNumber *dayTradesRemainingT3;
@property (nonatomic, readonly) NSNumber *dayTradesRemainingT4;
@property (nonatomic, readonly) NSNumber *excessLiquidity;
@property (nonatomic, readonly) NSNumber *buyingPower;
@property (nonatomic, readonly) NSNumber *cashBalance;
@property (nonatomic, readonly) NSNumber *usdCash;
@property (nonatomic, readonly) NSNumber *hkdCash;
@property (nonatomic, readonly) NSNumber *cnhCash;
@property (nonatomic, readonly) NSNumber *gbpCash;
@property (nonatomic, readonly) NSNumber *eurCash;
@property (nonatomic, readonly) NSNumber *nzdCash;
@property (nonatomic, readonly) NSNumber *audCash;                                // AUD现金
@property (nonatomic, readonly) NSNumber *sgdCash;                                // SGD现金
@property (nonatomic, readonly) NSNumber *jpyCash;
@property (nonatomic, readonly) NSNumber *settledCash;
@property (nonatomic, readonly) NSNumber *accruedCash;
@property (nonatomic, readonly) NSNumber *accruedDividend;
@property (nonatomic, readonly) NSNumber *accruedInterest;
@property (nonatomic, readonly) NSNumber *idleCashInterest;                       // 闲置资金产生的的利息, 目前只TBAU牌照存在
@property (nonatomic, readonly) NSNumber *grossPositionValue;
@property (nonatomic, readonly) NSNumber *regTEquity;
@property (nonatomic, readonly) NSNumber *regTMargin;
@property (nonatomic, readonly) NSNumber *cushion;
@property (nonatomic, readonly) NSNumber *totalPositionPnl;///< 周期内持仓盈亏综合
@property (nonatomic, readonly) NSNumber *unrealizedPnL;
@property (nonatomic, readonly) NSNumber *realizedPnl;        ///< 等于 positionPnl - unrealPnl 综合账户
@property (nonatomic, readonly, copy) NSString *currency;     ///< 账户的主币种，目前大部分为美元
@property (nonatomic, readonly, copy) NSString *capability;
@property (nonatomic, readonly) NSNumber *updateTime;
@property (nonatomic, readonly) NSNumber *level;
@property (nonatomic, readonly) NSNumber *sma;
@property (nonatomic, readonly) NSNumber *leverage;
@property (nonatomic, readonly) NSNumber *risk;
@property (nonatomic, readonly) NSNumber *dailyPnL;
@property (nonatomic, readonly) NSNumber *todayRealizedPnl;
@property (nonatomic, readonly) NSNumber *overnightLiquidation;
@property (nonatomic, readonly) NSNumber *excessLiquidation;
@property (nonatomic, readonly) NSNumber *intradayRiskRatio;    //!< 综合账户专属日内风险度 = MM/ELV(期货为NLV)
@property (nonatomic, readonly) NSNumber *overnightRiskRatio;   //!< 综合账户专属隔夜风险度 = Overnight MM/ELV(期货为NLV)
@property (nonatomic, readonly) NSNumber *overnightMarginReq;   //!< 综合账户专属隔夜保证金
@property (nonatomic, readonly) NSNumber *creditLineAmount;     //!< TBHK信用借款额度

@property (nonatomic, copy, readonly) NSString *intradayRiskLevel;   //!<  true | HIGH / VERY_HIGH / HIGHEST / LOW (日内风控危险>90%/日内风控危险>95%/日内风控危险>100%/不危险)
@property (nonatomic, copy, readonly) NSString *overnightRiskLevel;   //!< true | VERY_HIGH / HIGHEST / LOW (隔夜风控危险>95%/隔夜风控危险>100%/不危险)

@property (nonatomic, copy) NSString *intraDayRiskTriggered;///< 环球-日内风险提醒文案
@property (nonatomic, copy) NSString *overNightRiskTriggered;///< 环球-隔夜风险提醒文案

// 风控值，客户端自己计算
@property (nonatomic, readonly) NSNumber *riskControlValue;

/**
 在不加杠杆的条件下，可用于购买证券的保证金数额
 */
@property (nonatomic, readonly) NSNumber *leftLiquidity;

@property (nonatomic, copy) NSDictionary *forexRateMap;///< 汇率列表，现仅在综合账户下有值

@property (nonatomic, assign) TBAccountRiskLevel riskLevel;

@property (nonatomic, copy, readonly) NSString *riskLevelString;

@property (nonatomic, strong) UIColor *riskLevelColor;

@property (nonatomic, copy) NSArray<TBOmnibusAnalysisAssetItemAllocationModel> *assetAllocation;///< 资产分布
@property (nonatomic, copy) NSArray<TBOmnibusAssetsByCurrencyModel> *assetsByCurrency;          ///< 货币兑换
@property (nonatomic, copy) NSArray<TBOmnibusDelayQuoteInfo> *delayQuotes;                      ///< 延迟行情信息

/// 913 contra账户使用
@property (nonatomic, strong) TBOmnibusContraAssetInfoModel *contraAssetInfo;
@property (nonatomic, strong) NSNumber *cdpAvailableSellLimit;      // Contra CDP 可用sell limit
@optional

@property (nonatomic, readonly) NSNumber *previousEquityWithLoanValue;   // 未使用
@property (nonatomic, readonly) NSNumber *availableBuyingPower;
@property (nonatomic, readonly) NSNumber *lockedEE;
@property (nonatomic, readonly) NSNumber *totalTodayPnl;

@property (nonatomic, copy) NSString *pdtStatus;                  // pdt状态 [NONE, NORMAL, RESTRICTED]
@property (nonatomic, strong) NSNumber *pdtBuyingPower;            // pdtStatus为非NONE时，使用此购买力代替buyingPower

@property (nonatomic, strong) NSNumber *pdtAvailableBuyingPower;    // pdtStatus为非NONE时，使用此可用购买力代替availableBuyingPower
@property (nonatomic, strong) NSNumber *availableT2SettledCash;     //marsco 现金账户，已结算资金
@property (nonatomic, strong) NSNumber *instantDeposit;             // instantDeposit

@property (nonatomic, copy) NSString *limitMode;                    ///< 仅综合账号
@property (nonatomic, strong) NSNumber *accumulatedInterest;///< 累计收益（由 fund-business 提供）
@property (nonatomic, copy) NSArray *consolidatedSegTypes;///< 综合账户是否为合并购买力判断 count > 0

@property (nonatomic, copy) NSString *segType;
@property (nonatomic, copy) NSString *forexRateBaseCurrency;                ///< 查询资产时传递的币种，默认取主币种
/// 806-在途资金，只有综合账户证券使用，900 基金在途资产
@property (nonatomic, strong) NSNumber *uncollected;

/// 今日盈亏率 806 新增
@property (nonatomic, strong) NSNumber *totalTodayPnlPercent;

@property (nonatomic, strong) NSNumber *accruedAccountManagementFee;     //FA 账户管理费
@property (nonatomic, strong) NSNumber *accruedAccountManagementFeeGst;  //FA 账户管理费消费税

@property (nonatomic, readonly) NSNumber *portfolioId;                   //-1所有的聚合资产 0独立账户同segType=SEC 其他为portfolio
@property (nonatomic, readonly, copy) NSString *portfolioName;

@optional
- (BOOL)haveDebtMoney;

- (NSNumber *)availableCashWithCurrencyType:(NSString *)currency;

- (NSNumber *)availableEEWithCurrencyType:(NSString *)currency;

- (NSNumber *)cashBalanceWithCurrencyType:(NSString *)currency;

- (NSString *)limitModeDes;

- (NSNumber *)getUnrealizedPnL:(BOOL)useCostType;

- (NSNumber *)getUnrealizedPnlWithCostType:(NSString *)costType;

/// 判断是否为合并资产账户
- (BOOL)isConsolidatedAssets;

/// 判断是否为TradeUP PDT资产
- (BOOL)isTradeUPPdtUserAsset;

@end

#endif /* TBAsset_h */
