//
//  TBStockOrderCheckDefines.h
//  Stock
//
//  Created by zhengzhiwen on 2021/3/9.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBStockKit/TBBaseKLineItem.h>
#import "TBPlaceOrderContactInfoDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@class TBTradeAPIPlaceOrderModel;
@class TBPlaceOrderCheckAlertModel;
@class TBTradeAPIOrderItemModel;
@class TBTradeAPIPositionItemModel;
@class TBBaseViewController;
@class TBPlaceOrderBuySellAmountPromptModel;

typedef NS_ENUM(NSInteger, TBPlaceOrderCheckItem) {
    TBPlaceOrderCheckNone,
    TBPlaceOrderCheckOptionCombo,// 是否形成组合期权，显示对应弹窗（仅下单操作）
    TBPlaceOrderCheckOrderPreTrade, // 下单前校验接口检查
    TBPlaceOrderCheckConditionTriggerPrice, // 条件订单是否设置触发价
    TBPlaceOrderCheckOutsideRTH,           // 允许盘前盘后交易
    TBPlaceOrderCheckOnlyOvernightOnce,    // TBNZ、TFNZ(TBKIWI)牌照的允许盘前盘后交易(弹框触发逻辑、样式、处理逻辑不一样)
    TBPlaceOrderCheckStockAlert, // 毛票交易提醒
    TBPlaceOrderCheckMarketOrder, // 主订单市价单
    TBPlaceOrderCheckDayTrades, // T+0
    TBPlaceOrderCheckTradeShort,// 交易权限检查，用于闪电下单页，检查多有交易品种
    TBPlaceOrderCheckFutureShort,// 交易权限检查，用于闪电下单页，检查期货交易品种
    TBPlaceOrderCheckStockShort, // 股票做空提醒
    TBPlaceOrderCheckOptionShort, // 期权做空提醒
    TBPlaceOrderCheckAmountLimit, // 单笔最高金额
    TBPlaceOrderCheckGreyMarket, // 暗盘提示弹窗(Deprecated. 改为从权限判断)
    TBPlaceOrderCheckDecimalOrder, // 碎股提示弹窗
    TBPlaceOrderCheckComboTypes, // 检查是否为组合类型持仓
    TBPlaceOrderCheckMarscoGFV, // Marsco GFV 限制(只针对TradeUP https://tigertech.feishu.cn/wiki/wikcnqko9F85wIlvpBCDQlHtb7f)
    TBPlaceOrderCheckOptionTradeLimit, // TradeUP 期权交易限制(https://app.asana.com/0/1201159480937235/1201159878707261/f)
    TBPlaceOrderValidateTypeBasic,// 基础参数检查，价格、数量 大于 0
    TBPlaceOrderValidateTypeTick, // 精度
    TBPlaceOrderValidateTypeLimited, // 受限保证金账户
    TBPlaceOrderValidateTypeOrderDetail, // 订单详情预览
    TBPlaceOrderCheckUnableShortStock, // 不允许在限制保证金账户上做空股票
    TBPlaceOrderCheckTradePermissions,// 交易权限检查
    TBPlaceOrderCheckOptionBuySellTradePermissions,// 期权买入/卖出交易权限检查（AU牌照）
    TBPlaceOrderFractionShareRth,///< 美股碎股盘前盘后检查
    TBPlaceOrderInsufficientFunds, ///< 资金不足检查
    TBPlaceOrderCheckOTCClose,     ///< OTC 市场股票是否支持平仓
    TBPlaceOrderCheckGTCOvernight, /// GTC 夜盘交易
    TBPlaceOrderCheckPreConditions,  ///调用/trade/preconditions接口获取校验项进行检查
    TBPlaceOrderCheckOptionMaxQty, /// 期权最高张数
    TBPlaceOrderCheckCDPSell,      /// CDP Sell
};

typedef NS_ENUM(NSInteger, TBPlaceOrderActionAfterCheck) {
    TBPlaceOrderActionAfterCheckNone,
    TBPlaceOrderActionAfterCheckPlaceOrder, // 下单
    TBPlaceOrderActionAfterCheckModifyOrder,// 改单
    TBPlaceOrderActionAfterCheckPreview, // 预览
    TBPlaceOrderActionAfterCheckPnLChart, // 盈亏曲线
};

