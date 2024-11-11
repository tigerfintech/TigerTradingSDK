//
//  TUSAnalyticsEventNames.h
//  StockGlobal
//
//  Created by DepthFirst on 2019/8/9.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#ifndef TUSAnalyticsEventNames_h
#define TUSAnalyticsEventNames_h

#pragma mark - 注册(signup)

/// 注册
/// 在Splash页点击"sign up"
static NSString *const kTUPAnalyticsEventSignup = @"signup_signup";

/// 手机注册
/// 输入手机号和密码后, 点击"sign up"
static NSString *const kTUPAnalyticsEventSignupPhone = @"signup_phone";

/// 邮箱注册
/// 输入邮箱和密码后, 点击"sign up"
static NSString *const kTUPAnalyticsEventSignupEmail = @"signup_email";

/// 输入验证码
/// 输入 手机/邮箱 验证码
static NSString *const kTUPAnalyticsEventSignupVerification = @"signup_verification";

#pragma mark - 开户(openacc)
// 数据校验通过, 能跳到下一步的点击时进行记录

/// 开户
/// 点击 "open account"
static NSString *const kTUPAnalyticsEventOpenAcc = @"openacc_openacc";

/// 国家地区/国籍
static NSString *const kTUPAnalyticsEventOpenAccResidence = @"openacc_residence";

/// 个人基础信息
static NSString *const kTUPAnalyticsEventOpenAccBasic = @"openacc_basic";

/// 居住地
static NSString *const kTUPAnalyticsEventOpenAccHome = @"openacc_home";

/// 婚姻&职业
static NSString *const kTUPAnalyticsEventOpenAccSocial = @"openacc_social";

/// 详细职业
static NSString *const kTUPAnalyticsEventOpenAccCareer = @"openacc_career";

/// 收入来源
static NSString *const kTUPAnalyticsEventOpenAccIncome = @"openacc_income";

/// 其他收入来源
static NSString *const kTUPAnalyticsEventOpenAccOtherIncome = @"openacc_otherincome";

/// 合规信息确认
static NSString *const kTUPAnalyticsEventOpenAccRegulation = @"openacc_regulation";

/// Questionnaire
static NSString *const kTUPAnalyticsEventOpenAccQuestionnaire = @"openacc_questionnaire";

/// 账户类型/交易类型
static NSString *const kTUPAnalyticsEventOpenAccType = @"openacc_type";

/// 交易经验/资产信息
static NSString *const kTUPAnalyticsEventOpenAccPreference = @"openacc_preference";

/// 安全手机号/安全邮箱
static NSString *const kTUPAnalyticsEventOpenAccSecurity = @"openacc_security";

/// 签名
static NSString *const kTUPAnalyticsEventOpenAccSign = @"openacc_sign";

/// 协议
static NSString *const kTUPAnalyticsEventOpenAccAgreements = @"openacc_agreements";

/// 完成开户
static NSString *const kTUPAnalyticsEventOpenAccComplete = @"openacc_complete";

#pragma mark - 行情/自选

/// 导航-自选Tab
static NSString *const kTUPAnalyticsEventNavigationWatchlist = @"navigation_watchlist";

/// 导航-美股Tab
static NSString *const kTUPAnalyticsEventNavigationUSStock = @"navigation_usstock";

/// 导航-港股Tab
static NSString *const kTUPAnalyticsEventNavigationHKStock = @"navigation_hkstock";

/// 导航-Global Tab
static NSString *const kTUPAnalyticsEventNavigationGlobal = @"navigation_global";

/// 自选Tab-长按标的
static NSString *const kTUPAnalyticsEventWatchlistLongpress = @"watchlist_longpress";

/// 自选Tab-自选分组
static NSString *const kTUPAnalyticsEventWatchlistGroup = @"watchlist_group";

#pragma mark - 行情/港股

/// 恒生指数
static NSString *const kTUPAnalyticsEventHKMarketHSI = @"hkstock_hsi";

/// 国企指数
static NSString *const kTUPAnalyticsEventHKMarketHSCEI = @"hkstock_hscei";

/// 红筹指数
static NSString *const kTUPAnalyticsEventHKMarketRed = @"hkstock_red";

/// 港股通
static NSString *const kTUPAnalyticsEventHKMarketConnect = @"hkstock_connect";

/// 主板-港股
static NSString *const kTUPAnalyticsEventHKMarketMain = @"hkstock_main";

/// 港股个股
static NSString *const kTUPAnalyticsEventHKMarketStock = @"hkstock_stock";

#pragma mark - 个股页

/// 进入个股详情页
static NSString *const kTUPAnalyticsEventStockDetailEnter = @"stockdetail_enter";

/// 点击 news 页
static NSString *const kTUPAnalyticsEventStockDetailNews = @"stockdetail_news";

/// 点击 info 页
static NSString *const kTUPAnalyticsEventStockDetailInfo = @"stockdetail_info";

/// 点击 fillings 页
static NSString *const kTUPAnalyticsEventStockDetailFilings = @"stockdetail_filings";

/// 点击 financials 页
static NSString *const kTUPAnalyticsEventStockDetailFinancials = @"stockdetail_financials";

