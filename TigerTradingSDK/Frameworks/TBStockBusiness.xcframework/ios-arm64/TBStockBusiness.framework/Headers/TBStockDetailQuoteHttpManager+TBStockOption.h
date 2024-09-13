//
//  TBStockDetailQuoteHttpManager+TBStockOption.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/2/26.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBStockDetailQuoteHttpManager.h"
#import <TBStockBusinessBaseKit/TBOptionInfoDetailItem.h>
#import <TBStockBusinessBaseKit/TBOptionItem.h>
#import <TBStockBusinessBaseKit/TBCombineOptionInfoDetailItem.h>

NS_ASSUME_NONNULL_BEGIN
@class TBOptionAnalysisModel;
@class TBStockDetailOptionScenarioAnalysisModel;

@interface TBStockDetailQuoteHttpManager (TBStockOption)


/// 获取期权分析数据接口
/// @param symbol 标的
/// @param market 港股/美股期权
/// @param optionSymbol 期权symbol
/// @param expiry 到期时间
/// @param onlySkewness 只请求偏值
/// @param success success description
/// @param failure failure description
+ (void)fetchOptionAnalysis:(NSString *)symbol
                     market:(NSString *)market
               optionSymbol:(NSString *)optionSymbol
                     expiry:(NSNumber *)expiry
               onlySkewness:(BOOL)onlySkewness
                    success:(void (^)(TBOptionAnalysisModel *))success
                    failure:(void (^)(NSError * nullable))failure;

/// 获取期权分析数据接口-获取call-put ratio
/// @param symbol symbol description
/// @param market market description
/// @param callDividePut all/put为true，put/call为false，默认为true
/// @param success success description
/// @param failure failure description
+ (void)fetchOptionAnalysisCallPutRatio:(NSString *)symbol
                                 market:(NSString *)market
                          callDividePut:(BOOL)callDividePut
                                success:(void (^)(TBOptionAnalysisModel *))success
                                failure:(void (^)(NSError * nullable))failure;

/// 请求指定到期日期权连
/// @param symbol symbol description
/// @param expiry expiry description
/// @param success success description
/// @param failure failure description
+ (void)fetchOptionExpiryData:(NSString *)symbol
                       expiry:(long long)expiry
                       market:(NSString *)market
                      success:(void (^)(TBOptionChainExpireModel *chainModel))success
                      failure:(void (^)(void))failure;

/// 请求指定日期的期权链
/// @param symbol symbol description
/// @param expiry expiry description
/// @param market market description
/// @param parameters 增加limit和price
/// @param success success description
/// @param failure failure description
+ (void)fetchOptionExpiryData:(NSString *)symbol
                       expiry:(long long)expiry
                       market:(NSString *)market
                   parameters:(NSDictionary *)parameters
                      success:(void (^)(TBOptionChainExpireModel *chainModel))success
                      failure:(void (^)(void))failure;


/// 请求全部期权连
/// @param symbol symbol description
/// @param success success description
/// @param failure failure description
+ (void)fetchOptionChainData:(NSString *)symbol
                      market:(NSString *)market
                     success:(void (^)(TBOptionChainModel *model))success
                     failure:(void (^)(NSString *message))failure;

/// 获取全部期权链
/// @param symbol symbol description
/// @param market market description
/// @param parameters 增加limit和price
/// @param success success description
/// @param failure failure description
+ (void)fetchOptionChainData:(NSString *)symbol
                      market:(NSString *)market
                  parameters:(NSDictionary *)parameters
                     success:(void (^)(TBOptionChainModel *model))success
                     failure:(void (^)(NSString *message))failure;


/// 期权基本信息、分时图、逐笔请求
/// @param symbol symbol description
/// @param right right description
/// @param expiry expiry description
/// @param strike strike description
/// @param success success description
/// @param failure failure description
+ (void)fetchStockOptionDetail:(NSString *)symbol
                         right:(NSString *)right
                        expiry:(long long)expiry
                        strike:(NSString *)strike
                        market:(NSString *)market
                       success:(void (^)(TBOptionInfoDetailItem * _Nonnull, NSArray *, NSArray *))success
                       failure:(void (^)(NSError * nullable))failure;


/*
 批量获取期权详情
 @param items
 输入示例
 {
  "items": [
      {
         "symbol" : "AAPL", // string
         "right": "CALL", // string
         "expiry": 1444363200000, // long
         "strike":"110.0"; //string
      }
  ],
  "h":"ef123erf",
  "addInterestTarget":true
 }
 @param market <#market description#>
 @param addInterestTarget 是否订阅长连接消息，默认为false，持仓需要订阅买卖盘设置为true
 */
+ (void)fetchStockOptionDetails:(NSArray *)items market:(NSString *)market addInterestTarget:(BOOL)addInterestTarget hashCode:(NSString *)hashCode success:(void (^)(TBOptionDetailsModel * _Nonnull))success failure:(void (^)(NSError * nullable))failure;


/// 请求期权K线图
/// @param symbol symbol description
/// @param right right description
/// @param expiry expiry description
/// @param strike strike description
/// @param success success description
/// @param failure failure description
+ (void)fetchStockOptionKLine:(NSString *)symbol
                        right:(NSString *)right
                       expiry:(long long)expiry
                       strike:(NSString *)strike
                       market:(NSString *)market
                      success:(void (^)(NSArray *items, id responseObject))success
                      failure:(void (^)(NSError * nullable))failure;

