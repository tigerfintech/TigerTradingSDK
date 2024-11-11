//
//  TBOptionStrategyAnalysisDataManager.h
//  AFNetworking
//
//  Created by zlc on 2023/6/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionInfoDetailItem, TBStockInfoDetailItemModel, TBPlaceOrderMLegModel;
@class TBTableViewCellItem;
@class TBOptionStrategyBuilderStrategyCellItem;
@class TBOptionStrategyBuilderChartCellItem;
@class TBOptionStrategyBuilderPNLDetailsCellItem;
@class TBOptionStrategyBuilderStrategyModel;
@class TBOptionStrategyBuilderChartCell;
@class TBTableViewCell;
@class TBOptionStrategyBuilderCombinedInfoCellItem;
@class TBOptionStrategyBuilderStrategyOptionModel;

typedef NSString *TBOptionStrategyAnalysisFromType NS_STRING_ENUM;
FOUNDATION_EXTERN TBOptionStrategyAnalysisFromType const kTBOptionStrategyAnalysisFromTypeOptionDetail;//期权详情页
FOUNDATION_EXTERN TBOptionStrategyAnalysisFromType const kTBOptionStrategyAnalysisFromTypeCombineOption;//组合期权详情页
FOUNDATION_EXTERN TBOptionStrategyAnalysisFromType const kTBOptionStrategyAnalysisFromTypeTrade;//下单页
FOUNDATION_EXTERN TBOptionStrategyAnalysisFromType const kTBOptionStrategyAnalysisFromTypeOptionChain;//期权链

@protocol TBOptionStrategyAnalysisDataManagerDataSourceProtocol <NSObject>
// 容器VC
@property (nonatomic, weak, readonly) UIViewController *optionStrategyViewController;
// 期权四要素
@property (nonatomic, copy, readonly)   NSString *optionStrategySymbol;
@property (nonatomic, copy, readonly)   NSString *optionStrategyRight;
@property (nonatomic, strong, readonly) NSNumber *optionStrategyExpiry;
@property (nonatomic, copy, readonly)   NSString *optionStrategyStrike;
// 市场
@property (nonatomic, copy, readonly) NSString *optionStrategyMarket;
// secType
@property (nonatomic, copy, readonly) NSString *optionStrategySecType;
// 预估保证金（下单页传入）
@property (nonatomic, strong, readonly, nullable) NSNumber *optionStrategyNetEstetmatedValue;
/// 下单页带入 netValue - midPrice 的结果
@property (nonatomic, strong, readonly, nullable) NSNumber *optionStrategyNetSpread;
/// 下单页带入 quantity
@property (nonatomic, strong, readonly, nullable) NSNumber *optionStrategyNetQuantity;
/// mlegModel
@property (nonatomic, strong, readonly) TBPlaceOrderMLegModel *optionStrategyMLegModel;
/// 首个期权详情信息
@property (nonatomic, strong, readonly) TBOptionInfoDetailItem     *optionStrategyOptionItem;
/// 股票详情信息
@property (nonatomic, strong, readonly) TBStockInfoDetailItemModel *optionStrategyStockModel;

// tableView reloadData
- (void)optionStrategyReloadData;

/// 刷新bottomView状态（是否在自选中）
- (void)optionStrategyRefreshBottomActionViews;

- (void)setOptionStrategyOptionItem:(TBOptionInfoDetailItem *)optionItem;
- (void)setOptionStrategyStockModel:(TBStockInfoDetailItemModel *)stockModel;

// 初始化配置items
- (void)optionStrategyConfigDisplayItems:(nullable NSArray<TBOptionStrategyBuilderStrategyModel *> *)strategies;

@end

@interface TBOptionStrategyAnalysisDataManager : NSObject

/// 来源
@property (nonatomic, copy) TBOptionStrategyAnalysisFromType fromType;

/// 数据源
@property (nonatomic, weak) id<TBOptionStrategyAnalysisDataManagerDataSourceProtocol> dataSource;

/// 添加到自选成功回掉
@property (nonatomic, copy) void(^addCurrentSymbolsToWatchListBlock)(void);

/// fetch时loading是否禁用，默认为NO
@property (nonatomic, assign) BOOL fetchDataLoadingDisable;

/// 各个cellItem
- (TBOptionStrategyBuilderCombinedInfoCellItem *)strategyCombinedCellItem;
- (TBOptionStrategyBuilderStrategyCellItem *)strategyCellItem;
- (TBOptionStrategyBuilderPNLDetailsCellItem *)strategyPnlDetailCellItem;
- (TBOptionStrategyBuilderChartCellItem *)strategyChartCellItem;
- (TBOptionStrategyBuilderChartCell *)strategyChartCell;

/// 生成cellItems
- (NSArray <TBTableViewCellItem *> *)generateCellItems;

- (BOOL)checkIsFromPlaceOrder;

// fetch data
- (void)fetchData;

/// 去下单页
- (void)multiOptionTradeIfNeed;

/// cell action handler
- (void)strategyBuilderHandleActionForCell:(TBTableViewCell *)cell object:(TBTableViewCellItem *)item info:(id)info;

/// 是否期权组合在自选中
- (BOOL)isTwoLegOptionInWatchList;

/// 添加期权组合到自选中
- (void)addOrDeleteCurrentSymbolsToWatchList;

/// 是否有组合期权能力
- (BOOL)hasOptionMultiLegsAbility;

/// 原地刷新（只请求已有子期权详情，重新计算指标信息）
- (void)pullRefreshData;
- (void)pullRefreshDataWithBlock:(nullable dispatch_block_t)block;

/// 重置chart的onePageCount(vertical 30,其他300)，只更新一次
- (void)updateChartViewPageCountOnce;

@end

NS_ASSUME_NONNULL_END
