//
//  TBOptionScreenerConfigurationModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/5/16.
//

#import <TBBaseKit/JSONModel.h>

@class TBOptionScreenerConfigurationData;
@class TBOptionScreenerConfigurationTemplate;
@class TBOptionScreenerConfigurationTemplateItem;

@protocol TBOptionScreenerConfigurationStrategy;
@protocol TBOptionScreenerConfigurationMood;
@protocol TBOptionScreenerConfigurationCategory;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionScreenerConfigurationModel : JSONModel

@property (nonatomic, strong) TBOptionScreenerConfigurationData *data;
@property (nonatomic, copy) NSString *errMsg;
@property (nonatomic, assign) BOOL isSuccess;

@end


@interface TBOptionScreenerConfigurationData : JSONModel

@property (nonatomic, copy) NSArray <TBOptionScreenerConfigurationMood> *mood;
@property (nonatomic, copy) NSArray <TBOptionScreenerConfigurationStrategy> *strategy;
@property (nonatomic, strong) TBOptionScreenerConfigurationTemplate *templateValue;
@property (nonatomic, copy) NSArray <TBOptionScreenerConfigurationCategory> *category;

@end


@interface TBOptionScreenerConfigurationTemplate : JSONModel

@property (nonatomic, strong) TBOptionScreenerConfigurationTemplateItem *longItem;
@property (nonatomic, strong) TBOptionScreenerConfigurationTemplateItem *noneItem;
@property (nonatomic, strong) TBOptionScreenerConfigurationTemplateItem *shortItem;

@end

@interface TBOptionScreenerConfigurationTemplateItem : JSONModel

@property (nonatomic, copy) NSArray *goDown;
@property (nonatomic, copy) NSArray *goUp;
@property (nonatomic, copy) NSArray *stayNeutral;

@end

@interface TBOptionScreenerConfigurationStrategy : JSONModel

@property (nonatomic, copy) NSString *name; // eg: 买入认购期权
@property (nonatomic, copy) NSString *descriptionField;
@property (nonatomic, copy) NSString *iconGreenUp;
@property (nonatomic, copy) NSString *iconRedUp;
@property (nonatomic, copy) NSString *mood; // eg: bullish
@property (nonatomic, copy) NSString *type; // eg: Long Call
@property (nonatomic, copy) NSString *category; // eg: expenditure / income

@end

@interface TBOptionScreenerConfigurationMood : JSONModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *type;

@end


@interface TBOptionScreenerConfigurationCategory : JSONModel

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *defaultField;
@property (nonatomic, copy) NSArray *delta;
@property (nonatomic, copy) NSArray *rate;

@end

// MARK: - category
@interface TBOptionScreenerConfigurationData (Utils)

- (TBOptionScreenerConfigurationStrategy *)getStrategyWithType:(NSString *)type;

- (TBOptionScreenerConfigurationMood *)getMoodWithMood:(NSString *)moodType;

- (TBOptionScreenerConfigurationCategory *)getCategoryWithCategory:(NSString *)categoryType;

@end

@interface TBOptionScreenerConfigurationStrategy (Utils)

- (BOOL)isSellDirection;
- (BOOL)isIncomeType;

@end

@interface TBOptionScreenerConfigurationMood (Utils)

- (UIColor *)getDisplayColor;

@end

@interface TBOptionScreenerConfigurationCategory (Utils)

- (BOOL)isIncomeType;

/// 获取default值的index
- (NSInteger)getDefaultSelectedIdx;

/// income 返回 rate；expenditure 返回 delta
- (NSArray <NSString *> *)rateOrDetlaArray;

@end

NS_ASSUME_NONNULL_END
