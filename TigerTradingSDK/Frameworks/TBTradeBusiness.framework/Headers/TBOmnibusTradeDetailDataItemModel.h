//
//  TBOmnibusTradeDetailDataItemModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>
#import "TBUSStockPNLModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBOmnibusTradeDetailDataItemModel;

/**
 盈亏分析，交易明细
 */
@interface TBOmnibusTradeDetailDataItemModel : JSONModel

@property (nonatomic, strong) NSNumber *orderId;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *action;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString * localSymbol;
@property (nonatomic, strong) NSNumber *filledQty;
@property (nonatomic, strong) NSNumber *filledQtyScale;
@property (nonatomic, strong, readonly) NSNumber *realFilledQty;

@property (nonatomic, assign) CGFloat price;
@property (nonatomic, strong) NSNumber *tradeDate;
@property (nonatomic, strong) NSNumber *realizedPnl;

@property (nonatomic, strong) NSNumber *isOpen;///< 是否为开仓

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *cashFlow; // IN/OUT
@property (nonatomic, strong) NSNumber *commissionAndFees;
@property (nonatomic, strong) NSNumber *amount;

@property (nonatomic, copy) NSString *expiry;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *strike;

@property (nonatomic, assign) BOOL isRegularSavingsPlan; /// 是否为定投

@property (nonatomic, copy) NSArray<NSString *> *attrList;

@property (nonatomic, copy) NSDictionary *comboTypeMap; ///< 组合类型映射
@property (nonatomic, copy) NSArray <TBOmnibusTradeDetailDataItemModel> *legs;

/**
 转化成Ib盈亏分析交易明细

 @return Ib盈亏分析交易明细
 */
-(TBUSStockPNLItemTradeModel *)convertToIBPNLItemModel;
@end


NS_ASSUME_NONNULL_END
