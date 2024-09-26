//
//  TBNewPackageListTableViewController.h
//  Stock
//
//  Created by PXJ on 2020/7/14.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBPackageListTableViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBNewPackageListTableViewController : TBPackageListTableViewController

@property (nonatomic, assign) BOOL fromPrePostHourRank; // 从功能区【盘前盘后榜】进入
@property (nonatomic, assign)BOOL showPriceSort;
@property (nonatomic, strong) NSNumber *showNavigationBar;
@property (nonatomic, strong) NSNumber *isCN;
@property (nonatomic, copy) NSString *compare;
@property (nonatomic, copy) void(^updateSuperSegmentTabNameCallback)(NSDictionary *titleDict);
@property (nonatomic, copy) void(^updateSortTypeCallBack)(NSDictionary *dic);
- (void)loadPackageList:(BOOL)isLoadMore sortType:(NSString *)sortType withRefreshStatus:(void(^)(void))refreshStatus;
@end

NS_ASSUME_NONNULL_END
