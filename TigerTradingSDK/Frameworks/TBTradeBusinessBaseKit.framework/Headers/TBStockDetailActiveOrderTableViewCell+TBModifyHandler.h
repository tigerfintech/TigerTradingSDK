//
//  TBStockDetailActiveOrderTableViewCell+TBModifyHandler.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/17.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBStockDetailActiveOrderTableViewCell.h"
@class TBTradeAPIOrderItemModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailActiveOrderTableViewCell (TBModifyHandler)

- (NSNumberFormatter *)priceFormatter:(TBTradeAPIOrderItemModel *)orderModel;

- (double)minTick:(double)price;

- (double)minTick:(double)price isLeft:(BOOL)isLeft;

/// 根据最小变动精度矫正后的价格
/// @param price
- (double)minTickPrice:(double)price;
@end

NS_ASSUME_NONNULL_END
