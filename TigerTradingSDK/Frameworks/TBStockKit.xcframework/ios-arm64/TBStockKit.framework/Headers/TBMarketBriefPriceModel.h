//
//  TBMarketBriefPriceModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>


/*
 
 
 
 
 
 合约价格、信息的短连接请求到得数据
 
 
 
 
 
 
 */


NS_ASSUME_NONNULL_BEGIN

@class TBMarketBriefPriceItemModel;

@interface TBMarketBriefPriceModel : TBBaseModel

@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy) NSArray <TBMarketBriefPriceItemModel *> *items;

@end

@interface TBMarketBriefPriceItemModel : TBBaseModel

@property (copy, nonatomic) NSString *contractCode;
@property (copy, nonatomic) NSString *contractId;
@property (assign, nonatomic) NSInteger lastPrice;
@property (assign, nonatomic) NSInteger preSettlement;
@property (assign, nonatomic) NSInteger preClose;
@property (assign, nonatomic) NSInteger priceOffset;
@property (assign, nonatomic) NSUInteger time;


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////   辅助计算属性

@property (nonatomic, strong, readonly) NSNumber *quotesLastPrice;
@property (nonatomic, strong, readonly) NSNumber *quotesPreSettlement;
@property (nonatomic, strong, readonly) NSNumber *quotesPreClose;
@property (nonatomic, strong, readonly) NSNumber *quotesProfit;             // 盈亏
@property (nonatomic, strong, readonly) NSNumber *profitRatio;              // 盈亏比例

@end

NS_ASSUME_NONNULL_END
