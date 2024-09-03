//
//  TBStockDetailPriceTableViewCell.h
//  Stock
//
//  Created by luopengfei on 2018/4/13.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//
@class TBStockInfoDetailItemModel;

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockKit/TBStock.h>
#import "TBStockDetailPromptItemView.h"

UIKIT_EXTERN NSString *const TBUKStockCurrencyPromptString;
FOUNDATION_EXPORT CGFloat const TBStockDetailPriceCellHeightPro;

@protocol TBStockDetailPriceTableViewCell <NSObject>

@property (nonatomic, readonly) NSString *cellDisplayLatestPrice;
@property (nonatomic, readonly) NSString *cellDisplayChange;

@property (nonatomic, readonly) UIColor *animationColor;
@property (nonatomic, readonly) NSNumber *cellStockLatestPrice;
@property (nonatomic, readonly) NSNumber *cellStockChange;
@property (nonatomic, readonly) NSNumber *cellStockChangePercent;

- (BOOL) isShowShortAble;
@optional
- (BOOL) canbeTradeInIB;
- (BOOL) astockCanbeSellInIB;

@property (nonatomic, readonly) NSString *displayCurrency;

- (TBStockQuotePromptType )stockSplitOrJoinType;

@end


@interface TBStockDetailPriceTableViewCell : TBTableViewCell

@property (nonatomic, strong) UILabel *priceLabel;
@property (nonatomic, strong) UIView *iconView;

- (void)updateQuoteIcon:(NSArray *)array permissions:(NSArray *)permissions;
- (void)setupLiteViews;

@end

@interface TBStockDetailPriceTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *exchangeCode;

@property (nonatomic, assign) BOOL tradeable;
@property (nonatomic, assign) BOOL shortAble;
@property (nonatomic, assign) BOOL unopenable;

@property (nonatomic, assign) BOOL showStockFee; // 展示保证金、做空利率信息信息

@property (nonatomic, strong) id<TBStockDetailPriceTableViewCell> dataSource;
@property (nonatomic, strong) TBStockInfoDetailItemModel *itemModel;

@property (nonatomic, assign) BOOL isNeedResetRightView;//reset盘前盘后夜盘按钮
@property (nonatomic, assign) BOOL supportFractionalShare; // 是否支持碎股
@property (nonatomic, assign) BOOL canContraTrading; // contra的icon标志
@property (nonatomic, assign) BOOL canUsOvernightTrading; //夜盘的标志
@property (nonatomic, assign) BOOL isPIOnly; // 是否仅支持PI用户

@end
