//
//  TBPlaceOrderDemoViewViewController.m
//  TigerQuoteSDK
//
//  Created by 骆鹏飞 on 2024/9/26.
//  Copyright © 2024 linbingjie. All rights reserved.
//

#import "TBPlaceOrderDemoViewViewController.h"

#import <TigerTradingSDK/TigerTradingQuoteManager.h>

@interface TBPlaceOrderDemoViewViewController ()



@end

@implementation TBPlaceOrderDemoViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    UIViewController *priceVC = [TigerTradingQuoteManager placeOrderBriefQuoteViewWithSymbol:@"AAPL" secType:@"STK" market:@"US"];
    priceVC.view.frame = CGRectMake(0, 200, 340, 500);
    [self addChildViewController:priceVC];
    [self.view addSubview:priceVC.view];
    
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
