//
//  TBWealthPreconditionsDataSource.h
//  TBAccountSystemKit
//
//  Created by swordzhou on 12/15/23.
//

#import "TBWealthCheckDataSource.h"

@class TBWealthCheckBaseItem;
@class TBTradePreconditionModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBWealthPreconditionsDataSource : TBWealthCheckDataSource

/**
 * @param secType [fcn treasury us_crypto_nonderivative]
 * @param action [inquiry order], 可选不支持的品种不需要传递
 * @param riskRating 产品风险等级
 */
- (void)fetchCheckItems:(NSString *)productType
                 action:(nullable NSString *)action
             riskRating:(NSNumber *)riskRating
             completion:(void(^)(NSArray<TBWealthCheckBaseItem *> *checkItems, NSString *errorMessage))completion;

/**
 * @param secType [fcn treasury us_crypto_nonderivative]
 * @param action [inquiry order], 可选不支持的品种不需要传递
 * @param userInfo 额外信息 例如标的风险等级、标的信息 {"market" : "US", "symbol" : "AAPL", "riskRating" : "1"}
 */
- (void)fetchCheckItems:(NSString *)productType
                 action:(nullable NSString *)action
               userInfo:(nullable NSDictionary *)userInfo
             completion:(void(^)(NSArray<TBWealthCheckBaseItem *> *checkItems, NSString *errorMessage))completion;

- (TBWealthCheckBaseItem *)defaultRegionCheckItem:(BOOL)passed productType:(NSString *)productType;

@end

NS_ASSUME_NONNULL_END
