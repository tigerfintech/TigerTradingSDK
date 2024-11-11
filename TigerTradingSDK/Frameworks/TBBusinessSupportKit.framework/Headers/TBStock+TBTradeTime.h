//
//  Stock+TBTradeTime.h
//  TBBaseUtils
//
//  Created by zhengzhiwen on 2021/4/12.
//

#import <TBStockKit/TBStock.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStock (TBTradeTime)


// 是否是指数.
+ (BOOL) isIndexSymbol:(NSString *)symbol;

/// 是否是主要指数
/// @param symbol symbol description
+ (BOOL)isMainIndexSymbol:(NSString *)symbol;

// 是否为基金
+ (BOOL)isFund:(NSString*)symbol;

//股票是否是期权
+ (BOOL)isStockBelongOption:(NSString *)symbol;

/// 是否需要把关联期货提到最上面
/// @param symbol symbol description
+ (BOOL)enableFutureContractTopWithSymbol:(NSString *)symbol;

// 根据serverTime 判断是否需要刷新 A股的数据, A股刷新数据时间段:  // 9:20-11:40 || 12:50-15:10
// TODO 处理 周末?  如果有港股需要 调整到 下午16:00
+ (BOOL)needReloadAStockData:(NSNumber *)time;

// 自选因为展示的盘前盘后, 所以在美股的盘前盘后, A股的交易时间段, 以及港股的交易时间段都需要轮询自选页面.
+ (BOOL)needReloadWatchListData:(NSNumber *)time;

// 美股Market 只有盘前或者盘后
+ (BOOL)usMarketPreOpenOrAfterClose:(NSNumber *)time;

// 美股market 是否开盘.常规交易时间
+ (BOOL)usMarketOpen:(NSNumber *)time;

// 美股market 所有交易时间, 包含盘前盘后
+ (BOOL)usMarketTradeTimeALL:(NSNumber *)time;


/**
 是否在开盘时间
 
 @param market 市场
 @return 市场是否为开盘时间
 */
+ (BOOL)isMarketOpenTime:(NSString *)market;

+ (BOOL)ukMarketOpen:(NSNumber *)time;
+ (BOOL)siMarketOpen:(NSNumber *)time;


/**
 是否处于科创板盘后交易时间

 @param time time description
 @return return value description
 */
+ (BOOL)cnMarketKCBAfterMarket:(NSNumber *)time;

// 港股market 是否开盘.
+ (BOOL)hkMarketOpen:(NSNumber *)time;


// 上午交易时段(上午9:00~下午16:00)
+ (BOOL)isDayTimeTradeTime:(NSNumber *)time;

// 下午交易时段(下午16:00~第二天上午9:00)
+ (BOOL)isEveningTradeTime:(NSNumber *)time;

/**
 美股是否为盘前/盘后时间
 
 @param market 市场
 @return bool
 */
+ (BOOL)isUSPreOrSuffMarketTime:(NSString *)market;

// A股market 是否开盘.
+ (BOOL)cnMarketOpen:(NSNumber *)time;
/**
 sA股是否开盘，考虑科创板盘后清空

 @param time 时间戳
 @param isKCB 是否为科创板
 @return 是否开盘
 */
+ (BOOL)cnMarketOpen:(NSNumber *)time isKCB:(BOOL)isKCB;

/**
 美股是否为昨日盘前时间，美东时间：0:00 ～ 4:00
 
 @return bool
 */
+ (BOOL)isUSYesterdayPreMarketTime;


/**
 美股是否为昨日盘后时间，美东时间：0:00 ~ 16:00
 
 @return bool
 */
+ (BOOL)isUSYesterdayAfterMarketTime;

/**
 获取市场交易时间
 */
+ (NSDictionary *)tradingHoursForMarket:(NSString *)market;

@end

NS_ASSUME_NONNULL_END
