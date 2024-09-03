//
//  TBTradeAPIOrderModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/25.
//


#import "TBTradeAPIModel.h"
#import "TBPlaceOrderContractInfoConstants.h"
#import <TBBaseKit/TBBaseModel.h>
#import "TBConditionOrderConstants.h"
#import "TBOrderFeeCategoryModel.h"
#import "TBPlaceOrderConditionItem.h"
#import "TBOmnibuAPIOrderLegInfoModel.h"
#import "TBOrderPnlRespModel.h"

@class TBOrderReabtesModel;
@class TBOrderParams;
@class TBOmnibusAPIAssetExcessLiquidityPreviewModel;
@class TBOminibusAPIOrderModifyParamsInfoModel;
@class TBIBAPIOrderModifyParamsInfoModel;
@class TBFCNOrderModel;
@class TBBondExtraInfoModel;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 6 获取用户委托订单
@protocol TBTradeAPIOrderItemModel, TBOmnibuAPIOrderLegInfoModel;

@interface TBTradeAPIOrderModel : TBTradeAPIModel

@property (nonatomic, copy) NSArray<TBTradeAPIOrderItemModel> *items;
// undocumented
@property (nonatomic, strong, nullable) NSNumber <Optional> *hasMore;

@end

@interface TBTradeAPIOrderItemModel : TBBaseModel

@property (nonatomic, assign) long long orderId; // 订单Id
// TODO: 为和omnibus统一, 类型改为 long long
//@property (nonatomic, assign) NSInteger orderId
@property (nonatomic, copy) NSString *symbol;              // 股票代码
@property (nonatomic, copy) NSString *comboType;           // 策略 key
@property (nonatomic, copy) NSString *comboTypeName;       // 策略 名称
@property (nonatomic, copy) NSString *underlyingSymbol;    // 底层股票代码 港股期权对应的正股代码 用于社区港股期权跳转正股

@property (nonatomic, copy) NSString *optionSymbol;      //期权symbol
@property (nonatomic, copy) NSString *nameCN;           // 中文名称
@property (nonatomic, strong) NSNumber *latestPrice; // 最新价格
@property (nonatomic, strong) NSNumber *quoteLatestPrice;    // 根据行情权限请求最新价格


@property (nonatomic, copy) NSString *action;           // 买入或卖出 BUY/SELL
@property (nonatomic, copy) NSString *orderType;        // 订单类型
@property (nonatomic, copy) NSString *trailType;        //7.1.7 版本 综合账户新增跟踪止损单类型 PERCENT:百分比 AMOUNT:差额
@property (nonatomic, strong) NSNumber *trailAmount;     //7.1.7 版本 追踪止损条件数值，当 trail_type 为 PERCENT 时，比如设置 25.15%，那么 trail_amount 应该为 25.15

@property (nonatomic, strong, nullable) TBOrderParams *params;             //订单额外参数，算法单TWAP和VWAP时存在

@property (nonatomic, strong) NSNumber *totalQuantity;  // 总数
@property (nonatomic, strong) NSNumber *totalQuantityScale;  // 总数
@property (nonatomic, strong) NSNumber *realTotalQuantity;  // 总数
@property (nonatomic, strong) NSNumber *totalCashAmount;  // 下单总金额(基金、按金额下单)

@property (nonatomic, strong) NSNumber *realFilledQuantity; // 执行数目
@property (nonatomic, strong) NSNumber *filledQuantity; // 执行数目
@property (nonatomic, strong) NSNumber *filledQuantityScale; // 执行数目
@property (nonatomic, strong) NSNumber *filledCashAmount;  // 已成交总金额(基金、按金额下单)

@property (nonatomic, strong) NSNumber *avgFillPrice; // 平均成本
@property (nonatomic, copy) NSString *fundAvgFillPrice; // 基金平均成本 （闲钱3.0使用）
@property (nonatomic, copy) NSString *futureAvgFillPrice; // 平均成本
@property (nonatomic, copy) NSString *timeInForce;        // DAY/GTC
@property (nonatomic, copy) NSString *tradingSessionType; //OVERNIGHT PRE_RTH_POST
@property (nonatomic, assign) BOOL outsideRth;            //是否允许盘前盘后
/**
 PendingNew 订单请求已收到,但尚未被接收
 New 订单已经提交
 Filled 完全成交
 Canceled 已取消
 Rejected 已拒绝
 Expired 已过期
 */
