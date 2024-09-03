//
//  NSArray+TBAdditions.h
//  Stock
//
//  Created by donggongfu on 17/2/28.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBTradeBusinessBaseKit/NSArray+TBAdditions.h>

@class TBTradeAPIOrderItemModel;

@interface NSArray (TBAdditions)

- (NSArray<TBTradeAPIOrderItemModel *> *)tb_nameOrders;
- (NSArray<TBTradeAPIOrderItemModel *> *)tb_sortOrders;

@end
