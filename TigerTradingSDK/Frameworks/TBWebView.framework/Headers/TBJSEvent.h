//
//  TBJSEvent.h
//  StockGlobal
//
//  Created by linbingjie on 2019/12/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBThirdParty/dsbridge.h>

NS_ASSUME_NONNULL_BEGIN

/**
编写JS之前必须要阅读如下文件
https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=51810270
*/

// 内部代理，用于控制webView本身的逻辑
@protocol TBWebViewJSBridgeInnerDelegate <NSObject>

@optional

// 是否显示分享按钮
- (void)enableNativeShare:(BOOL)enable;

- (void)enableWebViewBounce:(BOOL)enable;

// 关闭web页
- (void)quitWebView;

// 设置导航栏标题
- (void)setTitle:(id)objc;

// 设置导航栏颜色
- (void)jsSetNavBarColor:(NSString *)bgColorString style:(NSString *)style;

/**
 开通华美银行账户的入口相关，回退到上一个原生页面
 */
- (void)disallowGoBack;

- (void)jsDeepCustomWebViewFullScreen:(BOOL)fullScreen
                          useSafeArea:(BOOL)useSafeArea
                                style:(NSInteger)style
                               navbar:(BOOL)navbar;

/// url 为登录进入App后加载的H5页面（优先级低于Deeplink）
/// @param url url 为登录进入App后加载的H5页面（优先级低于Deeplink）
/// @param params params 示例 "{"invite":  "tiger888", "adcode": "invitflow"}"
/// @param forceQuit forceQuit = true 会退出到登录页
- (void)setUrlAfterSignIn:(NSString *)url params:(NSDictionary *)params forceQuit:(BOOL)forceQuit;

- (void)login:(NSDictionary *)params forceQuit:(BOOL)forceQuit;

- (void)showOnlineChat:(BOOL)show info:(NSDictionary *)info;

/// 是否支持右滑返回
/// @param enable YES 支持；NO 不支持
- (void)setExitSliderEnable:(BOOL)enable;

// 是否支持webview左右滑动后退前进手势
- (void)setBackForwardNavigationGesturesEnable:(BOOL)enabled;

// 设置页面中是否含有隐私信息，如有隐私信息，APP会在用户截图、录屏等时提醒用户注意信息泄露
- (void)setPageSafeMode:(BOOL)flag;

// 安全验证
- (void)securityCheck:(id)objc;

// 更新分享信息
- (void)configureH5ShareInfo:(NSDictionary *)shareInfo;

// 网页触发分享
- (void)jsExportDelegateShare:(id)objc;

/// h5分享：web页面中的分享按钮
/// - Parameter objc: 分享的数据
- (void)shareWithParam:(id)objc;

// 获取弹窗信息
- (void)getAlertMessage:(id)objc;

// 点击关闭按钮，需要通过callback通知h5展示关闭确认弹窗
- (void)needCloseConfirm:(NSString *)callback;

// enable为true时，H5页面从不可见变为可见时要重新刷新H5
- (void)enableNativeReload:(BOOL)enable;

// 监听路由hash改变
- (void)onHashChange:(id)objc;

// h5关闭确认弹窗点击按钮隐藏
- (void)hideCloseConfirm;

/// 激活 模拟账户
- (void)openVirtualAccount:(NSDictionary *)objc;

- (void)showUploadLogDialog;
@end

// 外部代理，处理与webView无关的业务逻辑
@protocol TBWebViewJSBridgeOuterDelegate <NSObject>

@optional

// 跳转native页面
- (void)gotoNativePageWithPath:(NSString *)path;

// 跳转老虎令牌
- (BOOL)goTigerKey:(id)objc;

// 开启MyInfo登录
- (BOOL)openMyInfo:(id)objc;

/// 激活模拟账户
- (void)openVirtualAccount;

// 分享一组网络图片
- (void)sharePicAlbum:(id)objc;

// 分享当前网页截图，效果不好，用新方法sharePicFromData代替，先保留
- (void)shareScreenshot:(id)objc;

// 分享图片，图片参数为base64字符串或字符串的数组
- (void)sharePicFromData:(id)objc callback:(id)callback hasLogo:(BOOL)hasLogo;

