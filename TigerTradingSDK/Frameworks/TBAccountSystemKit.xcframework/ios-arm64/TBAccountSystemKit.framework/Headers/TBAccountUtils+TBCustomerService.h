//
//  TBAccountUtils+TBCustomerService.h
//  TBAccountSystemKit
//
//  Created by chenxin on 2021/8/26.
//

#import "TBAccountUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBAccountUtils (TBCustomerService)

// 获取客服电话
+ (NSString *)getUserCustomerServiceNumber;

// 拨打电话，可能为多个
+ (void)callTelephoneNumbers:(NSArray *)numbers;

// 拨打客服电话
+ (void)callCustomerService;

@end

NS_ASSUME_NONNULL_END
