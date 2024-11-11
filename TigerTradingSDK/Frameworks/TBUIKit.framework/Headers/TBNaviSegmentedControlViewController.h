//
//  TBNaviSegmentedControlViewController.h
//  Stock
//
//  Created by DepthFirst on 2019/6/12.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBContentBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

// 兼容已有用法, 改文件名, 改引用处代码后可删除
//@class TBNavigationSegmentPageViewController;
//@compatibility_alias TBNaviSegmentedControlViewController TBNavigationSegmentPageViewController;

// TODO: 改文件名
@interface TBNaviSegmentedControlViewController : TBContentBaseViewController

@property (nonatomic, strong, readonly) CAGradientLayer *gradientLayer;

// TODO: 后添加
/// udpate view controllers
- (void)updateViewControllers:(NSArray<UIViewController *> *)viewControllers;
//

/*
 更新tab小红点
 titls表示 哪些title带有小红点
 */
- (void)updateRedPoint:(NSArray<NSString *> *)titles;

@property (nonatomic, assign) BOOL applyA1NavigationBarColor;

/// 是否使用8.0外观，子类重新
@property (nonatomic, assign, readonly) BOOL v80Appearance;
@property (nonatomic, strong, readonly) UIColor *v80backgroundColor;
@end

NS_ASSUME_NONNULL_END
