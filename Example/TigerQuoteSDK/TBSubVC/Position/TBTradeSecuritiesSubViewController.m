//
//  TBTradeSecuritiesSubViewController.m
//  TigerQuoteSDK_Example
//
//  Created by wind on 2025/10/20.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBTradeSecuritiesSubViewController.h"
#import <Masonry/Masonry.h>

@import TBUIKit;
@import TBThirdParty;

@interface TBTradeSecuritiesSubViewController () <JXPagerViewListViewDelegate, UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, copy) void (^scrollCallback)(UIScrollView *scrollView);
@end

@implementation TBTradeSecuritiesSubViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.tableView = [[UITableView alloc] init];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.view addSubview:self.tableView];
    [self.tableView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view);
    }];
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 30; // 测试上下滑动
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    }
    cell.textLabel.text = [NSString stringWithFormat:@"测试行 %ld", (long)indexPath.row];
    return cell;
}

#pragma mark - JXPagerViewListViewDelegate
- (UIView *)listView {
    return self.view;
}

- (UIScrollView *)listScrollView {
    return self.tableView;
}

- (void)listViewDidScrollCallback:(void (^)(UIScrollView *scrollView))callback {
    self.scrollCallback = callback;
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    if (self.scrollCallback) {
        self.scrollCallback(scrollView);
    }
}

@end
