//
//  TigerQuoteSDKManager.h
//  TigerQuoteSDK
//
//  Created by linbingjie on 2024/8/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSNotificationName const TigerTradingSDKLoginTokenExpiredNotification;

@protocol TigerTradingSDKDelegate <NSObject>

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
- (void)requestTradePassword:(UIViewController *)viewcontroller completion:(void (^)(NSDictionary *info))completion;

@end


@interface TigerTradingSDKManager : NSObject

@property (nonatomic, weak, class) id<TigerTradingSDKDelegate> delegate;

/// 启动App设置加盟商在老虎侧被分配的CilentID
/// - Parameter launchingOption: 启动参数.
/// - Parameter brokerClientId: 加盟商在老虎侧被分配的CilentID
+ (void)setupWithOption:(NSDictionary *)launchingOption clientId:(NSString *)brokerClientId;

/// 设置加盟商在老虎侧被分配的CilentID
/// - Parameter brokerClientId: 加盟商在老虎侧被分配的CilentID
+ (void)setupBrokerClientId:(NSString *)brokerClientId;

/// 查看SDK版本号
+ (NSString *)sdkVersion;


/// 与加盟商auth交互，换取老虎股票SDK accessToken
/// accessToken、idToken、autorizationCode、state具体需要传哪些参考加盟商的对接文档
/// 推荐在加盟商App完成登录后进行token交换。
/// - Parameters:
///   - accesstoken: 加盟商app提供的访问令牌。
///   - idToken: 加盟商app提供的身份令牌
///   - autorizationCode: 加盟商app提供的授权码
///   - state: 获取授权码时传的state
///   - callBack: 成功回调，BOOL为YES表示成功，NO表示失败
+ (void)registerAccessToken:(nullable NSString *)accesstoken idToken:(nullable NSString *)idToken autorizationCode:(nullable NSString *)autorizationCode state:(nullable NSString *)state callBack:(nonnull void (^)(BOOL))callBack;


/// 获取老虎股票SDK首页，该方法会初始化一个首页控制器
+ (UIViewController *)homePageViewController;


/// 跳转老虎股票SDK首页，该方法会初始化一个首页控制器并跳转
/// - Parameter fromViewController: 跳转的起始控制器
+ (void)openHomePageViewController:(UIViewController *)fromViewController;

/// 跳转老虎股票SDK搜索页面，该方法会初始化一个搜索控制器并跳转
/// - Parameter fromViewController: 跳转的起始控制器
+ (void)openSearchViewController:(UIViewController *)fromViewController;

/// 跳转老虎股票SDK订单列表页面，该方法会初始化一个订单列表控制器并跳转
/// - Parameter fromViewController: 跳转的起始控制器
+ (void)openOrderListViewController:(UIViewController *)fromViewController;

/// SDK退出登录
+ (void)sdkLogout;

@end

NS_ASSUME_NONNULL_END
