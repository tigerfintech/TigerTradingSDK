//
//  TBOmnibusAnalysisStockPnlItemModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>
#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBTradeAPIStatBriefItemModel;

@protocol TBOmnibusAnalysisStockPnlItemModel <NSObject>

@end

// 盈亏分析
@interface TBOmnibusAnalysisStockPnlItemModel : JSONModel

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *localSymbol;
@property (nonatomic, copy) NSString *underlyingSymbol;

@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *localName;   //涡轮牛熊证时 对应底层标的名字
@property (nonatomic, copy) NSString *currency;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;

@property (nonatomic, copy) NSString *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *right;

@property (nonatomic, strong) NSNumber *realizedPnl;
@property (nonatomic, strong) NSNumber *unrealizedPnl;  // 受请求的position_cost_type参数影响
@property (nonatomic, strong) NSNumber *totalPnl;       // 受请求的position_cost_type参数影响
@property (nonatomic, strong) NSNumber *averageCost;    // 受请求的position_cost_type参数影响

/// 总交易次数
@property (nonatomic, strong) NSNumber *filledCount;
/// 持仓天数
@property (nonatomic, strong) NSNumber *holdingDays;

/**
 转化成IB的model

 @return ibModel
 */
- (TBTradeAPIStatBriefItemModel *)convertToIBBriefItemMode;

@end


/**
 盈亏分析个股盈亏
 */
@interface TBOmnibusAnalysisStockPnlModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray <TBOmnibusAnalysisStockPnlItemModel> *data;

@end

NS_ASSUME_NONNULL_END
