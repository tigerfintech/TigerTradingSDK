//
//  TBStockOptionPremiumHubOptionItemView.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockOptionPremiumHubOptionItemView : UIView

/// 唯一id，默认nil
@property (nonatomic, copy, nullable) NSString *ID;

@property (nonatomic, strong) UIImage *logoImage;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *earn;
@property (nonatomic, copy) NSString *apy;
@property (nonatomic, copy) NSString *apyHint;

- (void)setLogoImgViewHidden:(BOOL)isHidden;

- (void)changeAppColorStyle;

@end

NS_ASSUME_NONNULL_END
