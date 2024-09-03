//
//  TBFPSHelper.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2023/6/6.
//

#import <Foundation/Foundation.h>

@class TBFPSObject;

NS_ASSUME_NONNULL_BEGIN

typedef void (^TBFPSBlock)(TBFPSObject *fps);

@interface TBFPSHelper : NSObject

- (void)start;
- (void)end;
- (void)addFPSBlock:(TBFPSBlock)block;
- (BOOL)hasInitBlock;
- (NSArray *)fpsInfoWhenLagOccurWithDuration:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
