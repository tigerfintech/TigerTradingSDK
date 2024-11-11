//
//  TBMarketFullPriceModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/TBBaseModel.h>

/*
 
 完整的盘口数据
 
 */



NS_ASSUME_NONNULL_BEGIN

@protocol TBMarketFullPriceItemModel <NSObject>
@end
@interface TBMarketFullPriceItemModel : TBBaseModel

@property (copy, nonatomic) NSString * _Nullable contractCode;      // 合约代码
//@property (copy, nonatomic) NSString * _Nullable contractId;     // 相关的合约ID
@property (assign, nonatomic) NSInteger priceOffset;    // 当前条⽬的价格偏移量
@property (assign, nonatomic) NSInteger avgPriceOffset;    // 当前条⽬的均价偏移量
@property (assign, nonatomic) NSInteger lastPrice;      // 最近成交的价格(值/10的priceOffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger newvol;         // 最新成交的⼿数
@property (assign, nonatomic) NSInteger bid;            // ⼀档买价(值/10的priceOffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger ask;            // ⼀档卖价(值/10的priceOffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger bidvol;         // ⼀档买量
@property (assign, nonatomic) NSInteger askvol;         // ⼀档卖量
@property (assign, nonatomic) NSInteger volume;         // 当⽇成交⼿数
@property (assign, nonatomic) NSInteger position;       // 未平仓合约量
@property (assign, nonatomic) NSInteger prePosition;    // 上⼀交易⽇收盘后持仓量(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger open;           // 开盘后第⼀笔交易的成交价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger high;           // 开盘后最⾼价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger low;            // 开盘后的最低价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger settlement;     // 这个交易⽇的结算价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger preSettlement;  // 上个交易⽇的结算价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger preClose;       // 上个交易⽇的最后⼀笔成交价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger limitUp;        // 交易所规定的涨停价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger limitDown;      // 交易所规定的跌停价格(值/10的priceoffset次⽅是真实的值)
@property (assign, nonatomic) NSInteger time;           // 报价时间，是14位的⻓整形时间戳
@property (assign, nonatomic) NSInteger vwap;              // 均价，暂时不加




//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////   辅助计算属性


@property (nonatomic, strong, readonly) NSNumber *quotesLastPrice;      // 最新价
@property (nonatomic, strong, readonly) NSNumber *quotesBid;            // 一档买价
@property (nonatomic, strong, readonly) NSNumber *quotesAsk;            // 一档卖价
@property (nonatomic, strong, readonly) NSNumber *quotesOpen;           // 开盘价
@property (nonatomic, strong, readonly) NSNumber *quotesHigh;           // 最高价
@property (nonatomic, strong, readonly) NSNumber *quotesLow;            // 最低价
@property (nonatomic, strong, readonly) NSNumber *quotesSettlement;     // 结算价
@property (nonatomic, strong, readonly) NSNumber *quotesPreSettlement;  // 上个交易日结算价
@property (nonatomic, strong, readonly) NSNumber *quotesPreClose;       // 上个交易日最后一笔成交价
@property (nonatomic, strong, readonly) NSNumber *quotesLimitUp;        // 交易所规定涨停价
@property (nonatomic, strong, readonly) NSNumber *quotesLimitDown;      // 交易所规定跌停价
@property (nonatomic, strong, readonly) NSNumber *quotesVwap;           // 均价，暂时不加


//////////////////////////////////////////////////////////////////

@property (nonatomic, strong, readonly) NSNumber *quotesProfit;         // 计算出来的盈亏
@property (nonatomic, strong, readonly) NSNumber *profitRatio;              // 盈亏比例
@end

@interface TBMarketFullPriceModel : TBBaseModel

@property (assign, nonatomic)  NSTimeInterval serverTime;

@property (copy, nonatomic, nonnull) NSArray <TBMarketFullPriceItemModel> *items;

@end



NS_ASSUME_NONNULL_END
