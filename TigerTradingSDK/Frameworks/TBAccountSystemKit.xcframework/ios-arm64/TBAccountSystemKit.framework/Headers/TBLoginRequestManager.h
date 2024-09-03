//
//  TBLoginRequestManager.h
//  Stock
//
//  Created by 马超 on 2017/6/2.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBLoginApiModel.h"
#import <TBAccountSystemKit/TBLoginType.h>
#import "TBLoginRequestManager.h"
#import <TBBaseKit/TBBaseUtility.h>

@interface TBLoginRequestManager : NSObject

DECLARE_SHARED_INSTANCE(TBLoginRequestManager);

- (void)guestLoginIsAuto:(BOOL)isAuto
                 success:(void (^)(id responseObject))success
                 failure:(void (^)(NSError *error))failure;

// 登录成功后统一做的事情
- (void)handleLoginOrRegisterSuccessFinishWithData:(NSDictionary *)data
                                          loginType:(TBLoginType)loginType
                                        oldUserName:(NSString *)oldUserName
                                        newUserName:(NSString *)newUserName
                                           teleCode:(NSString *)teleCode;

/*
 海外包由于存在国内用户，需要根据用户账号判断使用哪个auth域名
*/
- (void)checkAuthRouteWithParameters:(id)parameters
                          completion:(void(^)(void))completion;

// 用户通过手机号+验证码，直接登录注册的新接口方式
- (void)phoneVerifyCodeLoginWithParameters:(NSString *)parameters
                                 loginType:(TBLoginType)loginType
                                 errorInfo:(void(^)(NSDictionary *errorInfo))errorInfo
                       needDynamicPassword:(void(^)(NSString * password))dynamicPsw
                                   success:(void(^)(id responseObject))success
                                   failure:(void(^)(NSError *error))failure;

// 手机号或邮箱登录
- (void)normalLoginWithParameters:(NSDictionary *)parameters
                        loginType:(TBLoginType)loginType
                isAddLoginAccount:(BOOL)isAddLoginAccount
                        errorInfo:(void(^)(NSDictionary *errorInfo))errorInfo
              needDynamicPassword:(void(^)(NSString * password))dynamicPsw
                          success:(void(^)(id responseObject))success
                          failure:(void(^)(NSError *error))failure;

//快捷登录
- (void)quickLoginWithParameters:(NSString *)parameters
                       errorInfo:(void(^)(NSDictionary *errorInfo))errorInfo
             needDynamicPassword:(void(^)(NSString * password))dynamicPsw
                         success:(void(^)(id responseObject))success
                         failure:(void(^)(NSError *error))failure;

// 三方登录后(无手机/邮箱的User), 绑定一个 Phone/Email, 若已注册, 提示用户该操作后仅保留手机号的数据，若未注册，则注册一个新用户
- (void)snsUserBindPhoneOrEmailWithParameters:(NSString *)parameters
                                     username:(NSString *)username
                                    errorInfo:(void(^)(NSDictionary *errorInfo))errorInfo
                          needDynamicPassword:(void(^)(NSString * password))dynamicPsw
                                      success:(void(^)(id responseObject))success
                                      failure:(void(^)(NSError *error))failure;

// 三方登录 wechat|weibo|facebook|twitter
- (void)snsLoginWithType:(TBLoginType)loginType
              parameters:(id)parameters
               errorInfo:(void (^)(NSDictionary *))errorInfo
     needDynamicPassword:(void(^)(NSString * password))dynamicPsw
                 success:(void (^)(id))success
                 failure:(void (^)(NSError *))failure;


- (void)brokerClientSignIn:(NSString *)clientId accessToken:(NSString *)accessToken idToken:(NSString *)idToken autorizationCode:(NSString *)autorizationCode state:(NSString *)state success:(void (^)(id))success
                   failure:(void (^)(NSError *))failure;

// IPification一键登录
- (void)oneclickSigninIPificationWithParameters:(NSDictionary *)parameters
                                      errorInfo:(void (^)(NSDictionary *errorInfo))errorInfo
                            needDynamicPassword:(void(^)(NSString * password))dynamicPsw
                                        success:(void (^)(id responseObject))success
                                        failure:(void (^)(NSError *error))failure;

// 手机或邮箱注册
- (void)signUpWithParameters:(NSDictionary *)parameters
                   loginType:(TBLoginType)loginType
                   errorInfo:(void(^)(NSDictionary *errorInfo))errorInfo
                     success:(void(^)(id responseObject))success
                     failure:(void(^)(NSError *error))failure;

// 退出登录
- (void)singoutWithSuccess:(void(^)(NSDictionary *responseDict))success
                   failure:(void(^)(NSString *errorMsg))failure;

/**
 发送邮箱验证码

 @param paramters dict
    email 需要发送的邮箱
    process 新设备登录为:new_signin 快捷登录为:fast_login
    code 图形验证码，可不传；或 validate_code 同盾验证码，black_box 同盾设备指纹
 @param success 成功回调
 @param failure 失败回调
 */
- (void)sendEmailVerifyCodeWithParameters:(NSDictionary *)parameters
                                  success:(void(^)(TBLoginApiModel *responseModel, NSString *successMsg))success
                                  failure:(void(^_Nullable)(NSString *errorMsg, NSString * _Nullable errorCode))failure;

/**
 校验密码的安全性
 @param password 密码
 @param verifyToken 验证token，可为空
 @param success 成功回调
 @param failure 失败回调
 */
- (void)checkPassword:(NSString *)password
          verifyToken:(NSString *)verifyToken
              success:(void(^)(NSDictionary *responseDict))success
              failure:(void(^)(NSString *errorMsg))failure;
                       
@end
