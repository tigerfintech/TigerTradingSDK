//
//  TBKLineItem.h
//  Stock
//
//  Created by liwt on 15/1/16.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//


#import "TBBaseKLineItem.h"


@protocol TBKLineItem <NSObject>
@end
@interface TBKLineItem : TBBaseKLineItem

@property (nonatomic, strong) NSNumber<Optional> *open;
@property (nonatomic, strong) NSNumber<Optional> *close;
@property (nonatomic, strong) NSNumber<Optional> *high;
@property (nonatomic, strong) NSNumber<Optional> *low;
@property (nonatomic, strong) NSNumber<Optional> *amplitude; // 振幅
@property (nonatomic, strong) NSNumber<Optional> *openInt; // 未平仓量


@property (nonatomic, strong) NSNumber *settlement; // 昨结价，期货用
@property (nonatomic, strong) NSNumber *position;
@property (nonatomic, strong) NSNumber *positionChange;

@property (nonatomic, strong) NSNumber<Optional> *volume;//成交量
@property (nonatomic, strong) NSNumber<Optional> *amount;//成交额

@property (nonatomic, copy) NSString<Optional> *changePercentString; // 涨跌幅百分比

@property (nonatomic, strong) NSNumber<Optional> *buy;
@property (nonatomic, strong) NSNumber<Optional> *sell;
@property (nonatomic, strong) NSNumber<Optional> *warning;
@property (nonatomic, strong) NSNumber<Optional> *warningPrice;

@property (nonatomic, strong) NSNumber<Optional> *action;
@property (nonatomic, strong) NSNumber<Optional> *actionType;
@property (nonatomic, copy) NSString<Optional> *actionDes;
@property (nonatomic, copy) NSString<Optional> *actionName;

/// 附加属性, 保存JSONModel.toDictionary的结果, 避免重复计算, 提高K线图性能
@property (atomic, copy, nullable) NSDictionary *jsonDictionary;

@end
