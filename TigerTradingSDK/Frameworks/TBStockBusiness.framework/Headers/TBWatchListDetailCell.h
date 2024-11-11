//
//  TBWatchListDetailCell.h
//  Stock
//
//  Created by yangfan on 2019/6/20.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBWatchListDisplayItem;
@class TBWatchListTableCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchListDetailColorObject : NSObject

@property (nonatomic, strong) UIColor *normalTextColor;
@property (nonatomic, strong) UIColor *bgViewTextColor;
@property (nonatomic, strong) UIColor *bgViewColor;

@end

@interface TBWatchListChangeAmountResult : NSObject

@property (nonatomic, copy) NSString *amountString;
@property (nonatomic, strong) TBWatchListDetailColorObject *detailColor;

@end

@interface TBWatchListDetailCell : UICollectionViewCell

@property (nonatomic, weak) TBWatchListTableCellItem * watchlistItem;

- (void)reloadCell;
@property (nonatomic, assign)BOOL isLandScapeMode;
//外部需要使用到以下接口，现做开放处理。

//标准化价格字符串输出
+ (NSString *)getPriceString:(TBWatchListTableCellItem *)tableViewCellItem;
//标准化涨跌幅字符串输出
+ (NSString *)getChangeRateString:(TBWatchListTableCellItem *)tableViewCellItem;
//是否是退市
+ (BOOL)isHalted:(TBWatchListTableCellItem *)tableViewCellItem;
//是否停牌
+ (BOOL)isStopped:(TBWatchListTableCellItem *)tableViewCellItem;
+ (BOOL)isNeedCenter:(TBWatchListTableCellItem *)tableViewCellItem displayItem:(TBWatchListDisplayItem *)item;
//标准化涨跌幅颜色输出
+ (UIColor *)getChangeRateStringColor:(TBWatchListTableCellItem *)tableViewCellItem;
+ (TBWatchListDetailColorObject *)getMultipleChangeRateStringColor:(TBWatchListTableCellItem *)tableViewCellItem;
+ (UIColor *)bgViewColorFromSettings:(BOOL)isIncrease;

@end

NS_ASSUME_NONNULL_END
