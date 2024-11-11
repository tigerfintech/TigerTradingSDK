//
//  TBNewOptionDetailViewController+TBOptionAction.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/30.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBNewOptionDetailViewController.h"
#import <TBTradeBusinessBaseKit/TBStockOrderCheckDefines.h>
@class TBTableViewCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBNewOptionDetailViewController (TBOptionAction) <TBStockOrderDataSource, TBPlaceOrderCheckerViewControllerCallback>

- (void)handleOrderCellAction:(id)info cellItem:(TBTableViewCellItem *)item;

- (void)fetchTradeToken;

// 弹出快捷下单
- (void)showSpeedModeWithLimitPrice:(NSNumber *)limitPrice;

- (void)makeSpeedOrderAction;

- (NSString *)secTypeString;

- (void)handlePositionOrdersFoldAction;
- (void)handleMoreOrdersAction;

- (void)reloadTableViewIfNeeded;

/// 获取TradingStatus
- (NSNumber *)fetchTradingStatus;

@end

NS_ASSUME_NONNULL_END
