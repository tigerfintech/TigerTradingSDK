//
//  TBMarketConditionsViewController+HTTPManager.h
//  Stock
//
//  Created by 王灵博 on 2020/9/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBMarketConditionsViewController.h"

@class TBRSPListModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketConditionsViewController (HTTPManager)

- (void)fetchAutoInvestData:(BOOL)showLoading completion:(void (^)(TBRSPListModel *autoInvestListModel))completion;

- (void)fetchFetchMarketDataWithParameters:(nullable NSDictionary *)parameters showLoading:(BOOL)showLoading;
//市场行情
- (void)fetchMarketData:(BOOL)showLoading;
//打新日历
- (void)fetchNewCalendarData;
//今日异动
- (void)fetchChangesToday;
@end

NS_ASSUME_NONNULL_END
