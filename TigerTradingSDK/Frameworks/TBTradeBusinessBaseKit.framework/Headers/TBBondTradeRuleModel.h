//
//  TBBondTradeRuleModel.h
//  TBTradeBusinessBaseKit
//
//  Created by dulijun on 2023/11/8.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBBondTradingHoliday <NSObject>

@end

// 国债交易规则
@interface TBBondTradeRuleModel : JSONModel

@property (nonatomic, copy) NSString *tradingHours; ///< 交易时间
@property (nonatomic, copy) NSString *minPurchase; ///< 交易数量
@property (nonatomic, copy) NSString *orderType; ///< 订单类型
@property (nonatomic, copy) NSString *timeInForce; ///< 订单期限
@property (nonatomic, copy) NSString *buyingPower; ///< 购买力
@property (nonatomic, copy) NSString *buyingRules; ///< 买入规则
@property (nonatomic, copy) NSString *sellingRules; ///< 卖出规则
@property (nonatomic, copy) NSString *dividends; ///< 派息
@property (nonatomic, copy) NSString *maturityRedemption; ///< 到期兑付
@property (nonatomic, copy) NSString *commission; ///< 佣金
@property (nonatomic, copy) NSString *platformUsageFee; ///< 平台使用费
@property (nonatomic, copy) NSString *custodialFee; ///< 托管费
@property (nonatomic, copy) NSString *commissionBrief; ///< 佣金（简短内容）
@property (nonatomic, copy) NSString *platformUsageFeeBrief; ///< 平台使用费（简短内容）
@property (nonatomic, copy) NSString *custodialFeeBrief; ///< 托管费（简短内容）
@property (nonatomic, copy) NSString *finraFee; ///< FINRA交易活动费
@property (nonatomic, copy) NSString *dividendProcessingFee; ///< 派息处理费
@property (nonatomic, copy) NSString *maturityRedemptionFee; ///< 到期兑付费
@property (nonatomic, copy) NSString *transferFee; ///< 转仓费
@property (nonatomic, copy) NSString *bondMarketHoliday;
@property (nonatomic, copy) NSArray<TBBondTradingHoliday> *tradingHolidays; ///< 债券休息日

@end

@interface TBBondTradingHoliday : JSONModel

@property (nonatomic, copy) NSString *holiday;  ///< 假日日期，如：20231225
@property (nonatomic, assign) BOOL half; ///< 是否半日市

@end

NS_ASSUME_NONNULL_END
