//
//  TBDefenderRecord.h
//  Stock
//
//  Created by JustLee on 2021/1/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBDefenderKit.h"

#define TBDefenderTryCatch(...) @try{ \
    __VA_ARGS__;\
} @catch(NSException * exception) { \
    [TBDefenderRecord recordException:exception]; \
};

#define TBDefenderTryCatchWithDefenderType(_TBDefenderType, ...) @try{ \
    __VA_ARGS__;\
} @catch(NSException * exception) { \
    [TBDefenderRecord recordException:exception errorType:(_TBDefenderType)];\
};

#define TBDefenderContitaerTryCatch(...) TBDefenderTryCatchWithDefenderType(TBDefenderTypeContainer, __VA_ARGS__);

NS_ASSUME_NONNULL_BEGIN

@interface TBDefenderRecord : NSObject

///  注册汇报中心
/// @param record 汇报中心
+ (void)registerRecordHandler:(nullable id<TBDefenderRecordProtocol>)record;

/// 汇报Crash
/// @param reason Sting 原因
/// @param type TBDefenderType
+ (void)recordFatalWithReason:(nullable NSString *)reason
                    errorType:(TBDefenderType)type;

/// 记录exception
/// @param exception expression description
+ (void)recordException:(NSException *)exception;

/// 记录exception
/// @param exception exception description
/// @param type type description
+ (void)recordException:(NSException *)exception errorType:(TBDefenderType)type;

@end

NS_ASSUME_NONNULL_END
