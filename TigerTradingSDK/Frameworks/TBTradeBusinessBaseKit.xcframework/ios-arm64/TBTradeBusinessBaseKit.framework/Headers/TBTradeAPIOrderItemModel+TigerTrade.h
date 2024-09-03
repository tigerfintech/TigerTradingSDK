//
//  TBTradeAPIOrderItemModel+TigerTrade.h
//  Stock
//
//  Created by 董恭甫 on 2017/12/6.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBTradeAPIOrderModel.h"
#import "TBTradeAPIOrderItemModel+TigerTrade.h"

@class TBFuturesTransferModel;
@class TBFundTradeHistoryV2;

@interface TBTradeAPIOrderItemModel (TigerTrade)

// 交易相关操作时, 用于判断订单是否有附加订单, 是否是一个附加订单
- (BOOL)isAttachedOrder;

//附加订单-主订单
- (BOOL)isAttachedOrderMainOrder;

//附加订单-子订单
- (BOOL)isAttachedOrderSubOrder;
- (BOOL)isGreyOrder;
- (BOOL)isOddOrder;

// 是否终身免佣订单
- (BOOL)isLifetimeCommissionFree;

/// 是否是括号订单
- (BOOL)isOCAOrder;

/// 是否是算法单
- (BOOL)isAlgorithmOrder;

/// 是否是算法单-限价单
- (BOOL)isAlgorithmLimitOrder;

/// 是否是算法单-市价单
- (BOOL)isAlgorithmMarketOrder;

/// 是否是股票&ETF定投订单
- (BOOL)isStockETFRspOrder;

// 长连接无法获取用户语言, 所以需要app端处理多语言
- (NSString *)localizedErrorMessage;

- (BOOL)validStatus;

- (NSString *)commissionCardStatusIconName;

- (NSString *)commissionCardStatus;

/**
 * 根据标的信息生成唯一标识
 * identifier=secType+{a_symbol}
 * secType = OPT, {a_symbol}=originSymbol
 * secType = WAR|IOPT, {a_symbol}=localSymbol
 * secType = MELG, {a_symbol}=symbol+comboType
 * secType = others, {a_symbol}=symbol
 */
- (NSString *)orderIdentifier;

- (NSString *)totalQuantityFormatedString;

@end

// 从omnibus订单对象创建ib订单对象, 当前对订单的做法是统一成ib的订单类型
@class TBOmnibusAPIOrderModel;

@interface TBTradeAPIOrderItemModel (omnibus)

- (instancetype)initWithOmnibusOrder:(TBOmnibusAPIOrderModel *)model;

- (instancetype)initWithFuturesOrder:(TBFuturesTransferModel *)model;

@end

@interface TBTradeAPIOrderItemModel (FundOrder)

- (instancetype)initWithFundOrder:(TBFundTradeHistoryV2 *)model;

/// 是否是基金订单
- (BOOL)isFundOrder;

/// 是否是基金的auto-sweep订单
- (BOOL)isFundAutoSweepOrder;

/// 是否是基金的REGULAR_SAVING_PLAN订单
- (BOOL)isFundRegularSavingPlanOrder;

- (BOOL)isFundCouponOrder;

@end

