//
//  TBPlatformLoggerManager.h
//  TBPerformanceKit
//
//  Created by swordzhou on 2022/9/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TBLoggerDateCandidate;

@interface TBPlatformLoggerManager : NSObject

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSString *host;

- (void)startMonitor:(void (^)(TBLoggerDateCandidate *candidate))callback;

- (void)start;

- (void)notifiyServerUploadFinished:(NSString *)uuid completion:(void (^)(BOOL success))completion;

@end

NS_ASSUME_NONNULL_END
