//
//  TBAppDelegate.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 08/08/2024.
//  Copyright (c) 2024 linbingjie. All rights reserved.
//

#import "TBAppDelegate.h"
#import "TBExampleConfig.h"
#if !TB_PUBLIC_EXAMPLE
#import "TBInternalExampleConfig.h"
@import TBAccountSystemKit;
#endif
#import "TBSceneDelegate.h"
#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import <TigerTradingSDK/TigerTradingSDKSettingManager.h>
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
#import <TigerTradingSDK/TigerQuoteDebugMananger.h>
#endif
#import "TBViewController.h"
#import <CoreText/CoreText.h>
#import <TigerTradingSDK/TigerTradingSDKModel.h>
#if !TB_PUBLIC_EXAMPLE
#import "TBAppDelegate+TBDebugTool.h"
#endif


#import "RootTabVarViewController.h"

@import TBBaseKit;

@implementation TBAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    // 窗口统一由 SceneDelegate 在连接场景时创建。
    
    // 初始化用来替换的字体
    [self loadFontWithFileName:@"Merriweather-Bold.ttf" bundleName:nil];
    [self loadFontWithFileName:@"Merriweather-Regular.ttf" bundleName:nil];

    // Setup SDK with options and clientId

    NSDictionary *config = [[NSUserDefaults standardUserDefaults] objectForKey:kTigerTradeLaunchConfig];
    TBExampleConfig *exampleConfig = [[TBExampleConfig alloc] init];
#if !TB_PUBLIC_EXAMPLE
    exampleConfig = [[TBInternalExampleConfig alloc] init];
#endif
    TigerTradingSDKConfig *sdkConfig = [exampleConfig configurationWithLaunchSettings:config];
    [TigerTradingSDKManager setupWithConfig:sdkConfig completionHandler:^(BOOL isSucc) {
        
    }];
    
    [self.class updateUserInfoConfig];
    // 给 demoApp 的 webview UA 加 "DemoApp" 标识
    [TBAppManager setCustomUserAgentSuffix:@"DemoApp"];
    [TBAPPFunctionConfigManager sharedInstance].debug_watchlistMode = TBSDKWatchlistModeDisabled; // 设置为SDK自己维护自选

#ifdef DEBUG
    [TigerTradingSDKManager setupSDKDebugMode:YES];
#else
#endif
    
    TigerTradingCustomColorModel *colorModel = [[TigerTradingCustomColorModel alloc] init];
    colorModel.light_HexColor = @"0x005DAA";
    colorModel.dark_HexColor = @"0x005DAA";
    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeBrandColor
                                            colorModel:colorModel];
    
    
    TigerTradingCustomColorModel *disableColorModel = [[TigerTradingCustomColorModel alloc] init];
    disableColorModel.light_HexColor = @"0x005DAA";
    disableColorModel.light_alpha = @(0.3);
    disableColorModel.dark_HexColor = @"0x005DAA";
    disableColorModel.dark_alpha = @(0.3);
    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeBrandDisable
                                            colorModel:disableColorModel];

    TigerTradingCustomColorModel *hightLightColorModel = [[TigerTradingCustomColorModel alloc] init];
    hightLightColorModel.light_HexColor = @"0x005DAA";
    hightLightColorModel.light_alpha = @(0.8);
    hightLightColorModel.dark_HexColor = @"0x005DAA";
    hightLightColorModel.dark_alpha = @(0.8);
    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeBrandUpInside
                                            colorModel:hightLightColorModel];

    
    
    TigerTradingCustomColorModel *labelNormalModel = [[TigerTradingCustomColorModel alloc] init];
    labelNormalModel.light_HexColor = @"0xe0e0e0";
    labelNormalModel.dark_HexColor = @"0xe0e0e0";
    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeBrandTitleNormal
                                            colorModel:labelNormalModel];
    
    // 蓝色
    TigerTradingCustomColorModel *quoteRiseColor = [[TigerTradingCustomColorModel alloc] init];
    quoteRiseColor.light_HexColor = @"0x00b5ff";
    quoteRiseColor.dark_HexColor = @"0x00b5ff";
    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteFallColor
                                            colorModel:quoteRiseColor];
    // 紫色
    TigerTradingCustomColorModel *quoteFallColor = [[TigerTradingCustomColorModel alloc] init];
    quoteFallColor.light_HexColor = @"0xb366ff";
    quoteFallColor.dark_HexColor = @"0xb366ff";
    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteRiseColor
                                            colorModel:quoteFallColor];

    
//    TigerTradingCustomColorModel *quoteRiseColor = [[TigerTradingCustomColorModel alloc] init];
//    quoteRiseColor.light_HexColor = @"0xFF0000";
//    quoteRiseColor.dark_HexColor = @"0xFF0000";
//    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteRiseColor
//                                            colorModel:quoteRiseColor];
//    
//    TigerTradingCustomColorModel *quoteFallColor = [[TigerTradingCustomColorModel alloc] init];
//    quoteFallColor.light_HexColor = @"0x00FF00";
//    quoteFallColor.dark_HexColor = @"0x00FF00";
//    [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteFallColor
//                                            colorModel:quoteFallColor];
//    
//    [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeGreen];
//    
    
