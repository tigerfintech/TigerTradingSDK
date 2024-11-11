//
//  NSCalendar+TBCalendar.h
//  CalendarX
//
//  Created by Tiger on 2018/6/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSCalendar (TBCalendar)

/**
 共享的阳历日历

 @return calendar
 */
+ (instancetype)sharedSolarCalendar;

/**
 获取给定日期的组件

 @param date 要计算的日期
 @return 日期组件
 */
- (NSDateComponents *)componentsFromDate:(NSDate *)date;

/**
 根据给定的年月日生成对应的日期类，时间为当地时间的中午12点

 @param year 年
 @param month 月
 @param day 日
 @return NSDate，模糊的日期，不精确
 */
- (NSDate *)dateWithYear:(NSUInteger)year month:(NSUInteger)month day:(NSUInteger)day;

- (NSDate *)tb_startOfDateFromComponents:(NSDateComponents *)components;
- (NSDate *)tb_endOfDateFromComponents:(NSDateComponents *)components;

/**
 根据给定的两个日期，计算间隔天数
 
 delta = toDate - fromDate

 @param fromDate 首个日期
 @param toDate 另一个日期
 @return NSInteger 间隔日期
 */
- (NSInteger)tb_deltaDayFromDate: (NSDate *)fromDate toDate: (NSDate *)toDate;

@end

@interface NSDateComponents (TBCalendar)

/**
 判断是否为同一天

 @param components 要比较的日期的组件类
 @return BOOL
 */
- (BOOL)sameDayTo:(NSDateComponents *)components;

@end

NS_ASSUME_NONNULL_END
