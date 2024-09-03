//
//  Constant.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

//内部域名(用于deeplinking)
#define TB_DOMAIN_TIGERBROKERS_COM @"tigerbrokers.com"
#define TB_DOMAIN_TIGERBROKERS_NET @"tigerbrokers.net"
#define TB_DOMAIN_ITIGER @"itiger.com"
#define TB_DOMAIN_LAOHU8 @"laohu8.com"
#define TB_DOMAIN_TIGER_FINTECH @"tigerfintech.com"
#define TB_DOMAIN_TIGER_BBS @"tigerbbs.com"

// 获取服务域名列表
#define TB_CONFIGURE_SERVER             @"https://cg.play-analytics.com"
#define TB_TEST_CONFIGURE_SERVER        @"https://cg-dev.play-analytics.com"
#define TB_DNHA_SERVER                  @"https://dnha.play-analytics.com"
#define TB_TEST_DNHA_SERVER             @"https://dnha-dev.play-analytics.com"
#define TB_DNHA_SERVER2                 @"https://cg.xiaohu8.com"
#define TB_TEST_DNHA_SERVER2            @"https://cg-dev.xiaohu8.com"

// app新版本检查
#define TB_TEST_APP_UPGRADE_SERVER      @"https://up-dev.play-analytics.com"
#define TB_APP_UPGRADE_SERVER           @"https://up.play-analytics.com"

// oauth
#define TB_TEST_OAUTH_WEB_SERVER        @"https://test-oauth.ihuhoo.com/"
#define TB_OAUTH_WEB_SERVER             @"https://oauth.tradeup.com/"

// oauth tesseract  oauth新接口返回account status 和 用户permission server域名
#define TB_TEST_OAUTH_TESSERACT_SERVER        @"https://tesseract-dev.ihuhoo.com/"
#define TB_OAUTH_TESSERACT_SERVER             @"https://tesseract.tradeup.com/"

// customer
#define TUP_CUSTOMER_SERVER             @"https://customer.tradeup.com/"
#define TUP_TEST_CUSTOMER_SERVER_GZ     @"https://test-customer.tigerfintech.com/"
#define TUP_TEST_CUSTOMER_SERVER_US     @"https://test-customer.ihuhoo.com/"

// 官网等证券无关业务支持项目(Customer Support)
#define TUP_CUSTOMERSUPPORT_SERVER             @"https://customer.itradeup.com/"

// openAccount agreement
#define TUP_OPENACCOUNTAGREEMENT_SERVER             @"https://customer.tradeup.com/support/"
#define TUP_OPENACCOUNTAGREEMENT_TEST_SERVER        @"https://test-customer.ihuhoo.com/support/"

// quote
#define TB_TEST_IDC_HTTP_SERVER         @"https://hq-dev.tigerfintech.com/"
#define TB_IDC_HTTP_SERVER              @"https://hq.tradeup.com/"


#define TB_TEST_QUOTE_PERMISSION_HTTP_SERVER         @"https://hq-perm-dev.ihuhoo.com/"
#define TB_QUOTE_PERMISSION_HTTP_SERVER              @"https://hq-perm.tradeup.com/"

// watchlist
#define TB_TEST_WATCH_LIST_SERVER       @"https://hq-dev.tigerfintech.com/"
#define TB_WATCH_LIST_SERVER            @"https://hq.tradeup.com/"

// option
#define TB_OPTION_SERVER                @"https://option.tradeup.com/"
#define TB_TEST_OPTION_SERVER           @"https://qa-option.tigerfintech.com/"

// 环球账户交易服务
#define TB_TEST_API_HTTP_SERVER         @"https://api-test.ihuhoo.com/"
#define TB_SPECIAl_HTTP_SERVER          @"https://api.tradeup.com/"

// marsco
#define TB_TEST_OMNIBUS_SERVER          @"https://trade-us-test.qa.tigerbrokers.net"
#define TB_OMNIBUS_SERVER               @"https://trade.tradeup.com"


