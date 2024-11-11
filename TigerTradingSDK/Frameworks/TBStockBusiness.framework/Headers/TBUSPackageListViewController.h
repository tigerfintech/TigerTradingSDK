//
//  TBUSPackageListViewController.h
//  Stock
//
//  Created by 马超 on 2017/4/28.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import <MJRefresh/MJRefresh.h>
#import "TBWatchListSectionHeaderItem.h"
#import <TBUIKit/TBRefreshView.h>

@interface TBUSPackageListViewController : TBListTableViewController<TBRefreshViewDelegate>

@property (nonatomic, copy) NSString *marketType;
@property (nonatomic, copy) NSString *packageId;
@property (nonatomic, copy) NSString *titleName;

@end
