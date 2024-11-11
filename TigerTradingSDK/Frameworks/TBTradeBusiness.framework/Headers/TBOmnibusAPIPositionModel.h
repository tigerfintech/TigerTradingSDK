//
//  TBOmnibusAPIPositionModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import <TBTradeBusinessBaseKit/TBPositionLabelTypes.h>
#import <TBTradeBusinessBaseKit/TBOmnibusAPIPositionFcnRespModel.h>
#import <TBTradeBusinessBaseKit/TBOmnibusAPIPositionCCRespModel.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 单股持仓

@protocol TBOmnibusAPIPositionModel;

@interface TBOmnibusAPIPositionModel : JSONModel

@property (nonatomic, strong) NSNumber *contractId;   // 合约ID, 持仓显示模式为Strategy时存在
@property (nonatomic, copy) NSString *positionKey;    // 持仓唯一标识
@property (nonatomic, strong) NSNumber *portfolioId;  // 综合账户FA
@property (nonatomic, copy) NSString *portfolioName;  // 综合账户FA存在意义，类似于segType的概念
@property (nonatomic, copy) NSString *symbol;       // 股票代码
@property (nonatomic, copy) NSString *nameCN;       // 股票名称
@property (nonatomic, copy) NSString *action;
@property (nonatomic, strong) NSNumber *ratio;
@property (nonatomic, copy) NSString *underlyingSymbol; ///< 底层股票代码 港股期权对应的正股代码 用于社区港股期权跳转正股
@property (nonatomic, copy) NSString *underlyingContractName; //关联正股合约名称
@property (nonatomic, copy) NSString <Optional> *market;       // 股票市场
@property (nonatomic, copy) NSString *exchange;                // 交易所标识
@property (nonatomic, assign) CGFloat latestPrice;       // 最新价
@property (nonatomic, strong) NSNumber *lastClosePrice;      // 最近收盘价盘前、盘中取左收价，盘后取今日收盘价
@property (nonatomic, strong) NSNumber *quoteLatestPrice;    // 根据行情权限请求最新价格

@property (nonatomic, assign) double position;   // 持仓数量
@property (nonatomic, assign) NSInteger positionScale;   // 持仓数量
@property (nonatomic, strong) NSNumber *realPosition;   // 持仓数量


// from Omnibus position model
@property (nonatomic, strong) NSNumber <Optional> *cumulativePnl;    /// 累计盈亏(收益)
@property (nonatomic, strong) NSNumber <Optional> *positionPnl; /// 持仓盈亏 803 新增字段，综合账户
@property (nonatomic, strong) NSNumber <Optional> *realizedPnl; ///< 等于 positionPnl - unrealPnl 综合账户
@property (nonatomic, strong) NSNumber <Optional> *realizedPnlByAverage; ///< 910 新增 平均成本下已实现盈亏

@property (nonatomic, strong) NSNumber *averageCost;                                    // 平均成本 期权是1手成本
@property (nonatomic, strong) NSNumber <Optional> *averageCostOfCarry;                  // 累计持仓成本(A股模式计算方式)
@property (nonatomic, strong) NSNumber <Optional> *averageCostByAverage;                     // 累计持仓成本(平均成本)

@property (nonatomic, strong) NSNumber *unrealPnl;                                      // 浮动盈亏(FIFI)
@property (nonatomic, strong) NSNumber *unrealPnlPercent;                               // 浮动盈亏率(FIFI)

@property (nonatomic, strong) NSNumber <Optional> *unrealPnlByCostOfCarry;              // 浮动盈亏(A股模式计算方式)
@property (nonatomic, strong) NSNumber <Optional> *unrealPnlPercentByCostOfCarry;       // 浮动盈亏率(A股模式计算方式)
@property (nonatomic, strong) NSNumber <Optional> *unrealPnlByAverage;                  // 浮动盈亏(平均成本)
@property (nonatomic, strong) NSNumber <Optional> *unrealPnlPercentByAverage;           // 浮动盈亏率(平均成本)

@property (nonatomic, assign) CGFloat marketValue;  // 市值
@property (nonatomic, strong) NSNumber <Optional>*multiplier;
@property (nonatomic, copy) NSString <Optional>*secType;
@property (nonatomic, copy) NSString <Optional>*secSubType;
@property (nonatomic, copy) NSString <Optional>*strike;           // 期权底层价格
@property (nonatomic, copy) NSString <Optional>*right;            // 期权PUT/CALL
@property (nonatomic, copy) NSString <Optional>*expiry;           // 期权过期日 格式yyyyMMdd
@property (nonatomic, copy) NSString <Optional> *currency;        // 币种

