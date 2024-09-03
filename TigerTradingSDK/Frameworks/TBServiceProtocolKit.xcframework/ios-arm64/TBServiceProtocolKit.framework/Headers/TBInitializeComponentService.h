//
//  TBInitializeComponentService.h
//  Pods
//
//  Created by linbingjie on 2022/6/7.
//

#ifndef TBInitializeComponentService_h
#define TBInitializeComponentService_h

NS_ASSUME_NONNULL_BEGIN

@protocol TBInitializeComponentService <NSObject>

- (void)tbInitialize_loadTabBar;

- (void)tbInitialize_reloadTab:(NSString *)name;
- (void)tbInitialize_reloadWealthTab:(BOOL)displayWealthTab;

- (void)tbInitialize_reloadTradeTab;

- (void)tbInitialize_hideNewbieGiftGuide:(id)tabBarController;

/// 获取当前配置的`TabItem`列表. 从工厂方法创建, 并非从tabvc获取
- (NSArray *)tbInitialize_getTabItems;

///  以下几个方法是三方handle处理逻辑
/// 注册三方SDK
/// @param application 应用
/// @param launchOptions 启动选项
- (void)tbInitialize_registerThirdPartyAccountWithApplication:(UIApplication *)application launchOptions:(NSDictionary *)launchOptions;
/// 微信是否可以打开universal link
/// @param activity NSUserActivity
- (BOOL)tbInitialize_canWechatUniversalLinkWithActivity:(NSUserActivity *)activity;
/// 微信是否可以打开url
/// @param url NSURL
- (BOOL)tbInitialize_canWecahtOpenUrl:(NSURL *)url;
/// 微博是否可以打开url
/// @param url NSURL
- (BOOL)tbInitialize_canWeiboOpenUrl:(NSURL *)url;
- (void)tbInitialize_openWechatAndSubscribe;





/// 设置jpush角标
/// - Parameter badge: 角标
- (void)tbInitialize_jpushSetBadge:(NSInteger)badge;

/// 注册相关方法调用
- (void)tbInitialize_jpushRegistration:(NSDictionary *)launchOptions
                           productMode:(BOOL)productMode
                            completion:(void(^)(int resCode,NSString *registrationID))completionHandler;


/// 跳到热更新debugvc
- (void)tbInitialize_jumpToPatchDebugVC;

// 底部微信引导入金delegate
- (void)tbInitialize_openAccountWeixinGuide;

// 初始化TBTabbarViewController
- (void)tbInitialize_startLoadTabbarViewController;

// 是否禁用了patch
- (BOOL)tbIsDisablePatch;

// 是否禁用卡顿监控
- (BOOL)tbIsDisableLagMonitor;

// 是否禁用冷启动埋点
- (BOOL)tbIsDisableColdLaunch;

// 是否禁用整个crash组件
- (BOOL)tbIsDisableCrashlyticsAll;

// 是否禁用crashlytics_record
- (BOOL)tbIsDisableCrashlyticsRecord;

// 是否禁用crashlytics_log
- (BOOL)tbIsDisableCrashlyticsLog;

// 是否禁用crashlytics_config
- (BOOL)tbIsDisableCrashlyticsConfig;

// 是否禁用crashlytics_trace
- (BOOL)tbIsDisableCrashlyticsTrace;

/// ipad + 横屏
/// 更新splitViewController 右边VC重置成默认状态
/// 切换tab之类的场景需要重置detail vc 成默认状态
- (void)tbInitialize_ipad_splitVCResetDetailVC;
@end

NS_ASSUME_NONNULL_END

#endif /* TBInitializeComponentService_h */
