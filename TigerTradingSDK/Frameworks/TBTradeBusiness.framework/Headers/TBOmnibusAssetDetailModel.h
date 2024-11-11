//
//  TBOmnibusAssetDetailModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAssetDetailModel : JSONModel

@property (nonatomic, strong, nullable) NSNumber <Optional> *settled;           // 已结算资金，单位是美元
@property (nonatomic, strong) NSNumber *lockedStockValue;                       // 冻结的购买股票资金
@property (nonatomic, strong) NSNumber *lockedCommission;                       // 冻结的交易佣金
@property (nonatomic, strong) NSNumber *purchase;                               // 未结算的购买股票花掉的资金
@property (nonatomic, strong) NSNumber *sale;                                   // 未结算的卖出股票获得的资金
@property (nonatomic, strong) NSNumber *commission;                             // 未结算的交易佣金

@end

NS_ASSUME_NONNULL_END
