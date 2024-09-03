//
//  TBUtils+Server.h
//  Stock
//
//  Created by ChenXin on 2017/9/14.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>

@interface TBUtils (Server)

// 获取url的根域名, 如 api.tigerbrokers.com, 返回 tigerbrokers.com
+ (NSString *)getROOTHost:(NSString *)host;

// 获取期权服务器host
+ (NSString *)getOptionServerHost;

// 获取期权深度服务器host（仅美股）
+ (NSString *)getOptionDepthServerHost;

// 获取期权策略
+ (NSString *)getOptionGeekServerHost;

// 获取最新官网域名
+ (NSString *)getPortalServerHost;

/* 获取最新官网域名
 * @param online true返回线上环境域名，否则根据当前用户登录选择的环境返回相应的域名
 */
+ (NSString *)getPortalServerHost:(BOOL)online;

/// NPS域名
+ (NSString *)npsPortalServerHost;


// 获取资讯服务器host
+ (NSString *)getNewsServerHost;

// 日志上传服务器host
+ (NSString *)getStreamServerHost;

// 消息中心服务器hosot，拼接了版本
+ (NSString *)getMessageCenterHost;

// 获取apns推送服务器host
+ (NSString *)getPush2ServerHost;

// 获取社区服务器host
// 从v2.4.0版本开始 域名更新服务器只给出host, 然后由客户端自己拼接版本, 如v2, v3
+ (NSString *)getCommunityServerHost;

//获取Web社区域名
+ (NSString *)getWebCommunityServerHost;

+ (NSString *)getCommunityServerHostWithVersion:(NSString *)version;



/// 获取行情权限域名
+ (NSString *)getHQPermissionHttpServerHost;

/// 暗盘行情域名
+ (NSString *)getGreyMarketQuoteHttpServerHost;

/**
 美股LV2域名
 */
+ (NSString *)getDepthQuoteHttpServerHost;
/**
 获取期货行情
 */
+ (NSString *)getFuturesQuoteHttpServerHost;
// 获取期货合约系统服务器地址
+ (NSString *)getFuturesContractHTTPServerHost;

// 获取WatchList 行情服务器host
+ (NSString *)getWatchListHttpServerHost;

// 获取宏观经济日历服务器host
+ (NSString *)getMacroCalendarHttpServerHost;

// 获取mqtt服务器host，port，ssl等信息
+ (NSString *)getMqttServerHost;
+ (NSUInteger)getMqttServerPort;
+ (BOOL)getMqttSSLEnabled;

/// 获取数字货币长连接mqtt服务器host，port，ssl等信息
+ (NSString *)getCCMqttServerHost;
+ (UInt32)getCCMqttServerPort;
+ (BOOL)getCCMqttSSLEnabled;


/// 获取publish长连接mqtt服务器host，port，ssl等信息
+ (NSString *)getPublishMQTTServerHost;
+ (UInt32)getPublishMqttServerPort;
+ (BOOL)getPublishMqttSSLEnabled;
+ (BOOL)getPublishMqttEnabled;

// 获取tesseract服务器host（北京）
+ (NSString *)getTesseractServerHost;

// 获取应用升级服务器host
+ (NSString *)getAppUpgradeServerHost;

// 获取Omnibus服务器host
+ (NSString *)getOmnibusServerHost;
+ (NSString *)getOmnibusServerHostWithLicense:(NSString *)license;

// 获取模拟交易服务器host
+ (NSString *)getVirtualTradeServerHost;

// 获取TipRank服务器
+ (NSString *)getStockTipRankServerHost;

// 获取Esop接口域名
+ (NSString *)getEsopServerHost;

// 获取esop跳转链接
+ (NSString *)getEsopWebHost;

//获取炒股大赛相关服务器域名
+ (NSString *)getStockGameServerHost;

//社区主题相关域名
+ (NSString *)getStockThemeServerHost;

//获取ipo直接相关App用接口
+ (NSString *)getIPOLiveServerHost;

//获取新的社区域名，与老域名同时使用
+ (NSString *)getTigerCommunityServerHost;

//获取新的社区域名，不带版本号
+ (NSString *)getTigerCommunityServerHostNoVersionNumber;

//获取社区push相关域名
+ (NSString *)getCommunityPushServerHost;

//获取社区push海外域名
+ (NSString *)getCommunityPushOverseaServerHost;

//获取社区push国内域名
+ (NSString *)getCommunityPushChnServerHost;

// 获取基金域名
+ (NSString *)getFundBusinessServerHost;

// 获取auth tesseract域名， 主要包含 新升级的account status 服务和 permission 服务
// 注意区别 非 auth tessercat 接口域名
// 线上请求tesseract-hk
+ (NSString *)getAuthTesseractServerHost;

//内购校验服务
+ (NSString *)getInAppPayDomain;

// 获取流服务接口域名，目前客户端用的是微信一次性订阅公众号推送消息的服务
+ (NSString *)getMsServerHost;

// 《暗盘交易风险》
+ (NSString *)getGreyMarketRiskAgreementURL;

// 《暗盘交易客户协议》
+ (NSString *)getGreyMarketClientAgreementURL;

// 数字货币
+ (NSString *)getDigitalCurrencyHttpServerHost;

// 神策
+ (NSString *)getSensorsServerURL;

// 活动
+ (NSString *)getBackendActivityServerHost;

// 行情请求监控
+ (NSString *)quoteTrackServerHost;

// 空间站提现
+ (NSString *)getSpacePayServerHost;

// 个人中心服务, 如出入金, 转股, 公司行动, 注销等 路径以/ams/开头
+ (NSString *)getWebAMSServerHost;

// IPO业务, 质押融资业务, 炒股大赛 路径 mi/ipo, mi/pledge
+ (NSString *)getWebIPOServerHost;
+ (NSString *)getWebIPOServerHostWithLicense:(NSString *)license;

+ (NSString *)getMarktingServerHost;

+ (NSString *)getVideoUploadServerHost;

// 获取获取美团logan日志上传服务器地址
+ (NSString *)getLoganLoggerServerHost;

// 获取会员域名
+ (NSString *)getTigerMembershipServerHost;

// 请求是否需要参数QuotePermissionVersion
+ (BOOL)isNeedQuotePermissionVersion:(NSString *)urlString;

#pragma mark - Deprecated

// 行情
+ (NSString *)getQuoteHttpServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

+ (NSString *)getOAuthServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

/// 和用户license对应的开户相关域名.
/// 如果要取和license无关的开户域名, 用[TBUtils getCommonCustomerServerHost].
+ (NSString *)getCustomerServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");
+ (NSString *)getCustomerServerHostWithLicense:(NSString *)license DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

// TODO: 拆成customerSupport, customerIPO两个域名
// 获取账户customer系统相关host, 单独获取common域名， 供customer_support、customer_ipo两个服务使用，目前只是提供了接口，暂未启用
+ (NSString *)getCommonCustomerServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

// 获取customer ipo 服务host
+ (NSString *)getCustomerIPOServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

// 获取customer support 服务host
+ (NSString *)getCustomerSupportServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

// 获取账户customer系统相关host, 单独获取国内域名， 新西兰牌照
+ (NSString *)getChineseCustomerServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

+ (NSString *)getCollegeServerHost DEPRECATED_MSG_ATTRIBUTE("用TBHostWithId获取域名");

@end
