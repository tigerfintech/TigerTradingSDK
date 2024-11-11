//
//  AXService.h
//  RTNetworking
//
//  Created by casa on 14-5-15.
//  Copyright (c) 2014年 casatwy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBKURLResponse.h"
#import "TBKNetworkGlobal.h"
#import "TTErrorCodes.h"

// 所有CTService的派生类都要符合这个protocol
@protocol CTServiceProtocol <NSObject>

@property (nonatomic, readonly) BOOL isOnline;
// 新版替换成了枚举类型, 其实没什么用, 只要区分测试和线上即可, 即使有, 也只需要两个类型
@property (nonatomic, assign, readonly) TBKNetworkEnvironmentType apiEnvironment;

// 旧版属性和方法
@property (nonatomic, readonly) NSString *offlineApiBaseUrl;
@property (nonatomic, readonly) NSString *onlineApiBaseUrl;

@property (nonatomic, readonly) NSString *offlineApiVersion;
@property (nonatomic, readonly) NSString *onlineApiVersion;

@property (nonatomic, readonly) NSString *onlinePublicKey;
@property (nonatomic, readonly) NSString *offlinePublicKey;

@property (nonatomic, readonly) NSString *onlinePrivateKey;
@property (nonatomic, readonly) NSString *offlinePrivateKey;

@optional

//为某些Service需要拼凑额外字段到URL处
- (NSDictionary *)extraParmas;

//为某些Service需要拼凑额外的HTTPToken，如accessToken
- (NSDictionary *)extraHttpHeadParmasWithMethodName:(NSString *)method;

- (NSString *)urlGeneratingRuleByMethodName:(NSString *)method;

//- (void)successedOnCallingAPI:(TBKURLResponse *)response;

//提供拦截器集中处理Service错误问题，比如token失效要抛通知等
- (BOOL)shouldCallBackByFailedOnCallingAPI:(TBKURLResponse *)response;

// 新版方法, 提供model
// 由于原作者的理念是去model化, 所以这里返回字典
// 可以提供一个返回model类型(Mantle)或字典类型的属性, 表示这个请求的响应数据?
- (NSDictionary *)resultWithResponseData:(NSData *)responseData
                                response:(NSURLResponse *)response
                                 request:(NSURLRequest *)request
                                   error:(NSError **)error;

/*
 return true means should continue the error handling process in CTAPIBaseManager
 return false means stop the error handling process
 
 如果检查错误之后，需要继续走fail路径上报到业务层的，return YES。（例如网络错误等，需要业务层弹框）
 如果检查错误之后，不需要继续走fail路径上报到业务层的，return NO。（例如用户token失效，此时挂起API，调用刷新token的API，成功之后再重新调用原来的API。那么这种情况就不需要继续走fail路径上报到业务。）
 */
// TODO: APIManager 的 failedOnCallingAPI 时候调用
- (BOOL)handleCommonErrorWithResponse:(TBKURLResponse *)response
                              manager:(TBKURLRequest *)manager
                            errorType:(TBKNetworkErrorType)errorType;

@end

@interface CTService : NSObject <CTServiceProtocol>

@property (nonatomic, copy, readonly) NSString *publicKey;
@property (nonatomic, copy, readonly) NSString *privateKey;
@property (nonatomic, copy, readonly) NSString *apiBaseUrl;
@property (nonatomic, copy, readonly) NSString *apiVersion;

/* 
 * 因为考虑到每家公司的拼凑逻辑都有或多或少不同，
 * 如有的公司为http://abc.com/v2/api/login或者http://v2.abc.com/api/login
 * 所以将默认的方式，有versioin时，则为http://abc.com/v2/api/login
 * 否则，则为http://abc.com/v2/api/login
*/
- (NSString *)urlGeneratingRuleByMethodName:(NSString *)method;


@end
