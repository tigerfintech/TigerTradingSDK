//
//  TBStockListOnewRowCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBStockListOneRowView;

NS_ASSUME_NONNULL_BEGIN

@interface TBStockListOnewRowCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL leftOneImageViewHidden;
@property (nonatomic, assign) CGSize leftOneImageSize;
@property (nonatomic, strong) UIImage * leftOneImage;
@property (nonatomic, copy) NSString *leftTwoText;
@property (nonatomic, copy) NSString *middleTopOneText;
@property (nonatomic, copy) NSString *middleTopTwoText;
@property (nonatomic, copy) NSString *rightTopText;
@property (nonatomic, strong) UIColor *rightTopTextColor;

- (void)applyForDisplayProperty;

@end

@interface TBStockListOnewRowCell : TBTableViewCell

@property (nonatomic, strong) TBStockListOneRowView *stockListView;

@end

NS_ASSUME_NONNULL_END
