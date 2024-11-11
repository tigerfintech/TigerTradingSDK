//
//  TBTradeAPIPositionModel+CostType.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/5/18.
//

#import "TBTradeAPIPositionModel.h"
#import <TBBusinessSupportKit/TBUserConfigManager.h>
#import "TBPositionIndocatorMacro.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeAPIPositionItemModel (CostType)

// 成本类型
- (NSString *)costTypeForCurrentAccount;

/**
 * 根据app类型、当前账户类型(综合、环球)和设置的成本类型获取持仓成本
 * TigerTrade和综合账户存在摊薄
 */
- (NSNumber *)averageCostBasedOnCostType;
/**
 * 根据app类型、当前账户类型(综合、环球)和设置的成本类型获取浮动盈亏
 */
- (NSNumber *)unrealPnlBasedOnCostType;
/**
 * 根据app类型、当前账户类型(综合、环球)和设置的成本类型获取浮动盈亏率
 */
- (NSNumber *)unrealPnlPercentBasedOnCostType;
/**
 * 根据app类型、当前账户类型(综合、环球)和设置的成本类型获取已实现盈亏(910新增)
 */
- (NSNumber *)realizedPnlBasedOnCostType;
/**
 * 根据成本类型返回持仓成本
 */
- (NSNumber *)averageCostWithCostType:(TBPositionSettingCostType)costType;
/**
 * 根据成本类型返回浮动盈亏
 */
- (NSNumber *)unrealPnlWithCostType:(TBPositionSettingCostType)costType;
/**
 * 根据成本类型返回浮动盈亏率
 */
- (NSNumber *)unrealPnlPercentWithCostType:(TBPositionSettingCostType)costType;
/**
 * 根据当前账户类型和持仓成本类型设置持仓成本到averageCost or averageCostOfCarry
 * @param costType 持仓成本类型
 * @param omnibus 是否为综合账户
 * @param value 持仓成本数值
 */
- (void)setAverageCostWithCostType:(TBPositionSettingCostType)costType omnibus:(BOOL)omnibus averageCost:(NSNumber *)averageCost;
/**
 * 根据当前账户类型和持仓成本类型设置浮动盈亏到unrealPnl or unrealPnlByCostOfCarry
 * @param costType 持仓成本类型
 * @param omnibus 是否为综合账户
 * @param value 浮动盈亏数值
 */
- (void)setUnrealPnlWithCostType:(TBPositionSettingCostType)costType omnibus:(BOOL)omnibus unrealPnl:(NSNumber *)unrealPnl;

- (CGFloat)pnlRate;

@end

NS_ASSUME_NONNULL_END
