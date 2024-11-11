//
//  TBLogger.h
//  StockGlobal
//
//  Created by swordzhou on 2020/6/1.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<CocoaLumberjack/CocoaLumberjack.h>)
#import <CocoaLumberjack/CocoaLumberjack.h>
#else
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBlogType) {
    TBlogTypeException = 1,         //异常
    TBlogTypeCode,                  //代码
    TBlogTypeBehavior,              //行为
    TBlogTypeSensor,                //埋点
    TBlogTypeBroadcast,             //广播
    TBlogTypeNetwork,               //网络
    TBlogTypeMQTT,                  //MQTT
};

@class TBPlatfromLoggerConfig;

@interface TBPlatformLogger : NSObject
#if __has_include(<CocoaLumberjack/CocoaLumberjack.h>)
@property (nonatomic, assign, class) DDLogLevel tbLogLevel;

@property (nonatomic, strong, class) NSDateFormatter *loggerDateFormater;
@property (nonatomic, strong, class) TBPlatfromLoggerConfig *config;
/**
 日志文件存储目录:${SandboxCachesDirectory}/Logs
 */
+ (NSString *)logsDirectory;

+ (void)setupLogger;

+ (void)log:(TBlogType)logType level:(DDLogLevel)level flag:(DDLogFlag)flag func:(const char *)func format:(NSString *)format, ... NS_FORMAT_FUNCTION(5,6);

+ (void)flush;
#endif
@end

NS_ASSUME_NONNULL_END