@property (nonatomic, copy) NSString *originalStatus;  // 未转换数据的订单状态
@property (nonatomic, assign) NSInteger status;         // 订单状态
@property (nonatomic, assign) BOOL canCancel;                   // 能否取消订单
@property (nonatomic, assign) BOOL canModify;                   // 能否修改订单
@property (nonatomic, assign) NSTimeInterval openTime;            // 订单创建时间
@property (nonatomic, assign) NSTimeInterval latestTime;          // 订单最近修改时间
@property (nonatomic, copy, nullable) NSString <Optional> *attrDesc;             //   特殊订单描述，Omnibus用

@property (nonatomic, strong, nullable) NSNumber <Optional> *limitPrice;        // 订单价格要素
@property (nonatomic, strong, nullable) NSNumber <Optional> *auxPrice;          // 订单价格要素
@property (nonatomic, strong, nullable) NSNumber <Optional> *trailingPercent;   // 订单价格要素
@property (nonatomic, copy, nullable) NSString <Optional> *strike;              // 底层价格
@property (nonatomic, copy, nullable) NSString <Optional> *right;               // PUT/CALL
@property (nonatomic, copy, nullable) NSString <Optional> *expiry;              // 过期日 格式yyyyMMdd
@property (nonatomic, strong, nullable) NSNumber <Optional> *multiplier;
@property (nonatomic, strong, nullable) NSNumber <Optional> *realizedPNL;       //实现盈亏
@property (nonatomic, strong, nullable) NSNumber <Optional> *realizedPnlByAverage;///< 订单的平均成本已实现盈亏

// undocumented
@property (nonatomic, strong, nullable) NSNumber <Optional> *id;
@property (nonatomic, copy, nullable) NSString <Optional> *localSymbol;         // 窝轮牛熊证用于区分正股, 其他同symbol
@property (nonatomic, copy, nullable) NSString <Optional> *originSymbol;        // 股票同symbol, 期权窝轮牛行政格式为"symbol expiry strike right"
@property (nonatomic, copy, nullable) NSString <Optional> *secType;
@property (nonatomic, copy, nullable) NSString <Optional> *secSubType;          // 交易品种子类型，如票据下面的 FCN、ELN
@property (nonatomic, copy, nullable) NSString <Optional> *secGroupType;
@property (nonatomic, strong, nullable) NSNumber <Optional> *portfolioId;
@property (nonatomic, copy, nullable) NSString <Optional> *market;
@property (nonatomic, copy, nullable) NSString <Optional> *currency;            // 交易货币 USD/HKD/CNH
@property (nonatomic, strong, nullable) NSNumber <Optional> *commission;        // 佣金
@property (nonatomic, strong, nullable) NSNumber <Optional> *commissionAndFee;  // 佣金费用总计
@property (nonatomic, strong, nullable) NSNumber <Optional> *gst;               // gst消费税

@property (nonatomic, strong, nullable) NSNumber * upfrontProportion; ///< 813 upfrontFee比例

@property (nonatomic, strong, nullable) NSNumber * upfrontFee; ///< 813 upfrontFee金额

@property (nonatomic, strong, nullable) NSNumber * reqCashAmount; ///< 813 下单委托金额（外扣真是下单金额相同）

/// 免佣状态: 1待免佣 2已免佣 0默认值
@property (nonatomic, strong, nullable) NSNumber <Optional> *discount;

/// 免佣金额. 仅在订单详情接口(/orders/{id})返回该字段
@property (nonatomic, strong, nullable) NSNumber <Optional> *commissionDiscountAmount;

/// 订单抵扣状态: 1待抵扣 2已抵扣 0默认值
@property (nonatomic, strong, nullable) NSNumber <Optional> *orderDiscount;

/// 订单减扣金额. 仅在订单详情接口(/orders/{id})返回该字段
@property (nonatomic, strong, nullable) NSNumber <Optional> *orderDiscountAmount;

@property (nonatomic, strong, nullable) NSNumber <Optional> *liquidation;
@property (nonatomic, copy, nullable) NSString <Optional> *remark;              // NULL 用户取消; 非NULL 系统取消, remark为原因
// 订单相关消息类型。非交易时段订单消息类型：NON_TRADING_HOURS，期权组合拒绝消息类型：OPTION_COMBO_SEQUENCE
@property (nonatomic, copy, nullable) NSString <Optional> *messageType;
// 附加订单
// 主订单
@property (nonatomic, strong, nullable) NSNumber <Optional> *profitTakerOrderId;
@property (nonatomic, strong, nullable) NSNumber <Optional> *profitTakerPrice;
@property (nonatomic, copy, nullable) NSString <Optional> *profitTakerTif;
@property (nonatomic, strong, nullable) NSNumber <Optional> *profitTakerRth;
@property (nonatomic, strong, nullable) NSNumber <Optional> *stopLossOrderId;
@property (nonatomic, strong, nullable) NSNumber <Optional> *stopLossPrice;
@property (nonatomic, copy, nullable) NSString <Optional> *stopLossTif;
@property (nonatomic, strong, nullable) NSNumber <Optional> *stopLossRth;
@property (nonatomic, assign) NSInteger halted;//停牌状态 0: 正常 3: 停牌 4: 退市 7: 新股 8: 变更

