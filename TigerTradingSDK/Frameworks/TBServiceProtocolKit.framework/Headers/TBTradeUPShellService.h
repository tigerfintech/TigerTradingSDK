//
//  TBTradeUPShellService.h
//  Pods
//
//  Created by linbingjie on 2021/6/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBTradeUPShellService <NSObject>

@required

/// 是否已退出账号
- (BOOL)isTradeUpLogout;

/// 跳转期权开通界面
- (void)gotoOpenOptionPage;

/// 跳转期权等级升级界面
- (void)gotoOptionUpgradePage;

/// 跳转 ipo 申购界面
- (void)gotoIPOSubscribePage:(NSString *)ipoName;

/// TBChatSDK根据项目分割不同的内容，所以不能直接调用对应代码的方法，存在调用对应代码而本target没有引用相关类的情况
- (void)tup_chatSDKUtilsConfig;
- (void)tup_chatSDKUtilsStartSupport;


@end

NS_ASSUME_NONNULL_END
