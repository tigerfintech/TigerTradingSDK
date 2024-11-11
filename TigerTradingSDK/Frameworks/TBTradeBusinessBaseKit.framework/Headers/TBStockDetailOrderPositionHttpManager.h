//
//  TBStockDetailOrderPositionHttpManager.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/13.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBTradeBusinessBaseKit/TBPlaceOrderContactInfoDataSource.h>

@class TBComboPositionModel;

@protocol TBStockDetailOrderPositionHttpManagerDelegate;
@protocol TBPlaceOrderContactInfoDataSource;

@interface TBStockDetailOrderPositionHttpManager : NSObject

@property (nonatomic, weak) id<TBStockDetailOrderPositionHttpManagerDelegate> _Nullable delegate;
/// 存储订单支持类型/有效期/保证金等信息
@property (nonatomic, weak) id<TBPlaceOrderContactInfoDataSource> _Nullable contractInfo;

@property (nonatomic, strong) UIColor * _Nonnull cellContentColor;
/**
 主要用于期货价格format显示，订单没有期货相关format格式只有从详情页去合约信息进行format
 */
@property (nonatomic, strong) id /*<TBStockDetailInfoDataSource>*/ _Nullable secInfo;

- (void)loadStockPositionAndOrderArray:(NSString *_Nullable)symbol
                               secType:(NSString *_Nullable)secType
                          originSymbol:(NSString *_Nullable)originSymbol
                              currency:(NSString *_Nullable)currency
                                market:(NSString *_Nullable)market;

///  请求标的的持仓 & 订单
///  originSymbol 涡轮牛熊证使用
///  comboType 组合策略
///  legs: 查询组合下的持仓必传, 字典数组:期权四要素+action+ratio+secType, secType=MLEG时必填，expiry 需要 formatter 成 yyyyMMdd 格式字符串
- (void)loadStockPositionAndOrderArray:(NSString *_Nullable)symbol
                               secType:(NSString *_Nullable)secType
                          originSymbol:(NSString *_Nullable)originSymbol
                              currency:(NSString *_Nullable)currency
                                market:(NSString *_Nullable)market
                             comboType:(nullable NSString *)comboType
                                  legs:(nullable NSArray <NSDictionary *> *)legs;

@end


@protocol TBStockDetailOrderPositionHttpManagerDelegate <NSObject>

@optional
- (void)getStockDetailOrderPosition:(NSArray *_Nullable)positionArray orderArray:(NSArray *_Nullable)orderArray todayCompleteOrderArray:(NSArray *_Nullable)todayCompleteOrderArray;

- (void)responseContractPositionAndOrders:(NSArray *_Nullable)positionOrders;
@end
