//
//  TBTradeDependence.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2021/8/4.
//

#import <Foundation/Foundation.h>
#import <TBAccountSystemKit/TBTradeAccountModel.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <TBAccountSystemKit/TBUserInfoManager+AccountStatus.h>

@class TBTradeAccountModel;
@class TBTradeTitleView;
@class TBTradeAPIOrderItemModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeDependence : NSObject

DECLARE_SHARED_INSTANCE(TBTradeDependence);

@property (nonatomic, assign, readonly) BOOL needTradeToken;
@property (nonatomic, copy, nullable) NSString *tradeToken;
@property (nonatomic, copy, readonly) NSString *needNDAgreementUrl;
@property (nonatomic, copy, readonly) NSString *gfvStatusDesc;

@property (nonatomic, assign) BOOL hasShowLimitedAlert;
/// 获取当前账户的类型 NSUInteger = TBTradeAccountType
@property (nonatomic, assign) TBTradeAccountType currentTradeAccountType;

- (void)hideTradeView;
- (void)gotoHKStockQuotePage;
- (void)fetchTradeTokenInViewController:(UIViewController *)viewController completion:(void (^)(BOOL success, NSString *errorMsg))completion;
- (void)fetchTradeTokenInViewController:(UIViewController *)viewController cancel:(void (^)(void))cancelBlock completion:(void (^)(BOOL success, NSString *errorMsg))completion;

- (void)share:(id)shareObject userInfo:(nullable NSDictionary *)userInfo;

// 明星投资者分享成交订单
- (void)starInvestorShareWithOrderModel:(TBTradeAPIOrderItemModel *)orderModel showQuantityCheckbox:(BOOL)showQuantityCheckbox arriveFrom:(NSString *)arriveFrom;

// 检查订单是否支持分享
- (void)checkSharePermissionWithOrderId:(id)orderId
                             completion:(void (^)(NSDictionary *orderPermissionInfo))completion;

// 批量 查询订单相关投资者信息
- (void)checkSharePermissionWithOrders:(NSArray *)orders
                             completion:(void (^)(NSArray *orderPermissionInfos))completion;

- (void)getIPOCount:(void(^)(BOOL hasNew, NSInteger newIPOCount))completion;

- (void)gotoIPOPage:(NSInteger)tabType userInfo:(nullable NSDictionary *)userInfo;
- (void)gotoCollegePage:(nullable NSDictionary *)userInfo;
- (void)gotoCommunityDetailPage:(id)communityItem;
/* 根据是否开户跳转到开户页或切换交易账户.
 * 包含: 判断参数是当前账户不切换; loading UI; 跳转到开户页
 * @param accountType
 * @param accountOrCustomerId
 * @param completion 返回切换结果枚举类型
 */
- (void)checkAndSwitchToAccount:(NSString *)accountType withId:(NSString *)accountOrCustomerId;

///// 获取账户列表
//- (NSArray *)tradeAccountList;

/// 判断是否为当前账户
- (BOOL)IsCurrentTradeAccount:(TBTradeAccountModel *)accountModel;

- (void)takeActionAfterMessageReceived:(NSDictionary *)messageInfo;

- (TBTradeTitleView *)titleViewWithFrame:(CGRect)frame targetController:(UIViewController *)targetVC;

- (void)showTradeAccountList;

/// 点击账号设置按钮后，浮窗展示账号列表页
- (void)showTradeAccountListWithFloatingShowAccountSetting;

@end

NS_ASSUME_NONNULL_END
