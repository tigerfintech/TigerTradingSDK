//
//  TBMonthObject.h
//  CalendarX
//
//  Created by Tiger on 2018/6/19.
//

#import <Foundation/Foundation.h>

@class TBDayItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBMonthObject : NSObject

/**
 初始化方法，内部会根据年月计算这个月在日历中展示的第一天到最后一天的实体类所有内容

 @param year 年份
 @param month 月份
 @param weeks 每屏几周
 @return self
 */
- (instancetype)initWithYear:(NSUInteger)year month:(NSUInteger)month weeks:(NSUInteger)weeks;

@property (nonatomic, assign, readonly) NSUInteger year;    // 年份
@property (nonatomic, assign, readonly) NSUInteger month;   // 月份
@property (nonatomic, copy, readonly) NSArray <TBDayItem *> *dayItems;    // 每个日子的实体类

- (instancetype)nextMonth;      // 计算下个月
- (instancetype)previousMonth;  // 计算上个月

@end

NS_ASSUME_NONNULL_END
