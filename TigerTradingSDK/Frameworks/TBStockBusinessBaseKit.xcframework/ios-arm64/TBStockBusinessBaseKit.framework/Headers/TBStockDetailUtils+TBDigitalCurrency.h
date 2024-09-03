//
//  TBStockDetailUtils+TBDigitalCurrency.h
//  TBStockBusiness
//
//  Created by zhenglanchun on 2022/2/24.
//

#import "TBStockDetailUtils.h"

#define SecInfoRealLotSize(secInfo) ([TBStockDetailUtils realLotSizeWithSecInfo:(secInfo)])

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailUtils (TBDigitalCurrency)

+ (NSNumber *)realLotSizeWithSecInfo:(id<TBStockDetailInfoDataSource>)secInfo;

@end

NS_ASSUME_NONNULL_END
