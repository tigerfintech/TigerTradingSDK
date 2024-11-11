//
//  TBOptionStrategyBuilderStrategyCell.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/8.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionStrategyBuilderStrategyModel;
@class TBOptionStrategyBuilderStrategyOptionModel;
@class TBOptionStrategyBuilderStrategyStockModel;

@interface TBOptionStrategyBuilderStrategyCellItem : TBTableViewCellItem

@property (nonatomic, assign) NSInteger segIndex;
@property (nonatomic, strong) TBOptionStrategyBuilderStrategyModel *strategyModel; // 策略信息
@property (nonatomic, strong, readonly) TBOptionStrategyBuilderStrategyOptionModel *topOptionModel; // 单腿期权
@property (nonatomic, strong, readonly, nullable) TBOptionStrategyBuilderStrategyOptionModel *bottomOptionModel; // 另一腿期权
@property (nonatomic, strong, nullable) TBOptionStrategyBuilderStrategyStockModel *stockModel; // 股票

/// 所有腿
@property (nonatomic, strong) NSMutableArray <TBOptionStrategyBuilderStrategyOptionModel *> *legOptionModels;
    
- (BOOL)anotherLegIsStockInfo;
- (BOOL)anotherLegIsOptionInfo;

- (NSNumber *)minimumDate;
- (NSNumber *)maximumDate;

/// 是否期权组合在自选中
- (BOOL)isMultiLegOptionInWatchList;

/// 有多腿（数量>1）期权
- (BOOL)hasMultiLegs;

/** 净收入/支出
 当两个期权收支(卖出为正，买入为负)相加为正，显示Net Credit; 为负时显示Net Debit;
 Net Credit（净收入） = (shortOptionPrice - longOptionPrice)*100
 Net Debit（净支出） = (longOptionPrice-shortOptionPrice)*100
 返回为正数-credit, 负数-debit, 0-N/A
 */
- (nullable NSNumber *)getNetCreditOrDebit;

- (NSString *)mlegSymbol;

- (CGFloat)legViewHeight;

@end

@interface TBOptionStrategyBuilderStrategyCellItem (TBUtils)

- (nullable TBOptionStrategyBuilderStrategyOptionModel *)legOptionModelAtIndex:(NSInteger)index;

/// 更新左右腿的brief信息
- (void)updateOptionModelBrief:(NSArray <TBOptionInfoDetailItem *> *)briefs;

/**
* 更新legOptionModels指定index的optionModel.trade属性
*/
- (void)updateLegOptionModelTrade:(NSString *)trade atIndex:(NSInteger)index;

/**
 * 添加或更新legOptionModels指定index的legOptionModel
 */
- (void)addAndUpdateLegOptionModel:(nullable TBOptionStrategyBuilderStrategyOptionModel *)legOptionModel atIndex:(NSInteger)index;

/**
 * 删除index位置的legOptionModel
 */
- (void)removeLegOptionModelAtIndex:(NSInteger)index;

@end


@interface TBOptionStrategyBuilderStrategyCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
