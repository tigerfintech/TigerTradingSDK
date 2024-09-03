//
//  TBAuthConstantString.h
//  Pods
//
//  Created by linbingjie on 2021/4/29.
//

#ifndef TBAuthConstantString_h
#define TBAuthConstantString_h

static NSString *USER_DEFAULT_KEY_USER_DEFAULT_EDITION              = @"userDefaultkeyEdtion";

// region 在 NSUserDefaults 中的key
static NSString *USER_DEFAULT_KEY_LOCATION_SETTING                  = @"userLocationSetting";                        // phone绑定

// region name 国家代码
static NSString *USER_DEFAULT_KEY_LOCATION_NAME_SETTING             = @"userLocationNameSetting";                        // phone绑定

// 存储用户开户牌照
static NSString *USER_DEFAULT_KEY_USER_DEFAULT_LICENSE              = @"userDefaultkeyLicense";

static NSString *USER_DEFAULT_KEY_USER_DEFAULT_LICENSE_HINT         = @"user_default_license_hint";

// location
static NSString *USER_DEFAULT_KEY_LOCATION                          = @"userDefaultKeyLocation";

// auth路由
static NSString *USER_DEFAULT_KEY_AUTH_ROUTE                          = @"userDefaultKeyAuthRoute";

static NSString *USER_DEFAULT_USER_DATA                             = @"userDefaultKeyUserData";                      //phone绑定

static NSString *USER_DEFAULT_LAST_UPDATE_TIME                      = @"userDefaultKeyLastUpdateDate";  // 用户状态最后更新时间

static NSString *USER_DEFAULT_KEY_LAST_LOGIN_TYPE                   = @"userLastLoginType";

static NSString *NOTIFICATION_KEY_LOGIN_TOKEN_EXPIRED               = @"loginTokenExpiredAction";

static NSString *NOTIFICATION_KEY_BUYLV2_QUOTE_SUCCESS              = @"buylv2_quote_sucess";

static NSString *NOTIFICATION_KEY_DO_QUESTIONNARIRE_SUCCESS         = @"do_questionnaire_sucess";

static NSString *USER_DEFAULT_KEY_IS_BINDING                        = @"userIsBindingPhoneNumber";

static NSString *USER_DEFAULT_KEY_HAS_LOGINPASSWORD                 = @"userDefaultKeyHasLoginPassword";                  //不绑定,每次删除

static NSString *NOTIFICATION_KEY_LOGIN_OR_BIND_SUCCESSFUL                                    = @"loginOrBindAccountSusccessfulAction";

static NSString *NOTIFICATION_KEY_SELECTED_COUNTRY = @"selectedCountryNotification";//选择国家手机号前缀通知key
static NSString *NOTIFICATION_KEY_REGISTER_COUNTRY = @"registerCountryNotification";//选择注册国家通知key
static NSString *NOTIFICATION_KEY_REGISTER_SUCCESSFUL = @"registerSuccessfullyAction";//注册成功key
static NSString *NOTIFICATION_KEY_FIRST_TIME_SET_TRADE_PWD_DONE = @"userFirstlySettingForTradePasswordDoneAction";//初次设置交易密码完成key
static NSString *NOTIFICATION_KEY_DIRECT_TO_LOGIN_FROM_WEB_VIEW = @"directToLoginViewControllerFromWebViewOpeartion";//web登录通知key
static NSString *NOTIFICATION_KEY_CHANGE_SERVER_ADDRESS = @"changeServerAddressAction";//修改服务地址key
static NSString *NOTIFICATION_KEY_SERVER_WILL_CHANGE_MANUAL = @"serverWillChangeManual";//登录超时key
static NSString *NOTIFICATION_KEY_SEND_TOKEN_BACK_FROM_FACEBOOK = @"sendWeChatTokenBackFromFaceBookAction";//facebook返回token key
static NSString *NOTIFICATION_KEY_SEND_TOKEN_BACK_FROM_WECHAT = @"sendWeChatTokenBackFromWeChatAction";//wechat返回token key
static NSString *NOTIFICATION_KEY_SEND_TOKEN_BACK_FROM_GOOGLE = @"sendGoogleTokenBackFromGoogleAction";//google返回token key
static NSString *NOTIFICATION_KEY_SEND_TOKEN_BACK_FROM_WEIBO = @"sendWeiboTokenBackFromWeiboAction";//微博返回token key
static NSString *NOTIFICATION_KEY_REQUEST_AUTH_TO_WECHAT = @"requestAuthToWeChatAction";//wechat认证key
static NSString *NOTIFICATION_KEY_REQUEST_AUTH_TO_WEIBO = @"requestAuthToWeiboAction";//微博认证key
static NSString *NOTIFICATION_KEY_REQUEST_AUTH_TO_APPLE = @"requestAuthToAppleAction";//apple认证key
static NSString *NOTIFICATION_KEY_BIND_APPLE_LOGIN_SUCCESS = @"bindAppleLoginSuccessed";//绑定apple登录成功key
static NSString *NOTIFICATION_APP_PRIVACY_ALERT_AGREED = @"NOTIFICATION_APP_PRIVACY_ALERT_AGREED";//隐私协议同意key
static NSString *NOTIFICATION_KEY_LOGIN_SUCCESSFUL = @"loginSuccessfulAction";//登录成功key
static NSString *NOTIFICATION_KEY_LOGIN_SUCCESSFUL_AND_DID_GET_ACCOUNT_STATUS = @"loginSuccessfulAndDidGetAccountStatusAction";//登录成功，并且获取到了账户信息accountStatus
static NSString *NOTIFICATION_KEY_UPDATE_WATCHLISTGROUP_LOGIN_SUCCESS = @"updateWatchListGroupLoginSuccess";//登录更新自选股key
static NSString *NOTIFICATION_KEY_SWITCH_LOGIN_ACCOUNT = @"switchLoginAccountAction";//切换登录账号key
static NSString *NOTIFICATION_KEY_SHOULD_SHOW_ANIMATION_AFTER_VERIFY_SUCCESSFUL = @"kShouldShowAnimationAfterVerifySuccess";//要显示验证码验证成功动画

