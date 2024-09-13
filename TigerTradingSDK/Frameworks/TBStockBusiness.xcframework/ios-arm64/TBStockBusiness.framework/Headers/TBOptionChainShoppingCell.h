//
//  TBOptionChainShoppingCell.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/19.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainShoppingCell : TBTableViewCell

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIImageView *arrowImageView;
@property (nonatomic, strong) UILabel *rightLabel;
@property (nonatomic, strong) UILabel *directionLabel;
@property (nonatomic, strong) UIButton *bgButton;

@property (nonatomic, copy) NSString *direction;

@end

NS_ASSUME_NONNULL_END
