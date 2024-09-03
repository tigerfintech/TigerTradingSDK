//
//  TBDeepLinkManager.h
//  Stock
//
//  Created by chenxin on 2020/4/2.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDeepLinkManager : NSObject

DECLARE_SHARED_INSTANCE(TBDeepLinkManager)

@property (nonatomic, assign) BOOL enableBranch; // 是否启用归因SDK

+ (BOOL)canHandleDeepLink:(NSURL *)url;

// 启动时初始化DeepLink
- (void)setupDeepLinkWithLaunchOptions:(nullable NSDictionary *)launchOptions;

/*
 如果首次启动时因为location不符合要求未初始化DeepLink，等location通过device/init更新后再尝试一次初始化
 */
- (void)delaySetupDeepLink;

+ (void)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary</*UIApplicationOpenURLOptionsKey*/NSString*,id> *)options;

+ (BOOL)continueUserActivity:(NSUserActivity *)userActivity;

- (void)appDidBecomeActive;

// 卸载衡量需要记录推送token
- (void)registerPushDeviceToken:(NSData *)deviceToken;

// 是否有deeplink逻辑要处理
- (BOOL)hasDeepLinkToProcess;

@end

NS_ASSUME_NONNULL_END
