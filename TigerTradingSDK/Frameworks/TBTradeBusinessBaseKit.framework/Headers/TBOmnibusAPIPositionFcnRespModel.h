//
//  TBOmnibusAPIPositionFcnRespModel.h
//  TBTradeBusinessBaseKit
//
//  Created by zlc on 2024/2/21.
//

#import "TBTradeAPIModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBOmnibusAPIPositionFcnUnderlyingContractModel;

@interface TBOmnibusAPIPositionFcnRespModel : TBTradeAPIModel

@property (nonatomic, copy) NSString *issuer;
@property (nonatomic, copy) NSString *couponPercent;
@property (nonatomic, copy) NSString *strikePercent;
@property (nonatomic, copy) NSString *knockOutPercent;
@property (nonatomic, copy) NSString *knockOutType;
@property (nonatomic, copy) NSString *knockOutObFreq;
@property (nonatomic, strong) NSNumber *observationFrequency;
@property (nonatomic, copy) NSString *tenor;
@property (nonatomic, copy) NSArray <TBOmnibusAPIPositionFcnUnderlyingContractModel> *underlyingContracts;

@end

@interface TBOmnibusAPIPositionFcnUnderlyingContractModel: TBTradeAPIModel
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *initialPrice;
@property (nonatomic, copy) NSString *strikePrice;
@property (nonatomic, copy) NSString *knockOutPrice;
@property (nonatomic, copy) NSString *upBarrierPrice;
@property (nonatomic, copy) NSString *downBarrierPrice;
@end

NS_ASSUME_NONNULL_END
