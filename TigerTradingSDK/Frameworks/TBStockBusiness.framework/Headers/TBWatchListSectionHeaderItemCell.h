//
//  TBWatchListSectionHeaderItemCell.h
//  Stock
//
//  Created by yangfan on 2018/8/28.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBCollectionViewCell.h>
@class TBWatchListDisplayItem;

@class TBWatchListSectionHeaderItemCell;
@protocol TBWatchListSectionHeaderToolRightViewDelegate <NSObject>

@optional

- (void)headerItemCellDidChangedSort:(TBWatchListSectionHeaderItemCell *)cell;
@end

@interface TBWatchListSectionHeaderItemCell : UICollectionViewCell

@property (nonatomic, strong) TBWatchListDisplayItem * item;
@property (nonatomic, assign) BOOL showLandscape;   //是否显示横屏按钮
@property (nonatomic, weak) id<TBWatchListSectionHeaderToolRightViewDelegate> delegate;

- (void)refreshLongPressGesture:(BOOL)enable;
- (void)refreshStyleIsVerticalLastColumn:(BOOL)isVerticalLastColumn;

@end



