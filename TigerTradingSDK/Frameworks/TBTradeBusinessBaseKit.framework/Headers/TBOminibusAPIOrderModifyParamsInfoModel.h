//
//  TBOminibusAPIOrderModifyParamsInfoModel.h
//  Stock
//
//  Created by 王昌阳 on 2020/7/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/TBBaseUtility.h>
#import "TBPlaceOrderConditionItem.h"

@class TBPlaceOrderConditionItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBOminibusAPIOrderModifyParamsInfoModel : JSONModel

@property (nonatomic, strong) NSNumber *totalQuantity; ///< int 下单数量
@property (nonatomic, strong) NSNumber *totalQuantityScale; ///< int 下单数量

@property (nonatomic, strong) NSNumber *realTotalQuantity; ///< double 下单数量

@property (nonatomic, strong) NSNumber *totalCashAmount; ///< 下单总金额

@property (nonatomic, strong) NSNumber *price;///< 限价
@property (nonatomic, strong) NSNumber *stopPrice;///< 止损价

@property (nonatomic, copy) NSArray<TBPlaceOrderConditionItem *><TBPlaceOrderConditionItem>  *conditions;///< 条件订单中对应的条件

@property (nonatomic, copy) NSString *orderType;///< 订单类型（环球账户）
@property (nonatomic, copy) NSString *timeInForce;///< 订单期限（环球账户）
@property (nonatomic, strong) NSNumber *auxPrice;///< 跟踪止损单（价差）（环球账户）
@property (nonatomic, strong) NSNumber *trailingPercent;///< 跟踪止损单（百分比）（环球账户）

@end

NS_ASSUME_NONNULL_END
