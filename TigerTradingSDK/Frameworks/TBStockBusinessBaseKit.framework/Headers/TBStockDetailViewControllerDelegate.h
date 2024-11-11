//
//  TBStockDetailViewControllerDelegate.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/3.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TBStockInfoDetailItemHourTradingModel;
@class TBFuturesContractModel;
@class TBStockDetailInfoNoticeModel;
@class TBStockInfoDetailItemModel;
@class TBAStockSymbolMetaItemModel;

typedef NS_ENUM(NSUInteger, TBStockDetailType) {
    TBStockDetailTypeUSStock, // 美股正股
    TBStockDetailTypeUSETF, // 美股ETF
    TBStockDetailTypeUSIndex, // 美股指数
    TBStockDetailTypeHKIndex, // 港股指数
    TBStockDetailTypeHKStock, // 港股
    TBStockDetailTypeCNIndex, // 沪深指数
    TBStockDetailTypeCNStock, // 沪深正股
    TBStockDetailTypeCNETF,   // 沪深基金
    TBStockDetailTypeHKWarrantIopt, // 窝轮牛熊证
    TBStockDetailTypeOptionDetail, // 期权详情页
    TBStockDetailTypeRight, // 股权
    TBStockDetailTypeFutrues, // 期货
    TBStockDetailTypeUKStock, // 伦敦
    TBStockDetailTypeUKIndexStock, // 伦敦
    TBStockDetailTypeSIDLCs, // 美股ETF
};

@class TBStockDetailInfoNoticeModel;
@class TBStockInfoDetailItemModel;
@class TBAStockSymbolMetaItemModel;
@class TBStockInfoDetailItemHourTradingModel;
@class TBFuturesContractModel;
@class TBListTableViewController;
@class TBStockOptionDataModel;

@protocol TBStockDetailInfoDataSource <NSObject>

@optional

#pragma mark --- 标的原始价格、昨收、涨跌额、涨跌幅
@property (nonatomic, readonly) NSNumber *stockLatestPrice; // 最新价格
@property (nonatomic, readonly) NSNumber *stockRealTimeLatestPrice; // 最新价格的实时价格（盘前盘后时为盘前盘后最新价格）
@property (nonatomic, readonly) NSNumber *stockPreClose;
@property (nonatomic, readonly) NSNumber *stockRealPreClose; // 真实的昨收价格（盘前时段的昨收为前天的昨收价格）
@property (nonatomic, readonly) NSNumber *stockChange; // 价格涨跌额
@property (nonatomic, readonly) NSNumber *stockChangePercent; // 价格涨跌百分比
@property (nonatomic, readonly) NSNumber *stockBidPrice; // 股票买盘价格
@property (nonatomic, readonly) NSNumber *stockBidSize; // 股票买盘数量
@property (nonatomic, readonly) NSNumber *treasuryBidYield;
@property (nonatomic, readonly) NSNumber *stockAskPrice; // 股票买盘价格
@property (nonatomic, readonly) NSNumber *stockAskSize; // 股票卖盘数量
@property (nonatomic, readonly) NSNumber *treasuryAskYield;
@property (nonatomic, readonly) NSNumber *treasuryYtm;  // 到期收益率
@property (nonatomic, readonly) NSNumber *treasuryFaceValue; // 票面价值
@property (nonatomic, readonly) NSString *dateStatus; //行情时间状态
@property (nonatomic, readonly) NSString *stockRiskRating; //标的风险等级

@property (nonatomic, readonly) NSNumber *etf; // 是否>1决定是否为杠杆etf
@property (nonatomic, readonly) NSString *stockDisplayLatestPriceTag;

#pragma mark ---- 用于展示的价格、个股信息
@property (nonatomic, readonly) NSString *stockDisplayLatestPrice;
@property (nonatomic, readonly) NSString *stockDisplayPriceChange;
@property (nonatomic, readonly) NSString *stockDisplayChangePercent;
@property (nonatomic, readonly) UIColor *stockChangeColor;

@property (nonatomic, readonly) NSString *stockDisplayBidPrice;
@property (nonatomic, readonly) NSString *stockDisplayAskPrice;
@property (nonatomic, readonly) NSString *stockDisplayBidSize;
@property (nonatomic, readonly) NSString *stockDisplayAskSize;

