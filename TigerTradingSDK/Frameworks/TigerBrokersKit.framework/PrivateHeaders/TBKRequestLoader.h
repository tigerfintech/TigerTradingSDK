//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

// Network
#import "TigerBrokersKit/TTURLRequestCachePolicy.h"

// Core
#import "TigerBrokersKit/TBKCorePreprocessorMacros.h" // For __TBKDEPRECATED_METHOD

@class TBKURLRequestQueue;
@class TBKURLRequest;
@class TBKURLResponse;

NS_ASSUME_NONNULL_BEGIN

/**
 * The loader manages a set of TBKURLRequests and makes the necessary callbacks for each.
 * It implements the NSURLConnectionDelegate protocol and calls the required operations on the
 * queue as the protocol methods are invoked.
 *
 * NSURLErrorCannotFindHost errors are retried at least twice before completely giving up.
 *
 * The loader collects identical GET TBKURLRequests into a single object. This logic is handled in
 * TBKURLRequestQueue's sendRequest.
 * For all other TBKURLRequest types, they will each have their own loader.
 */
@interface TBKRequestLoader : NSObject

/**
 * The common urlPath shared by every request.
 */
@property (nonatomic, readonly) NSString* urlPath; // 用于取缓存, 应该包含参数
@property (nonatomic, readonly) NSString *urlString;

/**
 * The common cacheKey shared by every request.
 */
@property (nonatomic, readonly) NSString* cacheKey;

/**
 * The common cache policy shared by every request.
 */
@property (nonatomic, readonly) TTURLRequestCachePolicy cachePolicy;

/**
 * The common cache expiration age shared by ever request.
 */
@property (nonatomic, readonly) NSTimeInterval cacheExpirationAge;

/**
 * The list of TBKURLRequests currently attached to this loader.
 */
@property (nonatomic, readonly) NSArray* requests;

/**
 * Whether or not any of the requests in this loader are loading.
 */
@property (nonatomic, readonly) BOOL isLoading;


- (id)initForRequest:(TBKURLRequest *)request queue:(TBKURLRequestQueue *)queue;

/**
 * Duplication is possible due to the use of an NSArray for the request list.
 */
- (void)addRequest:(TBKURLRequest *)request;
- (void)removeRequest:(TBKURLRequest *)request;

/**
 * If the loader isn't already active, create the NSURLRequest from the first TBKURLRequest added
 * to this loader and fire it off.
 */
- (void)load:(NSURL *)URL;

/**
 * Cancel only the given request.
 *
 * @return NO   If there are no requests left.
 *         YES  If there are any requests left.
 */
- (BOOL)cancel:(TBKURLRequest *)request;

- (TBKURLResponse *)processResponse:(NSHTTPURLResponse *)response data:(id)data error:(NSError *)error;
- (void)dispatchFailedResponse:(TBKURLResponse *)response withError:(NSError *)error;
- (void)dispatchLoadedResponse:(TBKURLResponse *)response withTimestamp:(NSDate *)timestamp;
- (void)dispatchAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;
- (void)cancel;

@end

@interface TBKRequestLoader (AFNetworking)

/// 使用 AFNetworking 生成要发送的 NSURLRequest
- (NSMutableURLRequest *)afn_createNSURLRequest:(TBKURLRequest *)request URL:(NSURL *)URL;

/// 使用 AFNetworking 的底层接口发送请求
- (NSURLSessionDataTask *)afn_loadRequest:(NSURLRequest *)request uploadProgress:(nullable void (^)(NSProgress *uploadProgress))uploadProgressBlock downloadProgress:(nullable void (^)(NSProgress *downloadProgress))downloadProgressBlock completionHandler:(nullable void (^)(NSURLResponse *response, id _Nullable responseObject,  NSError * _Nullable error))completionHandler;

/// 使用 AFNetworking 的方法根据请求的 responseSerializer 生成 responseObject
- (id)afn_responseObjectWithSerializerType:(NSInteger)serializerType response:(NSURLResponse *)response data:(NSData *)data error:(NSError *__autoreleasing *)error;


// TODO: 添加 AFNetworking 相对高级的 GET/POST 等接口
- (nullable NSURLSessionDataTask *)GET:(NSString *)URLString parameters:(nullable id)parameters success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

- (nullable NSURLSessionDataTask *)HEAD:(NSString *)URLString parameters:(nullable id)parameters success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

- (nullable NSURLSessionDataTask *)POST:(NSString *)URLString parameters:(nullable id)parameters success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

- (nullable NSURLSessionDataTask *)PUT:(NSString *)URLString parameters:(nullable id)parameters success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

- (nullable NSURLSessionDataTask *)PATCH:(NSString *)URLString parameters:(nullable id)parameters success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

- (nullable NSURLSessionDataTask *)DELETE:(NSString *)URLString parameters:(nullable id)parameters success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

@end
NS_ASSUME_NONNULL_END
