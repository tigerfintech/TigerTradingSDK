//
//  TBUserDefaultConstantString.h
//  TBToolsKit
//
//  Created by zhengzhiwen on 2021/6/9.
//

#ifndef TBUserDefaultConstantString_h
#define TBUserDefaultConstantString_h

/// 加盟商client id 存储
static NSString *USER_DEFAULT_KEY_CLIENT_ID                                                   = @"userDefaultKeyUserInfoClientId";
static NSString *TRADE_TOKEN_KEY                                                              = @"trade_token";
static NSString *ACCESS_TOKEN_KEY                                                             = @"access_token";
static NSString *REFRESH_TOKEN_KEY                                                            = @"refresh_token";
static NSString *AUTHORIZATION_KEY                                                            = @"Authorization";

static NSString *TOKEN_TYPE_KEY                                                               = @"token_type";

static NSString *UUID_KEY                                                                     = @"uuid";
static NSString *OPENID_KEY                                                                     = @"open_id";


#pragma mark --- hk

static NSString *USER_DEFAULT_ALLOW_AUDIO_NOTIFICATION                                        = @"userDefaultKeyAllowAudioNotification";        //phone绑定.
static NSString *USER_DEFAULT_ALLOW_EXPONENTITEM_NOTIFICATION                                 = @"userDefaultKeyAllowExponentitemNotification";//phone绑定.
static NSString *USER_NEW_STOCK_PRIORITY                                                      = @"userNewStockPriority";                         //phone绑定.
static NSString *USER_DEFAULT_STOCK_PRIORITY                                                  = @"userDefaultStockPriority";                    // 股票优先级

static NSString *USER_DEFAULT_STOCK_OPENID_KEY                                                                     = @"tigerbroker_ocid_open_id";


static NSString *USER_DEFAULT_KEY_NUMBER_THOUSAND_DISPLAY                                    = @"userDefaultKeyNumberThousandDisplay";
static NSString *USER_DEFAULT_KEY_ORDER_ALERT_VIBRATE = @"userDefaultOrderAlertVibrate";//为了跟Andorid适配添加
static NSString *USER_DEFAULT_KEY_POSITION_COST_TYPE = @"userDefaultKeyPositionCostType";

static NSString *USER_DEFAULT_KEY_PUSH_SETTING                                                = @"userDefaultKeyPushSetting";                    // phone 绑定.

static NSString *USER_DEFAULT_KEY_NEWGUIDE                                                    = @"userDefaultKeyNewGuide";                       // 新手引导是否显示

static NSString *USER_DEFAULT_KEY_NEWERWELFARE                                                    = @"userDefaultKeyNewerWelfare";                      // 新人福利弹窗是否已经展示


static NSString *USER_DEFAULT_KEY_SYSTEM_USERAGENT
= @"system_userAgent";

static NSString *const USER_DEFAULT_KEY_STOCK_FROM_NEW_FUNCTION = @"USER_DEFAULT_KEY_STOCK_FROM_NEW_FUNCTION";


static NSString *kNOTIFICATION_KEY_TABBAR_LOAD                                               = @"kNOTIFICATION_KEY_TABBAR_LOAD";

// 中信证券电话+客服时间

//用于缓存最后一条未读消息时间
static NSString * kLastUnreadMessageTime = @"kLastUnreadMessageTime";
static NSString * kShowSearchHintView = @"kShowSearchHintView";
//static NSString * USER_DEFAULT_ALLOW_AUDIO_NOTIFICATION       = @"userDefaultKeyAllowAudioNotification";        //phone绑定.

static NSString *USER_DEFAULT_KEY_STOCK_FUNDAMENTAL_FOLD
= @"userDefaultKeyHKStockFundamentalFold"; /// 详情页基本面信息折叠收起

static NSString * const USER_DEFAULT_KEY_AVG_COST_LINE_DETAIL_DISPLAY = @"userDefaultKeyAvgCostLineDetailDisplay"; // 是否显示持仓线
static NSString *const USER_DEFAULT_KEY_STOCK_DETAIL_SETTING = @"userDefaultKeyStockDetailSetting";
static NSString *const USER_DEFAULT_KEY_SHOW_JUMP_AREA = @"userDefaultKeyShowJumpArea";
static NSString * const USER_DEFAULT_KEY_KLINE_CHART_HEIGHT = @"userDefaultKeyKlineChartHeight"; // k线图高度设置
static NSString * const USER_DEFAULT_KEY_ASK_BID_CHART_SETTING = @"userDefaultKeyAskBidChartSetting"; // 买卖盘对比图是否展示设置
static NSString * const USER_DEFAULT_KEY_LEVEL_DETAIL_DISPLAY = @"userDefaultKeylevelDetailDisplay"; // 明细五档十档是否显示设置
static NSString * const USER_DEFAULT_KEY_Draw_LINE_DETAIL_DISPLAY = @"userDefaultKeyDrawLineDetailDisplay"; // 是否显示画线
static NSString *const USER_DEFAULT_KEY_SHOW_ASK_BID_BROKER = @"userDefaultKeyShowAskBidBroker"; // 是否展示买卖席位
static NSString * const kUSER_DEFAULT_KEY_DRAW_LASTESTPRICE_LINE_DISPLAY = @"userDefaultKeyDrawLastestPriceLineDetailDisplay"; // 是否显示现价线

