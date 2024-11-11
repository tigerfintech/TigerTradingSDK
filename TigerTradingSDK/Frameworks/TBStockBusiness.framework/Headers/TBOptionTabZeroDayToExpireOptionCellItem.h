//
//  TBOptionTabZeroDayToExpireOptionCellItem.h
//  TBStockBusiness
//
//  Created by chenxin on 2023/8/7.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>
#import "TBOptionTabZeroDayToExpireOptionModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionTabZeroDayToExpireOptionCell : TBTableViewCell

@end

@interface TBOptionTabZeroDayToExpireOptionCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray<TBOptionTabZeroDayToExpireOptionModel *> *zeroDayToExpireOptions;

@end

NS_ASSUME_NONNULL_END
