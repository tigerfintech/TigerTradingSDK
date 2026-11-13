//
//  TBOptionChainPageViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 2025/2/20.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBOptionChainPageViewController.h"
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <Masonry/Masonry.h>

@interface TBOptionChainPageViewController ()

@end

@implementation TBOptionChainPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    self.navigationController.navigationBar.hidden = YES;
    
    TigerTradingOptionChainModel *model = [[TigerTradingOptionChainModel alloc] init];
    model.symbol = @"TSLA";
    model.market = @"US";
    model.optionSymbol = @"TSLA";
    model.hiddenNavBar = YES;
    model.isIndex = NO;

    NSMutableString *str = [NSMutableString string];
    [str appendFormat:@"期权链参数"];
    // 拼接每个属性到字符串中
    [str appendFormat:@"symbol: %@\n", model.symbol];
    [str appendFormat:@"market: %@\n", model.market];
    [str appendFormat:@"optionSymbol: %@\n", model.optionSymbol];
    [str appendFormat:@"hiddenNavBar: %d\n", model.hiddenNavBar];
    [str appendFormat:@"isIndex: %d\n", model.isIndex];
        
    // 如果需要分隔符，可以在这里添加
    [str appendString:@"\n------------------------\n"];

    
    UIViewController *vc = [TigerTradingQuoteManager optionChainViewController:model fromViewController:self];

//    UIViewController *vc = [TigerTradingQuoteManager optionChainPage:<#(nonnull NSString *)#> market:<#(nonnull NSString *)#> latestPrice:<#(nonnull NSNumber *)#>];
//    self.usQuotevc = [TigerTradingQuoteManager openchain: TigerTradingMarketUS navigationHidden:YES fromViewController:self];
//    
    [self addChildViewController:vc];
    [self.view addSubview:vc.view];
    [vc.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.and.trailing.mas_equalTo(self.view);
        make.top.mas_equalTo(self.view.mas_top).offset(30);
        make.bottom.mas_equalTo(self.view.mas_safeAreaLayoutGuideBottom);
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