static NSString *const USER_DEFAULT_KEY_HOME_PAGE_TRADE_ASSETS_VISIBLE_STATUS = @"USER_DEFAULT_KEY_HOME_PAGE_TRADE_ASSETS_VISIBLE_STATUS";

static NSString *const USER_DEFAULT_KEY_STOCK_DETAIL_OPENACCOUNT_GUIDE_TIME = @"userDefaultKeyStockDetailGuideCloseTime";


#pragma mark 自定义指标
/**
 *  要显示的主指标. 是一个字符串的数组, 每个元素是指标的key, 默认 @[@"MA", @"BOLL", @"EMA"].
 */
static NSString * const USER_DEFAULT_KEY_KLINE_MAJOR_INDICATORS = @"userDefaultKeyKlineMajorIndicators";
/**
 *  要显示的副指标. 是一个字符串的数组, 每个元素是指标的key, 默认 @[@"MACD", @"KDJ", @"RSI", @"ARBR", @"OBV", @"WR", @"EMV", @"DMA"].
 */
static NSString * const USER_DEFAULT_KEY_KLINE_MINOR_INDICATORS = @"userDefaultKeyKlineMinorIndicators";
/**
 *  存储各指标参数的字典.
 */
static NSString * const USER_DEFAULT_KEY_KLINE_INDICATORS_PARAMS_DICT = @"userDefaultKeyKlineIndicatorsParamsDict";
// 存储各指标参数字典model
static NSString *const USER_DEFAULT_KEY_LINE_INDICATOR_PARAMS_DICT = @"userDefaultKeyLineIndicatorParamsDict";

static NSString *USER_DEFAULT_KEY_STOCK_DETAIL_KLINE_RIGHT_TAB_INDEX = @"userDefaultKeyStockDetailKlineRightTabIndex";

// 神奇九转提示次数
static NSString *USER_DEFAULT_KEY_MAGIC_POINT_PROMPT_TIME = @"userDefaultKeyMagicPointPromptTime";
// 是否开启神奇九转
static NSString *USER_DEFAULT_KEY_MAGIC_POINT_ENABLE = @"userDefaultKeyMagicPointEnable";

// 是否开启趋势线
static NSString *USER_DEFAULT_KEY_TREND_LINE_ENABLE = @"userDefaultKeyTrendLineEnable";

static NSString *USER_DEFAULT_KEY_KLINE_INDICATOR_ARRAY = @"user_default_key_kline_indicator_array";

//行情设置-名称代码互换
static NSString * USER_DEFAULT_KEY_HANGQING_ITEM_SYMBOL_FIRST                                      = @"userDefaultKeyHangqingItemSymbolFirst";

static NSString * kNOTIFICATION_KEY_SYMBOL_FIRST_CHANGED = @"kNOTIFICATION_KEY_SYMBOL_FIRST_CHANGED";

/// 交易成交后，添加自选成功通知
static NSString * NOTIFICATION_KEY_TRADESUCCESS_ADD_WATCH_LIST = @"NOTIFICATION_KEY_TRADESUCCESS_ADD_WATCH_LIST";

static NSString *USER_DEFAULT_STOCK_SHARE_LOGO_LINK = @"stock_share_logo_link";

static NSString *USER_DEFAULT_KEY_CASH_ASSETS_CURRENCY = @"cashAssetsCurrency";

static NSString *USER_DEFAULT_KEY_CUSTOM_LAST_FAV_NEWS_TAB                                    = @"userDefaultKeyCustomLastFavNewsTab";           // 记录用户上次在咨询tab停留的index, 用户相关.

static NSString *NOTIFICATION_KEY_NEW_ACTIVITY                                                = @"pushNewActivityAction";

static NSString * USER_DEFAULT_KEY_IS_SWITCH_THEME_WITH_SYSTEM_SHOWN = @"userDefaultKeyIsSwitchThemeWithSystemShown";

static NSString *NOTIFICATION_KEY_DOUBLE_TAP_TABBAR_ITEM                                      = @"doubleTapTabbarItem";

//点击全局截图分享
static NSString *NOTIFICATION_SCREENSHOT_WILL_APPEAR                                          = @"NOTIFICATION_SCREENSHOT_WILL_APPEAR";

static NSString *USER_DEFAULT_LAST_MESSAGEID                                                  = @"userDefaultLastMessageID";                    //phone绑定.

static NSString *const NOTIFICATION_KEY_LOGOUT                                                = @"logoutAction";

// 当社区tab红点有更新时 通知社区消息助手红点更新
static NSString *NOTIFICATION_KEY_UPDATE_COMMUNITY_MESSAGEVIEW = @"NOTIFICATION_KEY_UPDATE_COMMUNITY_MESSAGEVIEW";

//设置信息变化通知
static NSString *NOTIFICATION_USER_CHANGE_CONFIG                                             = @"NOTIFICATION_USER_CHANGE_CONFIG";

