//
//  TBTabBarBaseController.h
//  TBUIKit
//
//  Created by 董恭甫 on 2024/1/4.
//

#import <TBUIKit/TBContentBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTabBarBaseController : TBContentBaseViewController

@property (nonatomic, readonly, strong) UITabBar *tabBar;

@property (nullable, nonatomic, weak) id<UITabBarControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
