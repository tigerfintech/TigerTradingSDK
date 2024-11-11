//
//  TBStockDetailCombineModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/1/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBStockKit/NSString+TBStock.h>
@class TBAStockSymbolMetaItemModel;
@class TBStockInfoDetailItemModel;
@class TBStockDetailFunmatenalModel;
@class TBStockDetailETFDepthInfoModel;
@class TBFutruesCombineModel;
@class TBOptionFundamentalModel;
@class TBOptionInfoDetailItem;
@class TBCombineOptionFundamentalModel;
@class TBCombineOptionInfoDetailItem;

NS_ASSUME_NONNULL_BEGIN
/*
 个股详情页组合model
 
 wiki:https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=81232780
 */

/**
 这里的顺序经过多次调整，历史包袱越来越重
 基本面的排序有以下分支，仅供参考：
 概念板块
 期货
 数字货币
 债券
 外汇
 
 期权：
 美股期权
 港股期权

 指数：
 A股三大指数分支
 A股其他指数
 港股指数
 其他指数

 股票：
 a股
 美股澳股
 港股
 新加坡股
 伦敦股票

 特殊分支：
 港股涡轮牛熊分支
 港股暗盘
 美澳股的etf分支
 a股基金分支
 新加坡股的dlc分支
 */

@interface TBStockDetailCombineModel : JSONModel

@property (nonatomic, assign) BOOL isContra;

//应用于个股页pro版和基本面二级页https://tigertech.feishu.cn/docs/doccn5QplVXq5ZECSF7jTWDY3Vg
@property (nonatomic, copy) NSArray *proFundamentalArray;

//应用于个股页lite版https://tigertech.feishu.cn/docx/Bv3KdzNSrovyKyxfM9Qc5D1ynEf
@property (nonatomic, copy) NSArray *liteFundamentalArray;
/**
 *  股票代码，必须传
 */
@property (nonatomic, copy) NSString *symbol;

/**
 *  股票名称，可不传
 */
@property (nonatomic, copy) NSString *nameCN;

/**
 *  股票市场，必须传，如果没有传会使用[NSString getStockMarketFromSymbol:_symbol]判断市场
 */
@property (nonatomic, copy) NSString *market;

/**
 股票类型。
 期货必传，否则按股票处理。。。。。。
 */
@property (nonatomic, copy) NSString *secType;

@property (nonatomic, assign) BOOL isGreyMarket;

/// 处理A股基本数据
@property (nonatomic, strong) TBAStockSymbolMetaItemModel *astockItemModel;

/// 处理A股以外市场基本数据
@property (nonatomic, strong) TBStockInfoDetailItemModel *stockItemModel;

/// 美股部分指标在fundamental接口
@property (nonatomic, strong) TBStockDetailFunmatenalModel *fundamental;

/// A股部分指标在chartModel 里
//@property (nonatomic, strong) TBFundamentChartModel *chartModel;

@property (nonatomic, strong) TBStockDetailETFDepthInfoModel *etfDepthModel;

@property (nonatomic, strong) TBFutruesCombineModel *futureModel;

#pragma mark --- 单腿期权
@property (nonatomic, strong) TBOptionFundamentalModel *optionFundamentalModel;
@property (nonatomic, strong) TBOptionInfoDetailItem *optionInfoItem;
#pragma mark --- 组合期权
@property (nonatomic, strong) TBCombineOptionFundamentalModel *combineOptionModel;
@property (nonatomic, strong) TBCombineOptionInfoDetailItem *combineOptionInfo;

@end

NS_ASSUME_NONNULL_END
