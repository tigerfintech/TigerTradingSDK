//
//  TBSDKDelegateDebugViewController.h
//  TigerQuoteSDK
//

#import <UIKit/UIKit.h>
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
#import <TigerTradingSDK/TigerQuoteDebugMananger.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSDKDelegateDebugViewController : UITableViewController <TigerQuoteDebugDelegate>

/// 展示完整的客户代理实现开关。
- (void)showAllDelegateSettings;

/// 展示宿主自定义行情设置，并回写权限档位。
- (void)showHostQuoteSettingsWithQuoteType:(TigerTradingSDKQuoteType)quoteType
                             changeHandler:(void (^)(TigerTradingSDKQuoteType quoteType))changeHandler;

@end

NS_ASSUME_NONNULL_END

#endif
