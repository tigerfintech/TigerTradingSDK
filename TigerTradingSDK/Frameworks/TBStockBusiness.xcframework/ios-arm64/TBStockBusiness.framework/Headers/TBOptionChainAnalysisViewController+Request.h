//
//  TBOptionChainAnalysisViewController+Request.h
//  Stock
//
//  Created by 王灵博 on 2021/1/14.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBOptionChainAnalysisViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainAnalysisViewController (Request)
- (void)fetchStockFundamentalCorporateAction;
- (void)fetchStockCorpation;
- (void)fetchStockPriceData:(NSString *)symbol;
- (void)fetchOptionMarketData;
- (void)fetchOptionAnalysisCallDividePut:(BOOL)callDividePut;
- (void)fetchExpiryOptionData;
- (void)fetchOptionAnalysis;
@end

NS_ASSUME_NONNULL_END
