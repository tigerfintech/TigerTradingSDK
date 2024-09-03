//
//  TBKURLRequest.h
//  TigerBrokersKit
//
//  Created by donggf on 2018/8/23.
//  Copyright © 2018年 TIGER BROKERS. All rights reserved.
//

#import <Foundation/Foundation.h>

// Network
#import "TTURLRequestCachePolicy.h"

#import "TBKURLRequestDelegate.h"
#import "TTErrorCodes.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * A constant to improve code readabillity, when using negative numbers for
 * timeoutInterval.
 *
 * @see timeoutInterval
 */
extern const NSTimeInterval TTURLRequestUseQueueTimeout;

typedef NS_ENUM(NSInteger, TBKNetworkRequestSerializerType) {
    TBKNetworkRequestSerializerTypeHTTP,
    TBKNetworkRequestSerializerTypeJSON,
    TBKNetworkRequestSerializerTypePlist
};

typedef NS_ENUM(NSInteger, TBKNetworkResponseSerializerType) {
    TBKNetworkResponseSerializerTypeData,
    TBKNetworkResponseSerializerTypeJSON,
    TBKNetworkResponseSerializerTypeXML,
    TBKNetworkResponseSerializerTypeXMLDocument,
    TBKNetworkResponseSerializerTypePlist,
    TBKNetworkResponseSerializerTypeImage,
    TBKNetworkResponseSerializerTypeCompound,
};

//@protocol TBKURLRequest; // 这样声明的协议写在 @interface 后有警告
//@protocol TBKURLRequestCompletionDelegate;
//@protocol TBKURLRequestDelegate; // Interceptor
//@protocol TBKNetworkDataReformer; // model 格式化协议
//@protocol TBKNetworkValidator; // 请求/响应的验证协议

@protocol TBKURLResponse; // from 320, 和 TBKNetworkDataReformer 的概念类似, 未使用

@protocol TBKURLRequest <NSObject>

- (NSString *_Nonnull)httpMethod;
- (NSString *_Nonnull)urlBase;
- (NSString *_Nonnull)urlPath;
- (NSString *_Nonnull)urlString;
- (NSMutableDictionary *)parameters; // 接口参数, 只有接口级请求提供, 根据httpMehtod类型决定放入url/body
- (NSMutableDictionary *)urlParameters;
- (NSMutableDictionary *)bodyParameters;

- (NSMutableDictionary *)headers;
- (NSMutableDictionary *)genenalHeaders; // 通用 headers

// afn在创建NSURLRequest时可设置的属性
// allowsCellularAccess
- (TTURLRequestCachePolicy)cachePolicy;
- (BOOL)shouldHandleCookies;
// HTTPShouldUsePipelining
// networkServiceType
- (NSTimeInterval)timeoutInterval;


- (NSString *_Nonnull)contentType;
- (NSDictionary *_Nullable)reformParameters:(NSDictionary *_Nullable)parameters;

- (void)cleanData;

@end

@interface TBKURLRequest : NSObject <TBKURLRequest>

@property (nonatomic, copy) NSString *urlBase;

/**
 * The URL path to be loaded by the request.
 */
@property (nonatomic, copy) NSString* urlPath;

@property (nonatomic, copy) NSString *urlString; // base + path

/**
 * The HTTP method to send with the request.
 *
 * @example @"POST"
 * @example @"GET"
 * @example @"PUT"
 * @default nil (equivalent to @"GET")
 */
@property (nonatomic, copy) NSString* httpMethod;

/**
 * The HTTP body to send with the request.
 *
 * If provided, will always be used. Please consider this when using POST/PUT methods: if
 * httpBody is provided, then the POST/PUT data generated from the parameters property will not
 * be used.
 */
@property (nonatomic, copy) NSData* httpBody;

@property (nonatomic, readonly) NSMutableDictionary* parameters;

/**
 * Custom HTTP headers.
 */
@property (nonatomic, readonly) NSMutableDictionary* headers;

/**
 * The content type of the data in the request.
 *
 * If not provided and httpMethod is POST/PUT, then contentType is @"multipart/form-data".
 */
@property (nonatomic, copy) NSString* contentType;

/**
 * Charset to use when creating multipart/form-data data.
 *
 * @default NSUTF8StringEncoding to remain backwards compatible.
 */
@property (nonatomic) NSStringEncoding charsetForMultipart;

@property (nonatomic, strong) NSMutableArray *files;

