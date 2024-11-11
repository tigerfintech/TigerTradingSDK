//
//  TBPortfolioLitePageDelegate.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2023/1/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TBPortfolioLitePageRefreshBlock)(void);

@protocol TBPortfolioLitePageDelegate <NSObject>

@required
- (CGFloat)litePageContentHeight;

@optional
- (void)litePageAssetDidChanged:(id<TBAsset>)asset;
- (void)litePagePositionsDidChanged;
- (NSInteger)litePageCurrencyCount;
- (NSInteger)litePagePositionsCurrentCount;

@end

NS_ASSUME_NONNULL_END
