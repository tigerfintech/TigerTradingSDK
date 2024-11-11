//
//  TBKeyChainManager.h
//  Stock
//
//  Created by charming on 2020/4/6.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/UICKeyChainStore.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <TBToolsKit/TBAuthConstantString.h>

FOUNDATION_EXTERN NSString *const USER_DEFAULT_KEY_PHONE_NUMBER;
FOUNDATION_EXTERN NSString *const USER_DEFAULT_KEY_EMAIL;
FOUNDATION_EXTERN NSString *const USER_DEFAULT_KEY_ACCESS_TOKEN;
FOUNDATION_EXTERN NSString *const USER_DEFAULT_KEY_UUID;
FOUNDATION_EXTERN NSString *const USER_DEFAULT_KEY_LOCAL_PHONE_NUMBER;
FOUNDATION_EXTERN NSString *const USER_DEFAULT_KEY_LOCAL_EMAIL;


@interface TBKeyChainManager : NSObject

DECLARE_SHARED_INSTANCE(TBKeyChainManager)
// 安全部门需求， 不能通过userDefaults 保存用户的phone 和 email，access token， 会被破解
// 登录注册等获得的用户手机号信息
+ (void)setEncryptedPhoneWithString:(NSString *)phone;
+ (NSString *)getEncryptedPhone;

// 登录注册等获得的用户email信息
+ (void)setEncryptedEmailWithString:(NSString *)email;
+ (NSString *)getEncryptedEmail;

+ (void)setEncryptedTokenWithString:(NSString *)token;
+ (NSString *)getEncryptedAccessToken;


// 注意区分， 这是用来存储上次登录的手机号， 该手机号，是可能上面的手机号是不同的， 因为上面的手机号，可能是有注册的情况保存的， 而这里只是存储上次登录用的
+ (void)setEncryptedLastLoginPhoneWithString:(NSString *)phone;
+ (NSString *)getEncryptedLastLoginPhone;

// 用来存储上次登录的email
+ (void)setEncryptedLastLoginEmailWithString:(NSString *)email;
+ (NSString *)getEncryptedLastLoginEmail;

// 存储上次登录的areaCode
+ (void)setEncryptedLastLoginAreaCodeWithString:(NSString *)areaCode;
+ (NSString *)getEncryptedLastLoginAreaCode;

// 存储uuid
+ (void)setEncryptedUUIDWithString:(NSString *)uuid;
+ (NSString *)getEncryptedUUID;

// 存储aes-data
+ (void)setEncryptedAESDataWithString:(NSData *)data;
+ (NSData *)getEncryptedAESData;

@end

