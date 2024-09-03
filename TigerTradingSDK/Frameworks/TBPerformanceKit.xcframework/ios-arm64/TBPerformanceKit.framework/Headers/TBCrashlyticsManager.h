//
//  TBCrashlyticsManager.h
//  Stock
//
//  Created by dulijun on 2021/6/8.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

/*
 
 使用指南
 1.
 APP启动时调用configure 初始化:[TBCrashlyticsManager configureWithSDKType:];
 使用时调用具体功能，如:[TBCrashlyticsManager log:@"your message"];
 
 2.扩展:以后新增sdk：
 新建类，遵从协议TBCrashlyticsProtocol，并实现方法

 */

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

typedef NS_ENUM(NSUInteger,TBCrashlyticsUtilType) {
    TBCrashlyticsUtilTypeFirebase ,//华为agc
    TBCrashlyticsUtilTypeHuaweiAgc,//firebase
};

typedef NS_ENUM(NSUInteger,TBCrashlyticsConfigValueType) {
    TBCrashlyticsConfigValueTypeBOOL = 1,
    TBCrashlyticsConfigValueTypeNumber,
    TBCrashlyticsConfigValueTypeString,
    TBCrashlyticsConfigValueTypeJSON
};

NS_ASSUME_NONNULL_BEGIN

@interface TBCrashlyticsManager : NSObject

DECLARE_SHARED_INSTANCE(TBCrashlyticsManager);

//初始化
+ (void)configure;

// sdk类型
+ (NSString *)sdkTypeString;

//具体功能
+ (void)recordError:(NSError *)error;
+ (void)log:(NSString *)msg;
+ (void)logWithFormat:(NSString *)format, ...;
+ (void)logWithFormat:(NSString *)format arguments:(va_list)args;
+ (void)fetchRemoteConfigWithKey:(NSString *)key
                       valueType:(TBCrashlyticsConfigValueType)type
                         Success:(void(^)(id responseValue))success
                         failure:(void(^)(void))failure;
+ (id)traceStartWithName:(NSString *)name;
+ (void)traceEndWithObject:(id)object;
+ (void)increateMetricWithObject:(id)object metric:(NSString *)metric value:(NSInteger)value;
+ (void)setCustomValue:(id)value forKey:(NSString *)key;
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (void)applicationWillEnterForeground:(UIApplication *)application;
+ (void)tb_operationsAfterLoginOrRegister;

@end

NS_ASSUME_NONNULL_END
