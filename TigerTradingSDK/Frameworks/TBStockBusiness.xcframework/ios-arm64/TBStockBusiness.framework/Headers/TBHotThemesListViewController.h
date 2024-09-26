//
//  TBHotThemesListViewController.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/31.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBUIKit/TBRefreshView.h>
@class TBRefreshView;
@class TBRefreshNormalHeader;
#import <MJRefresh/MJRefresh.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHotThemesListViewController : TBBaseViewController

@property (nonatomic, copy) NSString *packageId; // 默认themes
@property (nonatomic, copy) NSString *market;

@end

NS_ASSUME_NONNULL_END
