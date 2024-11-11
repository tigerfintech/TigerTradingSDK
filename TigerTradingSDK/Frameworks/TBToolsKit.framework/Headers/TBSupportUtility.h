//
//  TBSupportUtility.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/4/14.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TBTabBarBaseController.h>

#define TB_TRADEUP_UNCONFIRMED_ALERT(TITLE,MSG)   [TBSupportUtility tradeUPWarningAlert:TITLE message:MSG]

NS_ASSUME_NONNULL_BEGIN

@class TBTabBarBaseController;

@interface TBSupportUtility : NSObject


/**
 获取顶部VC
 ipad 横屏获取到的是右边页面的vc
 */
+ (UIViewController *)getTopVC;

// 获取tabBarController
+ (TBTabBarBaseController *)getTabBarController;

//自定义searchBar背景色
+ (UIImage*)searchFieldBackgroundImage;

+ (void)openInSafari:(NSString *)url;

//是否有权限打开相册,如果没有权限就申请
+ (void)requestAuthorizationStatus:(void(^)(BOOL enable))success;

+ (void)tradeUPWarningAlert:(NSString *)title message:(NSString *)message;

+ (void)dismissMZFormSheetCompletion:(void (^ __nullable)(void))completion;

// 当前是否有弹框类展示
+ (BOOL)hasAlertShowing;

/// 获取viewController在tabbar中的index。如果不是一级tab，则返回-1
/// - Parameter viewController: 目标vc
+ (NSInteger)tabBarControllerIndexFromViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
