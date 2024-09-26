//
//  TBStockMarketCalendarModel.h
//  Stock
//
//  Created by 王灵博 on 2020/7/23.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>
#import "TBMarketConditionsUntils.h"
//#import "TBNewStockCalendarListTableViewCell.h"
NS_ASSUME_NONNULL_BEGIN


@interface TBStockFinancCalendarModel : TBBaseModel
@property(nonatomic, strong)NSNumber *availableFundLimit;
@property(nonatomic, strong)NSNumber *financingId;
@property(nonatomic, strong)NSNumber *interestRate;
@property(nonatomic, strong)NSNumber *isAvailable;
@property(nonatomic, strong)NSNumber *marginRate;
@property(nonatomic, strong)NSNumber *type;
@end

@interface TBStockfreeCalendarModel : TBBaseModel
@property(nonatomic, strong)NSNumber *freeRate;
@property(nonatomic, strong)NSNumber *sinceAmount;
@property(nonatomic, strong)NSNumber *toAmount;
@end



@protocol TBStockFinancCalendarModel,TBStockfreeCalendarModel;
@interface TBStockDetailCalendarModel : TBBaseModel
@property(nonatomic, strong)NSNumber *itemId;
@property(nonatomic, copy)NSString *type;
@property(nonatomic, copy)NSString *ipoName;
@property(nonatomic, copy)NSString *symbol;
@property(nonatomic, copy)NSString *companyName;
@property(nonatomic, copy)NSString *market;
@property(nonatomic, copy)NSString *currency;
@property(nonatomic, copy)NSString *status;
@property(nonatomic, assign)TBNewStockBuyStatus  buyStatus;
@property(nonatomic, strong)NSNumber *minQty;
@property(nonatomic, copy)NSString *underwriter;
@property(nonatomic, strong)NSNumber *lotSize;
@property(nonatomic, strong)NSNumber *expectedOfferingSize;
@property(nonatomic, strong)NSNumber *openingDate;
@property(nonatomic, strong)NSNumber *closingDate;
@property(nonatomic, strong)NSNumber *allotmentDate;
@property(nonatomic, strong)NSNumber *listDate;
@property(nonatomic, strong)NSNumber *latestPrice;
@property(nonatomic, assign)BOOL marginable;
@property(nonatomic, strong)NSNumber *marginRate;
@property(nonatomic, strong)NSNumber *minPrice;
@property(nonatomic, strong)NSNumber *maxPrice;
@property(nonatomic, strong)NSNumber *allocationPrice;
@property(nonatomic, copy)NSString *prospectusUrl;
@property(nonatomic, strong)NSNumber *subscribed;
@property(nonatomic, strong)NSNumber *itemSigned;
@property(nonatomic, strong)NSNumber *finra5130;
@property(nonatomic, strong)NSNumber *finra5131;
@property(nonatomic, strong)NSNumber *winningRate;
@property(nonatomic, strong)NSNumber *interestRate;
@property(nonatomic, assign)BOOL isSupportFreeInterest;
@property(nonatomic, assign)BOOL maxFreeInterestAmount;
@property(nonatomic, copy)NSArray <TBStockfreeCalendarModel>*freeInterestSteps;
@property(nonatomic, copy)NSArray <TBStockFinancCalendarModel>*financingInfos;
@property(nonatomic, strong)NSNumber *subscribedRatio;
@property(nonatomic, strong)NSNumber *forecastRatio;
@property(nonatomic, assign)BOOL booking;
@property(nonatomic, strong)NSNumber *raiseMoney;
@property(nonatomic, strong)NSNumber *totalMargin;
@property(nonatomic, strong)NSNumber *quoteInfoUpdatedAt;
@property(nonatomic, strong)NSNumber *prospectusUpdatedAt;
@property(nonatomic, assign)BOOL recommend;
@property(nonatomic, strong)NSNumber *executingBrokerClosingDate;
@property(nonatomic, copy)NSString *hintInfo;
@property(nonatomic, copy)NSString *hintInfoUrl;
@property(nonatomic, strong)NSNumber *forecastMarketValue;
//@property(nonatomic, strong)NSArray *allowedQuantities;
@end

@protocol TBStockDetailCalendarModel;
@interface TBStockMarketCalendarModel : TBBaseModel
@property(nonatomic, copy)NSArray <TBStockDetailCalendarModel>*data;
@property(nonatomic, copy)NSString *msg;
@property(nonatomic, copy)NSString *status;
@property(nonatomic, strong)NSNumber *timestamp;
@property(nonatomic, strong)NSNumber *is_succ;
@end

@interface TBStockMianDetailCalendarModel : TBBaseModel
@property(nonatomic, strong)TBStockDetailCalendarModel *data;
@property(nonatomic, copy)NSString *msg;
@property(nonatomic, copy)NSString *status;
@property(nonatomic, strong)NSNumber *timestamp;
@end

NS_ASSUME_NONNULL_END
