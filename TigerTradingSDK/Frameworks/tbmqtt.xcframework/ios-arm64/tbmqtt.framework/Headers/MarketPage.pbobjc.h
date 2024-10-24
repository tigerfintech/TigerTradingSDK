// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MarketPage.proto

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

@class MarketPage_Index;
@class MarketPage_OffsetDecimal;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MarketPageRoot

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
GPB_FINAL @interface MarketPageRoot : GPBRootObject
@end

#pragma mark - MarketPage

typedef GPB_ENUM(MarketPage_FieldNumber) {
  MarketPage_FieldNumber_Market = 1,
  MarketPage_FieldNumber_Type = 2,
  MarketPage_FieldNumber_IndicesArray = 3,
};

GPB_FINAL @interface MarketPage : GPBMessage

/** 市场 US/CN/SI 等 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *market;

/** 取值为: market */
@property(nonatomic, readwrite, copy, null_resettable) NSString *type;

/** 指数信息 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<MarketPage_Index*> *indicesArray;
/** The number of items in @c indicesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger indicesArray_Count;

@end

#pragma mark - MarketPage_Index

typedef GPB_ENUM(MarketPage_Index_FieldNumber) {
  MarketPage_Index_FieldNumber_Market = 1,
  MarketPage_Index_FieldNumber_Symbol = 2,
  MarketPage_Index_FieldNumber_LatestPrice = 3,
  MarketPage_Index_FieldNumber_PreClose = 4,
  MarketPage_Index_FieldNumber_Timestamp = 5,
};

GPB_FINAL @interface MarketPage_Index : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *market;

@property(nonatomic, readwrite, copy, null_resettable) NSString *symbol;

@property(nonatomic, readwrite, strong, null_resettable) MarketPage_OffsetDecimal *latestPrice;
/** Test to see if @c latestPrice has been set. */
@property(nonatomic, readwrite) BOOL hasLatestPrice;

@property(nonatomic, readwrite, strong, null_resettable) MarketPage_OffsetDecimal *preClose;
/** Test to see if @c preClose has been set. */
@property(nonatomic, readwrite) BOOL hasPreClose;

@property(nonatomic, readwrite) int64_t timestamp;

@end

#pragma mark - MarketPage_OffsetDecimal

typedef GPB_ENUM(MarketPage_OffsetDecimal_FieldNumber) {
  MarketPage_OffsetDecimal_FieldNumber_LongVal = 1,
  MarketPage_OffsetDecimal_FieldNumber_Offset = 2,
};

GPB_FINAL @interface MarketPage_OffsetDecimal : GPBMessage

@property(nonatomic, readwrite) int64_t longVal;

@property(nonatomic, readwrite) int32_t offset;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
