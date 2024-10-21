//
//  TBStockGroupListCell.h
//  Stock
//
//  Created by yangfan on 2017/3/9.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TBWatchListGroup;

@class TBStockGroupListCell;

@protocol TBStockGroupListCellDelegate <NSObject>

@optional

- (void)groupListDidTappedDeleteButton:(TBStockGroupListCell *)cell;

- (void)groupListDidTappedGoTopButton:(TBStockGroupListCell *)cell;

- (void)groupListDidTappedTitleLabel:(TBStockGroupListCell *)cell;
- (void)groupListDidTappedDeleteButton:(TBStockGroupListCell *)cell withIndex:(NSIndexPath *)indexPath;

- (void)onTappedHide;
@end

@interface TBStockGroupListCell : UITableViewCell

@property (nonatomic, assign) BOOL showDeleteButton;
@property (nonatomic, strong) TBWatchListGroup  *group;
@property (nonatomic, strong) NSIndexPath *indexPath;
@property (nonatomic, assign) BOOL isEditMode;

@property (nonatomic, weak) id<TBStockGroupListCellDelegate> delegate;

@end
