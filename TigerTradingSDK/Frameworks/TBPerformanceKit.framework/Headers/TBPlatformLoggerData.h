//
//  TBLoggerData.h
//  StockGlobal
//
//  Created by swordzhou on 2020/11/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBPlatfromLoggerConfig.h"

NS_ASSUME_NONNULL_BEGIN

/**
 日志文件存放目录如下:${SandboxCachesDirectory}/[${uuid}|"Guest"]+_Logs/${yyyy-MM-dd}/xxx.log
 */
@interface TBPlatformLoggerData : NSObject
#if __has_include(<CocoaLumberjack/CocoaLumberjack.h>)

/// 使用config进行初始化
/// @param config config description
+ (TBPlatformLoggerData *)logerDataWithConfig:(TBPlatfromLoggerConfig *)config;

/**将yyyy-MM-dd的日期转化为NSDate
 @param dateString 日期
 @return an instance of NSDate
 */
- (NSDate *)dateWithFormatedString:(NSString *)dateString;

/**将date转化为yyyy-MM-dd格式的string
 @param date 日期
 @return 返回yyyy-MM-dd格式化后的日志日期数据
 */
- (NSString *)logFormattedDateString:(NSDate *)date;

/**将date转化为yyyy-MM-dd格式的string数组
 @param dates NSDate 数组
 @return 返回yyyy-MM-dd格式化后的日志日期数据
 */
- (NSArray *)displayedLogDateStrings:(NSArray *)dates;

/**按天分组，返回所有日志的NSDate数据，日志文件存放目录如下:${SandboxCachesDirectory}/[${uuid}|"Guest"]+_Logs/${yyyy-MM-dd}/xxx.log
 遍历${SandboxCachesDirectory}/[${uuid}|"Guest"]+_Logs/目录下所有的目录为${yyyy-MM-dd}的子目录下的日志文件信息
 @return 所有日志的日期
 */
- (NSArray <NSDate *> *)logDates;

/**按日期获取日志数据
 @param date 指定的日期
 @return 返回指定日期对应的日志数据，不存在返回nil
 */
- (NSData *)logDataWithDate:(NSDate *)date;

/**按日期获取日志内容
 @param date 指定的日期
 @return 返回指定日期的日志内容，不存在返回nil
 */
- (NSString *)logContentWithDate:(NSDate *)date;

/**按日期获取日志内容
 @param dateString 指定的日期yyyy-MM-dd
 @return 返回指定日期的日志内容，不存在返回nil
 */
- (NSString *)logContentWithFormatedDateString:(NSString *)dateString;

- (BOOL)hasLogDataWithFormatedDateString:(NSString *)dateString;

/**将指定日期的日志上传到服务器
 @param log 日志内容
 @param date 指定的日期 yyyy-MM-dd
 */
- (void)uploadLog:(NSString *)log date:(NSString *)date complection:(void(^)(BOOL success, NSString *fileUrl))completion;

/**
 * 上传当天日志
 * @param completion 完成回调 fileUrl是绝对路径，可以直接访问下载
 */
- (void)uploadTodayLog:(void(^)(BOOL success,  NSString *_Nullable fileUrl, NSString *error))completion;

/// 清除log日志
/// 只会删除当前用户日志
+ (void)clearLogCache;

- (void)loadData;
#endif
@end

NS_ASSUME_NONNULL_END
