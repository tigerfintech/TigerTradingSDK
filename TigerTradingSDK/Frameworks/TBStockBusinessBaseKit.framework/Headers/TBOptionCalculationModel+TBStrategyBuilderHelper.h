//
//  TBOptionCalculationModel+TBStrategyBuilderHelper.h
//  TBStockBusiness
//
//  Created by zlc on 2022/10/28.
//

#import "TBOptionCalculationModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionCalculationModel (TBStrategyBuilderHelper)
/// 根据边界获取采样点underlyingList，边界：-10%
+ (NSArray<NSNumber *> *)getStrategyBuilderUnderlyingListWithStartPrice:(double)startPrice
                                                             isLeftPage:(BOOL)isLeftPage
                                                                   step:(double)step
                                                    underlyingListCount:(NSInteger)underlyingListCount;

/// 根据盈亏平衡点获取采样点underlyingList，边界：strike +- 5%
+ (NSArray<NSNumber *> *)getStrategyBuilderUnderlyingListWithBreakEvens:(NSArray <NSNumber *> *)breakEvens
                                                    underlyingListCount:(NSInteger)underlyingListCount;

+ (NSArray<NSNumber *> *)getStrategyBuilderUnderlyingListWithBreakEvens:(NSArray <NSNumber *> *)breakEvens
                                                    underlyingListCount:(NSInteger)underlyingListCount
                                                            isFirstPage:(BOOL)isFirstPage;
/// 获取步长
+ (double)getStrategyBuilderStepWithBreakEvens:(NSArray <NSNumber *> *)breakEvens underlyingListCount:(NSInteger)underlyingListCount;

+ (double)getStrategyBuilderStepWithBreakEvens:(NSArray <NSNumber *> *)breakEvens underlyingListCount:(NSInteger)underlyingListCount isFirstPage:(BOOL)isFirstPage;


/**
 * 根据入参数生成最终采样点集合
 * @param fromAnalysisPage 是否是个股盈亏分析页面
 */
+ (NSArray<NSNumber *> *)generateCombinedUnderlyingListWithBreakEvens:(NSArray<NSNumber *> *)breakEvens
                                                          optionItems:(NSArray<TBOptionInfoDetailItem *> *)optionItemsArray
                                                  underlyingListCount:(NSInteger)underlyingListCount
                                                           stockPrice:(double)stockPrice
                                                         onePageCount:(NSInteger)onePageCount
                                                     fromAnalysisPage:(BOOL)fromAnalysisPage;

@end

NS_ASSUME_NONNULL_END