// 附加订单
@property (nonatomic, strong, nullable) NSNumber <Optional> *parentId;
@property (nonatomic, copy, nullable) NSString <Optional> *attachType;// 综合账户 LMT、STP、STP_LMT；环球账户：MAIN（主订单） PROFIT（止盈） LOSS（止损）

// 长连接推送
@property (nonatomic, copy, nullable) NSString <Optional> *type; // orderstatus
@property (nonatomic, strong, nullable) NSNumber <Optional> *timestamp; // 系统时间
@property (nonatomic, strong, nullable) NSNumber <Optional> *lastFillPrice; // 最近成交价格
@property (nonatomic, strong, nullable) NSNumber <Optional> *remaining; // 剩余数量
@property (nonatomic, copy, nullable) NSString <Optional> *source; // 下单来源
@property (nonatomic, strong, nullable) NSNumber <Optional> *errorCode;
@property (nonatomic, copy, nullable) NSString <Optional> *errorMsg;
@property (nonatomic, copy, nullable) NSString <Optional> *errorMsgCn;
@property (nonatomic, copy, nullable) NSString <Optional> *errorMsgTw;

@property (nonatomic, assign) BOOL modifyEnable;
@property (nonatomic, assign) BOOL cancelEnable;
/// 免佣卡状态： 1：待免佣；2：已免佣；0：默认值；11已申请免佣
@property (nonatomic, strong) NSNumber *commissionRebate;

/**
 附加订单名称.
 包括: 止盈单, 止损单, 括号止盈单, 括号止损单.
 由同组的附加订单情况决定, 在拿到全部订单数据时处理一次并赋值, cell展示时使用
 */
@property (nonatomic, copy) NSString *attachOrderName;

@property (nonatomic, assign) NSInteger bracketOrderId; // 另一半括号订单id

@property (nonatomic, assign) BOOL isBracket; // 是否为括号订单

@property (nonatomic, copy) NSString *statusDesc;
//内部转账用到
@property (nonatomic, copy) NSString <Optional>*fromSegment;
@property (nonatomic, copy) NSString <Optional>*toSegment;
@property (nonatomic, strong) NSNumber <Optional>*amount;
@property (nonatomic, copy) NSString *tradeCurrency;  //!< 当前股票的真实计价单位

@property (nonatomic,  assign) NSInteger exchangeOrderType;

@property (nonatomic, strong) TBOminibusAPIOrderModifyParamsInfoModel *modifyParameter;///< 改单信息
@property (nonatomic, strong) TBIBAPIOrderModifyParamsInfoModel *modifyDetail;///< 环球账户改单信息

/** 基金闲钱中
 *  AUTO_SWEEP 自动申赎，REGULAR_SAVINGS_PLAN 定投
 */
@property (nonatomic, copy) NSArray *attrList;///< 数组中有 GREY_MARKET 表示 暗盘订单， ATTACH_ORDER 表示是附加订单
@property (nonatomic, copy) NSString *paymentInfo; ///基金支付信息，目前为：银行名称（卡号后四位）
@property (nonatomic, copy) NSArray *marketingAttrs; /// <<< 活动侧赋予的订单属性，如:LIFETIME_FREE 使用场景类似attrList
@property (nonatomic, copy) NSArray<TBPlaceOrderConditionItem *><TBPlaceOrderConditionItem> * conditions;///< 条件订单对应的条件

@property (nonatomic, copy) NSString *triggerStatus;///< 条件订单 条件状态 [NEW, TRIGGERED]

/// 主要针对港股：是否为lv0（延迟）行情
@property (nonatomic, assign) BOOL isLevel0Price;

@property (nonatomic, assign) NSTimeInterval serverTimestamp;///< 时间戳，综合账号使用 毫秒

@property (nonatomic, assign) BOOL displayAttachOrderRelation;///< 如果是附加订单的话，为 YES  表示展示 父子关系 线，NO 则不展示

@property (nonatomic, assign) BOOL isBSOrder;           ///< 是否是综合账户订单
@property (nonatomic, assign) BOOL isTigerVaultOrder;   ///< 是否是基金-闲钱3.0(TigerVault)订单默认:NO

