//
//  TBLagRequestObject.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2022/11/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBLagRequestObject : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) BOOL isSuccess;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, strong) NSNumber *cost;
@property (nonatomic, assign) BOOL isFinished;
@property (nonatomic, assign) NSTimeInterval startTime;
@property (nonatomic, assign) NSTimeInterval endTime;

@end

NS_ASSUME_NONNULL_END
