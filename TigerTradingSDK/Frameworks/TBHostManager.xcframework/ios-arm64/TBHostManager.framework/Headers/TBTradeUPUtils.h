//
//  TBUtils+Server.h
//  Stock
//
//  Created by ChenXin on 2017/9/14.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBTradeUPUtils : NSObject

// 获取url的根域名, 如 api.tigerbrokers.com, 返回 tigerbrokers.com
+ (NSString *)getROOTHost:(NSString *)host;

// 获取站点名称，返回 tigerbrokers.com
+ (NSString *)getAppSiteName;
//
// 获取期权服务器host
+ (NSString *)getOptionServerHost;

// 获取主站服务器host，旧版本使用
+ (NSString *)getWebServerHost;

// 获取老虎股票网站服务器host
+ (NSString *)getStockWebServerHost;

// 获取公司官网, 用于展示协议
+ (NSString *)getCompanyWebServerHost;

// 获取资讯服务器host
+ (NSString *)getNewsServerHost;

// 获取资讯直播新闻服务器host
+ (NSString *)getNewsLiveServerHost;

// 获取apns推送服务器host
+ (NSString *)getPush2ServerHost;

// 获取股价提醒服务器host
+ (NSString *)getAlertServerHost;

// 获取消息中心服务器host
+ (NSString *)getMessageServerHost;

// 获取社区服务器host
// 从v2.4.0版本开始 域名更新服务器只给出host, 然后由客户端自己拼接版本, 如v2, v3
+ (NSString *)getCommunityServerHost;

+ (NSString *)getCommunityServerHostWithVersion:(NSString *)version;

//获取社区Feed服务器host
+ (NSString *)getCommunityFeedServerHost;

// 获取API 交易服务器host
+ (NSString *)getTradeServerHost;

// 获取IDC 行情服务器host
+ (NSString *)getQuoteHttpServerHost;

+ (NSString *)getQuotePermissionHttpServerHost;

// 获取WatchList 行情服务器host
+ (NSString *)getWatchListHttpServerHost;

// 获取宏观经济日历服务器host
+ (NSString *)getMacroCalendarHttpServerHost;

// 获取mqtt服务器host，port，ssl等信息
+ (NSString *)getMqttServerHost;
+ (NSUInteger)getMqttServerPort;
+ (BOOL)getMqttSSLEnabled;

// 获取oauth服务器host
+ (NSString *)getOAuthServerHost;

// 获取升级后oauth tesseract 服务器host , 升级服务后，将account status和 permission 做了拆分
+ (NSString *)getOAuthTesseractServerHost;

// 获取应用升级服务器host
+ (NSString *)getAppUpgradeServerHost;

// 获取Omnibus服务器host
+ (NSString *)getOmnibusServerHost;

// 获取模拟交易服务器host
+ (NSString *)getVirtualTradeServerHost;

// 获取FFA服务器
+ (NSString *)faServerHost;

// 获取开户相关host
+ (NSString *)getOpenAccountServerHost;

// 获取开户协议相关host
+ (NSString *)getOpenAccountAgreementServerHost;

// 判断是否是老虎的域名
+ (BOOL)isLocalSiteURL:(NSString *)domain;

// 获取活动相关host，已拼接/backend-activity/
+ (NSString *)getActivityServerHost;

// 获取个人中心顶部banner host
+ (NSString *)getPersonalCenterActivityServerHost;

// 获取流Server
+ (NSString *)getStreamServerHost;

// 获取ms域名，个性化物料在用
+ (NSString *)getMsServerHost;

//获取消息中心host
+ (NSString *)getMessageCenterHost;

// 获取获取美团logan日志上传服务器地址
+ (NSString *)getLoganLoggerServerHost;

//获取ipo直接相关App用接口
+ (NSString *)getIPOLiveServerHost;

//获取新的社区域名，与老域名同时使用
+ (NSString *)getTigerCommunityServerHost;

//获取新的社区域名，不带版本号
+ (NSString *)getTigerCommunityServerHostNoVersionNumber;

//获取Web社区域名
+ (NSString *)getWebCommunityServerHost;

// 活动
+ (NSString *)getBackendActivityServerHost;

// 基金学院
+ (NSString *)getCollegeServerHost;

// 空间站提现
+ (NSString *)getSpacePayServerHost;

// 获取customer support 服务host 不会根据牌照区分，只做域名拼接即可
// https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=57713529
+ (NSString *)getCustomerSupportServerHost;

// 获取iposervice
+ (NSString *)getCustomerIPOServerHost;

+ (NSString *)getTigerMembershipServerHost;

+ (NSString *)getVideoUploadServerHost;

+ (NSString *)quoteTrackHost;

@end
