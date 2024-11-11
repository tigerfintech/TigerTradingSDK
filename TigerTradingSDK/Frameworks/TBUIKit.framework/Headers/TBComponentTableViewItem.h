//
//  TBComponentTableViewItem.h
//  TBComponentTableView
//
//  Created by Just on 2019/4/1.
//  Copyright © 2019 Just. All rights reserved.
//

#define LOCK(...) dispatch_semaphore_wait(self.lock, DISPATCH_TIME_FOREVER); \
__VA_ARGS__; \
dispatch_semaphore_signal(self.lock);

#import <Foundation/Foundation.h>
#import "TBComponentTableViewCell.h"

/**
 tableview item that encapsulates the cell and cellitem
 */
@interface TBComponentTableViewItem : NSObject

- (instancetype)initSortItem;

/**
 if you need sort cell for severl async data response, set to YES
 */
@property (nonatomic, assign) BOOL needSort;

@property (nonatomic, copy, readonly) NSArray <__kindof TBComponentTableViewCellItem *> *cellItems;

@property (nonatomic, strong) __kindof TBComponentTableViewCellItem *sectionHeaderItem;

@property (nonatomic, strong) __kindof TBComponentTableViewCellItem *sectionFooterItem;


- (void)addCellItem:(__kindof TBComponentTableViewCellItem *)cellItem;

- (void)addCellItemsFromArray:(NSArray <__kindof TBComponentTableViewCellItem *> *)cellItems;

- (void)removeCellItemWithIndex:(NSUInteger)index;

- (void)clearCellItems;

@end
