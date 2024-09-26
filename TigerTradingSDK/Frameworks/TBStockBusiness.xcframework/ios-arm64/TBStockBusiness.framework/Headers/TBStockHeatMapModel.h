//
//  TBStockHeatMapModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/1.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockHeatMapItemModel <NSObject>
@end
@interface TBStockHeatMapItemModel : JSONModel

@property (nonatomic, strong) NSNumber *changeRate;
@property (nonatomic, copy) NSString *industry;
@property (nonatomic, copy) NSString *bkCode;
@property (nonatomic, copy) NSString *industryId;
@property (nonatomic, strong) NSNumber *marketValue;


@end

@interface TBStockHeatMapModel : JSONModel

@property (nonatomic, copy) NSArray<TBStockHeatMapItemModel> *data;

@property (nonatomic, copy) NSArray<TBStockHeatMapItemModel> *items;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, assign) NSTimeInterval serverTime;


@end

NS_ASSUME_NONNULL_END
