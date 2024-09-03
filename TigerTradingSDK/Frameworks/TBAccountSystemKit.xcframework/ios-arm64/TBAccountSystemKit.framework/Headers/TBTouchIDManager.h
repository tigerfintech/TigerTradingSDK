//
//  TBTouchIDManager.h
//  Stock
//
//  Created by WCP on 2018/10/24.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTouchIDManager : NSObject

/// 开启指纹验证
/// @param publicKey 公钥
/// @param tradePassword 交易密码
/// @param success 成功回调
/// @param failure 失败回调
+ (void)openTouchIDVerifyPublicKey:(nullable NSString *)publicKey
                     tradePassword:(nullable NSString *)tradePassword
                           success:(nullable void (^)(BOOL success))success
                           failure:(nullable void (^)(NSString *errorMsg))failure;

/// 关闭指纹验证
/// @param success 成功回调
/// @param failure  失败回调
+ (void)closeTouchIDVerifySuccess:(nullable void (^)(BOOL success))success
                         failure:(nullable void (^)(NSString *errorMsg))failure;

@end

NS_ASSUME_NONNULL_END
