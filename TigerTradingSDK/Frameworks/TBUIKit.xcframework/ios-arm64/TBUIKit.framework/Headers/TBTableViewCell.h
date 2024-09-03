//
//  TBTableViewCell.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBTableViewDelegate.h"
#import "TBTableViewCellItem.h"
#import "TBAppColorManager.h"
#import "TBCommonAppColor.h"
//#import <TBUIKit/UIView+Shadow.h>
//#import <TBStockKit/UIImageView+TBStock.h>

@class TBViewExposureLogicModel;

@interface UITableViewCell (reuse)

+ (id)dequeueCellForTableView:(UITableView *)inTableView;
//增加xib复用支持
+ (id)dequeueCellForTableView:(UITableView *)inTableView nibName:(NSString *)nibName __attribute__((deprecated("+ (id)dequeueCellForTableView:(UITableView *)inTableView nibName:(NSString *)nibName bundle:(NSBundle *)bundle")));

//增加xib复用支持
+ (id)dequeueCellForTableView:(UITableView *)inTableView nibName:(NSString *)nibName bundle:(NSBundle *)bundle;


+ (CGFloat)heightForObject:(TBTableViewCellItem *)inItem tableView:(UITableView *) inTableView;

@end

@interface TBTableViewCell : UITableViewCell
{
    TBTableViewCellItem *_tableViewCellItem;
}

@property (nonatomic, weak) TBTableViewCellItem *tableViewCellItem;

@property (nonatomic, weak) id<TBTableViewDelegate> delegate;

@property (nonatomic, weak) UIColor *cellBackgroundColor;
@property (nonatomic, weak) UIColor *selectedBackgroundColor;

@property (nonatomic, weak) UITableView *tableView;

@property (nonatomic, assign) TBAppColorStyle currentColorStyle;///< 当前的主题

/*
 如果cell包含scrollView且vc在segmentedPager里，左右滑动时需要禁用segmentedPager滑动，防止手势冲突
 */
@property (nonatomic, assign) BOOL disableSegmentedPagerScrollIfNeeded;

- (void)reloadCell;

/// 可带动画刷新cell高度
- (void)reloadCellAnimated:(BOOL)animated;

/// 视图上的子视图，如果超出父视图的部分就截取掉
- (void)tbClipsToBounds;

/// 主题改变后检查 是否需要更改 展示的颜色，返回 YES 表示 主题色已更换；NO 表示主题色 未更换
- (BOOL)changeDisplayColorIfNeed;

@end
