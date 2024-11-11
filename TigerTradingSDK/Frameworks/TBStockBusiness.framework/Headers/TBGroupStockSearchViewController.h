//
//  TBGroupStockSearchViewController.h
//  Stock
//
//  Created by yangfan on 2017/5/2.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>

@class TBGroupStockSearchViewController;

@protocol TBGroupStockSearchViewControllerDelegate <NSObject>

@optional

- (void)onTappedDismissButton:(TBGroupStockSearchViewController *)searchViewController;

@end

@interface TBGroupStockSearchViewController : TBListTableViewController

@property (nonatomic, copy) NSArray                                       * groupStocks;
@property (nonatomic, weak) id<TBGroupStockSearchViewControllerDelegate>      delegate;
@property (nonatomic, assign) BOOL                                            comesFromGroupManager;
@property (nonatomic, assign) BOOL                                            comesFromWatchlist; // 从自选页进入

+ (NSArray *)convertWatchListItemToSearchItem:(NSArray * )watchlistArray;

@end
