//
//  TBOptionTabHttpManager.h
//  StockBusiness
//
//  Created by mashanli on 2023/7/15.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//

#import "TBOptionTabModel.h"
#import "TBOptionTabMarketTrendModel.h"
#import "TBOptionTabZeroDayToExpireOptionModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionTabHttpManager : NSObject

/// 期权市场趋势+末日期权
- (void)fetchOptionMarketDataWithSuccess:(void (^)(NSArray<TBOptionTabMarketTrendModel *> *marketTrends, NSArray *zeroDayToExpireOptions))success
                                 failure:(void (^)(NSError * _Nullable error))failure;

/// 期权频道一级页：请求期权异动和排行榜
/// @param rankId  排行榜id nullable
/// @param pageSize  排行榜一页数量 nullable
- (void)fetchBulkOrderAndRank:(NSNumber * _Nullable)rankId
              rankingPageSize:(NSNumber * _Nullable)rankingPageSize
              unusualPageSize:(NSNumber * _Nullable)unusualPageSize
                      success:(void (^)(TBOptionTabBulkOrderModel * _Nonnull unusual, TBOptionTabRankModel * _Nonnull ranking))success
                      failure:(void (^)(NSError * _Nonnull))failure;

/// 期权异动结果列表
- (void)fetchBulkOrderList:(NSString *)market
                      page:(NSNumber *)page
                  pageSize:(NSNumber *)pageSize
                conditions:(NSArray *)conditions
                   success:(void (^)(TBOptionTabBulkOrderModel * _Nonnull unusual))success
                   failure:(void (^)(NSError * _Nonnull))failure;

/// 期权异动筛选
- (void)fetchBulkOrderFilter:(void (^)(NSArray<TBOptionTabBulkOrderFilterModel *> * _Nonnull array))success
                     failure:(void (^)(NSError * _Nonnull))failure;


/// 期权排行榜
- (void)fetchOptionRankingList:(NSNumber *)rankID
                          page:(NSUInteger)page
                      pageSize:(NSUInteger)pageSize
                     sortField:(NSString *)sortField
                          sort:(NSString *)sort
                       success:(void(^)(TBOptionTabRankModel *rankModel))success
                       failure:(void (^)(NSError * _Nonnull))failure;

/// 期权学习
- (void)fetchOptionLearningDataWithSuccess:(void (^)(NSArray * _Nullable dataArray))success
                                   failure:(void (^)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
