//
//  TBAnalysisChartOnOptionStrategyDataManager.h
//  AFNetworking
//
//  Created by zlc on 2023/8/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class TBOptionInfoDetailItem;
@class TBOptionStrategyBuilderFundamentalModel;

/*
    个股盈亏分析页-期权/组合期权曲线图dataManager
 */
@interface TBAnalysisChartOnOptionStrategyDataManager : NSObject

+ (void)calculateStrategyBuilderWithSettlementDate:(NSNumber *)settlementDate
                                           optionItem:(TBOptionInfoDetailItem *)optionItem
                                          tradeAction:(NSString *)tradeAction
                                             avgPrice:(NSNumber *)avgPrice
                                      otherOptionItem:(nullable TBOptionInfoDetailItem *)otherOptionItem
                                     otherTradeAction:(nullable NSString *)otherTradeAction
                                        otherAvgPrice:(nullable NSNumber *)otherAvgPrice
                                           stockPrice:(double)stockPrice
                                     isVerticalSpread:(BOOL)isVerticalSpread
                                              success:(void(^)(NSDictionary *))success __attribute__((deprecated("Use -calculateStrategyBuilderWithSettlementDate:stockPrice:optionItems:optOrderActions:optRatios:avgPrices:isVerticalSpread:success instead")));

+ (void)calculateStrategyBuilderWithSettlementDate:(NSNumber *)settlementDate
                                        stockPrice:(double)stockPrice
                                       optionItems:(NSArray <TBOptionInfoDetailItem *> *)optionItems
                                   optOrderActions:(NSArray <NSString *> *)optOrderActions
                                         optRatios:(NSArray <NSNumber *> *)optRations
                                         avgPrices:(NSArray <NSNumber *> *)avgPrices
                                  isVerticalSpread:(BOOL)isVerticalSpread
                                           success:(void(^)(NSDictionary *))success;

+ (NSArray <NSDictionary<NSString *,NSString *> *> *)getPNLDetailDataWithModel:(TBOptionStrategyBuilderFundamentalModel *)calculateModel netCreditOrDebit:(nullable NSNumber *)netValue margin:(nullable NSNumber *)margin avgPrices:(NSArray <NSNumber *> *)avgPrices  isValidPrice:(BOOL)isValidPrice currency:(NSString *)currency;
@end

NS_ASSUME_NONNULL_END
