//
//  TBBaseKitUtil.h
//  TBBaseKit
//
//  Created by zhengzhiwen on 2021/6/7.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *USER_DEFAULT_KEY_SERVER_SETTING = @"serverSetting"; // 服务器设置: 0 测试, 2 线上
static NSString *kTB_USER_DEFAULT_AUTO_TEST_SWITCH = @"kTB_USER_DEFAULT_AUTO_TEST_SWITCH"; ///<自动化测试key（打开后登录时不需要recaptcha验证）

@interface TBBaseKitUtil : NSObject

/// 返回当前是测试/线上环境. YES 测试, NO 线上.
+ (BOOL)isTestEnvironment;

//本地化图片名称，需要保证本地化目录下存在对应的图片
+ (NSString *)localizedImageName:(NSString *)name;
+ (BOOL)itemDefauleTrueValueForKey:(NSString *)key;
+ (BOOL)itemDefauleFalseValueForKey:(NSString *)key;

+ (UIImage *)imageWithView:(UIView *)view;
/// 是否安装TestFlight
+ (BOOL)isTestFlightInstalled;
/// 是否是沙盒环境.
+ (BOOL)isSandboxEnvironment;
/*
 是否是TestFlight构建版本，用于区分内测包还是正式包
 打testflight包且带测试环境时才会返回YES
 */
+ (BOOL)isTestFlightBuildVersion;
// 返回当前网络环境title
+ (NSString *)environmentTitle;

+ (nullable UIWindow *)tbGetKeyWindow;

+ (CGFloat)tbGetStatusBarHeight;

// 自动化开关是否打开
+ (BOOL)isAutoTestSwitchOn;

// 更新自动化开关状态
+ (void)updateAutoTestSwitch:(BOOL)isOn;

+ (BOOL)isIpad;

@end

NS_ASSUME_NONNULL_END
