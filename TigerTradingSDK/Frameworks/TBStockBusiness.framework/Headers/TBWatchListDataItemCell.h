//
//  TBWatchListDataItemCell.h
//  Stock
//
//  Created by yangfan on 2018/8/24.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBCollectionViewCell.h>

@class TBWatchListDetailColorObject;
@class TBWatchListTableCellItem;
@class TBWatchListDisplayItem;
@class TBPaddingLabel;

@interface TBWatchListDataItemCell : TBCollectionViewCell

@property (nonatomic, strong) UILabel       * valueLabel;
@property (nonatomic, strong) TBPaddingLabel       * prefixLabel;
@property (nonatomic, strong) UILabel       * subValueLabel;
@property (nonatomic, strong) TBWatchListTableCellItem       *cellItem;
@property (nonatomic, strong) TBWatchListDisplayItem       *displayItem;
@property (nonatomic, copy) NSString*       changeAmountString;
@property (nonatomic, copy) NSString*       changeRateString;
@property (nonatomic, copy) NSString*       priceString;
@property (nonatomic, strong) UIColor       *increateColor;

@property (nonatomic, assign) CGFloat       calculatedWidth; // 外部传入superview 的宽度用来计算内部UI

- (void)setValue:(NSString *)value subValue:(NSString *)subValue;
//子值的前缀
- (void)setValue:(NSString *)value subValue:(NSString *)subValue subValuePrefix:(NSString *)prefix;

- (void)setValueColor:(UIColor *)color;
- (void)setMutipleValueColor:(TBWatchListDetailColorObject *)color;
- (void)showColorBgViewIfNeed:(BOOL)show isLastColumn:(BOOL)isLast isValueCenter:(BOOL)center;

// 设置scaleFactor，numerator 分子
- (void)setValueMinimumScaleFactorNumerator: (CGFloat)numerator;

@end
