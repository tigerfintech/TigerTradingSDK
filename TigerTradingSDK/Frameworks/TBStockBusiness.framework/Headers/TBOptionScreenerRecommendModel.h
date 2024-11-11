//
//  TBOptionScreenerRecommendModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/5/17.
//

#import <TBBaseKit/JSONModel.h>
#import "TBOptionScreenerConfigurationModel.h"

@protocol TBOptionScreenerRecommendOption;
@class TBOptionScreenerRecommendData;


NS_ASSUME_NONNULL_BEGIN

@interface TBOptionScreenerRecommendModel : JSONModel

@property (nonatomic, strong) TBOptionScreenerRecommendData * data;
@property (nonatomic, strong) NSString * errMsg;
@property (nonatomic, assign) BOOL isSuccess;
        
@end

@interface TBOptionScreenerRecommendData : JSONModel

@property (nonatomic, strong) NSString * symbol;
@property (nonatomic, strong) NSString * market;
@property (nonatomic, strong) NSNumber * latestPrice;
@property (nonatomic, strong) NSArray <TBOptionScreenerRecommendOption> *options;
@property (nonatomic, strong) TBOptionScreenerConfigurationStrategy *strategy;

@end

@interface TBOptionScreenerRecommendOption : JSONModel

@property (nonatomic, strong) NSString * symbol;
@property (nonatomic, strong) NSString * strike;
@property (nonatomic, strong) NSString * right;
@property (nonatomic, strong) NSNumber * delta;
@property (nonatomic, strong) NSNumber * expiry;
@property (nonatomic, strong) NSNumber * askPrice;
@property (nonatomic, strong) NSNumber * bidPrice;
@property (nonatomic, strong) NSNumber * latestPrice;
@property (nonatomic, strong) NSNumber * preClose;
@property (nonatomic, strong) NSNumber * multiplier;
@property (nonatomic, strong) NSNumber * expectedArr;

@end

NS_ASSUME_NONNULL_END
