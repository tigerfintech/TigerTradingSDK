//
//  TBOpportunityViewController.m
//  TigerQuoteSDK
//
//  Created by wind on 2025/2/12.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBModuleViewController.h"
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <TBBaseKit/UIView+Sizes.h>
#import <Masonry/Masonry.h>

@interface TBModuleViewController ()

@property (nonatomic, strong) UIScrollView *scrollView;

@property (nonatomic, strong) UIViewController *assetVC;

@end

@implementation TBModuleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.scrollView = [[UIScrollView alloc] init];
    [self.view addSubview:self.scrollView];
    [self.scrollView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(30);
        make.leading.trailing.bottom.mas_equalTo(0);
        make.width.height.mas_equalTo(self.view);
    }];
    
    [self setupAsset];
    
    UIViewController *portfolioVC = [TigerTradingTradeManager portfolioViewController:self heightUpdateBlock:^(UIViewController * _Nonnull portfolioVC, CGFloat height) {
        [portfolioVC.view mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(height);
        }];
    }];
    UILabel *nameLabel = [self moduleNameLabelWithText:@"持仓模块"];
    [self.scrollView addSubview:nameLabel];
    [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.assetVC.view.mas_bottom).offset(15);
        make.leading.mas_equalTo(15);
        make.height.mas_equalTo(30);
    }];
    [self addChildViewController:portfolioVC];
    [self.scrollView addSubview:portfolioVC.view];
    [portfolioVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
        make.leading.trailing.mas_equalTo(self.view);
        make.height.mas_equalTo(0);
    }];
    
    UIViewController *shortcutsVC = [TigerTradingQuoteManager shortcutsViewController:@[@(TigerTradingSDKTransformersTypeCashManager), @(TigerTradingSDKTransformersTypeOrder), @(TigerTradingSDKTransformersTypeAction)]
                                                                     fromViewController:self
                                                                      heightUpdateBlock:^(UIViewController *shortcutsVC, CGFloat height) {
        [shortcutsVC.view mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(height);
        }];
    }];
    nameLabel = [self moduleNameLabelWithText:@"快捷功能模块"];
    [self.scrollView addSubview:nameLabel];
    [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(portfolioVC.view.mas_bottom).offset(15);
        make.leading.mas_equalTo(15);
        make.height.mas_equalTo(30);
    }];
    [self addChildViewController:shortcutsVC];
    [self.scrollView addSubview:shortcutsVC.view];
    [shortcutsVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
        make.leading.trailing.mas_equalTo(self.view);
        make.height.mas_equalTo(0);
    }];
    
    UIViewController *opportunityVC = [TigerTradingQuoteManager opportunityViewController:self heightUpdateBlock:^(UIViewController *opportunityVC, CGFloat height) {
        [opportunityVC.view mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(height);
        }];
    }];
    nameLabel = [self moduleNameLabelWithText:@"机会模块"];
    [self.scrollView addSubview:nameLabel];
    [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(shortcutsVC.view.mas_bottom).offset(15);
        make.leading.mas_equalTo(15);
        make.height.mas_equalTo(30);
    }];
    [self addChildViewController:opportunityVC];
    [self.scrollView addSubview:opportunityVC.view];
    [opportunityVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
        make.leading.trailing.mas_equalTo(self.view);
        make.height.mas_equalTo(0);
    }];
    
    UIViewController *briefQuoteVC = [TigerTradingTradeManager placeOrderBriefQuoteViewControllerWithMarket:@"US"
                                                                                                    secType:@"OPT"
                                                                                                     symbol:@"TSLA 20250620 245.0 CALL"
                                                                                                     fromVC:self
                                                                                          heightUpdateBlock:^(UIViewController * _Nonnull briefQuoteVC, CGFloat height) {
        [briefQuoteVC.view mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(height);
        }];
    }];
    
//    UIViewController *briefQuoteVC = [TigerTradingTradeManager placeOrderBriefQuoteViewControllerWithMarket:@"US"
//                                                                                                    secType:@"STK"
//                                                                                                     symbol:@"TSLA"
//                                                                                                     fromVC:self
//                                                                                          heightUpdateBlock:^(UIViewController * _Nonnull briefQuoteVC, CGFloat height) {
//        [briefQuoteVC.view mas_updateConstraints:^(MASConstraintMaker *make) {
//            make.height.mas_equalTo(height);
//        }];
//    }];
    
    nameLabel = [self moduleNameLabelWithText:@"下单行情模块"];
    [self.scrollView addSubview:nameLabel];
    [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(opportunityVC.view.mas_bottom).offset(15);
        make.leading.mas_equalTo(15);
        make.height.mas_equalTo(30);
    }];
    [self addChildViewController:briefQuoteVC];
    [self.scrollView addSubview:briefQuoteVC.view];
    [briefQuoteVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
        make.leading.trailing.mas_equalTo(self.view);
        make.height.mas_equalTo(0);
    }];
    
    UIViewController *optionChannelVC = [TigerTradingQuoteManager optionChannelViewController];
    nameLabel = [self moduleNameLabelWithText:@"期权频道模块"];
    [self.scrollView addSubview:nameLabel];
    [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(briefQuoteVC.view.mas_bottom).offset(15);
        make.leading.mas_equalTo(15);
        make.height.mas_equalTo(30);
    }];
    [self addChildViewController:optionChannelVC];
    [self.scrollView addSubview:optionChannelVC.view];
    [optionChannelVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
        make.leading.trailing.mas_equalTo(self.view);
        make.height.mas_equalTo(400);
    }];
    
    UIViewController *askBidVC = [TigerTradingTradeManager askBidViewControllerWithMarket:@"US" secType:@"STK" symbol:@"TQQQ" heightUpdateBlock:^(UIViewController * _Nonnull askBidVC, CGFloat height) {
        [askBidVC.view mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(height);
        }];
    }];
    if (askBidVC) {
        nameLabel = [self moduleNameLabelWithText:@"下单买卖盘模块"];
        [self.scrollView addSubview:nameLabel];
        [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(optionChannelVC.view.mas_bottom).offset(15);
            make.leading.mas_equalTo(15);
            make.height.mas_equalTo(30);
        }];
        [self addChildViewController:askBidVC];
        [self.scrollView addSubview:askBidVC.view];
        [askBidVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
            make.leading.trailing.mas_equalTo(self.view);
            make.height.mas_equalTo(0);
            make.bottom.mas_equalTo(-15);
        }];
    }
    
    // Do any additional setup after loading the view.
}

