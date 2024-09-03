//
//  TBMarketWarningModel.h
//  Stock
//
//  Created by yangfan on 2020/2/17.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBStockWarningDisplayModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockWarningDisplayModel;

@interface TBMarketWarningModel : TBStockWarningDisplayStockInfo

@property (nonatomic, assign) NSInteger totalSize;
@property (nonatomic, assign) NSInteger totalPage;
@property (nonatomic, copy) NSArray<TBStockWarningDisplayModel> * item;

@end

NS_ASSUME_NONNULL_END
