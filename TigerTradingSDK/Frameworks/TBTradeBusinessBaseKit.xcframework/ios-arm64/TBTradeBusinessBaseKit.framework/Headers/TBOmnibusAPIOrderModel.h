//
//  TBOmnibusAPIOrderModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import "TBOmnibusAPIModel.h"
#import <TBTradeBusinessBaseKit/TBOminibusAPIOrderModifyParamsInfoModel.h>
#import "TBOrderFeeCategoryModel.h"
#import "TBOmnibuAPIOrderLegInfoModel.h"

@class TBFCNOrderModel;
@class TBBondExtraInfoModel;

NS_ASSUME_NONNULL_BEGIN

#pragma mark 订单Order

// 订单状态status说明
// PendingNew   订单请求已收到, 但尚未被接收
// New          订单已经提交
// Filled       完全成交
// Canceled     已取消
// Rejected     已拒绝
// Expired      已过期

// 订单类型说明
// MKT 市价单
// LMT 限价单

@protocol TBOmnibusAPIOrderModel, TBOmnibuAPIOrderLegInfoModel;
@class TBOrderParams;
@class TBOrderPnlRespModel;

/// Omnibus 订单
///
/// https://git.tigerbrokers.net/alpha/site-api-docs/blob/master/api/data.md#-%E8%AE%A2%E5%8D%95order
@interface TBOmnibusAPIOrderModel : JSONModel

/// 订单唯一编号,全局唯一
@property (nonatomic, assign) long long orderId;

/// id的字符串表示. id的范围会超出javascript数字number类型的精度,使用此属性可以获得准确的id值
@property (nonatomic, copy, nullable) NSString <Ignore> *idStr;

/// 交易品种
@property (nonatomic, copy) NSString *secType;

/// 交易品种子类型，如票据下面的 FCN、ELN
@property (nonatomic, copy) NSString *secSubType;

@property (nonatomic, copy) NSString *secGroupType;

@property (nonatomic, strong) NSNumber *portfolioId;

/// 标的代码，如 NTES、BIDU
@property (nonatomic, copy) NSString *symbol;

/// 底层股票代码 港股期权对应的正股代码 用于社区港股期权跳转正股
@property (nonatomic, copy) NSString *underlyingSymbol;

/// 期权独有: 过期时间
@property (nonatomic, copy) NSString <Optional> *expiry;

/// 期权独有: 多空方向 CALL/PUT
@property (nonatomic, copy) NSString <Optional> *strike;

/// 期权独有: 行权价
@property (nonatomic, copy) NSString <Optional> *right;

/// 币种
@property (nonatomic, copy) NSString *currency;

/// 市场
@property (nonatomic, copy) NSString *market;

/// 股票中文名称
@property (nonatomic, copy) NSString *nameCN;

/// 买/卖，值只能为 BUY/SELL
@property (nonatomic, copy) NSString *action;

/// 订单时效[DAY,GTC]
@property (nonatomic, copy) NSString *timeInForce;

/// 订单成交时间
@property (nonatomic, copy) NSString *tradingSessionType; //OVERNIGHT PRE_RTH_POST

/// 订单类型
@property (nonatomic, copy) NSString *orderType;

/// 跟踪止损单类型
@property (nonatomic, copy) NSString *trailType;  //7.1.7 版本 综合账户新增跟踪止损单类型 PERCENT:百分比 AMOUNT:差额

/// 跟踪止损单类型-追踪条件数值 百分比/价差
@property (nonatomic, strong) NSNumber *trailAmount;  //7.1.7 版本 追踪止损条件数值，当 trail_type 为 PERCENT 时，比如设置 25.15%，那么 trail_amount 应该为 25.15

@property (nonatomic, strong, nullable) TBOrderParams *params;             //订单额外参数，算法单TWAP和VWAP时存在

/// 下单数量
@property (nonatomic, strong) NSNumber *totalQuantity; // int

@property (nonatomic, strong) NSNumber *totalQuantityScale;  // 总数(改单参数)
@property (nonatomic, strong) NSNumber *realTotalQuantity; // int (???)

@property (nonatomic, strong) NSNumber *totalCashAmount;  // 下单总金额(基金、按金额下单)

/// 成交数量
@property (nonatomic, strong) NSNumber *filledQuantity; // int
@property (nonatomic, strong) NSNumber *filledQuantityScale; // 执行数目 (???)

