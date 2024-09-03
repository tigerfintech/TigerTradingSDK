//
//  TBGroupCardCornerView.h
//  TBTradeBusiness
//
//  Created by zlc on 2022/6/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBGroupCardCornerView : UIView

/// 创建一个四边带圆角的cornerView
+ (TBGroupCardCornerView *)createCornerViewWithRadius:(CGFloat)radius;

/// 创建一个左上和右上的cornerView
+ (TBGroupCardCornerView *)createTopCornerViewWithRadius:(CGFloat)radius;

/// 创建一个左下和右下的cornerView
+ (TBGroupCardCornerView *)createBottomCornerViewWithRadius:(CGFloat)radius;

/** 创建一个cornerView
 @param backgroundColor 背景色
 @param radius 圆角大小
 @param maskedCorners 圆角方位
 */
+ (TBGroupCardCornerView *)createViewWithBackgroundColor:(UIColor *)backgroundColor radius:(CGFloat)radius maskedCorners:(CACornerMask)maskedCorners;

- (void)setTopCorner;

- (void)setBottomCorner;

@end

NS_ASSUME_NONNULL_END
