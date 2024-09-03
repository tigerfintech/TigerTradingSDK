//
//  TBHostService.h
//  Pods
//
//  Created by linbingjie on 2021/3/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBHostService <NSObject>

- (BOOL)tbHost_shouldStoreRequest:(NSURLRequest *)request;


@optional

/// 用hostId获取域名, 无"/"后缀
- (NSString *)hostWithIdentifier:(NSString *)hostId;

// 替换动态域名链接
- (NSString *)replacedUrlWithDynamicUrl:(NSString *)dynamicUrl defaultUrl:(NSString *)defaultUrl;

#pragma mark - 保留旧的域名获取方法

// dnha服务域名
- (NSString *)dnhaServerHost;

// 环球账户交易
- (NSString *)ibTradeHost;

// 行情
- (NSString *)getQuoteHttpServerHost;

// 自选
- (NSString *)getWatchlistServerHost;

// Auth服务器域名
- (NSString *)oauthHost;

// 获取对应路由（CHN，GLOBAL）的Auth服务器域名
- (NSString *)getOauthHostWithRoute:(NSString *)route;

/// 和用户license对应的开户相关域名.
/// 如果要取和license无关的开户域名, 用[TBUtils getCommonCustomerServerHost].
- (NSString *)getCustomerServerHost;
- (NSString *)getCustomerServerHostWithLicense:(NSString *)license;

// 获取customer ipo 服务host
- (NSString *)getCustomerIPOServerHost;

// 获取customer support 服务host
- (NSString *)getCustomerSupportServerHost;

// 获取账户customer系统相关host, 单独获取国内域名， 新西兰牌照
- (NSString *)getChineseCustomerServerHost;

- (NSString *)gcsChatServerHost; // GCS在线客服
- (NSString *)gcsChatServerHostWithLicense:(NSString *)license;
- (NSString *)ticketServerHost; // 新版用户反馈API/工单域名

// 获取学院host
- (NSString *)getCollegeServerHost;

// 综合账户（TradeUP为Marsco）交易服务器域名
- (NSString *)omnibusTradeHostWithLicense:(NSString *)license;

// 模拟账户交易服务器域名
- (NSString *)virtualTradeHost;

// 获取tesseract服务器host（北京）
// tradeup getOAuthTesseractServerHost
// tigertrade getTesseractServerHost
- (NSString *)getTesseractServerHost;

// tradeup getOAuthTesseractServerHost
// tigertrade getAuthTesseractServerHost
// 获取auth tesseract域名， 主要包含 新升级的account status 服务和 permission 服务
// 注意区别 非 auth tessercat 接口域名
// 线上请求tesseract-hk
- (NSString *)getAuthTesseractServerHost;

// tigertrade  获取最新官网域名
// tradeup 暂无使用这个逻辑
- (NSString *)getPortalServerHost;

/* tigertrade  获取最新官网域名
 * tradeup 暂无使用这个逻辑
 * @param online true返回线上环境域名，否则根据当前用户登录选择的环境返回相应的域名
 */
- (NSString *)getPortalServerHost:(BOOL)online;

//获取新的社区域名，与老域名同时使用
- (NSString *)getTigerCommunityServerHost;

// 获取股价提醒服务器host
- (NSString *)getPush2ServerHost;

// 获取推送服务器host
- (NSString *)getEpsServerHost;

#pragma mark - 行情相关域名

/*
 https://tigertech.feishu.cn/wiki/wikcnZ5J8ZO1ECkZRBJwdLAdQwm
 */
- (NSString *)getHQPermissionHttpServerHost;

// 数字货币
- (NSString *)getDigitalCurrencyHttpServerHost;

// 暗盘行情域名
- (NSString *)getGreyMarketQuoteHttpServerHost;

// 获取 option host
- (NSString *)getOptionHost;

// 获取 option host
- (NSString *)getOptionGeekHost;

// 获取期货行情
- (NSString *)getFuturesQuoteHttpServerHost;

// 获取流服务接口域名，目前客户端用的是微信一次性订阅公众号推送消息的服务
- (NSString *)getMsServerHost;

// 个人中心服务, 如出入金, 转股, 公司行动, 注销等 路径以/ams/开头
- (NSString *)getWebAMSServerHost;

// IPO业务, 质押融资业务, 炒股大赛 路径 mi/ipo, mi/pledge
- (NSString *)getWebIPOServerHost;
- (NSString *)getWebIPOServerHostWithLicense:(NSString *)license;

// 获取活动营销服务器host
- (NSString *)getMarktingServerHost;

// 社区视频上传
- (NSString *)getVideoUploadServerHost;

//社区主题相关域名
- (NSString *)getStockThemeServerHost;

// 获取Omnibus服务器host
- (NSString *)getOmnibusServerHost;

//获取新的社区域名，不带版本号
- (NSString *)getTigerCommunityServerHostNoVersionNumber;

//获取新的社区域名，带版本号
- (NSString *)getCommunityServerHostWithVersion:(nullable NSString *)version;

- (NSString *)getNewsServerHost;

- (NSString *)getStreamServerHost;

- (NSString *)getMessageCenterHost;

// 活动
- (NSString *)getBackendActivityServerHost;



// 获取期货合约系统服务器地址
- (NSString *)getFuturesContractHTTPServerHost;

/**
 美股LV2域名
 */
- (NSString *)getDepthQuoteHttpServerHost;

// 获取期权深度服务器host（仅美股）
- (NSString *)getOptionDepthServerHost;

//获取ipo直接相关App用接口
- (NSString *)getIPOLiveServerHost;

// 获取获取美团logan日志上传服务器地址
- (NSString *)getLoganLoggerServerHost;

// 获取社区服务器host
// 从v2.4.0版本开始 域名更新服务器只给出host, 然后由客户端自己拼接版本, 如v2, v3
- (NSString *)getCommunityServerHost;

//获取Web社区域名
- (NSString *)getWebCommunityServerHost;

- (NSString *)getInAppPayDomainServerHost;

- (NSString *)getSpacePayServerHost;

// 获取会员相关域名
- (NSString *)getTigerMembershipServerHost;

//行情监控host
- (NSString *)quoteTrackHost;

// ipip的host
- (NSString *)getIPServerHost;

#pragma mark -

/// 老虎内部域名
- (NSArray *)tigerHosts;

#pragma mark - Deprecated

@end

NS_ASSUME_NONNULL_END
