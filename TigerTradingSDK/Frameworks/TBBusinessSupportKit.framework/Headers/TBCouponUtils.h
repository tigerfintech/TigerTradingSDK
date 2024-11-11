//
//  TBCouponUtils.h
//  TBBusinessSupportKit
//
//  Created by swordzhou on 8/23/23.
//

#import <Foundation/Foundation.h>
#import "TBCouponDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCouponUtils : NSObject

+ (NSString *)couponTitleWithCategory:(TBCouponCategory)category;

+ (NSString *)couponTitleWithCategory:(TBCouponCategory)category isContraAccount:(BOOL)isContraAccount;

+ (BOOL)isCouponCategoryStatus:(TBCouponCategory)category;

/*
 由于加盟App和TT接口path有区别，统一对外提供优惠券接口前缀
 返回值形式host/xxx/infra/public/api/
 */
+ (NSString *)couponUrlPrefix;

@end

NS_ASSUME_NONNULL_END
