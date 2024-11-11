//
//  TBBaseViewController+TigerTrade.h
//  Stock
//
//  Created by chenxin on 2020/9/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>
#import <TBToolsKit/TBSensorsAnalyticsData.h>

NS_ASSUME_NONNULL_BEGIN

/*
 将原来直接写在TBBaseViewController的业务代码改为分类管理
 */
@interface TBBaseViewController (TigerTrade)

@property (nonatomic, assign) BOOL      isViewShown;    // 当前界面是否正在显示

//// 获取用户信息（社区相关），历史遗留代码
//- (void)netGetUserInfo;

/// communityAction埋点相关参数
@property (nonatomic, copy, readonly) NSString *communityActionCurrentPage; ///< communityAction埋点参数 currentPage


//上报曝光事件
- (void)reportShow;
//上报Show事件时需要重载
- (void)reportWillDisplayCell:(id)object;

// 计算pageId和referPage, 用于非标准容器vc切换页面时主动调用来记录进出某页面
- (void)enterPage;

/**
 * 神策埋点

 @param properties 用于重写
 */
- (void)sa_trackFollowEventWithType:(NSString *)type followedID:(NSString *)followedID otherProperties:(nullable NSDictionary *)properties;

- (void)sa_trackFollowUserEventWithFollowedID:(NSString *)followedID;

+ (void)preload;

#pragma mark - NSNotification Handler

// 开放几个通知方法为 public, 用于子类重写

- (void)handleDidReceiveRemoteNotification:(NSNotification *)notification;

- (void)applicationWillEnterForeground:(NSNotification *)notification;

- (void)applicationDidEnterbackground:(NSNotification *)notification;


/// 设置该页面需要上报页面停留时长（一定要在viewDidAppear方法执行前调用，可在viewdidload中调用）
/// - Parameter block: 在block内设置需要上报的参数
- (void)tb_configLeavePageWithDurationWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;

@end

NS_ASSUME_NONNULL_END
