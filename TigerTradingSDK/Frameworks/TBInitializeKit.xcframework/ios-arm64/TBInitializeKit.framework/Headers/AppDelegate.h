//
//  AppDelegate.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBBaseKit/TBBaseAppDelegate.h>

@interface AppDelegate : TBBaseAppDelegate

@property (strong, nonatomic) UIViewController *viewController;

- (void)didFinishLaunch;
- (void)setupBaseConfig;

@end

