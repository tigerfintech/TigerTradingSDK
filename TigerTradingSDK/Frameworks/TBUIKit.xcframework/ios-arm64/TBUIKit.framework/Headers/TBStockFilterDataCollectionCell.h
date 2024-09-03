//
//  TBStockFilterDataCollectionCell.h
//  Stock
//
//  Created by swordzhou on 2020/4/20.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBStockFilterBaseCollectionCell.h"

NS_ASSUME_NONNULL_BEGIN

@class TBTableViewCellItem;
@class TBWatchListDisplayItem;

@interface TBStockFilterDataCollectionCell : TBStockFilterBaseCollectionCell

@property (nonatomic, strong, readonly) UILabel *valueLabel;
@property (nonatomic, strong, readonly) UILabel *subValueLabel;

@property (nonatomic, strong) TBTableViewCellItem *stockItem;

- (void)update:(TBTableViewCellItem *)dataItem sequenceItem:(TBWatchListDisplayItem *)sequenceItem;

- (void)setValue:(NSString *)value subValue:(nullable NSString *)subValue;

- (void)setValue:(NSString *)value subValue:(NSString *)subValue subValuePrefix:(nullable NSString *)prefix;

- (void)setValueColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
