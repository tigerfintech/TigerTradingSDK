//
//  CTCache.h
//  RTNetworking
//
//  Created by casa on 14-5-26.
//  Copyright (c) 2014年 casatwy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBKURLResponse.h"

@interface CTMemoryCacheDataCenter : NSObject

- (TBKURLResponse *)fetchCachedRecordWithKey:(NSString *)key;
- (void)saveCacheWithResponse:(TBKURLResponse *)response key:(NSString *)key cacheTime:(NSTimeInterval)cacheTime;
- (void)cleanAll;

@end
