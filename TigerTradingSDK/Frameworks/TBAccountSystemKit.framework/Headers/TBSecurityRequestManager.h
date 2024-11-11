//
//  TBSecurityRequestManager.h
//  StockGlobal
//
//  Created by chenxin on 2018/12/29.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBVerifyDefines.h"
#import "TBSecurityRequestManager.h"
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSecurityRequestManager : NSObject

DECLARE_SHARED_INSTANCE(TBSecurityRequestManager)

- (void)bindPhone:(NSString *)phone
          telCode:(NSString *)telCode
       verifyCode:(NSString *)verifyCode
      verifyToken:(NSString *)verifyToken
          success:(void(^)(void))success
          failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)bindEmail:(NSString *)email
       verifyCode:(NSString *)verifyCode
      verifyToken:(NSString *)verifyToken
          success:(void(^)(void))success
          failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

// 验证邮箱
- (void)verifyEmailWithVerifyCode:(NSString *)verifyCode
            success:(void(^)(void))success
            failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)setLoginPassword:(NSString *)password
                 success:(void(^)(void))success
                 failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)setTradePassword:(NSString *)password
                 success:(void(^)(void))success
                 failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)resetTradePassword:(NSString *)password
               verifyToken:(NSString *)verifyToken
                   success:(void(^)(void))success
                   failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)modifyPhone:(NSString *)phone
            telCode:(NSString *)telCode
         verifyCode:(NSString *)verifyCode
        verifyToken:(NSString *)verifyToken
            success:(void(^)(void))success
            failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)modifyEmail:(NSString *)email
         verifyCode:(NSString *)verifyCode
        verifyToken:(NSString *)verifyToken
            success:(void(^)(void))success
            failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)modifyLoginPassword:(NSString *)password
                verifyToken:(NSString *)verifyToken
                    success:(void(^)(void))success
                    failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

- (void)modifyTradePassword:(NSString *)password
                verifyToken:(NSString *)verifyToken
                    success:(void(^)(void))success
                    failure:(void(^)(NSNumber * _Nullable errorCode, NSString *errorMsg))failure;

@end

NS_ASSUME_NONNULL_END
