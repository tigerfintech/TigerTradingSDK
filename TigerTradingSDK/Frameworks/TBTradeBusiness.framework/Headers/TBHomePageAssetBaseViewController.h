//
//  TBHomePageAssetBaseViewController.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/4/13.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class TBTradeSummaryTitleView;

@interface TBHomePageAssetBaseViewController : TBBaseViewController

@property (nonatomic, strong) UIView *roundContentBgView;
@property (nonatomic, strong) TBTradeSummaryTitleView *tradeSummaryTitleView;

@property (nonatomic, assign) BOOL viewWillAppearFromSwitchAccount;

@property (nonatomic, copy) void (^reloadDataCallBack)(BOOL isSection);
@property (nonatomic, copy) void (^moduleActionCallBack)(NSString *eventId, NSDictionary *params);

- (void)updateUserCommunityLevelBadge;
/// 显示账户列表
- (void)showTradeAccountListView;

@end

NS_ASSUME_NONNULL_END
