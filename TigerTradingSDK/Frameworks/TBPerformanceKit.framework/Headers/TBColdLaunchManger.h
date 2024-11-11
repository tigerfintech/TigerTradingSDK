//
//  TBColdLaunchManger.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2022/3/28.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBColdLaunchManger : NSObject

DECLARE_SHARED_INSTANCE(TBColdLaunchManger);

@property (nonatomic, strong) dispatch_queue_t queue;

- (void)start:(NSString *)methodName;
- (void)end;

- (void)finishPreMain;
- (void)finishAppdelegateLaunch;
- (void)finishFirstPageLaunch;

@end

NS_ASSUME_NONNULL_END