// virtual trade  模拟盘
#define TB_TEST_VIRTUALTRADE_SERVER     @"https://virtual-trade-test.tigerfintech.com"
#define TB_VIRTUALTRADE_SERVER          @"https://virtual-trade.tradeup.com"

// push: 长连接
#define TB_TEST_MQTT_SERVER             @"qa-live.tigerfintech.com"
#define TB_TEST_MQTT_SERVER_PORT        8883
#define TB_TEST_MQTT_SSL_ENABLE         YES

#define TB_SPECIAL_MQTT_SERVER          @"live.tradeup.com"
#define TB_SPECIAL_MQTT_SERVER_PORT     8883
#define TB_SPECIAL_MQTT_SSL_ENABLE      YES

// push2: apns
#define TB_TEST_PUSH2_SERVER            @"https://eps-dev.ihuhoo.com/"
#define TB_PUSH2_SERVER                 @"https://push.tradeup.com/"

// 股价提醒, 在国内版使用和push2一样的server地址, 在美国版有了单独的server地址
#define TB_TEST_PUSH_ALERT_SERVER       @"https://push-dev.tigerfintech.com/"
#define TB_PUSH_ALERT_SERVER            @"https://alert.tradeup.com/"

// ffa
#define TB_TEST_FFA_SERVER  @"https://fa-dev.tigerfintech.com"
#define TB_FFA_SERVER       @"https://fa.tigerfintech.com"

// econdata-host: 宏观经济日历
#define TB_TEST_MACRO_CALENDAR_SERVER       @"https://econdata-dev.ftigers.cc/"
#define TB_MACRO_CALENDAR_SERVER            @"https://econdata.ftfast.com/"

// 两个官网地址, 现在不确定区别是什么
// www
#define TB_TEST_WEB_SERVER              @"https://tradeup-dev.tigerfintech.com/"
#define TB_WEB_SERVER                   @"https://www.tradeup.com/"
// stock
#define TB_TEST_STOCK_WEB_SERVER        @"https://tradeup-dev.tigerfintech.com/"
#define TB_STOCK_WEB_SERVER             @"https://www.tradeup.com/"
// 公司官网, 用于展示协议类网页, 目前没有key对应
#define TUP_TEST_COMPANY_WEB_SERVER     @"https://us-dev.tigerfintech.com/"
#define TUP_COMPANY_WEB_SERVER          @"https://www.tradeup.com/"

// 社区
#define TB_TEST_COMMUNITY_SERVER        @"https://stock-community-frontend.ihuhoo.com/"
#define TB_COMMUNITY_SERVER             @"https://stock-community-frontend.tradeup.com/"

// 新版Host806先不上，暂使用旧Host
//#define TB_TEST_MESSAGE_CENTER_SERVER        @"https://community-service.ihuhoo.com/"
//#define TB_MESSAGE_CENTER_SERVER             @"https://community-service.tradeup.com/"
#define TB_TEST_MESSAGE_CENTER_SERVER        @"https://community-server-us.ihuhoo.com/"
#define TB_MESSAGE_CENTER_SERVER             @"https://community-server-us.tradeup.com/"

// 社区其他, 如web-community, feed.
// web-community
//FEED
#define TB_TEST_COMMUNITY_FEED_SERVER                       @"https://test-frontend-feed.laohu8.com/"
#define TB_COMMUNITY_FEED_SERVER                            @"https://frontend-feed.tigerbbs.com/"

#define TB_MARSC_PNL_TEST_SERVER                       @"https://trade-us-test.qa.tigerbrokers.net"
#define TB_MARSC_PNL_SERVER                            @"https://trade.tradeup.com"

// news2: 新闻; news 未使用
#define TB_TEST_NEWS_SERVER             @"https://stock-news-dev.ihuhoo.com/"
#define TB_NEWS_SERVER                  @"https://stock-news.tradeup.com/"

#define TB_UNIFIED_TEST_NEWS_SERVER     @"https://stock-news-dev.tigerfintech.com/"
#define TB_UNIFIED_NEWS_SERVER          @"https://stock-news.laohu8.com/"

