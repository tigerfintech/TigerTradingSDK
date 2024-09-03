//
//  AppDelegate+TBDebugTool.h
//  Stock
//
//  Created by JustLee on 2021/3/22.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "AppDelegate.h"
@class TBPlatformLoggerData;
@class TBPlatformLoggerManager;

NS_ASSUME_NONNULL_BEGIN

static NSString *const kShakeAbleKey = @"tb_ShakeAbleKey";

@interface AppDelegate (TBDebugTool)

@property (nonatomic, strong) TBPlatformLoggerData *loggerData;

@property (nonatomic, strong) TBPlatformLoggerManager *loggerManager;

- (void)tb_setupDebugTool;

- (void)configLogger;

@end

NS_ASSUME_NONNULL_END
