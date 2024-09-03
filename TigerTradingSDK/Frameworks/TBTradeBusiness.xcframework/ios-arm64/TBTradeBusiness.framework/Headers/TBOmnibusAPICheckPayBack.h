//
//  TBOmnibusAPICheckPayBack.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBTradeAPICloseCashBalanceModel;

@interface TBOmnibusAPICheckPayBack : TBOmnibusAPIModel

@property (nonatomic, copy, nullable)   NSString *loanCurrency;
@property (nonatomic, strong, nullable) NSNumber *loanAmount;
@property (nonatomic, copy, nullable)   NSString *paymentCurrency;
@property (nonatomic, strong, nullable) NSNumber *paymentAmount;
@property (nonatomic, strong, nullable) NSNumber *hasEnoughPaymentAmount;  //是否足够还款
@property (nonatomic, strong, nullable) NSNumber *commission;
@property (nonatomic, strong, nullable) NSNumber *commissionByMargin;

@property (nonatomic, strong, nullable) NSNumber *actualLoanAmount;///< 实际负债金额
@property (nonatomic, strong, nullable) NSNumber *accruedInterest;///< 应计利息


- (TBTradeAPICloseCashBalanceModel *)convertToIBTradeApiModel;
@end

NS_ASSUME_NONNULL_END
