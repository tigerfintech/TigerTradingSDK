//
//  TBWatchListSectionHeaderCellItem.h
//  Stock
//
//  Created by yangfan on 2018/9/3.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBWatchListDisplayItem;
#import <TBUIKit/TBTableViewCellItem.h>
#import "TBWatchListSectionHeaderItem.h"
#import "TBWatchListSectionHeaderItemCell.h"

@interface TBWatchListSectionHeaderCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL        isLandscapeMode; //是否横屏模式
@property (nonatomic, assign) BOOL        isUnflod;//全部、设置、旋转与名称代码、价格、涨跌幅显示为俩行
@property (nonatomic, copy) NSString    * title;
@property (nonatomic, assign) BOOL        hiddenBottomLine;

@property (nonatomic, assign) TBWatchListSortType sortType;
@property (nonatomic, assign) TBWatchListItemSortType nameItemSortType;
@property (nonatomic, copy) NSArray<TBWatchListDisplayItem *>     * displayItems;    //需要显示的选项内容
@property (nonatomic, assign) int portraitLastRow;
@end

@interface TBWatchListSectionHeaderCell : TBTableViewCell

@property (nonatomic, assign) BOOL                isLandscapeMode; //是否横屏模式
@property (nonatomic, copy) NSString            * title;
@property (class, nonatomic, assign) CGFloat      offsetX;
@property (class, nonatomic, strong) UIView     * scrollingView; //正在滑动的view,以使其他TBWatchListCell或者TBWatchListSectionHeaderCell不要响应它们的scrollViewDidScroll事件


@property (nonatomic, copy) NSArray<TBWatchListDisplayItem *>     * displayItems;    //需要显示的选项内容

- (void)setCollectionContentOffsetX:(CGFloat)offsetX;

-(UICollectionView *)getCollectionView;

@end
