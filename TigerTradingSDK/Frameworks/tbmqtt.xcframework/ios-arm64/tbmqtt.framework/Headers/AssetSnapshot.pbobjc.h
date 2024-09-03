// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: assetSnapshot.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30004
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30004 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class AssetSnapshot_AssetAllocation;
@class AssetSnapshot_AssetByCurrency;
@class AssetSnapshot_ContraAssetInfo;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - AssetSnapshotRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
GPB_FINAL @interface AssetSnapshotRoot : GPBRootObject
@end

#pragma mark - AssetSnapshot

typedef GPB_ENUM(AssetSnapshot_FieldNumber) {
  AssetSnapshot_FieldNumber_AccountType = 1,
  AssetSnapshot_FieldNumber_Currency = 2,
  AssetSnapshot_FieldNumber_CashBalance = 3,
  AssetSnapshot_FieldNumber_AccruedDividend = 4,
  AssetSnapshot_FieldNumber_AccruedInterest = 5,
  AssetSnapshot_FieldNumber_SettledCash = 6,
  AssetSnapshot_FieldNumber_AvailableT2SettledCash = 7,
  AssetSnapshot_FieldNumber_EquityWithLoan = 8,
  AssetSnapshot_FieldNumber_NetLiquidation = 9,
  AssetSnapshot_FieldNumber_InitMarginReq = 10,
  AssetSnapshot_FieldNumber_MaintainMarginReq = 11,
  AssetSnapshot_FieldNumber_OvernightMarginReq = 12,
  AssetSnapshot_FieldNumber_GrossPositionValue = 13,
  AssetSnapshot_FieldNumber_UnrealizedPnl = 14,
  AssetSnapshot_FieldNumber_TodayRealizedPnl = 15,
  AssetSnapshot_FieldNumber_TotalTodayPnl = 16,
  AssetSnapshot_FieldNumber_InstantDeposit = 17,
  AssetSnapshot_FieldNumber_ExcessEquity = 18,
  AssetSnapshot_FieldNumber_ExcessLiquidation = 19,
  AssetSnapshot_FieldNumber_OvernightLiquidation = 20,
  AssetSnapshot_FieldNumber_BuyingPower = 21,
  AssetSnapshot_FieldNumber_AvailableBuyingPower = 22,
  AssetSnapshot_FieldNumber_IntradayRiskRatio = 23,
  AssetSnapshot_FieldNumber_OvernightRiskRatio = 24,
  AssetSnapshot_FieldNumber_AvailableEE = 25,
  AssetSnapshot_FieldNumber_LockedEE = 26,
  AssetSnapshot_FieldNumber_Leverage = 27,
  AssetSnapshot_FieldNumber_Level = 28,
  AssetSnapshot_FieldNumber_IntradayRiskLevel = 29,
  AssetSnapshot_FieldNumber_OvernightRiskLevel = 30,
  AssetSnapshot_FieldNumber_ForexRateMap = 31,
  AssetSnapshot_FieldNumber_AssetsByCurrencyArray = 32,
  AssetSnapshot_FieldNumber_UnrealizedPnlByCostOfCarry = 33,
  AssetSnapshot_FieldNumber_TotalPositionPnl = 34,
  AssetSnapshot_FieldNumber_UnrealizedPnlByAverage = 35,
  AssetSnapshot_FieldNumber_TotalTodayPnlPercent = 36,
  AssetSnapshot_FieldNumber_Uncollected = 37,
  AssetSnapshot_FieldNumber_TotalYesterdayPnl = 38,
  AssetSnapshot_FieldNumber_ForexRateBaseCurrency = 39,
  AssetSnapshot_FieldNumber_IdleCashInterest = 40,
  AssetSnapshot_FieldNumber_CreditLineAmount = 41,
  AssetSnapshot_FieldNumber_TotalPositionPnlIncludeZero = 42,
  AssetSnapshot_FieldNumber_AssetAllocationArray = 43,
  AssetSnapshot_FieldNumber_AccruedAccountManagementFee = 44,
  AssetSnapshot_FieldNumber_AccruedAccountManagementFeeGst = 45,
  AssetSnapshot_FieldNumber_RealizedPnlByFifo = 46,
  AssetSnapshot_FieldNumber_RealizedPnlByAverage = 47,
  AssetSnapshot_FieldNumber_RealizedPnlByFifoIncludeZero = 48,
  AssetSnapshot_FieldNumber_RealizedPnlByAverageIncludeZero = 49,
  AssetSnapshot_FieldNumber_ContraAssetInfo = 50,
  AssetSnapshot_FieldNumber_CdpAvailableSellLimit = 51,
};

