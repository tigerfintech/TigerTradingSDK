//
//  UIColor+HBVHarmonies.h
//  Herbivore
//
//  Created by Travis Henspeter on 3/5/14.
//  Copyright (c) 2014 Herbivore. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (HBVHarmonies)

- (UIColor *)colorHarmonyWithExpression:(CGFloat(^)(CGFloat value))expression alpha:(CGFloat)alpha;
+ (UIColor *)randomColor;
- (UIColor *)complement;
- (UIColor *)jitterWithPercent:(CGFloat)percent;

@end

// 版权属于原作者
// http://code4app.com (cn) http://code4app.net (en)
// 发布代码于最专业的源码分享网站: Code4App.com
