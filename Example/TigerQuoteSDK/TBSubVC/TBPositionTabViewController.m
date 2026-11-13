//
//  TBPositionTabViewController.m
//  TigerQuoteSDK_Example
//
//  Created by chenxin on 2025/5/9.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBPositionTabViewController.h"
#import <TBBaseKit/TBBaseKit.h>
#import <TBUIKit/TBUIKit.h>
#import <TigerTradingSDK/TigerTradingTradeManager.h>

@implementation TBPositionTabViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    UILabel *lbl = [[UILabel alloc] init];
    [self.view addSubview:lbl];
    lbl.text = @"客户自定义嵌套持仓页面";
    lbl.textColor = [UIColor blackColor];
    lbl.textAlignment = NSTextAlignmentCenter;
    [lbl mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.mas_equalTo(self.view.mas_leading);
        make.trailing.mas_equalTo(self.view.mas_trailing);
        make.top.mas_equalTo(self.view.mas_top).offset(64);
    }];
    
    UIViewController *vc = [TigerTradingTradeManager portfolioViewController:self heightUpdateBlock:^(UIViewController * _Nonnull portfolioVC, CGFloat height) {
        
    }];
    [self.view addSubview:vc.view];
    [self addChildViewController:vc];
    [vc.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.trailing.mas_equalTo(0);
        make.top.equalTo(lbl.mas_bottom).offset(20);
        make.bottom.equalTo(self.view.tb_mas_bottom);
    }];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

@end
