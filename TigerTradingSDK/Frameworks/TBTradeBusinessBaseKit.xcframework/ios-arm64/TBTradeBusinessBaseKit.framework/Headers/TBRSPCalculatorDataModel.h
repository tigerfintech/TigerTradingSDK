//
//  TBRSPCalculatorDataModel.h
//  TBTradeBusiness
//
//  Created by zlc on 2022/11/9.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TBRSPCalculatorPeriodType) {
    TBRSPCalculatorPeriodTypeYear1,
    TBRSPCalculatorPeriodTypeYear2,
    TBRSPCalculatorPeriodTypeYear3,
    TBRSPCalculatorPeriodTypeYear5,
};

typedef NS_ENUM(NSInteger, TBRSPCalculatorFrequencyType) {
    TBRSPCalculatorFrequencyTypeDay,
    TBRSPCalculatorFrequencyTypeWeek,
    TBRSPCalculatorFrequencyTypeWeek2,
    TBRSPCalculatorFrequencyTypeMonth,
};

@protocol TBRSPCalculatorDataItemModel <NSObject>
@property (nonatomic, copy) NSString *period;
@property (nonatomic, copy) NSString *frequency;
@property (nonatomic, strong) NSNumber *count;
@property (nonatomic, strong) NSNumber *riReturn;
@end


@interface TBRSPCalculatorDataModel : JSONModel

@property (nonatomic, copy) NSArray <TBRSPCalculatorDataItemModel> *items;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *tradeCurrency;

@property (nonatomic, strong) NSNumber *minAmount;
@property (nonatomic, strong) NSNumber *maxAmount;
@property (nonatomic, strong) NSNumber *defaultAmount;

/// 获取指定period的所有items
- (NSArray <TBRSPCalculatorDataItemModel> *)filterItemsWithPeriodType:(TBRSPCalculatorPeriodType)type;
/// 获取指定frequency的所有items
- (nullable id<TBRSPCalculatorDataItemModel> )filterItemsWithFrequencyType:(TBRSPCalculatorFrequencyType)type inArray:(NSArray <TBRSPCalculatorDataItemModel > *)array;

@end

@interface TBRSPCalculatorDataItemModel : JSONModel

@property (nonatomic, copy) NSString *period;
@property (nonatomic, copy) NSString *frequency;
@property (nonatomic, strong) NSNumber *count;
@property (nonatomic, strong) NSNumber *riReturn;

// 定投频率
- (NSString *)getDisplayFrequency;
// 定投周期
- (NSString *)getDisplayPeriod;
// ri标题，eg1年定投回报率
- (NSString *)getDisplayRIReturn;

+ (NSString *)getDisplayFrequency:(NSString *)frequency;
+ (NSString *)getDisplayPeriod:(NSString *)period;
+ (NSString *)getDisplayRIReturn:(NSString *)period;

/// 获取所有的周期
+ (NSArray <NSString *> *)getPeriods;

/// 获取所有频率
+ (NSArray <NSString *> *)getFrequencies;

/// 获取periodKey
+ (NSString *)getPeriodKey:(TBRSPCalculatorPeriodType)type;
/// 获取frequencyKey
+ (NSString *)getFrequencyKey:(TBRSPCalculatorFrequencyType)type;
@end


NS_ASSUME_NONNULL_END
