//
//  TBStockStarInvestorHttpManager.h
//  TBStockBusiness
//
//  Created by F.S. on 2023/8/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockStarInvestorHttpManager : NSObject

// 投资者order
+ (void)fetchStarInvestorOrder:(NSNumber *)startFromTime
                   startFromId:(NSString *)startFromId
                       success:(void(^)(id responseObject))success
                       failure:(void(^)(NSError *error))failure;

+ (void)fetchStarInvestorOrder:(NSNumber *)startFromTime
                   startFromId:(NSString *)startFromId
                      criteria:(NSArray *)criteria
                       success:(void(^)(id responseObject))success
                       failure:(void(^)(NSError *error))failure;

/// 投资者rank
+ (void)fetchStarInvestorRank:(NSString *)typeStr
                    pageCount:(NSNumber *)pageCount
                      success:(void(^)(id responseObject))success
                      failure:(void(^)(NSError *error))failure;

+ (void)fetchStarInvestorRank:(NSString *)typeStr
                    pageCount:(NSNumber *)pageCount
             starInvestorType:(NSArray *)starInvestorType 
                      success:(void(^)(id responseObject))success
                      failure:(void(^)(NSError *error))failure;

/// 关注的投资者
+ (void)fetchStarInvestorHeadRank:(NSString *)userId
                        pageCount:(NSNumber *)pageCount
                    startFromTime:(NSNumber *)startFromTime
                          success:(void(^)(id responseObject))success
                          failure:(void(^)(NSError *error))failure;

/// 访谈
+ (void)fetchStarInvestorNews:(NSNumber *)pageCount
                      success:(void(^)(id responseObject))success
                      failure:(void(^)(NSError *error))failure;

+ (void)fetchStarInvestorRankRecommendList:(NSString *)uuid
                                   success:(void(^)(id responseObject))success
                                   failure:(void(^)(NSError *error))failure;

/// 个股交易分享 红点相关
/// 上报已读
+ (void)uploadStarInvestorStockDetailRead:(NSString *)symbol
                                  success:(void(^)(id responseObject))success
                                  failure:(void(^)(NSError *error))failure;

/// 查询某个股下交易分享列表 是否有未读新数据
+ (void)fetchStarInvestorStockDetailUnread:(NSString *)symbol
                                   success:(void(^)(id responseObject))success
                                   failure:(void(^)(NSError *error))failure;

/// 查询某个股下交易分享列表 是否有未读新数据
+ (void)fetchStarInvestorStockDetailTip:(NSString *)symbol
                                success:(void(^)(id responseObject))success
                                failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
