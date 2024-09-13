//
//  TBStockOptionPremiumHubHeaderCell.h
//  AFNetworking
//
//  Created by zlc on 2024/3/29.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBStockDetailOptionPremiumTypeEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockOptionPremiumHubHeaderCellItem : TBTableViewCellItem

@property (nonatomic, copy) TBStockDetailOptionPremiumHubType selectedType;
@property (nonatomic, copy) NSArray <TBStockDetailOptionPremiumHubType> *types;

@end


@interface TBStockOptionPremiumHubHeaderCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
