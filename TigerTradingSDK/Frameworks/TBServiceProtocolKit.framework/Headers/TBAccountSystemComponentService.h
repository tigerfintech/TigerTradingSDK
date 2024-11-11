//
//  TBAccountSystemComponentService.h
//  Pods
//
//  Created by linbingjie on 2022/5/17.
//

#ifndef TBAccountSystemComponentService_h
#define TBAccountSystemComponentService_h

NS_ASSUME_NONNULL_BEGIN

@protocol TBAccountSystemComponentService <NSObject>

/// 拨打电话
/// @param phoneNums 电话号码
/// 实现：            [TBCustomerServiceUtils callTelephoneNumbers:@[match.phoneNumber]];
- (void)tbAccount_telCallTelephoneNumbers:(NSArray *)phoneNums;

/// 联系客服
- (void)tbAccount_callCustomerService;

// 是否为游客登录模式
- (BOOL)tbAccount_isGuestLoginMode;

// 需要登录权限
- (BOOL)tbAccount_needUserAuthorization;

/// 返回两步验证密码页
/// @param completionBlock 输入6位密码后的回调
- (UIViewController *)tbAccount_twoFactorAuthPasswordViewControllerWithCompletionBlock:(void(^)(NSString * password))completionBlock;

/// 展示异常信息
/// @param errorMessage 异常信息
/// @param controller 密码controller
- (void)tbAccount_showDynamicErrorMessage:(NSString *)errorMessage controller:(UIViewController *)controller;

// 清除交易token（业务接口请求带交易token返回token失效的情况），返回结果：成功或失败
- (BOOL)tbAccount_clearTradeToken;

// 根据需要获取交易token再执行下一步
- (void)tbAccount_fetchTradeTokenInViewController:(id)viewController customView:(id)customView completion:(void (^)(BOOL isSuccess, NSString *errorMsg))completion;

/// 创建密码页
/// @param callBack 回调
- (UIViewController *)tbAccount_createPassWordControllerWithCallBack:(void(^)(NSString * password))callBack;

/**
 * 判断当前操作是否需要切换至综合账户
 *
 * @param secType 期货、港股期权、新加坡、澳洲、港股暗盘、数字货币
 * @param market 市场
 * @param specialCondition  闲钱管家、 基金超市、现金打新、资金质押、碎股卖出、OTC标的、港股暗盘、contra账户
 * @param contraTradable 合约是否支持contra账户交易
 * @param eventId 事件来源id
 */
- (BOOL)tbAccount_omnibusTradeConditionWithSecType:(NSString *)secType market:(NSString *)market specialCondition:(BOOL)specialCondition contraTradable:(nullable NSNumber *)contraTradable eventId:(NSString *)eventId;

/**
 * 跳转到开通期权权限页面
 * @param userInfo 额外信息(预留)
 */
- (void)tbAccount_goToOptionTradePrivilegeApplyPage:(nullable NSDictionary *)userInfo;

- (void)tbAccount_refreshToken:(UIViewController *)baseVC successed:(void(^)(BOOL success))successed;

/// 获取当前国籍
- (NSString *)tbAccount_getRegisterLocation;

- (BOOL)tbAccount_isVirtualTradeAccount;

- (BOOL)tbAccount_isOmnibusTrade;

- (BOOL)tbAccount_atLeastOneAccountStatusIsFunded;

- (BOOL)tbAccount_atLeastOneAccountStatusIsOpened;

- (NSNumber *)tbAccount_lastLoginType;

- (BOOL)tbAccount_isIBTrade;

- (BOOL)tbAccount_isUserInfoStatusDataExist;

- (BOOL)tbAccount_isNDTrade;

//是否开户（包括开户入金注销）
- (BOOL)tbAccount_ibOpened;
- (BOOL)tbAccount_omnibusOpened;

// IB或者综合是否入金
- (BOOL)tbAccount_ibDeposited;
- (BOOL)tbAccount_omnibusDeposited;

- (NSString *)tbAccount_getUserLicense;

- (NSString *)tbAccount_getUserLicenseHint;

- (NSString *)tbAccount_portalHostRegion;

/// 判断是否最后的登录类型是gesture
- (BOOL)tbAccount_isGestureLastLoginType;

// 是否已展示首次启动隐私弹窗（国内包要求展示）
- (BOOL)tbAccount_hasShowPrivacyAlert;

/// 从deeplink获取最后一次登录的类型
/// TBLoginTypeGuest的时候返回nil
- (NSString *)tbAccount_fetchDeepLinkLoginTypeString:(NSInteger)login;

/// 返回值是id TBAccountInfo 类型的，但是对外没办法公开TBAccountInfo，这个类目前在自己的组件内
- (NSArray *)tbAccount_virtualAccountList;

- (NSArray *)tbAccount_fetchUserInfo_V3_TradePermission;

// 设置auth域名路由：GLOBAL or CHN
- (NSString *)tbAccount_authHostRoute;

// MARK: Edition相关，该字段决定了 app的content, 就是部分内容展示不一样
// 正常情况下， 已注册用户的register region为中国大陆， Edition为full， 否则Edition为 fundamental， app部分内容可能会被隐藏。

// app edition
- (NSString *)tbAccount_getAppContentEdition;

- (NSString *)tbAccount_getLocation;

- (BOOL)tbAccount_hasNZQuotePermission;

- (BOOL)tbAccount_checkNeedRegisterAccount;

- (NSString *)tbAccount_currentAccountAccountId;

// 成功、失败block置空。（外部调用：关闭web验证弹框的时候会调用）
- (void)tbAccount_captchaUpdateBlockToNil;

- (BOOL)tbAccount_currentAccountIsLinkFA;

- (BOOL)tbAccount_currentAccountIsContra;
- (BOOL)tbAccount_canShowContraAccount;
- (NSString *)tbAccount_currentAccountNature;


- (BOOL)tbAccount_isMSLicense;
- (BOOL)tbAccount_isAULicense;
- (BOOL)tbAccount_isNZLicense;
- (BOOL)tbAccount_isHKLicense;

- (BOOL)tbAccount_isSGPLicense;
- (BOOL)tbAccount_isKIWILicense;
- (BOOL)tbAccount_isTBNZ_AFSL_License;
- (BOOL)tbAccount_isTFNZLicense;
- (NSString *)tbAccount_userTelCode;
// 当前账户是否已注销
- (BOOL)tbAccount_currentAccountStatusIsClosed;

- (BOOL)tbAccount_isLicense:(NSString *)license;
- (BOOL)tbAccount_isLicenseHint:(NSString *)license;
- (BOOL)tbAccount_isLicenseOrHint:(NSString *)license;

// 获取一次性免核身凭证ticket
- (void)tbAccount_getAuthTicketWithCompletion:(void(^)(NSString * _Nullable ticket))completion;

// 处理应用语言改变
- (void)tbAccount_handleAppContentLanguageSettingChanged;

// 更新个人设置
- (void)tbAccount_uploadPersonalConfigInfo:(void (^)(BOOL success, NSString *message, NSError *error))callBack;

/// 获取服务器配置信息，如用户设置的红涨绿跌等等
/// @isFromLogin 是否来自登录
- (void)tbAccount_fetchPersonalConfigInfoFromLogin:(BOOL)isFromLogin;

@end

NS_ASSUME_NONNULL_END

#endif /* TBAccountSystemComponentService_h */
