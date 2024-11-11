//
//  TBCouponListViewController.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/3/16.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBBusinessSupportKit/TBCouponDelegate.h>

NS_ASSUME_NONNULL_BEGIN


@interface TBCouponListViewController : TBListTableViewController

@property (nonatomic, strong) void(^didChangeCouponBlock)(NSArray<TBCouponDelegate> *, TBCouponCategory category);
@property (nonatomic, strong) void(^updateCouponTitleBlock)(BOOL showActionButton, NSInteger couponCount);

@property (nonatomic, weak) id<TBCouponDataService> dataService; // 数据源

@property (nonatomic, copy) NSDictionary *couponParameters;

@property (nonatomic, copy) TBCouponCategory category;

@property (nonatomic, copy, nullable) NSArray<TBCouponDelegate> *recommendedCoupons;     /// < 系统推荐的优惠券
@property (nonatomic, copy, nullable) NSArray<TBCouponDelegate> *coupons;                /// < 下单选择的优惠信息
@property (nonatomic, copy, nullable) NSArray<TBCouponDelegate> *exclusiveCoupons;       /// < 下单选择的优惠信息 附加订单:主订单-子订单 括号订单:订单1-订单2 优惠信息互斥

@property (nonatomic, assign) BOOL allowsMultipleSelection;                              /// < 是否允许多选,默认NO
@property (nonatomic, assign) BOOL recommendedStickyEnabled;                             /// < 是否推荐置顶,默认NO
@property (nonatomic, assign) BOOL lifetimeCommissionFree;                               /// < 是否终身免佣标识
@property (nonatomic, assign) BOOL hasData;

@property (nonatomic, copy) NSString *disclaimerText;                                    /// < 列表底部免责声明

@property (nonatomic, assign, readonly) BOOL hasValidDatas;                              /// < 是否含有有效的优惠券信息，有效定义：eligible != disable

- (void)update:(BOOL)didUserChangeCoupon;

@end

NS_ASSUME_NONNULL_END
