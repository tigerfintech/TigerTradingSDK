//
//  TBStockInfoAskBidIPOModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/7/15.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockInfoAskBidIPODataModel : JSONModel

@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, assign) double askPrice;
@property (nonatomic, assign) double bidPrice;
@property (nonatomic, assign) double askSize;
@property (nonatomic, assign) double bidSize;

/// bqt 竞价高价
@property (nonatomic, assign) double high;

///bqt 竞价低价
@property (nonatomic, assign) double low;

@end

@interface TBStockInfoAskBidIPOModel : JSONModel

@property (nonatomic, assign) NSTimeInterval serverTime;

@property (nonatomic, assign) NSInteger ret;

/**
 data 为 nil展示竞价
 data 有值展示竞价
 */
@property (nonatomic, strong) TBStockInfoAskBidIPODataModel *data;

@end

NS_ASSUME_NONNULL_END
