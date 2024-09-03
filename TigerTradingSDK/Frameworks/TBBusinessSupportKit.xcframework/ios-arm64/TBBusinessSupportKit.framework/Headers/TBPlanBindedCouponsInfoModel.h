//
//  TBPlanBindedCouponsInfoModel.h
//  TBBusinessSupportKit
//
//  Created by swordzhou on 8/22/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBCouponDelegate;

@interface TBPlanBindedCouponsInfoModel : NSObject

@property (nonatomic, copy) NSArray<TBCouponDelegate> *effectiveCoupons;
@property (nonatomic, copy) NSArray<TBCouponDelegate> *expiredCoupons;
@property (nonatomic, copy) NSArray<TBCouponDelegate> *usedCoupons;

@property (nonatomic, assign, readonly) BOOL hasBinedCoupon;
@property (nonatomic, assign, readonly) NSInteger bindedCouponCount;

@property (nonatomic, copy) NSArray<TBCouponDelegate> *allCoupons;

- (NSInteger)statusMaximumCouponCount;

@end

NS_ASSUME_NONNULL_END
