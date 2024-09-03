//
//  TBShellProjectService.h
//  Pods
//
//  Created by linbingjie on 2021/4/27.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBShellProjectService <NSObject>

@required

/// 个性化物料跳转
/// @param link 跳转链接，可能为url也可能只是path
/// @param arriveFrom 用于统计来源
- (void)tb_jumpWithMaterialLink:(NSString *)link arriveFrom:(NSString *)arriveFrom;


/// 非 http 开头的页面跳转
/// @param link 链接
- (void)tb_gotoNativePageWithPath:(NSString *)link;

// 深度链接跳转
- (void)tb_jumpWithDeepLink:(NSString *)link;

// 埋点方法
- (void)trackAppBehaviorWithModel:(NSString *)model type:(NSString *)type name:(NSString *)name param1:(nullable NSString *)param1 param2:(nullable NSString *)param2;

// 是否需要开通碎股权限
- (BOOL)shouldOpenFracShareTradePermission:(BOOL)buttonSelected;

//// 处理应用语言改变
//- (void)handleAppContentLanguageSettingChanged;

// 更新个人设置
- (void)uploadPersonalConfigInfo:(void (^)(BOOL success, NSString *message, NSError *error))callBack;

// 上传今日开发日志
- (void)tb_uploadTodayLog:(void (^)(BOOL success, NSString *logFileUrl))completion;

// 开发日志数据
- (id)loggerData;

//- (void)tb_uploadPersonalConfigInfo:(void (^)(BOOL success, NSString *message, NSError *error))callBack;

/// 获取服务器配置信息，如用户设置的红涨绿跌等等
/// @isFromLogin 是否来自登录
//- (void)fetchPersonalConfigInfoFromLogin:(BOOL)isFromLogin;

- (void)tb_handleSafariOpen:(NSURL *)url;

- (BOOL)tb_isURLCanOpenPageWithParsedUrl:(NSURL *)url;

- (BOOL)tb_isAbleHandleSafariOpen:(NSURL *)webpageURL;

/// 读取持仓本地配置
- (NSArray *)localPortfolioConfigs:(NSString *)accountCode;

- (NSDictionary *)tb_localKLineIndicatorParams;
- (NSInteger)tb_indicatorAtIndex:(NSInteger)index key:(NSString *)key;
- (NSArray *)tb_indicators:(NSString *)key;
- (void)tbShell_saveChartIndicators:(NSArray *)indicators;

- (void)tb_developLog:(NSString *)logStr;

// 跳转在线客服
- (void)tbShellProjectService_openCustomerServiceWithSource:(nullable NSString *)source
                                                  otherInfo:(nullable NSDictionary *)otherInfo;
// 获取tigertrade的客服链接
- (NSString *)tbShellProjectService_fetchTigerTradeGCSChatUrl:(nullable NSString *)source license:(nullable NSString *)license otherInfo:(nullable NSDictionary *)otherInfo;

/// 获取jpush的RegistrationID
/// jpush是.a库，组件framework二进制会有问题，放到壳工程
- (NSString *)tb_fetchJpushRegistrationID;


// google recaptcha验证流程
- (void)tb_executeRecaptchaWithSiteKey:(NSString *)siteKey
                          customAction:(NSString *)customAction
                                result:(void (^)(NSDictionary * _Nullable error_description, NSString * _Nullable recaptchaToken))result;

/// 判断是否安装了weibo
- (BOOL)tb_isWeiboAppInstalled;

/// weibo分享图片
/// - Parameters:
///   - messageText: 分享文案
///   - imageData: 分享的图片数据
- (BOOL)tb_weiboImageShare:(nonnull NSString *)messageText
                 imageData:(nonnull NSData *)imageData;


/// weibo分享带链接的图片
/// - Parameters:
///   - messageText: message
///   - webPageTitle: page title
///   - imageData: 图片数据
///   - webpageURL: url链接
- (BOOL)tb_weiboImageLinkURLShare:(nonnull NSString *)messageText
                     webPageTitle:(nonnull NSString *)webPageTitle
                        imageData:(nonnull NSData *)imageData
                       webpageUrl:(nonnull NSString *)webpageURL;


/// 判断相关框架是否存在
- (BOOL)tb_judgeForWeixin;
- (BOOL)tb_judgeForWeiBo;
- (BOOL)tb_judgeForTencent;

