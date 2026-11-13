//
//  TBSubOrderFilterViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/9/19.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBSubOrderFilterViewController.h"
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <Masonry/Masonry.h>

@interface TBSubOrderFilterViewController ()

@end

@implementation TBSubOrderFilterViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor blueColor];
    
    
    UIViewController *vc;
    if (self.isConditionOrder) {
        vc = [TigerTradingTradeManager fetchTradeConditionOrderListFilterViewController];
    }
    else {
        vc = [TigerTradingTradeManager fetchTradeOrderListFilterViewController];
    }
    [self.view addSubview:vc.view];
    [self addChildViewController:vc];
    [vc.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.trailing.mas_equalTo(0);
        make.top.mas_equalTo(self.view.mas_top).offset(150);
        make.bottom.equalTo(self.view.mas_bottom);
    }];

}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
