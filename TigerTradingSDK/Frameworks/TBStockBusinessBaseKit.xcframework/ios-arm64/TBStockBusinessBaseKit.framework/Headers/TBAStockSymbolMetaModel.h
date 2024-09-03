//
//  TBAStockSymbolMetaModel.h
//  Stock
//
//  Created by donggongfu on 16/7/30.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBusinessSupportKit/TBStockDetailBaseModel.h>
#import "TBStockLandScapeStockInfoDetailView.h"
#import "TBStockDetailPriceTableViewCell.h"
#import "TBStockDetailViewControllerDelegate.h"
#import "TBStockFundamentalCell.h"
#import "TBAHAndHourStockCell.h"

@class TBAStockAfterMarketModel;
@class TBStockDetailNextMarketStatusModel;
@class TBStockDetailBriefModel;

/**
 个股详情页A股model
 */
@protocol TBAStockSymbolMetaItemModel
@end

@protocol TBAStockSymbolNoticeModel
@end

@protocol TBAStockNoticeContentModel
@end

@protocol TBAStockSymbolNoticeDetailModel
@end

@protocol TBAStockSymbolBonusConversedModel
@end

@protocol TBAStockSymbolDividendModel
@end

@class TBAStockNoticeContentModel;
@class TBAStockSymbolBonusConversedModel;//派股比例&&转增股比例
@class TBAStockSymbolDividendModel;//派分红

@interface TBAStockSymbolBonusConversedModel : JSONModel

@property (nonatomic, strong) NSNumber<Optional> *forFactor;
@property (nonatomic, copy) NSString<Optional> *symbol;
@property (nonatomic, strong) NSNumber<Optional> *toFactor;
@property (nonatomic, copy) NSString<Optional> *market;

@property (nonatomic, copy) NSString<Optional> *payableDate;
@property (nonatomic, copy) NSString<Optional> *exDate;


@property (nonatomic, readonly) NSString<Optional> *showDate;
@property (nonatomic, readonly) NSString<Optional> *showTitle;

@end

@interface TBAStockSymbolDividendModel : JSONModel

@property (nonatomic, copy) NSString<Optional> *payableDate;
@property (nonatomic, copy) NSString<Optional> *exDate;
@property (nonatomic, copy) NSString<Optional> *symbol;
@property (nonatomic, strong) NSNumber<Optional> *amount;
@property (nonatomic, copy) NSString<Optional> *market;
@property (nonatomic, copy) NSString<Optional> *currency;

@property (nonatomic, readonly) NSString<Optional> *showDate;
@property (nonatomic, readonly) NSString<Optional> *showTitle;

@end

@interface TBAStockSymbolNoticeModel : JSONModel

//公告
@property (nonatomic, copy) NSArray<TBAStockSymbolNoticeDetailModel> *items;

@end

@interface TBAStockSymbolNoticeDetailModel : JSONModel

@property (nonatomic, copy) NSString<Optional> *redirect;
@property (nonatomic, strong) TBAStockNoticeContentModel<Optional> *data;
@property (nonatomic, copy) NSString<Optional> *symbol;
@property (nonatomic, copy) NSString<Optional> *name;
@property (nonatomic, copy) NSString<Optional> *type;
@property (nonatomic, copy) NSString<Optional> *market;
@property (nonatomic, strong) NSNumber<Optional> *eventTimestamp;

@property (nonatomic, readonly) NSString<Optional> *date;

- (NSString *)aStockSplitKey;
- (NSString *)aStockSplitStr;


@end

@interface TBAStockNoticeContentModel : JSONModel

@property (nonatomic, copy) NSString<Optional> *detail;
@property (nonatomic, strong) TBAStockSymbolDividendModel<Optional> *dividend;
@property (nonatomic, strong) TBAStockSymbolBonusConversedModel<Optional> *bonus;
@property (nonatomic, strong) TBAStockSymbolBonusConversedModel<Optional> *conversed;

@end

/**
 *  A股行情详情的 jsonmodel. 接口 /astock/symbol/meta/{symbol:.+}
 */
@interface TBAStockSymbolMetaModel : JSONModel

@property (nonatomic, assign) long ret;
@property (nonatomic, assign) long long serverTime;
@property (nonatomic, copy) NSArray<TBAStockSymbolMetaItemModel> *items;

@end

@interface TBAStockSymbolMetaItemModel : TBStockDetailBaseModel <TBStockLandScapeStockInfoDetailViewDelegate, TBStockDetailPriceTableViewCell,
    TBStockFundamentalCellDelegate,TBAHAndHourStockCellDelegate, TBStockDetailViewControllerDelegate>
@property (nonatomic, copy) NSString *todayOpen;
@property (nonatomic, copy) NSString *turnoverShare;
@property (nonatomic, copy) NSString *turnoverAmount;
@property (nonatomic, copy) NSString *turnoverRate;
@property (nonatomic, copy) NSString *dayHigh;
@property (nonatomic, copy) NSString *dayLow;
@property (nonatomic, copy) NSString *peRate; // 市盈率
@property (nonatomic, copy) NSString *changeValue;
@property (nonatomic, copy) NSString *marketValue;
@property (nonatomic, copy) NSString *circulatedValue;
@property (nonatomic, strong) NSNumber *serverTime; // long
@property (nonatomic, strong) NSNumber *status; // long
@property (nonatomic, copy) NSString *amplitude;
@property (nonatomic, copy) NSString *indexStatus;
@property (nonatomic, copy) NSString *generalCapital;

@property (nonatomic, copy) NSString *increases;
@property (nonatomic, copy) NSString *flats;
@property (nonatomic, copy) NSString *decrements;

@property (nonatomic, strong) NSNumber *ibTradeBuySell;
@property (nonatomic, strong) NSNumber *ibTradeSell;

@property (nonatomic, copy) NSString *pbRate;

/**
 如果symbol为科创板代码，则symbolType为stock_kcb ，否则为stock
 */
@property (nonatomic, copy) NSString *symbolType;

@property (nonatomic, copy) NSString *roa;
@property (nonatomic, copy) NSString *roe;
@property (nonatomic, copy) NSString *floatAShare;

/**
 沪港通停止交易提醒。沪港通股票，且当前停止交易时，存在该字段，且值为需要显示的文案；否则结果中不存在该字段。
 */
@property (nonatomic, copy) NSString *nextConnectDate;

@property (nonatomic, copy) NSString *notice;

/**
 科创板盘后行情（可为null）
 */
@property (nonatomic, strong) TBAStockAfterMarketModel *afterMarket;

/**
 *  净值
 */
@property (nonatomic, copy) NSString<Optional> *netWorth;
@property (nonatomic, copy) NSString<Optional> *discountRate;

@property (nonatomic, strong) TBStockDetailNextMarketStatusModel<Optional> *nextMarketStatus;
@property (nonatomic, strong) TBStockDetailBriefModel<Optional> *hkstockBrief;

@property (nonatomic, readonly) NSArray *fundamentalArray;

/**
 总股本
 */
@property (nonatomic, strong) NSNumber *totalEquity;
/**
 每股收益（LYR,TTM）
 */
@property (nonatomic, strong) NSNumber *epsLYR;
@property (nonatomic, strong) NSNumber *epsTTM;

@property (nonatomic, readonly) NSString *peLYR;

@end

