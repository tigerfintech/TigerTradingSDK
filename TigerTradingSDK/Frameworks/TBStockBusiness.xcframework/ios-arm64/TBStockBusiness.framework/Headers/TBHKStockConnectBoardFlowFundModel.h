//
//  TBHKStockConnectBoardFlowFundModel.h
//  Stock
//
//  Created by luopengfei on 2019/1/30.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBHKStockConnectStockFundModel <NSObject>
@end
@interface TBHKStockConnectStockFundModel : JSONModel
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, assign) NSInteger changeShares;


@end

@protocol TBHKStockConnectBoardFlowsItemModel <NSObject>
@end

@interface TBHKStockConnectBoardFlowsItemModel : JSONModel 

@property (nonatomic, copy) NSString *boardName;
@property (nonatomic, copy) NSString *bkCode;


@property (nonatomic, copy) NSArray<TBHKStockConnectStockFundModel> *items;

//@property (nonatomic, assign) BOOL header;
//@property (nonatomic, assign) BOOL isInFlow;

@property (nonatomic, assign) NSInteger totalChangeShares;
@property (nonatomic, assign) NSInteger maxTotalChangeShares;

@end

@interface TBHKStockConnectBoardFlowFundModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy) NSString *date;

@property (nonatomic, copy) NSArray<TBHKStockConnectBoardFlowsItemModel> *fundFlows;

@property (nonatomic, assign) NSInteger page;
@property (nonatomic, assign) NSInteger totalPage;

- (NSInteger)maxTotalChangeShares;

@end

NS_ASSUME_NONNULL_END