/**
 * An object that handles the response data and may parse and validate it.
 *
 * @see TTURLDataResponse
 * @see TTURLImageResponse
 * @see TTURLXMLResponse
 */
@property (nonatomic, strong) TBKURLResponse *response;

/**
 * @default TTURLRequestCachePolicyDefault
 */
@property (nonatomic) TTURLRequestCachePolicy cachePolicy;

/**
 * The maximum age of cached data that can be used as a response.
 *
 * @default TBK_DEFAULT_CACHE_EXPIRATION_AGE (1 week)
 */
@property (nonatomic) NSTimeInterval cacheExpirationAge;

/**
 * If no cache key is provided, a unique key is generated from the request data. If the request
 * is a POST/PUT request, then the POST/PUT parameters are also used to generate the cache key.
 *
 * By setting the cacheKey, you may override the default cache key generator with your own.
 */
@property (nonatomic, copy) NSString* cacheKey;

/// 请求发送时间
@property (nonatomic, strong) NSDate* timestamp; // TODO: 确定缓存怎么算? loader的相同请求怎么算?

/**
 * The number of request body bytes already uploaded by this request.
 */
@property (nonatomic) NSInteger totalBytesLoaded;

/**
 * The total number of request body bytes expected to be uploaded for this request.
 */
@property (nonatomic) NSInteger totalBytesExpected;

/**
 * The timeout to use for the request.
 *
 * If a negative value is set the request uses
 * the defaultTimeout of the TBKURLRequestQueue. <b>This differs from behaviour of
 * NSURLRequest.</b> Given a negative timeoutInterval NSURLRequest always fails.
 *
 * You should use the TTURLRequestUseQueueTimeout constant to improve
 * code readabillity, instead of negative numbers.
 *
 * The default value is TTURLRequestUseQueueTimeout
 *
 * @par from NSURLRequest.h:
 *
 * The timeout interval specifies the limit on the idle
 * interval alloted to a request in the process of loading. The "idle
 * interval" is defined as the period of time that has passed since the
 * last instance of load activity occurred for a request that is in the
 * process of loading. Hence, when an instance of load activity occurs
 * (e.g. bytes are received from the network for a request), the idle
 * interval for a request is reset to 0. If the idle interval ever
 * becomes greater than or equal to the timeout interval, the request
 * is considered to have timed out. This timeout interval is measured
 * in seconds.
 *
 * @see TBKURLRequestQueue::defaultTimeout
 */
@property (nonatomic) NSTimeInterval timeoutInterval;

/**
 * The number of downloaded bytes from server.
 */
@property (nonatomic) NSInteger totalBytesDownloaded;

/**
 *  The number of content length of request.
 */
@property (nonatomic) NSInteger totalContentLength;

/**
 * A dummy object used to uniquely identify this request object once it's been sent into the fray.
 * Generally TTUserInfo objects are used here.
 *
 * @see TTUserInfo
 */
@property (nonatomic, strong) id userInfo;

/**
 * Whether or not the request is currently active.
 */
@property (nonatomic) BOOL isLoading;

/**
 * Decide whether default cookie handling will happen for this request.
 *
 *  YES if cookies should be sent with and set for this request;
 *        otherwise NO.
 * @discussion The default is YES - in other words, cookies are sent from and
 *             stored to the cookie manager by default.
 *
 * @default YES
 */
@property (nonatomic) BOOL shouldHandleCookies;

/**
 * Whether or not the request was loaded from the cache.
 *
 * This is only valid after the request has completed.
 */
@property (nonatomic) BOOL respondedFromCache;

/**
 * Whether parameters named "password" should be suppressed in log messages.
 */
@property (nonatomic, assign) BOOL filterPasswordLogging;

/**
 * Determine whether to construct a multipart form or to instead encode the http body as the W3C default
 * of application/x-www-form-urlencoded
 */
@property (nonatomic, assign) BOOL multiPartForm;

@property (nonatomic, strong, nullable) void (^successCompletionBlock)(TBKURLRequest *request);
@property (nonatomic, strong, nullable) void (^failureCompletionBlock)(TBKURLRequest *request);

@property (nonatomic, weak) id<TBKURLRequestCompletionDelegate> completionDelegate;

/**
 * An array of non-retained objects that receive messages about the progress of the request.
 */
