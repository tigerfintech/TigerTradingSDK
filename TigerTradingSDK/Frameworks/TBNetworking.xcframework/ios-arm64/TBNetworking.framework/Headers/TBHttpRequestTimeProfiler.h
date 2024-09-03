//
//  TBHttpRequestTimeProfiler.h
//  TBNetworking
//
//  Created by 王昌阳 on 2022/10/31.
//

#import <Foundation/Foundation.h>
#import <Foundation/NSURLSession.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHttpRequestTimeProfiler : NSObject

+ (void)profileRequest:(NSURLRequest *)request metrics:(NSURLSessionTaskMetrics *)metrics;

@end

NS_ASSUME_NONNULL_END
