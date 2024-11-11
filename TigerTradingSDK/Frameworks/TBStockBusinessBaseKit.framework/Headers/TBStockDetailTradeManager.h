//
//  TBStockDetailTradeManager.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/23.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBStockBusinessBaseKit/TBStockDetailViewControllerDelegate.h>
@class TBStockInfoDetailItemModel;
@class TBAStockSymbolMetaItemModel;
@class TBStockOptionCorporateActionDataModel;



typedef NS_ENUM(NSUInteger, TBHKStockOptionTarget) {
    TBHKStockOptionTargetWarIpotChain,
    TBHKStockOptionTargetOption,
//    TBHKStockOptionTargetSimple,
//    TBHKStockOptionTargetOptionCombined,
};
typedef NS_ENUM(NSUInteger, TBTradeType) {
    TBTradeTypeBuy = 1,
    TBTradeTypeSell,
    TBTradeTypeModify,
    TBTradeTypeCancel,
    TBTradeTypeClose,
    TBTradeTypeSpeedMakeOrder,
    TBTradeTypeTradeTab, // 从交易tab的入口进入下单页
    TBTradeTypeMonetaryBuy, ///< 按金额下单入口
    TBTradeTypeRsp, ///< 定投
    TBTradeTypeCdp, ///< cdp
};

typedef NS_ENUM(NSUInteger, TBTradeMBShowType) {
    TBTradeMBShowTypeText,
    TBTradeMBShowTypeSuccess,
    TBTradeMBShowTypeLoadingShow,
    TBTradeMBShowTypeLoadingEnd,
};

@protocol TBStockDetailTradeManagerDelegate;
@class  TBStockOptionCorporateActionDataModel;

@interface TBStockDetailTradeManager : NSObject

@property (nonatomic, weak) id<TBStockDetailTradeManagerDelegate> delegate;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSArray *positions;
@property (nonatomic, copy) NSArray *orders;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *limitPrice;

@property (nonatomic, assign) BOOL isOption;
@property (nonatomic, assign) BOOL isBtcETF;        /// 是否是btc etf 默认NO

//@property (nonatomic, strong) TBStockInfoDetailItemModel *stockInfo;
@property (nonatomic, strong) TBAStockSymbolMetaItemModel *astockItemModel;
@property (nonatomic, strong) TBStockOptionCorporateActionDataModel *corporateActionDataModel;

@property (nonatomic, weak) id<TBStockDetailInfoDataSource>dataSource;
@property (nonatomic, weak) id<TBPlaceOrderContactInfoDataSource>contractInfo;

@property (nonatomic, assign) BOOL isStockInfoPositionClose;///< 是否是点击的 个股标的持仓的平仓 按钮引起的

@property (nonatomic, assign) BOOL contractSupportFractionalShare; ///< 是否支持碎股（合约接口中的数据）

/// MARK- 卖出
- (void)sellButtonClicked;

/// MARK- 买入
- (void)buyButtonClicked;

//定投
- (void)rspButtonClicked;

/// cdp 交易
- (void)cdpButtonClicked;

- (void)speedButtonClicked; // 快速下单

- (void)monetaryButtonClicked; // 按金额下单按钮点击（位于个股详情bottomBar更多-按金额下单中）

/// MARK- 平仓：只有港股/美股/窝轮牛熊证/期权有
- (void)closeButtonClicked;

/// MARK- 期权/窝轮牛熊证
- (void)optionButtonClicked:(TBHKStockOptionTarget)target optionSymbol:(NSString *)optionSymbol;

//- (void)checkOpenLimitContinueSell;
//- (void)checkoutOpenLimitContinueBuy;
- (void)makeCloseOrder;

- (void)makeBuyOrder;
- (void)makeSellOrder;
- (void)makeSpeedOrder;
- (void)makeMonetaryOrder;
- (void)makeRspOrder;
- (void)makeRspOrderIfNeeded;
- (void)makeCdpOrder;

@end

@protocol TBStockDetailTradeManagerDelegate <NSObject>

@optional
- (void)showTastWithStr:(NSString *)tastStr showType:(TBTradeMBShowType )showType;
- (void)tradeActionWithType:(TBTradeType)tradeType;
- (void)stockAccountVC;
- (void)bindBankCard;
- (void)limitMarginTradePrompt:(TBTradeType)tradeType;
- (void)makeSpeedOrderAction;

- (void)dismissMenuPage:(void (^ __nullable)(void))completion;

- (NSDictionary *)optionTradeDic;

- (void)gotoUpgradeMarginAccount;
- (void)gotoUpdateMarginAccountResource;  //Omnibus保证金账户升级资料

/// 期货资金划转弹窗
/// @param continueBlock 用户选择继续时执行的操作, 可以为 nil
- (void)futuresTransferFundFromSecWithContinue:(void (^)(void))continueBlock;


@end
