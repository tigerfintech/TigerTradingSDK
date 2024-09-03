//
//  TBTableViewController.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "TBBaseViewController.h"
#import "TBTableViewDelegate.h"
#import "TBTableView.h"
#import "TBTableEmptyView.h"
#import "TBRefreshNormalFooter.h"
#import "TBRefreshNormalHeader.h"
#import "NSArray+TBTableSectionView.h"

// 滑动列表通知，用于曝光统计等
extern NSString *const TBTableViewWillDisplayHeaderViewNotification;
extern NSString *const TBTableViewWillDisplayCellNotification;

extern NSString *const TBTableViewCellUserInfoKey; // 通知传递的TBTableViewCell类型参数的key
extern NSString *const TBTableViewControllerUserInfoKey; // 通知传递的TBTableViewController类型参数的key

@interface TBTableViewController : TBBaseViewController <TBTableViewDelegate>

@property (nonatomic, strong) TBTableView *tableView;
@property (nonatomic, assign) BOOL enablePullRefresh;
@property (nonatomic, assign) BOOL enableLoadMore;
@property (nonatomic, assign) BOOL isRefreshing;
@property (nonatomic, assign) BOOL isLoadingMore;
@property (nonatomic, assign) BOOL isShowingKeyboard;
@property (nonatomic, strong) TBTableEmptyView *emptyView;

@property (nonatomic, strong) TBTableViewCellItem *selectSectionItem;
@property (nonatomic, strong) TBTableViewCellItem *longPressSelectSectionItem;

/**
 header in section 点击手势是否禁用，默认yes，若禁用在viewdidload里置为no
 */
@property (nonatomic, assign) BOOL enableHeaderTapGesture;

/**
 header in section 长按手势是否禁用，默认NO，若启用在viewdidload里置为YES
 */
@property (nonatomic, assign) BOOL enableLongTapGesture;

- (Class) tableViewClass;

- (UITableViewStyle) tableViewStyle;

- (UITableViewCellSeparatorStyle) tableViewCellSeparatorStyleStyle;

- (void)registerForKeyboardNotifications;
- (void)unregisterForKeyboardNotifications;

/**
 为cellItem 绑定所属数组
 主要用于标的切换
 */
- (void)cellItemAddContainedArray:(UITableView *)tableView cellItem:(TBTableViewCellItem *)cellItem;

@end
