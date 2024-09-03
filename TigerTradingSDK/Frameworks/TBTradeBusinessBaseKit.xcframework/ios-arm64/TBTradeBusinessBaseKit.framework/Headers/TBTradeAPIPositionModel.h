//
//  TBTradeAPIPositionModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/25.
//

#import "TBTradeAPIModel.h"
#import "TBPositionLabelTypes.h"
#import "TBOmnibusAPIPositionFcnRespModel.h"
#import "TBOmnibusAPIPositionCCRespModel.h"

@protocol TBTradeAPIOrderItemModel;


NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *const kTBTradeAPIPositionItemModelDirectionKey;
FOUNDATION_EXTERN NSString *const kTBTradeAPIPositionItemModelActionKey;

#pragma mark - 持仓
@protocol TBTradeAPIPositionItemModel;

@interface TBTradeAPIPositionModel : TBTradeAPIModel

@property (nonatomic, copy) NSArray<TBTradeAPIPositionItemModel> *items;

@end

@interface TBTradeAPIPositionItemModel : JSONModel

@property (nonatomic, strong) NSNumber *contractId;     // 合约ID, 持仓显示模式为Strategy时存在
@property (nonatomic, copy) NSString *positionKey;      // 持仓唯一标识
@property (nonatomic, strong) NSNumber *portfolioId;    // 综合账户FA
@property (nonatomic, copy) NSString *portfolioName;    // 综合账户FA存在意义，类似于segType的概念
@property (nonatomic, copy) NSString *symbol;           // 股票代码
@property (nonatomic, copy) NSString *localSymbol;      // 港股涡轮牛熊证使用这个唯一标识，不可以使用 originSymbol
@property (nonatomic, copy) NSString *originSymbol;     // 股票同symbol, 期权四要素拼接而成,格式：{symbol expir strike right}, 如"AAPL 20170721 141.0 CALL"
@property (nonatomic, copy) NSString *underlyingSymbol; // 底层股票代码 港股期权对应的正股代码 用于社区港股期权跳转正股
@property (nonatomic, copy) NSString *underlyingContractName; //关联正股合约名称
@property (nonatomic, copy) NSString *stockId;          // 股票Id(symbol+market) 对于A股是symbol+交易所, 可用于区分SH/SZ

@property (nonatomic, copy) NSString *mlegsSingleSymbol;///< 组合期权中单个期权名称
@property (nonatomic, copy) NSString *mlegsCombinedSymbol;///< 组合期权策略代码
@property (nonatomic, copy, readonly) NSString *communityMlegSymbol;///< 用于社区跳转的组合期权策略代码

@property (nonatomic, copy) NSString *nameCN;           // 中文名
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *exchange;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *secSubType;
@property (nonatomic, copy) NSString *strike;           // 期权底层价格
@property (nonatomic, copy) NSString *right;            // 期权PUT/CALL
@property (nonatomic, copy) NSString *expiry;           // 期权过期日 格式yyyyMMdd
@property (nonatomic, copy) NSString *action;
@property (nonatomic, strong) NSNumber *ratio;

@property (nonatomic, strong) NSNumber *multiplier;
@property (nonatomic, strong) NSNumber *latestPrice;    // 最新价格
@property (nonatomic, strong) NSNumber *preClose;       // 昨收价
@property (nonatomic, strong) NSNumber *lastClosePrice; // 最近收盘价盘前、盘中取左收价，盘后取今日收盘价

@property (nonatomic, strong) NSNumber *quoteLatestPrice;    // 根据行情权限请求最新价格

@property (nonatomic, strong) NSNumber *position;       // 持仓数目
@property (nonatomic, strong) NSNumber *positionScale;       // 持仓数目
@property (nonatomic, strong) NSNumber *realPosition;       // 持仓数目

@property (nonatomic, strong) NSNumber *realPnl;
@property (nonatomic, strong) NSNumber *salable;
@property (nonatomic, strong) NSNumber *salableQty;
@property (nonatomic, strong) NSNumber *availableQty;       ///< 905接口新增 可用持仓(对应原接口字段salableQty)
@property (nonatomic, strong) NSNumber *marketValue;

@property (nonatomic, copy) NSString *tradeCurrency;

@property (nonatomic, assign) NSInteger halted;//停牌状态 0: 正常 3: 停牌 4: 退市 7: 新股 8: 变更

@property (nonatomic, copy) NSString *futuresLatestPrice;    // 期货格式化后的最新的价格
@property (nonatomic, copy) NSString *futuresAverageCost;    // 期货格式化后的成本价
@property (nonatomic, copy) NSString *futuresRealPnl;        // 期货格式化后的实现盈亏


