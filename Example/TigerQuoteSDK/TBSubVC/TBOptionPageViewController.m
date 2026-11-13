//
//  TBOptionPageViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/2/26.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBOptionPageViewController.h"
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <Masonry/Masonry.h>

@interface TBOptionPageViewController ()

@end

@implementation TBOptionPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor grayColor];
    
    UIViewController *vc = [TigerTradingQuoteManager optionPageControllerHiddenNavBar:YES fromViewController:self];
    [self addChildViewController:vc];
    [self.view addSubview:vc.view];
    [vc.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.and.trailing.mas_equalTo(self.view);
        make.top.mas_equalTo(self.view.mas_top).offset(150);
        make.bottom.mas_equalTo(self.view.mas_bottom);
    }];

}


@end