/**
 * 交易长链接推送,字段名跟短链接一致, 参考：https://git.tigerbrokers.net/alpha/site-api-docs/-/blob/master/api/data.md
 * 资产数据pb格式如下:
 **/
GPB_FINAL @interface AssetSnapshot : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *accountType;

@property(nonatomic, readwrite, copy, null_resettable) NSString *currency;

@property(nonatomic, readwrite) double cashBalance;

@property(nonatomic, readwrite) double accruedDividend;

@property(nonatomic, readwrite) double accruedInterest;

@property(nonatomic, readwrite) double settledCash;

@property(nonatomic, readwrite) double availableT2SettledCash;

/** 聚合资产 */
@property(nonatomic, readwrite) double equityWithLoan;

@property(nonatomic, readwrite) double netLiquidation;

/** 聚合资产 */
@property(nonatomic, readwrite) double initMarginReq;

/** 聚合资产 */
@property(nonatomic, readwrite) double maintainMarginReq;

/** 聚合资产 */
@property(nonatomic, readwrite) double overnightMarginReq;

@property(nonatomic, readwrite) double grossPositionValue;

@property(nonatomic, readwrite) double unrealizedPnl;

@property(nonatomic, readwrite) double todayRealizedPnl;

@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleValue *totalTodayPnl;
/** Test to see if @c totalTodayPnl has been set. */
@property(nonatomic, readwrite) BOOL hasTotalTodayPnl;

@property(nonatomic, readwrite) double instantDeposit;

/** 聚合资产 */
@property(nonatomic, readwrite) double excessEquity;

/** 聚合资产 */
@property(nonatomic, readwrite) double excessLiquidation;

/** 聚合资产 */
@property(nonatomic, readwrite) double overnightLiquidation;

/** 聚合资产 */
@property(nonatomic, readwrite) double buyingPower;

/** 聚合资产 */
@property(nonatomic, readwrite) double availableBuyingPower;

/** 聚合资产 */
@property(nonatomic, readwrite) double intradayRiskRatio;

/** 聚合资产 */
@property(nonatomic, readwrite) double overnightRiskRatio;

/** 聚合资产 */
@property(nonatomic, readwrite) double availableEE;

/** 聚合资产 */
@property(nonatomic, readwrite) double lockedEE;

/** 聚合资产 */
@property(nonatomic, readwrite) double leverage;

@property(nonatomic, readwrite) int32_t level;

/** 聚合资产 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *intradayRiskLevel;

/** 聚合资产 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *overnightRiskLevel;

@property(nonatomic, readwrite, strong, null_resettable) GPBStringDoubleDictionary *forexRateMap;
/** The number of items in @c forexRateMap without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger forexRateMap_Count;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AssetSnapshot_AssetByCurrency*> *assetsByCurrencyArray;
/** The number of items in @c assetsByCurrencyArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger assetsByCurrencyArray_Count;

@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleValue *unrealizedPnlByCostOfCarry;
/** Test to see if @c unrealizedPnlByCostOfCarry has been set. */
@property(nonatomic, readwrite) BOOL hasUnrealizedPnlByCostOfCarry;

@property(nonatomic, readwrite) double totalPositionPnl;

@property(nonatomic, readwrite) double unrealizedPnlByAverage;

@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleValue *totalTodayPnlPercent;
/** Test to see if @c totalTodayPnlPercent has been set. */
@property(nonatomic, readwrite) BOOL hasTotalTodayPnlPercent;

@property(nonatomic, readwrite) double uncollected;

@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleValue *totalYesterdayPnl;
/** Test to see if @c totalYesterdayPnl has been set. */
@property(nonatomic, readwrite) BOOL hasTotalYesterdayPnl;

@property(nonatomic, readwrite, copy, null_resettable) NSString *forexRateBaseCurrency;

@property(nonatomic, readwrite) double idleCashInterest;

@property(nonatomic, readwrite) double creditLineAmount;

@property(nonatomic, readwrite) double totalPositionPnlIncludeZero;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<AssetSnapshot_AssetAllocation*> *assetAllocationArray;
/** The number of items in @c assetAllocationArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger assetAllocationArray_Count;

@property(nonatomic, readwrite) double accruedAccountManagementFee;

@property(nonatomic, readwrite) double accruedAccountManagementFeeGst;

@property(nonatomic, readwrite) double realizedPnlByFifo;

@property(nonatomic, readwrite) double realizedPnlByAverage;

@property(nonatomic, readwrite) double realizedPnlByFifoIncludeZero;

@property(nonatomic, readwrite) double realizedPnlByAverageIncludeZero;

/** 仅contra账户提供 */
@property(nonatomic, readwrite, strong, null_resettable) AssetSnapshot_ContraAssetInfo *contraAssetInfo;
/** Test to see if @c contraAssetInfo has been set. */
@property(nonatomic, readwrite) BOOL hasContraAssetInfo;

