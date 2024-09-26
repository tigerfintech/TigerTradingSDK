//
//  TBHKStockMarketNetPurchaseModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/6/19.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/JSONModel.h>

#import "TBHKStockTurnOverTableViewCell.h"


NS_ASSUME_NONNULL_BEGIN


@protocol TBHKStockMarketNetPurchaseItemModel <NSObject>
@end

@interface TBHKStockMarketNetPurchaseItemModel : JSONModel <TBHKStockTurnOverTableViewCell>

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, strong) NSNumber *oneAmount;
@property (nonatomic, strong) NSNumber *threeAmount;
@property (nonatomic, strong) NSNumber *fiveAmount;
@property (nonatomic, strong) NSNumber *twentyAmount;

@property (nonatomic, assign) BOOL header;

@end

//@interface TBHKStockMarketNetPurchaseListModel : JSONModel
//
//@property (nonatomic, assign) NSInteger page;
//@property (nonatomic, assign) NSInteger totalPage;
//@property (nonatomic, copy) NSString *date;
//@property (nonatomic, copy) NSString *market;
//@property (nonatomic, strong) NSArray<TBHKStockMarketNetPurchaseItemModel> *items;
//
//@end

@interface TBHKStockMarketNetPurchaseModel : JSONModel

@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, assign) NSTimeInterval serverTime;

@property (nonatomic, assign) NSInteger page;
@property (nonatomic, assign) NSInteger totalPage;
@property (nonatomic, copy) NSString *date;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSArray<TBHKStockMarketNetPurchaseItemModel> *items;
@end

NS_ASSUME_NONNULL_END
