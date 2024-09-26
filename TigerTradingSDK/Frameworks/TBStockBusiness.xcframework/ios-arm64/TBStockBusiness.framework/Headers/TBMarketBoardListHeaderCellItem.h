//
//  TBMarketBoardListHeaderItem.h
//  Stock
//
//  Created by swordzhou on 2020/3/25.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

//#import "TBWatchListSectionHeaderItem.h"
#import <TBUIKit/TBTableViewCellItem.h>
//#import "TBMarketSHSZHKConstant.h"
#import <TBStockBusinessBaseKit/TBStockListHelper.h>
typedef NSString *TBMarketStockOrder;

FOUNDATION_EXPORT TBMarketStockOrder const _Nonnull TBMarketStockOrderDesc;
FOUNDATION_EXPORT TBMarketStockOrder const _Nonnull TBMarketStockOrderAsc;

NS_ASSUME_NONNULL_BEGIN


@interface TBMarketBoardListHeaderCellItem : TBTableViewCellItem

@property (nonatomic, strong) TBMarketStockOrder order;

@property (nonatomic, assign) TBWatchListSortType sortType;

@end

NS_ASSUME_NONNULL_END
