//
//  TBHostHeader.h
//  TBHostManager
//
//  Created by JustLee on 2020/6/4.
//  Copyright © 2020 JustLee. All rights reserved.
//

#ifndef TBHostHeader_h
#define TBHostHeader_h

#import <TBHostManager/TBServerHostManager.h>
#import <TBHostManager/TBQAXManager.h>

#pragma mark - 服务器地址在user default的key

// 声明 inline 方法
static inline NSString *processedTestQAXServerKey(NSString *key) {
    if ([TBServerHostManager sharedInstance].useQAServer) {
        if (TextValid([TBQAXManager fetchSelectedQAXItem])) {
            // 已经设置了对应的qa item
            NSString *selectedQA = [TBQAXManager fetchSelectedQAXItem];
            key = [selectedQA stringByAppendingFormat:@"_%@", key];
            return key;
        }
        else {
            // 未设置qa item，使用本地qa 默认的key是localqa
            NSString *selectedQA = @"qa-local";
            key = [selectedQA stringByAppendingFormat:@"_%@", key];
            return key;
        }
    }
    else {
        return key;
    }
}

// backend-activity
static NSString *BACKEND_ACTIVITY_SERVER_KEY        = @"backend_activity_server";
static inline NSString *TEST_BACKEND_ACTIVITY_SERVER_KEY(void) {
    NSString *key = @"test_backend_activity_server";
    return processedTestQAXServerKey(key);
}

// bi-stream
static NSString *BI_STREAM_SERVER_KEY       = @"bi_stream_server";
static inline NSString *TEST_BI_STREAM_SERVER_KEY(void) {
    NSString *key = @"test_bi_stream_server";
    return processedTestQAXServerKey(key);
}

// fund-business
static NSString *FUND_BUSINESS_SERVER_KEY       = @"fund_business_server";
static inline NSString *TEST_FUND_BUSINESS_SERVER_KEY(void) {
    NSString *key = @"test_fund_business_server";
    return processedTestQAXServerKey(key);
}

// crypto-push 数字货币长连接
static NSString *CRYPTO_PUST_SERVER_KEY                 = @"crypto_push_server";
static inline NSString *CRYPTO_TEST_PUSH_SERVER_KEY(void) {
    NSString *key = @"crypto_test_push_server";
    return processedTestQAXServerKey(key);
}
static NSString *CRYPTO_PUSH_SERVER_PORT_KEY            = @"crypto_push_server_port";
static inline NSString *CRYPTO_TEST_PUSH_SERVER_PORT_KEY(void) {
    NSString *key = @"crypto_test_push_server_port";
    return processedTestQAXServerKey(key);
}
static NSString *CRYPTO_PUSH_SERVER_PROTOCOL_KEY        = @"crypto_push_server_protocol";
static inline NSString *CRYPTO_TEST_PUSH_SERVER_PROTOCOL_KEY(void) {
    NSString *key = @"crypto_test_push_server_protocol";
    return processedTestQAXServerKey(key);
}

// publish-push 长连接
static NSString *PUBLISH_MQTT_PUSH_SERVER_KEY                 = @"publish_push_server";

static inline NSString *PUBLISH_MQTT_TEST_PUSH_SERVER_KEY(void) {
    NSString *key = @"publish_test_push_server";
    return processedTestQAXServerKey(key);
}


static NSString *PUBLISH_MQTT_PUSH_SERVER_PORT_KEY            = @"publish_push_server_port";
static inline NSString *PUBLISH_MQTT_TEST_PUSH_SERVER_PORT_KEY(void) {
    NSString *key = @"publish_test_push_server_port";
    return processedTestQAXServerKey(key);
}

static NSString *PUBLISH_MQTT_PUSH_SERVER_PROTOCOL_KEY        = @"publish_push_server_protocol";
static inline NSString *PUBLISH_MQTT_TEST_PUSH_SERVER_PROTOCOL_KEY(void) {
    NSString *key = @"publish_test_push_server_protocol";
    return processedTestQAXServerKey(key);
}

static NSString *PUBLISH_MQTT_PUSH_SERVER_ENABLE_KEY        = @"publish_push_server_enable";
static inline NSString *PUBLISH_MQTT_TEST_PUSH_SERVER_ENABLE_KEY(void) {
    NSString *key = @"publish_test_push_server_enable";
    return processedTestQAXServerKey(key);
}

// crypto-web 数字货币
static NSString *DIGITAL_CURRENCY_API_SERVER_KEY        = @"crypto_web";
static inline NSString *TEST_DIGITAL_CURRENCY_API_SERVER_KEY(void) {
    NSString *key = @"test_crypto_web";
    return processedTestQAXServerKey(key);
}

