//
//  TBPlaceOrderBriefQuoteViewController.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/7/2.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBPlaceOrderBaseTableViewController.h"
/*
 下单页简要行情：
 包含两部分：
 
 1、无行情 展示搜索，点击跳转搜索页面
 2、有行情 展示简要行情，可点击，跳转行情页，标的信息可清除
 
 
 */
NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderBriefQuoteViewController : TBPlaceOrderBaseTableViewController


/// 合约改变
@property (nonatomic, copy) void(^contractSwitched)(NSNumber *contractId, NSString *symbol, NSString *secType, NSString *market);

/// 合约信息被清除
@property (nonatomic, copy) void(^contractCleared)(void);

@property (nonatomic, copy) void(^contractQuoteUpdate)(void);

@property (nonatomic, copy) void(^secInfoUpdate)(id<TBStockDetailInfoDataSource> secInfo);

@property (nonatomic, assign, getter=isModifyOrder) BOOL modifyOrder;

@property (nonatomic, assign) BOOL disableChangeSymbol;///< 禁止切换标的（港股碎股卖出时不支持切换标的）
@property (nonatomic, assign) BOOL isSGOddLotsTradeMode;///< 是否是新加坡碎股交易模式

- (void)resetContract:(NSNumber *)contractId symbol:(NSString *)symbol secType:(NSString *)secType market:(NSString *)market;

/// 数据更新时间戳
@property (nonatomic, assign) NSTimeInterval secInfoUpateTime;


@property (nonatomic, assign) BOOL enableMQTT;

@end

NS_ASSUME_NONNULL_END