// 打开苹果内购
- (void)callInAppPay:(NSString *)productId orderId:(NSString *)orderId;

// 通过短信分享
- (void)shareMessage:(id)objc callback:(id)callback;

// 通过邮件分享
- (void)shareEmail:(NSString *)subject body:(NSString *)body torecipients:(id __nullable)torecipients callback:(NSDictionary *)callback;

// 更新用户状态
- (void)updateUserStatus;

// 期权测试通过
- (void)optionWarApprove;

/**
新加坡开户， singpass 回传数据
*/
- (void)singpassCallback:(id)callBack;

/**
新加坡用户登录， singpass 回传数据
*/
- (void)singpassAuthCallback:(id)callBack;

/**
 跳转开户页面
 */
-(void)openAccountGuideVC;


/*
 newsletter页触发
 如果是游客则跳转到 注册页面 并返回true；
 如果是 三方登录账号且尚未绑定过手机号，则跳转到绑定手机号页面 返回true；
 正常用户直接返回false
 */
- (BOOL)isAccountPermissionLimited;

/*
 return 0:手机号或邮箱用户 1:游客 2:三方账号且未绑定手机号或邮箱
 */
- (id)getUserStatus;

// 获取accessToken
- (NSString *)getAccessToken;

// 获取edition
- (NSString *)getEdition;

// 获取location
- (NSString *)getLocation;

// 获取region
- (NSString *)getRegion;

// 获取license
- (NSString *)getLicense;

// 获取交易密码
- (NSString *)getTradeToken;

- (NSString *)getUUID;

// 验证交易密码
- (void)verifyTradePasswordWithCallBack:(id)callBack;

// 行情权限切换设备
- (void)switchDeviceSuccessWithCallBack:(id)callBack;

// 统计页面时长
- (void)trackTimerWithEvent:(NSString *)event properties:(NSDictionary *)properties;

// 结束页面统计
- (void)trackTimerEnd;

// 统计点击事件
- (void)onAppBehavior:(NSDictionary *)dict;

// 订阅消息方式打开微信
- (void)openWechatAndSubscribe;

// 打开基金购买页（申购或赎回）
- (void)openFundPurchasePage:(NSDictionary *)dict;

// 引导用户去app store 好评
- (void)showFeedbackDialog;

- (void)openInNewPageWithUrl:(NSString *)url title:(nullable NSString *)title;

// 下载图片并保存到相册中，dataString可以为url或者base64
- (void)downloadImage:(NSString *)dataString callback:(NSDictionary *)callback;

// 返回自研客服web页需要的信息
- (NSDictionary *)getImInfo;

// 返回App设置，比如greenUpRedDown涨跌偏好
- (NSDictionary *)getAppSetting:(NSString *)key;

/// 跳转开户
- (id)goOpenAccount:(NSDictionary *)objc;

/// 跳转入金
- (id)gotoDeposit:(NSDictionary *)objc;

// 跳转app store
- (void)goAppStore:(NSDictionary *)objc;


// 跳转syep page
- (void)openSYEPPage:(NSDictionary *)objc;

// H5调用Native获取客户端属性和action参数
- (NSString *)getReCaptchaParam;

// 通过h5 recaptcha 获取验证token的回调
- (void)onReCaptchaResult:(NSDictionary *)callBack;

// (在调用h5的弹框recaptcha验证时) 通过该方法通知native改变弹框尺寸
- (void)resizeWebview;

// 跳转到微信小程序
- (void)goToWeChatMiniProgram:(id)objc;

@end


@interface TBJSEvent : NSObject

@property (nonatomic, weak, nullable) id <TBWebViewJSBridgeInnerDelegate> innerDelegate;

@property (nonatomic, weak, class) id <TBWebViewJSBridgeOuterDelegate> outerDelegate;

// 是否是老虎域名
+ (BOOL)isTigerHost:(NSString *)host;

+ (NSString *)fetchCustomUserAgent;
// 初始化UA, 目前在WKWebViewController 和 社区编辑器中使用
+ (void)initWebViewUserAgent;

@end

NS_ASSUME_NONNULL_END
