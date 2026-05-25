//
//  TBAppDelegate.m
//  TigerTradingSDK
//
//  Created by luopengfei on 08/30/2024.
//  Copyright (c) 2024 luopengfei. All rights reserved.
//

#import "TBAppDelegate.h"

#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import "TBViewController.h"

@implementation TBAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    [self.window makeKeyAndVisible];
    
    // Initialize the root view controller
    TBViewController *vc = [[TBViewController alloc] init];
    
     UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
     self.window.rootViewController = nav;
    return YES;
}


@end
