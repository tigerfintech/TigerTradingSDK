//
//  TBOmnibusOrderMarginModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import "TBOmnibusAPIModel.h"
#import "TBPlaceOrderContractInfoConstants.h"
#import "TBMinTickModel.h"

@class TBOmnibusAdvancedOrderModel;
@class TBOmnibusOrderTradingRestrictionModel;
@class TBOmnibusContractBondInfo;

@protocol TBComboPositionModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusOrderMarginItemModel : TBOmnibusAPIModel

@property (nonatomic, assign) long long stockID;                // 订单唯一编号, 全局唯一
@property (nonatomic, assign) long long underlyingContractId;   // 底层合约ID(期权对应的正股ID)

@property (nonatomic, assign) long long contractId;

@property (nonatomic, copy) NSString *symbol;                   // 股票代码
@property (nonatomic, copy) NSString *expiry;                   // 到期日期 yyyyMMdd
@property (nonatomic, copy) NSString *strike;                   // 行权价
@property (nonatomic, copy) NSString *currency;                 // 币种, 如USD\HKD
@property (nonatomic, copy) NSString *right;                    // C/P call/put

@property (nonatomic, copy) NSString *name;                     // 股票名称
@property (nonatomic, copy) NSString *market;                   // 股票市场
@property (nonatomic, copy) NSString *majorDescription;         // 合约名称（如：美国短期国债）
@property (nonatomic, copy) NSString *extraDescription;         // 合约扩展名称（如：债券票面利率+到期日）
@property (nonatomic, copy, nullable) NSString <Optional> *secType; // 标的类型
@property (nonatomic, assign) BOOL marginable;                  // 是否可融资
@property (nonatomic, assign) BOOL tradeable;                   // 是否可交易
@property (nonatomic, assign) BOOL closeOnly; // 是否无法开仓

@property (nonatomic, assign, getter=isSupportFractionalShare) BOOL supportFractionalShare;                  // 美股是否支持碎股交易
@property (nonatomic, assign, getter=isMonetaryOrderSupported) BOOL monetaryOrderSupported;                  // 美股是否支持碎股交易
@property (nonatomic, assign, getter=isSupportRegularSavings)  BOOL supportRegularSavings;                   // 美股是否支持股票定投

@property (nonatomic, strong) NSNumber *longInitialMargin;      // 做多初始保证金比例(百分比)
@property (nonatomic, strong) NSNumber *longMaintenanceMargin;  // 做多维持保证金比例(百分比)
@property (nonatomic, strong) NSNumber *multiplier;             // 乘数

// Omnibus新做空添加字段
@property (nonatomic, strong, nullable) NSNumber <Optional> *canShort;             // 能否做空boolean
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortableCount;       // 做空池大小
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortFeeRate;         // 做空利率, 单位%. 假如此值为2.3, 意味年化做空利率为2.3%
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortInitialMargin;   // 做空初始保证金比例
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortMaintenanceMargin; // 做空维持保证金比例
@property (nonatomic, copy, nullable) NSArray <Optional> *availableOrderTypes;    // 定单类型,可能的值有 MKT(市价单), LMT(限价单), STP(止损单), STP_LMT(止损限价单)
@property (nonatomic, copy, nullable) NSArray <Optional> *categories;
@property (nonatomic, strong, nullable) NSNumber *lotSize;    // 一手股数
@property (nonatomic, strong, nullable) NSNumber *lotSizeScale;
@property (nonatomic, strong, nullable) NSNumber *realLotSize;    // 一手股数

@property (nonatomic, copy, nullable) NSArray  <Optional,TBMinTickModel> *tickSizes;           // minTicks字段表示不同价格区间的最小报价单位

/// 支持的订单时效 eg. ["DAY","GTC"]
@property (nonatomic, copy, nullable) NSArray <Optional> *availableTimeInForce;

