//
//  TBMultiOptionItem.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/19.
//

#import <TBBaseKit/TBObject.h>
#import <TBBusinessSupportKit/TBStockDetailBaseModel.h>
#import <TBBusinessSupportKit/TBMlegWatchListProtocol.h>
#import "TBOptionItem.h"

@protocol TBMultiOptionChainAskBidModel <NSObject>
@end


@interface TBMultiOptionChainAskBidModel : JSONModel

@property (nonatomic, strong) NSNumber *askPrice;
@property (nonatomic, strong) NSNumber *askSize;
@property (nonatomic, strong) NSNumber *bidPrice;
@property (nonatomic, strong) NSNumber *bidSize;

@end

@protocol TBMultiOptionChainItemModel;
@interface TBMultiOptionChainItemModel : TBMultiOptionChainAskBidModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *volatility;
@property (nonatomic, strong) NSNumber *ratesBonds;
@property (nonatomic, strong) NSNumber *multiplier;
@property (nonatomic, strong) NSNumber *dividePrice;
@property (nonatomic, assign) BOOL old;

@property (nonatomic, copy) NSArray<NSString *> *strikes; //["50.0"]
@property (nonatomic, copy) NSArray<NSString *> *rights; //["call","call"]
@property (nonatomic, copy) NSArray<NSString *> *directions; //["buy","sell"]
@property (nonatomic, copy) NSArray<NSNumber *> *sizes; //[1,2,...]

@property (nonatomic, copy) NSArray<TBMultiOptionChainAskBidModel> *originalAskBids;

@end


@interface TBMultiOptionDefaultChainModel : JSONModel

@property (nonatomic, copy) NSArray<TBOptionExpiryItemModel> *expiry;
@property (nonatomic, copy) NSArray<NSArray<TBMultiOptionChainItemModel> *> *data;

- (void)setDataWithNSArray:(NSArray *)array;

@end


@protocol TBMultiOptionExpiryWidthModel;
@interface TBMultiOptionExpiryWidthModel : JSONModel

@property (nonatomic, strong) NSNumber *width;
@property (nonatomic, copy) NSString *periodTag;

@end


@interface TBMultiOptionChainModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSInteger serverTime;

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, assign) BOOL indexOption;

@property (nonatomic, copy) NSArray<NSArray<NSNumber *> *> *openAndCloseTimeList;

@property (nonatomic, copy) NSArray<NSArray<TBOptionExpiryItemModel> *> *expires;

@property (nonatomic, strong) TBMultiOptionDefaultChainModel *defaultChain;

@property (nonatomic, copy) NSDictionary *chainIVs;

//价差
@property (nonatomic, strong) NSNumber *defaultStrikeWidth;
@property (nonatomic, strong) NSNumber *currentStrikeWidth;
@property (nonatomic, copy) NSArray<NSNumber *> *strikeWidth;
//日历差
@property (nonatomic, strong) TBMultiOptionExpiryWidthModel *defaultExpiryWidth;
@property (nonatomic, strong) TBMultiOptionExpiryWidthModel *currentExpiryWidth;
@property (nonatomic, copy) NSArray<TBMultiOptionExpiryWidthModel> *expiryWidth;

@property (nonatomic, copy) NSArray<TBOptionStrategyBuilderStrategyModel> *strategies;

#pragma mark -
- (void)setExpiresWithNSArray:(NSArray *)array;

@end


/// 获取指定过期日的组合期权链model
@interface TBMultiOptionChainExpiryModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSInteger serverTime;

@property (nonatomic, copy) NSArray<NSArray<TBMultiOptionChainItemModel> *> *data;

@property (nonatomic, strong) NSNumber *defaultStrikeWidth;
@property (nonatomic, strong) NSNumber *currentStrikeWidth;
@property (nonatomic, copy) NSArray<NSNumber *> *strikeWidth;

@property (nonatomic, copy) NSDictionary *chainIVs;

#pragma mark -
- (void)setDataWithNSArray:(NSArray *)array;

@end


//购物车
@interface TBOptionChainShoppingModel : JSONModel

//唯一标识
@property (nonatomic, copy) NSString *combinedKey;

@property (nonatomic, copy) NSString *name;//标题
@property (nonatomic, copy) NSString *symbol;//可能为空
//match：考虑用strike + right 匹配
@property (nonatomic, copy) NSArray<NSString *> *strikes; //["50.0"]
@property (nonatomic, copy) NSArray<NSString *> *rights; //["call","call"]
@property (nonatomic, copy) NSArray<NSString *> *directions; //["buy","sell"]

@property (nonatomic, assign) BOOL isOld;
@property (nonatomic, assign) BOOL isMonth;
@property (nonatomic, assign) BOOL isIndexOption;

@end


@interface TBCombineOptionBaseItemModel : JSONModel <TBMlegWatchListProtocol>

@property (nonatomic, copy) NSString *symbol;//正股symbol
@property (nonatomic, strong) NSNumber *expiry;//过期日
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *direction;
@property (nonatomic, strong) NSNumber *size;

@property (nonatomic, assign) BOOL isOld;//旧期权
@property (nonatomic, assign, readonly) BOOL isValid;//六要素是否齐全

- (NSString *)mqttSymbolWithMarket:(NSString *)market;

@end

//组合盘口回包
@protocol TBOptionChainAskBidRetModel;
@interface TBOptionChainAskBidRetModel : TBCombineOptionBaseItemModel

@property (nonatomic, strong) NSNumber *askPrice;
@property (nonatomic, strong) NSNumber *askSize;
@property (nonatomic, strong) NSNumber *bidPrice;
@property (nonatomic, strong) NSNumber *bidSize;

@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *midPrice;

@end
