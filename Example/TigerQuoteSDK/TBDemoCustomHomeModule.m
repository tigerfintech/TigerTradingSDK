//
//  TBDemoCustomHomeModule.m
//  TigerQuoteSDK
//

#import "TBDemoCustomHomeModule.h"
#import <TigerTradingSDK/TigerTradingSDKHomeModuleItem.h>

/// 常量:压缩 / 展开两档高度。用于演示切换 + reload。
static const CGFloat kTBDemoCompactHeight = 200;
static const CGFloat kTBDemoExpandedHeight = 400;

@interface TBDemoCustomHomeModule ()
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) UILabel *statusLabel;
/// 保留最近一次返回的 item 引用,让"切换高度"按钮的 action 能拿到调 -reload。
/// 也可以用 moduleType 走 registry,这里持有实例只是方便。
@property (nonatomic, strong, nullable) TigerTradingSDKHomeModuleItem *latestItem;
@property (nonatomic, assign) BOOL expanded;
@end

@implementation TBDemoCustomHomeModule

- (TigerTradingSDKHomeModuleItem *)currentItem {
    if (!self.contentView) {
        [self buildContentView];
    }

    TigerTradingSDKHomeModuleItem *item = [[TigerTradingSDKHomeModuleItem alloc] init];
    item.moduleType = @"CUSTOM_NEWS";
    item.title = @"Custom News";
    item.customView = self.contentView;
    item.contentHeight = self.expanded ? kTBDemoExpandedHeight : kTBDemoCompactHeight;
    item.viewMoreBlock = ^(UIViewController *fromVC) {
        // 真实接入时,通常 push 资讯列表 / present 详情。
    };
    item.reloadBlock = ^{
        // 下拉刷新触发;host 重拉数据后调用 [item reload] 让 SDK 刷新该 section。
    };
    item.moduleUpdateBlock = ^{
        // 切换账户 / 语言时回调,host 可在此重做本地化或重新渲染。
    };

    self.latestItem = item;
    return item;
}

#pragma mark - Private

/// 一次性构建 customView:红色背景 + 状态 label + 切换高度按钮。
- (void)buildContentView {
    UIView *contentView = [[UIView alloc] init];
    contentView.backgroundColor = [UIColor systemRedColor];

    UILabel *statusLabel = [[UILabel alloc] init];
    statusLabel.text = [NSString stringWithFormat:@"Custom News · height=%.0f", kTBDemoCompactHeight];
    statusLabel.textColor = [UIColor whiteColor];
    statusLabel.textAlignment = NSTextAlignmentCenter;
    statusLabel.translatesAutoresizingMaskIntoConstraints = NO;
    [contentView addSubview:statusLabel];

    UIButton *toggleBtn = [UIButton buttonWithType:UIButtonTypeSystem];
    [toggleBtn setTitle:@"Expand ↓ (test reload)" forState:UIControlStateNormal];
    [toggleBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    toggleBtn.titleLabel.font = [UIFont boldSystemFontOfSize:14];
    toggleBtn.layer.borderColor = [UIColor whiteColor].CGColor;
    toggleBtn.layer.borderWidth = 1;
    toggleBtn.layer.cornerRadius = 6;
    toggleBtn.contentEdgeInsets = UIEdgeInsetsMake(6, 12, 6, 12);
    toggleBtn.translatesAutoresizingMaskIntoConstraints = NO;
    [toggleBtn addTarget:self action:@selector(tb_toggleHeight:) forControlEvents:UIControlEventTouchUpInside];
    [contentView addSubview:toggleBtn];

    [NSLayoutConstraint activateConstraints:@[
        [statusLabel.centerXAnchor constraintEqualToAnchor:contentView.centerXAnchor],
        [statusLabel.centerYAnchor constraintEqualToAnchor:contentView.centerYAnchor constant:-20],
        [toggleBtn.centerXAnchor constraintEqualToAnchor:contentView.centerXAnchor],
        [toggleBtn.topAnchor constraintEqualToAnchor:statusLabel.bottomAnchor constant:16],
    ]];

    self.contentView = contentView;
    self.statusLabel = statusLabel;
}

/// 演示 -reload:切换 contentHeight → 更新 label & 按钮文案 → 调 [item reload]。
/// SDK 会通过 TBHomePageComponentService 反向调用 tbhomepage 的 registry,
/// 精确刷新该 moduleType 对应的 wrapper VC(不会 re-pull customHomePageModules)。
- (void)tb_toggleHeight:(UIButton *)sender {
    self.expanded = !self.expanded;
    CGFloat newHeight = self.expanded ? kTBDemoExpandedHeight : kTBDemoCompactHeight;

    self.statusLabel.text = [NSString stringWithFormat:@"Custom News · height=%.0f", newHeight];
    NSString *btnTitle = self.expanded ? @"Collapse ↑ (test reload)" : @"Expand ↓ (test reload)";
    [sender setTitle:btnTitle forState:UIControlStateNormal];

    // 关键两步:同步 item 状态 + 通知 SDK 刷新
    self.latestItem.contentHeight = newHeight;
    [self.latestItem reload];
}

@end
