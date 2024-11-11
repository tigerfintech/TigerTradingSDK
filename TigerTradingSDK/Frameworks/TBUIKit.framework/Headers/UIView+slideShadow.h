//
//  UIView+slideShadow.h
//  Shadow
//
//  Created by 王灵博 on 2020/8/6.
//  Copyright © 2020 yotrolz. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_OPTIONS(NSUInteger, TBStockShadowSide) {
    TBStockShadowSideTop       = 1 << 0,//上阴影
    TBStockShadowSideBottom    = 1 << 1,//下阴影
    TBStockShadowSideLeft      = 1 << 2,//右阴影
    TBStockShadowSideRight     = 1 << 3,//左阴影
    TBStockShadowSideAllSides  = ~0UL//全阴影阴影
};

typedef NS_OPTIONS(NSUInteger, TBStockBorderSide) {
    TBStockBorderSideTop       = 1 << 0,//上边框
    TBStockBorderSideBottom    = 1 << 1,//下边框
};

@interface UIView (slideShadow)

- (void)setTopShaodwRadius:(CGFloat)shadowRadius
               shadowColor:(UIColor *)shadowColor shadowOffset:(CGSize)shadowOffset cornerRadius:(CGFloat)cornerRadius;

- (void)setCornerRadius:(CGFloat)cornerRadius byRoundingCorners:(UIRectCorner)corners;

//- (void)setCornerRadius:(CGFloat)cornerRadius byRoundingCorners:(UIRectCorner)corners layerColor:(UIColor *)layerColor;

- (void)setShadowWithShadowRadius:(CGFloat)shadowRadius shadowColor:(UIColor *)shadowColor shadowOffset:(CGSize)shadowOffset byShadowSide:(TBStockShadowSide)shadowSide;

- (void)setBorderLineWithShadowSide:(TBStockBorderSide)borderSide
                          CornerRadius:(CGFloat)cornerRadius
                               lineWidth:(CGFloat)lineWidth
                               lineColor:(UIColor *)lineColor;


- (void)dwawCornerRadius:(CGFloat)cornerRadius byRoundingCorners:(UIRectCorner)corners;
@end

NS_ASSUME_NONNULL_END
