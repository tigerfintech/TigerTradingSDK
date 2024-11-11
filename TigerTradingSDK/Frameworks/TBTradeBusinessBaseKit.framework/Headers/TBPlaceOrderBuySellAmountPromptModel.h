//
//  TBPlaceOrderBuySellAmountPromptModel.h
//  Stock
//
//  Created by 王昌阳 on 2020/9/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderBuySellAmountPromptModel : NSObject

@property (nonatomic, strong) NSNumber *realTradeQty;       ///< 现金可买
@property (nonatomic, strong) NSNumber *realFinancingQty;   ///< 融资可买/融券可卖
@property (nonatomic, strong) NSNumber *realPositionQty;    ///< 持仓数量

@property (nonatomic, strong) NSNumber *buyOnCashAmountByCurrency;

@property (nonatomic, strong) NSNumber *tradeQty;         ///< 现金可买
@property (nonatomic, strong) NSNumber *tradeQtyScale;    ///< 现金可买
@property (nonatomic, strong) NSNumber *financingQty;     ///< 融资可买/融券可卖
@property (nonatomic, strong) NSNumber *financingQtyScale;///< 融资可买/融券可卖
@property (nonatomic, strong) NSNumber *positionQty;      ///< 持仓数量
@property (nonatomic, strong) NSNumber *positionQtyScale; ///< 持仓数量
@property (nonatomic, strong) NSNumber *avgCost;          ///< 持仓均价
@property (nonatomic, strong) NSNumber *tradableQty;      ///< 持仓可平

/// 按金额下单-相关数据（持仓可卖字段不变）
@property (nonatomic, strong) NSNumber *tradeCashAmount;///< 现金可买
@property (nonatomic, strong) NSNumber *financingCashAmount;///< 融资可买/融券可卖

@property (nonatomic, strong) NSNumber *price;

@property (nonatomic, strong) NSNumber *availableCash;
@property (nonatomic, copy) NSArray <NSDictionary *> *assetsByCurrency;

/// 913 抵消交易数量 （contra账户额度交易使用）
@property (nonatomic, strong) NSNumber *contraTradingQty;
/// 913 抵消交易金额（contra账户额度交易金额单使用）
@property (nonatomic, strong) NSNumber *contraTradingAmount;
/// 913 购买力 （contra账户使用）
@property (nonatomic, strong) NSNumber *availableBuyingPower;
/// 920 已抵消数量 （contra账户使用）
@property (nonatomic, strong) NSNumber *settledQty;
/// 920 未抵消买入数量 （contra账户使用）
@property (nonatomic, strong) NSNumber *outstandingBuyQty;
/// 920 未抵消卖出数量 （contra账户使用）
@property (nonatomic, strong) NSNumber *outstandingSellQty;

/// 920 可用sell limit, 单位为合约对应币种 (sell from CDP使用)
@property (nonatomic, strong) NSNumber *availableSellLimit;
/// 920 挂单数量 (sell from CDP使用)
@property (nonatomic, strong) NSNumber *pendingSellQty;
/// 920 未结算数量 (sell from CDP使用)
@property (nonatomic, strong) NSNumber *unsettledSellQty;

@end

NS_ASSUME_NONNULL_END
