//
//  TBTableViewDelegate.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>


@class TBTableViewCell;
@class TBTableViewCellItem;
@protocol TBTableViewDelegate <NSObject, UITableViewDelegate, UITableViewDataSource>


@required
- (void) handleActionForCell:(TBTableViewCell *)cell object:(TBTableViewCellItem *)item info:(id)info;

@optional
- (void) handleActionForCell:(TBTableViewCell *)cell item:(TBTableViewCellItem *)item object:(id)object info:(id)info;

@optional

- (id) objectForTableView:(UITableView *)inTableView atIndex:(NSIndexPath *)indexPath;
- (void)didSelectObject:(id)inObject forTableView:(UITableView *)inTableView atIndex:(NSIndexPath *)indexPath;
- (id) objectForTableViewSectionHeader:(UITableView *)inTableView atSection:(NSInteger)section;
- (id) objectForTableViewSectionFooter:(UITableView *)inTableView atSection:(NSInteger)section;

@end
