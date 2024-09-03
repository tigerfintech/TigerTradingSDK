//
//  TBFundTradeHistoryV2.h
//  TBTradeBusiness
//
//  Created by chenxin on 2023/5/31.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>
#import <TBBusinessSupportKit/TBPaymentModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBFundTradeHistoryV2 <NSObject>

@end

// 闲钱（基金）3.0订单使用。基金2.0页面仍然存在，需要共存
@interface TBFundTradeHistoryV2 : JSONModel

@property(nonatomic, copy) NSString * ID; // 订单ID
@property(nonatomic, copy) NSString * symbol;  // isin.currency
@property(nonatomic, copy) NSString * name; // 基金名称
@property(nonatomic, copy) NSString * action; // BUY 申购；SELL 赎回
@property(nonatomic, assign) NSTimeInterval time; //下单时间
@property(nonatomic, assign) NSTimeInterval statusUpdateAt; //状态更新时间

@property(nonatomic, strong) NSNumber * amount; // 金额
@property(nonatomic, strong) NSNumber * filledAmount; // 成交金额
@property(nonatomic, strong) NSNumber * shares; //份额
@property(nonatomic, strong) NSNumber * sharesScale; //份额scale
@property(nonatomic, strong) NSNumber * avgNav; //确认价格 (废弃，使用avgNavStr）
@property(nonatomic, copy) NSString * avgNavStr; //确认价格，使用string，有几位展示几位
//@property(nonatomic, strong) NSNumber * avgNavScale; //确认价格scale
@property(nonatomic, strong) NSNumber * commission;
@property(nonatomic, strong) NSNumber * gst;
@property(nonatomic, strong) NSNumber * commissionAndFee; //commission + gst

@property(nonatomic, strong) NSNumber * upfrontProportion; // 813 upfrontFee比例
@property(nonatomic, strong) NSNumber * upfrontFee; // 813 upfrontFee金额
@property(nonatomic, strong) NSNumber * reqCashAmount; // 813 下单委托金额（外扣真是下单金额相同）

@property(nonatomic, copy) NSString * status;

@property(nonatomic, copy) NSString   * currency; //货币
@property(nonatomic, copy) NSString   * message; // 备注
@property(nonatomic, copy) NSString   * statusDesc; // 状态描述

/// 额外信息： AUTO_SWEEP: 自动申赎 | REGULAR_SAVING_PLAN:定投 | ACCOUNT_MANAGEMENT_FEE: 账户管理费 | PERFORMANCE_FEE: 绩效费
@property(nonatomic, copy) NSArray <NSString *> *attrs;

/// 是否可以取消
@property(nonatomic, assign) BOOL canCancel;

@property (nonatomic, strong) TBPaymentPaymentModel *payment; //支付方式

@end

// 基金无secType和market，需要补充上
@interface TBFundTradeHistoryV2 (TBStockAdditionalInformation)

@property(nonatomic, copy, readonly) NSString *secType;
@property(nonatomic, copy, readonly) NSString *market;

@end

NS_ASSUME_NONNULL_END
