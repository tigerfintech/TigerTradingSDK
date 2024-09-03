//
//  TBDateFormatManager.h
//  ACETelPrompt
//
//  Created by JustLee on 2020/5/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 主要城市时区对照表：https://blog.csdn.net/u011974797/article/details/78477174
static NSString *const kLondonTimeZoneID = @"Europe/London";
static NSString *const kHKTimeZoneID = @"Asia/Hong_Kong";
static NSString *const kBJTimeZoneID = @"Asia/Shanghai";
static NSString *const kUSTimeZoneID = @"America/New_York";
static NSString *const kJPTimeZoneID = @"Asia/Tokyo";

// 新加坡时区
static NSString *const kSGPTimeZoneID = @"Asia/Singapore";
/// 澳大利亚
static NSString *const kAUTimeZoneID = @"Australia/Sydney";
/// 新西兰
static NSString *const kNZTimeZoneID = @"Pacific/Auckland";

@interface TBDateFormatManager : NSObject

/// 默认转换日期字符串为指定格式，默认为美区
/// @param dateString 当前日期
/// @param origin 当前日期的格式
/// @param target 目标日期格式
+ (NSString *)dateStringFromString:(NSString *)dateString originDateFormat:(NSString *)origin targetDateFormat:(NSString *)target;

/// 指定市场转换日期字符串格式
/// @param dateString 当前日期
/// @param origin 当前日期格式
/// @param target 目标日期格式
/// @param market 市场类型
+ (NSString *)dateStringFromString:(NSString *)dateString originDateFormat:(NSString *)origin targetDateFormat:(NSString *)target market:(NSString *)market;

/// 指定时区转换日期格式
/// @param dateString 当前日期
/// @param origin 当前日期格式
/// @param target 目标日期格式
/// @param zone 时区标识
+ (NSString *)dateStringFromString:(NSString *)dateString originDateFormat:(NSString *)origin targetDateFormat:(NSString *)target timeZone:(NSString *)zone;


/// 转换时间戳为特定格式日期
/// @param stamp 时间戳
/// @param format 格式
+ (NSString *)dateStringWithStamp:(NSTimeInterval)stamp formatString:(NSString *)format;

/// 通过市场类型转换时间戳
/// @param stamp 时间戳
/// @param format 格式
/// @param market 市场类型
+ (NSString *)dateStringWithStamp:(NSTimeInterval)stamp formatString:(NSString *)format market:(NSString *)market;

/// 通过特定时区转换时间戳
/// @param stamp 时间戳
/// @param format 格式
/// @param zone 时区标识
+ (NSString *)dateStringWithStamp:(NSTimeInterval)stamp formatString:(NSString *)format timeZone:(NSString *)zone;

/// 通过特定时区转换时间戳
/// @param stamp 时间戳
/// @param format 格式
/// @param zoneID 时区ID
+ (NSString *)dateStringWithStamp:(NSTimeInterval)stamp formatString:(NSString *)format timeZoneID:(NSString *)zoneID;

/// 根据日期字符串获取时间戳 15位时间戳
/// @param format 日期格式
/// @param market 市场类型
+ (NSTimeInterval)stampWithDateString:(NSString *)dateString formatString:(NSString *)format market:(NSString *)market;


/// 根据市场返回dateformatter
///@param market 市场类型
+ (NSDateFormatter *)formatterWithmarket:(NSString *)market;

@end

@interface TBDateFormatManager (TBMarketZone)

//时区描述文案
+ (NSDictionary *)marketTimeZoneDesMap;
+ (NSDictionary *)marketTimeZoneSimpleMap;//简称

//时区标识
+ (NSDictionary *)marketTimeZoneMap;

/**
 根据market返回对应的timezone，默认返回系统当前所在地时区
 */
+ (NSTimeZone *)timeZoneWithMarket:(NSString *)market;

@end


@interface NSString (DateFormat)

/// 强制转换
- (NSString *)enForceFormatString;

/// 默认转换为yyyy-MM-dd转 yyyy/MM/dd
- (NSString *)enDateFormatString;

/// 只转日期MM-dd转MM/dd
- (NSString *)enMDDateFormatString;

- (NSString *)enYMDateFormatString;

@end

NS_ASSUME_NONNULL_END
