//
//  UIFont+TBAdditions.h
//  Stock
//
//  Created by chenxin on 2018/4/2.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIFont (TBAdditions)

+ (void)preload;

// tigertrade和tradeup共用一套字体
+ (UIFont *)tus_englishRegularFontOfSize:(CGFloat)fontSize;
+ (UIFont *)tus_englishMediumFontOfSize:(CGFloat)fontSize;

// 根据needAdjust确认是否需要根据字号设置进行变换
+ (UIFont *)tus_englishRegularFontOfSize:(CGFloat)fontSize  adjustFont:(BOOL)needAdjust;
+ (UIFont *)tus_englishMediumFontOfSize:(CGFloat)fontSize   adjustFont:(BOOL)needAdjust;
@end
