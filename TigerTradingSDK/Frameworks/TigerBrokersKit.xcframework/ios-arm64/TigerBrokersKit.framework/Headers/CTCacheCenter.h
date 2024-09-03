//
//  CTCacheCenter.h
//  BLNetworking
//
//  Created by casa on 2016/11/21.
//  Copyright © 2016年 casa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBKURLResponse.h"

@interface CTCacheCenter : NSObject

+ (instancetype)sharedInstance;

- (TBKURLResponse *)fetchDiskCacheWithServiceIdentifier:(NSString *)serviceIdentifier methodName:(NSString *)methodName params:(NSDictionary *)params;
- (TBKURLResponse *)fetchMemoryCacheWithServiceIdentifier:(NSString *)serviceIdentifier methodName:(NSString *)methodName params:(NSDictionary *)params;

- (void)saveDiskCacheWithResponse:(TBKURLResponse *)response serviceIdentifier:(NSString *)serviceIdentifier methodName:(NSString *)methodName cacheTime:(NSTimeInterval)cacheTime;
- (void)saveMemoryCacheWithResponse:(TBKURLResponse *)response serviceIdentifier:(NSString *)serviceIdentifier methodName:(NSString *)methodName cacheTime:(NSTimeInterval)cacheTime;

- (void)cleanAllMemoryCache;
- (void)cleanAllDiskCache;

@end
