//
//  TBPhoneUtility.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/1/28.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBSystemVersionMacro.h>
#import <TBBaseKit/TBBaseKitUtil.h>

NS_ASSUME_NONNULL_BEGIN

#define IS_IPAD                                             ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
#define IS_IPHONE                                           ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPhone)
#define IS_RETINA                                           ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH                                        ([TBPhoneUtility fetchScreenWidth])
#define SCREEN_HEIGHT                                       ([TBPhoneUtility fetchScreenHeight])

#define SCREEN_FIT(x)                                       (x * SCREEN_WIDTH / 375.0)
#define SCREEN_ADAPTATION_WIDTH(x, standardWidth)           (x * standardWidth / 375.0)
#define SCREEN_MAX_LENGTH                                   (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH                                   (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_CENTER_X                                     (SCREEN_WIDTH / 2.0)
#define SCREEN_CENTER_Y                                     (SCREEN_HEIGHT / 2.0)
#define SCREEN_RATIO_6P_VERSUS_6                            (IS_IPHONE_6P ? (736.0 / 667.0) : 1)
#define STATUSBAR_HEIGHT                                    (TBBaseKitUtil.tbGetStatusBarHeight)
#define NAVBAR_HEIGHT                                       44

#define IS_IPHONE_4_OR_LESS                                 (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5_OR_LESS                                 (IS_IPHONE && SCREEN_MAX_LENGTH <= 568.0)

#define IS_IPHONE_5                                         (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6                                         (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6_OR_LESS                                 (IS_IPHONE && SCREEN_MAX_LENGTH <= 667.0)
#define IS_IPHONE_6P                                        (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
#define IS_IPHONE_6P_OR_LESS                                (IS_IPHONE && SCREEN_MAX_LENGTH <= 736.0)

#define IS_IPHONE_X (TBBaseKitUtil.tbGetKeyWindow.safeAreaInsets.bottom > 0.0)

#define is_iPhoneXSerious IS_IPHONE_X

#define SAFEAREA_TOP_HEIGHT (TBBaseKitUtil.tbGetKeyWindow.safeAreaInsets.top)

#define SAFEAREA_BOTTOM_HEIGHT (TBBaseKitUtil.tbGetKeyWindow.safeAreaInsets.bottom)

#define SAFEAREA_STATUSBAR_HEIGHT (TBBaseKitUtil.tbGetKeyWindow.safeAreaInsets.top ?: 20)

#define SAFEAREA_TOP                                        (SAFEAREA_STATUSBAR_HEIGHT + NAVBAR_HEIGHT)
#define REAL_SCREEN_HEIGHT                                  (SCREEN_HEIGHT - SAFEAREA_TOP - SAFEAREA_BOTTOM_HEIGHT)

#define BX(obj)                                             obj.bounds.origin.x
#define BY(obj)                                             obj.bounds.origin.y
#define BW(obj)                                             obj.bounds.size.width
#define BH(obj)                                             obj.bounds.size.height
#define W(w)                                                (BW([UIScreen mainScreen])/320*w)
#define H(h)                                                (BH([UIScreen mainScreen])/728*h)

#define TAB_BAR_HEIGHT                                      64
#define VIEW_BOTTOM_HEIGHT                                  45
#define OPTIONLANDSCAPEWIDTH                                75

static NSString * const kSDKVersion = @"TQ_SDKVersion";

/*
 tigertrade
 App Store中要显示4位版本号，CFBundleShortVersionString只支持3位，经调查这两个可以不一致。
 在info.plist新增一个TBAppStoreVersionString来表示App Store中的版本号，app中也使用这个，
 每次提交新版本时同步更改，如果有bugfix版本，在CFBundleShortVersionString最后一位递增
 
 tradeup
 直接读CFBundleShortVersionString
 */
#define APPVERSION                       [TBPhoneUtility fetchAppVersion]


@interface TBPhoneUtility : NSObject

//系统语言
+ (NSString *)iOSSystemLanguage;

#pragma mark - system
+ (BOOL)isSize4s;
+ (BOOL)isSize6Plus;
+ (BOOL)isSize6;
+ (BOOL)isSize5s;
+ (BOOL)isDeviceWidthLargerThan320;

#pragma mark - network connection
+ (BOOL)WIFIConnected;
+ (BOOL)NETConnect;

#pragma mark - phone call
+ (void)callNumbersWithArray:(NSArray *)numberArray presentVC:(UIViewController  * _Nonnull)vc;


// 检测app是否在后台.
+ (BOOL)isAppRunInBackground;
+ (BOOL)isAppRunInForeground;

// 当前是否横屏
+ (BOOL)isCurrentLandscape;

+ (NSString *)fetchAppVersion;
+ (void)tradeUPAssert;

+ (CGFloat)fetchScreenWidth;
+ (CGFloat)fetchScreenHeight;

+ (BOOL)isDisplayZoomed;

@end

NS_ASSUME_NONNULL_END
