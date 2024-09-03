//
//  TBOmnibusExchangeRateModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 日末汇率
@interface TBOmnibusItemDayExchangeRateModel: TBOmnibusAPIModel

@property (nonatomic, copy) NSDictionary *data;

@end


@interface TBOmnibusItemExchangeRateModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSString *sourceCurrency;
@property (nonatomic, copy) NSString *targetCurrency;

// 907 在bff-config/currencyConfig中，获取不到基准货币对时生效
@property (nonatomic, strong) NSNumber *rate;

@property (nonatomic, copy) NSString *action; // 907 买卖方向
/** 907 基准汇率
 *  - 在bff-config/currencyConfig中，拿到基准货币对时生效
 *  - 永远都是基准货币对的汇率，例如, 无论兑出是usd还是hkd, 都是 `1usd= (1 * price) hkd`
 */
@property (nonatomic, strong) NSNumber *price;
@end

@protocol TBOmnibusItemExchangeRateModel;
@interface TBOmnibusExchangeRateModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusItemExchangeRateModel> *data;

/**
 907 根据原始货币和目标货币获取汇率（price)

 说明：返回的是基准货币的汇率。
 例如：基准货币：eg: usd -> sgd，
 - 输入是usd->sgd时，action是SELL
 - 输入是sgd->usd，action是BUY
 - 返回的都是usd->sgd的汇率，只不过汇率不同（server处理）

 @param originalCurrency 原始货币
 @param targetCUrrency 目标货币
 @param action 方向 BUY OR SELL
 @return 返回**基准货币**的汇率
 */
- (nullable NSNumber *)getPriceOriginalCurrency:(NSString *)originalCurrency targetCurrrency:(NSString *)targetCurrency action:(NSString *)action;

/**
 根据原始货币和目标货币获取汇率

 @param originalCurrency 原始货币
 @param targetCUrrency 目标货币
 @return 原始货币/目标货币的汇率
 */
- (NSNumber *)getRateOriginalCurrency:(NSString *)originalCurrency targetCurrrency:(NSString *)targetCurrency;
/**
 @param originalCurrency 原始货币
 @param targetCUrrency 目标货币
 @return 汇率对是否存在
 */
- (BOOL)exchangeRateAvailable:(NSString *)originalCurrency to:(NSString *)targetCurrency;

@end

NS_ASSUME_NONNULL_END