- (void)tb_qqShareImage:(nonnull NSData *)optimizeImageData
       previewImageData:(nonnull NSData *)previewImageData
                  title:(nonnull NSString *)title
            description:(nonnull NSString *)description;

- (void)tb_qqShareImage:(nonnull NSURL *)linkUrl
      optimizeImageData:(nonnull NSData *)optimizeImageData
                  title:(nonnull NSString *)title
            description:(nonnull NSString *)description;

- (void)tb_weixinShareImage:(BOOL)isTimeline
                      title:(nonnull NSString *)title
                description:(nonnull NSString *)description
                 thumbImage:(UIImage *)thumbImage
                  imageData:(nonnull NSData *)imageData;

- (void)tb_weixinShareWXMiniProgram:(BOOL)isTimeline
                              title:(nonnull NSString *)title
                        description:(nonnull NSString *)description
                         webpageUrl:(nonnull NSString *)webpageUrl
                           userName:(nonnull NSString *)userName
                           miniPath:(nonnull NSString *)miniPath
                        hdImageData:(nonnull NSData *)hdImageData;

- (void)tb_weixinShareLink:(BOOL)isTimeline
                     title:(nonnull NSString *)title
               description:(nonnull NSString *)description
                thumbImage:(UIImage *)thumbImage
                webpageUrl:(nonnull NSString *)webpageUrl
                   linkURL:(nullable NSString *)linkURL;

/// 微信是否安装
- (BOOL)tb_isWeixinInstalled;
/// 打开微信
- (BOOL)tb_openWXApp;



//// 一下几个FB相关的方法需要把代码调用放到壳工程来，因为TBForeignThirdPartyKit 需要改成静态库才能调用
- (void)tbShell_FireBase_logEventWithName:(NSString *)eventName parameters:(nullable NSDictionary *)parameters;
- (void)tbShell_FireBaseSetUserID:(NSString *)userID;
- (id)tbShell_traceStartWithName:(NSString *)name;
- (void)tbShell_traceEndWithObject:(id)object;
- (void)tbShell_increateMetricWithObject:(id)object metric:(NSString *)metric value:(NSInteger)value;
- (NSString *)tbShell_firebase_appInstanceID;
///// end

- (void)tbShell_setupDoraemon;
- (NSString *)tbShell_getAppInfo;

// 弹出应用评分
- (void)tbShell_showRateApp;

// Face++接口key和secret
- (NSDictionary *)tbShell_faceIdApiKeyAndSecret;

// 底下几个阿里云相关方法
- (BOOL)tbShell_ALIYUNEnable;
- (void)tbShell_ALIYUNLoginorRegister:(UIViewController *)vc;
// 检查环境是否可用
- (void)tbShell_ALIYUNCheckEnvAvailableWithCompletion:(void (^)(BOOL isSuccess))completion;
// 获取验证token
- (void)tbShell_ALIYUNGetVerifyTokenWithCompletion:(void (^)(BOOL isSuccess, NSString *token))completion;
- (void)tbShell_ALIYUNgotoAliOneClickLogin;
- (void)tbShell_ALIYUNSetupAliAuthSDK;

- (void)tbShell_AGConnectConfigure;
- (void)tbShell_AGConnectRecordError:(NSError *)error;
- (void)tbShell_AGConnectLog:(NSString *)msg;
- (void)tbShell_AGConnectLogWithFormat:(NSString *)format
                             arguments:(va_list)args;
- (void)tbShell_AGConnectFetchRemoteConfigWithKey:(NSString *)key
                                        valueType:(NSUInteger)type
                                          Success:(void(^)(id responseValue))success
                                          failure:(void(^)(void))failure;


/// 唤起交易密码弹框回调
/// 当SDK调用此方法时会需要唤起交易密码输入框，需要开发者实现此方法
/// - Parameters:
///   - viewcontroller: 交易密码弹出页面VC
///   - completion: 用户输入密码回调
///   - info: 用户输入的密码信息
///   定义key：
///   isSucc：是否成功获取tradetoken
///   encryptionPWD: tradetoken值
///   message：如果失败，错误信息
- (void)tbShell_requestTradePassword:(UIViewController *)viewcontroller Completion:(void (^)(NSDictionary *info))completion;

@end

NS_ASSUME_NONNULL_END
