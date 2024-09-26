//
//  TigerQuoteSDKManager.h
//  TigerQuoteSDK
//
//  Created by linbingjie on 2024/8/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TigerTradingSDKTradeType) {
    TigerTradingSDKTradeTypeBuy,        // 买
    TigerTradingSDKTradeTypeSell,       // 卖
    TigerTradingSDKTradeTypeClose,      // 平
};

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
///   isSucc：是否成功获取encryptionPWD
///   encryptionPWD: encryptionPWD值
///   message：如果失败，错误信息
- (void)requestTradePassword:(UIViewController *)viewcontroller completion:(void (^)(NSDictionary *info))completion;

@optional
/// 合约添加/删除自选
/// - Parameters:
///   - symbol: 合约symbol
///   - market: 合约所属市场
///   - secType: 合约类型：e.g STK(正股),OPT(期权)
///   - completion: 添加结果回调
- (void)requestAddOrRemoveWatchlist:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType completion:(void (^)(BOOL isSucc, NSNumber *code, NSString *msg))completion;

/// 合约是否在自选列表
/// - Parameters:
///   - symbol: 合约symbol
///   - market: 合约所属市场
///   - secType: 合约类型：e.g STK(正股),OPT(期权)
- (BOOL)requestContractIsInWatchlist:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

/// SDK 内是否展示自选按钮
- (BOOL)showWatchlistButton;


/// 用户请求交易
/// - Parameter type: 交易类型：买、卖、平
/// - Parameter symbol:  合约symbol
/// - Parameter market: 合约所属市场
/// - Parameter secType: 合约类型：e.g STK(正股),OPT(期权)
- (void)requestContractTrade:(TigerTradingSDKTradeType)type symbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

/// 是否使用App下单页模式，如果使用App下单页，需要实现上面的协议，pretrade检查等，否则不用。
- (BOOL)appPlaceOrderMode;


/// 查询合约是否在持仓
/// - Parameters:
///   - symbol: 合约symbol
///   - market: 合约市场
///   - secType: 合约类型：e.g STK(正股),OPT(期权)
- (BOOL)requestContractIsInPosition:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

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
///   - callBack: 成功回调，BOOL为YES表示成功，NO表示失败, NSNumber为错误码，NSString为错误信息
///   错误码:11201、11202、11208、11212 与加盟商auth交互失败, 11083 老虎侧用户不存在
+ (void)registerAccessToken:(NSString *)accesstoken idToken:(NSString *)idToken autorizationCode:(NSString *)autorizationCode state:(NSString *)state callBack:(nonnull void (^)(BOOL, NSNumber *, NSString *))callBack;

/// 注册用户openId，SDK不会缓存用户信息，每次启动SDK都需要注册openId
/// - Parameter openId: 用户openId，需要加盟商app提供
+ (void)registerUserOpenId:(NSString *)openId;

/// 注册App的accesstoken，SDK会在后续的请求中带上accesstoken，是否需要传递accesstoken由加盟商决定并同步Tiger
/// 用于Tiger server对SDK中请求携带AppAccessToken转发给加盟商做鉴权的验证
/// - Parameter accesstoken: AppAccessToken
+ (void)registerAppAccesstoken:(NSString *)accesstoken;


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


/// SDK当前client id
+ (NSString *)currentClientId;

/// SDK当前用户的openId
+ (NSString *)currentUserOpenId;

@end

NS_ASSUME_NONNULL_END
