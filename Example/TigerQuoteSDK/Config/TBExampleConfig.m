#import "TBExampleConfig.h"

@implementation TBExampleConfig

- (TigerTradingSDKConfig *)configurationWithLaunchSettings:(NSDictionary *)launchSettings {
    TigerTradingSDKConfig *sdkConfig = [[TigerTradingSDKConfig alloc] init];
    sdkConfig.appName = @"";
    sdkConfig.appSecret = @"";
    sdkConfig.tenantId = @"";
    sdkConfig.networkType = TigerTradingSDKNetWork_UAT_ITFS;

    NSAssert(sdkConfig.appName.length > 0, @"请在 TBExampleConfig.m 中填写 appName。");
    NSAssert(sdkConfig.appSecret.length > 0, @"请在 TBExampleConfig.m 中填写 appSecret。");
    NSAssert(sdkConfig.tenantId.length > 0, @"请在 TBExampleConfig.m 中填写 tenantId。");
    return sdkConfig;
}

- (void)updateUserInfoConfig {
    // 客户按需配置用户信息，公开示例不预置内部数据。
}

- (NSString *)injectionBundlePath {
    return nil;
}

- (void)registerDebugLogger {
    // 公开示例不注册内部 TTY 日志。
}

- (BOOL)languageDebugEnabled {
    return NO;
}

- (void)registerUITestLogExportNotification {
    // 公开示例不注册内部 UI Test 日志通知。
}

- (NSString *)defaultTradeAuthorization {
    return nil;
}

- (NSString *)tradeAuthorizationForInput:(NSString *)input {
    return input;
}

@end
