//
//  TBOrderUtil.h
//  Stock
//
//  Created by liwt on 15/2/5.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <TBTradeBusinessBaseKit/TBTradeAPIOrderItemModel+TigerTrade.h>
#import <TBTradeBusinessBaseKit/TBPlaceOrderContactInfoDataSource.h>
#import <TBTradeBusinessBaseKit/TBOrderStatusConstants.h>
#import <TBStockKit/TBBaseKLineItem.h>
#import <TBAccountSystemKit/TBUserInfoManager+AccountStatus.h>
#import <TBTradeBusiness/TBOrderUtil.h>
#import <TBStockKit/TBStock.h>
#import <TBToolsKit/TBWatchListDisplayItem.h>

@class TBTradeAPIPreviewOrderModel;
@class TBTradeAPIOrderItemModel;

typedef NS_ENUM(NSUInteger, kTBPlaceOrderTradeTimeAlertPageType) {
    kTBPlaceOrderTradeTimeAlertPageTypePlaceOrderPage = 0,
    kTBPlaceOrderTradeTimeAlertPageTypeOrderListPage,
};

@interface TBOrderUtil : NSObject

+ (NSString *)getStatisticsAccountTypeName;

+ (NSString *)attachOrderPriceDesForAttachOrderType:(NSString *)attachOrderType;
/**
 * @param totalCount 申请总数量 or 订单申请总金额,isMonetary=YES时为订单申请总金额
 * @param filledCount 实际成交数量 or 实际成交金额,isMonetary=YES时为实际成交金额
 * @param orderStatus 订单状态
 * @param isMonetary 是否为金额订单
 */
+ (NSString *)getOrderStatus:(double)totalCount filledCount:(double)filledCount orderStatus:(TBOrderStatus)orderStatus isMonetary:(BOOL)isMonetary;

+ (TBOrderValidDate)getOrderValidDateFromString:(NSString *)timeInForce;

+ (NSString *)getOrderValidDateDesFromType:(TBOrderValidDate)validDate;

+ (NSString *)getOrderActionTypeDes:(NSString *)action;

+ (NSString *)getTradeErrorMsg:(NSInteger)errorCode;

+ (NSString *)orderTypeDescription:(NSString *)orderType;

/**
 * @param orderType 订单类型
 * @param subType 算法单(TWAP VWAP) 跟踪止损单时存在
 */
+ (NSString *)orderTypeDescription:(NSString *)orderType subType:(NSString *)subType;

// 综合账号 附加订单的名称
+ (NSString *)bsAttachOrderTypeDescription:(NSString *)orderType;

/// 订单类型的描述文案
/// @param orderType 订单类型
/// @param support 是否支持暗盘
/// @param composedOrderType 是否支持暗盘
/// @param subType 算法单(TWAP VWAP) 跟踪止损单时存在
+ (NSString *)orderTypeDescription:(NSString *)orderType supportGreyMarket:(BOOL)support composedOrderType:(NSString *)composedOrderType;

+ (NSString *)orderTypeDescription:(NSString *)orderType supportGreyMarket:(BOOL)support composedOrderType:(NSString *)composedOrderType subType:(NSString *)subType;

+ (NSString *)orderTypeFromDescription:(NSString *)orderTypeDescription;

+ (NSString *)statisticsOrderTypeNameFromDescription:(NSString *)orderTypeDescription;

// 环球账户账号
+ (NSString *)attachOrderTypeDescription:(NSInteger)attachOrderType;

+ (NSArray<NSString *> *)availableOrderTypesOfMarket:(NSString *)market secType:(NSString *)secType;

+ (NSArray<NSString *> *)availableOrderTypesWhenModifyFrom:(NSString *)orderType;

+ (NSNumber *)maxQuantityWithMarket:(NSString *)market secType:(NSString *)secType currency:(NSString *)currency price:(double)price lotSize:(NSInteger)lotSize dividedBy:(NSInteger)divisor buyStyle:(BOOL)marginBuy cashDeposit:(double)deposit;

/**
 * @param latestPrice 最新价
 * @param trailingType 追踪止损单跟踪类型 价差/百分比
 * @param offset 偏移量 价差/百分比,如果实80% ，这里就是80
 * @param tradeAction 买卖方向
 * @return 返回预估触发价
 */
+ (double)trailStopOrderTriggerPrice:(double)latestPrice trailingType:(NSString *)trailingType offset:(double)offset action:(TBOrderAction)tradeAction;
/**
 * 是否是开仓操作
 */
+ (BOOL)isOpeningTransaction:(NSString *)originSymbol;
/**
 * 是否是加仓操作
 */
+ (BOOL)isOverweightTransaction:(NSString *)originSymbol action:(NSString *)action;

/// 是否是减仓操作
+ (BOOL)isUnderweightTransaction:(NSString *)originSymbol action:(NSString *)action;

+ (BOOL)hasAskBidInfo:(NSString *)market secType:(NSString *)secType exchangeCode:(NSString *)exchangeCode;

+ (BOOL)hasAskBidOrder:(NSString *)market secType:(NSString *)secType;

+ (BOOL)hasMakeOrderAskBidOrderDetail:(NSString *)market secType:(NSString *)secType;

