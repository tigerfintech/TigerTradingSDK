//
//  TBMarketConditionsViewController.h
//  Stock
//
//  Created by 王灵博 on 2020/9/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBMarketConditionsBaseViewController.h"
#import <TBStockBusiness/TBMarketConditionsBaseViewController.h>
#import <TBStockBusiness/TBMarketSectorCell.h>

@class TBMarketConditionsModel;
@class TBStockNewCalendarCellItem;
@class TBMarketSectorCellItem;
@class TBRSPListModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketConditionsViewController : TBMarketConditionsBaseViewController<TBMarketSectorCellItemDelegate>
@property (nonatomic, strong) TBMarketConditionsModel *conditionsModel;
///打新日历
@property (nonatomic, strong) NSMutableArray *calendarMarray;
@property (nonatomic, strong) TBStockNewCalendarCellItem *calendarItem;
///

///今日异动
@property (nonatomic, strong) NSMutableArray *changeMarray;
///
///热门行业、热力图
@property (nonatomic, strong) NSMutableArray *industryMArray;
@property (nonatomic, strong) NSMutableArray *conceptsMArray;
@property (nonatomic, assign) NSInteger boardSelectedIndex;

///
///其它榜单
@property (nonatomic, assign) NSInteger otherSelectedIndex;
///
///
/// ETF榜单
@property (nonatomic, assign) NSInteger etfSelectedIndex;

///期权榜单
@property (nonatomic, assign) NSInteger optionSelectedIndex;

///定投榜单
@property (nonatomic, copy) NSString *selectedAutoInvestLableId;

@property (nonatomic, assign) NSInteger currentIndex;

///今日股市
@property (nonatomic, assign) BOOL  todayIsFolded;//是否折叠
@property (nonatomic, strong) TBMarketSectorCellItem *todayStockItem;

@property (nonatomic, strong) TBMarketSectorCellItem *indicesSectorItem;

/// 指数数组
@property (nonatomic, strong) NSMutableArray *indiceSectorCellItems;

/// 股票定投榜单
@property (nonatomic, strong) NSMutableArray *autoInvestCellItems;

@property (nonatomic, strong) TBRSPListModel *autoInvestRankModel;

@property (nonatomic, strong) NSMutableDictionary *indicesNameDict;

@property (nonatomic, strong) NSMutableDictionary *packageIDParams;

@property (nonatomic, strong) NSMutableDictionary *autoInvestParams;

@property (nonatomic, assign) BOOL isSecondaryPage; //是否是二级页

- (void)didFetchMarketData;

@end

NS_ASSUME_NONNULL_END
