//
//  CTDiskCacheCenter.h
//  BLNetworking
//
//  Created by casa on 2016/11/21.
//  Copyright © 2016年 casa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBKURLResponse.h"

@interface CTDiskCacheCenter : NSObject

- (TBKURLResponse *)fetchCachedRecordWithKey:(NSString *)key;
- (void)saveCacheWithResponse:(TBKURLResponse *)response key:(NSString *)key cacheTime:(NSTimeInterval)cacheTime;
- (void)cleanAll;

@end