#define TB_TEST_NEWS_LIVE_SERVER        @"https://cms-us-dev.ihuhoo.com/"
#define TB_NEWS_LIVE_SERVER             @"https://live-stream.tradeup.com/"

#define TUP_TEST_STREAM_SERVER          @"https://test-ms-public.ihuhoo.com"
#define TUP_STREAM_SERVER               @"https://ms-public.tradeup.com"

// 官网域名, 用于清理cache和cookie, 退出登录时清理或在webview主动调用
#define TB_SITE_NAME                                        @"itiger.com"
#define TB_TEST_SITE_NAME                                   @"itiger.com"


#define TB_ACTIVITY_SERVER              @"https://activity.tradeup.com/"
#define TB_TEST_ACTIVITY_SERVER         @"https://activity-test.ihuhoo.com/"


#define TB_PERSONAL_CENTER_ACTIVITY__SERVER                   @"https://activity.tradeup.com/driver/"
#define TB_TEST_PERSONAL_CENTER_ACTIVITY__SERVER              @"https://activity-test.ihuhoo.com/driver/"

#define TB_LOGAN_SERVER_HOST           @"https://logan.tradeup.com"
#define TB_TEST_LOGAN_SERVER_HOST      @"https://logan.tradeup.com"

// live 直播
#define TB_TEST_IPOLIVE_SERVER        @"https://cms-dev.tigerfintech.com/"
#define TB_IPOLIVE_SERVER             @"https://live.laohu8.com/"

// tigerbrokers-community
#define TB_TEST_TIGER_COMMUNITY_SERVER        @"https://community-service.ihuhoo.com/"
#define TB_TIGER_COMMUNITY_SERVER             @"https://community-service.tradeup.com/"

// college 基金超市-基金学院
#define TB_FUND_LESSON_HOST                 @"https://college.tigerbbs.com/"
#define TB_TEST_FUND_LESSON_HOST            @"https://cms-dev.tigerfintech.com/"

// api-track
#define TB_TRACK_TRADE_UP_BUSINESS_HOST_TEST @"https://mnt-report.qa.tigerbrokers.net"
#define TB_TRACK_TRADE_UP_BUSINESS_HOST_ONLINE @"https://mnt-report.skytigris.cn"

// backend-activity 活动
#define TB_BACKEND_ACTIVITY_HOST                    @"https://www.itiger.com/"
#define TB_TEST_BACKEND_ACTIVITY_HOST               @"https://dev.itiger.com/"

// space-pay 空间站提现
#define TB_SPACE_WITHDRAW_HOST              @"https://pay.zhijianfengyi.com/"
#define TB_TEST_SPACE_WITHDRAW_HOST         @"https://pay-dev.zhijianfengyi.com/"

// web-community
#define TB_WEB_COMMUNITY_SERVER         @"https://ttm.financial/"
#define TB_TEST_WEB_COMMUNITY_SERVER    @"https://dev.ttm.financial/"

// 会员相关
#define TB_MEMBERSHIP_SERVER            @"https://marketing.skytigris.cn/"
#define TB_TEST_MEMEBERSHIP_SERVER      @"https://dev.itiger.com/"

// 会员相关
#define TB_HOME_PAGE_BFF_MOBILE         @"https://bff-mobile.tradeup.com"
#define TB_TEST_HOME_PAGE_BFF_MOBILE    @"https://bff-mobile-test-qa.ihuhoo.com"

// ApiHub
#define TB_BFF_API_HUB_SERVER           @"https://bff-apihub.skytigris.com"
#define TB_TEST_BFF_API_HUB_SERVER      @"https://api-hub-test.qa.tigerbrokers.net"

// 社区视频上传
#define TB_VIDEO_UPLOAD_HOST              @"https://news-service.laohu8.com/"
#define TB_TEST_VIDEO_UPLOAD_HOST         @"https://cms-dev.tigerfintech.com/"
