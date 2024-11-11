//
//  TBHomePageStocksViewController+MarketData.h
//  TBStockBusiness
//
//  Created by wind on 2022/7/1.
//

#import "TBHomePageStocksViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBHomePageStocksViewController (MarketData)

- (void)setupMarketData;

- (NSString *)getContentMoreComponentWithMarket:(NSString *)marketEn;
- (NSString *)getMarketUrlWithMarket:(NSString *)marketEn;

@end

NS_ASSUME_NONNULL_END
