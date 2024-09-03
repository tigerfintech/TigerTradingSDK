//
//  TBCollectionViewCellItem.h
//  Stock
//
//  Created by Pengfei_Luo on 2017/2/27.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
#import "TTHeader.h"

@class TBCollectionViewCell;

@interface TBCollectionViewCellItem : TBObject

@property (nonatomic, strong) TTURLAction *action;
@property (nonatomic, assign) CGSize tableCellHeight;
@property (nonatomic, strong) void(^actionBlock)(void);
@property (nonatomic, assign) NSInteger tag; // 当在同一个vc使用多个相同的cell item，用于互相区分
@property (nonatomic, strong) NSIndexPath *indexPath; // 记录cell的位置
@property (nonatomic, copy) NSString *statName; // 统计项名称, 用于记录点击统计

@property (nonatomic, assign) CGFloat collectionViewWidth; // collectionViewWidth


- (Class) cellClass;

- (CGSize) cellSize;

- (CGSize) sizeForTableView:(UITableView *)inTableView;

- (id)applyAction:(TTURLAction *)action;

- (id)applyActionBlock:(void(^)(void))actionBlock;

@end
