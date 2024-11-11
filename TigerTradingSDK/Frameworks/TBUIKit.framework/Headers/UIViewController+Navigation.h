//
//  UIViewController+Navigation.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBBarButtonContainerView.h"

@interface UIViewController (Navigation)

- (BOOL)hideNavigationBar;
- (void)tbDismissViewControllerAnimated:(BOOL)animated;
- (void)tbDismissViewControllerAnimated:(BOOL)animated completion:(void(^)(void))completion;
- (BOOL)autoGenerateBackBarButtonItem;

/**
 *  导航栏返回按钮的 callback. 先调 dismiss 再调 resourceRelease.
 */
- (void)dismiss;

/**
 *  返回按钮+手势的 callback
 */
- (void)resourceRelease;
- (id)tbParentViewController;

- (BOOL)enableDragBack;

// 某些页面中的view滑动时需要禁用返回手势防止冲突，默认不禁用
- (BOOL)shouldDisableDragBackWithView:(UIView *)view;

- (BOOL)isVisible;

/* 
 * 自定义导航栏左侧按钮视图，调整左侧边距，leftSpaceWidth应为负数，默认为-16
 * 注意views里的元素是UIView类型而不是UIBarButtonItem类型
 * 注意views中视图的顺序，应为从左向右排
 */
- (TBBarButtonContainerView *)tb_leftBarButtonView;
- (void)tb_setLeftBarButtonViews:(NSArray <UIView *> *)views leftSpaceWidth:(CGFloat)leftSpaceWidth;
- (void)tb_setLeftBarButtonViews:(NSArray <UIView *> *)views;

/*
 * 自定义导航栏右侧按钮视图，调整右侧边距，rightSpaceWidth应为负数，默认为-16
 * 注意views里的元素是UIView类型而不是UIBarButtonItem类型
 * 注意views中视图的顺序，应为从右向左排
 */
- (TBBarButtonContainerView *)tb_rightBarButtonView;
- (void)tb_setRightBarButtonViews:(NSArray <UIView *> *)views rightSpaceWidth:(CGFloat)rightSpaceWidth;
- (void)tb_setRightBarButtonViews:(NSArray <UIView *> *)views;

@end
