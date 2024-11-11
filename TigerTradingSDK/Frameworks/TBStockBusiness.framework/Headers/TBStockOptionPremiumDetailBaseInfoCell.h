//
//  TBStockOptionPremiumDetailBaseInfoCell.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/1.
//

#import "TBStockOptionPremiumDetailBaseCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockOptionPremiumDetailBaseInfoCellItem : TBStockOptionPremiumDetailBaseCellItem

@property (nonatomic, copy) NSString *displaySymbol;
@property (nonatomic, copy) NSAttributedString *displayDetail;

@end


@interface TBStockOptionPremiumDetailBaseInfoCell : TBStockOptionPremiumDetailBaseCell

@end

NS_ASSUME_NONNULL_END
