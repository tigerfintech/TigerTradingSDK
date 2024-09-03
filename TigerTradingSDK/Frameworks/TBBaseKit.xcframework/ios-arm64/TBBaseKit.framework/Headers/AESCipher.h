//
//  AESCipher.h
//  AESCipher
//
//  Created by Welkin Xie on 8/13/16.
//  Copyright © 2016 WelkinXie. All rights reserved.
//
//  https://github.com/WelkinXie/AESCipher-iOS
//

#import <Foundation/Foundation.h>

NSString * aesEncryptString(NSString *content, NSString *key, BOOL useECB);
NSString * aesDecryptString(NSString *content, NSString *key, BOOL useECB);

NSData * aesEncryptData(NSData *data, NSData *key, NSData *iv, BOOL useECB);
NSData * aesDecryptData(NSData *data, NSData *key, NSData *iv, BOOL useECB);
