//
//  TBStockDetailETFDepthInfoModel.h
//  Stock
//
//  Created by JustLee on 2019/7/31.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

@interface TBStockDetailETFDepthInfoModel : TBBaseModel

/**
 资产规模（现价
 */
@property (nonatomic, strong) NSNumber *assetSize;

/**
 流通份额
 */
@property (nonatomic, strong) NSNumber *sharesOutstanding;

/**
 资产规模（净值
 */
@property (nonatomic, strong) NSNumber *aum;

/**
 资产净值（昨日
 */
@property (nonatomic, strong) NSNumber *nav;

/**
 折扣/溢价率
 */
@property (nonatomic, strong) NSNumber *discountPremium;

/**
 日均差
 */
@property (nonatomic, strong) NSNumber *bidAskSpread;

/**
 分红频次
 */
@property (nonatomic, copy) NSString *distributionFrequency;

/**
 波动率均值
 */
@property (nonatomic, strong) NSNumber *avgDailyTradingVolume;

/**
 未平仓做空数量
 */
@property (nonatomic, strong) NSNumber *shortInterest;

/**
 净费率
 */
@property (nonatomic, strong) NSNumber *netExpenses;

/**
 是否支持期权
 */
@property (nonatomic, assign) BOOL optionsAvailable;

/**
 期权交易量
 */
@property (nonatomic, strong) NSNumber *optionsVolume;

/**
 认购期权交易量
 */
@property (nonatomic, strong) NSNumber *callVolume;

/**
 认沽期权交易量
 */
@property (nonatomic, strong) NSNumber *putVolume;

@end
