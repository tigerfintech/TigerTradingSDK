//
//  TBAIPCouponDataService.h
//  TBTradeBusiness
//
//  Created by swordzhou on 8/21/23.
//

#import <Foundation/Foundation.h>
#import <TBBusinessSupportKit/TBCouponDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 基金-股票定投获取优惠券的数据请求累，有别于TBCouponCardDataService
 */
@interface TBAIPCouponDataService : NSObject <TBCouponDataService>

@end

NS_ASSUME_NONNULL_END
