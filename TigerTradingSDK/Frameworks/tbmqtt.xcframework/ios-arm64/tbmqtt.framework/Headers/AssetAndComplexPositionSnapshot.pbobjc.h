// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: assetAndComplexPositionSnapshot.proto

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

@class AssetSnapshot;
@class ComplexPositionSnapshot;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - AssetAndComplexPositionSnapshotRoot

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
GPB_FINAL @interface AssetAndComplexPositionSnapshotRoot : GPBRootObject
@end

#pragma mark - AssetAndComplexPositionSnapshot

typedef GPB_ENUM(AssetAndComplexPositionSnapshot_FieldNumber) {
  AssetAndComplexPositionSnapshot_FieldNumber_AccountId = 1,
  AssetAndComplexPositionSnapshot_FieldNumber_SegType = 2,
  AssetAndComplexPositionSnapshot_FieldNumber_AssetSnapshot = 3,
  AssetAndComplexPositionSnapshot_FieldNumber_ComplexPositionSnapshotArray = 4,
  AssetAndComplexPositionSnapshot_FieldNumber_Timestamp = 5,
};

/**
 * 组合视图下的资产持仓数据结构
 **/
GPB_FINAL @interface AssetAndComplexPositionSnapshot : GPBMessage

@property(nonatomic, readwrite) int64_t accountId;

@property(nonatomic, readwrite, copy, null_resettable) NSString *segType;

@property(nonatomic, readwrite, strong, null_resettable) AssetSnapshot *assetSnapshot;
/** Test to see if @c assetSnapshot has been set. */
@property(nonatomic, readwrite) BOOL hasAssetSnapshot;

@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<ComplexPositionSnapshot*> *complexPositionSnapshotArray;
/** The number of items in @c complexPositionSnapshotArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger complexPositionSnapshotArray_Count;

@property(nonatomic, readwrite) int64_t timestamp;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
