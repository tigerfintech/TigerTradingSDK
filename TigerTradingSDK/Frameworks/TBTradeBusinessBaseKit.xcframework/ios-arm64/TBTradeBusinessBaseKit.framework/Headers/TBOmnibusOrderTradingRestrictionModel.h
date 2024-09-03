//
//  TBOmnibusOrderTradingRestrictionModel.h
//  TBTradeBusiness
//
//  Created by zlc on 2023/10/11.
//


#import "TBOmnibusAPIModel.h"

NS_ASSUME_NONNULL_BEGIN
@class TBOmnibusOrderTradingAmountInfoModel,TBOmnibusOrderTradingTimeRangesModel;

@interface TBOmnibusOrderTradingRestrictionModel : TBOmnibusAPIModel

@property (nonatomic, strong) NSNumber *maxSubscriptionRate;
@property (nonatomic, copy) NSDictionary *amountInfos; //Map<String, AmountInfo> 金额信息。key: 币种，value: AmountInfo
@property (nonatomic, copy) NSDictionary *tradingTimeRanges; //Map<String, TimeRangeResp> 交易时间段。key: 市场，value: TimeRangeResp

- (nullable TBOmnibusOrderTradingAmountInfoModel *)amountInfoWithCurrency:(NSString *)currency;
- (nullable TBOmnibusOrderTradingTimeRangesModel *)tradingTimeRangesWithMarket:(NSString *)market;

@end

@interface TBOmnibusOrderTradingAmountInfoModel : TBOmnibusAPIModel
@property (nonatomic, strong) NSNumber *minInvestAmount; // 起投金额，数值，例如：150000
@property (nonatomic, strong) NSNumber *maxInvestAmount; // 最大可投金额，数值，例如：3000000
@property (nonatomic, strong) NSNumber *incrementalAmount; // 递增金额，数值，例如：0.05
@end

@interface TBOmnibusOrderTradingTimeRangesModel : TBOmnibusAPIModel
@property (nonatomic, strong) NSNumber *beginHHmmss; // 左侧起始的0省略，例如：90000 (9:00:00)
@property (nonatomic, strong) NSNumber *endHHmmss; // 左侧起始的0省略，例如：153000 (15:30:00)
/**
 OPEN 左开右开
 OPEN_CLOSED 左开右闭
 CLOSED_OPEN 左闭右开
 CLOSED 左闭右闭
 */
@property (nonatomic, copy) NSString *boundType; // RangeBoundType
@property (nonatomic, copy) NSString *timeZone; // 时区，例如：GMT+8

- (NSArray<NSNumber *> *)beginHHmmssArray;
- (NSArray<NSNumber *> *)endHHmmssArray;
@end


NS_ASSUME_NONNULL_END
