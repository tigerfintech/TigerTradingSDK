//
//  TBContraQuoteTitleCell.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/1/4.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBContraQuoteTitleCell : TBTableViewCell

@end


@interface TBContraQuoteTitleCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) UIImage *logo;

@end

NS_ASSUME_NONNULL_END
