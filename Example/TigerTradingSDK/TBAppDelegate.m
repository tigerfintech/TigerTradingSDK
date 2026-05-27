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
    
    
    TigerTradingSDKConfig *sdkConfig = [[TigerTradingSDKConfig alloc] init];
    sdkConfig.appName = @"";
    sdkConfig.appSecret = @"";
    sdkConfig.tenantId = @"";
    sdkConfig.qaxEnvironmentName = @"";

    sdkConfig.networkType = TigerTradingSDKNetWork_UAT_ITFS;
    
    [TigerTradingSDKManager setupWithConfig:sdkConfig completionHandler:^(BOOL isSucc) {
        
    }];

    
    
    TigerTradingUserInformationModel *model = [[TigerTradingUserInformationModel alloc] init];
    model.external_phone = @"";
    model.external_email = @"";
    model.external_id = @"";
    model.external_client_id = @"";
    model.reg_source = @"";
    [TigerTradingSDKManager configUserInformation:model];
    

    
    // Initialize the root view controller
    TBViewController *vc = [[TBViewController alloc] init];
    
     UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
     self.window.rootViewController = nav;
    return YES;
}


@end
