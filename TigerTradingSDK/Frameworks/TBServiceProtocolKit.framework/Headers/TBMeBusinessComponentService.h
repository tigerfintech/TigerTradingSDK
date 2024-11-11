//
//  TBMeBusinessComponentService.h
//  Pods
//
//  Created by linbingjie on 2022/5/31.
//

#ifndef TBMeBusinessComponentService_h
#define TBMeBusinessComponentService_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBMeBusinessComponentService <NSObject>

- (void)tbMe_checkAppUpgrade;

- (void)tbMe_forceCheckAppUpgrade;

- (void)tbMe_fetchBannerData:(UIViewController *)viewController;

/// 给初始化工程提供vc初始化
- (UIViewController *)tbMe_initPersonalCenterViewController;

- (UIView *)tbMe_getUserFeedbackView;

- (BOOL)tbMe_getTBSparkADViewController_isShown;

- (void)tbMe_setTBSparkADViewControllerDismissBlock:(void(^)(void))block;

- (NSString *)tbMe_getNotificationKey_USER_DEFAULT_KEY_HAS_VIP_SKIN;

/// 壳工程触发判断版本升级
/// @param isForceCheck YES = 强制判断升级。  NO = 非强制判断升级
- (void)tbMe_checkAppUpgradeWithForce:(BOOL)isForceCheck;

/// 记录用户启动app次数
- (void)tbMe_remeberLaunchCount;

// 显示开屏广告
- (void)tbMe_showLaunchAd;

// 正在显示开屏广告
- (BOOL)tbMe_isShowingLaunchAd;

/// 处理开屏广告消失后操作
- (void)tbMe_handleLaunchAdDismissWithBlock:(void (^)(void))block;

/// 获取关于内部version描述
- (NSString *)tbMe_fetchVersion;

/// 跳转到新功能介绍页面
- (void)tbMe_gotoNewFeaturePage;

/*
 首页需要获取奖励中心，活动中心和邀请好友的数据
 dataDict的key分别为PromotionsRewards，CampaignCenter，InviteFriends
 对应的value为TBPersonalCenterFunctionModel类型，不需要解析，点击时回传即可
 */
- (void)tbMe_fetchRewardsAndCampaignsDataWithCompletion:(void(^)(NSDictionary *dataDict))completion;
- (void)tbMe_clickRewardsAndCampaignsItemWithModel:(id)model;

- (void)tbMe_newsPushLanguage;

/// 会员中心调用分享
/// - Parameter level: 会员等级
- (void)tbMe_shareImageWithMyMembershipLevel:(NSNumber *)level;

@end

NS_ASSUME_NONNULL_END

#endif /* TBMeBusinessComponentService_h */

