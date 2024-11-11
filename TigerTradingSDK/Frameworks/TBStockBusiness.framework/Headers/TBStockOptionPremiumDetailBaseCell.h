//
//  TBStockOptionPremiumDetailBaseCell.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/1.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

#define TBStockOptionPremiumDetailBaseCellContainerLeading 43

@interface TBStockOptionPremiumDetailBaseCellItem : TBTableViewCellItem

@end


@interface TBStockOptionPremiumDetailBaseCell : TBTableViewCell

@property (nonatomic, strong) UIView *vLineView;
@property (nonatomic, strong) UIImageView *iconImgView;
@property (nonatomic, strong) UIView *containerView;

@property (nonatomic, assign) CGFloat lineTopMargin;
@property (nonatomic, assign) CGFloat lineBottomMargin;

// container top/bottom margin
@property (nonatomic, assign) CGFloat topMargin;
@property (nonatomic, assign) CGFloat bottomMargin;

- (void)setupUI;
- (void)setupLayouts;

@end

NS_ASSUME_NONNULL_END
