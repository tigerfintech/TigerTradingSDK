//
//  TBHomePageStocksModel.h
//  StockBusiness
//
//  Created by mashanli on 2022/9/20.
//  Copyright © 2022 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomePageStocksModel : TBBaseModel

@property (nonatomic, strong) NSNumber *serverTime;
@property (nonatomic, copy) NSDictionary *data;

@end


@protocol TBMarketConditionsIndicesModel,TBHomePageStocksEtfModel;

@interface TBHomePageStocksDataModel : TBBaseModel

@property (nonatomic, copy) NSArray<TBMarketConditionsIndicesModel> *indices;
@property (nonatomic, copy) NSArray<TBHomePageStocksEtfModel> *etfs;

@end


@interface TBHomePageStocksEtfModel : TBBaseModel

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *open;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *total;

@property (nonatomic, copy) NSArray<NSNumber *> *price;
@property (nonatomic, copy) NSDictionary *hourTrading; // 盘前盘后字典

@end

NS_ASSUME_NONNULL_END
