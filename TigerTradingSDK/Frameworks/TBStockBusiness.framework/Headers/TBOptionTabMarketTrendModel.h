//
//  TBOptionTabMarketTrendModel.h
//  TBStockBusiness
//
//  Created by chenxin on 2023/8/4.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionTabMarketTrendModel : JSONModel

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *optionTotalVolume; // 期权总成交量
@property (nonatomic, strong) NSNumber *callRatio; // CALL期权成交量占比
@property (nonatomic, strong) NSNumber *putRatio; // PUT期权成交量占比

/*
 日成交量最高的期权
 "symbol": ".SPX",
 "right": "call",
 "expiry": 1694750400000,
 "strike": "12.5",
 "volume":10000
 */
@property (nonatomic, copy) NSDictionary *topOption;

/*
 正股行情数据
 "symbol":".SPX",
 "name":"标普500",
 "marketStatus": "未开盘",
 "latestTime": "07-10 16:00:00 EDT",
 "latestPrice": 4409.53,//最新价
 "preClose": 4398.95,//昨收
 "change": 10.58,//涨跌额
 "prices": [//SPX股价缩略图
     4400.12,
     4405.17,
     4402.99,
     4405.65,
     4409.53
 ]
 */
@property (nonatomic, copy) NSDictionary *underlyingQuote;

@end

NS_ASSUME_NONNULL_END