@property (nonatomic, strong, readonly) NSNumber *realFilledQuantity; // filledQuantity / pow(10,filledQuantityScale)

@property (nonatomic, strong) NSNumber *filledCashAmount;  // 已成交总金额(基金、按金额下单)

/// 成交均价
@property (nonatomic, strong) NSNumber *avgFillPrice;

/// 仅盘中
@property (nonatomic, assign) BOOL onlyRth;

/// 1：待免佣；2：已免佣；0：默认值
@property (nonatomic, assign) NSInteger discount;

/// 免佣金额. 仅在订单详情接口(/orders/{id})返回该字段
@property (nonatomic, strong, nullable) NSNumber <Optional> *commissionDiscountAmount;

/// 订单抵扣状态: 1待抵扣 2已抵扣 0默认值
@property (nonatomic, assign) NSInteger orderDiscount;

/// 订单减扣金额. 仅在订单详情接口(/orders/{id})返回该字段
@property (nonatomic, strong, nullable) NSNumber <Optional> *orderDiscountAmount;

/// 订单状态
@property (nonatomic, copy) NSString *status;

/// 订单状态，中文描述
@property (nonatomic, copy) NSString *statusDesc;


/// 订单相关消息类型。非交易时段订单消息类型：NON_TRADING_HOURS，期权组合拒绝消息类型：OPTION_COMBO_SEQUENCE
@property (nonatomic, copy) NSString *messageType;



/// 限价, 当order_type为LMT、STP_LMT时一定存在，为VWAP、TWAP时可能存在
@property (nonatomic, strong, nullable) NSNumber <Optional> *price;

/// 止损价, 当order_type为STP、STP_LMT时一定存在
@property (nonatomic, strong, nullable) NSNumber <Optional> *stopPrice;

/// 现价,仅在订单状态为New和PendingNew(待成交类别订单)时有此属性
@property (nonatomic, strong, nullable) NSNumber <Optional> *latestPrice;

/// 主要针对港股：是否为lv0（延迟）行情 仅在订单状态为New和PendingNew(待成交类别订单)时有此属性
@property (nonatomic, assign) BOOL isLevel0Price;

/// 是否是平仓订单
@property (nonatomic, assign) BOOL liquidation;

/// 佣金
@property (nonatomic, strong) NSNumber *commission;

/// 对手经纪
@property (nonatomic, copy, nullable) NSString *counterpartyBroker;

/// 佣金费用总计
@property (nonatomic, strong) NSNumber *commissionAndFee;

/// 813 前端申购销售费用
@property (nonatomic, strong) NSNumber *upfrontFee;

/// 订单相关备注
@property (nonatomic, copy, nullable) NSString <Optional> *message;

@property (nonatomic, copy, nullable) NSArray <Optional> *attrList;///< 数组中有 GREY_MARKET 表示 暗盘订单，有 ODD_LOT 表示碎股订单，有 ATTACH_ORDER 表示是附加订单

@property (nonatomic, copy) NSArray *marketingAttrs; /// <<< 活动侧赋予的订单属性，如:LIFETIME_FREE 使用场景类似attrList

/// 特殊订单描述(返回客户端语言对应的描述)
@property (nonatomic, copy, nullable) NSString <Optional> *attrDesc;

/// 订单状态更新时间
@property (nonatomic, strong, nullable) NSNumber <Optional> *statusUpdatedAt;

/// 订单创建时间
@property (nonatomic, assign) NSTimeInterval createdAt;

/// 订单最近修改时间
@property (nonatomic, assign) NSTimeInterval updatedAt;

/// 订单成交时间
@property (nonatomic, assign) NSTimeInterval filledAt;

/// 订单成交价格
@property (nonatomic, strong) NSNumber *filledPrice;

/// 是否可修改订单
@property (nonatomic, assign) BOOL canModify;

/// 是否可撤销订单
@property (nonatomic, assign) BOOL canCancel;

/// 订单额外参数
//@property (nonatomic, strong, nullable) OrderParams <Optional> *params;
// https://git.tigerbrokers.net/alpha/site-api-docs/blob/master/api/data.md#-%E8%AE%A2%E5%8D%95%E9%A2%9D%E5%A4%96%E5%8F%82%E6%95%B0

// Omnibus 客户端推送的订单数据结构特有的属性
// https://git.tigerbrokers.net/alpha/site-api-docs/blob/master/api/push.md#-2-%E8%AE%A2%E5%8D%95

