//
//  TBOrderFeeCategoryModel.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2021/12/15.
//

#import <TBBaseKit/JSONModel.h>

typedef NSString *TBOrderFeeType;
typedef NSString *TBOrderFeeCategoryType;
typedef NSString *TBOrderRebateType;            //订单折扣类型
typedef NSString *TBOrderRebateStatus;


FOUNDATION_EXPORT TBOrderFeeType const _Nonnull kTBOrderFeeTypeUserComission;                  ///< 收费类别-子项-佣金
FOUNDATION_EXPORT TBOrderFeeType const _Nonnull kTBOrderFeeTypeComission;                      ///< 收费类别-子项-佣金 交易和活动取值不一样兼容
FOUNDATION_EXPORT TBOrderFeeType const _Nonnull kTBOrderFeeTypePlatformFee;                    ///< 收费类别-子项-平台费
FOUNDATION_EXPORT TBOrderFeeType const _Nonnull kTBOrderFeeTypeTradingFee;                     ///< 收费类别-子项-交易费
FOUNDATION_EXPORT TBOrderFeeType const _Nonnull kTBOrderFeeTypeBrokerageFee;                   ///< TBAU收费类别-子项-交易费
FOUNDATION_EXPORT TBOrderFeeType const _Nonnull kTBOrderFeeTypeOrderRebate;                    ///< 活动抵扣类型-优惠券
FOUNDATION_EXPORT TBOrderFeeCategoryType const _Nonnull TBOrderFeeCategoryTypeTiger;          ///< 收费类别-老虎国际
FOUNDATION_EXPORT TBOrderFeeCategoryType const _Nonnull TBOrderFeeCategoryTypeTigerOfficical; ///< 收费类别-官网费用
FOUNDATION_EXPORT TBOrderFeeCategoryType const _Nonnull TBOrderFeeCategoryTypeThirdParty;     ///< 收费类别-第三方

FOUNDATION_EXPORT TBOrderRebateType const _Nonnull TBOrderRebateTypeCommissionFree; ///< 优惠类型-免佣
FOUNDATION_EXPORT TBOrderRebateType const _Nonnull TBOrderRebateTypeRebate;         ///< 优惠类型-抵扣
FOUNDATION_EXPORT TBOrderRebateType const _Nonnull TBOrderRebateTypeReward;         ///< 优惠类型-返现

FOUNDATION_EXPORT TBOrderRebateStatus const _Nonnull TBOrderRebateStatusRebating;   ///< 免佣卡、折扣券等的状态-待折扣
FOUNDATION_EXPORT TBOrderRebateStatus const _Nonnull TBOrderRebateStatusRebated;    ///< 免佣卡、折扣券等的状态-已折扣
FOUNDATION_EXPORT TBOrderRebateStatus const _Nonnull TBOrderRebateStatusApplied;    ///< 免佣卡、折扣券等的状态-已申请

NS_ASSUME_NONNULL_BEGIN

@protocol TBOrderFeeItemModel<NSObject>
@end

@protocol TBOrderFeeCategoryModel<NSObject>
@end

@protocol TBOrderReabteModel<NSObject>
@end

@protocol TBOrderReabtesModel<NSObject>
@end

@interface TBOrderFeeCategoryModel : JSONModel

@property (nonatomic, copy) TBOrderFeeCategoryType category;
@property (nonatomic, copy) NSString *categoryDesc;
@property (nonatomic, strong) NSNumber *total;

@property (nonatomic, copy) NSArray<TBOrderFeeItemModel> *details;

@end


@interface TBOrderFeeItemModel : JSONModel

@property (nonatomic, copy) TBOrderFeeType type;
@property (nonatomic, copy) NSString *typeDesc;

@property (nonatomic, strong) NSNumber *originalAmount;
@property (nonatomic, strong) NSNumber *afterDiscountAmount;

@end

@interface TBOrderReabteModel : JSONModel

@property (nonatomic, copy) TBOrderRebateStatus status;           //折扣状态：待折扣（REBATING），已折扣（REBATED），已申请（APPLIED）
@property (nonatomic, copy) NSString<Optional> *currency;         //币种
@property (nonatomic, copy) NSString<Optional> *msg;              //优惠使用失败存在
@property (nonatomic, strong) NSNumber<Optional> *amount;         //折扣金额

@end

@interface TBOrderReabtesModel : JSONModel

@property (nonatomic, strong) TBOrderReabteModel<Optional> *commissionRebateModel;         /// 免佣
@property (nonatomic, strong) TBOrderReabteModel<Optional> *orderRebateModel;              /// 抵扣
@property (nonatomic, strong) TBOrderReabteModel<Optional> *orderRewardModel;              /// 返现

@end
NS_ASSUME_NONNULL_END
