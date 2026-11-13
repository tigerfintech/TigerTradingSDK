#import "TBSceneDelegate.h"
#import "TBAppDelegate.h"

@implementation TBSceneDelegate

- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    if (![scene isKindOfClass:[UIWindowScene class]]) {
        return;
    }

    TBAppDelegate *appDelegate = (TBAppDelegate *)UIApplication.sharedApplication.delegate;
    [appDelegate configureWindowForScene:(UIWindowScene *)scene];
    self.window = appDelegate.window;

    // 冷启动回流在窗口准备好后交给原有 SDK 处理入口。
    [self scene:scene openURLContexts:connectionOptions.URLContexts];
    for (NSUserActivity *activity in connectionOptions.userActivities) {
        [self scene:scene continueUserActivity:activity];
    }
}

- (void)scene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts {
    UIApplication *application = UIApplication.sharedApplication;
    TBAppDelegate *appDelegate = (TBAppDelegate *)application.delegate;
    for (UIOpenURLContext *context in URLContexts) {
        NSMutableDictionary<UIApplicationOpenURLOptionsKey, id> *options = [NSMutableDictionary dictionary];
        if (context.options.sourceApplication) {
            options[UIApplicationOpenURLOptionsSourceApplicationKey] = context.options.sourceApplication;
        }
        if (context.options.annotation) {
            options[UIApplicationOpenURLOptionsAnnotationKey] = context.options.annotation;
        }
        options[UIApplicationOpenURLOptionsOpenInPlaceKey] = @(context.options.openInPlace);
        [appDelegate application:application openURL:context.URL options:options];
    }
}

- (void)scene:(UIScene *)scene continueUserActivity:(NSUserActivity *)userActivity {
    UIApplication *application = UIApplication.sharedApplication;
    TBAppDelegate *appDelegate = (TBAppDelegate *)application.delegate;
    [appDelegate application:application continueUserActivity:userActivity restorationHandler:^(NSArray<id<UIUserActivityRestoring>> *restorableObjects) {
        // SDK 负责回流处理，Example 不需要额外恢复控制器。
    }];
}

- (void)sceneDidBecomeActive:(UIScene *)scene {
    UIApplication *application = UIApplication.sharedApplication;
    [(TBAppDelegate *)application.delegate applicationDidBecomeActive:application];
}

- (void)sceneWillResignActive:(UIScene *)scene {
    UIApplication *application = UIApplication.sharedApplication;
    [(TBAppDelegate *)application.delegate applicationWillResignActive:application];
}

- (void)sceneWillEnterForeground:(UIScene *)scene {
    UIApplication *application = UIApplication.sharedApplication;
    [(TBAppDelegate *)application.delegate applicationWillEnterForeground:application];
}

- (void)sceneDidEnterBackground:(UIScene *)scene {
    UIApplication *application = UIApplication.sharedApplication;
    [(TBAppDelegate *)application.delegate applicationDidEnterBackground:application];
}

- (void)sceneDidDisconnect:(UIScene *)scene {
    TBAppDelegate *appDelegate = (TBAppDelegate *)UIApplication.sharedApplication.delegate;
    if (appDelegate.window == self.window) {
        appDelegate.window = nil;
    }
    self.window = nil;
}

@end
