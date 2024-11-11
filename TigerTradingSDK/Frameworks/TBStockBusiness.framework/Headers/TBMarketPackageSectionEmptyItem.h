//
//  TBMarketPackageSectionEmptyItem.h
//  TBStockBusiness
//
//  Created by zhenglanchun on 2021/7/29.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketPackageSectionEmptyItem : TBTableViewCellItem

@property (nonatomic, assign) CGFloat height;

- (instancetype)initWithHeight: (CGFloat)height;

@end

@interface TBMarketPackageSectionEmptyView : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
