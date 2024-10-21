//
//  TBStockSearchViewController.h
//  Stock
//
//  Created by 马超 on 16/5/26.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>

@class TBStockSearchViewController;
@class TBStockInfoDetailItemModel;

@protocol TBStockSearchViewControllerDelegate <NSObject>

@optional
- (void)viewController:(TBStockSearchViewController *)viewController didTappedAddOrRemoveButton:(BOOL)isAdd stock:(TBStockInfoDetailItemModel *)stockModel completed:(void(^)(void))completed;

@end

@interface TBStockSearchViewController : TBListTableViewController<TBTableViewDelegate>

- (void)searchStockWithText:(NSString *)text isClick:(BOOL)isClick;
//刷新分组下查找股票的状态（是否加入自选）
- (void)refreshSearchItemStatusByGroup;

- (void)setGroupStockArray:(NSArray *)groupStocks;

//从自选分组中搜索
@property (nonatomic, assign) BOOL                                      searchFromGroup;
@property (nonatomic, copy) NSArray                                 * groupStocks;
@property (nonatomic, weak) id<TBStockSearchViewControllerDelegate>     groupDelegate;

@end
