//
//  TBAuthBusinessComponentService.h
//  Pods
//
//  Created by linbingjie on 2022/5/18.
//

#ifndef TBAuthBusinessComponentService_h
#define TBAuthBusinessComponentService_h

NS_ASSUME_NONNULL_BEGIN

@protocol TBAuthBusinessComponentService <NSObject>

/// 创建生物识别解锁controller
/// @param type 类型
- (UIViewController *)tbAuth_createTouchUnlockControllerWithType:(NSInteger)type;

/// 获取国家编码
/// @param info 通知info
- (nullable NSString *)tbAuth_countryCodeWithInfo:(NSDictionary *)info;

/// 获取国家名字
/// @param info 通知info
- (nullable NSString *)tbAuth_countryNameWithInfo:(NSDictionary *)info;

- (BOOL)tbAuth_canWechatUniversalLinkWithActivity:(NSUserActivity *)activity;

/// 获取验证码
/// - Parameters:
///   - processType: 验证场景（如：绑定邮件、绑定邮箱、修改登录密码登，具体可看TBVerifyDefines.h）
///   - methodType: 验证方式（手机、邮箱、老虎令牌，具体查看TBVerifyDefines.h）
///   - account: 账号（phone或email）
///   - telCode: 国际区号（account为email时，传空）
///   - completed: 用户输入完验证码后的回调，code是输入的验证码；verifyCodeViewController是输入验证码页面，便于前页面自行调用dissmiss
- (void)tbAuth_fetchVerifyCodeWithVerifyProcessType:(NSInteger)processType methodType:(NSInteger)methodType account:(nullable NSString *)account telCode:(nullable NSString *)telCode verifyCodeCompleted:(void(^)(NSString *code, UIViewController *verifyCodeViewController))completed;

@optional
- (void)tbAuth_openWechatAndSubscribe;

- (UIViewController *)tbAuth_getAccountSettingViewController;


/// 检测阿里云一键登录是否可用
- (void)tbAuth_checkAliEnvAvailableWithCompletion:(void (^)(BOOL isSuccess))completion;

/// 跳转阿里云一键登录
- (void)tbAuth_gotoAliOneClickLogin;

@end

NS_ASSUME_NONNULL_END

#endif /* TBAuthBusinessComponentService_h */
