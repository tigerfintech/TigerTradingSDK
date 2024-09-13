//
//  TBCombineOptionDetailViewController+TBTrade.h
//  TBStockBusiness
//
//  Created by wind on 2023/6/29.
//

#import "TBCombineOptionDetailViewController.h"
@class TBStockDetailBaseTradeTableViewCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBCombineOptionDetailViewController (TBTrade)<TBStockOrderDataSource, TBPlaceOrderCheckerViewControllerCallback>

- (void)initTrade;

- (void)addTradeObserver;

- (void)loadRemotePositionOrderData;

- (void)handleMoreOrdersAction;
- (void)handlePositionOrdersFoldAction;

- (void)selectedCellWithItem:(TBStockDetailBaseTradeTableViewCellItem *)validItem;
- (void)tradeActionForCell:(TBTableViewCell *)cell object:(TBTableViewCellItem *)item info:(id)info;

- (void)dissmissSpeedVCCompletion:(void (^ __nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
