//
//  TBDateMonthItem.h
//  StockBusiness
//
//  Created by mashanli on 2023/2/8.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBCollectionViewCellItem.h"

@interface TBDateMonthItem : TBCollectionViewCellItem

@property (nonatomic, strong, readonly) NSDate *date;                       // 当前的日期
@property (nonatomic, strong, readonly) NSDateComponents *dateComponents;   // 当前日期的组件

@property (nonatomic, assign, readonly) NSInteger year;                 // 年
@property (nonatomic, assign, readonly) NSInteger month;                // 月

@property (nonatomic, copy, readonly) NSString *monthString; //月份
@property (nonatomic, assign) BOOL selected;        //对应的cell是否被选择
@property (nonatomic, assign) BOOL isSameMonth; //当月

@property (nonatomic, copy) NSArray *financeDatas;
@property (nonatomic, assign) BOOL isPnLCalendar;

@property (nonatomic, copy) NSArray<NSDictionary *> *customeDatas;

- (instancetype)initWithDate:(NSDate *)date;
/// 相同条件：年月相同
- (BOOL)isSameMonthWithItem: (TBDateMonthItem *)item;

@end
