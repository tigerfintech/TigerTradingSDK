//
//  TBOmnibusTradeDetailModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBOmnibusTradeDetailDataItemModel <NSObject>

@end

@interface TBOmnibusTradeDetailDataModel : JSONModel

@property (nonatomic, copy) NSArray <TBOmnibusTradeDetailDataItemModel> *tradeDetailList;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, strong) NSNumber *realizedPnl;
@end

@interface TBOmnibusTradeDetailModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusTradeDetailDataModel *data;

@end

@interface TBOmnibusTradeRecordsModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusTradeDetailDataItemModel> *data;

@end


NS_ASSUME_NONNULL_END
