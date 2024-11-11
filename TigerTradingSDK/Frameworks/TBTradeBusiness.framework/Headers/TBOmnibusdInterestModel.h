//
//  TBOmnibusdInterestModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

//应计利息
@interface TBOmnibusdInterestItemModel : JSONModel
@property (nonatomic, copy) NSString *interest;
@property (nonatomic, copy) NSString *currency;
@end

@protocol TBOmnibusdInterestItemModel <NSObject>
@end

@interface TBOmnibusdInterestModel : TBOmnibusAPIModel
@property (nonatomic, copy) NSArray <TBOmnibusdInterestItemModel> *data;
@end

NS_ASSUME_NONNULL_END
