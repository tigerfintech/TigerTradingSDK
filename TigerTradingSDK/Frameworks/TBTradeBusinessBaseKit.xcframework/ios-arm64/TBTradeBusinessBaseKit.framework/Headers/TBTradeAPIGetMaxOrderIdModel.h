//
//  TBTradeAPIGetMaxOrderIdModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/25.
//

#import "TBTradeAPIModel.h"
#import "TBMinTickModel.h"
#import "TBPlaceOrderContactInfoDataSource.h"
#import "TBPlaceOrderContractInfoConstants.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark 1 获取新订单的单号
@interface TBTradeAPIGetMaxOrderIdModel : TBTradeAPIModel

@property (nonatomic, assign) NSInteger orderId;                                // 订单Id
@property (nonatomic, strong, nullable) NSNumber <Optional> *preview;           // 该账户是否有预览订单的权限
@property (nonatomic, strong, nullable) NSNumber <Optional> *dayTradesRemaining;// 剩余日内交易次数
@property (nonatomic, copy, nullable) NSArray  <Optional,TBMinTickModel> *minTicks;           // minTicks字段表示不同价格区间的最小报价单位
// symbol非空时有值
@property (nonatomic, strong, nullable) NSNumber <Optional> *minTick;           // 港股或美股正股最小报价单位
@property (nonatomic, strong, nullable) NSNumber <Optional> *quantityUnit;      // 港股正股最小数量单位
@property (nonatomic, strong, nullable) NSNumber <Optional> *rebateRate;        // 做空费率1, 0.66 表示 0.66%
@property (nonatomic, strong, nullable) NSNumber <Optional> *feeRate;           // 做空费率2, 0.25 表示 0.25%
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortable;         // 可做空数目, 1.0E7 表示 >= 1.0E7
@property (nonatomic, strong, nullable) NSNumber <Optional> *longInitialMargin; // 做多初始保证金
@property (nonatomic, strong, nullable) NSNumber <Optional> *longMaintenanceMargin;// 做多维持保证金
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortMargin;       // 做空保证金
@property (nonatomic, copy, nullable) NSArray <Optional> *availableOrderTypes;    // 定单类型,可能的值有 MKT(市价单), LMT(限价单), STP(止损单), STP_LMT(止损限价单)

@property (nonatomic, strong, nullable) NSNumber<Optional> *lotSize;    // 一手股数

/// 支持的订单时效 eg. ["DAY","GTC"]
@property (nonatomic, copy, nullable) NSArray <Optional> *availableTimeInForce;

@property (nonatomic, assign, getter=isSupportFractionalShare) BOOL supportFractionalShare;                  // 美股是否支持碎股交易

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

@property (nonatomic, assign) BOOL greyMarketSupported;///< 是否支持暗盘交易 综合账号使用

@property (nonatomic, assign) NSTimeInterval serverTimestamp;///< 综合账号使用时间戳，环球默认为 0

@property (nonatomic, strong) id<TBPlaceOrderContactInfoDataSource> contractInfo;///< 闪电下单页有用到

@property (nonatomic, copy) TBOmnibusFractionShareTradeMode oddTradeMode;///< 综合账号碎股回收模式，环球账号返回nil
@property (nonatomic, strong) TBOmnibusAdvancedOrderModel *advancedOrderTypeSupports;///< 高级订单类型
@property (nonatomic, assign) BOOL hardToBorrow;///< 求用户卖空的股票为HTB（Hard to Borrow）时，需要用户同意才可下单

/// 915 合约属性枚举（当前数字货币使用）
@property (nonatomic, copy) NSArray <NSString *> *attrs;

@end

NS_ASSUME_NONNULL_END
