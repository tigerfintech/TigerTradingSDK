//
//  TBComponentTableViewController.h
//  TBComponentTableView
//
//  Created by Just on 2019/3/18.
//  Copyright © 2019 Just. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBComponentTableView.h"
#import "TBComponentTableViewCellItem.h"
#import "TBComponentTableViewCell.h"
#import "TBComponentTableViewItem.h"
#import "TBComponentTableViewSectionView.h"

@interface TBComponentTableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, TBTableViewComponentCellSelectedDelegate>
/**
 as the data source for the tableview
 */
@property (nonatomic, copy, readonly) NSArray <TBComponentTableViewItem *> *items;

@property (nonatomic, strong) TBComponentTableView *tableView;

- (UITableViewStyle)tableViewStyle;


- (void)reloadTableViewData;

- (void)resetTableViewConstraints;


- (void)addSectionItem:(TBComponentTableViewItem *)sectionItem;

- (void)addSectionItemsFromArray:(NSArray <TBComponentTableViewItem *> *)items;

- (void)insertSectionItem:(TBComponentTableViewItem *)sectionItem toSection:(NSUInteger)section;


- (void)addCellItem:(__kindof TBComponentTableViewCellItem *)cellItem;

- (void)addCellItemsFormArray:(NSArray <__kindof TBComponentTableViewCellItem *> *)cellItems;

- (void)addCellItem:(__kindof TBComponentTableViewCellItem *)cellItem toSection:(NSUInteger)section;

- (void)addCellItems:(NSArray <__kindof TBComponentTableViewCellItem *> *)cellItems toSection:(NSUInteger)section;


- (void)removeCellItemWithIndexPath:(NSIndexPath *)indexPath;

- (void)removeSectionItemWithSection:(NSUInteger)section;

- (void)clearItems;

- (__kindof TBComponentTableViewCellItem *)tableViewItemWithIndexPath:(NSIndexPath *)indexPath;


@end
