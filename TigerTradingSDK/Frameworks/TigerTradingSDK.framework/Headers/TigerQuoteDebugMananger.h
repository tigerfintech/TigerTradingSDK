//
//  TigerQuoteDebugMananger.h
//  AFNetworking
//
//  Created by linbingjie on 2024/8/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TigerQuoteDebugMananger : NSObject

/// 跳转网络页面
/// - Parameter fromViewController:
+ (void)openNetworkPageViewController:(UIViewController *)fromViewController;


/// 启动sdk，
/// FIXME: 开发阶段使用方法，不对外提供
+ (void)startWithRegisteredAccessToken:(NSString *)token
                              success:(void (^)(void))success
                              failure:(void (^)(NSError *error))failure;


+ (NSString *)getAccessToken;


+ (void)openSwitchAccountVC;

@end

NS_ASSUME_NONNULL_END
