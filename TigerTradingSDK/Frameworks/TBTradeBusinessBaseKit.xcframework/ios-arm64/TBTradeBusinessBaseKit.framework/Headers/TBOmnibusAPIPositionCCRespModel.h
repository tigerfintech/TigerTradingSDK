//
//  TBOmnibusAPIPositionCCRespModel.h
//  TBTradeBusiness
//
//  Created by zlc on 2024/3/8.
//

#import "TBTradeAPIModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBOmnibusAPIPositionCCTradeContractKeysDataModel;
@interface TBOmnibusAPIPositionCCRespModel : TBTradeAPIModel

@property (nonatomic, copy) NSArray <TBOmnibusAPIPositionCCTradeContractKeysDataModel> *tradeContractKeys;

@end


@interface TBOmnibusAPIPositionCCTradeContractKeysDataModel : TBTradeAPIModel

@property (nonatomic, strong) NSNumber *contractId;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *secType;

@end


NS_ASSUME_NONNULL_END
