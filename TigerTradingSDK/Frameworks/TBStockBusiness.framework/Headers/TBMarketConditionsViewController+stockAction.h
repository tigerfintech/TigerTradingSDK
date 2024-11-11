//
//  TBMarketConditionsViewController+stockAction.h
//  Stock
//
//  Created by 王灵博 on 2020/9/9.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBMarketConditionsViewController.h"
#import <TBStockBusiness/TBMarketSectorCell.h>
@class TBMarketSectorCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketConditionsViewController (stockAction)
- (void)marketSectorCellItem:(TBMarketSectorCellItem *)cell sectorType:(MarketSectorType)type didTappedItemAtIndex:(NSUInteger)index;

- (void)optionBuriedPointWithPackageId:(NSString *)packageId;
@end

NS_ASSUME_NONNULL_END