typedef NS_ENUM(NSInteger, TBPlaceOrderCheckResultActionType) {
    TBPlaceOrderCheckResultActionTypeNone           = 0,
    TBPlaceOrderCheckResultActionTypeChangeOrderType,      ///< 条件订单，切换订单类型
    TBPlaceOrderCheckResultActionTypeAddTriggerPrice,      ///< 条件订单，补充触发价格
    TBPlaceOrderCheckResultActionTypeFixPrice,             ///< 修改价格
    TBPlaceOrderCheckResultActionTypeChangeQty,            ///< 修改数量
    TBPlaceOrderCheckResultActionTypeOffRTH,               ///< 盘前盘后 改为 不允许
    TBPlaceOrderCheckResultActionTypeValidDateSwitchToDay, ///< 订单有效期改为 DAY
    
    // lite下单页-输入边框闪烁动画
    TBPlaceOrderCheckResultActionTypeLimitPriceBorderAlert, ///< 限价
    TBPlaceOrderCheckResultActionTypeStpPriceBorderAlert, ///< 止损价
    TBPlaceOrderCheckResultActionTypeQuantityBorderAlert, ///< 数量
    TBPlaceOrderCheckResultActionTypeAttachedOCATakeProfitPriceBorderAlert, ///< 附加括号订单-止盈
    TBPlaceOrderCheckResultActionTypeAttachedOCAStopLossTriggerPriceBorderAlert, ///< 附加括号订单-止损触发价
    TBPlaceOrderCheckResultActionTypeAttachedOCAStopLossPriceBorderAlert, ///< 附加括号订单-止损价
};

@protocol TBStockOrderDataSource <NSObject>

@optional

/// 下单对象，在下单操作时主要修改该对象值
- (TBTradeAPIPlaceOrderModel *)placeOrderModel;

//改单预览
- (TBTradeAPIOrderItemModel *)orderItemModel;

- (TBPlaceOrderBuySellAmountPromptModel *)estimateAmountModel;

/// 证券价格信息, 包括股票和期权, 是上面的4种具体类型中的一种, 用于屏蔽各行情数据结构的实现
/// 所有行情数据都来自于这个model
/// 解耦原因, 将代理注释掉, 相关的值会通过service方法获取
- (id<TBStockDetailInfoDataSource>)secInfo;

/// 存储订单支持类型/有效期/保证金等信息
- (id<TBPlaceOrderContactInfoDataSource>)contractInfo;

/// 平仓订单对象
- (TBTradeAPIPositionItemModel *)positionItem;

- (TBPlaceOrderAction)placeOrderAction; // 下单操作: 买, 卖, 平, 改, 交易帖

/// 是否为碎股
- (BOOL)isOddLotsSell;

//!< 展示股票毛票提醒
- (BOOL)needShowRiskAlert;

/// omnibus 使用
- (NSString *)externalId;

@end

@protocol TBPlaceOrderCheckActionCallback <NSObject>

- (NSAttributedString *)getShortHintText;
- (BOOL)needShowMaxMoneyAlertShow;
- (double)minTick:(double)price ranges:(NSArray *_Nullable *_Nullable)ranges;
- (BOOL)checkIsBSAttachOrder;
- (NSString *)message:(NSNumber *)price ranges:(NSArray *)ranges minTick:(NSNumber *)minTick;
- (TBBaseViewController *)viewController;

@end

@protocol TBPlaceOrderCheckAction <NSObject>

- (void)setupCallback:(id<TBPlaceOrderCheckActionCallback>)callback;
- (void)setupDataSource:(id<TBStockOrderDataSource>)data;

- (BOOL)shouldShowAlertForItemOutInfo:(NSDictionary **_Nonnull)outInfo;
- (void)showCheckAlert:(TBPlaceOrderCheckAlertModel *)model;

@end

@protocol TBPlaceOrderServiceCallback <NSObject>

- (BOOL)forceTrading;

@end

@protocol TBPlaceOrderCheckerViewControllerCallback <NSObject>
@optional
- (void)dissmissIfNeed;
- (void)afterCheckPnLChart;
- (void)modifiedSuccess;

@end


NS_ASSUME_NONNULL_END
