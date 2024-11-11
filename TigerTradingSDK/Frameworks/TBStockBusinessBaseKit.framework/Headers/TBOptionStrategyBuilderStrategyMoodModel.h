//
//  TBOptionStrategyBuilderStrategyMoodModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/9.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionStrategyBuilderStrategyModel;
@class TBOptionStrategyBuilderStrategyOptionModel;

@interface TBOptionStrategyBuilderStrategyMoodModel : JSONModel

@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, strong) NSNumber *netCredit;
@property (nonatomic, copy) NSString *currentOptionTrade;
@property (nonatomic, strong) TBOptionStrategyBuilderStrategyModel *strategy;
@property (nonatomic, strong) TBOptionStrategyBuilderStrategyOptionModel *target;

@end

NS_ASSUME_NONNULL_END
