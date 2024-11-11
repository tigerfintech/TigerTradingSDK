//
//  TBCouponsInfoModel.h
//  TBTradeBusiness
//
//  Created by swordzhou on 8/22/23.
//

#import <Foundation/Foundation.h>
#import "TBCouponDelegate.h"

@protocol TBCouponDescriptionModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBPlanCouponsInfoModel : NSObject

@property (nonatomic, assign) BOOL couponAvailable;          /// 是否存在可以使用的卡券

@property (nonatomic, assign) NSInteger canUseCount;         /// 可用卡券数量 如果是改单包括该计划已绑定未使用的数量
@property (nonatomic, assign) NSInteger bestUseCount;        /// 最优卡券数量

@property (nonatomic, copy) NSArray<TBCouponDelegate> *recommendCoupons; /// 推荐的优惠券信息
@property (nonatomic, copy) NSArray<TBCouponDelegate> *coupons;          /// 选中的优惠券:修改定投计划时为定投计划创建时绑定的优惠券;创建定投计划 和recommendCoupons相同

@property (nonatomic, copy) NSArray<TBCouponDescriptionModel> *couponCombinationDesc;

/**
 * 根据选中的优惠券获取选中优惠券的显示文案
 */
- (NSString *)selectedCouponCombinationDescInfo:(NSArray<TBCouponDelegate> *)selectedCoupons isFund:(BOOL)isFund;

- (NSString *)combinationDescWithType:(TBCouponCombinationDesc)type;

@end

NS_ASSUME_NONNULL_END
