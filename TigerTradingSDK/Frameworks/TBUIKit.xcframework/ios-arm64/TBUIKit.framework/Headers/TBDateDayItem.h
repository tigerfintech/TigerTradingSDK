//
//  TBDateDayItem.h
//  StockBusiness
//
//  Created by mashanli on 2023/2/8.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TBCollectionViewCellItem.h>

@interface TBDateDayItem : TBCollectionViewCellItem

@property (nonatomic, assign, readonly) NSUInteger locatedMonth;            // 一个月份的日历可能包含上下月的日子，需要处理
@property (nonatomic, strong, readonly) NSDate *date;                       // 当前的日期
@property (nonatomic, strong, readonly) NSDateComponents *dateComponents;   // 当前日期的组件

@property (nonatomic, assign, readonly) NSInteger year;                 // 年
@property (nonatomic, assign, readonly) NSInteger month;                // 月
@property (nonatomic, assign, readonly) NSInteger day;                  // 日
@property (nonatomic, assign, readonly) NSInteger weekday;              // 周几
@property (nonatomic, assign, readonly) NSInteger weekdayOrdinal;       // 顺序的第几周
@property (nonatomic, assign, readonly) NSInteger quarter;              // 季度
@property (nonatomic, assign, readonly) NSInteger weekOfMonth;          // 月中的第几周
@property (nonatomic, assign, readonly) NSInteger weekOfYear;           // 年中的第几周
@property (nonatomic, assign, readonly) NSInteger yearForWeekOfYear;

@property (nonatomic, assign) BOOL selected;        // 对应的cell是否被选择
@property (nonatomic, assign) BOOL isToday;         // 是否是今天
@property (nonatomic, assign) BOOL isSelectForbid;         // 点击被禁止掉，默认NO，不会禁止
@property (nonatomic, copy) NSArray *financeDatas;

@property (nonatomic, copy) NSArray<NSDictionary *> *customeDatas;

@property (nonatomic, copy, readonly) NSString *weekdayString;

@property (nonatomic, assign) BOOL isPnLCalendar;

/**
 初始化方法

 @param date 日期
 @param month 所在的月份
 @return self
 */
- (instancetype)initWithDate:(NSDate *)date locatedMonth:(NSUInteger)month;

/// 相同条件：年月日相同
- (BOOL)isSameDayWithItem:(TBDateDayItem *)item;



@end
