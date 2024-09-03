//
//  TBKeychainTouchID.h
//  Stock
//
//  Created by WCP on 2018/10/23.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TBTouchIdEvaluateResult)
{
    TBTouchIdEvaluateResultSuccess,   // 验证成功
    TBTouchIdEvaluateResultFailed,    // 验证失败
    TBTouchIdEvaluateResultCancel,    // 点击取消按钮
    TBTouchIdEvaluateResultFallback,  // 点击回退按钮
    TBTouchIdEvaluateResultOther      // 未知结果
};
@class LAContext;
typedef void(^TouchIdEvaluateCallback)(LAContext *context, TBTouchIdEvaluateResult result);


@protocol TBKeyChainTouchIDDelegate <NSObject>

@optional
/**
 获取私钥签名后的原始数据和签名后的数据
 
 @param success 签名状态
 @param originalStr 签名前的原始数据
 @param signDataStr 签名后的数据
 */
- (void)getSignStatus:(BOOL)success originalData:(NSString *)originalStr signData:(NSString *)signDataStr;

/// 处理签名失败, 根据 error code 进行不同的提示
- (void)getSignFailed:(NSError *)error;

/// 是否开启或设置生物验证
- (BOOL)canEvaluatePolicy:(NSError * __autoreleasing *)error;
// 生物 验证 callback回调已经抛到了主线程
// 失败三次会调用系统输入数字密码
- (void)evaluatePolicy:(NSString *)localizedReasion
         fallbackTitle:(NSString *)title
              callback:(TouchIdEvaluateCallback)callBack;

/**
 获取验证签名的状态
 
 @param success 成功或者失败
 */
- (void)getVerifySignStatus:(BOOL)success;

- (void)getVerifySignCanceled;


/**
 获取删除私钥的状态
 
 @param success 成功或者失败
 @param message 附加信息
 */
- (void)getDeletePrivateKeyStatus:(BOOL)success message:(NSString *)message;

/**
 输入用户密码
 */
- (void)verifyUserTradePassword;

/**
 验证成功
 */
- (void)verifyUserTouchIDSuccess;

/**
 验证失败
 */
- (void)verifyUserTouchIDFailed;

/**
未设置TouchID
 */
- (void)verifyUserTouchIDNoTouchID;

/**
用户取消touchid验证
 */
- (void)verifyUserCancelTouchID;
@end

@interface TBKeychainTouchID : NSObject

@property (nonatomic, weak) id <TBKeyChainTouchIDDelegate>delegate;

+ (BOOL)isSupportTouchID;

+ (BOOL)isSupportFaceID;

+ (NSString *)touchOrFaceIDName;

/**
 生成非对称加密的私钥, 保存到 keychain SecureEnclave
 
 @param userID 用户唯一标识
 @return  base64格式的公钥
 */
- (NSString *)generatePublicWithKeyUserID:(NSString *)userID;

/**
 从Keychain中获取公钥并转换成base64格式
 
 @param userID 用户唯一标识
 @return base64格式的公钥
 */
- (NSString *)getPublicKeyUserID:(NSString *)userID;

/**
 使用之前生成的私钥签名一段数据
 
 @param dataToSign 要签名的数据
 @param userID 用户唯一标识
 */
- (void)useKeyToSignString:(NSString *)dataToSign userID:(NSString *)userID;

/**
 验证一段签名
 
 @param originalStr 签名前的原始数据
 @param signAfterStr 签名后的数据
 @param userID 用户唯一标识
 */
- (void)verifySign:(NSString *)originalStr signData:(NSString *)signAfterStr userID:(NSString *)userID;

/**
 删除与用户userID相对于的私钥
 
 @param userID 用户唯一标识
 */
- (void)deletePrivateKeyWithUserID:(NSString *)userID;

/**
 检查userID对应的私钥是否存在
 
 @param userID userID 用户唯一标识
 @return YES存在，NO不存在
 */
- (BOOL)checkHasExistPrivateKeyWithUserID:(NSString *)userID;

/**
 验证指纹
 */
- (void)verifyTouchID;

/// "User has denied the use of biometry for this app."
+ (BOOL)isDeniedUseBiometrics;

@end
