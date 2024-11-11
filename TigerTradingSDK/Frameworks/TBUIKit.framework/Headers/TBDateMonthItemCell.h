//
//  TBDateMonthItemCell.h
//  StockBusiness
//
//  Created by mashanli on 2023/2/8.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBCollectionViewCell.h>
@class TBDateMonthItem;

@interface TBDateMonthItemCell : TBCollectionViewCell
@property (nonatomic, strong, readonly) UIView *selectedIndicateView;//选中背景
@property (nonatomic, strong, readonly) UILabel *dateLabel;
@property (nonatomic, strong) TBDateMonthItem *monthItem;

- (void)compileLayout;

@end
