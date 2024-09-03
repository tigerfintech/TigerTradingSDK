//
//  TBOmnibusAssetsByCurrencyModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOmnibusContraAssetInfoModel;

@interface TBOmnibusAssetsByCurrencyModel : JSONModel

@property (nonatomic, copy) NSString *currency;

@property (nonatomic, strong) NSNumber *lockedCash;         ///< 补齐字段，与服务端接口文档保持一致 by wcy 806-交易持仓优化
@property (nonatomic, strong) NSNumber *cashBalance;
@property (nonatomic, strong) NSNumber *availableCash;
@property (nonatomic, strong) NSNumber *availableEE;
@property (nonatomic, strong) NSNumber *availableT2SettledCash;
@property (nonatomic, strong) NSNumber *accruedInterest;   ///< 利息
@property (nonatomic, strong) NSNumber *idleCashInterest;  ///< 闲置资金产生的利息
@property (nonatomic, strong) NSNumber *creditLineAmount;  ///< TBHK信用借款额度

/**
 * 913 contra账户使用，分币种这里只有两个字段：
 * - outstandingAmount
 * - offsetAmount
 */
@property (nonatomic, strong) TBOmnibusContraAssetInfoModel *contraAssetInfo;
@property (nonatomic, strong) NSNumber *cdpAvailableSellLimit;
@end


@interface TBOmnibusDelayQuoteInfo : JSONModel

@property (nonatomic, copy) NSString *market;

@property (nonatomic, strong) NSNumber *lastTime;         /// 毫秒时间戳

@end

NS_ASSUME_NONNULL_END
