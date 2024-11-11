//
//  TBAxisValueFormatter.h
//  Stock
//
//  Created by luopengfei on 2018/3/5.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@import ChartKLineView;

/**
 处理Charts IChartAxisValueFormatter
 */
@interface TBAxisValueFormatter : NSObject <IChartAxisValueFormatter>

- (instancetype)initWithXAxis:(NSArray *)xaxis;

@property (nonatomic, copy) NSArray *axisArray;

/**
 处理年月日

 @param xAxis 原X数组
 @param separatedString 分割字符
 @return 处理过X数组
 */
+ (NSArray<NSString *> *)formatDate:(NSArray *)xAxis separatedString:(NSString *)separatedString;

+ (NSArray *)formatOnlyYearDate:(NSArray *)xAxis separatedString:(NSString *)separatedString;
+ (NSArray *)formatOnlyDayDate:(NSArray *)xAxis separatedString:(NSString *)separatedString;

@end
