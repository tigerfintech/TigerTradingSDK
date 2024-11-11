//
//  TBOmnibusAPIAssetModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOmnibusAssetDetailModel;
@protocol TBOmnibusAssetsByCurrencyModel;
@protocol TBOmnibusAnalysisAssetItemAllocationModel;


@interface TBOmnibusAPIAssetModel : TBOmnibusAPIModel <TBAsset>

@property (nonatomic, strong) NSNumber *dayTradesRemaining;
@property (nonatomic, strong) NSNumber *dayTradesRemainingT1;
@property (nonatomic, strong) NSNumber *dayTradesRemainingT2;
@property (nonatomic, strong) NSNumber *dayTradesRemainingT3;
@property (nonatomic, strong) NSNumber *dayTradesRemainingT4;

@property (nonatomic, copy) NSString *accountType;                              // CASH 或者 MARGIN
@property (nonatomic, strong) NSNumber *cashBalance;                            // 现金余额, 单位是美元. 下面double类型的资金值单位也都是美元
@property (nonatomic, strong) NSNumber *accruedDividend;                        // 累计分红. 指的是所有已执行但仍未支付的分红累加值
@property (nonatomic, strong) NSNumber *accruedInterest;                        // 累计利息, 指尚未结算的所有每日利息之和
@property (nonatomic, strong) NSNumber *idleCashInterest;                       // 闲置资金产生的的利息, 目前只TBAU牌照存在
@property (nonatomic, strong) NSNumber *grossPositionValue;                     // 总持仓市值
@property (nonatomic, strong) NSNumber *equityWithLoan;                         // 具有借贷价值的资产值, 对于现金账户 = cashBalance, 对于保证金账户 = cashBalance + grossPositionValue
@property (nonatomic, strong) NSNumber *netLiquidation;                         // 经清算价值. 相当于总资产 = cashBalance + accruedDividend + accrudeInterest + grossPositionValue
@property (nonatomic, strong, nullable) NSNumber <Optional> *initialMarginReq;  // 初始保证金要求, 仅保证金账户有此属性.
@property (nonatomic, strong, nullable) NSNumber <Optional> *marginReq;         // 初始保证金要求, 映射期货的initMarginReq
@property (nonatomic, strong, nullable) NSNumber <Optional> *maintainMarginReq; // 维持保证金要求, 仅保证金账户有此属性
@property (nonatomic, strong) NSNumber *excessEquity;                           // 剩余资产 = equityWithLoan - initMarginReq (现金账户初始保证金为0)
@property (nonatomic, strong) NSNumber *excessLiquidation;                      // 剩余流动性 = equityWithLoan - maintainMarginReq
@property (nonatomic, strong) NSNumber *overnightLiquidation;                   // 隔夜风控值 = equityWithLoan - overnightMarginReq
@property (nonatomic, strong) NSNumber *buyingPower;                            // 购买力. 如果资产>=2000美元的Margin账户, 此值 = 2 * excessEquity; 否则 = excessEquity
@property (nonatomic, strong) NSNumber *availableBuyingPower;                   // 可用购买力. 如果资产>=2000美元的Margin账户, 此值 = 2 * availableEE; 否则 = availableEE
@property (nonatomic, strong) NSNumber *availableEE;                            // 可用剩余资产 = excessEquity - lockedEE. 可取现金也是此值
@property (nonatomic, strong) NSNumber *lockedEE;                               // 已锁定的剩余资产
@property (nonatomic, strong) NSNumber *leverage;                               // 杠杆率 = grossPositionValue / netLiquidation
@property (nonatomic, strong) NSNumber *level;                                  // level = 2表示可以融资，level = 1表示不能融资(cash账户或者margin账户equityWithLoan < 2000USD)
@property (nonatomic, strong) NSNumber <Optional> *unrealizedPnl;              // 未实现盈亏(FIFO)
@property (nonatomic, strong) NSNumber <Optional> *unrealizedPnlByCostOfCarry; // 未实现盈亏(摊薄成本)
@property (nonatomic, strong) NSNumber <Optional> *unrealizedPnlByAverage;     // 未实现盈亏(平均成本)
@property (nonatomic, strong) NSNumber <Optional> *realizedPnl;                // 已实现盈亏
@property (nonatomic, strong) NSNumber <Optional> *realizedPnlByFifo;          // 已实现盈亏-FIFO
@property (nonatomic, strong) NSNumber <Optional> *realizedPnlByAverage;       // 已实现盈亏-AVG
@property (nonatomic, strong) NSNumber <Optional> *totalPositionPnlIncludeZero;          // 总持仓盈亏（包含0持仓），长连接返回
@property (nonatomic, strong) NSNumber <Optional> *realizedPnlByFifoIncludeZero;          // 已实现盈亏-FIFO（包含0持仓），长连接返回
@property (nonatomic, strong) NSNumber <Optional> *realizedPnlByAverageIncludeZero;       // 已实现盈亏-AVG（包含0持仓），长连接返回

