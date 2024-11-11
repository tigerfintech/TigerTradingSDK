//
//  TBFuturesMarketModel.h
//  TBStockKit
//
//  Created by zlc on 2023/8/24.
//

#import <TBBaseKit/TBBaseKit.h>
#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/TBBaseModel.h>

#import "TBFuturesDefinetions.h"
#import "TBMarketBriefPriceModel.h"
#import "TBDecimal.h"
NS_ASSUME_NONNULL_BEGIN

@class TBFuturesMarketContractModel;

@interface TBFuturesMarketModel : TBBaseModel

@property (nonatomic, copy) NSString *categoryId;
@property (nonatomic, copy) NSString *categoryName;
@property (nonatomic, copy) NSArray <TBFuturesMarketContractModel *> *contracts;

@end


/* 继承TBMarketBriefPriceModel，复用其中的属性和辅助计算属性*/
@interface TBFuturesMarketContractModel : TBMarketBriefPriceItemModel

@property (nonatomic, assign) NSInteger maxScale;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *symbolId;
@property (nonatomic, copy) NSString *symbolName;
@property (nonatomic, copy) NSString *quotesDisplayType;

@property (retain, nonatomic) TBDecimal *displayMultiplier;       // 合约乘数

@property (assign, nonatomic, readonly) TBQuotesDisplayType marketQuotesDisplayType;  // 是利率合约还是普通的合约

- (NSString *)displayForQuotesPrice:(id)price;
- (NSString *)displayForQuotesPrice:(id)price needPositivePrefix:(BOOL)needPositivePrefix;

@end

NS_ASSUME_NONNULL_END
