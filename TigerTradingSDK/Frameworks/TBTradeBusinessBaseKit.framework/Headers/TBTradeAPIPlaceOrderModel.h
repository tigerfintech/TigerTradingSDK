//
//  TBTradeAPIPlaceOrderModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/25.
//

#import <TBBaseKit/JSONModel.h>
#import "TBPlaceOrderContractInfoConstants.h"
#import "TBPlaceOrderConstants.h"
#import <TBBusinessSupportKit/TBCouponDelegate.h>

@protocol TBCouponDelegate;
@class TBPlaceOrderConditionItem;
@class TBOrderParams;
@class TBPlaceOrderBriefFrequencyModel;
@class TBPlaceOrderMLegItemModel;

NS_ASSUME_NONNULL_BEGIN

#pragma mark 2 下单
@interface TBTradeAPIPlaceOrderModel : JSONModel

@property (nonatomic, strong) NSNumber *orderId;                                // 订单ID. 通过 /trade/get_max_order_id 接口获取
// TODO: 添加id<TBPlaceOrderModel>类型后改回integer类型
//@property (nonatomic, assign) NSInteger orderId;
@property (nonatomic, copy) NSString *symbol;                                   // 底层股票代码
@property (nonatomic, copy, nullable) NSString <Optional> *localSymbol;         // 股票代码. 美股用于消除歧义, 同symbol; 港股用于识别窝轮和牛熊证
@property (nonatomic, copy) NSString *underlyingSymbol;                         // 底层股票代码 港股期权对应的正股代码
@property (nonatomic, copy) NSString *secType;                                  // 合约类型(STK 股票, OPT 美股期权, WAR 港股窝轮, IOPT 港股牛熊证)
@property (nonatomic, copy, nullable) NSString <Optional> *exchange;            // 交易所(美股 SMART, 港股 SEHK, 沪港通 SEHKNTL, 深港通 SEHKSZSE,伦敦交易所 lse)
@property (nonatomic, copy) NSString *market;                                   // 市场(美股 US, 港股 HK, 沪港通 CN)
@property (nonatomic, copy) NSString *currency;                                 // 货币(美股 USD, 港股 HKD, 沪港通 CNH)
@property (nonatomic, copy, nullable) NSString <Optional> *expiry;              // 过期日. 期权, 窝轮, 牛熊证专属
@property (nonatomic, copy, nullable) NSString <Optional> *strike;              // 底层价格. 期权, 窝轮, 牛熊证专属
@property (nonatomic, copy, nullable) NSString <Optional> *right;               // 期权方向(PUT/CALL). 期权, 窝轮, 牛熊证专属
@property (nonatomic, strong, nullable) NSNumber <Optional> *multiplier;         // 1手单位. 期权, 窝轮, 牛熊证专属
@property (nonatomic, copy) NSString *action;                                   // 交易方向(BUY/SELL)
@property (nonatomic, copy) NSString *orderType;                                // 订单类型(MKT 市价, LMT 限价, STP 止损, STP_LMT 止损限价, TRAIL 跟踪止损)
@property (nonatomic, copy) NSArray *attrs;                                     // 下单额外属性和action配置使用，CDP Sell时action=SELL attrs=[CDP]
@property (nonatomic, copy, nullable) NSString *trailType;                      //7.1.7 版本 综合账户新增跟踪止损单类型 PERCENT:百分比 AMOUNT:差额
@property (nonatomic, strong,nullable) NSNumber *totalQuantity;                 // 订单数量. 港股, 沪港通, 窝轮, 牛熊证有最小数量限制
@property (nonatomic, copy) NSString *timeInForce;                              // 有效时间(DAY 当日有效, GTC 取消前有效, GTD 指定日期前有效, AUC集合竞价(港股, 订单类型为MTL, 需要填limitPrice))
@property (nonatomic, copy) NSString *tradingSessionType;

@property (nonatomic, copy, nullable) NSString <Optional> *goodTillDate;        // GTD时间, 格式"20060505 08:00:00 EST"
@property (nonatomic, assign) BOOL outsideRth;                                  // 是否允许盘前盘后交易 美股专属 YES:允许盘前盘后 NO:不允许盘前盘后
@property (nonatomic, assign, readonly) BOOL isExtendedHourTrading;             // 是否为延长时间段交易
@property (nonatomic, strong, nullable) NSNumber <Optional> *limitPrice;        // 限价(LMT), 止损限价(STP_LMT)
@property (nonatomic, copy, nullable) NSString <Optional> *futuresLimitPrice;   // 期货限价，string往外传
@property (nonatomic, strong, nullable) NSNumber <Optional> *auxPrice;          // 止损价(STP, STP_LMT), 跟踪额(TRAIL)

@property (nonatomic, strong, nullable) NSString <Optional> *futuresAuxPrice;   // 期货止损价，string往外传

@property (nonatomic, strong, nullable) NSNumber <Optional> *trailAmount;       // 7.1.7版本新加字段，跟踪止损单价差(TRAIL)，百分比服用之前字段trailingPercent
@property (nonatomic, strong, nullable) NSNumber <Optional> *trailingPercent;   // 跟踪止损单百分比(TRAIL)

@property (nonatomic, strong, nullable) NSNumber <Optional> *attachedOcaAmount;       // 9.0版本新加字段，附加括号订单-触发止盈/止损金额
@property (nonatomic, strong, nullable) NSNumber <Optional> *attachedOcaPercent;   // 9.0版本新加字段，附加括号订单-触发百分比

@property (nonatomic, strong, nullable) TBOrderParams *params;             //订单额外参数，算法单TWAP和VWAP时存在

