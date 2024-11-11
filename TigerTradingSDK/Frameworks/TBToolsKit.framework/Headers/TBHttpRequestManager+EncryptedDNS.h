//
//  TBHttpRequestManager+EncryptedDNS.h
//  Stock
//
//  Created by donggongfu on 2021/2/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBNetworking/TBHttpRequestManager.h>

NS_ASSUME_NONNULL_BEGIN

#define TBEncryptedDNSEnabled (1)

extern NSString * const TBEncryptedDNSProvider;

//用户是否手动设置了DNS
extern NSString * const TBCustomDidSelectedDNSKey;

@interface TBHttpRequestManager (EncryptedDNS)

/// 检查是否指定了DoH提供商, 如果指定, 启用加密DNS
/// @return 是否使用了加密DNS
+ (BOOL)checkEncryptedDNS;

/// 用户选择的DNS提供商
+ (nullable NSString *)selectedProvider;
+ (void)setProvider:(nullable NSString *)provider;


/// 读取保存加密DNS的URL和地址的plist文件内容到字典
+ (nullable NSDictionary *)encryptedDNSSettings;


/// 使用指定提供商的加密DNS
/// @param provider 提供商名称
/// @return 是否成功启动了加密DNS
+ (BOOL)useEncryptedDNS:(nullable NSString *)provider;


/// 使用iOS14原生API启用加密DNS
/// @param URLString
/// @param addresses
+ (void)useEncryptedDNSWithURL:(NSString *)URLString addresses:(NSArray<NSString *> *)addresses;

@end

NS_ASSUME_NONNULL_END
