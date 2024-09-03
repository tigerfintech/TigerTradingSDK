//
//  TBABTestingManager.h
//  StockGlobal
//
//  Created by chenxin on 2019/12/13.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBToolsKit/TBStreamUserSplitModel.h>

//WIKI:https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=74943463
@interface TBABTestingManager : NSObject

@property (nonatomic, copy) NSArray<TBStreamUserSplitModel *> *userSplitModels;

DECLARE_SHARED_INSTANCE(TBABTestingManager)

+ (void)configure;

// 是否使用一键登录
+ (BOOL)useOneClickLogin;

//默认使用新股申购H5
+ (BOOL)useIPOPurchaseH5Method;

/// 个股新帖推荐tab是否使用新版数据
+ (NSString *)useNewPostFeed;

- (void)showABTestingInfo;

// 检查是否有testflight升级提醒
- (NSDictionary *)fetchTestFlightUpgrade;

// 是否使用新版开户入金引导包含banner样式
+ (BOOL)useOpenAccountDepositBanner;

// 是否使用新加坡新版本开户引导页面
+ (BOOL)useOpenAccountSGPGuideView;

@property (nonatomic, assign) BOOL useIPOPurchaseH5;
@property (nonatomic, assign) BOOL notABTestIPOPurchase;

// 获取用户分流数据，用于A/B测试
- (void)fetchUserSplitDataWithSuccess:(void(^)(NSArray<TBStreamUserSplitModel *> *userSplitModels))success
                              failure:(void(^)(NSError *error))failure;
@end
