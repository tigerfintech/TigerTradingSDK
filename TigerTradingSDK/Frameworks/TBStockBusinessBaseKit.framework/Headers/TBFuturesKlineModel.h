//
//  TBFuturesKlineModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>
#import <TBStockKit/TBKLineItem.h>



/*
 
 k线数据
 
 */




NS_ASSUME_NONNULL_BEGIN

@interface TBFuturesKlineModel : TBBaseModel

@property (nonatomic, copy) NSString *contractCode; // 合约代码
@property(nonatomic, assign) NSInteger serverTime;  // 服务器当前的时间和1970年1⽉1⽇的时间差的毫秒数
//@property(nonatomic, copy) NSString * _Nullable contractId;   // 请求K线数据的合约ID
@property(nonatomic, assign) NSInteger priceOffset; // 价格偏移量，priceOffset=6代表需要偏移的字段原来值乘以10的6次⽅
@property(nonatomic, copy) NSString * _Nullable period;    // day/week/month/year/min/5min/15min/30min/60min
@property(nonatomic, retain) NSArray<TBKLineItem> * _Nullable items;

@end

NS_ASSUME_NONNULL_END
