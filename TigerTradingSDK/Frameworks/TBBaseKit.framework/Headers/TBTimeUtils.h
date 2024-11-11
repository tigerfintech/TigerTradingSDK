//
//  TBTimeUtils.h
//  Stock
//
//  Created by yangfan on 17/1/12.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBTimeUtils : NSObject

+ (NSInteger)getDateHour:(NSDate *)date;

//将8位时间值转为NSDate 例如:20180101
+ (NSDate *)systemTimeZoneDateFromDateInterger:(NSInteger)time;

//将标准时间转为系统时区时间
+ (NSDate *)covertDateToSystemZoneDate:(NSDate *)date;

//将NSDate转为8位时间值 例如:20180101
+ (NSInteger)dateToInteger:(NSDate *)date;

//获取指定时间的星期值从1到7
+ (NSInteger)weekdayOfDate:(NSDate *)date;

//获取当前星期几
+ (NSString *)weekdayStringOfDate:(NSDate *)date;
//两个时间是否属于同一周
+ (BOOL)isSameWeekCompare:(NSDate *)time withTime:(NSDate *)newTime;

@end
