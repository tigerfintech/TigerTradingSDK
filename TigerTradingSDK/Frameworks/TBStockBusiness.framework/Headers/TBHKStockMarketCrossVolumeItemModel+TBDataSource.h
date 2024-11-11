//
//  TBHKStockMarketCrossVolumeItemModel+TBDataSource.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/5/31.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBHKStockMarketCrossVolumeModel.h"
#import "TBHKStockCrossVolumeTableViewCell.h"
#import "TBHKStockShareHoldRateTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBHKStockMarketCrossVolumeItemModel (TBDataSource) <TBHKStockCrossVolumeTableViewCell, TBHKStockShareHoldRateTableViewCell>

@end

NS_ASSUME_NONNULL_END
