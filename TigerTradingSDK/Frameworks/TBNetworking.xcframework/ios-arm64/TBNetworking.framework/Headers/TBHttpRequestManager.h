//
//  TBHttpRequestManager.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <AFNetworking/AFHTTPSessionManager.h>

#define TIGERBROKERS_HTTP_SERVER_TIMEOUT                    10.0
#define TIGERBROKERS_HTTP_IMAGE_TIMEOUT                     60.0

// 网络连通性通知
extern NSString * const kTBNetworkingReachabilityDidChangeNotification;

@protocol TBHttpRequestManagerDelegate;

@interface TBHttpRequestManager : AFHTTPSessionManager

+ (TBHttpRequestManager *)sharedInstance;

@property (nonatomic, weak) id<TBHttpRequestManagerDelegate> delegate;

@property (nonatomic, assign) BOOL enableConsoleLog;

// 是否开启加密，默认为NO（目前只有部分接口支持）
@property (nonatomic, assign) BOOL tigerEncryptionEnabled;

@property (readonly, nonatomic, assign, getter = isReachable) BOOL reachable;

// 默认携带了accessToken
- (NSURLSessionTask *) GET:(NSString *)URLString
                      parameters:(id)parameters
                         headers:(id)headers
                         inQueue:(NSOperationQueue *)inQueue
                         success:(void(^)(id responseObject))success
                         failure:(void(^)(NSError *error))failure;

/**
 期货接口请求
 */
- (NSURLSessionTask *) FT_GET:(NSString *)URLString
     parameters:(id)parameters
        headers:(id)headers
        inQueue:(NSOperationQueue *)inQueue
        success:(void(^)(id responseObject))success
        failure:(void(^)(NSError *error))failure;

// 用于不需要传accesToken 的场景.
- (NSURLSessionTask *) GET_NO_AUTHORIZATION:(NSString *)URLString
                      parameters:(id)parameters
                         headers:(id)headers
                         inQueue:(NSOperationQueue *)inQueue
                         success:(void(^)(id responseObject))success
                         failure:(void(^)(NSError *error))failure;



// post 携带了accessToken
- (NSURLSessionTask *) POST:(NSString *)URLString
                       parameters:(id)parameters
                          headers:(id)headers
                          inQueue:(NSOperationQueue *)inQueue
                          success:(void(^)(id responseObject))success
                          failure:(void(^)(NSError *error))failure;

// post 携带了accessToken，timeout 支持自定义请求超时，目前用于上传用户日志
- (NSURLSessionTask *) POST:(NSString *)URLString
                    timeout:(NSTimeInterval)timeoutInterval
                 parameters:(id)parameters
                    headers:(id)headers
                    inQueue:(NSOperationQueue *)inQueue
                    success:(void(^)(id responseObject))success
                    failure:(void(^)(NSError *error))failure;

- (NSURLSessionTask *)dataTask:(NSString *)URLString
                        method:(NSString *)method
                   contentType:(NSString *)contentType
                    parameters:(id)parameters
                       headers:(id)headers
                       inQueue:(NSOperationQueue *)inQueue
                       success:(void(^)(id responseObject))success
                       failure:(void(^)(NSError *error))failure;

// form表单形式POST
- (NSURLSessionTask *)FORM_POST:(NSString *)URLString
       parameters:(id)parameters
          headers:(id)headers
          inQueue:(NSOperationQueue *)inQueue
          success:(void(^)(id responseObject))success
          failure:(void(^)(NSError *error))failure;

// form 表单形式 携带了accessToken
- (NSURLSessionTask *) POSTBODY:(NSString *)URLString
                           parameters:(id)parameters
                              headers:(id)headers
                              inQueue:(NSOperationQueue *)inQueue
                              success:(void (^)(id responseObject))success
                              failure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *) POSTBODY_NO_AUTHORIZATION:(NSString *)URLString
                                            parameters:(id)parameters
                                               headers:(id)headers
                                               inQueue:(NSOperationQueue *)inQueue
                                               success:(void (^)(id responseObject)) success
                                               failure:(void (^)(NSError *error))failure;

// DELETE
- (NSURLSessionTask *)DELETEFORM:(NSString *)URLString
                            parameters:(id)parameters
                               success:(void (^)(id responseObject))success
                               failure:(void (^)(NSError * error))failure;

// DELETE， 不带header
- (NSURLSessionTask *)DELETE:(NSString *)URLString
                  parameters:(id)parameters
                     success:(void (^)(id responseObject))success
                     failure:(void (^)(NSError * error))failure;

- (NSURLSessionTask *)DELETE:(NSString *)URLString
                  parameters:(id)parameters
                     headers:(NSDictionary *)headers
                     success:(void (^)(id responseObject))success
                     failure:(void (^)(NSError * error))failure;



// PUT
/*
 当parameters是NSString类型时，Content-Type类型是x-www-form-urlencoded
 当parameters是NSDictionry类型时，Content-Type类型是json
 */
- (NSURLSessionTask *)PUT:(NSString *)URLString
                     parameters:(id)parameters
                        headers:(id)headers
                        success:(void (^)(id responseObject)) success
                        failure:(void (^)(NSError * error)) failure;

// PUT JSON 且存在parameters , 上个put方法中，不支持content type json， 且param 为nil
// 上个方法已经做了兼容，这个方法保留以免影响使用到的业务逻辑
- (NSURLSessionTask *)PUT:(NSString *)URLString
               parameters:(NSDictionary *)parameters
                  success:(void (^)(id responseObject)) success
                  failure:(void (^)(NSError * error)) failure;


