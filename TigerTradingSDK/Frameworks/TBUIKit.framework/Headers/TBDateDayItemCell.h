//
//  TBDateDayItemCell.h
//  StockBusiness
//
//  Created by mashanli on 2023/2/8.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBCollectionViewCell.h>

@class TBDateDayItem, TBDayItemDisplayCirclesView;

@interface TBDateDayItemCell : TBCollectionViewCell
@property (nonatomic, strong, readonly) TBDayItemDisplayCirclesView *circlesView;//小点点
@property (nonatomic, strong, readonly) UILabel *dayLabel;
@property (nonatomic, strong, readonly) UIView *selectedIndicateView;//选中背景

@property (nonatomic, strong) TBDateDayItem *dayItem;
@property (nonatomic, copy) NSDictionary *keyAndColorDic;//日期下边的点对应的key与颜色值
@property (nonatomic, assign) BOOL isWeekType;      //用于week维度

- (void)compileLayout;

@end
