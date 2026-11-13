//
//  TBSubMarketIndicesViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/8/11.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBSubMarketIndicesViewController.h"
#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import <Masonry/Masonry.h>

@interface TBSubMarketIndicesViewController ()

@end

@implementation TBSubMarketIndicesViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    self.view.backgroundColor = [UIColor systemPinkColor];
    
    UIViewController *usVC = [TigerTradingQuoteManager fetchUSIndicesSectorVC];
    [self addChildViewController:usVC];
    [self.view addSubview:usVC.view];
    [usVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.and.trailing.mas_equalTo(self.view);
        make.top.mas_equalTo(self.view.mas_top).offset(100);
        make.height.mas_equalTo(150);
    }];

}

@end
