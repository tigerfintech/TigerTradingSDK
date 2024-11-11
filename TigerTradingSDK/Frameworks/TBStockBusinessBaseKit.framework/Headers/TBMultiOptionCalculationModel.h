//
//  TBMultiOptionCalculationModel.h
//  TBStockBusiness
//
//  Created by wind on 2023/4/26.
//

#import <Foundation/Foundation.h>

@class TBMultiOptionStrategyBuilderFundamentalModel;
@class TBMultiOptionChainItemModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBMultiOptionCalculationModel : NSObject

/**
 * StrategyPerformanceCalculator 初始化策略指标计算器 https://tigertech.feishu.cn/wiki/wikcnPpDZumbaiVZHIefIvsUdv0
 * @param afterExpiry 表示使用不同的结算日期，yes 为到期日后一天，no 表示当前日期
 */
+ (TBMultiOptionStrategyBuilderFundamentalModel *)StrategyBuilderCalculationWithOptionItemModel:(TBMultiOptionChainItemModel *)optionItem
                                                                                        expirys:(NSArray <NSNumber *> *)expirys
                                                                                     stockPrice:(double)stockPrice
                                                                                         market:(NSString *)market
                                                                           openAndCloseTimeList:(NSArray <NSArray <NSNumber *> *> *)openAndCloseTimeList
                                                                                  isIndexOption:(BOOL)isIndexOption
                                                                                stockVolatility:(NSNumber *)stockVolatility
                                                                                    afterExpiry:(BOOL)afterExpiry
                                                                          needSetEvaluationDate:(BOOL)needSetEvaluationDate;

+ (void)updateEvaluationDateWithExpires:(NSArray <NSNumber *> *)expires closeTime:(NSNumber *)closeTime market:(NSString *)market;
                                                                              
@end

NS_ASSUME_NONNULL_END
