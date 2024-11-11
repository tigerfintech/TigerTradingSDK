//
//  TBStockOptionPremiumHubOptionCell.h
//  AFNetworking
//
//  Created by zlc on 2024/3/29.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@class TBStockDetailOptionPremiumOptionItemModel;

@interface TBStockOptionPremiumHubOptionCellItem : TBTableViewCellItem

@property (nonatomic, strong) UIImage *logoImage;
@property (nonatomic, strong) TBStockDetailOptionPremiumOptionItemModel *model;
@property (nonatomic, assign) BOOL isLineViewHidden;

@end


@interface TBStockOptionPremiumHubOptionCell : TBTableViewCell

@end

// MARK: - budget-fit
@interface TBStockOptionPremiumBudgetFitOptionCellItem : TBStockOptionPremiumHubOptionCellItem

@end


@interface TBStockOptionPremiumBudgetFitOptionCell : TBStockOptionPremiumHubOptionCell

@end


// MARK: - detail cell
@interface TBStockOptionPremiumDetailOptionCellItem : TBStockOptionPremiumHubOptionCellItem

@end


@interface TBStockOptionPremiumDetailOptionCell : TBStockOptionPremiumHubOptionCell

@end

NS_ASSUME_NONNULL_END
