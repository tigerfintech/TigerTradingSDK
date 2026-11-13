//
//  TB23SDKPlaceOrderCustomAccountDataViewController.m
//  TigerQuoteSDK
//
//  Created by chenxin on 2025/8/22.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TB23SDKPlaceOrderCustomAccountDataViewController.h"
#import <TigerTradingSDK/TigerTradingTradeManager.h>

@import TBUIKit;

@interface TB23SDKPlaceOrderCustomAccountDataViewController ()

@property (nonatomic, strong) TBSegmentedControl *segmentedControl;

@property (nonatomic, strong) UIViewController *stockPositionVC;

@property (nonatomic, strong) UIViewController *stockOrderVC;

@property (nonatomic, assign) CGFloat orderContentHeight;
@property (nonatomic, assign) CGFloat positionContentHeight;

@end

@implementation TB23SDKPlaceOrderCustomAccountDataViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    @TB_weakify(self);
    self.stockPositionVC = [TigerTradingTradeManager positionViewControllerWithScrollEnabled:NO countChanged:^(NSInteger count) {
        @TB_strongify(self);
        [self.segmentedControl setTitle:[NSString stringWithFormat:@"%@(%ld)", @"持仓股票", (long)count] forSegmentAtIndex:0];
    } contentHeightUpdated:^(CGFloat contentHeight) {
        @TB_strongify(self);
        if (self.positionContentHeight == ceil(contentHeight)) {
            return;
        }
        self.positionContentHeight = contentHeight;
        
        if (self.segmentedControl.selectedSegmentIndex == 0) {
            [self refreshSizeIfNeeded];
        }
    }];
    
    self.stockOrderVC = [TigerTradingTradeManager orderViewControllerWithScrollEnabled:NO countChanged:^(NSInteger count) {
        @TB_strongify(self);
        [self.segmentedControl setTitle:[NSString stringWithFormat:@"%@(%ld)", @"今日订单", (long)count] forSegmentAtIndex:1];
    } contentHeightUpdated:^(CGFloat contentHeight) {
        @TB_strongify(self);
        if (self.orderContentHeight == ceil(contentHeight)) {
            return;
        }
        self.orderContentHeight = contentHeight;
        
        if (self.segmentedControl.selectedSegmentIndex == 1) {
            [self refreshSizeIfNeeded];
        }
    }];
    
    [self createSubviews];
}

#pragma mark - UI

- (void)createSubviews {
    [self.view addSubview:self.segmentedControl];
    [self.segmentedControl mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.equalTo(self.view).offset(k_LeftOffset);
        make.trailing.mas_equalTo(-k_LeftOffset);
        make.top.equalTo(self.view).offset(20);
        make.height.equalTo(@(kSegmentHeight30));
    }];
    
    [self addChildViewController:self.stockPositionVC];
    [self.view addSubview:self.stockPositionVC.view];
    [self.stockPositionVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.trailing.bottom.equalTo(self.view);
        make.top.equalTo(self.segmentedControl.mas_bottom).offset(15);
    }];
    
    [self addChildViewController:self.stockOrderVC];
    [self.view addSubview:self.stockOrderVC.view];
    [self.stockOrderVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
        make.leading.trailing.bottom.equalTo(self.view);
        make.top.equalTo(self.segmentedControl.mas_bottom).offset(15);
    }];
    self.stockOrderVC.view.hidden = YES;
}

#pragma mark - Action

- (void)actionSegmentedControlValueChanged:(UISegmentedControl *)segmentedControl {
    switch (segmentedControl.selectedSegmentIndex) {
        case 0:
            self.stockPositionVC.view.hidden = NO;
            self.stockOrderVC.view.hidden = YES;
            break;
        case 1:
            self.stockPositionVC.view.hidden = YES;
            self.stockOrderVC.view.hidden = NO;
            break;
        case 2:
            self.stockPositionVC.view.hidden = YES;
            self.stockOrderVC.view.hidden = YES;
            break;
            
        default:
            break;
    }
    
    [self refreshSizeIfNeeded];
}

/// SDK逻辑：持仓数据变化后，刷新size
- (void)refreshSizeIfNeeded {
    if (self.updateContentHeightBlock) {
        self.updateContentHeightBlock(self.contentHeight);
    }
}

- (CGFloat)contentHeight {
    CGFloat segmentControlTopMargin = 20;
    CGFloat segmentControlHeight = kSegmentHeight30;
    CGFloat segmentControlBottomMargin = 15;
    CGFloat currentVCHeight = self.segmentedControl.selectedSegmentIndex == 0 ? self.positionContentHeight : self.orderContentHeight;
    CGFloat maxHeight = MAX(segmentControlTopMargin + segmentControlHeight + segmentControlBottomMargin + currentVCHeight, 380);
    return maxHeight;
}

#pragma mark - Property

- (UISegmentedControl *)segmentedControl {
    if (!_segmentedControl) {
        NSArray *items = @[@"持仓股票", @"今日订单", @"资产"];
        TBSegmentedControl *segmentedControl = [[TBSegmentedControl alloc] initWithItems:items];
        [segmentedControl setSegmentCustomUI_NOAdjustFont];
        segmentedControl.selectedSegmentIndex = 0;
        [segmentedControl addTarget:self action:@selector(actionSegmentedControlValueChanged:) forControlEvents:UIControlEventValueChanged];
        _segmentedControl = segmentedControl;
    }
    return _segmentedControl;
}
@end
