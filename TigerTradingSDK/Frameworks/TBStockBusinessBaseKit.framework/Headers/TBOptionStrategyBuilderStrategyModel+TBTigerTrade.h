//
//  TBOptionStrategyBuilderStrategyModel+TBTigerTrade.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/9.
//

#import "TBOptionStrategyBuilderStrategyModel.h"

typedef NS_ENUM(NSInteger, TBOptionStrategyBuilderStrategyType) {
    TBOptionStrategyBuilderStrategyTypeNone, // 无策略
    TBOptionStrategyBuilderStrategyTypeSingleOption,
    TBOptionStrategyBuilderStrategyTypeBullVerticalSpread,
    TBOptionStrategyBuilderStrategyTypeBearVerticalSpread,
    TBOptionStrategyBuilderStrategyTypeCalendarSpread,
    TBOptionStrategyBuilderStrategyTypeDiagonalSpread,
    TBOptionStrategyBuilderStrategyTypeStraddle,
    TBOptionStrategyBuilderStrategyTypeStrangle,
};


NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBuilderStrategyModel (TBTigerTrade)
/// 通过key匹配icon
- (UIImage *)strategyIconImage;
/// 期权策略
- (TBOptionStrategyBuilderStrategyType)strategyType;


@end

NS_ASSUME_NONNULL_END
