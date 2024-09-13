//
//  TBNewOptionDetailViewController.h
//  Stock
//
//  Created by 骆朋飞 on 2017/8/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBTradeBusinessBaseKit/TBPlaceOrderContactInfoDataSource.h>
#import <TBStockBusinessBaseKit/TBStockDetailTradeManager.h>
#import <TBUIKit/TBRefreshView.h>
#import <TBStockBusinessBaseKit/TBOptionStrategyBuilderChartCell.h>

@class TBOptionInfoDetailItem;
@class TBTradeAPIOrderItemModel;
@class TBStockDetailBottomTabBar;
@class TBStockDetailTitleView;
@class TBStockPrompView;
@class TBStockDetailRefreshHeaderView;
@class MZFormSheetPresentationViewController;
@class TBStockDetailMoreOrdersTableViewCellItem;
@class TBTradeAPIPlaceOrderModel;
@class TBStockDetailActiveOrderTableViewCellItem;
@class TBStockInfoDetailItemModel;
@class TBPlaceOrderBuySellAmountPromptModel;
@class TBStockDetailActiveOrderTableViewCellItem;
@class TBStockDetailHttpRequstManager;

NS_ASSUME_NONNULL_BEGIN
@interface TBNewOptionDetailViewController : TBListTableViewController

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *optionSymbol;

@property (nonatomic, copy) NSString *symbolCN;
@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *right;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, strong) TBOptionInfoDetailItem *optionItem;
@property (nonatomic, strong) TBTradeAPIOrderItemModel *currentItem;

@property (nonatomic, strong) TBStockDetailTradeManager *tradeManager;
@property (nonatomic, strong) TBStockDetailHttpRequstManager *detailManager;

@property (nonatomic, strong) TBStockDetailBottomTabBar *bottomBar;

//@property (nonatomic, strong) TBAStockBarView *titleView;
@property (nonatomic, strong) TBStockDetailTitleView *detailTitleView;

@property (nonatomic, strong) TBStockDetailRefreshHeaderView *refreshHeaderView;

@property (nonatomic, readonly) NSString *combinedOptionSymbol;

@property (nonatomic, strong) NSTimer *refreshTimer;

@property (nonatomic, readonly) UIViewController *speedModeViewController;

@property (nonatomic, weak)  MZFormSheetPresentationViewController *speedOrderPresentVC;
@property (nonatomic, strong) NSNumber *limitPrice;


@property (nonatomic, weak) MZFormSheetPresentationViewController *modifyPresentVC;

@property (nonatomic, readonly) UIViewController *modifyVC;

/// 临时存放新订单持仓
@property (nonatomic, strong) NSMutableArray *tempPositionOrderMArray;
/// 是否展开，default NO，
@property (nonatomic, assign) BOOL ordersUnfold;
@property (nonatomic, assign) BOOL positionOrdersUnfold;
@property (nonatomic, assign) BOOL scrollToPositionOrderModule;
@property (nonatomic, assign) BOOL showIndexOptionInfo;
@property (nonatomic, assign) BOOL tradeUPOptionLevelDidChecked;

/// 查看更多订单cellItem
@property (nonatomic, strong) TBStockDetailMoreOrdersTableViewCellItem *moreOrdersCellItem;

/// 改单临时对象
@property (nonatomic, strong) TBTradeAPIPlaceOrderModel *placeOrderModel;
/// 综合账户存在 预估数量
@property (nonatomic, strong) TBPlaceOrderBuySellAmountPromptModel *estimateAmountModel;
@property (nonatomic, strong) id<TBPlaceOrderContactInfoDataSource> _Nullable contractInfo;
/// 改单临时对象
@property (nonatomic, strong) TBStockDetailActiveOrderTableViewCellItem  * _Nullable tempOrderCellItem;
@property (nonatomic, assign) TBTradeType tradeType;
@property (nonatomic, strong) NSMutableArray * _Nullable orderAMarray;
@property (nonatomic, strong) NSMutableArray * _Nullable todayCompleteOrderArray;
@property (nonatomic, strong) NSMutableArray * _Nullable positionMArray;
@property (nonatomic, strong) NSMutableArray *orderPositionTabArray;

@property (nonatomic, strong) TBStockInfoDetailItemModel *stockModel;

@property (nonatomic, copy) NSString *omniUnTradeAbleMessage;

@property (nonatomic, strong) id placeOrderCheckManager;

/// 开通期权权限弹框
- (void)showOptionPermissionAlert;

/// TBAU && HK期权提示
- (void)showTBAUHKOptionBox;

/// tableView reloadData 不触发隐藏键盘
- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
