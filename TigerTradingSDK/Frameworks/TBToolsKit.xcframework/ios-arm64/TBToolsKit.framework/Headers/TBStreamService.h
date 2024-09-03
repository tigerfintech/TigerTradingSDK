//
//  TBStreamService.h
//  TBToolsKit
//
//  Created by linbingjie on 2021/5/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStreamService : NSObject
/// 查询个性化物料/用户分流
/// /stream/public/popup
+ (void)fetchPublicPopupWithParameters:(NSDictionary *)parameters
                               success:(void(^)(id responseObject))success
                               failure:(void(^)(NSError *error))failure;

/// 不再展示个性化物料
/// /stream/public/popup/forbidden
+ (void)forbiddenPublicPopupWithMaterialIDs:(NSArray *)materialIDs;

/// 不再展示个性化物料 (只针对每N天展示的物料配置)
/// /stream/public/popup/nth_forbidden
+ (void)forbiddenPublicPopupOnlyForNthDaysWithMaterialIDs:(NSArray *)materialIDs;

/// 分享渠道顺序接口
/// /api/polaris/v1/guidance/share_channel_order
/// https://tigertech.feishu.cn/wiki/wikcnoqYa8KFHGRPm0YLr3pMDke
+ (void)getShareChannelOrderForApp:(NSString *)appName success:(nullable void (^)(id responseObject))success failure:(nullable void (^)(NSError *error))failure;

/// 记录分享正向收益的用户
+ (void)recordPositiveReturnShare;

@end

NS_ASSUME_NONNULL_END
