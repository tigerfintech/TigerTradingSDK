//
//  TBOptionStrategyBuilderStrategyModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/9.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBOptionStrategyBuilderStrategyTagModel;

@interface TBOptionStrategyBuilderStrategyModel : JSONModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *descriptionStr;
@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSArray<TBOptionStrategyBuilderStrategyTagModel> *tags;

@property (nonatomic, copy) NSString *strategyKey;///< 交易侧用策略名称

/// 策略是否包含Debit
- (BOOL)containDebit;

@end

@interface TBOptionStrategyBuilderStrategyTagModel : JSONModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *key;

- (UIColor *)tagColor;

@end

NS_ASSUME_NONNULL_END
