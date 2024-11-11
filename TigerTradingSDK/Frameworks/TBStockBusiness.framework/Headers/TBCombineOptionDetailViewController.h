//
//  TBCombineOptionDetailViewController.h
//  StockBusiness
//
//  Created by mashanli on 2023/6/15.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBStockBusinessBaseKit/TBStockDetailTradeManager.h>
#import <TBTradeBusinessBaseKit/TBStockOrderCheckDefines.h>

@class TBChartKLineView;
@class TBStockDetailOrderPositionHttpManager;
@class TBStockDetailMoreOrdersTableViewCellItem;
@class MZFormSheetPresentationViewController;
@class TBTradeAPIOrderItemModel;
@class TBTradeAPIPlaceOrderModel;
@class TBStockDetailActiveOrderTableViewCellItem;
@class TBPlaceOrderBuySellAmountPromptModel;
@class TBPlaceOrderCheckManager;
@class TBPlaceOrderMLegModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBCombineOptionDetailViewController : TBListTableViewController 

@property (nonatomic, copy) NSString *symbol;//对应的正股
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSArray *optionItems;//组合期权入参[Dictionary]格式

@property (nonatomic, weak) id<TBStockDetailInfoDataSource> secInfo;

@property (nonatomic, strong) TBPlaceOrderMLegModel *mlegModel;

@property (nonatomic, readonly) TBChartKLineView *klineChartView;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 持仓订单
@property (nonatomic, strong) NSMutableArray * _Nullable orderArray;
@property (nonatomic, strong) NSMutableArray * _Nullable todayCompleteOrderArray;
@property (nonatomic, strong) NSMutableArray * _Nullable positionArray;
@property (nonatomic, strong) NSMutableArray *positionOrderArray; //持仓订单
@property (nonatomic, strong) NSMutableArray *tempPositionOrderArray; /// 临时存放新订单持仓
@property (nonatomic, strong) TBStockDetailOrderPositionHttpManager *positionOrderManager;

/// 是否展开，default NO，
@property (nonatomic, assign) BOOL ordersUnfold;
@property (nonatomic, assign) BOOL positionOrdersUnfold;
@property (nonatomic, assign) BOOL scrollToPositionOrderModule;

/// 查看更多订单cellItem
@property (nonatomic, strong) TBStockDetailMoreOrdersTableViewCellItem *moreOrdersCellItem;
@property (nonatomic, strong) TBTradeAPIOrderItemModel *currentItem;
/// 改单临时对象
@property (nonatomic, strong) TBTradeAPIPlaceOrderModel *placeOrderModel;
@property (nonatomic, strong) TBStockDetailActiveOrderTableViewCellItem  * _Nullable tempOrderCellItem;
/// 综合账户存在 预估数量
@property (nonatomic, strong) TBPlaceOrderBuySellAmountPromptModel *estimateAmountModel;
@property (nonatomic, strong) id<TBPlaceOrderContactInfoDataSource> _Nullable contractInfo;

@property (nonatomic, strong) TBPlaceOrderCheckManager *placeOrderCheckManager;

@property (nonatomic, strong) NSNumber *limitPrice;
@property (nonatomic, assign) TBTradeType tradeType;
@property (nonatomic,assign) BOOL needRefreshAuth;
@property (nonatomic, strong) TBStockDetailTradeManager *tradeManager;

@property (nonatomic, readonly) UIViewController *modifyVC;
@property (nonatomic, weak) MZFormSheetPresentationViewController *modifyPresentVC;

@property (nonatomic, readonly) UIViewController *speedModeViewController;
@property (nonatomic, weak)  MZFormSheetPresentationViewController *speedOrderPresentVC;

@end

NS_ASSUME_NONNULL_END
