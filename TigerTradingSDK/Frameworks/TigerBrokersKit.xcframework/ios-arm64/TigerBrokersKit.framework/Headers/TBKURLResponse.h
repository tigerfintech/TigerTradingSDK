//
//  TBKURLResponse.h
//  TigerBrokersKit
//
//  Created by donggf on 2018/8/23.
//

#import <Foundation/Foundation.h>

#import <Mantle/MTLModel.h>

NS_ASSUME_NONNULL_BEGIN

// from TTURLResponse
@class TBKURLRequest;

/**
 * A response protocol for TBKURLRequest. This protocol is used upon the successful retrieval of
 * data from a TBKURLRequest. The processResponse method is used to process the data, whether it
 * be an image or an XML string.
 *
 * @see TTURLDataResponse
 * @see TTURLImageResponse
 */
@protocol TBKURLResponse <NSObject>
@required

/**
 * Processes the data from a successful request and determines if it is valid.
 *
 * If the data is not valid, return an error. The data will not be cached if there is an error.
 *
 * @param  request    The request this response is bound to.
 * @param  response   The response object, useful for getting the status code.
 * @param  data       The data received from the TBKURLRequest.
 * @return NSError if there was an error parsing the data. nil otherwise.
 *
 * @required
 */
- (NSError*)request:(TBKURLRequest *)request processResponse:(NSHTTPURLResponse *)response
               data:(id)data;

@optional
/**
 * Processes the data from a unsuccessful request to construct a custom NSError object.
 *
 * @param  request    The request this response is bound to.
 * @param  response   The response object, useful for getting the status code.
 * @param  data       The data received from the TBKURLRequest.
 * @return NSError to construct for this response.
 *
 * @optional
 */
- (NSError*)request:(TBKURLRequest *)request processErrorResponse:(NSHTTPURLResponse *)response data:(id)data;
@end

// TODO: 确定是否不使用, 需要删除
typedef NS_ENUM(NSUInteger, TBKURLResponseStatus)
{
    TBKURLResponseStatusSuccess, //作为底层，请求是否成功只考虑是否成功收到服务器反馈。至于签名是否正确，返回的数据是否完整，由上层的CTAPIBaseManager来决定。
    TBKURLResponseStatusErrorTimeout,
    TBKURLResponseStatusErrorCancel,
    TBKURLResponseStatusErrorNoNetwork // 默认除了超时以外的错误都是无网络错误。
};

@interface TBKURLResponse : NSObject

@property (nonatomic, strong) NSDate *timestamp; // 接收到响应的时间

// FIXME: from CTNetwork，确定是否删除
@property (nonatomic, assign, readonly) TBKURLResponseStatus status;
//

@property (nonatomic, assign, readonly) NSInteger requestId;
@property (nonatomic, copy, readonly) NSURLRequest *request;

// TODO: 确定参数保留哪个属性?
@property (nonatomic, copy) NSDictionary *requestParams;
@property (nonatomic, copy) NSDictionary *acturlRequestParams;
@property (nonatomic, copy) NSDictionary *originRequestParams;
//

@property (nonatomic, copy) NSString *logString;

@property (nonatomic, assign, readonly) BOOL isFromCache;


// from YTKNetwork
// 没有保存这个, 如果需要再加回来, 从afn请求的返回值获取
/////  The underlying NSURLSessionTask.
/////
/////  @warning This value is actually nil and should not be accessed before the request starts.
//@property (nonatomic, strong, readonly) NSURLSessionTask *requestTask;
//
/////  Shortcut for `requestTask.currentRequest`.
//@property (nonatomic, strong, readonly) NSURLRequest *currentRequest;
//
/////  Shortcut for `requestTask.originalRequest`.
//@property (nonatomic, strong, readonly) NSURLRequest *originalRequest;
//

///  Shortcut for `requestTask.response`.
@property (nonatomic, strong, readonly) NSHTTPURLResponse *httpResponse;

///  The response status code.
@property (nonatomic, readonly) NSInteger responseStatusCode;

///  The response header fields.
@property (nonatomic, copy, readonly, nullable) NSDictionary *responseHeaders;

///  The raw data representation of response. Note this value can be nil if request failed.
@property (nonatomic, copy, readonly, nullable) NSData *responseData;

///  The string representation of response. Note this value can be nil if request failed.
@property (nonatomic, copy, readonly, nullable) NSString *responseString;

///  This serialized response object. The actual type of this object is determined by
///  `YTKResponseSerializerType`. Note this value can be nil if request failed.
///
///  @discussion If `resumableDownloadPath` and DownloadTask is using, this value will
///              be the path to which file is successfully saved (NSURL), or nil if request failed.
@property (nonatomic, strong, /*readonly,*/ nullable) id responseObject;

@property (nonatomic, strong) MTLModel *responseModel;

///  This error can be either serialization error or network error. If nothing wrong happens
///  this value will be nil.
@property (nonatomic, strong, /*readonly,*/ nullable) NSError *error;

#pragma mark - from YTKNetwork
///  Return cancelled state of request task.
@property (nonatomic, readonly, getter=isCancelled) BOOL cancelled; // 未使用

///  Executing state of request task.
@property (nonatomic, readonly, getter=isExecuting) BOOL executing; // 未使用
#pragma mark -

- (instancetype)initWithResponse:(NSHTTPURLResponse*)response data:(id)data error:(NSError *)error;


// 使用initWithData的response，它的isCache是YES，上面两个函数生成的response的isCache是NO
- (instancetype)initWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