/// 点击 profile 页
static NSString *const kTUPAnalyticsEventStockDetailProfile = @"stockdetail_profile";

/// 点击 analysis 页
static NSString *const kTUPAnalyticsEventStockDetailAnalysis = @"stockdetail_analysis";

/// 点击持仓页
static NSString *const kTUPAnalyticsEventStockDetailHoldings = @"stockdetail_holdings";

/// 点击分享
static NSString *const kTUPAnalyticsEventStockDetailShare = @"stockdetail_share";

/// 点击提醒
static NSString *const kTUPAnalyticsEventStockDetailAlert = @"stockdetail_alert";

/// 点击自选
static NSString *const kTUPAnalyticsEventStockDetailWatchlist = @"stockdetail_watchlist";

/// 点击 trade
static NSString *const kTUPAnalyticsEventStockDetailTrade = @"stockdetail_trade";

/// 点击切换 k 线图标
static NSString *const kTUPAnalyticsEventStockDetailSwitch = @"stockdetail_switch";

/// 点击订单区域展开
static NSString *const kTUPAnalyticsEventStockDetailOrders = @"stockdetail_orders";

/// 点击 打开/收起 tick by tick
static NSString *const kTUPAnalyticsEventStockDetailTick = @"stockdetail_tick";

/// 点击打开全屏 k 线
static NSString *const kTUPAnalyticsEventStockDetailFull = @"stockdetail_full";

/// 点击展开副屏
static NSString *const kTUPAnalyticsEventStockDetailMarket = @"stockdetail_market";

/// 点击展开盘前/盘后
static NSString *const kTUPAnalyticsEventStockDetailPrepost = @"stockdetail_prepost";

#pragma mark - 资讯
/// 点击底部Discover tab 成功进入时记录
static NSString *const kTUPAnalyticsEventDiscoverHomePageEnter = @"discover_enter";

/// 点击discover页顶部任何一个banner成功进入时记录
static NSString *const kTUPAnalyticsEventDiscoverTopBanner = @"discover_banner";

/// 点击breaking news 成功进入时记录
static NSString *const kTUPAnalyticsEventDiscoverBreakingNews = @"discover_breaking";

/// 点击下方任何条目新闻时记录
static NSString *const kTUPAnalyticsEventDiscoverNews = @"discover_news";

/// 点击任何活动 banner 成功时记录
static NSString *const kTUPAnalyticsEventDiscoverActivity = @"discover_activity";

/// 上滑成功打开 upcoming events时记录
static NSString *const kTUPAnalyticsEventDiscoverUpcoming = @"discover_upcoming";

/// 点击 In Focus 成功时记录
static NSString *const kTUPAnalyticsEventDiscoverInFocus = @"discover_inFocus";

/// 点击 Most Active成功时记录
static NSString *const kTUPAnalyticsEventDiscoverMostActive = @"discover_mostActive";

/// 点击calendar 成功时记录
static NSString *const kTUPAnalyticsEventDiscoverCalendar = @"discover_calendar";

/// 点击 screener成功时记录
static NSString *const kTUPAnalyticsEventDiscoverScreener = @"discover_screener";

/// 点击themes成功进入时记录
static NSString *const kTUPAnalyticsEventDiscoverThemes = @"discover_themes";

/// 点击hot map成功进入时记录
static NSString *const kTUPAnalyticsEventHotMap = @"hot_map";

/// 点击右上角“search” icon 成功时记录
static NSString *const kTUPAnalyticsEventDiscoverSearch = @"discover_search";

/// 进入直播显示页
static NSString *const kTUPAnalyticsEventEnterLiveNews = @"discover_livenews_list";

/// 进入直播显示页
static NSString *const kTUPAnalyticsEventHomeLiveNews = @"discover_livenews_home";

/// 内购相关埋点
static NSString *const kTUPApplePay = @"applepay_detail";


#pragma mark - 搜索
static NSString *const kTUPAnalyticsEventSearchRefresh = @"search_refresh";

#pragma mark - flutter 行情购买
static NSString *const kTUPAnalyticsEventMyQuotersRenew = @"myquotes_renew";
static NSString *const kTUPAnalyticsEventMyQuotersSubscribe = @"myquotes_subscribe";

#pragma mark - flutter 开户
static NSString *const kTUPAnalyticsEventOpenaccPersonal = @"openacc_personal";
static NSString *const kTUPAnalyticsEventOpenaccAddress = @"openacc_address";
static NSString *const kTUPAnalyticsEventOpenaccRegulation = @"openacc_regulation";
static NSString *const kTUPAnalyticsEventOpenaccType = @"openacc_type";
static NSString *const kTUPAnalyticsEventOpenaccPreference = @"openacc_preference";
static NSString *const kTUPAnalyticsEventOpenaccSecurity = @"openacc_security";
static NSString *const kTUPAnalyticsEventOpenaccIRS = @"openacc_IRS";
static NSString *const kTUPAnalyticsEventOpenaccComplete = @"openacc_complete";


#endif /* TUSAnalyticsEventNames_h */
