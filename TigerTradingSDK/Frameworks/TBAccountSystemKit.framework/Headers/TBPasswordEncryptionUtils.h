//
//  TBPasswordEncryptionUtils.h
//  Stock
//
//  Created by chenxin on 2021/8/2.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBPasswordType) {
    TBPasswordTypeLogin,
    TBPasswordTypeTrade,
};

extern NSString * const TBPwdApiVerKey;

extern NSString * const TBLoginPasswordKey;

extern NSString * const TBTradePasswordKey;

@interface TBPasswordEncryptionUtils : NSObject

// // 密码是否满足规则。（规则：长度8至24，且至少要满足两个：1.字母（大小写均可）2.数字 3.标点符号和特殊字符）
+ (BOOL)isValidLoginPassword:(NSString *)password;

// 密码是否符合规范，暂不校验密码长度。（规则：至少要满足两个：1.字母（大小写均可）2.数字 3.标点符号和特殊字符）
+ (BOOL)isPasswordValidWithoutLengthCheck:(NSString *)password;

// 密码长度是否有效（8至24位）
+ (BOOL)isPasswordLengthValid:(NSString *)password;

/*
 返回对登录密码进行加密处理过的query字符串，包含login_password和pwd_api_ver两个参数
 拼接使用时需要自己添加&
 */
+ (NSString *)encryptedQueryStringWithLoginPassword:(NSString *)loginPassword;

/*
 返回对登录密码进行加密处理过的字典，包含login_password和pwd_api_ver两个参数
 */
+ (NSDictionary *)encryptedDictionaryWithLoginPassword:(NSString *)loginPassword;

/*
 返回对交易密码进行加密处理过的query字符串，包含trade_password和pwd_api_ver两个参数
 拼接使用时需要自己添加&
 */
+ (NSString *)encryptedQueryStringWithTradePassword:(NSString *)tradePassword;

/*
 返回对交易密码进行加密处理过的字典，包含trade_password和pwd_api_ver两个参数
 */
+ (NSDictionary *)encryptedDictionaryWithTradePassword:(NSString *)tradePassword;

@end

NS_ASSUME_NONNULL_END
