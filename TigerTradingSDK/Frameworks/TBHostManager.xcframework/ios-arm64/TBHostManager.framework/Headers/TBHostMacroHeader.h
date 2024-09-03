//
//  TBHostMacroHeader.h
//  TBHostManager
//
//  Created by JustLee on 2020/6/4.
//  Copyright © 2020 JustLee. All rights reserved.
//

#ifndef TBHostMacroHeader_h
#define TBHostMacroHeader_h

#pragma mark - 内部域名(用于deeplinking)

#define TB_DOMAIN_TIGERBROKERS_COM @"tigerbrokers.com"
#define TB_DOMAIN_TIGERBROKERS_NET @"tigerbrokers.net"
#define TB_DOMAIN_ITIGER @"itiger.com"
#define TB_DOMAIN_XIAOHU8 @"xiaohu8.com"
#define TB_DOMAIN_LAOHU8 @"laohu8.com"
#define TB_DOMAIN_TIGER_FINTECH @"tigerfintech.com"
#define TB_DOMAIN_TIGER_BBS @"tigerbbs.com"
#define TB_DOMAIN_TIGER_SECURITIES @"tigersecurities.com"
#define TB_DOMAIN_TIGER_AU @"trade.tigerbrokers.com.au"
#define TB_DOMAIN_TIGER_SG @"trade.tigerbrokers.com.sg"
#define TB_DOMAIN_SPACE_WITHDRAW_HOST @"pay.zhijianfengyi.com" // 6.8.3 空间站提现域名
#define TB_DOMAIN_TEST_SPACE_WITHDRAW_HOST @"pay-dev.zhijianfengyi.com" // 6.8.3 空间站提现域名

#pragma mark - 服务器地址

// TODO: 全部适配后移动到一个类, 隐藏字符串中的url地址

// portal 官网
static NSString *const TBHostPortalURL = @"https://www.itigerup.com";
static NSString *const TBHostTestPortalURL = @"https://dev.itiger.com";

// college
// 基金超市-基金学院
static NSString *const TBHostCollegeServer      = @"https://college.tigerbbs.com";
static NSString *const TBHostTestCollegeServer  = @"https://cms-dev.tigerfintech.com";


// 官网活动域名
static NSString *const TBHostPortalActivityURL = @"https://www.itigerup.com";
static NSString *const TBHostTestPortalActivityURL = @"https://dev.itiger.com";


// backend-activity 活动
#define TB_BACKEND_ACTIVITY_HOST                    @"https://www.itiger.com/"
#define TB_TEST_BACKEND_ACTIVITY_HOST               @"https://dev.itiger.com/"

// bi-stream
#define TB_TEST_STEAMMS_SERVER @"https://test-ms.tigerfintech.com/"
#define TB_STEAMMS_SERVER @"https://ms.tigerfintech.com/"

// fund-business
#define TB_FUND_BUSINESS_HOST_COMMON @"https://cash-plus-api.skytigris.cn"
#define TB_FUND_BUSINESS_HOST_TBKIWI @"https://cash-plus-api.itiger-nz.com"
#define TB_FUND_BUSINESS_HOST_TBSG @"https://cash-plus-api.tigerbrokers.com.sg"
#define TB_FUND_BUSINESS_HOST_TBAU @"https://cash-plus-api.tigerbrokers.com.au"
#define TB_FUND_BUSINESS_HOST_TBNZ @"https://cash-plus-api.skytigris.cn"
#define TB_FUND_BUSINESS_HOST_TBHK @"https://cash-plus-api.tigerbrokers.com.hk"
#define TB_FUND_BUSINESS_HOST_TBMS @"https://cash-plus-api.skytigris.com"
#define TB_FUND_BUSINESS_HOST_TEST @"https://cash-plus-api-test.tigerfintech.com"

// api-track
#define TB_TRACK_BUSINESS_HOST_TEST @"https://mnt-report.qa.tigerbrokers.net"
#define TB_TRACK_BUSINESS_HOST_ONLINE @"https://mnt-report.skytigris.cn"