// depth 美股深度数据
static NSString *DEPTH_QUOTE_SERVER_KEY         = @"depth";
static inline NSString *TEST_DEPTH_QUOTE_SERVER_KEY(void) {
    NSString *key = @"test_depth";
    return processedTestQAXServerKey(key);
}
// econdata-host 宏观经济日历
static NSString *MACRO_CALENDAR_SERVER_KEY      = @"macroCalendar_server";
static inline NSString *TEST_MACRO_CALENDAR_SERVER_KEY(void) {
    NSString *key = @"test_macroCalendar_server";
    return processedTestQAXServerKey(key);
}

// esop-api
static NSString *ESOP_SERVER_KEY            = @"esop_server";
static inline NSString *TEST_ESOP_SERVER_KEY(void) {
    NSString *key = @"test_esop_server";
    return processedTestQAXServerKey(key);
}

// esop-web
static NSString *ESOP_WEB_KEY                                                    = @"esop_web";
static inline NSString *TEST_ESOP_WEB_KEY(void) {
    NSString *key = @"test_esop_web";
    return processedTestQAXServerKey(key);
}
// future-contract
static NSString *FUTURES_CONTRACT_SERVER_KEY        = @"futures_contract_server";
static inline NSString *TEST_FUTURES_CONTRACT_SERVER_KEY(void) {
    NSString *key = @"test_futures_contract_server";
    return processedTestQAXServerKey(key);
}

// future-quote
static NSString *FUTURES_QUOTE_SERVER_KEY           = @"futures_quote_server";
static inline NSString *TEST_FUTURES_QUOTE_SERVER_KEY(void) {
    NSString *key = @"test_futures_quote_server";
    return processedTestQAXServerKey(key);
}

// grey-quote 暗盘行情
static NSString *GREY_QUOTE_SERVER_KEY      = @"grey-quote";
static inline NSString *TEST_GREY_QUOTE_SERVER_KEY(void) {
    NSString *key = @"test_grey-quote";
    return processedTestQAXServerKey(key);
}

// hqlist
static NSString *HQ_SERVER_LIST_KEY                                                         = @"hq_server_list";
static inline NSString *TEST_HQ_SERVER_LIST_KEY(void) {
    NSString *key = @"test_hq_server_list";
    return processedTestQAXServerKey(key);
}

// quote
static NSString *QUOTE_SERVER_KEY                                                             = @"quote_server";
static inline NSString *TEST_QUOTE_SERVER_KEY(void) {
    NSString *key = @"test_quote_server";
    return processedTestQAXServerKey(key);
}

static NSString *QUOTE_PERM_SERVER_KEY                                                             = @"quote_perm_server";
static inline NSString *TEST_QUOTE_PERM_SERVER_KEY(void) {
    NSString *key = @"test_quote_perm_server";
    return processedTestQAXServerKey(key);
}

// watchlist
static NSString *WATCH_LIST_SERVER_KEY                                                        = @"watchlist_server";
static inline NSString *TEST_WATCH_LIST_SERVER_KEY(void) {
    NSString *key = @"test_watchlist_server";
    return processedTestQAXServerKey(key);
}

// iap
static NSString *IN_APP_PURCHASE_SERVER_KEY         = @"in_app_purchase_server";
static inline NSString *TEST_IN_APP_PURCHASE_SERVER_KEY(void) {
    NSString *key = @"test_in_app_purchase_server";
    return processedTestQAXServerKey(key);
}

// omnibuslist
static NSString *OMNIBUS_SERVER_LIST_KEY                                                     = @"omnibus_server_list";
static inline NSString *TEST_OMNIBUS_SERVER_LIST_KEY(void) {
    NSString *key = @"test_omnibus_server_list";
    return processedTestQAXServerKey(key);
}

// option
static NSString *OPTION_SERVER_KEY                                                            = @"option_server";
static inline NSString *TEST_OPTION_SERVER_KEY(void) {
    NSString *key = @"test_option_server";
    return processedTestQAXServerKey(key);
}

// optionlist
static NSString *OPTION_SERVER_LIST_KEY                                                            = @"option_server_list";
static inline NSString *TEST_OPTION_SERVER_LIST_KEY(void) {
    NSString *key = @"test_option_server_list";
    return processedTestQAXServerKey(key);
}

// optiondepth
static NSString *OPTION_SERVER_DEPTH_KEY                                                            = @"option_server_depth";
static inline NSString *TEST_OPTION_SERVER_DEPTH_KEY(void) {
    NSString *key = @"test_option_server_depth";
    return processedTestQAXServerKey(key);
}

