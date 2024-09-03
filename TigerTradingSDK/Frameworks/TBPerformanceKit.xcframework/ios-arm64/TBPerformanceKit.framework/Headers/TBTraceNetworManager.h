//
//  TBTraceNetworManager.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2022/12/5.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import "TBLagRequestObject.h"

typedef enum : NSUInteger {
    InvalidResponseDataWrongType,
    InvalidResponseDataNotSuccess,
    InvalidResponseDataEmpty,
    InvalidBusinessDataNotSuccess,
    InvalidBusinessDataEmpty,
    InvalidBusinessDataWrongType,
    ServerInternalError,
    InvalidParams
} TBInvalidResponseType;

NS_ASSUME_NONNULL_BEGIN

@interface TBTraceNetworManager : NSObject

DECLARE_SHARED_INSTANCE(TBTraceNetworManager);

@property (nonatomic, assign, readonly) NSTimeInterval pageTraceCapDuration;
@property (nonatomic, assign, readonly) BOOL pageTraceEnable;
@property (nonatomic, copy) NSString *userId;

- (void)fetchPageTrace;

- (void)startRequestWithURLString:(NSString *)url;
- (void)endRequestWithURLString:(NSString *)url isSuccess:(BOOL)isSuccess error:(NSError * _Nullable)err;
- (void)endRequesetFailForWithURLString:(NSString *)url invalidResponseType:(TBInvalidResponseType)type;

- (void)clear;
- (TBLagRequestObject *)requestResultForKey:(NSString *)url;

- (NSArray *)debugTraceArrayWithAfterTime:(NSTimeInterval)time beforeTime:(NSTimeInterval)before;

@end

NS_ASSUME_NONNULL_END
