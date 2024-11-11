//
//  TBBaseViewController+TBNavigationItem.h
//  TBUIKit
//
//  Created by linbingjie on 2021/7/19.
//

#import "TBBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

static char tb_leftBarButtonView;
static char tb_rightBarButtonView;

// 按照2018改版规范，按钮icon到屏幕边距为15，实现时icon到按钮边距为10，按钮到屏幕边距为5
static const CGFloat kTBButtonToScreenOffset = 5;
static const CGFloat kTBBarButtonItemFixedSpaceDefaultWidth = -16;
static const CGFloat kTBUIButtonBarStackViewMargin = 0;
static const NSInteger kTBLeftPlaceholderItemTag = 1001;
static const NSInteger kTBRightPlaceholderItemTag = 1002;

@interface TBBaseViewController (TBNavigationItem)

/*
 * 自定义导航栏左侧按钮视图，调整左侧边距，leftSpaceWidth应为负数，默认为-16
 * 注意views里的元素是UIView类型而不是UIBarButtonItem类型
 * 注意views中视图的顺序，应为从左向右排
 */
- (TBBarButtonContainerView *)tb_baseLeftBarButtonView;
- (void)tb_baseSetLeftBarButtonViews:(NSArray <UIView *> *)views leftSpaceWidth:(CGFloat)leftSpaceWidth;
- (void)tb_baseSetLeftBarButtonViews:(NSArray <UIView *> *)views;

/*
 * 自定义导航栏右侧按钮视图，调整右侧边距，rightSpaceWidth应为负数，默认为-16
 * 注意views里的元素是UIView类型而不是UIBarButtonItem类型
 * 注意views中视图的顺序，应为从右向左排
 */
- (TBBarButtonContainerView *)tb_baseRightBarButtonView;
- (void)tb_baseSetRightBarButtonViews:(NSArray <UIView *> *)views rightSpaceWidth:(CGFloat)rightSpaceWidth;
- (void)tb_baseSetRightBarButtonViews:(NSArray <UIView *> *)views;

@end

NS_ASSUME_NONNULL_END
