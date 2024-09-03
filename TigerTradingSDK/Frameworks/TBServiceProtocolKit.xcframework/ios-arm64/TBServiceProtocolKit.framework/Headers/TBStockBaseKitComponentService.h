//
//  TBStockBaseKitComponentService.h
//  Pods
//
//  Created by 秦晓强 on 2023/5/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockBaseKitComponentService <NSObject>

- (NSString *)tbStockBaseKit_getStockOriginSymbolWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getFuturesRealSymbolWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getFuturesRealNameCNWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getStockSymbolWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getStockMarketWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getStockSecTypeWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getStockNameCNWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getDerivativesStrikeWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getStockTradeCurrencyWithSecInfo:(id)secInfo;

- (NSNumber *)tbStockBaseKit_getStockRealTimeLatestPriceWithSecInfo:(id)secInfo;

- (NSNumber *)tbStockBaseKit_getStockPreCloseWithSecInfo:(id)secInfo;

- (NSNumber *)tbStockBaseKit_getStockBidPriceWithSecInfo:(id)secInfo;

- (NSNumber *)tbStockBaseKit_getStockAskPriceWithSecInfo:(id)secInfo;

- (NSNumber *)tbStockBaseKit_getStockLotSizeWithSecInfo:(id)secInfo;

- (NSNumber *)tbStockBaseKit_getStockSpreadScaleWithSecInfo:(id)secInfo;

- (NSInteger)tbStockBaseKit_getStockDetailTypeWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getFuturesQuotesDisplayTypeWithSecInfo:(id)secInfo;

- (NSString *)tbStockBaseKit_getDisplayStringFromNumber:(NSNumber *)number
                                                secInfo:(id)secInfo;

- (NSNumber *)tbStockBaseKit_priceNumberWithDisplayString:(NSString *)displayString
                                                  secInfo:(id)secInfo;

- (id)tbStockBaseKit_getStockDetailPositionOrderSectionHeaderWith:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

- (BOOL)tbStockBaseKit_isFutureValidatePrice:(id)price             
                                     secInfo:(id)secInfo;
/// 跳转到形态选股解释说明页
- (void)tbStockBaseKit_gotoCandleSelectedIntroWebView;

- (BOOL)tbStockBaseKit_isIndexOptionSecInfo:(id)secInfo;

/// 组合期权最大腿数量
- (int)tbStockBaseKit_optionStrategyMaxOptionLegsCount;

@end
NS_ASSUME_NONNULL_END
