//
//  TBAccountConstantString.h
//  Pods
//
//  Created by linbingjie on 2021/5/25.
//

#ifndef TBAccountConstantString_h
#define TBAccountConstantString_h

// 是否设置过交易密码
static NSString *USER_SET_TRADE_PASSWORD = @"userSetTradePassword";

// 是否已
// CRS认证通知
static NSString *NOTIFICATION_WATCHLIST_CRS_ALERT = @"NOTIFICATION_WATCHLIST_CRS_ALERT";

// 跳转个人信息校验alert
static NSString *NOTIFICATION_WATCHLIST_VERIFICATION_ALERT = @"NOTIFICATION_WATCHLIST_VERIFICATION_ALERT";

//获取到server 新接口得到bs_available等字段的通知
static NSString *NOTIFICATION_KEY_REFRESH_TRADETITLE                                             = @"NOTIFICATION_KEY_REFRESH_TRADETITLE";

static NSString *TBAccountStatusDataArchiveKey                   = @"TBAccountStatusDataArchiveKey";//缓存statusModelV3到本地的Key

// 通过h5获取了验证token
static NSString *NOTIFICATION_KEY_DID_FETCH_WEB_RECAPTCHA         = @"NOTIFICATION_KEY_DID_FETCH_WEB_RECAPTCHA";

// (在调用h5的recaptcha验证时) 通过该方法通知native改变h5弹框尺寸
static NSString *NOTIFICATION_KEY_WEB_RECAPTCHA_WEB_CHANGE_SIZE         = @"NOTIFICATION_KEY_WEB_RECAPTCHA_WEB_CHANGE_SIZE";

// key 用于记录登录页出现的date
static NSString *kTBLoginPageShowDate = @"kTBLoginPageShowDate";

// key 用于记录登录欢迎页是否展示完毕
static NSString *kTBLoginWelcomePageShow = @"kTBLoginWelcomePageShow";

// 交易权限发生变化，发送通知，目前用于切换账户类型后（模拟->综合）更新 TradeSummary 展示 期货 segment
static NSString *kTBNotificationUserAccountTradePermissionChanged = @"kTBNotificationUserAccountTradePermissionChanged";

// 行情权限发生变化，发送通知
static NSString *kTBNotificationUserAccountQuotePermissionChanged = @"kTBNotificationUserAccountQuotePermissionChanged";

// bff-PortfolioFunctionModulePro 切换账户成功后的通知，调用bff接口更新PortfolioFunctionModulePro模块
static NSString *kPortfolioFunctionModuleProChangeOnAccountSwitchKey = @"kPortfolioFunctionModuleProChangeOnAccountSwitchKey";

#endif /* TBAccountConstantString_h */
