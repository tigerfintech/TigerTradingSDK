//
//  TBFCNOrderModel.h
//  TBTradeBusinessBaseKit
//
//  Created by wind on 2023/10/12.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN
@protocol TBFCNOrderUnderlyingContractModel <NSObject>

@end


@interface TBFCNOrderUnderlyingContractModel : JSONModel

@property (nonatomic, copy) NSString *symbol;

@property (nonatomic, copy) NSString *currency;

@property (nonatomic, copy) NSString *initialPrice;

@property (nonatomic, copy) NSString *strikePrice;

@property (nonatomic, copy) NSString *knockOutPrice;

/// sharkfin 看涨障碍价格
@property (nonatomic, copy) NSString *upBarrierPrice;

/// sharkfin 看跌障碍价格
@property (nonatomic, copy) NSString *downBarrierPrice;

@end


@interface TBFCNOrderModel : JSONModel

@property (nonatomic, copy) NSString *issuer;

@property (nonatomic, copy) NSString *couponPercent;

@property (nonatomic, copy) NSString *strikePercent;

@property (nonatomic, copy) NSString *knockOutPercent;

@property (nonatomic, copy) NSString *knockOutType;

@property (nonatomic, copy) NSString *knockOutObFreq;

@property (nonatomic, copy) NSString *tenor;

@property (nonatomic, copy) NSString *settlementPeriod;

@property (nonatomic, copy) NSArray<TBFCNOrderUnderlyingContractModel> *underlyingContracts;

@property (nonatomic, copy) NSString *underlying;         // underlying FCN限价单时存在

/// SHF 敲出票息
@property (nonatomic, copy) NSString *cashRebate;

/// SHF 看涨障碍比率
@property (nonatomic, copy) NSString *upperBarrierRatio;

/// SHF 看跌障碍比率
@property (nonatomic, copy) NSString *lowerBarrierRatio;

/// SHF 参与率
@property (nonatomic, copy) NSString *participationRate;

/// SHF 保本率
@property (nonatomic, copy) NSString *principalProtection;

/// SHF 保证票息
@property (nonatomic, copy) NSString *floorCoupon;

/// ELN 年化收益
@property (nonatomic, copy) NSString *annualYield;

/// ELN 发行价比例
@property (nonatomic, copy) NSString *issuePriceRatio;

@end

NS_ASSUME_NONNULL_END
