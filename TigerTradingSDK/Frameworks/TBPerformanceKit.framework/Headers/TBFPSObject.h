//
//  TBFPSObject.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2023/6/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFPSObject : NSObject

@property (nonatomic, assign) NSTimeInterval ts;
@property (nonatomic, assign) NSInteger fps;

@end

NS_ASSUME_NONNULL_END
