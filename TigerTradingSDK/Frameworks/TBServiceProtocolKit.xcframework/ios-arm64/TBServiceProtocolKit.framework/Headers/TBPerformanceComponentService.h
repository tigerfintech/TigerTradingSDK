//
//  TBPerformanceComponentService.h
//  TBServiceProtocolKit
//
//  Created by linbingjie on 2022/7/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBPerformanceComponentService <NSObject>

// type 对应TBlogType中定义的type
// level 对应DDLogLevel定义的level
// flag 对应DDLogFlag定义的flag
- (void)tb_logMaybeType:(NSInteger)type
                  level:(NSInteger)level
                   flag:(NSInteger)flag
                   func:(const char *)func
                 format:(NSString *)format, ... NS_FORMAT_FUNCTION(5,6);

- (NSInteger)tb_getTBLogLevel;

- (void)tbPerformance_crashlyticsLog:(NSString *)msg;
- (void)tb_setCustomValue:(id)value forKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