// 附加订单
@property (nonatomic, strong, nullable) NSNumber <Optional> *profitTakerPrice;  // 止盈单限价
@property (nonatomic, copy, nullable) NSString <Optional> *profitTakerTif;      // 止盈单有效期
@property (nonatomic, strong, nullable) NSNumber <Optional> *profitTakerRth;    // 止盈单盘前盘后
@property (nonatomic, strong, nullable) NSNumber <Optional> *stopLossPrice;     // 止损单止损价
@property (nonatomic, copy, nullable) NSString <Optional> *stopLossTif;         // 止损单有效期
@property (nonatomic, strong, nullable) NSNumber <Optional> *stopLossRth;       // 止损单盘前盘后
// T+0 == 0 时下单
@property (nonatomic, strong, nullable) NSNumber <Optional> *forceDayTrading;

// TODO: 业务数据移动到别处
// 下单页区分百分比, 价差
@property (nonatomic, strong) NSNumber<Ignore> *isTrailingPercent;
// 附加订单类型
@property (nonatomic, strong) NSNumber<Ignore> *attachOrderType;
//

// 副订单属性
@property (nonatomic, strong) NSNumber<Optional> *parentId;  // 环球账户：附加订单的父订单 ID； 综合账户：如果是附加订单的话，该字段有值 表示该订单为 附加订单的子订单，如果没有值表示为改订单为附加订单的主订单 对应 TBOmnibusAPIOrderModel 中的 parentOrderId
@property (nonatomic, strong) NSNumber<Optional> *hedgeType; // Pair Trade
@property (nonatomic, strong) NSNumber<Optional> *hedgeRatio; // 股票是1.0, 期权是0.01

@property (nonatomic, copy) NSString *source;


@property (nonatomic, copy, nullable) NSArray<TBPlaceOrderConditionItem *> *conditions;///< 条件订单的条件列表
@property (nonatomic, copy, nullable) NSString *triggerStatus;///< 条件订单 条件状态 [NEW, TRIGGERED]

@property (nonatomic, assign) BOOL greyMarketSupported;///< 是否支持暗盘交易

@property (nonatomic, copy, nullable) NSString *composedOrderType;  ///< 组合订单类型 - 附加订单 括号订单 条件订单
@property (nonatomic, copy, nullable) NSString *attachMainOrderType;///< 组合订单类型 - 对应的主订单类型 条件订单

@property (nonatomic, strong, nullable) TBTradeAPIPlaceOrderModel *attachedOrder;///< 附加订单

/** 9.0 基础类型增加附加OCA订单
 *  附加OCA订单有两个子订单，这是第二个订单
 */
@property (nonatomic, strong, nullable) TBTradeAPIPlaceOrderModel *attachedOcaAnotherOrder;

@property (nonatomic, assign) BOOL hasChildren;///< 附加订单 用，是否是主订单

@property (nonatomic, assign) TBOrderPriceInputType limitPriceInputType; /// <限价输入类型

@property (nonatomic, strong) NSNumber *flowPrice;                      ///< 改变的价格


@property (nonatomic, assign) TBOrderPriceInputType profitStopPriceInputType; ///< 附加订单子订单 - 止盈限价 限价输入类型
@property (nonatomic, strong) NSNumber *profitStopFlowPrice;///< 附加订单子订单 - 止盈限价 限价输入类型

@property (nonatomic, assign) BOOL isOdd;                   ///< 是否是碎股单
@property (nonatomic, assign) BOOL isPreIpo;                ///< 是否安排订单

@property (nonatomic, copy) NSString *externalID;           ///< 综合账户所需去重ID

@property (nonatomic, copy, nullable) NSArray<TBCouponDelegate> *coupons; /// < 下单选择的优惠信息

@property (nonatomic, assign) BOOL isModifyOrder;                ///< 是否为改单

@property (nonatomic, strong) NSNumber * _Nullable cashAmount;///< 按金额下单的订单总金额

@property (nonatomic, assign) TBPlaceOrderBuyWaysType buyWaysType;///< 买入方式，默认按数量买入，自定义订单属性标识，不需要上传到服务端，719 版本只支持市价单买入时设置 https://app.asana.com/0/792932789264562/1201891027531793/f

@property (nonatomic, assign, getter=isOddLotsSell) BOOL oddLotsSell;///< 是否为碎股卖出

/** 禁用碎股
 *  805 lite版下单页未适配碎股功能，因此当下单页是lite版时，禁用碎股设置
 */
@property (nonatomic, assign) BOOL forceDisableFractionShare;

/// 定投频率model，811 lite下单页使用
@property (nonatomic, strong, nullable) TBPlaceOrderBriefFrequencyModel *autoInvestFrequencyModel;

/// 901 组合期权策略类型（字段名和server统一）
@property (nonatomic, copy, nullable) NSString *comboType;
@property (nonatomic, copy, nullable) NSString *comboTypeName;

/// 901 legs组合期权腿信息
@property (nonatomic, copy, nullable) NSArray <TBPlaceOrderMLegItemModel *> *legs;

//OTC Expert/Grey 平仓订单
@property (nonatomic, assign) BOOL isOTCExpertGreyCloseOrder;
@property (nonatomic, assign) BOOL solicited;
@property (nonatomic, assign) BOOL nonAffiliate;


- (instancetype)initWithPlaceOrderModel:(TBTradeAPIPlaceOrderModel *)placeOrderModel;

- (BOOL)isAlgorithmOrder;
- (BOOL)isAlgorithmLimitOrder;
- (BOOL)isAlgorithmMarketOrder;
- (BOOL)isConditionOrder;
- (BOOL)isCDPSellOrder;

@end

NS_ASSUME_NONNULL_END