static NSString *USER_LOAD_SHOW_PSD = @"userLoadShowPsd";//展示密码key
static NSString *USER_DEFAULT_KEY_LAST_LOGIN_PAGE = @"userLastLoginPage";//用户上次登录成功页面key
static NSString *USER_DEFAULT_KEY_APPLE_CREDENTIAL_USER = @"userDefaultKeyAppleCredential";//apple资质用户key
static NSString *USER_THIRD_ACCOUNT_APPLE_NICKNAME = @"userThirdAccountAppleNickname"; // 苹果昵称key
static NSString *USER_THIRD_ACCOUNT_AUTHCODE = @"userThirdAccountAuthCode";//苹果认证码
// 三方账号邮箱
static NSString *kTBUserThirdAccountEmail = @"userThirdAccountEmail";
static NSString *USER_FIRST_LOGIN = @"userFirstLogin";//用户初次登录key
static NSString *USER_THIRD_ACCOUNT_OPENID = @"userThirdAccountOpenid";  //三方账号openID key
static NSString *USER_THIRD_ACCOUNT_WECHAT_NICKNAME = @"userThirdAccountWechatNickname"; // 微信昵称
static NSString *USER_DEFAULT_STOCK_SORT_PRIORITY = @"userDefaultStockSortPriority";                    // 用户市场排序key

// singpass
static NSString *NOTIFICATION_KEY_REQUEST_AUTH_TO_SINGPASS                       = @"requestAuthToSingpassAction";//发送通知，此时需要通过singpass获取用户信息（会唤起web页sdk）
static NSString *NOTIFICATION_KEY_DID_RECEIVED_AUTHCODE_FROM_SINGPASS_WEB_SDK    = @"notificationKeyDidReceivedAuthCodeFromSingpassWebSdk";// h5页面通过singpass获取到用户的authcode以后，通过js方法传递给native，然后发送此通知，传递给AppDelegate+TBThirdParty来处理是绑定还是登录，再做后续处理（下边通知NOTIFICATION_KEY_SEND_TOKEN_BACK_FROM_SINGPASS）
static NSString *NOTIFICATION_KEY_SEND_TOKEN_BACK_FROM_SINGPASS                  = @"sendTokenBackFromSingpassAction";// 已经从singpass获取了信息，携带从singpass获取的用户信息
static NSString *NOTIFICATION_KEY_LOGIN_WITH_VERIFY_CODE                  = @"loginWithVerifyCode";// 从验证码输入页携带验证码，发起登录操作
static NSString * const kLoginFirstPageAbtestResult = @"kLoginFirstPageAbtestResult";// 登录注册流程首页方案

#pragma mark - notification
static NSString * const NOTIFICATION_KEY_LOGIN_WITH_PHONE_VERIFY_DATA                  = @"loginWithPhoneVerifyData";// 发起登录网络请求，会携带手机登录、注册所需的数据
static NSString * const NOTIFICATION_KEY_THIRD_PARTY_LOGIN_DID_CLICK                  = @"thirdPartyLoginDidClick";// 三方登录触发（用于通知所在VC上报埋点）

// 开户提交个人资料通知
static NSString *NOTIFICATION_KEY_OPEN_ACCOUNT_SUBMIT_DATA = @"openAccountSubmitData";

static NSString * const kLastPhoneOrEmailLoginType                   = @"kLastPhoneOrEmailLoginType";// 只有当手机、邮箱登录时，保存登录类型，并且不清空（比如第一次手机登录，第二次邮箱登录，第三次微信登录，第四次游客登录，这时候保存值是邮箱登录）

static NSString *NOTIFICATION_KEY_UUID_CHANGED = @"NOTIFICATION_KEY_UUID_CHANGED";//登录成功key

static NSString *TB_NOTIFICATION_KEY_LOGIN_CHANGE_TO_PHONE_TAB = @"TB_NOTIFICATION_KEY_LOGIN_CHANGE_TO_PHONE_TAB"; //  登录注册（或添加账号）的时候，切到手机登录tab。并且会pop回登录注册页（或添加账号页）
// location
static NSString *USER_DEFAULT_KEY_QUOTE_PERMISSION_VERSION = @"userDefaultKeyQuotePermissionVersion";

#endif /* TBAuthConstantString_h */