@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleValue *cdpAvailableSellLimit;
/** Test to see if @c cdpAvailableSellLimit has been set. */
@property(nonatomic, readwrite) BOOL hasCdpAvailableSellLimit;

@end

#pragma mark - AssetSnapshot_AssetByCurrency

typedef GPB_ENUM(AssetSnapshot_AssetByCurrency_FieldNumber) {
  AssetSnapshot_AssetByCurrency_FieldNumber_Currency = 1,
  AssetSnapshot_AssetByCurrency_FieldNumber_CashBalance = 2,
  AssetSnapshot_AssetByCurrency_FieldNumber_LockedCash = 3,
  AssetSnapshot_AssetByCurrency_FieldNumber_AvailableCash = 4,
  AssetSnapshot_AssetByCurrency_FieldNumber_AvailableT2SettledCash = 5,
  AssetSnapshot_AssetByCurrency_FieldNumber_AvailableEE = 6,
  AssetSnapshot_AssetByCurrency_FieldNumber_AccruedInterest = 7,
  AssetSnapshot_AssetByCurrency_FieldNumber_IdleCashInterest = 8,
  AssetSnapshot_AssetByCurrency_FieldNumber_ContraAssetInfo = 9,
};

GPB_FINAL @interface AssetSnapshot_AssetByCurrency : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *currency;

@property(nonatomic, readwrite) double cashBalance;

@property(nonatomic, readwrite) double lockedCash;

@property(nonatomic, readwrite) double availableCash;

@property(nonatomic, readwrite) double availableT2SettledCash;

@property(nonatomic, readwrite) double availableEE;

@property(nonatomic, readwrite) double accruedInterest;

@property(nonatomic, readwrite) double idleCashInterest;

@property(nonatomic, readwrite, strong, null_resettable) AssetSnapshot_ContraAssetInfo *contraAssetInfo;
/** Test to see if @c contraAssetInfo has been set. */
@property(nonatomic, readwrite) BOOL hasContraAssetInfo;

@end

#pragma mark - AssetSnapshot_AssetAllocation

typedef GPB_ENUM(AssetSnapshot_AssetAllocation_FieldNumber) {
  AssetSnapshot_AssetAllocation_FieldNumber_Type = 1,
  AssetSnapshot_AssetAllocation_FieldNumber_Value = 2,
  AssetSnapshot_AssetAllocation_FieldNumber_UnrealizedPnlByFifo = 3,
  AssetSnapshot_AssetAllocation_FieldNumber_UnrealizedPnlByAverage = 4,
  AssetSnapshot_AssetAllocation_FieldNumber_TotalPositionPnl = 5,
};

GPB_FINAL @interface AssetSnapshot_AssetAllocation : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *type;

@property(nonatomic, readwrite) double value;

@property(nonatomic, readwrite) double unrealizedPnlByFifo;

@property(nonatomic, readwrite) double unrealizedPnlByAverage;

@property(nonatomic, readwrite) double totalPositionPnl;

@end

#pragma mark - AssetSnapshot_ContraAssetInfo

typedef GPB_ENUM(AssetSnapshot_ContraAssetInfo_FieldNumber) {
  AssetSnapshot_ContraAssetInfo_FieldNumber_UsedCreditAmount = 1,
  AssetSnapshot_ContraAssetInfo_FieldNumber_AvailableCreditAmount = 2,
  AssetSnapshot_ContraAssetInfo_FieldNumber_OutstandingAmount = 3,
  AssetSnapshot_ContraAssetInfo_FieldNumber_OffsetAmount = 4,
};

GPB_FINAL @interface AssetSnapshot_ContraAssetInfo : GPBMessage

/** 分币种暂不提供 */
@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleValue *usedCreditAmount;
/** Test to see if @c usedCreditAmount has been set. */
@property(nonatomic, readwrite) BOOL hasUsedCreditAmount;

/** 分币种暂不提供 */
@property(nonatomic, readwrite, strong, null_resettable) GPBDoubleValue *availableCreditAmount;
/** Test to see if @c availableCreditAmount has been set. */
@property(nonatomic, readwrite) BOOL hasAvailableCreditAmount;

@property(nonatomic, readwrite) double outstandingAmount;

@property(nonatomic, readwrite) double offsetAmount;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)