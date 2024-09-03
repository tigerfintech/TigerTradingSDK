//
//  TBRSPConstants.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/11/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NSString *TBRSPPeriod;
typedef NSString *TBRiReturnYr;
typedef NSString *TBRSPPaymentMethod;
typedef NSString *TBRSPOrderStatus;

FOUNDATION_EXPORT TBRSPPeriod const _Nonnull kTBRSPPeriodDay;
FOUNDATION_EXPORT TBRSPPeriod const _Nonnull kTBRSPPeriodWeek;
FOUNDATION_EXPORT TBRSPPeriod const _Nonnull kTBRSPPeriodWeek2;
FOUNDATION_EXPORT TBRSPPeriod const _Nonnull kTBRSPPeriodMonth;

FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBRiReturn1Yr;
FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBRiReturn2Yr;
FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBRiReturn3Yr;
FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBRiReturn5Yr;
FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBDivideRate;

FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBStockPriceChg3M;
FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBStockPriceChg6M;
FOUNDATION_EXPORT TBRiReturnYr const _Nonnull kTBStockPriceChg52W;

FOUNDATION_EXPORT TBRSPPaymentMethod const _Nonnull kTBRSPPaymentMethodPrimeAccount;
FOUNDATION_EXPORT TBRSPPaymentMethod const _Nonnull kTBRSPPaymentMethodBankCard;

FOUNDATION_EXPORT TBRSPOrderStatus const _Nonnull kTBRSPOrderStatusCanceled;
FOUNDATION_EXPORT TBRSPOrderStatus const _Nonnull kTBRSPOrderStatusRejected;
FOUNDATION_EXPORT TBRSPOrderStatus const _Nonnull kTBRSPOrderStatusExpired;
FOUNDATION_EXPORT TBRSPOrderStatus const _Nonnull kTBRSPOrderStatusNew;
FOUNDATION_EXPORT TBRSPOrderStatus const _Nonnull kTBRSPOrderStatusPendingNew;
FOUNDATION_EXPORT TBRSPOrderStatus const _Nonnull kTBRSPOrderStatusInvesting;
FOUNDATION_EXPORT TBRSPOrderStatus const _Nonnull kTBRSPOrderStatusFilled;

// 订单状态 order status
typedef NS_ENUM(NSInteger, TBRSPStatus) {
    TBRSPStatusNone    = -1,
    TBRSPStatusFailed  = 0,         // 已终止
    TBRSPStatusOngoing = 1,         // 进行中
};

typedef NS_ENUM(NSInteger, TBRSPActivityStatus) {
    TBRSPActivityStatusNone    = 0,
    TBRSPActivityStatusNotBeginning,   //未开始
    TBRSPActivityStatusOngoing,        //进行中
    TBRSPActivityStatusEnded,          //已结束
};

typedef NS_ENUM(NSInteger, TBRSPInterfaceActionType) {
    TBRSPInterfaceActionTypeNone,
    TBRSPInterfaceActionTypeMyRSP,
    TBRSPInterfaceActionTypeInterfaceCalculator,
    TBRSPInterfaceActionTypeCalculator,
    TBRSPInterfaceActionTypeRSPList,
    TBRSPInterfaceActionTypeAddPlan,
    TBRSPInterfaceActionTypeStockDetail,
    TBRSPInterfaceActionTypeChangeTag,
    TBRSPInterfaceActionTypeGuideCardDetail,
    TBRSPInterfaceActionTypeClearAllTag,
    TBRSPInterfaceActionTypeClearTag,
    TBRSPInterfaceActionTypeDidChangeTypeFilter,
    TBRSPInterfaceActionTypeDidChangeFilter,
    TBRSPInterfaceActionTypeDidUpdateMarketValue,
    TBRSPInterfaceActionTypeDidChangeMarketValue,
    TBRSPInterfaceActionTypePopularBannerDidScrollEnd,
    TBRSPInterfaceActionTypeRSPListDidScrollEnd,
    TBRSPInterfaceActionTypeRSPGuideDidScrollEnd,
};

FOUNDATION_EXPORT NSString *const kTBRSPMyPlanUpdateNotification;
FOUNDATION_EXPORT NSString *const kTBRSPReloadRSPDetailNotification;
FOUNDATION_EXPORT NSString *const kTBRSPCancelRSPNotification;

NS_ASSUME_NONNULL_END
