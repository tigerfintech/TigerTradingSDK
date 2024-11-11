//
//  TBOmnibusOrderMarginItemModel+TBConverter.h
//  TBTradeBusiness
//
//  Created by swordzhou on 7/25/23.
//

#import <TBTradeBusiness/TBTradeBusiness.h>

@class TBTradeAPIPositionItemModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusOrderMarginItemModel (TBPositionConverter)

+ (NSArray <TBOmnibusOrderMarginItemModel *> *)contractsWithMlegPostionModel:(TBTradeAPIPositionItemModel *)positionModel;

@end

NS_ASSUME_NONNULL_END
