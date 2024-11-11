//
//  TBPaymentConstants.h
//  ActionSheetPicker-3.0
//
//  Created by zlc on 2022/8/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBPaymentMethod;

extern NSString * const NOTIFICATION_KEY_FUND_AUTO_TRADE_OPEN;

extern NSString * const kTBPaymentPayMethod;
extern NSString * const kTBPaymentBankCardIdKey;

FOUNDATION_EXPORT TBPaymentMethod const _Nonnull kTBPaymentMethodPrimeAccount;
FOUNDATION_EXPORT TBPaymentMethod const _Nonnull kTBPaymentMethodBankCard;
FOUNDATION_EXPORT TBPaymentMethod const _Nonnull kTBPaymentMethodAddBankCard;

NS_ASSUME_NONNULL_END