@property (nonatomic, readonly) NSString *stockNameCN; // 标的名称
@property (nonatomic, readonly) NSString *stockSymbol;
@property (nonatomic, readonly) NSString *combineOriginSymbol;
@property (nonatomic, readonly) NSString *optionUnderlyingSymbol; // 底层股票代码 港股期权对应的正股代码
@property (nonatomic, readonly) NSString *stockOriginSymbol;
@property (nonatomic, readonly) NSString *stockOptionSymbol;

@property (nonatomic, readonly) NSString *stockReferMainSymbol; //拆合股临时代码关联的主代码
@property (nonatomic, readonly) NSString *stockReferTempSymbol; //拆合股临时代码

@property (nonatomic, readonly) NSString *stockMarket; // 标的所属市场
/**
 
 标的类型
 STK 股票, OPT 期权，WAR：窝轮 IOPT：牛熊证 FUT:期货
 */
@property (nonatomic, readonly) NSString *stockSecType;

/**
 * 所在市场开盘状态 交易中、盘前、盘后
 */
@property (nonatomic, readonly) NSString *stockMarketSimpleStatus;

@property (nonatomic, readonly) NSArray<NSNumber *> *stockOpenAndCloseTimeList;  //所在市场开盘、收盘时间

/// 业务上使用的广义的证券类型, 如OPT和MLEG都算作期权, 各种配置/规则可以兼容期权接口
@property (nonatomic, readonly) NSString *stockGeneralSecType;

/**
 是否停牌
 0: 正常
 3: 停牌
 4: 退市
 */
@property (nonatomic, readonly) NSInteger stockHalted; // 停牌信息

/*
 股票是否处于交易时间
 */
@property (nonatomic, readonly) BOOL stockIsInTradingTime;
/*
 标的交易时间区间，同期货currentTradingTime
 二维数组：
 每个元素一个交易区间，同时每个元素索引0:open 1:close
 */
@property (nonatomic, readonly) NSArray *stockTradeTime;

/// 价格精度, 如果 server 想控制, 会通过个股数据结构返回
@property (nonatomic, readonly) NSNumber *stockMaxScale;

#pragma mark --- 以下属性，在下单页使用
@property (nonatomic, readonly) NSString *stockTradeCurrency; // 交易货币代号
@property (nonatomic, readonly) NSNumber *stockLotSize; // 每手股数
@property (nonatomic, readonly) NSNumber *stockLotSizeScale; // 小数量值，例如realLotSize = stockLotSize/stockLotSizeScale
@property (nonatomic, readonly) NSNumber *stockSpreadScale; // 报价精度, 0代表按价格区间决定精度, 1代表固定精度，3港股基金
@property (nonatomic, readonly) NSString *stockExchange; // 标的所在交易所

@property (nonatomic, readonly) NSNumber *mlegMidPrice; // MLEG下单类型，中间价

/**
 换股比率，期权默认是1
 */
@property (nonatomic, readonly) NSNumber *stockEntitlementRatio;

// 期权只有到期日, 窝轮牛熊证区分到日期和最后交易日, 前者用于展示, 后者用于接口
- (NSString *)expiryWithFormat:(NSString *)format; // 到期日
- (NSString *)lastTradingDateStringWithFormat:(NSString *)format; // 最后交易日
// 衍生品行权价
@property (nonatomic, readonly) NSString *derivativesStrike;
// call or put
@property (nonatomic, readonly) NSString *derivativesRight;

@property (nonatomic, readonly) TBStockInfoDetailItemHourTradingModel *stockHourTrading;             // 盘前盘后数据
@property (nonatomic, readonly) TBStockInfoDetailItemHourTradingModel *stockOvernightHourTrading;    // 夜盘数据
@property (nonatomic, readonly) BOOL isSupportOvernight; //标的是否支持夜盘

