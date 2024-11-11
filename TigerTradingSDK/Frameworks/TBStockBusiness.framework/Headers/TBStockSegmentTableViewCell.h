//
//  TBStockSegmentTableViewCell.h
//  Stock
//
//  Created by luopengfei on 2019/1/29.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockSegmentTableViewCell : TBTableViewCell

@end

@interface TBStockSegmentTableViewCellItem : TBTableViewCellItem

@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, copy) NSArray *segmentTitles;

@property (nonatomic, assign) CGFloat segmentWidth;

@end

NS_ASSUME_NONNULL_END