// optionGeek
static NSString *OPTION_SERVER_GEEK_KEY                                                            = @"option_server_geek";
static inline NSString *TEST_OPTION_SERVER_GEEK_KEY(void) {
    NSString *key = @"test_option_server_geek";
    return processedTestQAXServerKey(key);
}

// NPS
static NSString *NPS_PORTAL_SERVER_DICT_KEY         = @"nps_portal_server_dict";
static inline NSString *TEST_NPS_PORTAL_SERVER_DICT_KEY(void) {
    NSString *key = @"nps_test_portal_server_dict";
    return processedTestQAXServerKey(key);
}

// push
static NSString *PUST_SERVER_KEY                                                              = @"push_server";
static inline NSString *TEST_PUSH_SERVER_KEY(void) {
    NSString *key = @"test_push_server";
    return processedTestQAXServerKey(key);
}

static NSString *PUSH_SERVER_PORT_KEY                                                         = @"push_server_port";
static inline NSString *TEST_PUSH_SERVER_PORT_KEY(void) {
    NSString *key = @"test_push_server_port";
    return processedTestQAXServerKey(key);
}

static NSString *PUSH_SERVER_PROTOCOL_KEY                                                     = @"push_server_protocol";
static inline NSString *TEST_PUSH_SERVER_PROTOCOL_KEY(void) {
    NSString *key = @"test_push_server_protocol";
    return processedTestQAXServerKey(key);
}

// push2
static NSString *PUSH2_SERVER_KEY                                                             = @"push2_server";
static inline NSString *TEST_PUSH2_SERVER_KEY(void) {
    NSString *key = @"test_push2_server";
    return processedTestQAXServerKey(key);
}
// eps
static NSString *EPS_SERVER_KEY                                                             = @"eps_server";
static inline NSString *TEST_EPS_SERVER_KEY(void) {
    NSString *key = @"test_eps_server";
    return processedTestQAXServerKey(key);
}

// sensors 神策
static NSString *SENSORS_SERVER_KEY         = @"sensors_server";

// stockgame 炒股大赛
static NSString *STOCKGAME_SERVER_KEY                                                         = @"stockgame_server";
static inline NSString *TEST_STOCKGAME_SERVER_KEY(void) {
    NSString *key = @"test_stockgame_server";
    return processedTestQAXServerKey(key);
}

// tesseract 香港
static NSString *TESSERACT_HK_SERVER_KEY                                                      = @"tesseract_hk_server";
static inline NSString *TEST_TESSERACT_HK_SERVER_KEY(void) {
    NSString *key = @"test_tesseract_hk_server";
    return processedTestQAXServerKey(key);
}

// tesseract-poll 北京
static NSString *TESSERACT_SERVER_KEY                                                         = @"tesseract_server";
static inline NSString *TEST_TESSERACT_SERVER_KEY(void) {
    NSString *key = @"test_tesseract_server";
    return processedTestQAXServerKey(key);
}

// tip-ranks
static NSString *TIPRANK_SERVER_KEY                                                               = @"tiprank_server";

// trade
static NSString *TRADE_SERVER_DICT_KEY      = @"trade_server_dict";
static inline NSString *TEST_TRADE_SERVER_DICT_KEY(void) {
    NSString *key = @"test_trade_server_dict";
    return processedTestQAXServerKey(key);
}

static NSString *TRADE_TBNZ_SERVER_KEY              = @"trade_tbnz_server";
static NSString *TEST_TRADE_TBNZ_SERVER_KEY         = @"test_trade_tbnz_server";

// virtual-trade 模拟账户
static NSString * VIRTUALTRADE_SERVER_KEY                                                     = @"virtualtrade_server";
static inline NSString *TEST_VIRTUALTRADE_SERVER_KEY(void) {
    NSString *key = @"test_virtualtrade_server";
    return processedTestQAXServerKey(key);
}

// 社区域名

// community-host
static NSString *COMMUNITY_SERVER_KEY                   = @"community_server";
static NSString *TEST_COMMUNITY_SERVER_KEY              = @"test_community_server";

// 升级为字典类型的社区域名 本地存储key
static NSString *COMMUNITY_LIST_SERVER_KEY                   = @"community_list_server";
static inline NSString *TEST_COMMUNITY_LIST_SERVER_KEY(void) {
    NSString *key = @"test_community_list_server";
    return processedTestQAXServerKey(key);
}

// community-broadcast 未使用
static NSString *COMMUNITY_BROADCAST_SERVER_KEY         = @"community_broadcast_server";
static NSString *TEST_COMMUNITY_BROADCAST_SERVER_KEY    = @"test_community_broadcast_server";

// live
static NSString *IPOLIVE_SERVER_KEY                     = @"ipolive_server";
static NSString *TEST_IPOLIVE_SERVER_KEY                = @"test_ipolive_server";

