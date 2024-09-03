//
//  TBCouponListViewController.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/3/15.
//

#import <TBUIKit/TBBaseViewController.h>
#import <TBBusinessSupportKit/TBCouponDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBCouponDelegate;
@protocol TBCouponDataService;

@class TBFloatingPanel;

typedef NS_ENUM(NSInteger, TBCouponConfirmViewStyle) {
    TBCouponConfirmViewStyleNone = 0,
    TBCouponConfirmViewStyleDefault = 1,        // 仅仅展示选中的优惠券
    TBCouponConfirmViewStyleEditable = 2,       // 展示和可删除选中的优惠券且可左右滑动查看
};

@interface TBCouponSummaryViewController : TBBaseViewController

@property (nonatomic, copy) NSDictionary *couponParameters;

@property (nonatomic, copy, nullable) NSArray<TBCouponDelegate> *coupons;               /// < 下单选择的优惠信息
@property (nonatomic, copy, nullable) NSArray<TBCouponDelegate> *exclusiveCoupons;      /// < 下单选择的优惠信息 附加订单:主订单-子订单 括号订单:订单1-订单2 优惠信息互斥
@property (nonatomic, copy, nullable) NSArray<TBCouponDelegate> *recommendedCoupons;    /// < 系统推荐的优惠券组合

@property (nonatomic, strong, nullable) TBFloatingPanel *floatingPanel;

@property (nonatomic, strong) void(^didChangeCouponBlock)(NSArray<TBCouponDelegate> *);

@property (nonatomic, assign) NSInteger availableCouponCount;                           /// < 可用优惠券数量

/**
 * @param coupons 选中的优惠券
 * @param exclusiveCoupons 互斥的优惠券
 * @param recommendedCoupons 推荐的优惠券
 * @param couponParameters 获取当前优惠券列表数据的请求参数
 * @param lifetimeCommissionFree 是否终生免佣标识
 * @param dataService 数据源的协议实现
 * @param couponCategory 优惠券类别 详见TBCouponCategory声明和定义
 * @param didChangeCouponBlock 修改优惠券的回调
 */
+ (nonnull TBCouponSummaryViewController *)couponListVCWithCoupons:(nullable NSArray<TBCouponDelegate> *)coupons
                                                  exclusiveCoupons:(nullable NSArray<TBCouponDelegate> *)exclusiveCoupons
                                                recommendedCoupons:(nullable NSArray<TBCouponDelegate> *)recommendedCoupons
                                                  couponParameters:(NSDictionary *)couponParameters
                                            lifetimeCommissionFree:(BOOL)lifetimeCommissionFree
                                                       dataService:(id<TBCouponDataService>)dataService
                                                    couponCategories:(nullable NSArray<TBCouponCategory> *)couponCategories
                                              didChangeCouponBlock:(void(^)(NSArray<TBCouponDelegate> *selectedCoupons))didChangeCouponBlock;

+ (nonnull TBCouponSummaryViewController *)couponListVCWithCoupons:(nullable NSArray<TBCouponDelegate> *)coupons
                                                  exclusiveCoupons:(nullable NSArray<TBCouponDelegate> *)exclusiveCoupons
                                                recommendedCoupons:(nullable NSArray<TBCouponDelegate> *)recommendedCoupons
                                                  couponParameters:(NSDictionary *)couponParameters
                                            lifetimeCommissionFree:(BOOL)lifetimeCommissionFree
                                           allowsMultipleSelection:(BOOL)allowsMultipleSelection
                                                  couponEditEnable:(BOOL)couponEditEnable
                                                    disclaimerText:(NSString *)disclaimerText
                                                  confirmViewStyle:(TBCouponConfirmViewStyle)confirmViewStyle
                                                       dataService:(id<TBCouponDataService>)dataService
                                                  couponCategories:(nullable NSArray<TBCouponCategory> *)couponCategories
                                              didChangeCouponBlock:(void(^)(NSArray<TBCouponDelegate> *selectedCoupons))didChangeCouponBlock;

@end

NS_ASSUME_NONNULL_END
