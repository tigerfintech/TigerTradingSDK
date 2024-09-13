//
//  TBStockOptionPremiumDetailChartInfoCell.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/1.
//

#import "TBStockOptionPremiumDetailBaseCell.h"

NS_ASSUME_NONNULL_BEGIN

@class TBStockDetailOptionScenarioAnalysisModel,TBStockDetailOptionPremiumOptionItemModel;

@interface TBStockOptionPremiumDetailChartInfoCellItem : TBStockOptionPremiumDetailBaseCellItem

@property (nonatomic, assign) NSInteger selectedIndex;
@property (nonatomic, copy) NSString *displayTitle;
@property (nonatomic, copy) NSAttributedString *displayHintAttributedString;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) TBStockDetailOptionScenarioAnalysisModel *model;
@property (nonatomic, strong) TBStockDetailOptionPremiumOptionItemModel *optionItemModel;

@end


@interface TBStockOptionPremiumDetailChartInfoCell : TBStockOptionPremiumDetailBaseCell

- (void)updateChartData;

@end

NS_ASSUME_NONNULL_END
