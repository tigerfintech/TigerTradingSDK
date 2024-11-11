//
//  TBOptionStrategyBuilderStrategyOptionModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/9.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBusinessSupportKit/TBMlegWatchListProtocol.h>

NS_ASSUME_NONNULL_BEGIN
@class TBOptionInfoDetailItem;

@interface TBOptionStrategyBuilderStrategyOptionModel : JSONModel<TBMlegWatchListProtocol>

@property (nonatomic, copy) NSString *market; // 默认为USMarket
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *trade; // 买卖方向：buy/sell

@property (nonatomic, copy, readonly) NSString *expiryStr; // yyyy/MM/dd
@property (nonatomic, copy, readonly) NSString *combinedOptionSymbol;

@property (nonatomic, copy, readonly) NSString *legCombinedSymbol;

@property (nonatomic, strong, nullable) TBOptionInfoDetailItem *brief; // 期权的额外信息

@property (nonatomic, strong) NSNumber *ratio;///< 比例

@property (nonatomic, copy) NSString *yyyyMMddExpiryString;

- (instancetype)initWithSymbol:(NSString *)symbol right:(NSString *)right expiry:(NSNumber *)expiry strike:(NSString *)strike trade:(NSString *)trade ratio:(NSNumber *)ratio;

@end

@interface TBOptionStrategyBuilderStrategyOptionModel (TBTigerTrade)

- (BOOL)isBuyAction;

/// 组合属性为字典,@{"symbol":symbol,@"right":right,@"expiry":expiry,@"strike":strike,@"trade":trade}
- (NSDictionary *)getParams;

/// 是否是同一只期权（判断期权四要素）
- (BOOL)isSameOptionWithModel:(TBOptionStrategyBuilderStrategyOptionModel *)model;

@end

NS_ASSUME_NONNULL_END
