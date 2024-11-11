//
//  UIView+TBMASAdditions.h
//  Stock
//
//  Created by ChenXin on 2017/10/24.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Masonry/Masonry.h>

@interface UIView (TBMASAdditions)

/*
 iOS 11增加了Safe Area的概念，为适配iPhone X并兼容iOS 10以下版本，
 设置或更新子视图同viewController的view的边缘约束时，使用以下方法
 方法内部做不同版本处理，以免重复写@available(iOS 11.0, *)判断代码
 */

- (MASViewAttribute *)tb_mas_top;

- (MASViewAttribute *)tb_mas_bottom;

- (MASViewAttribute *)tb_mas_left;

- (MASViewAttribute *)tb_mas_right;

// iPhone X上，某些页面需要在viewDidLayoutSubviews方法中更新部分子视图底部约束
- (void)updateBottomConstraintInView:(UIView *)superview;

// 子视图统一布局
- (void)tb_addAndLayoutSubviews:(NSArray *)subviews
                      alongAxis:(MASAxisType)axisType
               withFixedSpacing:(CGFloat)fixedSpacing
                     edgeInsets:(UIEdgeInsets)edgeInsets;

@end
