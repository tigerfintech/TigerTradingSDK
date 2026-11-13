//
//  TBDemoNewsListViewController.m
//  TigerQuoteSDK
//

#import "TBDemoNewsListViewController.h"
#import <MJRefresh/MJRefresh.h>
#import <TBUIKit/UIViewController+Navigation.h>

@interface TBDemoNewsListViewController () <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong, readwrite) UITableView *newsTable;
@property (nonatomic, strong) NSMutableArray<NSString *> *rows;
@property (nonatomic, strong) UIView *topBar;
@property (nonatomic, strong) UIButton *backButton;
@property (nonatomic, strong) UILabel *titleLabel;
@end

@implementation TBDemoNewsListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor systemPurpleColor];
    [self setupTopBar];
    self.rows = [NSMutableArray array];
    for (NSInteger i = 1; i <= 20; i++) {
        [self.rows addObject:[NSString stringWithFormat:@"资讯 #%ld (初始)", (long)i]];
    }

    // frame 统一由 viewDidLayoutSubviews 管（要给顶部自绘导航条让位），不用 autoresizingMask。
    self.newsTable = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
    self.newsTable.dataSource = self;
    self.newsTable.delegate = self;
    self.newsTable.rowHeight = 60;
    [self.view addSubview:self.newsTable];

    __weak typeof(self) weakSelf = self;
    self.newsTable.mj_footer = [MJRefreshAutoNormalFooter footerWithRefreshingBlock:^{
        __strong typeof(weakSelf) strongSelf = weakSelf;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)),
                       dispatch_get_main_queue(), ^{
            NSInteger base = strongSelf.rows.count;
            for (NSInteger i = 1; i <= 10; i++) {
                [strongSelf.rows addObject:
                 [NSString stringWithFormat:@"资讯 #%ld (loadMore)", (long)(base + i)]];
            }
            [strongSelf.newsTable reloadData];
            [strongSelf.newsTable.mj_footer endRefreshing];
        });
    }];
}

/// 自绘顶部导航条。
/// SDK 环境下系统导航栏是关闭的（TBUIKit 给 UIViewController 的 -hideNavigationBar 默认
/// 返回 YES，TB 自家页面都自绘导航栏），所以宿主页面要自己画标题和返回按钮。
/// 不要试图覆写 -hideNavigationBar 打开系统导航栏 —— TBNavigationController 用的
/// TBNavigationBar 会往 UINavigationBar 上直接 addSubview，新版 iOS 会在
/// -[UINavigationBar layoutSubviews] 断言崩溃。
- (void)setupTopBar {
    self.topBar = [[UIView alloc] init];
    self.topBar.backgroundColor = [UIColor colorWithWhite:0.12 alpha:1.0];
    [self.view addSubview:self.topBar];

    self.backButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [self.backButton setTitle:@"< 返回" forState:UIControlStateNormal];
    [self.backButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.backButton addTarget:self action:@selector(backAction) forControlEvents:UIControlEventTouchUpInside];
    [self.topBar addSubview:self.backButton];

    self.titleLabel = [[UILabel alloc] init];
    self.titleLabel.text = self.title;
    self.titleLabel.textColor = [UIColor whiteColor];
    self.titleLabel.textAlignment = NSTextAlignmentCenter;
    [self.topBar addSubview:self.titleLabel];
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    CGFloat width = self.view.bounds.size.width;
    CGFloat topInset = self.view.safeAreaInsets.top;
    CGFloat barHeight = topInset + 44;

    self.topBar.frame = CGRectMake(0, 0, width, barHeight);
    self.backButton.frame = CGRectMake(8, topInset, 80, 44);
    self.titleLabel.frame = CGRectMake(96, topInset, width - 192, 44);
    self.newsTable.frame = CGRectMake(0, barHeight, width, self.view.bounds.size.height - barHeight);
}

/// 返回：栈里有上一页就 pop，自己是根（present 进来的）就 dismiss。
/// SDK 用 isPushStyle:YES 做的是自定义转场，所以走 TBUIKit 的 -tbDismissViewControllerAnimated:
/// 让它一并处理动画，而不是自己裸 dismiss。
- (void)backAction {
    [self tbDismissViewControllerAnimated:YES];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.rows.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellID = @"TBDemoNewsCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellID];
    }
    cell.textLabel.text = self.rows[indexPath.row];
    return cell;
}

@end
