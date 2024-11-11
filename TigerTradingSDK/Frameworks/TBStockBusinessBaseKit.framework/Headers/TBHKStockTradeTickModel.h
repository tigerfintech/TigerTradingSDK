//
//  TBHKStockTradeTickModel.h
//  Stock
//
//  Created by Pengfei_Luo on 16/7/7.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import "TBStockDetailTradeDetailTableViewCell.h"
#import <TBBaseKit/JSONModel.h>

@protocol TBHKStockTradeTickModel
@end
@interface TBHKStockTradeTickModel : JSONModel <TBStockDetailTradeDetailTableViewCell>
@property (nonatomic, copy) NSString<Optional> *market;
@property (nonatomic, copy) NSString<Optional> *secType;
@property (nonatomic, strong) NSNumber<Optional> *price;
@property (nonatomic, copy) NSString<Optional> *type;
@property (nonatomic, strong) NSNumber<Optional> *volume;
@property (nonatomic, strong) NSNumber<Optional> *time;

@property (nonatomic, copy) NSString<Optional> *timeStr;

@property (nonatomic, strong) NSString<Optional> *detailTime;
@property (nonatomic, strong) NSString<Optional> *detailTimeWithSeconds; // 格式：HH:mm:ss

@property (nonatomic, strong) NSNumber<Optional> *tickID;

@property (nonatomic, copy) NSString<Optional> *tag;//pre,after,overnight...

/**
 一分钟内的涨跌幅，0 不涨不跌，1 涨，-1 跌
 */
@property (nonatomic, assign) double currentMinuteDirection;

/**
 展示价格，主要用于期货，根据合约类型转过的价格展示
 */
@property (nonatomic, copy) NSString *displayPrice;

/**
 买入卖出方向显示icon
 */
@property (nonatomic, strong) UIImage<Optional> *itemColor;

/**
 买入卖出方向，-表示无法判断买卖方向
 由于显示字号大小不一致，废弃
 */
@property (nonatomic, copy) NSString<Optional> *itemType;

/** 期权逐笔中，交易所映射字段名字简写
 */
@property (nonatomic, copy) NSString<Optional> *part;

/** 期权逐笔中，用于显示交易所名称
 */
@property (nonatomic, copy, readonly) NSString<Optional> *displayExchangeName;

@end

@protocol TBHKStockTradeTickStatsModel
@end


@interface TBHKStockTradeTickStatsModel: JSONModel

@property (nonatomic, strong) NSNumber<Optional> *downVol;
@property (nonatomic, strong) NSNumber<Optional> *upVol;
@property (nonatomic, strong) NSNumber<Optional> *lastVol;
@property (nonatomic, strong) NSNumber<Optional> *timestamp;

@property (nonatomic, copy) NSString<Optional> *market;
@property (nonatomic, copy) NSString<Optional> *detailTime;

- (void)convertTimestampToDetailTimeWithMarket:(NSString *)market;

@end


@interface TBHKStockTradeDetailModel : JSONModel

@property (nonatomic, strong) NSNumber<Optional> *beginIndex;
@property (nonatomic, strong) NSNumber<Optional> *endIndex;

@property (nonatomic, strong) NSArray<TBHKStockTradeTickModel *><Optional> *items;
@property (nonatomic, strong) NSArray<TBHKStockTradeTickStatsModel *><Optional> *stats;

@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, strong) NSNumber *serverTime;
@end
