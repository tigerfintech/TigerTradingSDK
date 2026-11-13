//
//  TBOptionDetailViewController.m
//  TigerQuoteSDK_Example
//
//  Created by wind on 2025/3/7.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBOptionDetailViewController.h"
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <Masonry/Masonry.h>

@interface TBOptionDetailViewController ()

@property (nonatomic, strong) UILabel *label;

@property (nonatomic, strong) UIButton *analysisButton;

@property (nonatomic, strong) UIViewController *optionDetailVC;

@end

@implementation TBOptionDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor orangeColor];
    
    self.analysisButton = [[UIButton alloc] init];
    self.analysisButton.titleLabel.textColor = [UIColor blueColor];
    [self.analysisButton setTitle:@"策略分析" forState:UIControlStateNormal];
    [self.analysisButton addTarget:self action:@selector(analysisButtonAction) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.analysisButton];
    [self.analysisButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(20);
        make.leading.mas_equalTo(15);
    }];
    
    self.label = [[UILabel alloc] init];
    self.label.numberOfLines = 0;
    self.label.textColor = [UIColor blackColor];
    self.label.adjustsFontSizeToFitWidth = YES;
    [self.view addSubview:self.label];
    [self.label mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.analysisButton.mas_bottom).offset(20);
        make.leading.mas_equalTo(15);
        make.trailing.mas_equalTo(-15);
    }];
    
    if (self.isCombine) {
        __weak typeof(self) weakSelf = self;
        self.optionDetailVC = [TigerTradingQuoteManager combinationOptionDetailPageWithLegs:self.legsInfoArr
                                                                                   callback:^(NSString * _Nonnull time, NSString * _Nonnull lastPrice, BOOL showPriceString, NSString *combinedSymbol, NSString *combinedName) {
            weakSelf.label.text = [NSString stringWithFormat:@"time:%@ lastPrice:%@,showPriceString:%@,combinedSymbol:%@, combinedName:%@", time, lastPrice, @(showPriceString), combinedSymbol, combinedName];
        }];
        
        [self addChildViewController:self.optionDetailVC];
        [self.view addSubview:self.optionDetailVC.view];
        
        [self.optionDetailVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(self.label.mas_bottom).offset(15);
            make.leading.trailing.mas_equalTo(0);
            make.bottom.mas_equalTo(-50);
        }];
    } else {
        __weak typeof(self) weakSelf = self;
        self.optionDetailVC = [TigerTradingQuoteManager optionDetailViewControllerWithSymbol:(self.optionSymbol ? :  @"MU 20250919 120.0 PUT")
                                                                                      market:(self.market ? : @"US")
                                                                 updateTimeAndLastPriceBlock:^(NSString * _Nonnull time, NSString * _Nonnull lastPrice, BOOL showPriceString) {
            weakSelf.label.text = [NSString stringWithFormat:@"time:%@ lastPrice:%@,showPriceString:%@", time, lastPrice, @(showPriceString)];
        }];
        
        [self addChildViewController:self.optionDetailVC];
        [self.view addSubview:self.optionDetailVC.view];
        
        [self.optionDetailVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(self.label.mas_bottom).offset(15);
            make.leading.trailing.mas_equalTo(0);
            make.bottom.mas_equalTo(-50);
        }];
    }
    
    // Do any additional setup after loading the view.
}

- (void)analysisButtonAction {
    [TigerTradingQuoteManager openOptionStrategyAnalysisPageWithOptionDetailVC:self.optionDetailVC
                                                                    customView:^(UIView * _Nonnull contentView, UIButton * _Nonnull tradeBtn, UIButton * _Nonnull watchlistImageBtn, UIButton * _Nonnull watchlistTitleBtn) {
        NSLog(@"132");
    } fromViewController:self];
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