@property (nonatomic, copy) NSString <Optional> *originSymbol;    // 股票同symbol, 期权四要素拼接而成,格式：{symbol expir strike right}, 如"AAPL 20170721 141.0 CALL"

@property (nonatomic, strong) NSNumber <Optional>*entitlementRatio; // 换股率

@property (nonatomic, strong) NSNumber <Optional> *salable;      // 可卖数量
@property (nonatomic, strong) NSNumber <Optional> *salableQty;   // 新）可卖数量。https://app.asana.com/0/792932789264562/1202251595974874/f
@property (nonatomic, strong) NSNumber <Optional> *availableQty;    // 905接口新增 可用持仓(对应原接口字段salableQty)
@property (nonatomic, strong) NSNumber <Optional> *todayPnl;        // 今日盈亏额
@property (nonatomic, strong) NSNumber <Optional> *yesterdayPnl;    // 昨日盈亏(收益)
@property (nonatomic, strong) NSNumber <Optional> *todayRealizedPnl;
@property (nonatomic, strong) NSNumber <Optional> *todayPnlPercent; // 今日盈亏百分比
@property (nonatomic, strong) NSNumber <Optional> *openPnl; // 开仓盈亏
@property (nonatomic, strong) NSNumber <Optional> *positionsPercent; // 持仓占比
@property (nonatomic, strong) NSNumber <Optional> *mmPercent; // 保证金占比
@property (nonatomic, strong) NSNumber <Optional> *mmValue; // 维持保证金

/// 主要针对港股：是否为lv0（延迟）行情
@property (nonatomic, assign) BOOL isLevel0Price;

@property (nonatomic, strong) NSNumber <Optional> *isOdd;///< 是否是港股碎股

@property (nonatomic, copy) NSArray *comboTypes;            ///< 组合类型 COVERED_CALL/COVERED_PUT，没有组合 则不返回
@property (nonatomic, copy) NSDictionary *comboTypeMap;     ///< 组合类型映射
@property (nonatomic, copy) NSArray<TBPositionLabelType> *labels;   ///< 持仓标签属性
@property (nonatomic, assign) NSInteger holdingPeriod; // 持有天数（从最近一次开仓到当天的日历天数）

@property (nonatomic, copy) NSArray<TBOmnibusAPIPositionModel> *legPositions;

@property (nonatomic, copy) NSString *secGroupType; ///< 分组类型
@property (nonatomic, copy) NSString *contractExtraDescription; ///< 用于客户端展示，合约名称
@property (nonatomic, copy) NSString *contractMajorDescription; ///< 合约名称展示所需特殊字段拼接
@property (nonatomic, strong) NSNumber <Optional> *accruedInterest; ///< 应计利息

/**
 * 持仓盈亏率 （910添加）
 *
 * 说明：摊薄成本下使用
 * 当前使用范围：国债（以及新增secType时使用）
 */
@property (nonatomic, strong) NSNumber *positionPnlPercent;

/**
 * fcnResp fcn持仓数据 （915添加）
 *
 * - 长链接不更新此字段 by server 胡茗轩
 */
@property (nonatomic, strong) TBOmnibusAPIPositionFcnRespModel <Optional> *fcnResp;

/**
 * ccResp 数字货币持仓数据 （916添加）
 * - 长链接不更新此字段
 */
@property (nonatomic, strong) TBOmnibusAPIPositionCCRespModel <Optional> *ccResp;

/// 918 开发埋点记录信息
@property (nonatomic, copy, readonly) NSString *logInfoString;

@end

@interface TBOmnibusAPIPositionsModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusAPIPositionModel> *data;

@end

@interface TBOmnibusAPISymbolPositionModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusAPIPositionModel *data;

@end

@protocol TBOmnibusAPIPortfoioPositionModel;

@interface TBOmnibusAPIPortfolioPositionsModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusAPIPortfoioPositionModel> *data;

@end

@interface TBOmnibusAPIPortfoioPositionModel : JSONModel

@property (nonatomic, strong) NSNumber *portfolioId;
@property (nonatomic, copy) NSString *portfolioName;

@property (nonatomic, copy) NSArray<TBOmnibusAPIPositionModel> *positionDetails;            // 普通持仓视图对应数据
@property (nonatomic, copy) NSArray<TBOmnibusAPIPositionModel> *complexPositionDetails;     // 策略模式视图对应数据

@end

NS_ASSUME_NONNULL_END
