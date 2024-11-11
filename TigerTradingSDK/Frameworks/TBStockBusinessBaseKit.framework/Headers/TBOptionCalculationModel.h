//
//  TBOptionCalculationModel.h
//  Optionlib
//
//  Created by 王灵博 on 2021/3/15.
//

#import <Foundation/Foundation.h>
@class TBOptionFundamentalModel;
@class TBOptionInfoDetailItem;
@class TBOptionFundamentalModel,TBOptionInfoDetailItem;
@class TBOptionStrategyBuilderFundamentalModel;
@class TBOptionStrategyBuilderConfigModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionCalculationModel : NSObject

+ (NSDictionary <NSString *, NSArray <NSNumber *> *> *)calcUnderlyingListPointsWithBreakEvens:(nullable NSArray <NSNumber *> *)breakEvensListPoints
                                                                               underlyingList:(nullable NSArray <NSNumber *> *)underlyingListPoints
                                                                          underlyingListCount:(NSInteger)underlyingListCount
                                                                                   stockPrice:(double)stockPrice
                                                                                         step:(double)step;

+ (NSDictionary <NSString *, NSArray <NSNumber *> *> *)calcUnderlyingListPointsWithBreakEvens:(nullable NSArray <NSNumber *> *)breakEvensListPoints
                                                                               underlyingList:(nullable NSArray <NSNumber *> *)underlyingListPoints
                                                                          underlyingListCount:(NSInteger)underlyingListCount
                                                                                   stockPrice:(double)stockPrice
                                                                                         step:(double)step
                                                                                  isFirstPage:(BOOL)isFirstPage;

/**
 * 计算期权组合工具数据
 */
+ (TBOptionStrategyBuilderFundamentalModel *)StrategyBuilderCalculationWithConfigModel:(TBOptionStrategyBuilderConfigModel *)configModel;

/// 计算持仓-盈亏分析页组合期权数据
+ (TBOptionStrategyBuilderFundamentalModel *)AnalysisStrategyBuilderCalculationWithConfigModel:(TBOptionStrategyBuilderConfigModel *)configModel;

+ (TBOptionFundamentalModel *)OptionCalculationWithOptionItemModel:(TBOptionInfoDetailItem *)optionItem right:(NSString *)right realExpiryTime:(NSNumber *)realExpiryTime market:(NSString *)market stockPrice:(NSNumber *)stockPrice optionPrice:(double)optionPrice;

+ (TBOptionFundamentalModel *)OptionCalculationWithOptionItemModel:(TBOptionInfoDetailItem *)optionItem right:(NSString *)right realExpiryTime:(NSNumber *)realExpiryTime market:(NSString *)market stockPrice:(NSNumber *)stockPrice optionPrice:(double)optionPrice isSupportMultiThread:(BOOL)isSupportMultiThread;


//获取有效的SettlementDate
+(NSTimeInterval)effectiveSettlementDateWithExpiry:(long long)expiry
                                         closeTime:(NSNumber *)closeTime
                                        serverTime:(NSTimeInterval)serverTime;




//获取期权价格
+ (double)OptionPriceWithItem:(TBOptionInfoDetailItem *)optionItem
                              right:(NSString *)right
                     realExpiryTime:(NSNumber *)realExpiryTime
                     settlementTime:(long long)settlementTime
                             market:(NSString *)market
                         stockPrice:(NSNumber *)stockPrice
                               vol:(double)vol
                       strike:(NSString *)strike;

@end

NS_ASSUME_NONNULL_END
