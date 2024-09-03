//
//  TBFutruesCombineModel.h
//  Stock
//
//  Created by luopengfei on 2018/7/6.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import "TBStockDetailViewControllerDelegate.h"
#import "TBStockDetailPriceTableViewCell.h"
#import "TBUStockAskBidTableViewCell.h"
#import "TBStockFundamentalCell.h"

@class TBFuturesContractModel;
@class TBMarketFullPriceItemModel;
@class TBStockDetailShortMarginModel;


/**
 期货详情页model
 */
@class TBStockDetailShortMarginModel;
@interface TBFutruesCombineModel : JSONModel <TBStockDetailViewControllerDelegate>

@property (nonatomic, strong) TBFuturesContractModel *contractModel;

@property (nonatomic, strong) TBMarketFullPriceItemModel *fullPriceModel;

@property (nonatomic, strong) TBStockDetailShortMarginModel *ominibusFuturesMarginModel;

@property (assign, nonatomic)  NSTimeInterval serverTime;

@property (nonatomic, readonly) NSArray *descriptionCellItems;

- (void)updateLatestPriceWithDic:(NSDictionary *)dic;

@end


@interface TBFutruesCombineModel (StockDetailPriceModel) <TBStockDetailPriceTableViewCell>
@end

@interface TBFutruesCombineModel (StockDetailAskBidModel) <TBUStockAskBidTableViewCell>
@end

@interface TBFutruesCombineModel (StockDetailFundamentalModel) <TBStockFundamentalCellDelegate>
@end
