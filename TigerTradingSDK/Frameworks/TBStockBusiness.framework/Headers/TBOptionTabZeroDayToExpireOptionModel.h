//
//  TBOptionTabZeroDayToExpireOptionModel.h
//  TBStockBusiness
//
//  Created by chenxin on 2023/8/7.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionTabZeroDayToExpireOptionModel : JSONModel

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *expiry; // 期权到期日

/*
 正股行情数据
 "symbol":"SPY",
 "latestPrice": 4409.53,//最新价
 "preClose": 4398.95,//昨收
 "change": 10.58,//涨跌额
 */
@property (nonatomic, copy) NSDictionary *underlyingQuote;

/*
 call期权数据
 "strike":"434",
 "changeRate":-0.45,//涨跌幅
 "volume":10000
 */
@property (nonatomic, copy) NSDictionary *call;

/*
 put期权数据
 "strike":"411",
 "changeRate":0.136,//涨跌幅
 "volume":10000
 */
@property (nonatomic, copy) NSDictionary *put;

@end

NS_ASSUME_NONNULL_END
