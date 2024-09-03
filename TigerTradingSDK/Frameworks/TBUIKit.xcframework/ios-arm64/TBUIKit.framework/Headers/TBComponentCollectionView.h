//
//  TBComponentCollectionView.h
//  TBComponentList
//
//  Created by JustLee on 2019/10/15.
//  Copyright © 2019 JustLee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBComponentCollectionViewItem.h"
#import "TBComponentCollectionCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBComponentCollectionView : UICollectionView <UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

/// 瀑布流
/// @param frame frame description
- (instancetype)initWaterFlowLayoutCollectionViewWithFrame:(CGRect)frame;

/**
 设置布局方向
 */
@property (nonatomic, assign) UICollectionViewScrollDirection scrollDirection;

/**
 是否展示自定义滚动条
 */
@property (nonatomic, assign) BOOL showsCustomScrollIndicator;

/**
 自延展cell点击代理
 */
@property (nonatomic, weak) id<TBComponentCollectionViewCellSelectedDelegate> cellSelectedDelegate;

@property (nonatomic, weak) id<UIScrollViewDelegate> scrollDelegate;

/**
 外部只读sectionItem
 */
@property (nonatomic, copy, readonly) NSArray <TBComponentCollectionViewItem *> *items;


/// 刷新collectionView数据
- (void)reloadCollectionViewData;

/// 添加sectionItem
/// @param sectionItem sectionItem description
- (void)addSectionItem:(TBComponentCollectionViewItem *)sectionItem;

/// 通过数组添加sectionItem
/// @param items items description
- (void)addSectionItemsFromArray:(NSArray <TBComponentCollectionViewItem *> *)items;

/// 通过section插入sectionItem
/// @param sectionItem sectionItem description
/// @param section 插入位置的indexPath.section
- (void)insertSectionItem:(TBComponentCollectionViewItem *)sectionItem toSection:(NSUInteger)section;

/// 添加cellItem
/// @param cellItem cellItem description
- (void)addCellItem:(__kindof TBComponentCollectionCellItem *)cellItem;

/// 通过数组添加cellItem
/// @param cellItems cellItems description
- (void)addCellItemsFormArray:(NSArray <__kindof TBComponentCollectionCellItem *> *)cellItems;

/// 对指定位置分组添加cellItem
/// @param cellItem cellItem description
/// @param section 指定位置indexPath.section
- (void)addCellItem:(__kindof TBComponentCollectionCellItem *)cellItem toSection:(NSUInteger)section;

/// 使用数组，对指定位置添加cellItem
/// @param cellItems cellItems description
/// @param section 指定位置indexPath.sectoin
- (void)addCellItems:(NSArray <__kindof TBComponentCollectionCellItem *> *)cellItems toSection:(NSUInteger)section;

/// 通过indexPath删除cellItem
/// @param indexPath indexPath description
- (void)removeCellItemWithIndexPath:(NSIndexPath *)indexPath;

/// 通过indexPath.section删除SectionItem
/// @param section section description
- (void)removeSectionItemWithSection:(NSUInteger)section;

/// 删除所有数据
- (void)clearItems;

/// 通过section获取
/// @param section section
- (__kindof TBComponentCollectionViewItem *)collectionViewSectionItemWithSection:(NSInteger)section;

/// 获取header或者footer item
/// @param elementKind elementKind description
/// @param indexPath indexPath description
- (__kindof TBComponentCollectionCellItem *)collectionViewSupplementaryViewOfKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;

/// 通过indexPath获取cellItem
/// @param indexPath indexPath description
- (__kindof TBComponentCollectionCellItem *)collectionViewItemWithIndexPath:(NSIndexPath *)indexPath;


@end

NS_ASSUME_NONNULL_END
