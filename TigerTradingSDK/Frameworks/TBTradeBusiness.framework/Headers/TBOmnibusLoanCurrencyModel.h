//
//  TBOmnibusLoanCurrencyModel.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2022/6/9.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusLoanCurrencyModel : JSONModel

@property (nonatomic, copy) NSString *currency;
@property (nonatomic, assign) BOOL isLoan;

@property (nonatomic, copy, nullable) NSArray <NSString *> *repayMethods;

@end

@protocol TBOmnibusLoanCurrencyModel;

@interface TBOmnibusLoanInfoModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusLoanCurrencyModel> *data;

@end

NS_ASSUME_NONNULL_END