// crypto-push 数字货币长连接
#define TB_CRYPTO_TEST_MQTT_SERVER              @"qa-crypto-live.tigerfintech.com"
#define TB_CRYPTO_TEST_MQTT_SERVER_PORT         8883
#define TB_CRYPTO_TEST_MQTT_SSL_ENABLE          YES
#define TB_CRYPTO_SPECIAL_MQTT_SERVER           @"crypto-live.xiaohu8.com"
#define TB_CRYPTO_SPECIAL_MQTT_SERVER_PORT      8893
#define TB_CRYPTO_SPECIAL_MQTT_SSL_ENABLE       YES

// PUBLISH 长连接
#define TB_PUBLISH_TEST_MQTT_SERVER              @"172.30.73.235"
#define TB_PUBLISH_TEST_MQTT_SERVER_PORT         10100
#define TB_PUBLISH_TEST_MQTT_SSL_ENABLE          NO
#define TB_PUBLISH_SPECIAL_MQTT_SERVER           @"quote-live.skytigris.cn"
#define TB_PUBLISH_SPECIAL_MQTT_SERVER_PORT      10100
#define TB_PUBLISH_SPECIAL_MQTT_SSL_ENABLE       YES

// crypto-web 数字货币
#define TB_Digital_Currency_HOST @"https://crypto.xiaohu8.com"
#define TB_TEST_Digital_Currency_HOST @"https://qa-crypto.tigerfintech.com"

// depth 美股深度数据
#define TB_TEST_DEPTH_HTTP_SERVER         @"https://hq-depth-dev.tigerfintech.com/"
#define TB_DEPTH_HTTP_SERVER              @"https://hq-depth.xiaohu8.com/"

// econdata-host 宏观经济日历
#define TB_TEST_MACRO_CALENDAR_SERVER       @"https://econdata-dev.ftigers.cc/"
#define TB_MACRO_CALENDAR_SERVER            @"https://econdata.ftfast.com/"

// esop-api
#define TB_TEST_ESOP_SERVER            @"https://esop-api-test.tigerfintech.com/"
#define TB_ESOP_SERVER                 @"https://api.tigeresop.com/"

// esop-web
#define TB_TEST_ESOP_WEB               @"https://esop-test.tigerfintech.com/"
#define TB_ESOP_WEB                    @"https://www.tigeresop.com/"

// future-contract 期货合约
#define TB_TEST_FUTURES_CONTRACT_HTTP_SERVER        @"https://contract-qa.ftigers.cc/"
#define TB_FUTURES_CONTRACT_HTTP_SERVER             @"https://contract-tb.ftfast.com/"

// future-quote 期货行情
#define TB_TEST_FUTURES_QUOTE_HTTP_SERVER         @"https://quotes-qa.ftigers.cc/"
#define TB_FUTURES_QUOTE_HTTP_SERVER              @"https://quotes-tb.ftfast.com/"

// grey-quote 暗盘行情
#define TB_TEST_GREY_MARKET_HTTP_SERVER     @"https://hq-dev.tigerfintech.com/"
#define TB_GREY_MARKET_HTTP_SERVER          @"https://hq-grey.xiaohu8.com/"

// quote 行情
//#define TB_TEST_IDC_HTTP_SERVER         @"https://hq-dev.tigerfintech.com/"
//#define TB_IDC_HTTP_SERVER              @"https://hq.xiaohu8.com/"

#define TB_TEST_QUOTE_PERM_HTTP_SERVER         @"https://hq-perm-dev.tigerfintech.com"
#define TB_QUOTE_PERM_HTTP_SERVER              @"https://hq-perm.xiaohu8.com/"

// watchlist
//#define TB_TEST_WATCH_LIST_SERVER       @"https://hq-dev.tigerfintech.com/"
//#define TB_WATCH_LIST_SERVER            @"https://hq.xiaohu8.com/"

// iap 内购
#define TB_TEST_PAYMENT_DOMAIN          @"https://payment-test.tigerfintech.com"
#define TB_PAYMENT_DOMAIN               @"https://payment.xiaohu8.com"

