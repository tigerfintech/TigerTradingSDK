//
//  TBOptionStrategyAnalysisDataManager+TBStrategyBuilder.h
//  TBStockBusiness
//
//  Created by zlc on 2023/6/8.
//

#import "TBOptionStrategyAnalysisDataManager.h"

NS_ASSUME_NONNULL_BEGIN

@class TBOptionStrategyBuilderStrategyModel;
@class TBOptionPickListCellItem;
@class TBOptionStrategyBuilderStrategyCellItem;
@class TBOptionStrategyBuilderStrategyOptionModel;
@class TBOptionStrategyBuilderStrategyMoodModel;
@class TBOptionStrategyBuilderPNLDetailsCellItem;
@class TBOptionAllOptionsModel;
@class TBOptionStrategyBuilderStrategyStockModel;
@class TBOptionStrategyBuilderFundamentalModel;

@interface TBOptionStrategyAnalysisDataManager (TBStrategyBuilder)

- (TBOptionStrategyBuilderStrategyOptionModel *)getDefaultOptionModel;
- (TBOptionStrategyBuilderStrategyStockModel *)getDefaultStockModel;

- (NSArray <TBOptionPickListCellItem *> *)getStrategiesWithModels:(NSArray <TBOptionStrategyBuilderStrategyModel *> *)models
                                                    selectedIndex:(NSInteger)selectedIndex;

- (NSArray <NSDictionary<NSString *,NSString *> *> *)getPNLDetailDataWithModel:(TBOptionStrategyBuilderFundamentalModel *)calculateModel netCreditOrDebit:(NSNumber *)netValue margin:(NSNumber *)margin isValidPrice:(BOOL)isValidPrice;

// MARK: 网络请求

/// 获取默认期权的brief信息，如果有信息直接返回
- (void)tb_fetchOptionBriefDataWithBlock:(void(^)(void))block;

/// 获取所有期权brief信息
- (void)tb_fetchAllOptionsWithSymbol:(NSString *)symbol block:(void(^)(TBOptionAllOptionsModel *allOptionsModel, NSString *error))block;

/// 获取策略列表
- (void)tb_fetchStrategyBuilderStrategiesWithBlock:(void(^)(NSArray <TBOptionStrategyBuilderStrategyModel *> *strategies, NSString * error))block;

/// 通过已有期权+策略，获取target期权
- (void)tb_getOptionByStrategy:(NSString *)strategy
                  strategyName:(NSString *)strategyName
                        symbol:(NSString *)symbol
                        expiry:(NSNumber *)expiry
                        strike:(NSString *)strike
                         right:(NSString *)right
                       success:(void(^)(TBOptionStrategyBuilderStrategyMoodModel *model, NSString *error))success;

/// 通过改变期权属性（方向、到期日等），获取策略情绪（例如单腿期权、看涨/看跌、tags等）信息
- (void)tb_getStrategyByOptionWithParams:(NSDictionary *)params
                                 success:(void(^)(TBOptionStrategyBuilderStrategyMoodModel *model, NSString *error))success;

/// 获得两个期权的简介信息
- (void)tb_fetchAllOptonBriefInfoWithCellItem:(TBOptionStrategyBuilderStrategyCellItem *)cellItem
                                       market:(NSString *)market
                                      success:(void (^)(NSArray < TBOptionInfoDetailItem * > * optinItems))success
                                      failure:(void (^)(NSError * __nullable))failure;

/// 获取保证金信息
- (void)tb_getRiskNavigatorMarginWithParams:(NSDictionary *)params success:(void(^)(NSNumber * __nullable initMargin))success;

// MARK: SDK 计算
/// 通过期权+股票（期权）组合计算
- (void)tb_calculateStrategyBuilderWithStrategyCellItem:(TBOptionStrategyBuilderStrategyCellItem *)cellItem
                                         settlementDate:(NSNumber *)settlementDate
                                                success:(void(^)(NSDictionary *))success;
            
/// 通过组合期权获取策略信息
+ (void)getStrategyByOptionWithParams:(NSDictionary *)params success:(void(^)(TBOptionStrategyBuilderStrategyMoodModel *model, NSString *error))success;
@end

NS_ASSUME_NONNULL_END
