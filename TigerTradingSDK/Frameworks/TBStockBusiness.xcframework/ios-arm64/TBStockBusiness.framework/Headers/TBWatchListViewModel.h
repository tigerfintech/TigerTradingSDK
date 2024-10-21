//
//  TBWatchListViewModel.h
//  Stock
//
//  Created by zhengzhiwen on 2020/9/7.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBWatchListSectionHeaderItem.h"
#import "TBWatchListSectionHeaderItemCell.h"

NS_ASSUME_NONNULL_BEGIN

@class TBWatchListDataController;
@interface TBWatchListViewModel : NSObject

@property (nonatomic, strong) TBWatchListDataController *dataController;

@property (nonatomic, copy, nullable) NSArray *defaultMarkTitleArray;
@property (nonatomic, copy) NSArray *defaultMarkDataArray;

@property (nonatomic, copy, readonly) NSDictionary *sortWathListArrayPropertyMap;
@property (nonatomic, assign) TBWatchListSortType sortType;

@property (nonatomic, assign) TBWatchListItemSortType nameItemSortType; //名称代码排序 none/des/inc

- (void)setupData;
- (NSArray *)stocksWithMarket:(TBWatchListMarketType)market inWatchlist:(NSArray *)array;

- (NSArray *)sortItemBySmartSorting:(NSArray *)items;
- (BOOL)currentSortTypeIsExtendType;
- (NSArray *)sortWatchListDisplayList:(NSArray *)watchList marketType:(TBWatchListMarketType)mt;
- (NSArray *)sortWatchListItems:(NSArray *)items byMarketType:(TBWatchListMarketType)marketType sortType:(TBWatchListSortType)sortType;


//定时器刷新更新大盘指数
- (NSDictionary *)refreshIndicesArrayData:(NSArray *)indexArray;
//第一次请求更新大盘指数
- (NSDictionary *)getStockDetailBottomIndexInfoArray:(NSArray *)indexArray;
- (NSArray *)sortWatchListArrayWithProperty:(NSArray *)itemArray propertyName:(NSString *)propertyName isIncrease:(BOOL)isIncrease;

@end

NS_ASSUME_NONNULL_END
