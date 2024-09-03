//
//  TBAuthUtils.h
//  TBAccountSystemKit
//
//  Created by yangln on 2022/2/28.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TBNavigator.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAuthUtils : NSObject

// 是否已展示首次启动隐私弹窗（国内包要求展示）
+ (BOOL)hasShowPrivacyAlert;

// 保存已展示首次启动隐私弹窗状态
+ (void)saveHasShowPrivacyAlert;

/// 是否已经开始登录流程
+ (BOOL)hasAlreadyInLoginProcess;

/// 调起登录页面（有动画，之前老的open Login VC 的方法，默认都是animated yes, 有可能打开手机号一键登录页面）
+ (void)openLoginVC;

/// 打开普通登录页面，如手机验证码登录页面
/// @param animated YES有动画，NO无动画
+ (void)openNormalLoginVCAnimated:(BOOL)animated;

/// 进入注册或者绑定
+ (void)thirdAccountBindPhone;

+ (void)thirdAccountBindPhoneWithAnimated:(BOOL)animated;

/// 当前VC已经进入登录/注册流程，不需要再次因为token失效弹出登录界面
/// @param vc 当前top controller
+ (BOOL)hasAlreadyInLoginProcessWithViewController:(UIViewController *)vc;

/// 检查用户权限，满足返回YES，不满足返回NO并进入绑定或设置昵称
+ (BOOL)checkUserAuthorization;

/// 检查用户能否开户， 可能是微信，一键登录注册用户等等，需要检查密码
+ (BOOL)checkOpenAccountAuthorization;

/// 限制登录弹窗提示
/// @param message 提示内容 
+ (void)showRestrictLoginAlertWithMessage:(NSString *)message;

/// 打开生物识别规则web页面
+ (void)openBiometricRulesWebView;

// 确认调用的地方是否正常
+ (TTURLAction *)fastLoginAction;

// 清token并打开登录页（只有在token失效（比如被踢出登录、token过期）时，会调该方法。其他情况直接调openLoginVC 不用清token）
+ (void)clearTokenAndOpenLoginVC;

// 登录成功后销毁所有页面，并且登录页要有模态视图dissmiss的动画
+ (void)loginDidFinishHandleViewControllersIsSignUp:(BOOL)isSignUp;
@end

NS_ASSUME_NONNULL_END
