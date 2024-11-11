//
//  TBExplanationCollectionCellItem.h
//  TBUIKit
//
//  Created by swordzhou on 2022/8/12.
//

#import "TBComponentCollectionCellItem.h"

NS_ASSUME_NONNULL_BEGIN

@class TBIndicatorExplanationModel;

@interface TBExplanationCollectionCellItem : TBComponentCollectionCellItem

@property (nonatomic, strong) TBIndicatorExplanationModel *indicatorExplanationModel;

@property (nonatomic, assign) BOOL showLeftBorder;
@property (nonatomic, assign) BOOL showTopBorder;
@property (nonatomic, assign) BOOL showRightBorder;
@property (nonatomic, assign) BOOL showBottomBorder;

@end

NS_ASSUME_NONNULL_END
