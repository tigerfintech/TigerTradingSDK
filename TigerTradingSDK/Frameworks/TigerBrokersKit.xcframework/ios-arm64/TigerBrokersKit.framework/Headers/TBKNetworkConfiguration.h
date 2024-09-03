//
//  TBKNetworkConfiguration.h
//  TigerBrokersKit
//
//  Created by donggf on 2018/8/23.
//

#import <Foundation/Foundation.h>

@interface TBKNetworkConfiguration : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, assign, readonly) BOOL isReachable;

@property (nonatomic, assign) BOOL shouldCache;
@property (nonatomic, assign) BOOL serviceIsOnline;
@property (nonatomic, assign) NSTimeInterval apiNetworkingTimeoutSeconds;
@property (nonatomic, assign) NSTimeInterval cacheOutdateTimeSeconds;
@property (nonatomic, assign) NSInteger cacheCountLimit;

//默认值为NO，当值为YES时，HTTP请求除了GET请求，其他的请求都会将参数放到HTTPBody中，如下所示
//request.HTTPBody = [NSJSONSerialization dataWithJSONObject:requestParams options:0 error:NULL];
@property (nonatomic, assign) BOOL shouldSetParamsInHTTPBodyButGET;

// from ytknetwork
@property (nonatomic, strong) NSURLSessionConfiguration* sessionConfiguration;

// 创建request类的参数
@property (nonatomic, assign) NSURLRequestCachePolicy cachePolicy;
@end
