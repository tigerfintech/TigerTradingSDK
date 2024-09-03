//
//  TBTradeAccountManager.h
//  Stock
//
//  Created by ChenXin on 2018/3/21.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBAccountSystemKit/TBTradeAccountModel.h>
#import <TBBaseKit/TBBaseUtility.h>

extern NSString * const NOTIFICATION_KEY_SWITCH_USER_TIGER_ACCOUNT;

@class TBTradeTitleView;

typedef NS_ENUM(NSInteger, TBTradeAccountSwitchResultType) {
    TBTradeAccountSwitchResultTypeNone = 0, ///< 默认
    TBTradeAccountSwitchResultTypeSuccess,  ///< 账户切换成功
    TBTradeAccountSwitchResultTypeFailure,  ///< 账户切换失败
    TBTradeAccountSwitchResultTypeGotoOpenVirtualAccountPage,///< 模拟账户开户
    TBTradeAccountSwitchResultTypeGotoOpenFirstAccountPage,///< 开第一个户
    TBTradeAccountSwitchResultTypeGotoOpenSecondAccountPage,///< 开第二个户
};

@interface TBTradeAccountManager : NSObject

- (void)clearData;

DECLARE_SHARED_INSTANCE(TBTradeAccountManager)

@property (nonatomic, weak) UIViewController *titleViewContainerViewCtrl;

// 是否在交易tab展示切换账户引导，目前只在展示Contra账户开通弹窗后设置为YES
@property (nonatomic, assign) BOOL needShowAccountSwitchGuide;
- (BOOL)showAccountSwitchGuideIfNeededWithButton:(UIButton *)button trackPage:(NSString *)trackPage;

// 当前交易账户类型
// 从auth的currentAccountType到自定义枚举类型的映射
// TODO: 自定义枚举类型是否有必要, 直接用账户类型判断即可
+ (TBTradeAccountType)currentTradeAccountType;

// 当前交易的模拟账户名称
+ (NSString *)currentTradeVirtualAccountName;

// IB账户标题
+ (NSString *)ibAccountTitle;

// Omnibus或Marsco账户标题
+ (NSString *)bsAccountTitle:(BOOL)isContra;

// 当前交易账户名称
+ (NSString *)currentTradeAccountTitle;

// 判断交易tab下拉账户列表点击的是否是当前交易账户
+ (BOOL)isCurrentTradeAccount:(TBTradeAccountModel *)accountModel;

// 使用的地方：ipo首页（TBIPOsSummaryViewController）
+ (NSArray<TBTradeAccountModel *> *)displayedAccountList;

// 使用的地方：股票下单页（TBPlaceOrderViewController）
+ (NSArray <TBTradeAccountModel *> *)makeOrderTradeAccountList;

/// 判断是否应该显示 交易Tab（根据它来判断是显示TBTradeSummaryViewController 还是显示TBOpenAccountGuideViewController）
+ (BOOL)checkShouldShowTradeTab;

- (void)requestAccountSwitchWithType:(NSString *)accountType accountOrCustomerId:(NSString *)accountOrCustomerId success:(void(^)(BOOL isSuccess, NSString *message))success failure:(void(^)(NSError *error))failure;

// 创建交易tab导航栏titleView
- (TBTradeTitleView *)titleViewWithFrame:(CGRect)frame inViewController:(UIViewController *)viewController;


/// 根据是否开户跳转到开户页或切换交易账户.
/// 包含: 判断参数是当前账户不切换; loading UI; 跳转到开户页
/// @param accountType 账户类型
/// @param accountOrCustomerId id
/// @param completion 返回切换结果枚举类型
- (void)checkAndSwitchToAccount:(NSString *)accountType withId:(NSString *)accountOrCustomerId completion:(void(^)(TBTradeAccountSwitchResultType resultType))completion;
- (void)checkAndSwitchToAccount:(NSString *)accountType withId:(NSString *)accountOrCustomerId;

// TigeTrade 716 需求（https://app.asana.com/0/1200809137132393/1201437762606937/f）
/// 跳转到模拟盘开通页面
+ (void)gotoVirtualAccountOpenPage;

/// 跳转到模拟盘介绍页
+ (void)gotoVirtualAccountIntroducePage;

@end
