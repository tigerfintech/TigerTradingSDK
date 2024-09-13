//
//  TBOptionChainWidthCell.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/19.
//
@class TBMultiOptionExpiryWidthModel;
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainWidthCell : TBTableViewCell

@end


@interface TBOptionChainWidthCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL isDefault;
@property (nonatomic, assign) BOOL select;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) TBMultiOptionExpiryWidthModel *model;
@property (nonatomic, strong) NSNumber *value;

@end

NS_ASSUME_NONNULL_END
