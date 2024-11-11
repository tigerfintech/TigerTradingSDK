//
//  TBOptionStrategyDescriptionCell.h
//  Stock
//
//  Created by JustLee on 2020/12/21.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBOptionQuoteSelecteCell.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBStrategyDescriptionType) {
    TBStrategyDescriptionTypeMaxLoss,
    TBStrategyDescriptionTypeMaxProfit,
    TBStrategyDescriptionTypeOther,
};

#pragma mark -- 基类

@interface TBOptionStrategyBaseCellItem : TBTableViewCellItem

@property (nonatomic, assign) TBOptionQuoteTrendType quoteTrendType;

@end

#pragma mark - 通用策略
@interface TBOptionStrategyCommonCell : TBTableViewCell

@end


@interface TBOptionStrategyCommonCellItem : TBOptionStrategyBaseCellItem

/// 是否处于折叠状态
@property (nonatomic, assign, getter=isFold) BOOL fold;

@end


#pragma mark - 策略描述。最大亏损、最大盈利、其他风险
@interface TBOptionStrategyDescriptionCell : TBTableViewCell

@end


@interface TBOptionStrategyDescriptionCellItem : TBOptionStrategyBaseCellItem

@property (nonatomic, assign) TBStrategyDescriptionType descriptionType;


@end

#pragma mark - 图形说明
@interface TBOptionStrategyGraphicsIntroduceCell : TBTableViewCell

@end


@interface TBOptionStrategyGraphicsIntroduceCellItem : TBOptionStrategyBaseCellItem

@end


NS_ASSUME_NONNULL_END
