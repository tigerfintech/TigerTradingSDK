//
//  TBBoardListViewController.h
//  Stock
//
//  Created by liwt on 11/4/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBUIKit/TBRefreshView.h>
@class TBRefreshView;
@class TBRefreshNormalHeader;
#import <MJRefresh/MJRefresh.h>
#import "TBMarketBoardPackageListHeaderItem.h"

@interface TBStockBoardListViewController : TBListTableViewController<TBRefreshViewDelegate>


@property (nonatomic, assign) TBWatchListSortType sortType;
@property (nonatomic, strong) NSMutableDictionary *orginDict4Sort;

@property (nonatomic, strong) TBRefreshView *refreshView;

@property (nonatomic, assign) BOOL is_Level2;

@property (nonatomic, copy) NSString *titleName;
@property (nonatomic, copy) NSString *marketType;
@property (nonatomic, strong) NSMutableArray *header;
@property (nonatomic, strong) NSMutableArray *data;
@property (nonatomic, copy) NSString *packageId;

@property (nonatomic, strong) TBRefreshNormalHeader *refreshHeaderView;

@property (atomic, strong) NSTimer *refreshTimer;
@property (nonatomic, assign) BOOL isShown;
@property (nonatomic, assign) BOOL isFirstTime;

@property (nonatomic, assign) BOOL isNavigationBarHidden; // navBar 隐藏，默认为NO

- (void)loadData:(BOOL)showLoading callBack:(nullable dispatch_block_t)block;

@end
