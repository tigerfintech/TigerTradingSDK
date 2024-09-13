//
//  TBOptionTabBulkOrderFilterViewController.h
//  StockBusiness
//
//  Created by mashanli on 2023/7/15.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//

@class TBOptionTabBulkOrderFilterModel;
#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionTabBulkOrderFilterViewController : TBListTableViewController

@property (nonatomic, copy) NSArray<TBOptionTabBulkOrderFilterModel *> *models;
@property (nonatomic, assign, readonly) CGFloat contentHeight;
@property (nonatomic, copy) void(^completeBlock)(void);

@end

NS_ASSUME_NONNULL_END
