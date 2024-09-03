//
//  TBWatchListTableCellItem.h
//  Stock
//
//  Created by liwt on 14/12/30.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//


#import <TBUIKit/TBTableViewCell.h>
#import <TBBaseKit/JSONModel.h>
@class TBWatchListDisplayItem;
@class TBWatchListParamObject;
@class TBFuturesContractModel;
@class TBAHStockABriefItem;
#import <TBUIKit/TBTableViewCellItem.h>
#import <TBBaseKit/TBAppManager.h>

// WATCHLIST_CELL_HEIGHT 与 WATCH_LIST_COLLECTIONVIEW_BASE_ITEM_HEIGHT 有个计算，所以这里需要设置 5 的整数倍
#define WATCHLIST_CELL_HEIGHT (55)

@interface TBAHStockABriefItem : NSObject

@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *symbol;

@end

@interface TBWatchListTableCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL     isLandscapeMode; //是否横屏模式
@property (nonatomic, copy) NSArray<TBWatchListDisplayItem *> * displayItems;    //需要显示的选项内容
@property (nonatomic, assign) int portraitLastRow;
@property (nonatomic, strong) TBFuturesContractModel *contractModel;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *name;///< 组合期权使用
@property (nonatomic, copy) NSString *fullName; ///< 组合期权使用
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *underlyingSymbol;///< 组合期权对应的正股 标的
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *changeRate;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) NSNumber *timestamp;
@property (nonatomic, strong) NSNumber *halted;
@property (nonatomic, strong) NSNumber *auction;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *expiry;

@property (nonatomic, copy) NSDictionary *hourTrading;
@property (nonatomic, copy) NSDictionary *overnightTrading;
@property (nonatomic, assign) BOOL hideBottomLine;
@property (nonatomic, assign) NSUInteger delay;

@property (nonatomic, copy) NSDictionary *greyMarket;
@property (nonatomic, strong, readonly) NSNumber *realLatestPrice;

@property (nonatomic, strong) UIImage *logoImage;

//新增需要显示的字段
@property (nonatomic, strong) NSNumber * change;            //涨跌额
@property (nonatomic, strong) NSNumber * turnoverRate;      //换手率
@property (nonatomic, strong) NSNumber * peRate;            //市盈率
@property (nonatomic, strong) NSNumber * pbRate;            //市净率
@property (nonatomic, strong) NSNumber * amplitude;         //振幅
@property (nonatomic, strong) NSNumber * volume;            //成交量
@property (nonatomic, strong) NSNumber * cryptoVolume;      //DBS成交量
@property (nonatomic, strong) NSNumber * amount;            //成交额
//@property (nonatomic, strong) NSNumber * marketValue;       //流通市值
@property (nonatomic, strong) NSNumber * floatMarketValue;  //流通市值
@property (nonatomic, strong) NSNumber * marketValue;         //总市值
@property (nonatomic, strong) NSNumber * roa;               //roa
@property (nonatomic, strong) NSNumber * roe;               //roe
@property (nonatomic, strong) NSNumber * volumeRatio;       //量比
@property (nonatomic, strong) NSNumber * committee;         //委比
@property (nonatomic, strong) NSNumber * shares;            //总股本
@property (nonatomic, strong) NSNumber * floatShares;       //流通股本
@property (nonatomic, strong) NSNumber * eps;               //每股收益
@property (nonatomic, strong) NSNumber * ttmEps;            //港股美股收益
@property (nonatomic, strong) TBAHStockABriefItem * aStockBrief;//AH股中A股信息

@property (nonatomic, strong) NSNumber *lyrEps;                 //静态eps
@property (nonatomic, strong) NSNumber *dividePrice;            //股息
@property (nonatomic, strong) NSNumber *prevYearClose;          //上一年最后一个交易日收盘价
@property (nonatomic, strong) NSNumber *fiveDayClose;           //五日前收盘价
@property (nonatomic, strong) NSNumber *twentyDayClose;         //20日前收盘价

@property (nonatomic, strong) NSNumber *YTD;                //年初至今
@property (nonatomic, strong) NSNumber *dayChg_5;           //5日涨幅
@property (nonatomic, strong) NSNumber *dayChg_20;          //20日涨幅
@property (nonatomic, strong) NSNumber *dividendYieldRatio;//股息率

@property (nonatomic, strong) NSNumber *marketCap;
@property (nonatomic, strong) NSNumber *floatMarketCap;

@property (nonatomic, strong) NSNumber *impliedVolPercentile;
@property (nonatomic, strong) NSNumber *impliedVol;


//期货特殊情况，五个字段
@property (nonatomic, copy) NSString * displayLastestPrice;
@property (nonatomic, copy) NSString * displayChangeRate;
@property (nonatomic, copy) NSString * displayChangeAmount;  //期货涨跌额

@property (nonatomic, strong) NSNumber *sortPrice;

@property (assign, nonatomic) BOOL isMain;        // 是否是抽象的那个主连合约,这个字段的作用：如果yes，则不用判断是否过期
@property (assign, nonatomic) BOOL isContractMain;//yes要显示“主”图标
@property (nonatomic, copy) NSString *contractStateUnusual;//过期或下架

@property (nonatomic, assign) BOOL isSelected;

@property (nonatomic, strong) NSNumber *maxScale; //价格相关字段的数据精度
@property (nonatomic, copy) NSString *currency;

/// 长连接订阅symbol
@property (nonatomic, copy, readonly) NSString *subcribeSymbol;

- (TBWatchListTableCellItem *)applyTitle:(NSString *)nameCN symbol:(NSString *)symbol price:(NSNumber *)latestPrice changeRate:(NSNumber *)changeRate marketType:(NSString *)marketType;

+ (NSArray<TBWatchListParamObject *> *)covertToStockInfoModelArray:(NSArray<TBWatchListTableCellItem *> *)stocks;

/**
 公司行动列表
 */
@property (nonatomic, copy) NSArray *noticeList;
//初始化数据的字典
@property (nonatomic, copy) NSDictionary * srcDictionary;

@property (nonatomic, copy) void(^dismissBlock)(void);


////////////////////////////////////////////////////////////future相关contract
//@property (nonatomic, strong) TBFuturesContractModel *contractModel;

@property (nonatomic, strong) NSNumber *preSettlement;
@property (nonatomic, strong) NSNumber *priceOffset;

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////   辅助计算属性

@property (nonatomic, strong, readonly) NSNumber *quotesLastPrice;
@property (nonatomic, strong, readonly) NSNumber *quotesPreSettlement;
@property (nonatomic, strong, readonly) NSNumber *quotesPreClose;
@property (nonatomic, strong, readonly) NSNumber *quotesProfit;             // 盈亏
@property (nonatomic, strong, readonly) NSNumber *profitRatio;              // 盈亏比例

@end
 