//计算佣金
+ (NSString *)getCommissionCost:(TBTradeAPIPreviewOrderModel *)model market:(NSString *)market;

+ (NSString *)currencyForMarket:(NSString *)market;

/**
 * 判断价格是否满足最小变动单位要求
 */
+ (BOOL)isValidStockScale:(NSNumber *)scale forPrice:(NSNumber *)price;

/**
 浮点数是否能整除

 @param number 被除数
 @param denom 除数
 */
+ (BOOL)fmodf:(NSNumber *)number denom:(NSNumber *)denom;

+ (NSArray<TBTradeAPIOrderItemModel *> *)sortOrders:(NSArray<TBTradeAPIOrderItemModel *> *)orders;

+ (NSArray<TBTradeAPIOrderItemModel *> *)sortOrders:(NSArray<TBTradeAPIOrderItemModel *> *)orders symbolSortOrder:(TBWatchListItemSortType)sortOrder;

// 是否处于港股竞价时段(盘前盘后)
+ (BOOL)isInsideHKPreOpeningSession:(NSTimeInterval)serverTime;
+ (BOOL)isInsideHKClosingAuctionSession:(NSTimeInterval)serverTime;

/**
 是否是待成交订单中的部分成交

 @param model 订单
 @return 是否
 */
+ (BOOL)isUnfilledPartCompleteOrder:(TBTradeAPIOrderItemModel *)model;

+ (NSDictionary *)handleDecimalQuantity:(NSNumber *)quantity;

/// 是否可以展示盘前盘后交易设置
/// 显示 盘前盘后交易设置条件：
///  1、美股市场 + 正股 + 限价单/止损限价单 （除 综合账户 OTC 订单、条件订单）
///  2、综合账户：港股市场 + 正股 + 现价单/市价单 （除 港股暗盘、条件订单）
/// @param market 市场
/// @param secType 交易品种
/// @param orderType 订单类型
/// @param isUsOTCOrder 是否是美股 OTC 订单
/// @param isHkGreyOrder 是否是 港股暗盘
/// @param composedOrderType 高级订单（组合订单）类型
/// @param isConditionOrder 是否是 条件订单
+ (BOOL)canShowRthSettingForMarket:(NSString *)market
                           secType:(NSString *)secType
                         orderType:(NSString *)orderType
                        usOTCOrder:(BOOL)isUsOTCOrder
                       hkGreyOrder:(BOOL)isHkGreyOrder
                    conditionOrder:(BOOL)isConditionOrder
                 composedOrderType:(NSString *)composedOrderType
                      contractTime:(NSTimeInterval)contractTime;

/** 是否可以展示撤销前有效（GTC：DAY/GTC）设置
 *
 *  **Lite下单页-市价单无GTC配置项**
 *
 *  @param market 市场
 *  @param secType 交易品种
 *  @param orderType 订单类型
 *  @param isBriefMode 是否是Lite下单页
 *  @param isHKOddLotSell 是否是港股碎股下单
 */
+ (BOOL)canShowGTCSettingForMarket:(NSString *)market
                           secType:(NSString *)secType
                         orderType:(NSString *)orderType
                       isBriefMode:(BOOL)isBriefMode
                    isHKOddLotSell:(BOOL)isHKOddLotSell;

/// 废弃！使用canShowGTCSettingForMarket:secType:orderType:isBriefMode:isHKOddLotSell:
+ (BOOL)canShowGTCSettingForMarket:(NSString *)market
                           secType:(NSString *)secType
                         orderType:(NSString *)orderType
                        usOTCOrder:(BOOL)isUsOTCOrder
                    conditionOrder:(BOOL)isConditionOrder
                  buyWaysTypeMoney:(BOOL)isBuyWaysTypeMoney API_DEPRECATED("使用canShowGTCSettingForMarket:secType:orderType:isBriefMode:isHKOddLotSell", ios(8.0, 13.0));


/// 下单页 数量设置 format
/// @param secType 交易品种
/// @param market 市场
/// @param supprtFraction 是否支持碎骨
+ (NSNumberFormatter *)quantityFormatterForSecInfo:(NSString *)secType
                                            market:(NSString *)market
                                   supportFraction:(BOOL)supprtFraction;

+ (NSNumberFormatter *)cashAmountFormatter;

+ (NSString *)attachOrderTypeDesForAttachOrderType:(NSString *)attachOrderType;

// 订单列表跳转到 改单页面
+ (BOOL)handleGotoModifyOrderWithOrderItem:(TBTradeAPIOrderItemModel *)model;

+ (NSString *)tradeTimeAlertWithMarket:(NSString *)market timestamp:(long long)timestamp pageType:(kTBPlaceOrderTradeTimeAlertPageType)pageType orderType:(NSString *)orderType;

/**
 获取当前账户类型名称
 
 @return 当前账户类型名称
 */
+ (NSString *)getCurrentAccountTypeName;

+ (NSString *)getAccountTypeName:(NSString *)accountType;

/** 获取附加括号订单类型描述
 * - 订单类型是 TBPlaceOrderAttachOcaOrderType
 * 0 none
 * 1 LMT
 * 2 STP
 * 3 STP-LMT
 */
+ (NSString *)attachOcaOrderTypeDescription:(NSInteger)attachOrderType;

@end
