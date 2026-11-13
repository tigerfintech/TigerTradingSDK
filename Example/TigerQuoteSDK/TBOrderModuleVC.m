//
//  TBOrderModuleVC.m
//  TigerQuoteSDK
//
//  Created by wind on 2025/6/12.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBOrderModuleVC.h"
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <Masonry/Masonry.h>

@interface TBOrderModuleVC ()

@property (nonatomic, strong) UIViewController *orderListVC;

@end

@implementation TBOrderModuleVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self setUpOrderList];
    // Do any additional setup after loading the view.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)setUpOrderList {
    UILabel *nameLabel = [self moduleNameLabelWithText:@"订单列表模块"];
    [self.view addSubview:nameLabel];
    [nameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(100);
        make.leading.mas_equalTo(15);
        make.height.mas_offset(30);
    }];
    
    UIButton *allStatusButton = [self actionButtonWithTitle:@"ALL" sel:@selector(changeOrderStatus:)];
    allStatusButton.tag = 1;
    [self.view addSubview:allStatusButton];
    [allStatusButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(nameLabel.mas_bottom).offset(10);
        make.leading.mas_equalTo(15);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *FILLEDStatusButton = [self actionButtonWithTitle:@"FILLED" sel:@selector(changeOrderStatus:)];
    FILLEDStatusButton.tag = 2;
    [self.view addSubview:FILLEDStatusButton];
    [FILLEDStatusButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(allStatusButton);
        make.leading.mas_equalTo(allStatusButton.mas_trailing).offset(5);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *ACTIVEStatusButton = [self actionButtonWithTitle:@"ACTIVE" sel:@selector(changeOrderStatus:)];
    ACTIVEStatusButton.tag = 3;
    [self.view addSubview:ACTIVEStatusButton];
    [ACTIVEStatusButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(allStatusButton);
        make.leading.mas_equalTo(FILLEDStatusButton.mas_trailing).offset(5);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *INACTIVEButton = [self actionButtonWithTitle:@"INACTIVE" sel:@selector(changeOrderStatus:)];
    INACTIVEButton.tag = 4;
    [self.view addSubview:INACTIVEButton];
    [INACTIVEButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(allStatusButton);
        make.leading.mas_equalTo(ACTIVEStatusButton.mas_trailing).offset(5);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *allSecTypeButton = [self actionButtonWithTitle:@"ALL" sel:@selector(changOrderSecType:)];
    allSecTypeButton.tag = 1;
    [self.view addSubview:allSecTypeButton];
    [allSecTypeButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(allStatusButton.mas_bottom).offset(5);
        make.leading.mas_equalTo(allStatusButton);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *STKSecTypeButton = [self actionButtonWithTitle:@"STK" sel:@selector(changOrderSecType:)];
    STKSecTypeButton.tag = 2;
    [self.view addSubview:STKSecTypeButton];
    [STKSecTypeButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(allSecTypeButton);
        make.leading.mas_equalTo(allSecTypeButton.mas_trailing).offset(5);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *OPTSecTypeButton = [self actionButtonWithTitle:@"OPT" sel:@selector(changOrderSecType:)];
    OPTSecTypeButton.tag = 3;
    [self.view addSubview:OPTSecTypeButton];
    [OPTSecTypeButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(STKSecTypeButton);
        make.leading.mas_equalTo(STKSecTypeButton.mas_trailing).offset(5);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *oneTimeButton = [self actionButtonWithTitle:@"近一年" sel:@selector(changeOrderTime:)];
    oneTimeButton.tag = 1;
    [self.view addSubview:oneTimeButton];
    [oneTimeButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(STKSecTypeButton.mas_bottom).offset(5);
        make.leading.mas_equalTo(allStatusButton);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    UIButton *halfTimeButton = [self actionButtonWithTitle:@"近一天" sel:@selector(changeOrderTime:)];
    halfTimeButton.tag = 2;
    [self.view addSubview:halfTimeButton];
    [halfTimeButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(oneTimeButton);
        make.leading.mas_equalTo(oneTimeButton.mas_trailing).offset(5);
        make.size.mas_equalTo(CGSizeMake(80, 30));
    }];
    
    NSDate *currentDate = [NSDate date];
    NSTimeInterval secondsInOneYear = -365 * 24 * 60 * 60; // 365天的秒数
    NSDate *oneYearAgo = [currentDate dateByAddingTimeInterval:secondsInOneYear];
    
    self.orderListVC = [TigerTradingTradeManager orderListVCWithOrderStatus:@"ALL" secType:@"ALL" sinceDate:oneYearAgo toDate:currentDate];
    
    [self addChildViewController:self.orderListVC];
    [self.view addSubview:self.orderListVC.view];
    [self.orderListVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(oneTimeButton.mas_bottom).offset(15);
        make.leading.trailing.mas_equalTo(self.view);
        make.height.mas_equalTo(400);
    }];
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

- (void)changeOrderStatus:(UIButton *)button {
    NSDictionary *map = @{@(1): @"ALL",
                          @(2): @"FILLED",
                          @(3): @"ACTIVE",
                          @(4): @"INACTIVE"};
    [TigerTradingTradeManager updateOrderListVC:self.orderListVC orderStatus:map[@(button.tag)]];
}

- (void)changOrderSecType:(UIButton *)button {
    NSDictionary *map = @{@(1): @"ALL",
                          @(2): @"STK",
                          @(3): @"OPT,MLEG"};
    [TigerTradingTradeManager updateOrderListVC:self.orderListVC secType:map[@(button.tag)]];
}

- (void)changeOrderTime:(UIButton *)button {
    NSDictionary *map = @{@(1): @365,
                          @(2): @1};
    
    NSDate *currentDate = [NSDate date];
    NSTimeInterval secondsInOneYear = -[map[@(button.tag)] intValue] * 24 * 60 * 60; // 365天的秒数
    NSDate *oneYearAgo = [currentDate dateByAddingTimeInterval:secondsInOneYear];
    [TigerTradingTradeManager updateOrderListVC:self.orderListVC sinceDate:oneYearAgo toDate:currentDate];
}

@end
