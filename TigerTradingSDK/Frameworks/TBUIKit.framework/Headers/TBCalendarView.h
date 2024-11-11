//
//  TBCalendarView.h
//  TBUIKit
//
//  Created by 王昌阳 on 2023/5/29.
//

#import "TBView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBCalendarViewType) {
    TBCalendarViewTypeDay = 0,
    TBCalendarViewTypeWeek,
    TBCalendarViewTypeMonth,
};

typedef NS_ENUM(NSUInteger, TBCalendarViewDisplayType) {
    TBCalendarViewDisplayTypeDefault = 0,
    TBCalendarViewDisplayTypePnL,///< 盈亏日历
};

@protocol TBCalendarViewDelegate <NSObject>

@optional
/**
 日历列表数据
 startDate 日期
 dimension 维度
 */
- (void)fetchCalendarListData:(NSDate *)date calendarViewType:(TBCalendarViewType)calendarViewType;

//日历打点数据
- (void)fetchCalendarTypeData:(NSDate *)date;

@end

@interface TBCalendarView : TBView

@property (nonatomic, assign) TBCalendarViewDisplayType calendarDisplayType;

@property (nonatomic, assign) TBCalendarViewType calendarViewType;

@property (nonatomic, weak) id<TBCalendarViewDelegate> delegate;

- (instancetype)initWithDisplayType:(TBCalendarViewDisplayType)displayType;

- (void)refreshData:(NSDictionary *)datas NSDate:(NSDate *)date;

- (void)updateSelectedDate:(NSDate *)date;

@property (nonatomic, copy) void(^selectItemBlock)(NSArray * _Nullable datas);

@end

NS_ASSUME_NONNULL_END
