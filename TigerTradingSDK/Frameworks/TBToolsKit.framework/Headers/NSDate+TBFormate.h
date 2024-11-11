//
//  NSDate+TBFormate.h
//  Stock
//
//  Created by dull grass on 1/15/20.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (TBFormate)

- (NSDate *)tbDateByAddingMonths:(NSInteger)months;

- (NSDate *)tbDateByAddingWeeks:(NSInteger)weaks;

- (NSDate *)tbDateByAddingDays:(NSInteger)days;

// 转换为美国东部时间 EST/EDT, format为美国date format常量
- (NSString *)tup_toEtYmdDateString;
- (NSString *)tup_toEtMdDateString;
- (NSString *)tup_toEtHmsDateString;
- (NSString *)tup_toETDateStringWithFormat:(NSString *)format;

+ (NSDate *)tup_dateWithYmdDateString:(NSString *)dateString;

/// 计算两个日期时间间隔天数，以日期中的日为准，如2019/02/09 10:00:00 2019/02/10 8:00:00，两个日期向查未满24小时，但返回值是-1
/// @param date 日期
- (NSInteger)tup_estDaysFrom:(NSDate *)date;

- (NSString *)monthString;

@end

NS_ASSUME_NONNULL_END
