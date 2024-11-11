//
//  TBOmnibusAvailableAmountModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark 内部转账
@interface TBOmnibusAvailableAmountDataModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSString *amount;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *fromSegment;
@property (nonatomic, copy) NSString *toSegment;

@end

@protocol TBOmnibusAvailableAmountDataModel <NSObject>
@end
@interface TBOmnibusAvailableAmountModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray <TBOmnibusAvailableAmountDataModel> *data;

@end

NS_ASSUME_NONNULL_END