// omnibus/trade, COMMON和TBNZ牌照的默认域名
#define TB_TEST_OMNIBUS_SERVER          @"https://trade-test.itiger.com"
#define TB_OMNIBUS_SERVER               @"https://trade.xiaohu8.com"

// option
#define TB_OPTION_SERVER                @"https://option.xiaohu8.com/"
#define TB_TEST_OPTION_SERVER           @"https://qa-option.tigerfintech.com/"

// option-depth
#define TB_OPTION_DEPTH_SERVER                @"https://option-depth.xiaohu8.com/"
#define TB_TEST_OPTION_DEPTH_SERVER           @"https://qa-option.tigerfintech.com/"

// option-Geek
#define TB_OPTION_GEEK_SERVER                @"https://optionsgeek.skytigris.cn/"
#define TB_TEST_OPTION_GEEK_SERVER           @"https://stock-option-dev.tigerbrokers.net/"

// NPS域名
#define TB_NPS_PORTAL_SERVER             @"https://www.itiger.com/"
#define TB_TEST_NPS_PORTAL_SERVER        @"https://dev.itiger.com/"

// push 长连接
#define TB_TEST_MQTT_SERVER             @"qa-live.tigerfintech.com"
#define TB_TEST_MQTT_SERVER_PORT        8883
#define TB_TEST_MQTT_SSL_ENABLE         YES

#define TB_SPECIAL_MQTT_SERVER          @"live.xiaohu8.com"
#define TB_SPECIAL_MQTT_SERVER_PORT     8883
#define TB_SPECIAL_MQTT_SSL_ENABLE      YES

// push2 APNs
#define TB_TEST_PUSH2_SERVER            @"https://push-dev.tigerfintech.com/"
#define TB_PUSH2_SERVER                 @"https://push.xiaohu8.com/"

// sensors 神策
#define TB_SENSORS_SERVER   @"https://da.tigerfintech.com/"

// stockgame 炒股大赛
#define TB_TEST_STOCKGAME_SERVER        @"https://stockgame-dev.tigerfintech.com/"
#define TB_STOCKGAME_SERVER             @"https://stockgame.xiaohu8.com/"

// tesseract 香港
#define TB_AUTH_TESSERACT_SERVER             @"https://tesseract-hk.xiaohu8.com/"
#define TB_TEST_AUTH_TESSERACT_SERVER        @"https://dev-tesseract.tigerfintech.com/"

// tesseract-poll 北京
#define TB_TEST_TESSERACT_SERVER        @"https://dev-tesseract.tigerfintech.com/"
#define TB_TESSERACT_SERVER             @"https://tesseract.xiaohu8.com/"

// tip-ranks
#define TB_TIPRANK_SERVER                @"https://tipranks.tigerfintech.com/"

// virtual-trade 模拟账户
#define TB_TEST_VIRTUALTRADE_SERVER     @"https://virtual-trade-test.tigerfintech.com"
#define TB_VIRTUALTRADE_SERVER          @"https://virtual-trade.xiaohu8.com"

// 会员相关
#define TB_MEMBERSHIP_SERVER            @"https://marketing.skytigris.cn/"
#define TB_TEST_MEMEBERSHIP_SERVER      @"https://dev.itiger.com/"


// 会员相关
#define TB_HOME_PAGE_BFF_MOBILE         @"https://bff-mobile.skytigris.cn"
#define TB_TEST_HOME_PAGE_BFF_MOBILE    @"https://bff-mobile-test.qa.tigerbrokers.net"
#define TB_TEST_HOME_PAGE_BFF_MOBILE_QA @"https://bff-mobile-qa.qa.tigerbrokers.net"

// ApiHub
#define TB_BFF_API_HUB_SERVER           @"https://bff-apihub.skytigris.com"
#define TB_TEST_BFF_API_HUB_SERVER      @"https://api-hub-test.qa.tigerbrokers.net"

