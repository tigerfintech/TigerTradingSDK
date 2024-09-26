//
//  TBMarketConditionsViewController+MarketData.h
//  Stock
//
//  Created by 王灵博 on 2020/9/4.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBMarketConditionsViewController.h"
@class TBBroaderMarketTipViewCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketConditionsViewController (MarketData)

- (void)setupIndicesCellItem;
- (void)setUpAndDownCellItem;
- (void)seManyEntranceCellItem;
- (void)seNewCalendarCellItem;
- (void)setChangesTodayCellItem;
- (void)didFetchChangesTodayData:(NSArray<TBBroaderMarketTipViewCellItem *> *)array;
- (void)setupindustryHotCellItem;
- (void)setupMoreRanks;
- (void)setupAutoInvestRanks;
- (void)setupUsualRanks;
- (void)setupUSHKOptionRanks;
- (void)setupMarketWide;
- (void)setUpMarketWarrantBullBear;
- (void)setupTodayCellItem;
- (void)setupUKETFCellItem;
- (void)setupEmptyCellItemWithHeight: (CGFloat)height; // 有的市场需要占位section
- (void)setUnusualOptions;
- (void)setupConceptsCellItems;

/// ETF 榜单
- (void)setupETFRanks;

- (void)setupAutoInvestRanks:(BOOL)showLoading clearData:(BOOL)clearData;

@end

NS_ASSUME_NONNULL_END
