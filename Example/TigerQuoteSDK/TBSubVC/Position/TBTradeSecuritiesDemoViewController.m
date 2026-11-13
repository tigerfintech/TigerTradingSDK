//
//  TBTradeSecuritiesDemoViewController.m
//  TigerQuoteSDK_Example
//
//  Created by linbingjie on 2025/8/11.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBTradeSecuritiesDemoViewController.h"
#import "TBTradeSecuritiesSubViewController.h"
#import "PagingViewTableHeaderView.h"
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <Masonry/Masonry.h>

@import TBUIKit;
@import TBThirdParty;

@interface TBTradeSecuritiesDemoViewController ()<JXPagerViewDelegate, JXCategoryViewDelegate>

@property (nonatomic, strong) PagingViewTableHeaderView *headerView;
@property (nonatomic, strong) JXCategoryTitleView *categoryView;
@property (nonatomic, strong) JXPagerView *pagerView;
@property (nonatomic, strong) NSArray<UIViewController *> *viewControllers;

@end

@implementation TBTradeSecuritiesDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // 顶部 header label
    self.headerView = [[PagingViewTableHeaderView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 100)];

    // CategoryView
    self.categoryView = [[JXCategoryTitleView alloc] init];
    self.categoryView.titles = @[@"证券页", @"子页面"];
    self.categoryView.titleColor = [UIColor darkGrayColor];
    self.categoryView.titleSelectedColor = [UIColor blackColor];
    self.categoryView.delegate = self;
    
    JXCategoryIndicatorLineView *line = [[JXCategoryIndicatorLineView alloc] init];
    line.indicatorColor = UIColor.blackColor;
    self.categoryView.indicators = @[line];

    // 子 VC
    UIViewController *tradeVC = [TigerTradingTradeManager fetchTradeSecuritiesPageViewControllerWithAsset:YES disableRefreshHeader:YES];
    TBTradeSecuritiesSubViewController *subVC = [[TBTradeSecuritiesSubViewController alloc] init];
    self.viewControllers = @[tradeVC, subVC];

    // pagerView
    self.pagerView = [[JXPagerView alloc] initWithDelegate:self];
    [self.view addSubview:self.pagerView];
    [self.pagerView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.view.mas_top).offset(100);
        make.leading.trailing.equalTo(self.view);
        make.bottom.mas_equalTo(self.view.mas_safeAreaLayoutGuideBottom);
    }];
    
    self.categoryView.listContainer = (id<JXCategoryViewListContainer>)self.pagerView.listContainerView;
}

#pragma mark - JXPagerViewDelegate

- (UIView *)tableHeaderViewInPagerView:(JXPagerView *)pagerView {
    return self.headerView; 
}

- (NSUInteger)tableHeaderViewHeightInPagerView:(JXPagerView *)pagerView {
    return 100;
}

- (UIView *)viewForPinSectionHeaderInPagerView:(JXPagerView *)pagerView {
    return self.categoryView; 
}

- (NSUInteger)heightForPinSectionHeaderInPagerView:(JXPagerView *)pagerView {
    return 44;
}

- (NSInteger)numberOfListsInPagerView:(JXPagerView *)pagerView {
    return self.viewControllers.count;
}

- (id<JXPagerViewListViewDelegate>)pagerView:(JXPagerView *)pagerView initListAtIndex:(NSInteger)index {
    return (id<JXPagerViewListViewDelegate>)self.viewControllers[index];
}

- (void)pagerView:(JXPagerView *)pagerView mainTableViewDidScroll:(UIScrollView *)scrollView {
    
}

@end
