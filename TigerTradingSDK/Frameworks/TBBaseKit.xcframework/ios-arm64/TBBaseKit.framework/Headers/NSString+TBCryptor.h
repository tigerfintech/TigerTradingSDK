//
//  NSString+TBCryptor.h
//  TigerToken
//
//  Created by chenxin on 2018/8/2.
//  Copyright © 2018年 TigerBrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TBCryptor)

- (NSString *)tb_encryptString:(BOOL)useECB;
- (NSString *)tb_decryptString:(BOOL)useECB;

// with ECB
- (NSString *)tb_encryptStringWithECB;
- (NSString *)tb_decryptStringWithECB;

// without ECB
- (NSString *)tb_encryptStringNOECB;
- (NSString *)tb_decryptStringNOECB;

/**
 *  AES加密
 *
 *  @param keyString 加密密钥
 *  @param iv        初始化向量(8个字节)
 *
 *  @return 返回加密后的base64编码字符串
 */
- (NSString *)tb_aesEncryptString:(NSString *)keyString iv:(NSData *)iv;

/**
 *  AES解密
 *
 *  @param keyString 解密密钥
 *  @param iv        初始化向量(8个字节)
 *
 *  @return 返回解密后的字符串
 */
- (NSString *)tb_aesDecryptString:(NSString *)keyString iv:(NSData *)iv;

@end
