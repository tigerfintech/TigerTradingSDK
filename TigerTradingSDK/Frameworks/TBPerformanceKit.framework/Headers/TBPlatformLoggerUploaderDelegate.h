//
//  TBPlatformLoggerUploaderDelegate.h
//  TBPerformanceKit
//
//  Created by swordzhou on 2021/9/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TBPlatfromLoggerConfig;

@protocol TBPlatformLoggerUploaderDelegate <NSObject>

@required
- (void)uploadLog:(NSString *)log date:(NSString *)date config:(TBPlatfromLoggerConfig *)config complection:(void(^)(BOOL success, NSString *fileUrl))completion;

@end

NS_ASSUME_NONNULL_END
