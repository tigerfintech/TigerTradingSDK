//
//  TBStockDetailBaseModel.h
//  Stock
//
//  Created by luopengfei on 2018/8/9.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

/**
 个股详情页base model
 */
@interface TBStockDetailBaseModel : JSONModel

@property (nonatomic, copy) NSString *symbol;

/**
 直接使用即可，内部getter做检查:
 market如果为nil，会根据symbol进行判断所属market
 */
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSNumber *contractId; // 组合期权 持仓策略显示时需要

@property (nonatomic, assign) double latestPrice;
@property (nonatomic, assign) double preClose;
@property (nonatomic, copy) NSString *secType; // STK 股票, OPT 期权，WAR：窝轮 IOPT：牛熊证 FUT:期货

/**
 是否停牌
 0: 正常
 3: 停牌
 4: 退市
 */
@property (nonatomic, assign) NSInteger halted;


@property (nonatomic, assign) NSInteger maxScale;//标的精度,外汇和债券每个标的精度可能不一样
/**
 merge 数据
 封装调用JSONModel提供‘mergeFromDictionary:useKeyMapping:error:’方法

 @param dict 新数据容器
 */
- (void)updateModelValueWithDictionary:(NSDictionary *)dict;


#pragma mark ----------------------
#pragma mark -计算涨跌、颜色;展示价格、涨跌
#pragma mark ----------------------
@property (nonatomic, readonly) NSString *displayLatestPrice;
@property (nonatomic, readonly) NSString *displayPreClose;
@property (nonatomic, readonly) NSString *displayChange;
@property (nonatomic, readonly) NSString *displayChangeRatio;
@property (nonatomic, readonly) UIColor *priceColor;

@property (nonatomic, readonly) double change;
@property (nonatomic, readonly) double changePercent;

@end
