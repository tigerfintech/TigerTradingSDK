//
//  TBBasicConfigurationConstantString.h
//  Pods
//
//  Created by linbingjie on 2021/7/1.
//

#ifndef TBBasicConfigurationConstantString_h
#define TBBasicConfigurationConstantString_h

//跳转到任意Tab
static NSString *NOTIFICATION_GOTO_TABBAR_INDEX                          = @"NOTIFICATION_GOTO_TABBAR_INDEX";

// 登录账号变化通知，包括登录、注册、切换账号等
static NSString *NOTIFICATION_LOGIN_ACCOUNT_CHANGED                      = @"NOTIFICATION_LOGIN_ACCOUNT_CHANGED";

static NSString *NOTIFICATION_KEY_SWITCH_USER_REFRESH_TABBAR             = @"switchUserTigerRefreshtabbar";

static NSString *NOTIFICATION_KEY_IB_SWITCH_OMNIBUS_CANCELLED            = @"IbSwitchOmnibusCancelled";

static NSString *NOTIFICATION_KEY_SWITCH_USER_FAIL                       = @"switchUserTigerFail";

static NSString *USER_DEFAULT_KEY_ADD_TO_WATCHLIST_AFTER_PLACE_ORDER     = @"userDefaultKeyAddToWatchlistAfterPlaceOrder";

//跳转到交易页并切换到账户
static NSString *NOTIFICATION_GOTO_TRADE_CHANGEACCOUNT                   = @"NOTIFICATION_GOTO_TRADE_CHANGEACCOUNT";

// 刷新token成功通知
static NSString *NOTIFICATION_KEY_REFRESH_TOKEN_SUCCESS = @"refresh_token_success";

static NSString *NOTIFICATION_KEY_ADVISOR_UPDATETRANSFER = @"advisorUpdateTransfer";

//显示app隐私协议alert
static NSString *NOTIFICATION_APP_PRIVACY_ALERT  = @"NOTIFICATION_APP_PRIVACY_ALERT";

//跳转到社区tab
static NSString *NOTIFICATION_GOTO_TABBAR_COMMUNITY_TAB                                        = @"NOTIFICATION_GOTO_TABBAR_COMMUNITY_TAB";

static NSString *NOTIFICATION_KEY_COMMUNITY_CHANGEUSERINFO                                    = @"communityUserInfoChanged";

static NSString *TBFlutterPageDidCloseNotification = @"TBFlutterPageDidClose";// flutter页面关闭通知

// 关闭singpass login page
static NSString *NOTIFICATION_KEY_CLOSE_SINGPASS_LOGIN_PAGE                                    = @"notification_key_close_singpass_login_page";

//允许上传图片的大小最大值（字节）
#define UploadImageMaxCapacity                              (10 * 1024 * 1024)

static NSString *NOTIFICATION_KEY_TABBAR_APPEAR                                               = @"tabbarAppear";

static NSString *const kOpenAccountGuideSourceKey = @"kOpenAccountGuideSourceKey"; ///用于存取 触发开户入金引导页的来源

static NSString *const kGotoCloseTwoAuthAfterAgreement = @"kGotoCloseTwoAuthAfterAgreement"; ///签署（完关闭两步验证的）协议后，继续关闭两步验证流程
///
static NSString *NOTIFICATION_KEY_SINGLE_TAP_TABBAR_ITEM                                      = @"singleTapTabbarItem";

static NSString *NOTIFICATION_KEY_NEW_MESSAGE                                                 = @"pushNewMessageAction";

static NSString *NOTIFICATION_KEY_MESSAGE_CENTER_UPDATE = @"NOTIFICATION_KEY_MESSAGE_CENTER_UPDATE"; ///< 退出消息中心页(messageCenterVC)需要刷新未读数

static NSString *NOTIFICATION_KEY_LOADING_AD_END = @"loadingADend";

//通过device config 接口获取到用户相关设置， 包含用户location设置， 红涨绿跌设置等等
static NSString *NOTIFICATION_USER_GET_CONFIG                                             = @"NOTIFICATION_USER_GET_CONFIG";

// 用户跳转入金页
static NSString *NOTIFICATION_KEY_USER_GOTO_DEPOSIT_PAGE = @"userGotoDepositPage";

// 用户购买基金
static NSString *NOTIFICATION_KEY_USER_BUY_FUND = @"userBuyFund";

// 用户添加自选
static NSString *NOTIFICATION_KEY_USER_ADD_WATCHLIST = @"userAddWatchlist";

// 用户下单
static NSString *NOTIFICATION_KEY_USER_PLACE_ORDER = @"userPlaceOrder";

// 社区默认tab变更
static NSString *NOTIFICATION_CHANGE_COMMUNITY_TAB = @"NOTIFICATION_CHANGE_COMMUNITY_TAB";

// 跳转到社区tab 指定二级rab
static NSString *NOTIFICATION_COMMUNITY_SUBTAB = @"NOTIFICATION_COMMUNITY_SUBTAB";

// 获取了用户资料（社区昵称等）
static NSString *TB_NOTIFICATION_COMMUNITY_DID_FETCH_USERINFO = @"TB_NOTIFICATION_COMMUNITY_DID_FETCH_USERINFO";

// 直播间订阅状态发生改变
static NSString *TB_NOTIFICATION_COMMUNITY_LIVE_ROOM_REMIND_STATUS_DID_CHANGE = @"TB_NOTIFICATION_COMMUNITY_LIVE_ROOM_REMIND_STATUS_DID_CHANGE";

// 跳转到 社区-直播tab-指定分类
static NSString *TB_NOTIFICATION_COMMUNITY_JUMP_LIVE_SUBTAB = @"TB_NOTIFICATION_COMMUNITY_JUMP_LIVE_SUBTAB";

// 学院课程状态发生改变
static NSString *TB_NOTIFICATION_COMMUNITY_COLLEGE_LESSON_STATUS_DID_CHANGE = @"TB_NOTIFICATION_COMMUNITY_COLLEGE_LESSON_STATUS_DID_CHANGE";

#endif /* TBBasicConfigurationConstantString_h */