#if TTSDK_TEST
    [exampleConfig registerDebugLogger];
#endif
    [[NSUserDefaults standardUserDefaults] setObject:@([exampleConfig languageDebugEnabled]) forKey:@"LanguageDebugUserDefaultsKey"];
    
#if DEBUG
    NSString *injectionBundlePath = [exampleConfig injectionBundlePath];
    if (injectionBundlePath.length > 0) {
        [[NSBundle bundleWithPath:injectionBundlePath] load];
    }
#endif

    // UI Test 模式：注册日志导出通知
    if ([NSProcessInfo.processInfo.arguments containsObject:@"-UITesting"]) {
        [exampleConfig registerUITestLogExportNotification];
    }

    return YES;
}

- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options API_AVAILABLE(ios(13.0)) {
    BOOL applicationScene = [connectingSceneSession.role isEqualToString:UIWindowSceneSessionRoleApplication];
    UISceneConfiguration *configuration = [[UISceneConfiguration alloc] initWithName:applicationScene ? @"Default Configuration" : nil sessionRole:connectingSceneSession.role];
    if (applicationScene) {
        configuration.delegateClass = [TBSceneDelegate class];
    }
    return configuration;
}

- (void)configureWindowForScene:(UIWindowScene *)windowScene {
    if (self.window.windowScene == windowScene) {
        return;
    }
    self.window = [[UIWindow alloc] initWithWindowScene:windowScene];
    [self p_configureRootViewController];
}

- (void)p_configureRootViewController {
    BOOL useTabbar = YES;

    if (useTabbar) {
        RootTabVarViewController *rootVC = [[RootTabVarViewController alloc] init];
        self.window.rootViewController = rootVC;
    }
    else {
        // Initialize the root view controller
        TBViewController *vc = [[TBViewController alloc] init];

    //     If you want to use a navigation controller, uncomment the following lines
         UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
         self.window.rootViewController = nav;
    //    self.window.rootViewController = vc;
    }


    [self.window makeKeyAndVisible];
#if TTSDK_TEST && !TB_PUBLIC_EXAMPLE
    [self setupDebugTool];
#endif
}



// 动态加载自定义字体
- (void)loadFontWithFileName:(NSString *)fileName bundleName:(NSString *)bundleName {
    if (!fileName) {
        return;;
    }
    NSBundle *bundle = nil;
    if (bundleName) {
        bundle = [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:bundleName ofType:@"bundle"]];
    }
    else {
        bundle = [NSBundle mainBundle];
    }
    
    if (!bundle) {
        NSBundle *bundleUI = [NSBundle bundleForClass:NSClassFromString(@"TBBaseViewController")];
        NSURL *url = [bundleUI URLForResource:@"TBUIKit" withExtension:@"bundle"];
        bundle = [NSBundle bundleWithURL:url];
    }
    NSString *filePath = [bundle pathForResource:fileName ofType:nil];
    NSURL *fontURL = [NSURL fileURLWithPath:filePath];
    NSData *inData = [NSData dataWithContentsOfURL:fontURL];
    CFErrorRef error;
    CGDataProviderRef provider = CGDataProviderCreateWithCFData((CFDataRef)inData);
    CGFontRef font = CGFontCreateWithDataProvider(provider);
    if (!CTFontManagerRegisterGraphicsFont(font, &error)) {
        CFStringRef errorDescription = CFErrorCopyDescription(error);
        NSLog(@"Failed to load font: %@", errorDescription);
        CFRelease(errorDescription);
    }
    else {
        // 每次新增字体打开注释获取真正的字体名称
//        NSString *fontName = CFBridgingRelease(CGFontCopyPostScriptName(font));
//        NSLog(@"fontName: %@",fontName);
    }
    CFSafeRelease(font);
    CFSafeRelease(provider);
}

void CFSafeRelease(CFTypeRef cf) { // redefine this
  if (cf != NULL) {
    CFRelease(cf);
  }
}

+ (void)updateUserInfoConfig {
    TBExampleConfig *exampleConfig = [[TBExampleConfig alloc] init];
#if !TB_PUBLIC_EXAMPLE
    exampleConfig = [[TBInternalExampleConfig alloc] init];
    TBSDK_LOG([TBLoginManager sharedInstance].sdkUserInfomationModel.external_client_id);
#endif
    [exampleConfig updateUserInfoConfig];
}

#pragma mark - Orientation

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window {
    return UIInterfaceOrientationMaskAllButUpsideDown;
}

#pragma mark - SDK URL Scheme 转发

// demoApp://tusdk/openWebview?url=xxx 这类 SDK scheme 唤起转给 SDK
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options {
    if ([TigerTradingSDKManager handleSDKURL:url]) {
        return YES;
    }
    return NO;
}

// Universal Link 回流(www-callback*.tradeup.com/partner/tradeup/...)转给 SDK
- (BOOL)application:(UIApplication *)application
    continueUserActivity:(NSUserActivity *)userActivity
      restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> *_Nullable))restorationHandler {
    if ([TigerTradingSDKManager handleSDKUserActivity:userActivity]) {
        return YES;
    }
    return NO;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
