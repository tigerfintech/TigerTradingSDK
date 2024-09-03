//
//  TBKNetworkLogger.h
//  TBKNetwork
//
//  Created by donggf on 2018/3/6.
//  Copyright © 2018年 TIGER BROKERS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTService.h"
#import "CTLoggerConfiguration.h"

@class TBKURLResponse;

@interface TBKNetworkLogger : NSObject

// 新版去掉了设置项，设置项用于发送log
@property (nonatomic, strong, readonly) CTLoggerConfiguration *configParams;

// log request
+ (NSString *)logDebugInfoWithRequest:(NSURLRequest *)request apiName:(NSString *)apiName service:(CTService *)service requestParams:(id)requestParams httpMethod:(NSString *)httpMethod;

// log response
+ (NSString *)logDebugInfoWithResponse:(TBKURLResponse *)response request:(NSURLRequest *)request error:(NSError *)error;

// log cache
+ (NSString *)logDebugInfoWithCachedResponse:(TBKURLResponse *)response methodName:(NSString *)methodName serviceIdentifier:(CTService *)service params:(NSDictionary *)params;

// delete in new version
+ (instancetype)sharedInstance;
- (void)logWithActionCode:(NSString *)actionCode params:(NSDictionary *)params;

@end
