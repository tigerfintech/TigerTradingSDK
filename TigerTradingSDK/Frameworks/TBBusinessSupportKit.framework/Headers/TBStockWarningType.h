//
//  TBStockWarningType.h
//  Stock
//
//  Created by yangfan on 2020/2/23.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#ifndef TBStockWarningType_h
#define TBStockWarningType_h

typedef enum : NSUInteger
{
    TBStockWarningTypePriceUpTo = 101,    //股价涨到
    TBStockWarningTypePriceDownTo = 102,  //股价跌到
    TBStockWarningTypePriceUpPercent = 103,    //当日涨超
    TBStockWarningTypePriceDownPercent = 104,  //当日跌超
    TBStockWarningTypeTurnOver = 201,     //日成交额超
    TBStockWarningTypeVolumeOver = 202,     //日成交量超
    TBStockWarningTypeTORate = 203,     //日换手率超
    TBStockWarningTypeBid1Over = 206,     //买一价超
    TBStockWarningTypeAsk1Over = 207,     //卖一价超
    TBStockWarningTypeBid1VolOver = 204,     //买一量超
    TBStockWarningTypeAsk1VolOver = 205,     //卖一量超
    //标题
    TBStockWarningTypeMACDGoldAbove = 300,      //MACD零轴上方金叉
    
    TBStockWarningTypeMACDGoldAboveDay = 301,   //MACD零轴上方金叉.指标提醒,日
    TBStockWarningTypeMACDGoldAboveWeek = 302,   //MACD零轴上方金叉,指标提醒,周
    TBStockWarningTypeMACDGoldAboveMonth = 303,  //MACD零轴上方金叉,指标提醒,月
    
    //标题
    TBStockWarningTypeMACDGoldLow = 400,      //MACD零轴下方金叉
    
    TBStockWarningTypeMACDGoldLowDay = 401,   //MACD零轴下方金叉.指标提醒,日
    TBStockWarningTypeMACDGoldLowWeek = 402,   //MACD零轴下方金叉,指标提醒,周
    TBStockWarningTypeMACDGoldLowMonth = 403,  //MACD零轴下方金叉,指标提醒,月
    
    //标题
    TBStockWarningTypeMACDDeadAbove = 500,      //MACD零轴上方死叉
    
    TBStockWarningTypeMACDDeadAboveDay = 501,   //MACD零轴上方死叉,指标提醒,日
    TBStockWarningTypeMACDDeadAboveWeek = 502,   //MACD零轴上方死叉,指标提醒,周
    TBStockWarningTypeMACDDeadAboveMonth = 503,  //MACD零轴上方死叉,指标提醒,月
    
    //标题
    TBStockWarningTypeMACDDeadLow = 600,      //MACD零轴下方死叉
    
    TBStockWarningTypeMACDDeadLowDay = 601,   //MACD零轴下方死叉,指标提醒,日
    TBStockWarningTypeMACDDeadLowWeek = 602,   //MACD零轴下方死叉,指标提醒,周
    TBStockWarningTypeMACDDeadLowMonth = 603,  //MACD零轴下方死叉,指标提醒,月
    //标题
    TBStockWarningTypeRSIOverBought = 700,       ///RSI超买
    
    TBStockWarningTypeRSI6OverBoughtDay = 701,    //RSI6超买,指标提醒,日
    TBStockWarningTypeRSI6OverBoughtWeek = 702,   //RSI6超买,指标提醒,周
    TBStockWarningTypeRSI6OverBoughtMonth = 703,  //RSI6超买,指标提醒,月
    TBStockWarningTypeRSI12OverBoughtDay    = 901,    //RSI12超买,指标提醒,日
    TBStockWarningTypeRSI12OverBoughtWeek   = 902,    //RSI12超买,指标提醒,周
    TBStockWarningTypeRSI12OverBoughtMonth  = 903,    //RSI12超买,指标提醒,月
    TBStockWarningTypeRSI24OverBoughtDay    = 1101,    //RSI24超买,指标提醒,日
    TBStockWarningTypeRSI24OverBoughtWeek   = 1102,    //RSI24超买,指标提醒,周
    TBStockWarningTypeRSI24OverBoughtMonth  = 1103,    //RSI24超买,指标提醒,月
    
    //标题
    TBStockWarningTypeRSIOverSell = 800,          ///RSI超卖
    
    TBStockWarningTypeRSI6OverSellDay   = 801,    //RSI6超卖,指标提醒,日
    TBStockWarningTypeRSI6OverSellWeek  = 802,    //RSI6超卖,指标提醒,周
    TBStockWarningTypeRSI6OverSellMonth = 803,    //RSI6超卖,指标提醒,月
    TBStockWarningTypeRSI12OverSellDay      = 1001,   //RSI12超卖,指标提醒,日
    TBStockWarningTypeRSI12OverSellWeek     = 1002,   //RSI12超卖,指标提醒,周
    TBStockWarningTypeRSI12OverSellMonth    = 1003,   //RSI12超卖,指标提醒,月
    TBStockWarningTypeRSI24OverSellDay      = 1201,    //RSI24超卖,指标提醒,日
    TBStockWarningTypeRSI24OverSellWeek     = 1202,    //RSI24超卖,指标提醒,周
    TBStockWarningTypeRSI24OverSellMonth    = 1203,    //RSI24超卖,指标提醒,月
    
    //标题
    TBStockWarningTypeBullish = 1300,          ///上穿均线
    
    TBStockWarningTypeBullishMA5Day         = 1301,    //上穿均线MA5,指标提醒,日
    TBStockWarningTypeBullishMA5Week        = 1302,    //上穿均线MA5,指标提醒,周
    TBStockWarningTypeBullishMA5Month       = 1303,    //上穿均线MA5,指标提醒,月
    TBStockWarningTypeBullishMA10Day        = 1401,    //上穿均线MA10,指标提醒,日
    TBStockWarningTypeBullishMA10Week       = 1402,    //上穿均线MA10,指标提醒,周
    TBStockWarningTypeBullishMA10Month      = 1403,    //上穿均线MA10,指标提醒,月
    TBStockWarningTypeBullishMA20Day        = 1501,    //上穿均线MA20,指标提醒,日
    TBStockWarningTypeBullishMA20Week       = 1502,    //上穿均线MA20,指标提醒,周
    TBStockWarningTypeBullishMA20Month      = 1503,    //上穿均线MA20,指标提醒,月
    TBStockWarningTypeBullishMA30Day        = 1601,    //上穿均线MA30,指标提醒,日
    TBStockWarningTypeBullishMA30Week       = 1602,    //上穿均线MA30,指标提醒,周
    TBStockWarningTypeBullishMA30Month      = 1603,    //上穿均线MA30,指标提醒,月
    TBStockWarningTypeBullishMA60Day        = 1701,    //上穿均线MA60,指标提醒,日
    TBStockWarningTypeBullishMA60Week       = 1702,    //上穿均线MA60,指标提醒,周
    TBStockWarningTypeBullishMA60Month      = 1703,    //上穿均线MA60,指标提醒,月
    
    //标题
    TBStockWarningTypeBearish = 1800,          ///下穿均线
    
    TBStockWarningTypeBearishMA5Day         = 1801,    //下穿均线MA5,指标提醒,日
    TBStockWarningTypeBearishMA5Week        = 1802,    //下穿均线MA5,指标提醒,周
    TBStockWarningTypeBearishMA5Month       = 1803,    //下穿均线MA5,指标提醒,月
    TBStockWarningTypeBearishMA10Day        = 1901,    //下穿均线MA10,指标提醒,日
    TBStockWarningTypeBearishMA10Week       = 1902,    //下穿均线MA10,指标提醒,周
    TBStockWarningTypeBearishMA10Month      = 1903,    //下穿均线MA10,指标提醒,月
    TBStockWarningTypeBearishMA20Day        = 2001,    //下穿均线MA20,指标提醒,日
    TBStockWarningTypeBearishMA20Week       = 2002,    //下穿均线MA20,指标提醒,周
    TBStockWarningTypeBearishMA20Month      = 2003,    //下穿均线MA20,指标提醒,月
    TBStockWarningTypeBearishMA30Day        = 2101,    //下穿均线MA30,指标提醒,日
    TBStockWarningTypeBearishMA30Week       = 2102,    //下穿均线MA30,指标提醒,周
    TBStockWarningTypeBearishMA30Month      = 2103,    //下穿均线MA30,指标提醒,月
    TBStockWarningTypeBearishMA60Day        = 2201,    //下穿均线MA60,指标提醒,日
    TBStockWarningTypeBearishMA60Week       = 2202,    //下穿均线MA60,指标提醒,周
    TBStockWarningTypeBearishMA60Month      = 2203,    //下穿均线MA60,指标提醒,月
}TBStockWarningType;

typedef enum : NSUInteger
{
    TBGenerateWarningTypeCreateNew,
    TBGenerateWarningTypeModify,
}TBGenerateWarningType;

#endif /* TBStockWarningType_h */