@property (nonatomic, strong, nullable) TBOmnibusAssetDetailModel <Optional> *detail; // 资产详情信息, 仅测试环境接口有此属性

@property (nonatomic, copy) NSArray<TBOmnibusAssetsByCurrencyModel, Optional> *assetsByCurrency; // 货币兑换
@property (nonatomic, copy) NSArray<TBOmnibusDelayQuoteInfo> *delayQuotes;                       // 延迟行情数据

@property (nonatomic, copy) NSString <Optional>*currency;
@property (nonatomic, strong) NSNumber <Optional>*riskRate;
@property (nonatomic, strong) NSNumber <Optional>*risk;
@property (nonatomic, strong) NSNumber <Optional>*todayPnl;
@property (nonatomic, strong) NSNumber <Optional>*todayRealizedPnl;

@property (nonatomic, strong) NSNumber *intradayRiskRatio;    //!< 综合账户专属日内风险度 = MM/ELV(期货为NLV)
@property (nonatomic, strong) NSNumber *overnightRiskRatio;   //!< 综合账户专属隔夜风险度 = Overnight MM/ELV(期货为NLV)
@property (nonatomic, strong) NSNumber *overnightMarginReq;   //!< 综合账户专属隔夜保证金

@property (nonatomic, copy) NSString *intradayRiskLevel;   //!<  true | HIGH / VERY_HIGH / HIGHEST / LOW (日内风控危险>90%/日内风控危险>95%/日内风控危险>100%/不危险)
@property (nonatomic, copy) NSString *overnightRiskLevel;   //!< true | VERY_HIGH / HIGHEST / LOW (隔夜风控危险>95%/隔夜风控危险>100%/不危险)

@property (nonatomic, copy) NSDictionary *forexRateMap;///< 汇率列表，现仅在综合账户下有值


@property (nonatomic, strong) NSNumber *totalTodayPnl;  ///< 当日盈亏

@property (nonatomic, copy) NSString *pdtStatus;                  // pdt状态 [NONE, NORMAL, RESTRICTED]
@property (nonatomic, strong) NSNumber *pdtBuyingPower;             // pdtStatus为非NONE时，使用此购买力代替buyingPower
@property (nonatomic, strong) NSNumber *pdtAvailableBuyingPower;    // pdtStatus为非NONE时，使用此可用购买力代替availableBuyingPower
@property (nonatomic, strong) NSNumber *availableT2SettledCash;     // marsco 现金账户，已结算资金
@property (nonatomic, strong) NSNumber *instantDeposit;             // instantDeposit
@property (nonatomic, strong) NSNumber *creditLineAmount;           // TBHK信用借款额度;
@property (nonatomic, copy) NSString *limitMode;///< 如果值为 BROKER_LIQUIDATION 时，判断为特殊情况 https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=74949975

@property (nonatomic, copy) NSArray<TBOmnibusAnalysisAssetItemAllocationModel> *assetAllocation;///< 资产分布

@property (nonatomic, strong) NSNumber *accumulatedInterest;///< 累计收益（由 fund-business 提供）
@property (nonatomic, copy) NSArray *consolidatedSegTypes;///< 综合账户是否为合并购买力判断 count > 0

@property (nonatomic, strong) NSNumber *totalPositionPnl;

@property (nonatomic, copy) NSString *segType;
@property (nonatomic, copy) NSString *portfolioName;
@property (nonatomic, strong) NSNumber *portfolioId;
@property (nonatomic, strong) NSNumber *uncollected;// 806-在途资金，只有综合账户证券使用，900 基金在途资产

/// 今日盈亏率 806 新增
@property (nonatomic, strong) NSNumber *totalTodayPnlPercent;

@property (nonatomic, strong) NSNumber *accruedAccountManagementFee;     //FA 账户管理费
@property (nonatomic, strong) NSNumber *accruedAccountManagementFeeGst;  //FA 账户管理费消费税

/// 913 contra账户使用
@property (nonatomic, strong) TBOmnibusContraAssetInfoModel *contraAssetInfo;
@property (nonatomic, strong) NSNumber *cdpAvailableSellLimit;      // Contra CDP 可用sell limit


@end

NS_ASSUME_NONNULL_END
