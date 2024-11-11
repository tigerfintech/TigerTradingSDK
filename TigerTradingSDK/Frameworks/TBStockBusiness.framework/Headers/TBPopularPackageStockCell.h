//
//  TBPopularPackageStockCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/2.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBExcelTableCell.h>
@class TBWatchListSortItem;
@class TBPopularPackageStockItemsDataModel;
NS_ASSUME_NONNULL_BEGIN


@interface TBPopularPackageStockCellItem : TBExcelTableCellItem

@property (nonatomic, copy, readonly) NSString *nameCN;
@property (nonatomic, copy, readonly) NSString *symbol;
@property (nonatomic, copy, readonly) NSString *market;
@property (nonatomic, strong, readonly) TBPopularPackageStockItemsDataModel * model;

@property (nonatomic, copy, readonly) NSArray <TBWatchListSortItem *> *sortItems;

- (TBPopularPackageStockCellItem *)applyDataModel: (TBPopularPackageStockItemsDataModel *)model withSortItmes: (NSArray <TBWatchListSortItem *> *)sortItems;

@end

@interface TBPopularPackageStockCell : TBExcelTableCell


@end



NS_ASSUME_NONNULL_END
