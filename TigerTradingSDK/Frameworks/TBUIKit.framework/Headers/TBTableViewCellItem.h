//
//  TBTableViewCellItem.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
#import "TTHeader.h"


typedef enum : NSUInteger {
    TBTableViewCellItemTypeNone,
    TBTableViewCellItemTypeContainedArray,
} TBTableViewCellItemType;

@class TBTableViewCell;

@interface TBTableViewCellItem : TBObject

@property (nonatomic, strong) TTURLAction *action;
@property (nonatomic, assign) CGFloat tableCellHeight;
@property (nonatomic, strong) void(^actionBlock)(void);
@property (nonatomic, strong) void(^longActionBlock)(void);
@property (nonatomic, strong) UIColor *backgroundColor;

@property (nonatomic, weak) TBTableViewCell *tableViewCell;

@property (nonatomic, assign) TBTableViewCellItemType cellItemType;
/**
 包含该CellItem 的数组
 */
@property (nonatomic, weak) NSArray *containedArray;

@property (nonatomic, assign) NSInteger tag; // 当在同一个vc使用多个相同的cell item，用于互相区分
@property (nonatomic, strong) NSIndexPath *indexPath; // 记录cell的位置
@property (nonatomic, copy) NSString *statName; // 统计项名称, 用于记录点击统计（友盟统计，已不再使用）
@property (nonatomic, copy) NSString *headerTitle;//作为section Header时的标题
@property (nonatomic, strong) id extraData;

@property (nonatomic, assign) CGFloat tableViewWidth; // tableview的宽度，可能返回0 需要对0进行一个校验处理
- (CGFloat)fetchTableViewWidth_ZeroAble; // 和tableViewWidth的区别是可以接受是0（debug环境不会弹出alert）

- (Class)cellClass;

- (CGFloat)cellHeight;

- (CGFloat)heightForTableView:(UITableView *)inTableView;

//使用xib时调用
- (NSString *)nibName;
- (NSBundle *)nibBundle;

- (id)applyAction:(TTURLAction *)action;

- (id)applyActionBlock:(void(^)(void))actionBlock;

- (void)reloadCell;

@end
