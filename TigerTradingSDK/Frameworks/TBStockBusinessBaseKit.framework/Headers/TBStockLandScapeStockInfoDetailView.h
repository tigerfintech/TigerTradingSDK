//
//  TBStockLandScapeStockInfoDetailView.h
//  Stock
//
//  Created by donggongfu on 16/7/29.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TBStockLandScapeStockInfoDetailView;

@protocol TBStockLandScapeStockInfoDetailViewDelegate <NSObject>
@optional
- (NSString *)latestPriceStringForMarket:(NSString *)market inLandScapeStockInfoDetailView:(TBStockLandScapeStockInfoDetailView *)view;
- (NSString *)changeStringForMarket:(NSString *)market inLandScapeStockInfoDetailView:(TBStockLandScapeStockInfoDetailView *)view;
- (NSString *)changePercentStringInLandScapeStockInfoDetailView:(TBStockLandScapeStockInfoDetailView *)view;

- (NSString *)volumeStringInLandScapeStockInfoDetailView:(TBStockLandScapeStockInfoDetailView *)view;
- (NSString *)latestTimeStringInLandScapeStockInfoDetailView:(TBStockLandScapeStockInfoDetailView *)view;


@end


typedef void(^showLandScapeSearchView)(void);
@interface TBStockLandScapeStockInfoDetailView : UIView

@property (nonatomic, copy) NSString *market;

- (void)showLandScapeSearchView:(showLandScapeSearchView)showSearchView;

- (instancetype)initWithName:(NSString *)name symbol:(NSString *)symbol market:(NSString *)market;

- (void)updateName:(NSString *)name symbol:(NSString *)symbol;

- (void)updateWithDetailItem:(id<TBStockLandScapeStockInfoDetailViewDelegate>)detailItem;
@property (nonatomic, strong) UIButton *symbolLabel; // name + symbol

@end
