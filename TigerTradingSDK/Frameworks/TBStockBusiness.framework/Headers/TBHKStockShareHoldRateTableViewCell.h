//
//  TBHKStockShareHoldRateTableViewCell.h
//  Stock
//
//  Created by JustLee on 2020/6/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@protocol TBHKStockShareHoldRateTableViewCell <NSObject>

@property (nonatomic, readonly) NSString *stockName;
@property (nonatomic, readonly) NSString *stockSymbol;

@property (nonatomic, readonly) NSString *stockRate;
@property (nonatomic, readonly) NSString *stockVolume;
@property (nonatomic, readonly) NSString *stockDayChange;
@property (nonatomic, readonly) UIColor *stockDayChangeColor;
@property (nonatomic, readonly) UIColor *changeRateColor;

@property (nonatomic, readonly) NSString *stockChangeVolumeRate;
@property (nonatomic, readonly) NSString *stockHoldMarketValue;
@end

@interface TBHKStockShareHoldRateTableViewCell : TBTableViewCell

@property (nonatomic, strong) UIScrollView *contentScrollView;

@end

@interface TBHKStockShareHoldRateTableViewCellItem : TBTableViewCellItem
@property (nonatomic, strong) id<TBHKStockShareHoldRateTableViewCell> dataSource;

@property (nonatomic, assign, getter=isHeader) BOOL header;

@property (nonatomic, assign) CGFloat offsetX;

@end


@interface TBHKStockShareHoldRateItemView : UIView

@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, copy) NSString *text;

@property (nonatomic, strong) UIColor *textColor;

@property (nonatomic, assign) BOOL isHeader;

@property (nonatomic, strong) UIFont *font;

@end
