#import <TBTradeBusinessBaseKit/TBPlaceOrderConstants.h>
//
//  TBPlaceOrderConstants.h
//  Pods
//
//  Created by swordzhou on 2021/8/4.
//

#ifndef TBPlaceOrderConstants_h
#define TBPlaceOrderConstants_h

typedef NS_ENUM(NSUInteger, TBOrderPriceInputType) {
    TBOrderPriceInputTypeDefault,    ///< 手动输入
    TBOrderPriceInputTypeBuy1,       ///< 买一价 跟随
    TBOrderPriceInputTypeSell1,      ///< 卖一价 跟随
    TBOrderPriceInputTypeMid,        ///< 中间价
    TBOrderPriceInputTypeLatest,     ///< 最新价
    TBOrderPriceInputTypeCounter,    ///< 对手价 - 期货用
    TBOrderPriceInputTypeQueuing,    ///< 排队价
    TBOrderPriceInputTypeMarket,     ///< 市场价
    TBOrderPriceInputTypeBid1,
    TBOrderPriceInputTypeAsk1,
    TBOrderPriceInputTypeLast,
    TBOrderPriceInputTypeCustom,     ///< 外部传入
    TBOrderPriceInputType1Percent,           ///< 1%
    TBOrderPriceInputType2Percent,           ///< 2%
    TBOrderPriceInputType5Percent,           ///< 5%
    TBOrderPriceInputType10Percent,          ///< 10%
    TBOrderPriceInputTypeNegative1Percent,   ///< 1%
    TBOrderPriceInputTypeNegative2Percent,   ///< 2%
    TBOrderPriceInputTypeNegative5Percent,   ///< 5%
    TBOrderPriceInputTypeNegative10Percent,  ///< 10%
    TBSNStrikePercentageInput70Percent,      ///< 70%
    TBSNStrikePercentageInput80Percent,      ///< 80%
    TBSNStrikePercentageInput90Percent,      ///< 90%
    TBSNCouponPercentageInput5Percent,       ///< 5%
    TBSNCouponPercentageInput10Percent,      ///< 10%
    TBSNCouponPercentageInput15Percent,      ///< 15%
};

typedef NS_ENUM(NSInteger, TBMakeOrderCheckItem) {
    TBMakeOrderCheckNone,
    TBMakeOrderCheckOutsideRTH, // 允许盘前盘后交易
    TBMakeOrderCheckStockAlert, // 毛票交易提醒
    TBMakeOrderCheckMarketOrder, // 主订单市价单
    TBMakeOrderCheckDayTrades, // T+0
    TBMakeOrderCheckStockShort, // 股票做空提醒
    TBMakeOrderCheckOptionShort, // 期权做空提醒
    TBMakeOrderCheckAmountLimit, // 单笔最高金额
    TBMakeOrderCheckComboTypes,  // 组合类型持仓
    
    TBMakeOrderValidateTypeBasic,
    TBMakeOrderValidateTypeTick, // 精度
    TBMakeOrderValidateTypeLimited, // 受限保证金账户
    TBMakeOrderValidateTypeOrderDetail, // 订单详情预览
};

typedef NS_ENUM(NSUInteger, TBPlaceOrderBuyWaysType) {
    TBPlaceOrderBuyWaysTypeShares = 0,///< 按数量下单
    TBPlaceOrderBuyWaysTypeMoney,     ///< 按金额下单
};

typedef NS_ENUM(NSUInteger, TBPlaceOrderQuantityQucikSelectType) {
    TBPlaceOrderQuantityQucikSelectTypeNone = 0,
    TBPlaceOrderQuantityQucikSelectTypeQuarter,          // 1/4
    TBPlaceOrderQuantityQucikSelectTypeOneThird,         // 1/3
    TBPlaceOrderQuantityQucikSelectTypeHalf,             // 1/2
    TBPlaceOrderQuantityQucikSelectTypeThreeQuarters,    // 3/4
    TBPlaceOrderQuantityQucikSelectTypeFull,             // full
};

/// lite按金额下单选项
typedef NS_ENUM(NSUInteger, TBPlaceOrderShareQucikSelectType) {
    TBPlaceOrderShareQucikSelectTypeNone = 0,
    TBPlaceOrderShareQucikSelectTypeFive,          // 5
    TBPlaceOrderShareQucikSelectTypeFifty,         // 50
    TBPlaceOrderShareQucikSelectTypeHundred,       // 100
    TBPlaceOrderShareQucikSelectTypeTwoHundred,    // 200
};

static NSString *NOTIFICATION_KEY_DID_CHANGE_MOST_USED_QUANTITY = @"NOTIFICATION_KEY_DID_CHANGE_MOST_USED_QUANTITY";

/*盈亏分析*/
static NSString *USER_ANAlYSIS_PNL_START_DATE = @"userAnalysisPNLStartDate";
static NSString *USER_ANAlYSIS_PNL_END_DATE = @"userAnalysisPNLEndDate";
static NSString *USER_ANAlYSIS_PNL_DATE_TITLE = @"userAnalysisPNLDateTitle";
static NSString *USER_ANAlYSIS_PNL_DATE_Type = @"userAnalysisPNLDateType";



#endif /* TBPlaceOrderConstants_h */
