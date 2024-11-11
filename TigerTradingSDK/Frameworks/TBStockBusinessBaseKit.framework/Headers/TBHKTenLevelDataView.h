//
//  TBHKTenLevelDataView.h
//  Stock
//
//  Created by Pengfei_Luo on 16/3/23.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBThirdParty/HMSegmentedControl.h>
@class TBStockDetailBorderSegmentControl;
@class TBStockAskBidLevelModel;

typedef NS_ENUM(NSUInteger, TBHKStockSelectedIndex) {
    TBHKStockSelectedTenLevelIndex = 0, // 买卖十档
    TBHKStockSelectedDetailTicks,       // 明细
    TBHKStockSelectedIndexPriceList,    // 分价图
    TBHKStockSelectedDealIndex          // 成交（同花顺有此项，未来产品可能也会设计此项，预留）
};

typedef NS_ENUM(NSUInteger, TBStockLevelType) {
    TBStockLevelTypeInStockDetail, // 个股详情页，显示十档 or 五档 & 明细切换tab
    TBStockLevelTypeInAStockTrade  // A股交易页面，不显示切换tab
};


/// MARK- 刷新type类型
typedef NS_ENUM(NSUInteger, TBHKStockDataRefreshType) {
     /// MARK- 刷新数据
    TBHKStockDataRefreshNormal,
     /// MARK- 加载最新数据
    TBHKStockDataRefreshLoadMoreType,
    /// MARK- 加载之前数据
    TBHKStockDataRefreshLoadBeforeType
};


typedef void(^actionLoadData)(TBHKStockDataRefreshType refrshType);

typedef void(^tenLevelSegementClicked)(NSInteger index);

@interface TBHKTenLevelDataView : UIView

@property (nonatomic, strong) UITableView *tableView;


/**
 该UIView所处VC：stockDetail or AStockMakeOrder
 */
@property (nonatomic, assign) TBStockLevelType levelType;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *exchangeCode;

@property (nonatomic, copy) NSString *LV2QuoteType;

@property (nonatomic, assign) double askLV1;
@property (nonatomic, assign) double bidLV1;

@property (nonatomic, assign) BOOL isOption;
@property (nonatomic, assign) BOOL isOTCMarket;

/// 是否处于港股处于暗盘
@property (nonatomic, assign) BOOL isHKGreyMarketStep;

@property (nonatomic, strong) TBStockDetailBorderSegmentControl *segementControl;
@property (nonatomic, assign) TBHKStockSelectedIndex selectedIndex;

@property (nonatomic, copy) NSArray *tradeDetailArray;
@property (nonatomic, copy) NSArray *priceListArray;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong, readonly) NSMutableArray *dataSourceArray;

@property (nonatomic, copy) actionLoadData loadDataBlock;

@property (nonatomic, copy) void(^lv2SourceChangeAction)(UIView *view);

@property (nonatomic, assign) TBHKStockDataRefreshType currentRefreshType;

@property (nonatomic, copy) void (^stockTradeSelected)(NSDictionary *selectedDictionary);

@property (nonatomic, copy) void (^stockTradeSelectedIndex)(TBHKStockSelectedIndex selectedType);
@property (nonatomic, copy) void (^pullRefreshAction)(void);
@property (nonatomic, assign) BOOL hiddenTickTip;//明细查看更多

@property (nonatomic, assign) CGFloat preClose;
@property (nonatomic, assign) CGFloat realPreClose;
- (void)clearData;

/**
 买卖五档、十档、美股LV240g档更新数据

 @param data 档位数据
 @param bidLV1 美股买盘LV1
 @param askLV1 美股卖盘LV1
 */
- (void)updateData:(NSDictionary *)data bidLV1:(double)bidLV1 askLV1:(double)askLV1;
- (void)updateLevelModel:(TBStockAskBidLevelModel *)model bidLV1:(double)bidLV1 askLV1:(double)askLV1;

- (void)tenLevelSegementClicked:(tenLevelSegementClicked)tenLevelSegement;


/// MARK- STOP REFRESHING
- (void)endRefreshing;

/**
 reload data
 */
- (void)tableViewReloadData;


/**
 期权深度数据异常下，隐藏segment
 */
- (void)hiddenSegment:(BOOL)hidden;

- (void)updateSegmentTitlesAndFrame;

@end