@property (nonatomic, strong) NSNumber *entitlementRatio; // 换股率

/// 主要针对港股：是否为lv0（延迟）行情
@property (nonatomic, assign) BOOL isLevel0Price;

@property (nonatomic, strong) NSNumber <Optional> *isOdd;///< 是否是港股碎股

@property (nonatomic, strong) NSNumber <Optional> *todayPnl; // 当日盈亏
@property (nonatomic, strong) NSNumber <Optional> *todayPnlPercent; // 今日盈亏占比
@property (nonatomic, strong) NSNumber <Optional> *positionsPercent; // 持仓占比
@property (nonatomic, strong) NSNumber <Optional> *mmPercent; // 保证金占比
@property (nonatomic, strong) NSNumber <Optional> *mmValue; // 维持保证金(随TBOmnibusAPIPositionModel添加)

@property (nonatomic, copy) NSArray *comboTypes;                    ///< 组合类型，没有组合则不返回
@property (nonatomic, copy) NSDictionary *comboTypeMap;             ///< 组合类型映射
@property (nonatomic, copy) NSArray<TBPositionLabelType> *labels;   ///< 持仓标签属性
@property (nonatomic, assign) NSInteger holdingPeriod;              ///< 持有天数（从最近一次开仓到当天的日历天数）随TBOmnibusAPIPositionModel添加
@property (nonatomic, assign) NSInteger isSingleLegOfMleg;          ///< 组合持仓下的单腿

// from Omnibus position model
@property (nonatomic, strong) NSNumber <Optional> *cumulativePnl;                            /// 累计盈亏(收益)
@property (nonatomic, strong) NSNumber <Optional> *positionPnl;                         /// 持仓盈亏 803 新增字段，综合账户
@property (nonatomic, strong) NSNumber <Optional> *realizedPnl;                         ///< 910-TT-FIFO下的已实现盈亏。 其他情况等于 positionPnl - unrealPnl 综合账户
@property (nonatomic, strong) NSNumber <Optional> *realizedPnlByAverage;                ///< 910 平均成本下的已实现盈亏
@property (nonatomic, strong) NSNumber <Optional> *yesterdayPnl;                        /// 昨日盈亏(收益)
@property (nonatomic, strong) NSNumber *averageCost;                                    // 平均成本 期权是1手成本
@property (nonatomic, strong) NSNumber <Optional> *averageCostOfCarry;                  // 累计持仓成本(A股模式计算方式)
@property (nonatomic, strong) NSNumber <Optional> *averageCostByAverage;                     // 累计持仓成本(平均成本)

@property (nonatomic, strong) NSNumber *unrealPnl;                                      // 浮动盈亏(FIFI)
@property (nonatomic, strong) NSNumber <Optional> *unrealPnlByCostOfCarry;              // 浮动盈亏(A股模式计算方式)
@property (nonatomic, strong) NSNumber <Optional> *unrealPnlPercentByCostOfCarry;       // 浮动盈亏率(A股模式计算方式)

@property (nonatomic, strong) NSNumber *unrealPnlPercent;                               // 浮动盈亏率(FIFI)
@property (nonatomic, strong) NSNumber <Optional> *unrealPnlByAverage;          // 浮动盈亏(平均成本)
@property (nonatomic, strong) NSNumber <Optional> *unrealPnlPercentByAverage;   // 浮动盈亏率(平均成本)

@property (nonatomic, strong) NSNumber *parentContractId;                       // 单腿所属的组合持仓contractId

@property (nonatomic, copy) NSArray<TBTradeAPIPositionItemModel> *legPositions;

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

- (NSString *)positionIdentifier;
- (NSString *)mqttTopic;
- (NSString *)stockUnderlyingSymbol;
- (NSString *)strategyKey;
- (NSString *)strategyName;
- (NSString *)strategyPositionDisplayName;
- (NSString *)strategyPositionDisplayName:(BOOL)isLitePage;
/**
 * 组合持仓里的单腿，返回dictionary，内容包括期权四要素+action ratio
 */
- (NSDictionary *)legContractInfoDictionary;

- (BOOL)isMarginReducation;   /// 是否保证金减免

/**
 * 判断当前持仓是否是组合持仓
 */
- (BOOL)isMlegPositionItemModel;

- (BOOL)isPortfolioPositionModel;

// 判断是否是0持仓
- (BOOL)isZeroPosition;

@end

NS_ASSUME_NONNULL_END
