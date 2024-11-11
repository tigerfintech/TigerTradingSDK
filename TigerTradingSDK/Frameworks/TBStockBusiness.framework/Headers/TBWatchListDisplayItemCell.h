//
//  TBWatchListDisplayItemCell.h
//  Stock
//
//  Created by yangfan on 2018/8/23.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBWatchListDisplayItem;

@class TBWatchListDisplayItemCell;

@protocol TBWatchListDisplayItemCellDelegate <NSObject>

@optional
- (void)displayItemDidChangedStatus:(TBWatchListDisplayItemCell *)cell;

@end

@interface TBWatchListDisplayItemCell : TBTableViewCell

@property (nonatomic, strong) TBWatchListDisplayItem * option;
@property (nonatomic, weak) id<TBWatchListDisplayItemCellDelegate>  ownDelegate;
@property (nonatomic, assign) BOOL            isLandscapeMode;     //是否横屏模式

- (void)setNameCell;

@end