// 数据返回类型为字典类型, 本地存储key
static NSString *IPOLIVE_LIST_SERVER_KEY                     = @"ipolive_list_server";
static inline NSString *TEST_IPOLIVE_LIST_SERVER_KEY(void) {
    NSString *key = @"test_ipolive_list_server";
    return processedTestQAXServerKey(key);
}

// news2 新闻
static NSString *NEWS_SERVER_KEY                        = @"news_server";
static NSString *TEST_NEWS_SERVER_KEY                   = @"test_news_server";

// 数据返回类型升级为字典类型, 本地存储key
static NSString *NEWS_LIST_SERVER_KEY                        = @"news_list_server";
static inline NSString *TEST_NEWS_LIST_SERVER_KEY(void) {
    NSString *key = @"test_news_list_server";
    return processedTestQAXServerKey(key);
}

// space-pay
static NSString *SPACE_PAY_SERVER_KEY                   = @"space_pay_server";
static inline NSString *TEST_SPACE_PAY_SERVER_KEY(void) {
    NSString *key = @"test_space_pay_server";
    return processedTestQAXServerKey(key);
}

// marketing
static NSString *MARKETING_SERVER_KEY                   = @"marketing_server";
static inline NSString *TEST_MARKETING_SERVER_KEY(void) {
    NSString *key = @"test_marketing_server";
    return processedTestQAXServerKey(key);
}

static NSString *VIDEO_UPLOAD_SERVER_KEY                = @"video_upload_server";
static inline NSString *TEST_VIDEO_UPLOAD_SERVER_KEY(void) {
    NSString *key = @"test_video_upload_server";
    return processedTestQAXServerKey(key);
}

// theme 社区主题
static NSString *STOCKTHEME_SERVER_KEY                  = @"stocktheme_server";
static inline NSString *TEST_STOCKTHEME_SERVER_KEY(void) {
    NSString *key = @"test_stocktheme_server";
    return processedTestQAXServerKey(key);
}

// tigerbrokers-community
static NSString *TIGER_COMMUNITY_SERVER_KEY             = @"tiger_community_server";
static NSString *TEST_TIGER_COMMUNITY_SERVER_KEY        = @"test_tiger_community_server";

// 数据返回类型为字典的 本地存储key
static NSString *TIGER_COMMUNITY_LIST_SERVER_KEY             = @"tiger_community_list_server";
static inline NSString *TEST_TIGER_COMMUNITY_LIST_SERVER_KEY(void) {
    NSString *key = @"test_tiger_community_list_server";
    return processedTestQAXServerKey(key);
}

// 新加的community-push本地存储key 数据返回类型为dictionary
static NSString *COMMUNITY_PUSH_SERVER_KEY             = @"community_push_server";
static inline NSString *TEST_COMMUNITY_PUSH_SERVER_KEY(void) {
    NSString *key = @"test_community_push_server";
    return processedTestQAXServerKey(key);
}

// web-community
static NSString * WEB_COMMUNITY_SERVER_KEY              = @"web_community_server";
static NSString * TEST_WEB_COMMUNITY_SERVER_KEY         = @"test_web_community_server";

// web-community-list 对应新增的数据类型为字典类型
static NSString * WEB_COMMUNITY_LIST_SERVER_KEY              = @"web_community_list_server";
static inline NSString *TEST_WEB_COMMUNITY_LIST_SERVER_KEY(void) {
    NSString *key = @"test_web_community_list_server";
    return processedTestQAXServerKey(key);
}

// web-ams
static NSString * WEB_AMS_SERVER_KEY                    = @"web_ams_server";
static inline NSString *TEST_WEB_AMS_SERVER_KEY(void) {
    NSString *key = @"test_web_ams_server";
    return processedTestQAXServerKey(key);
}

// web-ipo
static NSString * WEB_IPO_SERVER_DICT_KEY                    = @"web_ipo_server_dict";
static inline NSString *TEST_WEB_IPO_SERVER_DICT_KEY(void) {
    NSString *key = @"test_web_ipo_server_dict";
    return processedTestQAXServerKey(key);
}

// ipip
static NSString *IPIP_SERVER_KEY                   = @"ipip_server";
static inline NSString *TEST_IPIP_SERVER_KEY(void) {
    NSString *key = @"test_ipip_server";
    return processedTestQAXServerKey(key);
}

#pragma mark - 内部域名集合的 NSUserDefaults key
static NSString * TIGER_HOSTS_KEY       = @"tiger_hosts";
static inline NSString *TEST_TIGER_HOSTS_KEY(void) {
    NSString *key = @"test_tiger_hosts";
    return processedTestQAXServerKey(key);
}
#endif /* TBHostHeader_h */

