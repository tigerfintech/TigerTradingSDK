//
//  TBKLineItem.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>



//typedef  enum {
//    TBLineTypeCandle1Minute                  = 1,        // 1分
//    TBLineTypeCandle5Minute                  = 5,        // 5分
//    TBLineTypeCandle15Minute                 = 15,       // 15分
//    TBLineTypeCandle30Minute                 = 30,       // 30分
//    TBLineTypeCandle1Hour                    = 60,       // 60分
//    TBLineType4Hour                    = 240,      // 4小时, 未使用
//    TBLineTypeCandle1Day                     = 1440,     // 日K
//    TBLineTypeCandle1Week                    = 10080,    // 周K
//    TBLineTypeCandle1Month                   = 43200,    // 月K
//    TBLineType1Year                    = 518400,   // 年K
//    TBLineTypeAll                      = 5184000,  // 全部
//
//    TBLineTypeRealTime1Day             = 391,      // 分时
//    TBLineTypeRealTime5Day             = 1955      // 5日
//} TBLineType;

typedef enum{
    TBOrderValidDateDay                 = 0,// 当日有效
    TBOrderValidDateGTC                 = 1,// 撤销前有效
    TBOrderValidDateGTD                 = 2 // 到某日前有效
} TBOrderValidDate;

typedef enum {
    TBOrderActionBuy                    = 0,
    TBOrderActionSell                   = 1
} TBOrderAction;

typedef enum{
    TBOrderTypeLMT                      = 0,    // 限价单
    TBOrderTypeMKT                      = 1,    // 市价单
    TBOrderTypeSTP                      = 2,    // 止损单
    TBOrderTypeSTP_LIMIT                = 3,    // 止损限价单
    TBOrderTypeTRAIL                    = 4,    // 跟踪止损单
    TBOrderTypeTRAIL_LIMIT              = 5     // 跟踪止损限价单
    
} TBOrderType;


typedef NS_ENUM(NSInteger, TBPlaceOrderAction) {
    TBPlaceOrderActionBuy = 1,
    TBPlaceOrderActionSell,
    TBPlaceOrderActionClose, // 平仓
    TBPlaceOrderActionModify, // 改单
    TBPlaceOrderActionAdvisorPost, // 持仓交易帖    
};

/**
 附加订单类型

 - TBPlaceOrderAttachOrderTypeNone:
 - TBPlaceOrderAttachOrderTypeProfitTaker: 止盈单
 - TBPlaceOrderAttachOrderTypeStopLoss: 止损单
 - TBPlaceOrderAttachOrderTypeBracket: 括号订单
 - TBPlaceOrderAttachOrderTypeCoveredCallOption: 持保看涨期权(做多正股, 卖出价外看涨期权; 做空正股, 卖出价内看跌期权)(已取消，暂无此附加订单类型)
 - TBPlaceOrderAttachOrderTypeHedgeOption: 对冲期权(做多正股, 买入价内看跌期权; 做空正股, 买入价外看涨期权)（已下线，暂无此附加订单类型）
 */
typedef NS_ENUM(NSInteger, TBPlaceOrderAttachOrderType) {
    TBPlaceOrderAttachOrderTypeNone,
    TBPlaceOrderAttachOrderTypeProfitTaker,             ///< 止盈单
    TBPlaceOrderAttachOrderTypeStopLoss,                ///< 止损单
    TBPlaceOrderAttachOrderTypeBracket,                 ///< 括号订单
    TBPlaceOrderAttachOrderTypeCoveredCallOption,
    TBPlaceOrderAttachOrderTypeHedgeOption
};

typedef NS_ENUM(NSInteger, TBPlaceOrderComesFromType) {
    TBPlaceOrderComesFromTypeDefault,       //来自默认路径
    TBPlaceOrderComesFromTypeAdvisorPost,   //来自交易贴
};


#define DEFAULT_K_LINE_COUNT_INIT                       100
#define DEFAULT_K_LINE_INIT_DISPLAY_COUNT               65
#define DEFAULT_K_LINE_COUNT_OLDER                      100



@interface TBBaseKLineItem : JSONModel
/**
 *  ADD:LPF,在叠加图表里使用，计算好涨跌幅，在chart里直接使用
 */
@property (nonatomic, strong) NSNumber<Optional> *change;

@property (nonatomic, strong) NSNumber<Optional> *time;

@property (nonatomic, strong) NSNumber<Optional> *volume;

@property (nonatomic, strong) NSNumber<Optional> *lastTime;
@property (nonatomic, copy) NSString *timeStr;
@property (nonatomic, copy) NSString<Optional> *tradeMark; // 交易买卖点

//0：全部分时，1：盘前，2：盘中，3：盘后，5：夜盘
@property (nonatomic, strong) NSNumber<Optional> *type;

@end
