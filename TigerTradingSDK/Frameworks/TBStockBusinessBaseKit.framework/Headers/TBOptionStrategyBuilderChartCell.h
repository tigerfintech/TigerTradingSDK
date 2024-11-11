//
//  TBOptionStrategyBuilderChartCell.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/8.
//

#import <TBUIKit/TBTableViewCell.h>

@class TBOptionStrategyBuilderFundamentalModel;
@class TBCombinedChartView;
@class TBOptionStrategyBuilderChartView;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBuilderChartCellItem : TBTableViewCellItem

@property (nonatomic, strong) TBOptionStrategyBuilderFundamentalModel *model;
@property (nonatomic, strong) TBOptionStrategyBuilderFundamentalModel *otherModel;
@property (nonatomic, strong) TBOptionStrategyBuilderFundamentalModel *underlyingListModel; // 采样点的model，绘制CELL用不到

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, strong) NSNumber *settlementDate;
@property (nonatomic, copy, readonly) NSString *displayDateStr;

@property (nonatomic, assign) BOOL isEndDateLine; // 是否是末日线（settlementDate == minDate)

@property (nonatomic, strong, nullable) NSValue *point;

@property (nonatomic, assign) BOOL isEndDateLineOnly; // 是否只有末日线
@property (nonatomic, assign) BOOL isChartInteractionDisabled; // 是否禁止曲线图交互
@property (nonatomic, assign) BOOL isIntroHidden; // intro 是否禁止
@property (nonatomic, assign) BOOL isSettlementDateDisabled; // 时间选择是否禁止

@property (nonatomic, assign) BOOL isVerticalSpread; // 是否是垂直价差

- (NSDictionary *)getBreakEvenPointAndXValue;

+ (NSInteger)getStrategyChartOnePageCount:(BOOL)isVerticalSpread;

@end


@interface TBOptionStrategyBuilderChartCell : TBTableViewCell

@property (nonatomic, strong, readonly) TBOptionStrategyBuilderChartView *endDateLineChartView;

- (TBCombinedChartView *)highlightLineChartView;

// isVerticalSpread 是否是垂直价差策略
- (void)resetChartKLine:(BOOL)isVerticalSpread;

- (void)resetChartKLineWithPageCount:(NSInteger)pageCount;

@end

NS_ASSUME_NONNULL_END
