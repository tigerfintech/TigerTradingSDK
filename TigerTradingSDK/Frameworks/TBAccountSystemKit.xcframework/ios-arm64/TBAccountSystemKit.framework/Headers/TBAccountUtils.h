//
//  TBAccountUtils.h
//  Pods
//
//  Created by linbingjie on 2021/4/29.
//

#import <Foundation/Foundation.h>
#import <TBToolsKit/TBAuthConstantString.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kTBAppEditionDidChangedNotification;

extern NSString * const kTBUserRegionCHN;
extern NSString * const kTBUserRegionSGP;
extern NSString * const kTBUserRegionHKG;
extern NSString * const kTBUserRegionIDN;
extern NSString * const kTBUserRegionNZL;
extern NSString * const kTBUserRegionAUS;

@interface TBAccountUtils : NSObject
// MARK: Edition相关，该字段决定了 app的content, 就是部分内容展示不一样
// 正常情况下， 已注册用户的register region为中国大陆， Edition为full， 否则Edition为 fundamental， app部分内容可能会被隐藏。

// app edition
+ (NSString *)getAppContentEdition;
+ (void)setAppContentEdition:(NSString *)edition;

+ (BOOL)isAppFullEdition; // 非Full即Fundamental

/**
 获取注册国籍
 */
+ (NSString *)getRegisterLocation;

/**
 获取注册国籍名称， 在未开户状态下， 设置页面显示名称
 */
+ (NSString *)getRegisterLocationName;

+ (NSString *)getUserRegisterRegion; // 用户注册地，我们通常所述的region， 可能会使用region做一些区域上的判断。
+ (void)setUserRegisterRegion:(NSString *)region;


// MARK: 牌照相关， 目前Tiger Trade有三个牌照， TBNZ（新西兰牌照），TBSG（新加坡牌照）， TBAU（澳大利亚牌照）
// 牌照关系到开户，行情，交易。 正常一个大陆用户，开出的交易账户，都是TBNZ牌照下的， 行情显示，下单交易也会在该牌照下进行。
// 特殊的情况是，用户打开app，通过web开户， 然后返回客户端， 这个时候客户端本来的license是nil， 通过轮询的account status的接口也会有license， 如果发现本地为nil，接口不为nil，会进行写入。

// 注意， 牌照可能为空， 牌照是在用户开完户之后确定的， 且确定牌照之后， 开户，行情，交易的相关域名会进行相应的切换
// 比如 官网的域名是以license为key的字典, 取官网会先取牌照, 再取对应的值
// 获取用户牌照
+ (NSString *)getUserLicense;
+ (void)setUserLicense:(nullable NSString *)license;

/// device/config 接口返回了两个字段：license, license_hint，license 是用户的开户牌照，license_hint 是按照 license, region 先后顺序进行映射的：有 license 返回 license, 没有 license 根据 region 映射。
+ (NSString *)getUserLicenseHint;
+ (void)setUserLicenseHint:(NSString *)licenseHint;

// 官网域名对应的region，根据license映射
+ (NSString *)portalHostRegion;

@property (class, nonatomic, readonly) NSString *licenseOrHint;

/// 从 NSUserDefault 获取 location 参数的值, 可能是保存的上次使用 app 时的位置
+ (NSString *)getLocation;
+ (void)setLocation:(NSString *)location;

//用户id
+ (void)setUUID:(NSString *)uuid;

// 获取默认区号
+ (NSString *)getDefaultTelCode;
+ (void)setDefaultTelCode:(NSString *)telCode fromLogin:(BOOL)fromLogin;

// 设置auth域名路由：GLOBAL or CHN
+ (NSString *)authHostRoute;
+ (void)setAuthHostRoute:(NSString *)route;

//最后一次登录类型
+ (NSNumber *)lastLoginType;

// 是否为游客登录模式
+ (BOOL)isGuestLoginMode;

// 是否401 未授权
+ (BOOL) isUnauthorizedRequest:(NSError *)error;

// 用户牌照是否为新西兰（针对中国大陆用户）
+ (BOOL)isNZLicense;

// 用户牌照是否为新加坡
+ (BOOL)isSGPLicense;

// 用户牌照是否为澳大利亚
+ (BOOL)isAULicense;

// 用户牌照是否为新西兰-牌照下的 AFSL 牌照（已废弃，不再有这种牌照）
+ (BOOL)isTBNZ_AFSL_License;

// (已废弃，TFNZ对应TBKIWI）
+ (BOOL)isTFNZLicense;

// 用户牌照是否为新西兰(TBKIWI)牌照
+ (BOOL)isKIWILicense;

// 用户牌照是否为TBHK
+ (BOOL)isHKLicense;

// 用户牌照是否为TBMS
+ (BOOL)isMSLicense;

// 开户埋点param1字段，与license一一对应
+ (NSString *)openAccountParam1;

+ (BOOL)checkNeedRegisterAccount;

// MARK: 登录相关 （包含登录后的跳转， 新手引导， 游客等）
// 多处需要跳转到新设备认证页面， 都收敛到该方法内
+ (void)gotoLoginDeviceAuthenticWithUserName:(NSString *)userName
                                    teleCode:(NSString *)teleCode;

// 检查一键登录注册功能，是否需要设置密码
+ (BOOL)checkOneCilckNeedPassword;

// 获取虚拟账户名
+ (NSString *)currentTradeVirtualAccountName;

// 获取当前账户类型名
+ (NSString *)currentTradeAccountTitle;
+ (NSString *)userCurrentSimpleAccountName;

// 跳转忘记密码
+ (void)gotoAccountRetrive;

// 跳转注销账号
+ (void)gotoAccountLogOff;

// 跳转开通期权
+ (void)gotoOpenOption;

// 跳转模拟账户
+ (void)gotoDemoTrade;

// 跳转Contra账户
+ (void)gotoContraAccount;

// 跳转Contra产品介绍页
+ (void)gotoContraIntroductionPage;

/*
 已开通一个账户的情况下跳转去开第二个户
 source，默认不传，开Contra传contra_account
 */
+ (void)gotoAccountsUpgradeWithSource:(nullable NSString *)source;

@end

NS_ASSUME_NONNULL_END
