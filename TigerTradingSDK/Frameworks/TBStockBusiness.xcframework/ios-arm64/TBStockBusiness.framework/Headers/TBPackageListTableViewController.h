//
//  TBPackageListTableViewController.h
//  Stock
//
//  Created by luopengfei on 2018/1/15.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
@class TBRefreshNormalHeader;
@class TBRefreshNormalFooter;
@class TBMarketPackageListHeaderItem;
@class TBAHStockPackageSectionHeaderItem;
@class TBStockSegmentTableViewCellItem;
@class TBEmptyTableViewCellItem;
#import <MJRefresh/MJRefresh.h>

#import "TBMarketConditionsUntils.h"


@interface TBPackageListTableViewController : TBListTableViewController

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *packageID;

@property (nonatomic, assign) TBStockPackageListType listType;
@property (nonatomic, strong) TBRefreshNormalHeader *refreshHeaderView;
@property (nonatomic, strong) TBRefreshNormalFooter * refreshFooter;

@property (nonatomic, copy) NSString *marketID;

@property (nonatomic, copy) NSString *sortType;
//继承而用
@property (nonatomic, readonly) NSString *requestPath; // 请求路径
@property (nonatomic, assign) NSInteger pageNumber;
@property (nonatomic, copy) NSArray *headers;
@property (nonatomic, readonly) BOOL isNeedSort; // 接口是否支持排序
@property (nonatomic, strong) TBMarketPackageListHeaderItem *headerItem;
@property (nonatomic, strong) TBAHStockPackageSectionHeaderItem *ahHeaderItem;
@property (nonatomic, strong) TBStockSegmentTableViewCellItem *bottomSegmentCellItem;
@property (nonatomic, strong) TBEmptyTableViewCellItem *emptyCellItem;
@property (nonatomic, readonly) BOOL isSupportLoadMore; // 支持分页需要加载更多
@property (nonatomic, strong) NSMutableArray *bottomConstituentsArray; // 底部成分股

@property (nonatomic, strong) NSMutableArray *turnOverArray;
@property (nonatomic, strong) NSMutableArray *netPurchaseArray;
@property (nonatomic, assign) NSInteger netPurchasePage;

@property (nonatomic, strong) NSMutableArray *crossVolumeArray;
@property (nonatomic, assign) NSInteger crossVolumePage;

@property (nonatomic, copy) NSArray *dateArray;

- (void)setInit;
- (void)endHeaderFooterRefreshing;
- (void)loadMarketConnectNetPurchase:(NSString *)orderName order:(NSString *)order loadMore:(BOOL)loadMore;
- (void)loadMarketConnectCrossVolume:(NSString *)orderName order:(NSString *)order loadMore:(BOOL)loadMore;
- (void)loadPackageList:(BOOL)isLoadMore sortType:(NSString *)sortType;
@end