@property (nonatomic, readonly) TBStockOptionDataModel *stockOptionData;
#pragma mark --- 期货用
- (NSString *)displayStringFromNumber:(NSNumber *)number;
- (NSNumber *)priceNumberWithDisplayString:(NSString *)displayString;
- (BOOL)isFutureValidatePrice:(id)price;
@property (nonatomic, readonly) NSString *futuresQuotesDisplayType;
@property (nonatomic, readonly) NSString *futuresDisplayMinTick;

/**
 对于期货有主连合约和非主连合约之分，主连合约返回关联合约的symbol，非主连合约返回合约symbol
 */
@property (nonatomic, readonly) NSString *futuresRealSymbol; // 标的名称
@property (nonatomic, readonly) NSString *futuresRealNameCN; // 标的名称

@property (nonatomic, readonly) NSArray *availableOrderTypeArray;   // 支持的订单类型
//@property (nonatomic, readonly) TBFuturesContractModel *futuresContractModel; // 期货合约信息

/**
 个股详情页类型
 */
@property (nonatomic, readonly) TBStockDetailType detailType;

@optional
@property (nonatomic, readonly) NSString *ioptCallPrice; //!< 只有窝轮有的回收价
/**
 股票是否为指数：
 1、本地根据symbol判断
 2、server返回symbolType 字段判断:
 "symbolType": "index",  有这个字段且值是index就表示指数
 */
@property (nonatomic, readonly) BOOL stockIsIndex;

/**
 是否为OTC市场股票
 判断根据exchange判断：PINK,OTCQB,OTCQX
 目前不支持展示买卖盘口，不支持交易
 
 */
@property (nonatomic, readonly) BOOL stockIsOTC;

@property (nonatomic, readonly) BOOL stockIsDLC;
/**
 是否为数字货币期货
 */
@property (nonatomic, readonly) BOOL isDigitalCurrencyFutures;


//是否显示分隔符
- (NSString *)derivativesStrike:(BOOL)enableGroup;
- (NSString *)ioptCallPrice:(BOOL)enableGroup;
@property (nonatomic, readonly) BOOL stockIPOIsGreyMarket; // 是否处于暗盘

@property (nonatomic, readonly) NSTimeInterval stockQuoteServerTime;
@property (nonatomic, readonly) NSNumber *stockTradingStatus;

/// 预警线价格
- (NSArray<NSNumber *> *)stockAlertPrices;

@end

/**
 个股详情页代理
 */
@protocol TBStockDetailViewControllerDelegate <NSObject, TBStockDetailInfoDataSource>
@optional
/**
 股票下一个市场状态：
 */
@property (nonatomic, readonly) NSString *stockNameEN; // 标的名称
@property (nonatomic, readonly) NSString *stockStatusTag;
@property (nonatomic, readonly) NSTimeInterval stockStatusRecordTime;
@property (nonatomic, readonly) NSString *stockMarketStatus; // 标的市场状态

@property (nonatomic, readonly) NSNumber *stockDayHigh;
@property (nonatomic, readonly) NSNumber *stockDayLow;



@property (nonatomic, readonly) NSString *latestPriceChangeString;



@property (nonatomic, readonly) BOOL stockIsADR; // 标的是否为ADR
@property (nonatomic, readonly) NSString *stockADRRate; // adr 比例

@property (nonatomic, readonly) BOOL hasBottomTab; // 是否有新闻、新帖。。。tab

@property (nonatomic, readonly) BOOL stockIsIPOStep; // 是否处于iPO阶段
@property (nonatomic, readonly) BOOL stockIPOIsPurchaseStep; // 是否处于申购阶段
@property (nonatomic, readonly) NSArray *ipoCellItems; // ipo阶段cellItems

// 股票公告
@property (nonatomic, readonly) TBStockDetailInfoNoticeModel *stockNotice;

@property (nonatomic, readonly) TBStockInfoDetailItemModel *usHKStockModel;
@property (nonatomic, readonly) TBAStockSymbolMetaItemModel *astockMetaModel;

- (BOOL) isShowShortAble;

@property (nonatomic, readonly) NSArray<TBListTableViewController *> *bottomTagArray;
@property (nonatomic, readonly) NSArray<TBListTableViewController *> *bottomCommunityArray;
@property (nonatomic, readonly) BOOL hasStarInvestorTab; // 社区弹层 是否有交易分享tab

@end
