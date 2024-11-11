//
//  TBPlaceOrderVerifyResultModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderVerifyResultModel : NSObject

@property (nonatomic, assign) BOOL isPass;
@property (nonatomic, strong) NSNumber *errorCode;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *action;///< DEPOSIT = 入金

@property (nonatomic, assign) BOOL stopByTradePassword;

@end
NS_ASSUME_NONNULL_END
