//
//  TBDateYearObject.h
//  StockBusiness
//
//  Created by mashanli on 2023/2/8.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TBDateMonthItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBDateYearObject : NSObject

@property (nonatomic, assign, readonly) NSUInteger year;    // 年份
@property (nonatomic, copy, readonly) NSArray <TBDateMonthItem *> *monthItems; //每个月份的实体类

- (instancetype)initWithYear:(NSUInteger)year;
- (instancetype)nextYear;      // 计算下年
- (instancetype)previousYear;  // 计算下月

@end

NS_ASSUME_NONNULL_END
