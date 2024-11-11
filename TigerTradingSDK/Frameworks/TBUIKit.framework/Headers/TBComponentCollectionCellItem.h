//
//  TBComponentCollectionCellItem.h
//  TBComponentList
//
//  Created by JustLee on 2019/10/11.
//  Copyright © 2019 JustLee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 support both delegate and block, block first;
 if you need more selector, please implementation yourself;
 */
@class TBComponentCollectionCellItem;
@class TBComponentCollectionCell;

typedef void (^TBCollectionViewComponentCellActionBlock)(TBComponentCollectionCellItem *cellItem);
typedef void (^TBCollectionViewComponentCellLongPressBlock)(TBComponentCollectionCellItem *cellItem, UILongPressGestureRecognizer * gestureRecognizer);

@protocol TBComponentCollectionViewCellSelectedDelegate <NSObject>

@optional
- (void)collectionViewSelectedCellItem:(TBComponentCollectionCellItem *)cellItem;
- (void)collectionViewCustomActionWithCellItem:(TBComponentCollectionCellItem *)cellItem;
- (void)collectionViewLongPressedCellItem:(TBComponentCollectionCellItem *)cellItem longPressGestureRecognizer:(UILongPressGestureRecognizer *)gestureRecognizer;

- (void)collectionViewSelectedSectionItem:(TBComponentCollectionCellItem *)sectionItem;
- (void)collectionViewLongPressedSectionItem:(TBComponentCollectionCellItem *)sectionItem longPressGestureRecognizer:(UILongPressGestureRecognizer *)gestureRecognizer;
- (void)collectionViewCustomActionWithSectionItem:(TBComponentCollectionCellItem *)cellItem;
@end


@interface TBComponentCollectionCellItem : NSObject

/**
 collectionViewCell的标识，可通过子类重写属性进行自定义
 */
@property (nonatomic, copy, readonly) NSString *collectionViewCellIdentifier;

/**
 collectionview cell size, 默认为 CGSizeZero
 如果需要默认size，请重写此方法getter，自定义传入即可
 */
@property (nonatomic, assign) CGSize collectionViewCellSize;

/**
 collectionViewCellClass，用于注册cellClass
 */
@property (nonatomic, strong) Class collectionViewCellClass;

/**
 如果需要指定cell顺序，可以指定展示index，适用于多个网络请求聚合的数据页面
 */
@property (nonatomic, assign) NSInteger sortIndex;

/**
 cell indexPath，外展属性
 */
@property (nonatomic, strong) NSIndexPath *indexPath;

/**
 cell点击时，需要外传的信息
 */
@property (nonatomic, strong) id transformInfo;

/**
 为cell点击操作设置的block
 */
@property (nonatomic, copy) TBCollectionViewComponentCellActionBlock selectedBlock;

@property (nonatomic, copy) TBCollectionViewComponentCellLongPressBlock longPressedBlock;

/**
 为sectionHeader、Footer点击操作设置的block
 */
@property (nonatomic, copy) TBCollectionViewComponentCellActionBlock sectionSelectedBlock;

@property (nonatomic, copy) TBCollectionViewComponentCellLongPressBlock sectionLongPressedBlock;

/**
 自定的代理属性，设置用于于cellItem的delegate
 */
@property (nonatomic, weak) id<TBComponentCollectionViewCellSelectedDelegate> delegate;

/**
 预留的cell点击的统计事件字段
 */
@property (nonatomic, copy) NSString *statName;

@property (nonatomic, weak) TBComponentCollectionCell *collectionCell;

- (void)reloadCell;

@end