@property (nonatomic, assign, readonly) BOOL isPartialTransactionOrder; ///< 是否部分成交

/// 开仓订单的已实现盈亏
@property (nonatomic, strong, nullable) NSNumber <Optional> *openRealizedPnl;

/// 开仓订单的未实现盈亏
@property (nonatomic, strong, nullable) NSNumber <Optional> *openUnrealizedPnl;

// 盈亏比例
@property (nonatomic, strong, nullable) TBOrderPnlRespModel *orderPnlResp;

/// 收费明细
@property (nonatomic, copy) NSArray<TBOrderFeeCategoryModel> *charges;

@property (nonatomic, strong, nullable) TBOrderReabtesModel *rebates;

// 括号订单
@property (nonatomic, strong, nullable) NSNumber <Optional> *ocaGroupId;

@property (nonatomic, assign) BOOL displayOCAAttachOrderRelation;/// 如果是OCA订单，YES 展示父子关系竖线，NO 不展示


@property (nonatomic, assign) BOOL fromPushToShowToast;

@property (nonatomic, strong) NSNumber *refundCashAmount;///< 退回金额

@property (nonatomic, copy) NSString *optionTips;           // 期权提示

@property (nonatomic, copy) NSString *groupType;            ///< AUTO_FOREX:自动换汇

@property (nonatomic, assign) BOOL hasChildrenOrder;///< 同列表中是否有子订单
@property (nonatomic, assign) BOOL hasParentOrder;///< 同列表中是否有子订单
@property (nonatomic, assign) BOOL childIndex;///< 第几个子订单

@property (nonatomic, assign) BOOL isOpen;

@property (nonatomic, copy, nullable) NSArray<TBOmnibuAPIOrderLegInfoModel> *legs;///< 组合期权腿信息

@property (nonatomic, copy) NSString *contractMajorDescription;  //fcn 合约主描述信息

@property (nonatomic, copy) NSString *contractExtraDescription;  //fcn 合约补充描述信息

@property (nonatomic, strong) TBFCNOrderModel *fcnResp;

@property (nonatomic, strong) TBBondExtraInfoModel *bondResp;   //国债额外补充信息

#pragma mark - 基金订单信息

/// 未成交时返回预估结算时间，成交后返回结算时间
@property (nonatomic, strong) NSNumber *settlementTime;

- (void)updateOrderLatestPriceIfNeeded:(NSNumber *)quoteLatestPrice;

/// 拒单类型，是否是 TUP 期权等级导致
- (BOOL)isTradeUPOptionPermissionRejectWithType;

- (BOOL)tb_isMonetaryOrder;///< 是否为按金额下单形成的订单

- (BOOL)isFractionalOrder; ///< 是否为碎股订单

- (NSString *)orderStatusString;

- (NSString *)tradingSessionTypeString;

- (NSString *)composedOrderType;

- (NSNumber *)realizedPnlBaseOnCurrentCostType;

- (BOOL)canShowShareAction; ///< 是否显示分享入口

- (BOOL)isAutoForexOrder;   ///< 是否是自动换汇订单

- (BOOL)isStockRspOrder;    ///< 是否是股票定投订单

- (BOOL)isStockRspOrderAndBankCardPayment;  ///< 是否是股票定投订单且使用银行卡支付

- (BOOL)isStockRspOrderAndPrimePayment;     ///< 是否是股票定投订单且使用综合账户支付

- (BOOL)bankCardPayment; ///< 是否是银行卡支付

- (BOOL)canShowSymbolEntrance;///< 订单展开是否显示 详情，907 调整 MLEG 也支持详情

/**
 * 是否是待成交订单
 */
- (BOOL)isPendingOrder;

/**
 * 是否是取消、撤单
 */
- (BOOL)isInactiveOrder;
/**
 * 是否是已完成订单
 */
- (BOOL)isFilledOrder;

/**
 * 订单是否使用优惠券
 */
- (BOOL)hasCoupon;

- (NSString *)mlegsCombinedSymbol;

/**
 * 是否是cdp订单
 */
- (BOOL)isCDPOrder;

/**
 * 是否是buy in订单
 */
- (BOOL)isBuyInOrder;

// 终态订单，订单已经不会产生变化。包括 Filled, Canceled, Rejected, Expired 四种状态。
- (BOOL)isFinalState;

// 用于社区跳转的组合期权策略代码
@property (nonatomic, copy, readonly) NSString *communityMlegSymbol;

@end

NS_ASSUME_NONNULL_END
