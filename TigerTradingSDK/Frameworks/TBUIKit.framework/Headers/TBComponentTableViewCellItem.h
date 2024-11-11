//
//  TBComponentTableViewCellItem.h
//  TBComponentTableView
//
//  Created by Just on 2019/3/18.
//  Copyright © 2019 Just. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 support both delegate and block, block first;
 if you need more selector, please implementation youself;
 */
@class TBComponentTableViewCellItem;
typedef void (^TBTableViewComponentCellActionBlock)(TBComponentTableViewCellItem *cellItem);
typedef void (^TBTableViewComponentCellLongPressBlock)(TBComponentTableViewCellItem *cellItem, UILongPressGestureRecognizer * gestureRecognizer);

@protocol TBTableViewComponentCellSelectedDelegate <NSObject>

@optional
- (void)tableViewSelectedCellItem:(TBComponentTableViewCellItem *)cellItem;
- (void)tableViewCustomActionWithCellItem:(TBComponentTableViewCellItem *)cellItem;
- (void)tableViewLongPressdCellItem:(TBComponentTableViewCellItem *)cellItem longPressGestureRecognizer:(UILongPressGestureRecognizer *)gestureRecognizer;

- (void)tableViewSelectedSectionItem:(TBComponentTableViewCellItem *)sectionItem;
- (void)tableViewCustomActionWithSectionItem:(TBComponentTableViewCellItem *)cellItem;
- (void)tableViewLongPressdSectionItem:(TBComponentTableViewCellItem *)sectionItem longPressGestureRecognizer:(UILongPressGestureRecognizer *)gestureRecognizer;


@end

@interface TBComponentTableViewCellItem : NSObject

/**
 cell identifier
 */
@property (nonatomic, copy, readonly) NSString *cellIdentifier;

/**
 cell height, default is UITableViewAutomaticDimension
 */
@property (nonatomic, assign) CGFloat cellHeight;

/**
 cell class
 */
@property (nonatomic, strong) Class cellClass;

/**
 cell xib file name
 */
@property (nonatomic, copy) NSString *nibName;

/**
 if you need sort cellItem for async data response, set a index for this item
 */
@property (nonatomic, assign) NSInteger sortIndex;

/**
 cell indexPath
 */
@property (nonatomic, strong) NSIndexPath *indexPath;

/**
 cell selected extra info
 */
@property (nonatomic, strong) id transformInfo;

/**
 cell selected block
 */
@property (nonatomic, copy) TBTableViewComponentCellActionBlock selectedBlock;

@property (nonatomic, copy) TBTableViewComponentCellLongPressBlock longPressdBlock;

/**
 section view selected block
 */
@property (nonatomic, copy) TBTableViewComponentCellActionBlock sectionSelectedBlock;

@property (nonatomic, copy) TBTableViewComponentCellLongPressBlock sectionLongPressdBlock;

/**
 cell selected delegate
 */
@property (nonatomic, weak) id<TBTableViewComponentCellSelectedDelegate> delegate;

/**
cell item's statistical name
*/
@property (nonatomic, copy) NSString *statName;

@end
