//
//  TBOptionInfoDetailItem.h
//  Stock
//
//  Created by liwt on 9/14/15.
//  Copyright (c) 2015 com.tigerbrokers. All rights reserved.
//

#import "TBStockDetailTradeDetailTableViewCell.h"
#import "TBOptionItem.h"
#import <TBBaseKit/JSONModel.h>
#import <TBStockBusinessBaseKit/TBStockDetailCorporationModel.h>


/// 包一层处理属性与返回值不一致的问题。
@interface TBOptionDividendItemModel : TBStockDetailDividendModel
@end

@protocol TBOptionInfoDetailItem <NSObject>
@end
@interface TBOptionInfoDetailItem : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, assign) BOOL stockHaveVol;//是否能计算波动率
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right; // 大写
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *optionName;
@property (nonatomic, copy) NSString *underlyingSymbol;


@property (atomic, copy) NSString *marketStatus;

@property (nonatomic, strong) NSNumber *bidPrice;
@property (nonatomic, strong) NSNumber *bidSize;

@property (nonatomic, strong) NSNumber *askPrice;
@property (nonatomic, strong) NSNumber *askSize;

@property (nonatomic, strong) NSNumber *volume;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *open;
@property (nonatomic, strong) NSNumber *high;
@property (nonatomic, strong) NSNumber *low;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *openInt; //未平仓数
@property (nonatomic, strong) NSNumber *equalUnderlying; //正股单位倍数
@property (nonatomic, strong) NSNumber *netOpenInt; //净未平仓数
@property (nonatomic, strong, readonly) NSNumber *dividendYieldRatio;//股息率


@property (nonatomic, strong) NSNumber *change;

@property (nonatomic, copy) NSString *latestTime;
@property (nonatomic, strong) NSNumber *latestTimestamp;//市场最近交易时间，计算波动率使用
@property (nonatomic, strong) NSNumber *quoteTimestamp;

@property (nonatomic, strong) NSNumber *multiplier;

@property (nonatomic, copy) NSString *volatility;
@property (nonatomic, assign) double doubleVolatility;
@property (nonatomic, strong) NSNumber *ratesBonds;
@property (atomic, copy) NSString *stockExchange;

@property (nonatomic, strong) NSNumber *daysToExpiry;//距离到期天数
@property (nonatomic, strong) NSNumber *amount;//成交额
@property (nonatomic, strong) NSNumber *sellingReturn;//卖出年化收益
@property (nonatomic, strong) NSNumber *sellMargin;//卖出保证金（非server返回）

- (void)updateByOtherItem:(TBOptionInfoDetailItem *)other;

@property (nonatomic, copy) NSArray <NSArray <NSNumber *> *> *openAndCloseTimeList; // 交易时间区间
@property (nonatomic, copy) NSArray<TBOptionIndiceQuoteModel> *stockQuotes;
@property (nonatomic, copy) NSString *notice;
@property (nonatomic, assign) BOOL isIndexOption;

@property (nonatomic, strong) TBOptionDividendItemModel *dividend;


@property (nonatomic, copy, readonly) NSString *optionCombineSymbol;

@property (nonatomic, strong) NSNumber *stockPrice;///<  期权对应正股的价格

@property (nonatomic, strong) NSNumber *dividePrice;

@property (nonatomic, assign) BOOL stockIsInTradingTime;

@property (nonatomic, strong) NSNumber *deliverableShares;

@property (nonatomic, assign) BOOL isOld;

@end

@protocol TBOptionDepthAskBidItemModel <NSObject>
@end
@interface TBOptionDepthAskBidItemModel : JSONModel <TBStockDetailTradeDetailTableViewCell>


@property (nonatomic, copy) NSString *code;
@property (nonatomic, strong) NSNumber *size;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSNumber *timestamp;


@end

@interface TBOptionDepthModel : JSONModel
@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;

//@property (nonatomic, strong) TBOptionInfoDetailItem *data;

@property (nonatomic, copy) NSArray<TBOptionDepthAskBidItemModel> *ask;
@property (nonatomic, copy) NSArray<TBOptionDepthAskBidItemModel> *bid;//是否为旧期权
@end


/// 批量期权详情
@interface TBOptionDetailsModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy) NSString *h;
@property (nonatomic, copy) NSArray<TBOptionInfoDetailItem> *items;

@end
