//
//  TBStockDetailActiveOrderLegInfoCell.h
//  TBStockBusiness
//
//  Created by 王昌阳 on 2023/4/19.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailActiveOrderLegInfoCell : TBTableViewCell

@end

@interface TBStockDetailActiveOrderLegInfoCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subTitle;
@property (nonatomic, strong) UIColor *titleColor;

@end

NS_ASSUME_NONNULL_END
