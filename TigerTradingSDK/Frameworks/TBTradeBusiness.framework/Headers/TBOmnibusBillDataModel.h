//
//  TBOmnibusBillDataModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBAccountBillItemModel;

@interface TBOmnibusBillDataModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBAccountBillItemModel *data;

@end

NS_ASSUME_NONNULL_END
