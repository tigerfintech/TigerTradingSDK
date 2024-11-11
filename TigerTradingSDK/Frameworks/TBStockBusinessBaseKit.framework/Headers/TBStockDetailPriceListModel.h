//
//  TBStockDetailPriceListModel.h
//  Stock
//
//  Created by luopengfei on 2018/5/24.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@protocol TBStockDetailPriceListItemModel <NSObject>
@end
@interface TBStockDetailPriceListItemModel : JSONModel

@property (nonatomic, strong) NSNumber *total;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSNumber *buy;
@property (nonatomic, strong) NSNumber *sell;
@property (nonatomic, strong) NSNumber *mid;
@property (nonatomic, strong) NSNumber *percent;

@property (nonatomic, copy) NSString *market;


/**
 展示价格，主要用于期货，根据合约类型转过的价格展示
 */
@property (nonatomic, copy) NSString *displayPrice;


@end

@interface TBStockDetailPriceListModel : JSONModel

@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, strong) NSNumber *page;
@property (nonatomic, strong) NSNumber *serverTime;
@property (nonatomic, strong) NSNumber *totalPage;
@property (nonatomic, copy) NSArray<TBStockDetailPriceListItemModel> *data;

@end
