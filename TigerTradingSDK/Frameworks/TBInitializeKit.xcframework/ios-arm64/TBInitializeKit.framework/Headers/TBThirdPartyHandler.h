//
//  TBThirdPartyHandler.h
//  TBAuthBusiness
//
//  Created by yangln on 2022/2/24.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBThirdPartyHandler : NSObject

/// 单例声明
DECLARE_SHARED_INSTANCE(TBThirdPartyHandler)

// 初始化配置三方账户信息
- (void)configureThirdPartyAccountInfo;

/// 注册三方SDK
/// @param application 应用
/// @param launchOptions 启动选项
- (void)registerThirdPartyAccountWithApplication:(UIApplication *)application launchOptions:(NSDictionary *)launchOptions;

/// 微信是否可以打开universal link
/// @param activity NSUserActivity
- (BOOL)canWechatUniversalLinkWithActivity:(NSUserActivity *)activity;

/// 微信是否可以打开url
/// @param url NSURL
- (BOOL)canWecahtOpenUrl:(NSURL *)url;

/// 微博是否可以打开url
/// @param url NSURL
- (BOOL)canWeiboOpenUrl:(NSURL *)url;


- (void)openWechatAndSubscribe;

@end

NS_ASSUME_NONNULL_END
