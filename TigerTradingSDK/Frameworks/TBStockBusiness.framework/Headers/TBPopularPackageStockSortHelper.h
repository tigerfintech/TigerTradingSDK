//
//  TBPopularPackageStockSortHelper.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/3.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TBWatchListSortItem;
#import <TBStockBusinessBaseKit/TBStockListHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPopularPackageStockSortHelper : NSObject
+ (NSArray <TBWatchListSortItem *> *)generatePackageStockFilterItems;

/// 美股市场：明星股/中概股筛选项
+ (NSArray <TBWatchListSortItem *> *)generateUSPopularPackageStockFilterItems;
/// 美股市场：重要指数筛选项
+ (NSArray <TBWatchListSortItem *> *)generateUSPopularImportantIndicesFilterItems;
/// 获取order
+ (NSString *)getOrderWithSotItem: (TBWatchListSortItem *)sortItem;
/// 获取对比字段
+ (NSString *)getCompareWithSotItem: (TBWatchListSortItem *)sortItem;
/// 从filterItems里找到当前sortType == none的sortItem
+ (TBWatchListSortItem *)getSortedItemAtFilterItems: (NSArray <TBWatchListSortItem *> *)items;
/// 是否支持变色
+ (BOOL)isUpDownColorWithSortType: (TBWatchListSortType)sortType;
@end


NS_ASSUME_NONNULL_END