/// 用户ID
@property (nonatomic, strong, nullable) NSNumber <Optional> *userId;

/// 账户ID
@property (nonatomic, strong, nullable) NSNumber <Optional> *accountId;

/// 账户Segment类型, SEC/FUT
@property (nonatomic, copy, nullable) NSString <Optional> *segType;

/// 消息码
@property (nonatomic, copy, nullable) NSString <Optional> *messageCode;

/// 改单状态 (NONE, RECEIVED, REPLACED, FAILED)
@property (nonatomic, copy, nullable) NSString <Optional> *replaceStatus;

/// 撤单状态 (NONE, RECEIVED, FAILED)
@property (nonatomic, copy, nullable) NSString <Optional> *cancelStatus;

/// 订单来源平台
@property (nonatomic, copy, nullable) NSString <Optional> *source;

@property (nonatomic, strong, nullable) TBOminibusAPIOrderModifyParamsInfoModel *modifyParameter;///< 综合账户改单信息

@property (nonatomic, copy) NSArray<TBPlaceOrderConditionItem *><TBPlaceOrderConditionItem> * conditions;///< 条件订单对应的条件

@property (nonatomic, copy) NSString *triggerStatus;///< 条件订单 条件状态 [NEW, TRIGGERED]

@property (nonatomic, assign) NSTimeInterval serverTimestamp;///< 时间戳 毫秒


@property (nonatomic, strong) NSNumber *parentOrderId;///< 如果是附加订单的话，该字段有值 表示该订单为 附加订单的子订单，如果没有值表示为改订单为附加订单的主订单

@property (nonatomic, strong, nullable) NSNumber <Optional> *ocaGroupId; ///< 如果是括号订单的话，改字段有值。括号订单里的两个订单的ocaGroupId相同

/// 订单以实现盈亏（平仓定单）
@property (nonatomic, strong) NSNumber *realizedPnl;
@property (nonatomic, strong, nullable) NSNumber <Optional> *realizedPnlByAverage;///< 订单的平均成本已实现盈亏
/// 开仓订单的以实现盈亏
@property (nonatomic, strong) NSNumber *openRealizedPnl;

/// 开仓订单的未实现盈亏
@property (nonatomic, strong) NSNumber *openUnrealizedPnl;

// 盈亏比例
@property (nonatomic, strong) TBOrderPnlRespModel *orderPnlResp;

/// 免佣卡状态： 1：待免佣；2：已免佣；0：默认值；11已申请免佣
@property (nonatomic, strong) NSNumber *commissionRebate;

/// 收费明细
@property (nonatomic, copy) NSArray<TBOrderFeeCategoryModel> *charges;

@property (nonatomic, strong, nullable) TBOrderReabtesModel *rebates;

@property (nonatomic, strong) NSNumber *refundCashAmount;///< 退回金额

@property (nonatomic, assign) BOOL isOpen;

@property (nonatomic, copy) NSString *groupType;            ///< AUTO_FOREX:自动换汇

@property (nonatomic, copy, nullable) NSArray<TBOmnibuAPIOrderLegInfoModel> *legs;///< 组合期权腿信息
@property (nonatomic, copy, nullable) NSString *comboType;///< 组合期权策略 key
@property (nonatomic, copy, nullable) NSString *comboTypeName;///< 组合期权策略 名称

#pragma mark - fcn 订单信息
@property (nonatomic, copy) NSString *contractMajorDescription;  //fcn 合约主描述信息

@property (nonatomic, copy) NSString *contractExtraDescription;  //fcn 合约补充描述信息

@property (nonatomic, strong) TBFCNOrderModel *fcnResp;

@property (nonatomic, strong) TBBondExtraInfoModel *bondResp;   //国债额外补充信息

#pragma mark - 基金订单信息

/// 未成交时返回预估结算时间，成交后返回结算时间
@property (nonatomic, strong) NSNumber *settlementTime;

/// 前端申购销售费用
@property (nonatomic, strong) NSNumber *reqCashAmount;

/// gst消费税
@property (nonatomic, strong) NSNumber *gst;

@end


// 下单, 单个订单, 取消订单, 修改订单
@interface TBOmnibusAPIOrderDataModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusAPIOrderModel *data;

@end

@interface TBOmnibusAPIMultiOrdersDataModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusAPIOrderModel> *data;

@end


// 订单列表
@interface TBOmnibusAPIOrdersModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusAPIOrderModel> *data;

@end

NS_ASSUME_NONNULL_END