- (NSURLSessionTask *)POSTForms:(NSString *)URLString
                           parameters:(id)parameters
                              headers:(NSDictionary *)headers
            constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                              success:(void (^)(id responseObject))success
                              failure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *)POSTFormsWithProgress:(NSString *)URLString
                     parameters:(id)parameters
                        headers:(NSDictionary *)headers
      constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                 uploadProgress:(void (^)(NSProgress *uploadProgress)) uploadProgressBlock
               downloadProgress:(void (^)(NSProgress *downloadProgress)) downloadProgressBlock
                        success:(void (^)(id responseObject))success
                        failure:(void (^)(NSError *error))failure;

//下载文件 savePath:保存路径
- (NSURLSessionTask *)downloadFileWithURL:(NSString *)URL
                   savePath:(NSString *)savePath
            downloadSuccess:(void (^)(void))success
            downloadFailure:(void (^)(NSError *error))failure;

- (NSURLSessionTask *)downloadImageWithURL:(NSString*)URL savePath:(NSString*)savePath downloadSuccess:(void (^)(void))success downloadFailure:(void (^)(NSError *error))failure;

- (void)recordLastServerDate:(NSDictionary *)responseObject;

- (NSURLSessionTask *)startDataTaskWithRequest:(NSURLRequest *)request
                                       inQueue:(NSOperationQueue *)inQueue
                             completionHandler:(void (^)(NSURLResponse *response, id responseObject,  NSError * error))completionHandler;

/**
 为请求的URL添加基本参数

 @param urlString 原始URL
 @return 添加基本参数后缀的URL
 */
- (NSString *)URLStringByAddingGeneralParameters:(NSString *)urlString parameters:(NSDictionary *)parameters;

/**
 通用参数
 已默认设置：platform，channel，vendor，device，screenW，screenH，osVer
 需要使用方设置：deviceId，appVer，keyfrom，appName，lang等
 */
+ (NSDictionary*)getGeneralParameters;

// 更新指定通用参数的值
- (void)updateGeneralParameterValue:(NSString *)value forKey:(NSString *)key;
- (void)updateGeneralParametersWithDict:(NSDictionary *)dict;

#pragma mark - Trade

// trade post 携带了tradeToken
- (NSURLSessionTask *)TRADE_POST:(NSString *)URLString
   parameters:(id)parameters
      inQueue:(NSOperationQueue *)inQueue
      success:(void(^)(id responseObject))success
      failure:(void(^)(NSError *error))failure;

- (NSURLSessionTask *)TRADE_POST:(NSString *)URLString
                      parameters:(id)parameters
                         timeout:(NSTimeInterval)timeout
                         inQueue:(NSOperationQueue *)inQueue
                         success:(void(^)(id responseObject))success
                         failure:(void(^)(NSError *error))failure;

// trade post 携带了tradeToken，form表单形式
- (NSURLSessionTask *)TRADE_FORM_POST:(NSString *)URLString
        parameters:(id)parameters
           inQueue:(NSOperationQueue *)inQueue
           success:(void(^)(id responseObject))success
           failure:(void(^)(NSError *error))failure;

// trade put 携带了tradeToken
- (NSURLSessionTask *)TRADE_PUT:(NSString *)URLString
                     parameters:(id)parameters
                        success:(void (^)(id responseObject)) success
                        failure:(void (^)(NSError * error)) failure;

#pragma mark - 期货的网络接口请求方式

// 期货GET请求
- (NSURLSessionTask *)FT_GET:(NSString *)URLString
                  parameters:(id)parameters
                     headers:(id)headers
                     inQueue:(NSOperationQueue *)queue
                    response:(void (^)(NSURLResponse *URLResponse, id responseObject, NSError *error))response;
// 期货POST请求
- (NSURLSessionTask *)FT_POST:(NSString *)URLString
                   parameters:(id)parameters
                      headers:(id)headers
                      inQueue:(NSOperationQueue *)inQueue
                     response:(void (^)(NSURLResponse *URLResponse, id responseObject, NSError *error))response;


@end

@protocol TBHttpRequestManagerDelegate <NSObject>

// 获取accessToken
- (NSString *)getAccessToken;

@optional

// 获取交易token
- (NSString *)getTradeToken;

// 通过请求接口检查网络是否实际可达
- (void)checkRealReachabilityWithCompletion:(void (^)(BOOL isReachable))completion;

// 响应根据需要进行安全验证
- (void)securityInterceptResponse:(NSHTTPURLResponse *)response;

// 请求根据需要添加安全验证token
- (NSString *)securityInterceptRequest:(NSString *)requestString;

// 记录服务端时间
- (void)recordServerTime:(NSNumber *)serverTime;

// 请求失败处理（特定域名相关请求符合一定条件会切换服务器）
- (void)handleRequestURL:(NSURL *)URL error:(NSError *)error;

// 请求成功处理逻辑，用于某些需要对 responseObject 做统一处理的场景
- (void)handleRequestURL:(NSURL *)URL responseObject:(id)responseObject;

// 某些接口需要替换部分通用参数的值，比如oauth接口要求TigerTradeHD的platform传iPadOS
- (NSDictionary *)replacedGeneralParametersWithURLString:(NSString *)urlString parameters:(NSDictionary *)parameters;

// 对部分请求进行加密处理
- (NSURLRequest *)encryptedRequestWithRequest:(NSURLRequest *)request;

// 对部分加密的响应数据进行解密处理
- (id)decryptedResponseObjectWithResponseObject:(id)responseObject;

@end