static NSString *NOTIFICATION_KEY_HIDDEN_KEYBOARD = @"hiddenKeyBoardNotification";

static NSString *NOTIFICATION_KEY_SERVER_SETTING_CHANGED                                      = @"serverSettingChangedAction";

static NSString *NOTIFICATION_KEY_US_MARKET_OPENED                                            = @"USMarketOpenedAction";

static NSString *NOTIFICATION_KEY_GET_ACTIVITY_SUCCESS = @"get_activity_success"; // 活动领取成功

// 将要切换服务器地址时的通知
static NSString *NOTIFICATION_KEY_SERVER_WILL_CHANGE_AUTOMATIC = @"serverWillChangeAutomatic";

static NSString *NOTIFICATION_KEY_ANALYZEVIEW_REFRESH = @"analyzeViewRefreshNoti";

static NSString *NOTIFICATION_KEY_ANALYZEVIEW_ENDREFRESH = @"analyzeViewEndRefreshNoti";

// 消息中心
static NSString *NOTIFICATION_KEY_WATCHLIST_MESSAGE = @"NOTIFICATION_KEY_WATCHLIST_MESSAGE"; ///< 自选页消息中心同步

static NSString *NOTIFICATION_KEY_NEWSPAPER_UPDATE = @"NOTIFICATION_KEY_NEWSPAPER_UPDATE"; ///< 自选页早晚报同步
static NSString *NOTIFICATION_KEY_NEWSPAPER_READ = @"NOTIFICATION_KEY_NEWSPAPER_READ"; ///< 退出消息中心页需要刷新早晚报

static NSString *NOTIFICATION_KEY_LOG_LEVEL = @"NOTIFICATION_KEY_LOG_LEVEL";

static NSString *NOTIFICATION_KEY_DID_RECEIVE_REMOTE_NOTIFICATION = @"didReceiveRemoteNotification";

static NSString *USER_DEFAULT_KEY_AUTO_LOCK_SCREEN = @"userDefaultKeyAutoLockScreen";

// 期权推荐banner
static NSString *USER_DEFAULT_KEY_OPTIONS_RECOMMENDED_PRODUCT_BANNER = @"userDefaultKeyOptionsRecommendedProductBanner";

static NSString *NOTIFICATION_KEY_OPTIONS_RECOMMEND_BANNER_HIDDEN = @"NOTIFICATION_KEY_OPTIONS_RECOMMEND_BANNER_HIDDEN";


static NSString * const USER_DEFAULT_KEY_LIMITED_QUOTE_PROMPT = @"userDefaultKeyLimitedQuotePrompt";


static NSString * const kUSER_DEFAULT_KEY_FRACTIONAL_SHARE_OPEN_ALERT_CLOSED = @"userDefaultKeyFractionalShareOpenAlertClosed";

static NSString * kNOTIFICATION_KEY_CURRENCY_CHANGED = @"kNOTIFICATION_KEY_CURRENCY_CHANGED";

static NSString * const kUSER_DEFAULT_KEY_CURRENT_APP_VERSION_IS_NEW_INSTALL = @"kCurrentAppVersionIsNewInstall";// app当前版本是不是新安装(YES：新安装。NO：更新版本而来）

static NSString * const kUSER_DEFAULT_KEY_IS_NEW_USER_FOR_PERSON_CENTER = @"kIsNewUserForPersonCenter";// 用户是否新用户（新用户：没有看到过811之前的我的页面；老用户：没有看到过811之前我的页面）

static NSString *const kUSER_DEFAULT_KEY_SELECTED_GROUP                                     = @"kUSER_DEFAULT_KEY_SELECTED_GROUP";

static NSString *const kTB_USER_DEFAULT_TIGER_GPT_HOMEPAGE_DID_CLOSE                                     = @"kTB_USER_DEFAULT_TIGER_GPT_HOMEPAGE_DID_CLOSE"; ///<用户是否手动关闭过首页的TigerGpt入口

static NSString *const kTB_USER_DEFAULT_TIGER_GPT_PAGE_SETTING_DID_SHOW_RED_POINT                                    = @"kTB_USER_DEFAULT_TIGER_GPT_PAGE_SETTING_DID_SHOW_RED_POINT"; ///<TigerGpt页右上角设置按钮是否展示过小红点

static NSString *const kTB_USER_DEFAULT_DID_USE_TIGER_GPT                                    = @"kTB_USER_DEFAULT_DID_USE_TIGER_GPT"; ///<用户是否使用过TigerGpt（进入过页面就算使用过）

static NSString *const kTB_USER_DEFAULT_TIP_TIGER_GPT_RESATRT_IN_SEARCH                                    = @"kTB_USER_DEFAULT_TIP_TIGER_GPT_RESATRT_IN_SEARCH"; ///<TIP：提示用户可以在搜索里找到TigerGpt

static NSString *NOTIFICATION_RELODE_COMMUNITY_RED = @"NOTIFICATION_RELODE_COMMUNITY_RED"; // 更新社区小红点状态

#endif /* TBUserDefaultConstantString_h */
