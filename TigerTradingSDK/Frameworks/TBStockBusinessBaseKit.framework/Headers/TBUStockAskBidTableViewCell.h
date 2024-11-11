//
//  TBUStockAskBidTableViewCell.h
//  Stock
//
//  Created by Pengfei_Luo on 2017/1/11.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@protocol TBUStockAskBidTableViewCell <NSObject>

- (double )cellBidPrice;
- (UIColor *)bidPriceColor;
- (double )bidCount;

- (double )cellAskPrice;
- (UIColor *)askPriceColor;
- (double )askCount;

@optional
@property (nonatomic, readonly) NSString *bidPriceString;
@property (nonatomic, readonly) NSString *askPriceString;
@property (nonatomic, readonly) NSString *stockMarket;
@property (nonatomic, readonly) NSString *stockSecType;

@property (nonatomic, readonly) NSString *stockAskTitle;
@property (nonatomic, readonly) NSString *stockBidTitle;
@property (nonatomic, readonly) BOOL showInfoIcon;

/// 优先判断 ask Bid 字段，如果非0，展示给用户。 否则判断high low 是否非0，若是则展示 bqt竞价区间。
@property (nonatomic, readonly) NSString *stockBqtPriceRange;

@end

@interface TBUStockAskBidTableViewCell : TBTableViewCell

@end

@interface TBUStockAskBidTableViewCellItem : TBTableViewCellItem

@property (nonatomic, weak) id<TBUStockAskBidTableViewCell > dataSource;

@end
