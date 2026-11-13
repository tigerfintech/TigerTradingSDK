#import <Foundation/Foundation.h>
#import <TigerTradingSDK/TigerTradingSDKManager.h>

NS_ASSUME_NONNULL_BEGIN

/// 通用 Demo 的公开配置基类；内部子类可覆盖配置逻辑。

@interface TBExampleConfig : NSObject

/// 只生成配置，不执行 SDK 初始化。公开实现使用客户填写的值；内部实现保留启动配置覆盖规则。
- (TigerTradingSDKConfig *)configurationWithLaunchSettings:(nullable NSDictionary *)launchSettings;

/// 按需更新用户信息；公开示例默认不处理，内部子类可提供预置数据。
- (void)updateUserInfoConfig;

/// 可选的调试注入 Bundle 路径；公开示例默认不提供。
- (nullable NSString *)injectionBundlePath;

/// 注册可选调试日志；公开示例默认不处理。
- (void)registerDebugLogger;

/// 多语言调试的启动默认值；公开示例默认关闭。
- (BOOL)languageDebugEnabled;

/// 注册 UI Test 日志导出通知；公开示例默认不处理。
- (void)registerUITestLogExportNotification;

/// 默认交易授权；公开示例不提供测试样本。
- (nullable NSString *)defaultTradeAuthorization;
/// 将输入转换为交易授权；公开示例直接返回输入，内部可处理测试快捷值。
- (NSString *)tradeAuthorizationForInput:(NSString *)input;

@end

NS_ASSUME_NONNULL_END
