//
//  TBAppDelegate.h
//  TigerQuoteSDK
//
//  Created by linbingjie on 08/08/2024.
//  Copyright (c) 2024 linbingjie. All rights reserved.
//

@import UIKit;

@interface TBAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

/// 创建 Scene 对应的 Example 窗口，并保留 AppDelegate.window 兼容现有代码。
- (void)configureWindowForScene:(UIWindowScene *)windowScene API_AVAILABLE(ios(13.0));

+ (void)updateUserInfoConfig;

@end
