//
//  TBAppDelegate.m
//  TigerTradingSDK
//
//  Created by luopengfei on 08/30/2024.
//  Copyright (c) 2024 luopengfei. All rights reserved.
//

#import "TBAppDelegate.h"

#import <TigerQuoteSDK/TigerQuoteSDKManager.h>
#import "TBViewController.h"

#import <AFNetworking/AFNetworking.h>

@implementation TBAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    [self.window makeKeyAndVisible];
    
    // Setup SDK with options and clientId
    [TigerQuoteSDKManager setupWithOption:launchOptions clientId:@"1012892644333"];

    // Initialize the root view controller
    TBViewController *vc = [[TBViewController alloc] init];
    
    // If you want to use a navigation controller, uncomment the following lines
    // UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    // self.window.rootViewController = nav;
    self.window.rootViewController = vc;
    return YES;
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