@property (weak, nonatomic, readonly) NSMutableArray<id<TBKURLRequestDelegate>> *requestDelegates; // CTNetworking 叫 interceptor, YTK 叫 RequestAccessory

//@property (nonatomic, weak) id<TBKNetworkDataReformer> dataReformer;
//@property (nonatomic, weak) id<TBKNetworkValidator> validator;
// reformer 提供的方法
//- (id _Nullable )fetchDataWithReformer:(id<TBAPIManagerDataReformer> _Nullable)reformer;

@property (nonatomic, assign) BOOL encodingParametersInURL;

#pragma mark - Methods
+ (instancetype)request;

+ (instancetype)requestWithURL:(NSString*)URL delegate:(id<TBKURLRequestCompletionDelegate>)delegate;

- (instancetype)initWithURL:(NSString*)URL delegate:(id<TBKURLRequestCompletionDelegate>)delegate;

- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

/**
 * Add a file whose data will be posted.
 */
//- (void)addFile:(NSData*)data mimeType:(NSString*)mimeType fileName:(NSString*)fileName;

/**
 * Attempt to send a request.
 *
 * If the request can be resolved by the cache, it will happen synchronously.  Otherwise,
 * the request will respond to its delegate asynchronously.
 *
 * @return YES if the request was loaded synchronously from the cache.
 */
- (BOOL)send;

// TODO: 业务对象只想要responseObject
- (BOOL)sendWithSuccess:(nullable void (^)(TBKURLRequest *request))success failure:(nullable void (^)(TBKURLRequest *request))failure;

- (BOOL)sendWithParameters:(id)parameters success:(nullable void (^)(TBKURLRequest *request))success failure:(nullable void (^)(TBKURLRequest *request))failure;

//
- (BOOL)send:(NSString *)URLString httpMethod:(NSString *)httpMethod parameters:(id)parameters header:(NSDictionary *)headers progress:(nullable void (^)(NSProgress *progress))progress success:(nullable void (^)(TBKURLRequest *request))success failure:(nullable void (^)(TBKURLRequest *request))failure;
//

/**
 * Cancel the request.
 *
 * If there are multiple requests going to the same URL as this request, the others will
 * not be cancelled.
 */
- (void)cancel;

- (NSURLRequest*)createNSURLRequest;

- (BOOL)sendPriority; // 最高优先级执行

#pragma mark - 考虑添加
@property (nonatomic, assign) NSInteger level; // 请求级别: app 级, service 级, api 级. TODO: 改为枚举类型
@property (nonatomic, copy) NSString *version; // 接口版本
@property (nonatomic, copy) NSString *format; // base + version + path 的格式, 默认 {base}/{version}/{path}
@property (nonatomic, copy) NSString *modelClassName; // 模型类的名称

@property (nonatomic, assign) TBKNetworkRequestSerializerType requestSerializerType; // request serializer 的枚举类型
@property (nonatomic, assign) TBKNetworkResponseSerializerType responseSerializerType; // response serializer 的枚举类型

#pragma mark - from CTNeworking
@property (nonatomic, assign) BOOL ignoreCache; // 默认 NO

@property (nonatomic, readonly) TBKNetworkErrorType errorType;
@property (nonatomic, copy, readonly) NSString * _Nullable errorMessage;
#pragma mark - from YTKNetwork

// TODO: 以上时 TTURLRequest 的属性和方法
// 还可以考虑加入以下属性和方法

//@property (nonatomic, strong) NSURLRequest *request;
@property (nonatomic, strong) NSURLSession *session;




///  Nil out both success and failure callback blocks.
- (void)clearCompletionBlock;

///  Convenience method to add request accessory. See also `requestAccessories`.
- (void)addRequestDelegate:(id<TBKURLRequestDelegate>)requestDelegate;

@end

// TODO: 一组内部的interceptor方法 未使用
@interface TBKURLRequest (InnerInterceptor)

- (BOOL)willFinishLoadResponse:(TBKURLResponse *)response;
- (void)didFinishLoadResponse:(TBKURLResponse *)response;

- (BOOL)willFailLoadResponse:(TBKURLResponse *)response withError:(NSError *)error;
- (void)didFailLoadResponse:(TBKURLResponse *)response withError:(NSError *)error;

//- (BOOL)shouldCallAPIWithParams:(NSDictionary *_Nullable)params;
//- (void)afterCallingAPIWithParams:(NSDictionary *_Nullable)params;
//
@end

NS_ASSUME_NONNULL_END
