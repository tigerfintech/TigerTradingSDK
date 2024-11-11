//
//  TBCombineOptionInfoDetailItem.h
//  Stock
//
//  Created by mashanli on 2023/6/15.
//  Copyright (c) 2023 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import "TBOptionItem.h"
#import "TBMultiOptionItem.h"

@interface TBCombineOptionInfoDetailItem : JSONModel

@property (nonatomic, copy) NSString *reqId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *latestTime;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *open;
@property (nonatomic, strong) NSNumber *high;
@property (nonatomic, strong) NSNumber *low;
@property (nonatomic, strong) NSNumber *preClose;

@property (nonatomic, strong) NSNumber *askSize;
@property (nonatomic, strong) NSNumber *bidSize;
@property (nonatomic, strong) NSNumber *askPrice;
@property (nonatomic, strong) NSNumber *bidPrice;

@property (nonatomic, strong) NSNumber *dividePrice;
@property (nonatomic, strong) NSNumber *ratesBonds;
@property (nonatomic, copy) NSString *volatility;
@property (nonatomic, strong) NSNumber *multiplier;
@property (nonatomic, strong) NSNumber *deliverableShares;
@property (nonatomic, copy) NSString *marketStatus;
@property (nonatomic, assign) BOOL isOld;
@property (nonatomic, assign) BOOL isIndexOption;

@property (nonatomic, copy) NSArray<TBOptionIndiceQuoteModel> *stockQuotes;
@property (nonatomic, copy) NSArray<NSArray<NSNumber *> *> *openAndCloseTimeList; //交易时间区间
@property (nonatomic, copy) NSArray<TBOptionChainAskBidRetModel> *originalQuotes;
@property (nonatomic, copy) NSDictionary *chainIVs;

@property (nonatomic, copy) NSString *notice;//提示信息
//minutes，K线分时
@property (nonatomic, copy) NSArray<NSDictionary *> *minutes;

@property (nonatomic, copy) NSString *symbol;//非server返回

@end

