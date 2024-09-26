//
//  TBHKStockCrossVolumeTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/6/19.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN
/*
 持股比
 */

@protocol TBHKStockCrossVolumeTableViewCell <NSObject>

@property (nonatomic, readonly) NSString *stockName;
@property (nonatomic, readonly) NSString *stockSymbol;

@property (nonatomic, readonly) NSString *stockRate;
@property (nonatomic, readonly) NSString *stockVolume;
@property (nonatomic, readonly) NSString *stockDayChange;
@property (nonatomic, readonly) UIColor *stockDayChangeColor;
@property (nonatomic, readonly) UIColor *changeRateColor;


@end

@interface TBHKStockCrossVolumeTableViewCell : TBTableViewCell

@end

@interface TBHKStockCrossVolumeTableViewCellItem : TBTableViewCellItem
@property (nonatomic, strong) id<TBHKStockCrossVolumeTableViewCell> dataSource;

@property (nonatomic, assign, getter=isHeader) BOOL header;
@end


NS_ASSUME_NONNULL_END
