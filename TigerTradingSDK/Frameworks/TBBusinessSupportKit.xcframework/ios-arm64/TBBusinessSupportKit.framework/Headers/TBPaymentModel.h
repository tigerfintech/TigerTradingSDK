//
//  TBPaymentModel.h
//  TBFundMall
//
//  Created by wind on 2022/9/26.
//

#import <TBBaseKit/JSONModel.h>
#import "TBPaymentConstants.h"

@protocol TBPaymentBankCardLimitModel <NSObject>

@end

@interface TBPaymentBankCardLimitModel : JSONModel
/// 币种
@property (nonatomic, copy) NSString *currency;

/// 银行卡单次限额
@property (nonatomic, strong) NSNumber *amount;

/// 银行卡最小限额
@property (nonatomic, strong) NSNumber *minAmount;

/// 银行卡最大限额
@property (nonatomic, strong) NSNumber *maxAmount;

@property (nonatomic, strong) NSNumber *defaultAmount;

@property (nonatomic, copy) NSArray<NSNumber *> *amountOptions;

/// 对于基金主币种的汇率信息
@property (nonatomic, strong) NSNumber *toTradeCurrencyRate;

@end

///////////////////////////////////////////////////////////////////////////////////
@protocol TBPaymentMethodBankCardModel <NSObject>

@end

@interface TBPaymentMethodBankCardModel : JSONModel

/// 银行名称
@property (nonatomic, copy) NSString *shortBankName;

/// 银行卡号
@property (nonatomic, copy) NSString *bankAccount;

/// 银行卡限额信息
@property (nonatomic, copy) NSArray<TBPaymentBankCardLimitModel> *limits;

/// 银行卡id
@property (nonatomic, copy) NSString *bankCardId;

/// 是否可用(true/false)
@property (nonatomic, assign) BOOL enable;

/// 支付方式状态(银行卡开通状态描述)
@property (nonatomic, strong) NSNumber *status;

/// 银行卡开通状态描述文案
@property (nonatomic, copy) NSString *statusDesc;

/// 银行卡是否解绑
@property (nonatomic, assign) BOOL unlinked;

/// 获取对应限额信息，根据 server 要求，取 limits 第一个
- (TBPaymentBankCardLimitModel *)getLimitInfo;

/// 银行卡简要信息：名称(卡号后四位)
- (NSString *)bankCardSimpleInfo;

@end

///////////////////////////////////////////////////////////////////////////////////
@interface TBPaymentMethodPrimeAccountModel : JSONModel

/// 币种
@property (nonatomic, copy) NSString *currency;

/// 最小定投金额
@property (nonatomic, strong) NSNumber *minAmount;

/// 现金可用金额
@property (nonatomic, strong) NSNumber *availableAmount;

/// 融资可用金额
@property (nonatomic, strong) NSNumber *financingCashAmount;

/// 是否支持融资
@property (nonatomic, assign) BOOL supportFinancing;

/// 合并购买力后的现金可买，包括TigerValut
@property (nonatomic, strong) NSNumber *buyOnCashAmountByCurrency;

@property (nonatomic, strong) NSNumber *defaultAmount;

@property (nonatomic, copy) NSArray<NSNumber *> *amountOptions;

@end

///////////////////////////////////////////////////////////////////////////////////
@interface TBPaymentPaymentModel :JSONModel

/// 支付方式（PRIME：综合账户 BANKCARD：银行卡）
@property (nonatomic, copy) TBPaymentMethod method;

/// 支付银行卡信息
@property (nonatomic, strong) TBPaymentMethodBankCardModel *bankCard;


- (BOOL)isBankCardPayment;

- (BOOL)isPrimeAccountPayment;

@end

///////////////////////////////////////////////////////////////////////////////////

@interface TBPaymentMethodModel : JSONModel

/// 是否支持银行卡支付
@property (nonatomic, assign) BOOL bankSupport;

/// Prime Account 信息
@property (nonatomic, strong) TBPaymentMethodPrimeAccountModel *prime;

/// 银行卡信息
@property (nonatomic, copy) NSArray<TBPaymentMethodBankCardModel> *bankCards;

/// 根据 bankCardId 获取对应银行卡信息
/// - Parameter bankCardId: 银行卡 id
- (TBPaymentMethodBankCardModel *)getBankInfo:(NSString *)bankCardId;

@end

