//
//  TBPopularPackageViewController.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/2.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBExcelTableViewController.h>
#import <MJRefresh/MJRefresh.h>
#import <TBUIKit/TBRefreshNormalFooter.h>
#import "TBMarketConditionsUntils.h"


NS_ASSUME_NONNULL_BEGIN

@interface TBPopularPackageViewController : TBExcelTableViewController

// require: 初始化参数
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *packageID;
@property (nonatomic, assign) TBStockPackageListType listType;
@property (nonatomic, assign, getter=isSupportLoadMore) BOOL supportLoadMore; // 支持分页需要加载更多

@property (nonatomic, copy) NSString *sortType;
@property (nonatomic, readonly) NSString *requestPath; // 请求路径

- (void)setInit;
- (void)endHeaderFooterRefreshing;

- (void)loadPackageList:(BOOL)isLoadMore sortType:(NSString *)sortType;
- (void)loadPackageList:(BOOL)isLoadMore sortType:(NSString *)sortType withRefreshStatus:(void(^)(void))refreshStatus;
@end

NS_ASSUME_NONNULL_END
