//
//  TBDemoQuoteTabViewController.m
//  TigerQuoteSDK
//
//  Created by 骆鹏飞 on 2024/9/26.
//  Copyright © 2024 linbingjie. All rights reserved.
//

#import "TBDemoQuoteTabViewController.h"
#if __has_include(<TigerTradingSDK/TigerTradingQuoteManager.h>)
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#endif
#import <TBUIKit/TBNavigator.h>

#import <TigerTradingSDK/TigerTradingSDKManager.h>
@import TBUIKit;

@interface TBDemoQuoteTabViewController ()

@property (nonatomic, strong) UIViewController *usQuotevc;
@property (nonatomic, strong) UIViewController *hkQuotevc;
//@property (nonatomic, strong) UIViewController *optionQuotevc;

@property (nonatomic, strong) NSArray *pages;

@end

@implementation TBDemoQuoteTabViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    NSInteger offset = 0;
    if (self.navigationController) {
        offset = 100;
    }
    else {
        offset = 60;
        
        UIButton *cancelButton = [[UIButton alloc] initWithFrame:CGRectZero];
        [cancelButton setTitleColor:RGBCOLOR_HEX(0x333333) forState:UIControlStateNormal];
        [cancelButton setTitle:@"关闭" forState:UIControlStateNormal];
        cancelButton.titleLabel.font = FONTO(k_Font_SmallsubTitle);
        cancelButton.titleLabel.adjustsFontSizeToFitWidth = YES;
        [cancelButton addTarget:self action:@selector(didPressedToClickDismiss) forControlEvents:UIControlEventTouchUpInside];
        [self.view addSubview:cancelButton];
        [cancelButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.mas_equalTo(self.view.mas_leading);
            make.width.mas_equalTo(100);
            make.height.mas_equalTo(30);
            make.top.mas_equalTo(self.view).offset(40);
        }];
    }
    
    UILabel *lbl = [[UILabel alloc] init];
    [self.view addSubview:lbl];
    lbl.text = @"这是客户自定义嵌套SDK页面DEMO";
    lbl.textColor = [UIColor blackColor];
    [lbl mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(self.view.mas_leading).offset(15);
        make.trailing.mas_equalTo(self.view.mas_trailing);
        make.top.mas_equalTo(self.view.mas_top).offset(20+offset);
    }];
    
    
    UIButton *jumpAppleButton = [[UIButton alloc] initWithFrame:CGRectZero];
    [jumpAppleButton setTitleColor:RGBCOLOR_HEX(0x333333) forState:UIControlStateNormal];
    [jumpAppleButton setTitle:@"跳转apple" forState:UIControlStateNormal];
    jumpAppleButton.titleLabel.font = FONTO(k_Font_SmallsubTitle);
    jumpAppleButton.titleLabel.adjustsFontSizeToFitWidth = YES;
    [jumpAppleButton addTarget:self action:@selector(didPressedToClickJumpApple) forControlEvents:UIControlEventTouchUpInside];
    jumpAppleButton.layer.cornerRadius = 18.0f;
    jumpAppleButton.layer.masksToBounds = YES;
    jumpAppleButton.layer.borderColor = RGBCOLOR_HEX(0xA6A9B6).CGColor;
    jumpAppleButton.layer.borderWidth = 1.f;

    [self.view addSubview:jumpAppleButton];
    [jumpAppleButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(self.view.mas_leading).offset(15);
        make.width.mas_equalTo(100);
        make.height.mas_equalTo(30);
        make.top.mas_equalTo(lbl.mas_bottom).offset(10);
    }];

    UIButton *jumpSearchButton = [[UIButton alloc] initWithFrame:CGRectZero];
    [jumpSearchButton setTitleColor:RGBCOLOR_HEX(0x333333) forState:UIControlStateNormal];
    [jumpSearchButton setTitle:@"跳转搜索" forState:UIControlStateNormal];
    jumpSearchButton.titleLabel.font = FONTO(k_Font_SmallsubTitle);
    jumpSearchButton.titleLabel.adjustsFontSizeToFitWidth = YES;
    [jumpSearchButton addTarget:self action:@selector(didPressedToClickJumpSearch) forControlEvents:UIControlEventTouchUpInside];
    jumpSearchButton.layer.cornerRadius = 18.0f;
    jumpSearchButton.layer.masksToBounds = YES;
    jumpSearchButton.layer.borderColor = RGBCOLOR_HEX(0xA6A9B6).CGColor;
    jumpSearchButton.layer.borderWidth = 1.f;
    [self.view addSubview:jumpSearchButton];
    [jumpSearchButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(jumpAppleButton.mas_trailing).offset(15);
        make.width.mas_equalTo(100);
        make.height.mas_equalTo(30);
        make.top.mas_equalTo(jumpAppleButton.mas_top);
    }];

#if __has_include(<TigerTradingSDK/TigerTradingQuoteManager.h>)
    self.usQuotevc = [TigerTradingQuoteManager quotePageViewController: TigerTradingMarketUS navigationHidden:YES fromViewController:self];
    [self addChildViewController:self.usQuotevc];
    [self.view addSubview:self.usQuotevc.view];
//    self.usQuotevc.view.frame = CGRectMake(0, 100+offset, self.view.frame.size.width, 250);
    [self.usQuotevc.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.and.trailing.mas_equalTo(self.view);
        make.top.mas_equalTo(jumpSearchButton.mas_bottom).offset(10);
        make.height.mas_equalTo(300);
    }];
    
    self.hkQuotevc = [TigerTradingQuoteManager quotePageViewController: TigerTradingMarketHK navigationHidden:YES fromViewController:self];
    [self addChildViewController:self.hkQuotevc];
    self.hkQuotevc.view.frame = CGRectMake(0, 370+offset, self.view.frame.size.width, 250);
    [self.view addSubview:self.hkQuotevc.view];
    
    [self.hkQuotevc.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.and.trailing.mas_equalTo(self.view);
        make.top.mas_equalTo(self.usQuotevc.view.mas_bottom).offset(10);
        make.height.mas_equalTo(300);
    }];
#endif
}

- (void)didPressedToClickDismiss {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)didPressedToClickJumpApple {
    [TigerTradingQuoteManager openStockDetailPageWithSymbol:@"AAPL" market:@"US" fromViewController:self];
}

- (void)didPressedToClickJumpSearch {
    [TigerTradingSDKManager openSearchViewController:self];
}

- (void)dealloc {
    NSLog(@"dealloc");
}


///*
//#pragma mark - Navigation
//
//// In a storyboard-based application, you will often want to do a little preparation before navigation
//- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
//    // Get the new view controller using [segue destinationViewController].
//    // Pass the selected object to the new view controller.
//}
//*/
//
//
//#pragma mark - UIPageViewControllerDataSource
//
//// 返回上一个页面
//- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController {
//    NSUInteger currentIndex = [self.pages indexOfObject:viewController];
//    if (currentIndex == 0 || currentIndex == NSNotFound) {
//        return nil;
//    }
//    return self.pages[currentIndex - 1];
//}
//
//// 返回下一个页面
//- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController {
//    NSUInteger currentIndex = [self.pages indexOfObject:viewController];
//    if (currentIndex == self.pages.count - 1 || currentIndex == NSNotFound) {
//        return nil;
//    }
//    return self.pages[currentIndex + 1];
//}


@end
