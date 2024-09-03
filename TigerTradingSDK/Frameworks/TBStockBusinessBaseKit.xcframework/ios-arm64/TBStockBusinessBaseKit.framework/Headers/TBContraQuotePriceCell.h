//
//  TBContraQuotePriceCell.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/1/4.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockBusinessBaseKit/TBStockDetailPriceTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBContraQuotePriceCell : TBTableViewCell

@end


@interface TBContraQuotePriceCellItem : TBTableViewCellItem

@property (nonatomic, strong) id<TBStockDetailPriceTableViewCell> dataSource;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *currency;

@end

NS_ASSUME_NONNULL_END
