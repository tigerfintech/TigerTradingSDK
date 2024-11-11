//
//  TBLaunchLoadConfigManager.h
//  TBInitializeKit
//
//  Created by zhengzhiwen on 2024/2/29.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBToolsKit/GYBootingProtection.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBLaunchLoadConfigManager : NSObject

DECLARE_SHARED_INSTANCE(TBLaunchLoadConfigManager);

@property (nonatomic, copy) BoolCompletionBlock launchCrashFixCompletionBlock;

@property (nonatomic, assign, readonly) BOOL isPatchDisable;
@property (nonatomic, assign, readonly) BOOL isCrashlyticsAllDisable;
@property (nonatomic, assign, readonly) BOOL isCrashlyticsRecordDisable;
@property (nonatomic, assign, readonly) BOOL isCrashlyticsLogDisable;
@property (nonatomic, assign, readonly) BOOL isCrashlyticsConfigDisable;
@property (nonatomic, assign, readonly) BOOL isCrashlyticsTraceDisable;
@property (nonatomic, assign, readonly) BOOL isLagMonitorDisable;
@property (nonatomic, assign, readonly) BOOL isColdLaunchDisable;

- (void)startFixWithConfig;

@end

NS_ASSUME_NONNULL_END
