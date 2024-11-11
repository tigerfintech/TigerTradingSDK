//
//  TBTradeAssetsPositionCache.h
//  TBTradeBusiness
//
//  Created by swordzhou on 5/22/23.
//

#import <Foundation/Foundation.h>

typedef NSString *TBTradeCacheCategory;

FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryAssets;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryAggregatedAssets;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryPortfolioConsolidatedAssets;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryPortfolioAggregatedAssets;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryPositions;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryPortfolioPositions;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryFundAssets;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryFundPositions;
FOUNDATION_EXPORT TBTradeCacheCategory const _Nonnull kTBTradeCacheCategoryTigerVault;

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeAssetsPositionCache : NSObject

- (void)updateCachedJsonString:(TBTradeCacheCategory)category key:(NSString *)key jsonString:(NSString *)jsonString;
- (NSString *)cachedJsonString:(TBTradeCacheCategory)category key:(NSString *)key;

- (void)save;

- (void)clear;

@end

NS_ASSUME_NONNULL_END
