//
//  TBTableContainerView.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/13.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBTableView.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBTableContainerViewDelegate <NSObject>

- (void) tableContainerViewHandleActionForCell:(TBTableViewCell *)cell object:(TBTableViewCellItem *)item info:(id)info;

@end

@interface TBTableContainerView : UIView

@property (nonatomic, weak) id<TBTableContainerViewDelegate> delegate;

@property (nonatomic, assign, getter=isRefreshing) BOOL refreshing;

@property (nonatomic, strong) TBTableView * tableView;

@property (nonatomic, copy) NSArray <NSArray *> * items;

@end

NS_ASSUME_NONNULL_END
