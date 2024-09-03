//
//  TBWatchListCell.h
//  Stock
//
//  Created by yangfan on 2018/9/3.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@class TBWatchListTableCellItem;

NS_ASSUME_NONNULL_BEGIN

typedef void(^WatchlistEditBlock)(NSDictionary *obj);

@interface TBWatchListCell : TBTableViewCell

@property (nonatomic, assign) BOOL           flowWarning;//决定是否使用股价变化动效。设置为YES则支持有动效，
@property (nonatomic, assign) BOOL           isMainContract;//是否是主连合约
@property (nonatomic, assign) NSInteger      thumbnailState; //分时图状态 1 显示；0 隐藏
@property (nonatomic, strong) UIImage *logoImage; //logo
@property (nonatomic, assign) BOOL      enableLogo; //允许logo

- (void)watchlistEdit:(WatchlistEditBlock)thisBlock;

//播放价格变动的动画
- (void)playAnimation;

/// 设置缩略图
/// @param priceList 如果为nil，说明没有缩略图；否则展示缩略图
/// @param lineValue 虚线值
/// @param total 全部点值
/// @param color 颜色
- (void)setThumbnailPriceList:(nullable NSArray <NSNumber *> *)priceList withLimitLineValue: (NSNumber *)lineValue withTotal: (NSInteger)total withColor: (UIColor *)color ;

@end

NS_ASSUME_NONNULL_END
