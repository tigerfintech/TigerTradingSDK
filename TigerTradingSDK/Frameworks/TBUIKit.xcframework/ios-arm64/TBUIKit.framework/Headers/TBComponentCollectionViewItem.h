//
//  TBComponentCollectionViewItem.h
//  TBComponentList
//
//  Created by JustLee on 2019/10/11.
//  Copyright © 2019 JustLee. All rights reserved.
//

#define LOCK(...) dispatch_semaphore_wait(self.lock, DISPATCH_TIME_FOREVER); \
__VA_ARGS__; \
dispatch_semaphore_signal(self.lock);

#import <Foundation/Foundation.h>
#import "TBComponentCollectionCellItem.h"

@interface TBComponentCollectionViewItem : NSObject

/// 如果需要排序请使用此初始化方法
- (instancetype)initSortItem;

/// 设置此分组内数据是否需要排序
@property (nonatomic, assign) BOOL needSort;

/// 外部展示的只读数据
@property (nonatomic, copy, readonly) NSArray <__kindof TBComponentCollectionCellItem *> *cellItems;

/// 每个分组的sectionheader的cellItem
@property (nonatomic, strong) __kindof TBComponentCollectionCellItem *sectionHeaderItem;

/// 每个分组的sectionfooter的cellItem
@property (nonatomic, strong) __kindof TBComponentCollectionCellItem *sectionFooterItem;

/// 设置此分组的insets
@property (nonatomic, assign) UIEdgeInsets sectionInsets;

/// 设置分组minmumLineSpace
@property (nonatomic, assign) CGFloat minmumLineSpace;

/// 设置分组minimumInteritemSpacing
@property (nonatomic, assign) CGFloat minimumInteritemSpacing;


/// 给当前分组添加cellItem
/// @param cellItem cellItem description
- (void)addCellItem:(__kindof TBComponentCollectionCellItem *)cellItem;

/// 通过数组对此分组添加cellItem
/// @param cellItems cellItems description
- (void)addCellItemsFromArray:(NSArray <__kindof TBComponentCollectionCellItem *> *)cellItems;

/// 通过索引删除此分组内的数据
/// @param index index description
- (void)removeCellItemWithIndex:(NSUInteger)index;

/// 删除全部数据
- (void)clearCellItems;

@end

