//
//  RootTabVarViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/10/14.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "RootTabVarViewController.h"
#import "TB23SDKStockDetailViewController.h"
#import "TBViewController.h"
#import "TBTradeSecuritiesDemoViewController.h"
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBBaseKit/UIDevice+OrientationDevice.h>
#import "TBSDKAllFunctionViewController.h"

@interface RootTabVarViewController ()

@property (nonatomic, strong) NSArray<UIViewController *> *originalViewControllers;

@end

@implementation RootTabVarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 创建子控制器（原来的逻辑）
    TBViewController *homeVC = [[TBViewController alloc] init];
    UINavigationController *homeNav = [[UINavigationController alloc] initWithRootViewController:homeVC];
    homeNav.tabBarItem.title = @"首页";
    homeNav.tabBarItem.image = [UIImage systemImageNamed:@"house"];
    
    NSMutableArray *tabControllers = [NSMutableArray array];
    [tabControllers addObject:homeNav];
    
//    if ([TBAPPFunctionConfigManager sharedInstance].useQuoteTradeCombinedStyle) {
//        NSMutableDictionary *query = [NSMutableDictionary dictionary];
//        [query setValue:@"AAPL" forKey:@"symbol"];
//        [query setValue:@"US" forKey:@"market"];
//        [query setValue:@"STK" forKey:@"secType"];
//        
//        UIViewController *vc = [[TB23SDKStockDetailViewController alloc] initWithNavigatorURL:nil query:query];
//        UINavigationController *discoverNav = [[UINavigationController alloc] initWithRootViewController:vc];
//        discoverNav.tabBarItem.title = @"AAPL";
//        discoverNav.tabBarItem.image = [UIImage systemImageNamed:@"magnifyingglass"];
//        
//        [tabControllers addObject:discoverNav];
//    }
    
    TBTradeSecuritiesDemoViewController *tradeSecurityVC = [[TBTradeSecuritiesDemoViewController alloc] init];
    UINavigationController *tradeSecurityNav = [[UINavigationController alloc] initWithRootViewController:tradeSecurityVC];

    tradeSecurityNav.tabBarItem.title = @"持仓";
    tradeSecurityNav.tabBarItem.image = [UIImage systemImageNamed:@"person.circle"];
    
    
    UIViewController *usQuotevc = [TigerTradingQuoteManager quotePageViewController: TigerTradingMarketUS navigationHidden:YES fromViewController:self];
    
    UINavigationController *usQuoteNav = [[UINavigationController alloc] initWithRootViewController:usQuotevc];

    usQuoteNav.tabBarItem.title = @"US市场";
    usQuoteNav.tabBarItem.image = [UIImage systemImageNamed:@"chart.line.uptrend.xyaxis"];

    [tabControllers addObject:tradeSecurityNav];
    [tabControllers addObject:usQuoteNav];
    
//    [self addChildViewController:usQuotevc];
//    [self.view addSubview:self.usQuotevc.view];
//    self.usQuotevc.view.frame = CGRectMake(0, 100+offset, self.view.frame.size.width, 250);
//    [self.usQuotevc.view mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.and.trailing.mas_equalTo(self.view);
//        make.top.mas_equalTo(jumpSearchButton.mas_bottom).offset(10);
//        make.height.mas_equalTo(300);
//    }];
    
    TBSDKAllFunctionViewController *moreVC = [[TBSDKAllFunctionViewController alloc] init];
    UINavigationController *moreNav = [[UINavigationController alloc] initWithRootViewController:moreVC];

    moreNav.tabBarItem.title = @"更多";
    moreNav.tabBarItem.image = [UIImage systemImageNamed:@"line.3.horizontal"];
    [tabControllers addObject:moreNav];
    
    // 设置 tabBar 控制器
    self.viewControllers = tabControllers;
    
    // 记录原始 viewControllers
    self.originalViewControllers = self.viewControllers;
    
    // tabbar 外观可选配置
    self.tabBar.tintColor = [UIColor systemBlueColor];
    self.tabBar.unselectedItemTintColor = [UIColor grayColor];
    self.tabBar.backgroundColor = [UIColor whiteColor];
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

#pragma mark - 拦截 viewControllers 设置
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    // iOS 16+: setNeedsUpdateOfSupportedInterfaceOrientations 是同步触发方向重查询的 API，
    // 必须在 viewWillAppear 调用（dismiss 动画 setup 前），才能在动画第一帧渲染前生效。
    // 配合上面 supportedInterfaceOrientations 返回 portrait，系统会在 dismiss 设置阶段就切回竖屏。
    if (@available(iOS 16.0, *)) {
        [self setNeedsUpdateOfSupportedInterfaceOrientations];
    } else {
        [UIDevice switchNewOrientation:UIInterfaceOrientationPortrait];
    }

    [self checkTabBarControllers];
}

- (void)checkTabBarControllers {
    if (self.viewControllers.count != self.originalViewControllers.count) {
        NSLog(@"⚠️ Tab 数量异常，自动恢复原始数量");
        self.viewControllers = self.originalViewControllers;
    }
    NSLog(@"✅ 当前 Tab 数量: %lu", (unsigned long)self.viewControllers.count);
}

@end
