//
//  TBHomePageWatchlistCell.h
//  TBStockBusiness
//
//  Created by wind on 2022/3/30.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockKit/TBFuturesContractModel.h>

NS_ASSUME_NONNULL_BEGIN


@interface TBHomePageWatchlistCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, strong, nullable) NSNumber *changeRate;
@property (nonatomic, strong, nullable) NSNumber *latestPrice;
@property (nonatomic, strong, nullable) NSNumber *preClose;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *halted;
@property (nonatomic, strong) NSNumber *maxScale;
@property (nonatomic, copy) NSString *dispalyLatestPrice;  //期货的价格展示使用

@property (nonatomic, copy) NSDictionary *hourTrading; // 盘前盘后字典
@property (nonatomic, copy) NSDictionary *overnightTrading; // 夜盘字典

// 期货计算 price 使用
@property (nonatomic, strong) TBFuturesContractModel *contractModel;
@property (nonatomic, strong) NSNumber *priceOffset;
@property (nonatomic, strong, readonly) NSNumber *quotesLastPrice;
@property (nonatomic, strong, readonly) NSNumber *quotesPreClose;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface TBHomePageWatchlistCell : TBTableViewCell

//更新缩略图数据
- (void)updateThumbnailDataIfNeed;

@end

@interface TBHomePageWatchlistAddCellItem : TBTableViewCellItem

@end

@interface TBHomePageWatchlistAddCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
