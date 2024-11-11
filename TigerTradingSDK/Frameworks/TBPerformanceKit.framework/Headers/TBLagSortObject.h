//
//  TBLagSortObject.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2022/9/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBLagSortObject : NSObject

@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *value;

@end

NS_ASSUME_NONNULL_END
