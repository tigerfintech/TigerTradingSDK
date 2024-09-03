//
//  TBHKStockTenLevelTableViewCell.h
//  Stock
//
//  Created by Pengfei_Luo on 16/3/23.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@class TBStockAskBidLevelItemModel;
@class TBHKStockTradeTickModel;
@interface TBHKStockTenLevelTableViewCell : TBTableViewCell

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *priceLabel;
@property (nonatomic, strong) UILabel *volumnLabel;
@property (nonatomic, strong) UILabel *timeLabel;

@property (nonatomic, strong) TBStockAskBidLevelItemModel *levelModel;


@property (nonatomic, strong) UIImageView *iconImageView;


@property (nonatomic, assign) double preClose;
@property (nonatomic, assign) double realPreClose;

//- (void)isBuy:(BOOL)buy index:(NSInteger)index;
//- (double)getPrice;
- (void)updateCellWithPrice:(double)price;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *symbol;

- (void)updateIconImage:(UIImage *)img;

@property (nonatomic, assign) BOOL unfold;
@property (nonatomic, strong) NSIndexPath *indexPath;
@property (nonatomic) double rowHeight;

/// au市场深度数据处理
@property (nonatomic, copy) void(^auFoldAction)(NSInteger section, double price);

/**
 v4.9 cell背景动画
 */
- (void)cellUpdateDataAnimation:(BOOL)increase;
- (void)cellUpdateDataAnimation:(BOOL)increase oneBackcolor:(BOOL)oneBackcolor;

- (void)setLevelModel:(TBStockAskBidLevelItemModel *)levelModel isBuy:(BOOL)buy askLV1:(double)askLv1 bidLV1:(double)bidLv1;

// 更新UI样式(数字货币市场里会调整UI占比)
- (void)updateUILayout;

@end


@interface TBHKStockTenLevelTableViewCellItem : TBTableViewCellItem
@property (nonatomic, strong) TBHKStockTradeTickModel *tradeTickModel;

@end