/// 请求期权详情
/// @param symbol symbol description
/// @param expiry expiry description
/// @param strike strike description
/// @param right right description
/// @param success success description
/// @param failure failure description
+ (void)fetchOptionBriefOfSymbol:(NSString *)symbol
                          expiry:(long long)expiry
                          strike:(NSString *)strike
                           right:(NSString *)right
                          market:(NSString *)market
                         success:(void (^)(TBOptionInfoDetailItem *))success
                         failure:(void (^)(NSError * nullable))failure;

/// 17.获取期权深度报价
/// @param symbol symbol description
/// @param right right description
/// @param expiry expiry description
/// @param strike strike description
/// @param success success description
/// @param failure failure description
+ (void)fetchStockOptionDepth:(NSString *)symbol
                        right:(NSString *)right
                       expiry:(long long)expiry
                       strike:(NSString *)strike
                       market:(NSString *)market
                      success:(void (^)(TBOptionDepthModel * _Nonnull, id responseObject))success
                      failure:(void (^)(NSError * nullable))failure;

/** 33.获取组合期权深度
 *  @param stockSymbol 正股symbol （如果无正股时，可不传）
 *  @param stockSize 正股size（如果无正股时，可不传）
 *  @param stockDirection 正股方向（如果无正股时，可不传）
 *  @param contracts 期权合约（里面是四要素）
 */
+ (void)fetchMLegOptionDepth:(nullable NSString *)stockSymbol
                   stockSize:(nullable NSNumber *)stockSize
              stockDirection:(nullable NSString *)stockDirection
                   contracts:(NSArray <NSDictionary *> *)contracts
                     success:(void (^)(id responseObject))success
                     failure:(void (^)(NSError * nullable))failure;


+ (void)fetchStockOptionTicks:(NSString *)symbol
                        right:(NSString *)right
                       expiry:(long long)expiry
                       strike:(NSString *)strike
                       market:(NSString *)market
                       params:(NSDictionary *)params
                      success:(void (^)(id responseObject))success failure:(void (^)(NSError * _Nonnull))failure;

+ (void)fetchStockDetailDeviceSwitch:(void(^)(BOOL success))sucess;

/// 32.获取期权组合盘口
/// https://tigertech.feishu.cn/wiki/wikcnQmRjx6tcv4zyGlB6adNisq#b9tOJk


/// 38.获取组合期权详情
/// https://tigertech.feishu.cn/wiki/wikcnQmRjx6tcv4zyGlB6adNisq#QsXDxW
/// @param contracts 期权合约（里面是四要素）
/// @param withMinutes 是否返回分时
+ (void)fetchCombineOptionDetail:(NSDictionary *)contracts success:(void (^)(NSArray<TBCombineOptionInfoDetailItem *> *items))success failure:(void (^)(NSError *))failure;

/// 39.获取组合期权K线
/// https://tigertech.feishu.cn/wiki/wikcnQmRjx6tcv4zyGlB6adNisq#ZIiW4m
+ (void)fetchOptionComplexKLineWithItems:(NSArray *)items beginTime:(nullable NSNumber *)beginTime endTime:(nullable NSNumber *)endTime limit:(nullable NSNumber *)limit period:(NSString *)period success:(nullable void (^)(NSDictionary * _Nullable model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 40.获取组合期权分时
/// https://tigertech.feishu.cn/wiki/wikcnQmRjx6tcv4zyGlB6adNisq#A0CKzl
+ (void)fetchOptionComplexMinuteWithItems:(NSArray *)items beginTime:(nullable NSNumber *)beginTime success:(nullable void (^)(NSDictionary * _Nullable model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 42.批量获取组合期权K线
/// https://tigertech.feishu.cn/wiki/wikcnQmRjx6tcv4zyGlB6adNisq#SU8qtD
+ (void)requestOptionComplexKLineWithItems:(NSArray *)items beginTime:(nullable NSNumber *)beginTime endTime:(nullable NSNumber *)endTime limit:(nullable NSNumber *)limit period:(NSString *)period success:(nullable void (^)(NSDictionary * _Nullable model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 43.批量获取组合期权分时
/// https://tigertech.feishu.cn/wiki/wikcnQmRjx6tcv4zyGlB6adNisq#0ZCkWy
+ (void)requestOptionComplexMinuteWithItems:(NSArray *)items beginTime:(nullable NSNumber *)beginTime success:(nullable void (^)(NSDictionary * _Nullable model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/**
 * 卖方项目详情页
 
symbol (股票代码，大写，如AAPL)
expiry           (到期时间，long, 毫秒数，来源于期权链，必须为美东时间零点)
strike (行权价，string，来源于期权链)
right            (看多或看空，string, =”CALL” or “PUT”)
 
 */
+ (void)fetchStockOptionScenarioAnalysis:(NSString *)symbol
                                   right:(NSString *)right
                                  expiry:(long long)expiry
                                  strike:(NSString *)strike
                               success:(void (^)(TBStockDetailOptionScenarioAnalysisModel *model))success
                               failure:(void (^)(NSError * nullable))failure;



@end

NS_ASSUME_NONNULL_END
