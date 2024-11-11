//
//  TBStockTodayChangeModel.h
//  Stock
//
//  Created by 王灵博 on 2020/7/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>
//#import "TBBroaderMarketTipViewCell.h"

NS_ASSUME_NONNULL_BEGIN
@interface TBStockTodayChangeDetailModel : TBBaseModel
@property(nonatomic, copy)NSString *activeName;
@property(nonatomic, copy)NSString *brief;
@property(nonatomic, copy)NSString *direction;
@property(nonatomic, strong)NSNumber *latestPrice;
@property(nonatomic, copy)NSString *market;
@property(nonatomic, copy)NSString *name;
@property(nonatomic, strong)NSNumber *quoteChange;
@property(nonatomic, strong)NSNumber *currQuoteChange;
@property(nonatomic, copy)NSString *secType;
@property(nonatomic, copy)NSString *symbol;
@property(nonatomic, strong)NSNumber *timeStamp;
@property (nonatomic, copy) NSString *marketStatus;
@property (nonatomic, copy) NSDictionary *articleItemData;
@end
@protocol TBStockTodayChangeDetailModel;
@interface TBStockTodayChangeDataModel : TBBaseModel
@property(nonatomic, copy)NSArray <TBStockTodayChangeDetailModel> *activeResultList;
@property(nonatomic, assign)NSInteger index;
@end
@protocol TBStockTodayChangeDataModel;
@interface TBStockTodayChangeModel : TBBaseModel
@property(nonatomic, assign)NSInteger code;
@property(nonatomic, strong)TBStockTodayChangeDataModel *data;
@property(nonatomic, copy)NSString *message;
@property(nonatomic, strong)NSNumber *serverTime;
@end

NS_ASSUME_NONNULL_END
