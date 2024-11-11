//
//  UIView+Shadow.h
//  Stock
//
//  Created by JustLee on 2019/3/18.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBShadowImageView : UIImageView

@property (nonatomic, assign) BOOL nonatomicState;
@property (nonatomic, assign) UIControlState state;

- (instancetype)initWithImage:(UIImage *)image selectedImage:(UIImage *)selectedImage;

@end

@interface UIView (Shadow)

@property (nonatomic, strong) TBShadowImageView *shadowContentView;

- (void)addShadowWithEdgeInsets:(UIEdgeInsets)insets;
- (void)addNonatomicStateShadowWithEdgeInsets:(UIEdgeInsets)insets;

- (void)addCustomStyleWithImage:(UIImage *)image selectedImage:(UIImage *)selectedImage edgeInsets:(UIEdgeInsets)insets;

- (void)addShadowWithShadowImageView:(TBShadowImageView *)shadowImageView edgeInsets:(UIEdgeInsets)insets;

/**
 * 根据设计师在蓝湖上的阴影参数添加阴影
 *
 * 参考 https://stackoverflow.com/questions/34269399/how-to-control-shadow-spread-and-blur

 @param offset 对应shadowOffset
 @param blur 对应shadowRadius
 @param spread 对应shadowPath
 @param hexColor 对应shadowColor
 @param alpha 对应shadowColor
 */
- (void)addShadowWithOffset:(CGSize)offset blur:(CGFloat)blur spread:(CGFloat)spread hexColor:(NSInteger)hexColor alpha:(CGFloat)alpha;

/**
 * 根据设计师在蓝湖上的阴影参数添加阴影
 *
 * 参考 https://stackoverflow.com/questions/34269399/how-to-control-shadow-spread-and-blur

 @param offset 对应shadowOffset
 @param blur 对应shadowRadius
 @param spread 对应shadowPath
 @param color 对应shadowColor
 */
- (void)addShadowWithOffset:(CGSize)offset blur:(CGFloat)blur spread:(CGFloat)spread color:(UIColor *)color;

/**
 添加 S3 规范阴影
 https://docs.google.com/spreadsheets/d/14fl80yWD_Dl4CydeP-TgThJxyh8OVykR0tDg_REFLT8/edit#gid=0
 */
- (void)addS3Shadow;

@end

