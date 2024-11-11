//
//  TBRealTimeKLineItem.h
//  Stock
//
//  Created by liwt on 14/12/25.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <TBStockKit/TBBaseKLineItem.h>

@protocol TBRealTimeLineItem <NSObject>
@end
@interface TBRealTimeLineItem : TBBaseKLineItem

@property (nonatomic, strong) NSNumber<Optional> *price;
@property (nonatomic, strong) NSNumber<Optional> *avgPrice;
@property (nonatomic, strong) NSNumber<Optional> *direction;
@property (nonatomic, strong) NSNumber<Optional> *avg;

@property (nonatomic, strong) NSNumber *preClose;


/// 神奇九转
@property (nonatomic, strong) NSNumber *magicPoint;
@property (nonatomic, strong) NSNumber *magicColorType;

/// 到期收益率, 债券(BOND)特有
@property (nonatomic, strong) NSNumber<Optional> *ytm;
@property (nonatomic, strong) NSNumber<Optional> *dayOfWeek;
@property (nonatomic, strong) NSNumber<Optional> *mid;

@end
