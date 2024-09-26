//
//  TBQuoteTabViewController.m
//  TigerQuoteSDK
//
//  Created by 骆鹏飞 on 2024/9/26.
//  Copyright © 2024 linbingjie. All rights reserved.
//

#import "TBQuoteTabViewController.h"

#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <TBUIKit/TBNavigator.h>

@interface TBQuoteTabViewController ()

@property (nonatomic, strong) UIViewController *usQuotevc;
@property (nonatomic, strong) UIViewController *hkQuotevc;
@property (nonatomic, strong) UIViewController *optionQuotevc;

@property (nonatomic, strong) NSArray *pages;

@end

@implementation TBQuoteTabViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.usQuotevc = [TigerTradingQuoteManager quotePageViewController: TigerTradingMarketUS];
    self.hkQuotevc = [TigerTradingQuoteManager quotePageViewController: TigerTradingMarketHK];
    self.optionQuotevc = [TigerTradingQuoteManager optionPageController];
    
    // 保存两个视图控制器到数组
       self.pages = @[self.usQuotevc, self.optionQuotevc, self.hkQuotevc];
       
       // 设置数据源为当前类
       self.dataSource = self;
       
       // 设置第一个展示的页面
       [self setViewControllers:@[self.usQuotevc] direction:UIPageViewControllerNavigationDirectionForward animated:YES completion:nil];
    
    [[TBNavigator navigator] setRootViewController:self];

}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/


#pragma mark - UIPageViewControllerDataSource

// 返回上一个页面
- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController {
    NSUInteger currentIndex = [self.pages indexOfObject:viewController];
    if (currentIndex == 0 || currentIndex == NSNotFound) {
        return nil;
    }
    return self.pages[currentIndex - 1];
}

// 返回下一个页面
- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController {
    NSUInteger currentIndex = [self.pages indexOfObject:viewController];
    if (currentIndex == self.pages.count - 1 || currentIndex == NSNotFound) {
        return nil;
    }
    return self.pages[currentIndex + 1];
}


@end
