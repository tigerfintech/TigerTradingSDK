//
//  TBStockBusinessBriefQuoteModel.h
//  TBStockBusiness
//
//  Created by 骆鹏飞 on 2021/6/10.
//

#import <TBBaseKit/JSONModel.h>
#import <TBStockKit/TBFuturesContractModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockBusinessBriefQuoteModel : JSONModel
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *changeRate;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) NSNumber *timestamp;
@property (nonatomic, strong) NSNumber *halted;
@property (nonatomic, strong) NSNumber *auction;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSDictionary *overnightTrading;
@property (nonatomic, copy) NSDictionary *hourTrading;
@property (nonatomic, copy) NSDictionary *greyMarket;
@property (nonatomic, assign) NSUInteger delay;

@property (nonatomic, copy) TBFuturesContractModel *futuresContractModel; ///< 期货数据
@property (nonatomic, strong) NSNumber *priceOffset; ///< 价格便宜量

#pragma mark ----------------------
#pragma mark -计算涨跌、颜色;展示价格、涨跌
#pragma mark ----------------------
@property (nonatomic, readonly) NSString *displayLatestPrice;
@property (nonatomic, readonly) NSString *displayPreClose;
@property (nonatomic, readonly) NSString *displayChange;
@property (nonatomic, readonly) NSString *displayChangeRatio;
@property (nonatomic, readonly) UIColor *priceColor;

- (NSString *)getChangeRateString;

- (UIColor *)getChangeRateStringColor;

- (NSString *)getPriceString;

/**
 * 获取最新价格，如果存在盘前盘后数据取盘前盘后加嘎
 */
- (NSNumber *)realLatestPrice;

- (NSNumber *)realLatestPriceWithOverNight:(BOOL)withOverNight;

@end

NS_ASSUME_NONNULL_END
