//
//  TBHKStockConnectTurnoverTopModel.h
//  Stock
//
//  Created by luopengfei on 2019/1/30.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/JSONModel.h>


NS_ASSUME_NONNULL_BEGIN

@protocol TBHKStockConnectTurnoverTopItemModel <NSObject>
@end

@interface TBHKStockConnectTurnoverTopItemModel : JSONModel 

@property (nonatomic, assign) double buyTurnover;
@property (nonatomic, assign) double sellTurnover;
@property (nonatomic, assign) double totalTurnover;

@property (nonatomic, assign) NSInteger rankCount;


@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *symbol;

@property (nonatomic, assign) BOOL header;

@end

@interface TBHKStockConnectTurnoverTopModel : JSONModel

@property (nonatomic, copy) NSString *date;
@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy) NSArray *historyDates;

@property (nonatomic, copy) NSArray<TBHKStockConnectTurnoverTopItemModel> *items;

@end

NS_ASSUME_NONNULL_END
