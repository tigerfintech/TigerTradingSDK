//
//  TBMarketWideDetailModel.h
//  Stock
//
//  Created by luopengfei on 2018/3/19.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
@import ChartKLineView;

@protocol TBMarketDailyQuotaBalanceItem <NSObject>
@end
@interface TBMarketDailyQuotaBalanceItem : JSONModel

@property (nonatomic, strong) NSNumber *askAccumulatedTurnover;         //卖出额
@property (nonatomic, strong) NSNumber *tradeTotalValue;
@property (nonatomic, strong) NSNumber *dailyBalance;
@property (nonatomic, strong) NSNumber *time;
@property (nonatomic, strong) NSNumber *bidAccumulatedTurnover;         //买入额

@end

@interface TBMarketDailyQuotaBalanceModel : JSONModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *limit;

@property (nonatomic, copy) NSArray<TBMarketDailyQuotaBalanceItem> *data;

- (NSArray<NSArray<NSNumber *> *> *)dailyQuoteBalaceData;

@property (nonatomic, readonly) NSArray *xVals;

@property (nonatomic, readonly) ChartLimitLine *limitLine;

@end

@interface TBMarketConstituentsModel : JSONModel

@property (nonatomic, copy) NSArray *headers;
@property (nonatomic, copy) NSArray *data;

@property (nonatomic, strong) NSNumber *totalPage;
@property (nonatomic, strong) NSNumber *page;
@property (nonatomic, copy) NSString *constituentsID;
@property (nonatomic, strong) NSNumber *totalCount;

@end

@protocol TBMarketMinuteQuotaBalanceItem <NSObject>
@end
@interface TBMarketMinuteQuotaBalanceItem : JSONModel
@property (nonatomic, strong) NSNumber *balance;
@property (nonatomic, strong) NSNumber *time;
@end

@interface TBMarketMinuteQuotaBalanceModel : JSONModel

@property (nonatomic, copy) NSArray<TBMarketMinuteQuotaBalanceItem> *data;
@property (nonatomic, strong) NSNumber *datetime;
@property (nonatomic, strong) NSNumber *limit;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, readonly) ChartLimitLine *limitLine;

@end


@interface TBMarketWideDetailModel : JSONModel

@property (nonatomic, strong) TBMarketMinuteQuotaBalanceModel *minuteQuotaBalance;
@property (nonatomic, strong) TBMarketConstituentsModel *constituents;
@property (nonatomic, strong) TBMarketDailyQuotaBalanceModel *dailyQuotaBalance;
@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *serverTime;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *connectCloseText;

- (NSAttributedString *)pieChartCenterAttributedText;
- (NSArray *)pieChartLegends;
- (PieChartData *)pieChartData;

- (NSArray *)combinedChartLegends;
- (CombinedChartData *)combinedChartData;
- (NSArray *)xAxisValue;
@end
