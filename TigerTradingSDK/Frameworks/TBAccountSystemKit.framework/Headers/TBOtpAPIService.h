//
//  TBOtpAPIService.h
//  Stock
//
//  Created by chenxin on 2021/9/14.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include("TBTwoFactorAuthKey.h")
#import "TBTwoFactorAuthKey.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface TBOtpAPIService : NSObject

/// 获取两步验证状态
+ (void)fetchStatus:(void(^)(BOOL status, BOOL signin, BOOL trade))success
            failure:(void(^)(NSString * message))failure;

#if __has_include("TBTwoFactorAuthKey.h")

/// 生成两步验证秘钥
+ (void)generateKeyWithLoginPassword:(NSString *)loginPassword
                             success:(void(^)(TBTwoFactorAuthKey *key))success
                             failure:(void(^)(NSString *message))failure;
#endif
/// 启用两步验证
+ (void)turnOn:(NSDictionary *)params
       success:(void(^)(void))success
       failure:(void(^)(NSString *message))failure;

/// 关闭两步验证
+ (void)turnOffWithLoginPassword:(NSString *)loginPassword
                         otpCode:(nullable NSString *)otpCode
                         linkCode:(nullable NSString *)linkCode
                         success:(void(^)(BOOL needDynamicPsw))success
                         failure:(void(^)(NSString *message))failure;

/// 设置启用位置
+ (void)setOptions:(NSDictionary *)params
           success:(void(^)(BOOL needDynamicPsw))success
           failure:(void(^)(NSString *message))failure;

/// 错误提示信息
/// @param dataDict 接口返回data
+ (NSString *)errorMessageWithData:(NSDictionary *)dataDict;

@end

NS_ASSUME_NONNULL_END
