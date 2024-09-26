//
//  TBStockRankSegmentCell.h
//  Stock
//
//  Created by 王灵博 on 2020/7/23.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBRankSegmentCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockRankSegmentCell : TBRankSegmentCell

@end

@interface TBStockRankSegmentCellItem : TBRankSegmentCellItem

@property (nonatomic, copy) NSString *title;

@property (nonatomic, copy) NSString *packageId;

@property (nonatomic, copy) NSString * pageURL;
@property (nonatomic, strong) UIColor *selectedColor;


@end

NS_ASSUME_NONNULL_END
