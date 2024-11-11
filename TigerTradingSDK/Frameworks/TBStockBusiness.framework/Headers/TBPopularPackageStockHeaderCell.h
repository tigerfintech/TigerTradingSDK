//
//  TBPopularPackageStockHeaderCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/3.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBExcelTableHeaderCell.h>
@class TBWatchListSortItem;
#import "TBPopularPackageStockSortHelper.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBPopularPackageStockHeaderCellItem : TBExcelTableHeaderCellItem

@property (nonatomic, copy) NSString * leftTitle;
@property (nonatomic, copy) NSArray <TBWatchListSortItem *> *sortItems;
@property (nonatomic, assign, readonly) TBWatchListSortType sortType;

- (void)updateSortItems;

@end

@interface TBPopularPackageStockHeaderCell : TBExcelTableHeaderCell

@end

NS_ASSUME_NONNULL_END
