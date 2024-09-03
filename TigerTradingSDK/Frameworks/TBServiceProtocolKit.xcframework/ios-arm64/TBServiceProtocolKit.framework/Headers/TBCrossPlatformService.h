//
//  TBCrossPlatformService.h
//  Pods
//
//  Created by linbingjie on 2021/7/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TBCrossPlatformModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBCrossPlatformService <NSObject>

@required

#pragma mark - Flutter
/// 跳转Flutter页面,扩展性高，通过param传递参数做特殊处理
/// @param model 页面逻辑
- (nullable id)tb_gotoFlutterPage:(nonnull TBCrossPlatformModel *)model;

// 通过https://laohu8.com/flutter/xxx 形式的链接打开flutter页面
- (void)tb_gotoFlutterPageWithURLString:(NSString *)urlString;

- (void)tb_gotoFlutterMembershipHomeWithIsSvip:(BOOL)isSvip;

// TradeUP使用，打开flutter页面
- (void)tup_gotoFlutterPageWithRouteName:(NSString *)routeName params:(nullable NSDictionary *)params;

- (void)tb_removeFlutterDBCache;

/// TUP IB 跳转入金页面
- (void)tup_ibGotoDepositPage;

/// TUP IB 跳转出金页面
- (void)tup_ibGotoWithdrawalPage;

/// TUP 跳转IPO页面
- (void)tup_gotoIPOPage;

#pragma mark - RN
/// 跳转RN页面  - tb_gotoRNPage 扩展性高，通过param传递参数做特殊处理
/// @param params 页面逻辑
- (void)tb_gotoRNPageWithURLString:(NSString *)urlString fromAD:(BOOL)fromAD arriveFrom:(NSString *)arriveFrom otherParam:(nullable NSDictionary *)otherParamDict;

- (BOOL)tb_canOpenRNLink:(NSString *)rnLink;

- (NSString *)tb_fetchTBNewsChangeTabNotification;

- (void)tb_gotoOpenAccountStartPageWithParams:(nullable NSDictionary *)param;

/**
 * 跳转升级到保证金账户
 * @param userInfo 额外信息(预留)
 */
- (void)tup_goToUpgradeToMarginPage:(nullable NSDictionary *)userInfo;


@end

NS_ASSUME_NONNULL_END
