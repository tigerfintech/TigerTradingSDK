//
//  TBLagManager.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2022/2/22.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import "TBTraceNetworManager.h"
#import "TBPlatformLogger.h"
@class TBPlatfromLoggerConfig;

#define TraceStart(class, cmd)  [TBLagManager.sharedInstance startWithClass:NSStringFromClass(class) command:NSStringFromSelector(cmd)];

#define TraceEnd(class, cmd)  [TBLagManager.sharedInstance endWithClass:NSStringFromClass(class) command:NSStringFromSelector(cmd)];

#define TraceStartCurrent() [TBLagManager.sharedInstance startWithClass:NSStringFromClass([self class]) command:NSStringFromSelector(_cmd)];

#define TraceEndCurrent() [TBLagManager.sharedInstance endWithClass:NSStringFromClass([self class]) command:NSStringFromSelector(_cmd)];

#define TraceNetworkStart(url)  [TBTraceNetworManager.sharedInstance startRequestWithURLString:url];
#define TraceNetworkEndSuccess(url)  [TBTraceNetworManager.sharedInstance endRequestWithURLString:url isSuccess:YES error:nil];
#define TraceNetworkEndFail(url, err)  [TBTraceNetworManager.sharedInstance endRequestWithURLString:url isSuccess:NO error:err];
#define TraceNetworkEndFailWithType(url, type)  [TBTraceNetworManager.sharedInstance endRequesetFailForWithURLString:url invalidResponseType:type];


NS_ASSUME_NONNULL_BEGIN

@interface TBLagManager : NSObject


DECLARE_SHARED_INSTANCE(TBLagManager);

- (void)appendLog:(NSString *)msg;
- (void)setupLagManager;

- (void)startMonitor;
- (void)stopMonitor;

//统计方法
- (void)startWithClass:(NSString *)cls command:(NSString *)cmd;
- (void)endWithClass:(NSString *)cls command:(NSString *)cmd;

//获取指定时间段内的方法耗时信息, start和end单位是ms
- (NSString *)methodCostInfoWithStart:(NSTimeInterval)start end:(NSTimeInterval)end;

- (NSString *)debugMessage;
- (void)debugUpload;

@end

NS_ASSUME_NONNULL_END
