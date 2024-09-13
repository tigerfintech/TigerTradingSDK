//
//  TBStockOptionChainHttpManager.h
//  TBOptionChain
//
//  Created by 王灵博 on 2021/5/25.
//

@import ChartKLineView;

@class TBCorporateActionsModel;
@class TBOptionAnalysisModel;
@class TBMultiOptionChainModel;
@class TBMultiOptionChainExpiryModel;
@class TBCombineOptionBaseItemModel;
@class TBOptionChainAskBidRetModel;

#import <Foundation/Foundation.h>
#import <TBStockBusinessBaseKit/TBOptionInfoDetailItem.h>
#import <TBStockBusinessBaseKit/TBOptionItem.h>
#import "TBOptionAnalysisModel.h"

typedef void (^TBKLinePeriodDataSuccess)(TBLineType lineType, NSArray * _Nullable items, id _Nullable responseObject);
typedef void (^TBKLinePeriodDataFailure)(NSError * _Nullable error);
typedef void(^FailedBlock)(NSError * _Nullable error);
typedef void(^SuccessedWithResultBlock)(id _Nullable result);


NS_ASSUME_NONNULL_BEGIN

@interface TBStockOptionChainHttpManager : NSObject

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


/// 请求指定到期日期权链
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

/// 请求全部期权连
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


/// 请求组合期权链
/// @param symbol symbol
/// @param strategy 策略名
/// @param strikeWidth 价差
/// @param stockPrice 正股价格
/// @param expiryWidth 日期差值
/// @param expiryWidthPeriodTag 日期差单位（week还是month）
/// @param strategyVersion 接口版本
/// @param success success description
/// @param failure failure description
+ (void)fetchMultiOptionChainData:(NSString *)symbol
                         strategy:(NSString *)strategy
                      strikeWidth:(NSNumber *)strikeWidth
                       stockPrice:(NSNumber *)stockPrice
                      expiryWidth:(NSNumber *)expiryWidth
             expiryWidthPeriodTag:(NSString *)expiryWidthPeriodTag
                          success:(void (^)(TBMultiOptionChainModel * _Nonnull))success
                          failure:(void (^)(NSError * _Nonnull))failure;

/// 获取指定日期的组合期权链
/// @param symbol symbol
/// @param expires 到期日列表
/// @param strategy 策略名
/// @param strikeWidth 价差
/// @param stockPrice 正股价格
/// @param success success description
/// @param failure failure description
+ (void)fetchMultiOptionChainExpiryData:(NSString *)symbol
                               strategy:(NSString *)strategy
                                expires:(NSArray<NSNumber *> *)expires
                            strikeWidth:(NSNumber *)strikeWidth
                             stockPrice:(NSNumber *)stockPrice
                                success:(void (^)(TBMultiOptionChainExpiryModel * _Nonnull))success
                                failure:(void (^)(NSError * _Nonnull))failure;

+ (void)fetchStockDetailFundamentalActions:(NSString *)symbol market:(NSString *)market success:(void (^)(TBStockDetailCorporationModel * _Nonnull))success failure:(void (^)(NSError * _Nonnull))failure;

+ (void)fetchStocksDetailInfo:(NSArray *)stockSymbols brifeMode:(BOOL)brifeMode isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay refreshOptFut:(BOOL)refreshOptFut successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;


//+ (void)fetchKlineData:(NSString *)symbol market:(NSString *)market lineType:(TBLineType)lineType params:(nonnull NSDictionary *)params success:(nonnull TBKLinePeriodDataSuccess)success failure:(nonnull TBKLinePeriodDataFailure)failure;


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
                         failure:(void (^)(NSError * _Nonnull))failure;

/// 请求公司行动
/// @param symbol <#symbol description#>
/// @param market <#market description#>
/// @param success <#success description#>
/// @param failure <#failure description#>
+ (void)fetchStockDetailCorporateAction:(NSString *)symbol market:(NSString *)market success:(void (^)(TBCorporateActionsModel * _Nonnull))success failure:(void (^)(NSError * _Nonnull))failure;

@end

NS_ASSUME_NONNULL_END
