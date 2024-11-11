//
//  TBMessageCenterComponentService.h
//  TBServiceProtocolKit
//
//  Created by linbingjie on 2022/5/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBMessageCenterComponentService <NSObject>

/// 注册token
- (void)tbMC_registerPushToken;

- (void)tbMC_showPushIfNeededInViewController:(UIViewController *)viewController;

- (void)tbMC_hidePushIfNeeded:(UIViewController *)viewController;

- (void)tbMC_takeActionAfterMessageReceived:(NSDictionary *)payload innerAPNS:(BOOL)innerAPNS;

- (void)tbMC_takeActionAfterMessageReceived:(NSDictionary *)messageInfo;

// 请求推送权限
- (void)tbMC_requestPushAuthorization;

// 从服务器获取推送设置, 写到本地
- (void)tbMC_getRegisterPushSetting;

- (void)tbMC_getRegisterPushSetting:(void(^)(BOOL finished))completed;

// 在有必要时更新推送设置
- (void)tbMC_updatePushSettingIfNeeded;

/// push logout && clean cachepushmessage
- (void)tbMC_pushMessageLogoutCleanCachePushMessage;

/// trackSFApp && handle received message
- (void)tbMC_pushTrackSFAndHandleReceivedMessage:(NSDictionary *)userInfo;

// MARK: TBInAppPushManager
- (void)tbMC_inAppPushManagerSubcribeInAppPushTopics:(BOOL)enable;

- (void)tbMC_inAppPushManagerSubcribeCommunityTransactionSharing:(BOOL)enable;

- (void)tbMC_fetchUnreadMessageCount:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

- (void)tbMC_updatePushSetting:(NSDictionary *)dict;
- (void)tbMC_updatePushSetting:(NSDictionary *)dict success:(void(^)(void))success failure:(void(^)(NSString * message))failure;

- (void)tbMC_checkNeedResetNotificationPrompt;

@optional

- (NSString *)tbMC_getMessageCenterNotificationKeyUpdate;

- (NSString *)tbMC_getDenpendenceConfigSettingKey;

- (void)tbMC_syncBadgeNumberToServer:(NSInteger)badgeNumber
                         completed:(nullable void(^)(BOOL isFinished))completed;

- (void)tbMC_gotoMessageCenterHomePage:(nullable NSDictionary *)query;

/// 判断是否应该显示提示
- (BOOL)tbMC_checkCanShowNotificationPrompt;

/// 关闭当前版本通知提示
- (void)tbMC_closeNotificationPrompt;

- (NSArray *)tbMC_getCachePushMessageArray;

- (NSArray *)tbMC_groupItemsFromResultArray:(NSArray *)array;

- (void)tbMC_cachePushMessageArrayRemoveAll;

- (void)tbMC_updatePushLanguage;

- (void)tbMC_onlineNotify:(BOOL)force;

@end

NS_ASSUME_NONNULL_END
