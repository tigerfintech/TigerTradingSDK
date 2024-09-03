//
//  TBConditionOrderConstants.h
//  Stock
//
//  Created by 王昌阳 on 2020/10/13.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//  条件订单常用参数
//  wiki: https://git.tigerbrokers.net/alpha/site-api-docs/-/blob/condition/api/data.md#conditionType

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

// 条件订单 下单参数
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionID;///< 条件序号
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionType;///< 条件类型
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionValue;///< 条件值
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionOperator;///< 条件运算符
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionConjunction;///< 条件连接符

// 条件订单 条件运算符
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionOperatorEQ;///< 条件运算符: 等于
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionOperatorNE;///< 条件运算符: 不等于
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionOperatorGT;///< 条件运算符: 大于
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionOperatorLT;///< 条件运算符: 小于
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionOperatorGE;///< 条件运算符: 大于等于
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionOperatorLE;///< 条件运算符: 小于等于

// 条件订单 条件连接符
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionConjunctionAND;///< 条件连接符: 并且
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionConjunctionOR;///< 条件连接符: 或

// 条件订单 条件类型
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTypePRICE;///< 合约价格
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTypeVOLUME;///< 合约成交量
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTypeTIME;///< 时间
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTypeMARGIN;///< 融资额度
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTypeEXECUTION;///< 某合约有交易
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTypePERCENT_CHANGE;///< 前一日收盘价的百分比

FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTriggerStatusNEW;///< 条件订单状态 未触发 NEW
FOUNDATION_EXTERN NSString *const kPlaceOrderConditionTriggerStatusTRIGGERED;///< 条件订单状态 已触发 TRIGGERED

typedef NS_ENUM(NSInteger, TBConditionOrdersCategoryType) {
    TBConditionOrdersCategoryTypePendingTrigger = 0,    ///< 待触发
    TBConditionOrdersCategoryTypePendingDeal,           ///< 待成交
    TBConditionOrdersCategoryTypeDeal,                  ///< 已成交
    TBConditionOrdersCategoryTypeRevoked,               ///< 已撤销
};



NS_ASSUME_NONNULL_END
