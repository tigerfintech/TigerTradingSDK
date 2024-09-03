//
//  TBStockBulletUntil.h
//  Stock
//
//  Created by 王灵博 on 2020/8/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TBStockBulletUntil.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockBulletUntil : NSObject
/**
获取弹框蒙层颜色
@return 弹框蒙层颜色
*/
+ (UIColor *)getBulletframeCover;


/**
获取tab字号
@return tab字号
*/
+ (CGFloat)getBulletTabFontNumber;

/**
获取弹框圆角
@return 取弹框圆角
*/
+ (CGFloat)getBulletCornerRadius;


/**
添加弹框阴影
@param view  需要添加阴影的view
*/
+ (void)addBulletShadowForView:(UIView *)view;


/**
获取弹框背景色
@return 弹框背景色
*/
+ (UIColor *)getBulletBackgroundColor;



/**
获取弹框标题top
@return top
*/
+ (CGFloat)getBulletTopDistance;


/**
获取弹框标题bottom
@return bootom
*/
+ (CGFloat)getBulletBottomDistance;


/**
获取弹框标题font
@return font
*/
+ (UIFont *)getBulletFont;


/**
获取弹框关闭按钮
@return UIImage
*/
+ (UIImage *)getBulletCloseImg;


/**
给弹框添加上边框
*/
+ (void)addBulletTopBorderForView:(UIView *)view;

/**
给view添加圆角，边框，和阴影，此方法针对非MZ弹框view
*/
+ (UIView *)addBulletStyleForCustomView:(UIView *)view;


/**
给view添加圆角 view
*/
+ (void)addBulletCornerRadiusForView:(UIView *)view;
@end

NS_ASSUME_NONNULL_END
