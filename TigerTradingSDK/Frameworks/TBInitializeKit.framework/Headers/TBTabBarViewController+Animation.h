//
//  TBTabBarViewController+Animation.h
//  Stock
//
//  Created by wind on 2022/5/24.
//  Copyright © 2022 com.tigerbrokers. All rights reserved.
//

#import "TBTabBarViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTabBarViewController (Animation)

- (void)showHomePageAnimationWithTop:(BOOL)top;

// 移除之前 tabBar 上的动画视图
- (void)removeAnimationView;

// 显示所有的 icon 图片
- (void)showTabBarImageView;

@end

NS_ASSUME_NONNULL_END
