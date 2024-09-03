//
//  TBVerifyRequestManager.h
//  StockGlobal
//
//  Created by chenxin on 2018/12/27.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBVerifyDefines.h"
#import "TBVerifyRequestManager.h"
#import <TBBaseKit/TBBaseUtility.h>

@interface TBVerifyRequestManager : NSObject

DECLARE_SHARED_INSTANCE(TBVerifyRequestManager)

- (NSString *)processWithType:(TBVerifyProcessType)type;

// 验证登录密码或交易密码
- (void)verifyPassword:(NSString *)password
           processType:(TBVerifyProcessType)processType
               success:(void(^)(NSString *verifyToken))success
               failure:(void(^)(NSString *errorMsg))failure;

// 获取验证方式
- (void)fetchVerifyOptionsWithSuccess:(void(^)(NSDictionary *options))success
                              failure:(void(^)(NSString *errorMsg))failure;

// 发送手机号或邮箱验证码, 传processType
- (void)sendVerifyCodeWithMethodType:(TBVerifyMethodType)methodType
                         processType:(TBVerifyProcessType)processType
                             captcha:(id)captcha
                            username:(NSString *)username
                             isVoice:(BOOL)isVoice
                             telCode:(NSString *)telCode
                             success:(void(^)(void))success
                             failure:(void(^)(NSString *errorMsg))failure;

// 发送手机号或邮箱验证码, 直接传process
- (void)sendVerifyCodeWithMethodType:(TBVerifyMethodType)methodType
                             process:(NSString *)process
                             captcha:(id)captcha
                            username:(NSString *)username
                             isVoice:(BOOL)isVoice
                             telCode:(NSString *)telCode
                             success:(void(^)(id responseObject))success
                             failure:(void(^)(NSError *error))failure;

// 验证短信验证码/邮箱验证码/动态验证码
- (void)verifyCode:(NSString *)code
        methodType:(TBVerifyMethodType)methodType
       processType:(TBVerifyProcessType)processType
           success:(void(^)(NSString *verifyToken))success
           failure:(void(^)(NSString *errorMsg))failure;

// 验证手机号（非登录手机号的场景需要传phone和tel_code）
- (void)verifyPhone:(NSString *)phone
            telCode:(NSString *)telCode
         verifyCode:(NSString *)verifyCode
        processType:(TBVerifyProcessType)processType
            success:(void(^)(NSString *verifyToken))success
            failure:(void(^)(NSString *errorMsg))failure;

@end
