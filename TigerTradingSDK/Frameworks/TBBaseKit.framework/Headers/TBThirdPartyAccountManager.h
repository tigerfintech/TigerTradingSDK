//
//  TBThirdPartyAccountManager.h
//  Stock
//
//  Created by Tiger on 2021/10/29.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

/*
是否允许三方平台登录或者分享
*/
#define EnableThirdPartyPlatform   YES

#define TB_JPUSH_APPKEY             [TBThirdPartyAccountManager sharedInstance].jpushAppKey

#define WEIXIN_APPID                [TBThirdPartyAccountManager sharedInstance].weixinAppId
#define WEIXIN_APP_SECRET           [TBThirdPartyAccountManager sharedInstance].weixinAppSecret
#define WEIXIN_ENABLE               TextValid(WEIXIN_APPID)

#define TWITTER_API_KEY             [TBThirdPartyAccountManager sharedInstance].twitterAppId
#define TWITTER_API_SECRET          [TBThirdPartyAccountManager sharedInstance].twitterAppSecret
#define TWITTER_ENABLE              TextValid(TWITTER_API_KEY)

#define FACEBOOK_APPID              [TBThirdPartyAccountManager sharedInstance].facebookAppId
#define FACEBOOK_ENABLE             TextValid(FACEBOOK_APPID)

#define WEIBO_APPID                 [TBThirdPartyAccountManager sharedInstance].weiboAppId
#define WEIBO_ENABLE                TextValid(WEIBO_APPID)

#define TENCENT_APPID               [TBThirdPartyAccountManager sharedInstance].qqAppId
#define TENCENT_ENABLE              TextValid(TENCENT_APPID)

#define ALI_AUTH_KEY                [TBThirdPartyAccountManager sharedInstance].aliAuthKey

#define GOOGLE_APPID              [TBThirdPartyAccountManager sharedInstance].googleAppId
#define GOOGLE_ENABLE             TextValid(GOOGLE_APPID)

//  weiChat  集成微信SKD1.5（升级为1.8.7.1）：
#define WEIXIN_TEMPLATEID           @"J3k-aqXaC_Qk8VylVMsjlXCLH914R_v0ZTxRGmE1NRA"

@interface TBThirdPartyAccountManager : NSObject

DECLARE_SHARED_INSTANCE(TBThirdPartyAccountManager)

/*
 以下账号信息由壳工程配置
 */

@property (nonatomic, copy) NSString *jpushAppKey;

@property (nonatomic, copy) NSString *weixinAppId;

@property (nonatomic, copy) NSString *weixinAppSecret;

@property (nonatomic, copy) NSString *twitterAppId;

@property (nonatomic, copy) NSString *twitterAppSecret;

@property (nonatomic, copy) NSString *facebookAppId;

@property (nonatomic, copy) NSString *weiboAppId;

@property (nonatomic, copy) NSString *qqAppId;

@property (nonatomic, copy) NSString *aliAuthKey;

@property (nonatomic, copy) NSString *googleAppId;

@property (nonatomic, copy) NSString *appsflyerKey;

@end

NS_ASSUME_NONNULL_END
