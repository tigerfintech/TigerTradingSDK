//
//  TBOrderAttrTypes.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/6/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBOrderAttrType;

FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeOddLot;                     ///< 碎股订单（非整手)
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeGreyMarket;                 ///< 港股暗盘订单
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeFractionalShare;            ///< 碎股订单（非整股）
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeBrokerLiquidation;          ///< 上手强平执行报告生成的强平订单
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeConditionalOrder;           ///< 条件订单
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeAttachedOrder;              ///< 附加订单
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeFA;                         ///< 财务顾问下单
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeOCAOrder;                   ///< OCA订单(括号订单)
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeCoupon;                     ///< 是否使用优惠券
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeAccountMgmtFee;             ///< FA账户管理费
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypePerformanceFee;             ///< FA绩效费
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeCDP;                        ///< CDP订单
FOUNDATION_EXPORT TBOrderAttrType const _Nonnull TBOrderAttrTypeBuyIn;                      ///< Buy in 订单

FOUNDATION_EXPORT NSString *const _Nonnull TBUserLifetimeCommissionFree;


NS_ASSUME_NONNULL_END
