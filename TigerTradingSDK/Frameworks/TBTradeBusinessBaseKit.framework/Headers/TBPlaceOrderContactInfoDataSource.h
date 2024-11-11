//
//  TBPlaceOrderContactInfoDataSource.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/7/19.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBPlaceOrderContractInfoConstants.h"

@class TBOmnibusAdvancedOrderModel;
@class TBTradeAPIPlaceOrderModel;

@protocol TBStockDetailInfoDataSource;
@protocol TBOmnibusAdvancedOrderModel;

NS_ASSUME_NONNULL_BEGIN

/// 个股保证金合约信息/订单信息
@protocol TBPlaceOrderContactInfoDataSource <NSObject>

@property (nonatomic, strong, readonly) NSNumber *contractContractId;

/// 订单Id:只有ib有，omni 不需要
@property (nonatomic, strong, readonly) NSNumber *contractOrderId;

/// 账户是否有预览订单的权限
@property (nonatomic, strong, readonly) NSNumber *contractPreview;


/// 获取精度
/// @param price price
/// @param minTick minTick
/// @param secInfo secInfo
/// @param ranges 回调当前精度区间（针对区间精度）
- (NSNumber *)contractMinTick:(NSNumber *)price minTick:(nullable NSNumber *)minTick secInfo:(id<TBStockDetailInfoDataSource>)secInfo ranges:( NSArray * _Nullable *_Nullable)ranges;
- (NSNumber *)contractMinTick:(NSNumber *)price minTick:(nullable NSNumber *)minTick secInfo:(id<TBStockDetailInfoDataSource>)secInfo;

/// 订单类型,可能的值有 MKT(市价单), LMT(限价单), STP(止损单), STP_LMT(止损限价单)
@property (nonatomic, copy, readonly) NSArray *contractAvailableOrderTypes;

- (NSArray *)contractAvailableOrderTypes:(nullable TBTradeAPIPlaceOrderModel *)placeOrderModel;

/// Lite 版本下单页支持的订单类型（721 期权 支持 LMT、MKT、STP_LMT）
@property (nonatomic, copy, readonly) NSArray *contractAvailableLiteOrderTypes;

/// 支持的订单时效 eg. ["DAY","GTC"]
@property (nonatomic, copy, readonly) NSArray *contractAvailableTimeInForce;

/// 每手股数，可能为nil
@property (nonatomic, strong, readonly) NSNumber *contractLotSize;

/// 股数小数量值，eg: contractLotSize / pow(10, contractLotSizeScale)
@property (nonatomic, strong, readonly) NSNumber *contractLotSizeScale;
/// 每手股数
/// @param secInfo 标的信息
- (NSNumber *)contractLotSizeWithSecInfo:(id<TBStockDetailInfoDataSource>)secInfo;

/// 展示的数量最小变化单位(美股正股 限价单、市价单 支持碎股交易)，用于展示 和 下单时的校验
/// @param secInfo 标的信息
/// @param orderType orderType 订单类型（美股碎股 限价单、市价单 支持小数输入，其他订单类型不支持）
- (NSNumber *)contractDisplayLotSizeWithSecInfo:(id<TBStockDetailInfoDataSource>)secInfo orderType:(NSString *)orderType;

/// // 剩余日内交易次数
/// @param market market
- (NSNumber *)dayTradeRemaing:(NSString *)market;

/// 合约是否可做空
@property (nonatomic, assign, readonly) BOOL contractShortAble;

@property (nonatomic, assign, readonly) BOOL contractSupportFractionalShare;

@property (nonatomic, assign, readonly) BOOL contractSupportDigitalCurrency;

@property (nonatomic, assign, readonly) BOOL contractIsBtcEtf;

#pragma mark ---<保证金信息>

/// 做空费率
@property (nonatomic, strong, readonly) NSNumber *contractShortRate;
/// 做空初始保证金
@property (nonatomic, strong, readonly) NSNumber *contractShortInitalMargin;
/// 做空维持保证金
@property (nonatomic, strong, readonly) NSNumber *contractShortMaintenanceMargin;

/// 可做空数目
@property (nonatomic, strong, readonly) NSNumber *contractShortCount;

/// 做多初始保证金
@property (nonatomic, strong, readonly) NSNumber *contractLongInitalMargin;

/// 做多维持保证金
@property (nonatomic, strong, readonly) NSNumber *contractLongMaintenancMargin;

@property (nonatomic, strong, readonly) NSNumber *contractMultiplier;

@property (nonatomic, strong, readonly) NSNumber *contractFaceValue;

@property (nonatomic, strong, readonly) NSNumber *contractInterestPerFaceValue;

#pragma  mark --<期货需要的一些合约信息>--
/**
 日内优惠开始时间
 */
@property (nonatomic, copy, readonly) NSString *futDiscountedStartAt;

/**
 日内优惠结束时间
 */
@property (nonatomic, copy, readonly) NSString *futDiscountedEndAt;

/**
 日内优惠初始保证金比例
 */
@property (nonatomic, strong, readonly) NSNumber *futDiscountedDayInitialMargin;

/**
 日内优惠维持保证金比例
 */
@property (nonatomic, strong, readonly) NSNumber *futDiscountedDayMaintenanceMargin;

/**
 时区
 */
@property (nonatomic, copy, readonly) NSString *futDiscountedTimeZoneCode;

/**
 时区名称
 */
@property (nonatomic, copy, readonly) NSString *futDiscountedTimeZoneName;

@property (nonatomic, copy, readonly) NSString *belongsToMarket; ///< 标的所属市场，包括期货、期权、数字货币

@property (nonatomic, assign) BOOL greyMarketSupported;///< 是否支持暗盘交易

@property (nonatomic, assign) NSTimeInterval serverTimestamp;///< 单位：毫秒 服务端时间戳

@property (nonatomic, copy) TBOmnibusFractionShareTradeMode oddTradeMode;///< 碎股回收模式

@property (nonatomic, strong) TBOmnibusAdvancedOrderModel *advancedOrderTypeSupports;///< 高级订单类型

@property (nonatomic, assign) BOOL hardToBorrow;///< 求用户卖空的股票为HTB（Hard to Borrow）时，需要用户同意才可下单, TradeUP Marsco 用户

@property (nonatomic, assign, readonly) BOOL contractMonetaryOrderSupported; ///< 是否支持按金额下单，只有支持碎股下单的前提下，该判断才有效

@property (nonatomic, assign, readonly) BOOL contractIsOvernightTradingSupported; /// 917 标的是否支持夜盘交易

@optional
/// 交易币种，数字货币交易时currency目前无法从行情里获取，只能从合约接口获取。
@property (nonatomic, copy) NSString *currency;

/// 代表了当前合约所属的交易所
@property (nonatomic, copy, readonly) TBOmnibusContractExchange exchange;

/// 是否可交易
@property (nonatomic, assign, readonly) BOOL tradeable;

@property (nonatomic, copy, readonly) NSString *contractMajorDescription;

@property (nonatomic, copy, readonly) NSString *contractExtraDescription;

/// 913 是否能抵消交易
@property (nonatomic, assign, readonly) BOOL contractCanContraTrading;

/// 标的是否支持cdp sell
@property (nonatomic, assign, readonly) BOOL contractCanCDPTrading;

/// 913 contra账户是否可交易
@property (nonatomic, assign, readonly) BOOL contractContraTradeable;

/// 915 合约属性枚举（当前数字货币使用）
@property (nonatomic, copy) NSArray <NSString *> *contractAttrs;

@end

NS_ASSUME_NONNULL_END
