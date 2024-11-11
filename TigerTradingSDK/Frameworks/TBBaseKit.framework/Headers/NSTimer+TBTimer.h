//
//  NSTimer+TBTimer.h
//  Stock
//
//  Created by luopengfei on 2018/8/15.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTimer (TBTimer)
- (void)pause;
- (void)resume;
- (void)resumeWithDelay:(NSTimeInterval)delay;

+ (NSTimer *_Nullable)tb_scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats block:(void (^_Nullable)(NSTimer * _Nonnull timer))block;

+ (NSTimer *_Nullable)tb_scheduledWithFireDate:(NSDate *_Nullable)date
                                   timeInterval:(NSTimeInterval)interval
                                        repeats:(BOOL)repeats
                                          block:(void (^_Nullable)(NSTimer * _Nonnull timer))block;

@end
