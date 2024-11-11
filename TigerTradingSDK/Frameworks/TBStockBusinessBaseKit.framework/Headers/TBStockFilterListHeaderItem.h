//
//  TBStockFilterListHeaderItem.h
//  Stock
//
//  Created by swordzhou on 2020/4/20.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBWatchListDisplayItemManager.h"
#import <TBToolsKit/TBWatchListDisplayItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockFilterListHeaderItem : TBWatchListSortItem

@property (nonatomic, copy) NSString *compare;
@property (nonatomic, copy) NSString *order;
@property (nonatomic, assign) BOOL isLastColumn;
@property (nonatomic, assign) BOOL showSortIndicator;

- (instancetype)initWithItem:(TBWatchListDisplayItem *)item itemSortType:(TBWatchListItemSortType)itemSortType;

- (instancetype)initWithItem:(TBWatchListDisplayItem *)item itemSortType:(TBWatchListItemSortType)itemSortType compare:(NSString *)compare;

- (void)updateWithItem:(TBStockFilterListHeaderItem *)item;

@end

NS_ASSUME_NONNULL_END
