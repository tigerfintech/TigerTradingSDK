//
//  TBLoggerDateCandidate.h
//  TBPerformanceKit
//
//  Created by swordzhou on 2022/9/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBLoggerDateCandidate : NSObject

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSArray *dates;
@property (nonatomic, assign) BOOL fromPush;
@property (nonatomic, assign) BOOL upload; //表示是否需要上传

@end

NS_ASSUME_NONNULL_END