@property (nonatomic, copy, nullable) NSArray <Optional, TBComboPositionModel> *legs;    ///组合合约里的腿信息
// 期货

/**
 日内优惠开始时间
 */
@property (nonatomic, copy) NSString <Optional>*discountedStartAt;

/**
 日内优惠结束时间
 */
@property (nonatomic, copy) NSString <Optional>*discountedEndAt;

/**
 日内优惠初始保证金比例
 */
@property (nonatomic, strong) NSNumber <Optional>*discountedDayInitialMargin;

/**
 日内优惠维持保证金比例
 */
@property (nonatomic, strong) NSNumber <Optional>*discountedDayMaintenanceMargin;

/**
 时区
 */
@property (nonatomic, copy) NSString <Optional>*discountedTimeZoneCode;

/**
 时区名称
 */
@property (nonatomic, copy) NSString <Optional>*discountedTimeZoneName;

@property (nonatomic, assign) BOOL greyMarketSupported;///< 是否支持暗盘交易

@property (nonatomic, assign) BOOL canUsOvernightTrading; /// 917 标的是否支持夜盘交易

@property (nonatomic, assign) BOOL conditionalOrderSupported DEPRECATED_ATTRIBUTE; ///< 是否支持条件订单；已废弃 使用 advancedOrderTypeSupports 进行判断

@property (nonatomic, strong) NSArray *availableConditionalOrderTypes DEPRECATED_ATTRIBUTE; ///< 选中条件订单时，支持的订单类型；已废弃 使用 advancedOrderTypeSupports 进行判断

@property (nonatomic, assign) NSTimeInterval serverTimestamp;///< 时间戳 毫秒

@property (nonatomic, assign) BOOL attachOrderSupported DEPRECATED_ATTRIBUTE;///< 是否支持附加订单；已废弃 使用 advancedOrderTypeSupports 进行判断
@property (nonatomic, strong) NSArray<NSString *> *availableAttachChildOrderTypes DEPRECATED_ATTRIBUTE;///<   附加订单支持的订单类型 LMT", "STP", "STP_LMT；已废弃 使用 advancedOrderTypeSupports 进行判断
@property (nonatomic, copy) TBOmnibusFractionShareTradeMode oddTradeMode;///< 碎股回收模式
@property (nonatomic, strong) TBOmnibusAdvancedOrderModel *advancedOrderTypeSupports;///< 支持的高级订单类型
@property (nonatomic, assign) BOOL hardToBorrow;///< 求用户卖空的股票为HTB（Hard to Borrow）时，需要用户同意才可下单
///</// 代表了当前合约所属的交易所
@property (nonatomic, copy, nullable) TBOmnibusContractExchange exchange;

@property (nonatomic, strong) TBOmnibusOrderTradingRestrictionModel *tradingRestriction; ///< 交易限制

@property (nonatomic, strong) TBOmnibusContractBondInfo *bondResp;                      /// 910新增，存放债券合约的独有字段

/// 913 是否能抵消交易
@property (nonatomic, assign) BOOL canContraTrading;

/// 920 标的是否支持cdp sell
@property (nonatomic, assign) BOOL canCDPTrading;

/// 913 contra账户是否可交易
@property (nonatomic, assign) BOOL contraTradeable;

/// 915 合约属性枚举（当前数字货币使用）
@property (nonatomic, copy) NSArray <NSString *> *attrs;

@end


@interface TBOmnibusOrderMarginModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusOrderMarginItemModel *data;

@end

@interface CommissionRuleModel : TBOmnibusAPIModel

@property (nonatomic, strong) NSArray *commissionGroupAttrs;

@end

@interface TBOmnibusContractBondInfo : JSONModel

@property (nonatomic, strong) NSNumber *faceValue;            /// 债券面值
@property (nonatomic, strong) NSNumber *interestPerFaceValue; /// 1 faceValue 的当前应计利息，(settleDate-上次付息日)*每日应计利息

@end

NS_ASSUME_NONNULL_END
