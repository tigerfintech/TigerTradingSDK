//
//  TBUserAccountPageViewController.m
//  TigerQuoteSDK_Example
//
//  Created by linbingjie on 2025/9/17.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBUserAccountPageViewController.h"
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <Masonry/Masonry.h>

@interface TBUserAccountPageViewController ()

@end

@implementation TBUserAccountPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor systemTealColor];

    
    NSInteger offset = 0;
    if (self.navigationController) {
        offset = 100;
    }
    else {
        offset = 60;
    }
 
    
    UIViewController *userAccountPageViewController = [TigerTradingTradeManager fetchUserAccountPage];
    [self addChildViewController:userAccountPageViewController];
    [self.view addSubview:userAccountPageViewController.view];
//    self.usQuotevc.view.frame = CGRectMake(0, 100+offset, self.view.frame.size.width, 250);
    [userAccountPageViewController.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.and.trailing.mas_equalTo(self.view);
        make.top.mas_equalTo(self.view.mas_top).offset(offset);
        make.bottom.mas_equalTo(self.view.mas_safeAreaLayoutGuideBottom);
    }];

    
}


@end
