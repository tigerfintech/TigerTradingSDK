//
//  TBDefenderKit.h
//  TBPerformanceKit
//
//  Created by JustLee on 2021/1/29.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "TBDefenderStubObject.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBDefenderType) {
    TBDefenderTypeUnknown               = 0,        //未知原因

    TBDefenderTypeUnrecognizedSelector  = 1 << 1,
    TBDefenderTypeContainer             = 1 << 2,
    TBDefenderTypeNSNull                = 1 << 3,
    TBDefenderTypeKVO                   = 1 << 4,
    TBDefenderTypeTimer                 = 1 << 5,
    TBDefenderTypeDangLingPointer       = 1 << 6,
    TBDefenderTypeString                = 1 << 7,

    TBDefenderTypeExceptDangLingPointer = (TBDefenderTypeUnrecognizedSelector | TBDefenderTypeContainer |
                                           TBDefenderTypeNSNull| TBDefenderTypeKVO | TBDefenderTypeTimer | TBDefenderTypeString)
};

typedef void(^CustomDefenderCatch)(void);

@protocol TBDefenderCatchProtocol <NSObject>

+ (void)registerCatchSelectorException;
+ (void)registerCatchContainerException;
+ (void)registerCatchNSNullException;
+ (void)registerCatchKVOException;
+ (void)registerCatchTimerException;
+ (void)registerCatchStringException;

+ (void)registerCatchCommonException;

@end

@protocol TBDefenderRecordProtocol <NSObject>

/// 暴露给外部的记录方法
/// @param reason reason description    
- (void)recordWithReason:(NSError *)reason;

@end


@interface TBDefenderKit : NSObject

/**
 注册汇报中心
 
 @param record 汇报中心
 */
+ (void)registerRecordHandler:(id<TBDefenderRecordProtocol>)record;

/**
 注册SDK，默认只要开启就打开防Crash，如果需要DEBUG关闭，请在调用处使用条件编译
 本注册方式不包含TBDefenderTypeExceptDangLingPointer类型
 */
+ (void)registerStabilitySDK;

/**
 单独注册类型防护
 不包含TBDefenderTypeExceptDangLingPointer类型
 @param ability ability
 */
+ (void)registerStabilityWithAbility:(TBDefenderType)ability;

/**
 ///注册TBDefenderTypeExceptDangLingPointer需要传入存储类名的array，不支持系统框架类。
 
 @param ability ability description
 @param classNames 野指针类列表
 */
+ (void)registerStabilityWithAbility:(TBDefenderType)ability withClassNames:(nonnull NSArray<NSString *> *)classNames;

/// 添加不需要保护的控制器类型
/// @param vcClassNames vcClassNames description
+ (void)registerExcludeVCClassNames:(nonnull NSArray<NSString *> *)vcClassNames;

/// 注册自定义的拦截类型
/// @param customWork customWork description
+ (void)regusterCustomDefenderWithWork:(CustomDefenderCatch)customWork;

@end





@interface NSObject (TBDefenderSwizzling)

/// 实例方法交换
/// @param originalSelector 原始方法
/// @param swizzledSelector 替换方法
+ (BOOL)swizzleInstanceMethod:(SEL)originalSelector with:(SEL)swizzledSelector;

/// 类方法交换
/// @param originalSelector 原始方法
/// @param swizzledSelector 替换方法
+ (BOOL)swizzleClassMethod:(SEL)originalSelector with:(SEL)swizzledSelector;


/// 实例方法交换
/// @param originalSelector 原始方法
/// @param swizzledSelector 替换方法
/// @param cls 交换的类
+ (BOOL)swizzleInstanceMethod:(SEL)originalSelector swizzledSelector:(SEL)swizzledSelector withClass:(Class)cls;

/// 类方法交换
/// @param originalSelector 原始方法
/// @param swizzledSelector 替换方法
/// @param cls 交换的类
+ (BOOL)swizzleClassMethod:(SEL)originalSelector swizzledSelector:(SEL)swizzledSelector withClass:(Class)cls;

/// 实例交换方法
/// @param anClass 交换的类
/// @param method1Sel method1Sel description
/// @param method2Sel method2Sel description    
+ (BOOL)exchangeInstanceMethod:(Class)anClass method1Sel:(SEL)method1Sel method2Sel:(SEL)method2Sel;

@end



@interface NSObject (TBDefenderCatch) <TBDefenderCatchProtocol>

@end

NS_ASSUME_NONNULL_END