- (void)setupAsset {
    UILabel *nameLabel = [self moduleNameLabelWithText:@"资产模块"];
    [self.scrollView addSubview:nameLabel];
    [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(15);
        make.leading.mas_equalTo(15);
        make.height.mas_equalTo(30);
    }];

    UIButton *buttonShowAsset = [self actionButtonWithTitle:@"展示资产" sel:@selector(showAsset)];
    [self.scrollView addSubview:buttonShowAsset];
    [buttonShowAsset mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
        make.leading.mas_equalTo(15);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *buttonHideAsset = [self actionButtonWithTitle:@"隐藏资产" sel:@selector(hideAsset)];
    [self.scrollView addSubview:buttonHideAsset];
    [buttonHideAsset mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(buttonShowAsset);
        make.leading.mas_equalTo(buttonShowAsset.mas_trailing).offset(15);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *buttonShowAssetVisibleButton = [self actionButtonWithTitle:@"展示按钮" sel:@selector(showAssetButton)];
    [self.scrollView addSubview:buttonShowAssetVisibleButton];
    [buttonShowAssetVisibleButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(buttonShowAsset);
        make.leading.mas_equalTo(buttonHideAsset.mas_trailing).offset(15);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *buttonHideAssetVisibleButton = [self actionButtonWithTitle:@"隐藏按钮" sel:@selector(hideAssetButton)];
    [self.scrollView addSubview:buttonHideAssetVisibleButton];
    [buttonHideAssetVisibleButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(buttonShowAsset);
        make.leading.mas_equalTo(buttonShowAssetVisibleButton.mas_trailing).offset(15);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];

    UIButton *changeCurrencyButton = [self actionButtonWithTitle:@"美元" sel:@selector(changeCurrency)];
    [self.scrollView addSubview:changeCurrencyButton];
    [changeCurrencyButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(buttonShowAsset.mas_bottom).offset(5);
        make.leading.mas_equalTo(buttonShowAsset);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    self.assetVC = [TigerTradingTradeManager assetViewController:self heightUpdateBlock:^(UIViewController *assetVC, CGFloat height) {
        [assetVC.view mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(height);
        }];
    }];
    
    [self addChildViewController:self.assetVC];
    [self.scrollView addSubview:self.assetVC.view];
    [self.assetVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(changeCurrencyButton.mas_bottom).offset(15);
        make.leading.trailing.mas_equalTo(self.view);
        make.height.mas_equalTo(0);
    }];
}

- (void)changeCurrency {
    [TigerTradingTradeManager updateAssetViewController:self.assetVC currency:@"USD" completion:^(BOOL success, NSString * _Nonnull currency, NSString * _Nonnull message) {
        
    }];
}

- (void)showAsset {
    [TigerTradingTradeManager updateAssetViewController:self.assetVC visible:YES];
}

- (void)hideAsset {
    [TigerTradingTradeManager updateAssetViewController:self.assetVC visible:NO];
}

- (void)showAssetButton {
    [TigerTradingTradeManager updateAssetViewController:self.assetVC showVisibleButton:YES];
}

- (void)hideAssetButton {
    [TigerTradingTradeManager updateAssetViewController:self.assetVC showVisibleButton:NO];
}

- (UIButton *)actionButtonWithTitle:(NSString *)title sel:(SEL)sel {
    UIButton *actionButton = [[UIButton alloc] init];
    actionButton.titleLabel.font = [UIFont systemFontOfSize:15];
    [actionButton addTarget:self action:sel forControlEvents:UIControlEventTouchUpInside];
    [actionButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [actionButton setTitle:title forState:UIControlStateNormal];
    return actionButton;
}

- (UILabel *)moduleNameLabelWithText:(NSString *)text {
    UILabel *nameLabel = [[UILabel alloc] init];
    nameLabel.textColor = [UIColor blackColor];
    nameLabel.text = text;
    nameLabel.font = [UIFont systemFontOfSize:20];
    return nameLabel;
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