// FA
#define TB_FA_SERVER         @"https://fa.tigerfintech.com"
#define TB_TEST_FA_SERVER    @"https://fa-test.qa.tigerbrokers.net"
#define TB_QA_FA_SERVER      @"https://fa-qa.qa.tigerbrokers.net"

// 社区相关

// community-host
#define TB_TEST_COMMUNITY_SERVER        @"https://test-frontend-community.laohu8.com/"
#define TB_COMMUNITY_SERVER             @"https://frontend-community.tigerbbs.com/"

// live 直播
#define TB_TEST_IPOLIVE_SERVER        @"https://cms-dev.tigerfintech.com/"
#define TB_IPOLIVE_SERVER             @"https://live.laohu8.com/"

// news2 新闻
#define TB_TEST_NEWS_SERVER             @"https://stock-news-dev.tigerfintech.com/"
#define TB_NEWS_SERVER                  @"https://stock-news.xiaohu8.com/"

// space-pay 空间站提现
#define TB_SPACE_WITHDRAW_HOST              @"https://pay.zhijianfengyi.com/"
#define TB_TEST_SPACE_WITHDRAW_HOST         @"https://pay-dev.zhijianfengyi.com/"

// theme 社区主题
#define TB_TEST_STOCKTHEME_SERVER        @"https://stock-theme-dev.tigerfintech.com/"
#define TB_STOCKTHEME_SERVER             @"https://stock-theme.xiaohu8.com/"

// tigerbrokers-community
#define TB_TEST_TIGER_COMMUNITY_SERVER        @"https://test-community-service.laohu8.com/"
#define TB_TIGER_COMMUNITY_SERVER             @"https://community-service.laohu8.com/"

#define TB_TEST_COMMUNITY_PUSH_SERVER        @"https://community-push-test.laohu8.com/"
#define TB_COMMUNITY_PUSH_SERVER             @"https://stock-community-push.laohu8.com/"

#define TB_TEST_OVERSEA_COMMUNITY_PUSH_SERVER        @"https://community-push.ihuhoo.com/"
#define TB_OVERSEA_COMMUNITY_PUSH_SERVER             @"https://community-push.tradeup.com/"

#define TB_TEST_STREAM_SERVER          @"https://test-ms.tigerfintech.com"
#define TB_STREAM_SERVER               @"https://ms.tigerfintech.com"

// web-community
#define TB_WEB_COMMUNITY_SERVER         @"https://www.laohu8.com/"
#define TB_TEST_WEB_COMMUNITY_SERVER    @"https://dev.laohu8.com/"

// web-ams
#define TB_WEB_AMS_SERVER               @"https://www.tigersecurities.com/"
#define TB_TEST_WEB_AMS_SERVER          @"https://dev.tigersecurities.com/"

// web-ipo
#define TB_WEB_IPO_SERVER               @"https://www.itigerup.com/"
#define TB_TEST_WEB_IPO_SERVER          @"https://dev.itiger.com/"

// 活动营销
#define TB_MARKETING_HOST              @"https://marketing.xiaohu8.com/"
#define TB_TEST_MARKETING_HOST         @"https://test-marketing.tigerfintech.com/"

// 社区视频上传
#define TB_VIDEO_UPLOAD_HOST              @"https://news-service.laohu8.com/"
#define TB_TEST_VIDEO_UPLOAD_HOST         @"https://cms-dev.tigerfintech.com/"

#define TB_LOGAN_SERVER_HOST           @"https://logan.tigerfintech.com"
#define TB_TEST_LOGAN_SERVER_HOST      @"https://logan-test.qa.tigerbrokers.net"
#pragma mark -


// AppUpgrade
#define TB_TEST_APP_UPGRADE_SERVER                          @"https://up-dev.play-analytics.com"
#define TB_APP_UPGRADE_SERVER                               @"https://up.play-analytics.com"

// ipip
#define TB_IPIP_HOST              @"https://geo.skytigris.cn/"
#define TB_TEST_IPIP_HOST         @"https://test-oauth.tigerfintech.com/"

#endif /* TBHostMacroHeader_h */
