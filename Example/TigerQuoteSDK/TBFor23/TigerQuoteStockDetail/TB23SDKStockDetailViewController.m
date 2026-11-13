////
////  TB23SDKStockDetailViewController.m
////  TBStockBusiness
////
////  Created by chenxin on 2025/7/25.
////
//
//#import "TB23SDKStockDetailViewController.h"
//#import <TigerTradingSDK/TBQuoteTradeCombinedViewController.h>
//#import <TigerTradingSDK/TigerQuoteSDKModel.h>
//#import <TigerTradingSDK/TigerTradingTradeManager.h>
//#import "TB23SDKStockDetailBottomItemView.h"
//#import "TB23SDKStockDetailTitleView.h"
//#import "TB23SDKTradeTopView.h"
//#import <TigerTradingSDK/TigerTradingSDKManager.h>
//
//#import <TBUIKit/TBUIKit.h>
//#import <TBUIKit/TBFloatPanelSelectViewController.h>
//#import <TBPerformanceKit/TBWeakProxy.h>
//#import <TBToolsKit/TBSupportUtility.h>
//#import <TigerTradingSDK/TigerTradingSDKManager.h>
//#import <TBUIKit/MBProgressHUD+Wrapper.h>
//
//@interface TB23SDKStockDetailViewController () <TBQuoteTradeCombinedViewControllerDelegate>
//
//@property (nonatomic, copy) NSDictionary *query;
//
//@property (nonatomic, strong) TBQuoteTradeCombinedViewController *detailVC;
//
//@property (nonatomic, strong) TB23SDKStockDetailTitleView *titleView;
//
//@property (nonatomic, strong) TigerTradingSymbolDetailModel *currentDetailModel;
//
//@property (nonatomic, strong) UIButton *buyButton;
//
//@property (nonatomic, strong) UIButton *sellButton;
//
//@property (nonatomic, strong) UIButton *watchlistButton;
//
//@property (nonatomic, strong) UIButton *settingButton;
//
//@property (nonatomic, strong) UIButton *changeSubAccountButton;
//
//@property (nonatomic, strong) UILabel *accountLabel;
//@property (nonatomic, strong) UILabel *availableEELabel;
//
//@property (nonatomic, strong) TB23SDKStockDetailBottomItemView *warningView;
//
//@property (nonatomic, strong) TB23SDKStockDetailBottomItemView *moreView;
//
//@property (nonatomic, strong) TB23SDKStockDetailBottomItemView *multiLegView;
//
//@property (nonatomic, strong) UIView *quoteBottomView;
//
//@property (nonatomic, strong) UIView *customTradeCoverView;
//
//@property (nonatomic, strong) TB23SDKTradeTopView *tradeTopView;
//
//@property (nonatomic, copy) NSArray<TigerTradingSymbolDetailModel *> *symbolList;
//
//@property (nonatomic, assign) BOOL useFirstAccount;
//
//@property (nonatomic, strong) NSTimer *timer;
//
//@end
//
//@implementation TB23SDKStockDetailViewController
//
//- (instancetype)initWithNavigatorURL:(NSURL *)URL query:(NSDictionary *)query {
//    self = [super initWithNavigatorURL:URL query:query];
//    if (self) {
//        if (query[@"optionItems"] && [query[@"optionItems"] isKindOfClass:[NSArray class]] && ([query[@"optionItems"] count] == 1)) {
//            //兼容单腿策略分析里的单腿期权
//            self.query = ((NSArray *)query[@"optionItems"]).firstObject;
//        } else {
//            self.query = query;
//        }
//        self.currentDetailModel = [[TigerTradingSymbolDetailModel alloc] initWithDictionary:query];
//        
//        [self testSymbolList];
//    }
//    return self;
//}
//
//- (void)testSymbolList {
//    NSArray *array = @[
//        @{@"symbol":@"AAPL", @"secType": @"STK", @"market": @"US", @"name": @"苹果"},
//        @{@"symbol":@".IXIC", @"secType": @"STK", @"market": @"US", @"name": @"纳斯达克"},
//        @{@"symbol":@"00700", @"secType": @"STK", @"market": @"HK", @"name": @"腾讯控股"},
//        @{@"symbol":@"BK4141", @"secType": @"PLATE", @"market": @"US", @"name": @"半导体产品"},
//        @{@"symbol":@"AAPL", @"secType": @"OPT", @"market": @"US",
//          @"right": @"CALL", @"strike": @"230.0",@"expiry": @(1768539600000),},
//        @{
//            @"secType": @"MLEG",
//            @"name": @"AAPL 垂直价差 250829 225.0P/230.0P",
//            @"optionItems": @[
//                @{@"symbol":@"AAPL", @"right": @"PUT", @"strike": @"225.0",
//                  @"expiry": @(1756440000000), @"size": @"1", @"direction": @"sell"},
//                @{@"symbol":@"AAPL", @"right": @"PUT", @"strike": @"230.0",
//                  @"expiry": @(1756440000000), @"size": @"1", @"direction": @"buy"},
//            ],
//        },
//    ];
//    
//    NSMutableArray *symbolList = [NSMutableArray array];
//    for (NSDictionary *dict in array) {
//        TigerTradingSymbolDetailModel *model = [[TigerTradingSymbolDetailModel alloc] initWithDictionary:dict];
//        if (model) {
//            [symbolList addObject:model];
//        }
//    }
//    self.symbolList = symbolList;
//}
//
//- (void)viewDidLoad {
//    [super viewDidLoad];
//    // Do any additional setup after loading the view.
//    
//    TB23SDKTradeTopView *tradeTopView = [[TB23SDKTradeTopView alloc] initWithFrame:CGRectMake(0, 0, self.view.tb_width, 44)];
//    [tradeTopView addSubview:self.accountLabel];
//    [self.accountLabel mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.mas_equalTo(0);
//        make.leading.mas_equalTo(k_LeftOffset);
//    }];
//    
//    [tradeTopView addSubview:self.availableEELabel];
//    [self.availableEELabel mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.mas_equalTo(self.accountLabel.mas_bottom);
//        make.leading.mas_equalTo(k_LeftOffset);
//    }];
//    self.tradeTopView = tradeTopView;
//    
//    self.accountLabel.text = [TigerTradingTradeManager fetchCurrentTradeAccountTitleHasAccountId:YES];
//    
//    self.detailVC = [[TBQuoteTradeCombinedViewController alloc] init];
//    NSDictionary *query = [self.currentDetailModel jumpQuery];
//    self.detailVC.query = query;
//    self.detailVC.delegate = self;
//    self.detailVC.customQuoteBottomView = self.quoteBottomView;
//    
//    [self addChildViewController:self.detailVC];
//    [self.view addSubview:self.detailVC.view];
//    [self.detailVC.view mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.trailing.equalTo(self.view);
//        make.top.equalTo(self.tbNavigationBar.mas_bottom);
//        make.bottom.equalTo(self.view);
//    }];
//    [self.detailVC didMoveToParentViewController:self];
//    
//    if (self.shouldJumpToTradeTab) {
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            NSInteger placeOrderAction = [self.query[@"placeOrderAction"] integerValue];
//            
//            id positionOrOrderModel = self.query[@"position"] ?: self.query[@"order"];
//            
//            [self.detailVC gotoTradeTabWithAction:placeOrderAction positionOrOrderModel:positionOrOrderModel];
//        });
//    }
//    
//    [self tb_setRightBarButtonViews:@[self.watchlistButton, self.changeSubAccountButton]];
//    
//    [self createTitleView];
//    
//    [self createQuoteBottomSubviews];
//    [self updateQuoteBottomViewStatus];
//    
//    
//    // 初始化 Timer，使用 YYWeakProxy 来避免循环引用
//    self.timer = [NSTimer scheduledTimerWithTimeInterval:2
//                                                  target:[TBWeakProxy proxyWithTarget:self]
//                                                selector:@selector(timerDidFire)
//                                                userInfo:nil
//                                                 repeats:YES];
//    
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [self reloadTradeViewIfNeeded];
//    });
//}
//
//- (void)reloadTradeViewIfNeeded {
//    if ([TigerTradingTradeManager currentAccountIsFunded]) {
//        self.detailVC.customTradeCoverView = nil;
//        self.detailVC.customTradeHeaderView = self.tradeTopView;
//    }
//    else {
//        self.detailVC.customTradeCoverView = self.customTradeCoverView;
//    }
//    [self.detailVC reloadTradeView];
//}
//
//- (void)timerDidFire {
//    NSString *availableEE = [self.detailVC fetchAvailableEE];
//    self.availableEELabel.text = [NSString stringWithFormat:@"可用:%@", (TextValid(availableEE)?availableEE:@"0")];
//}
//
//- (void)dealloc {
//    // 清理定时器
//    if (_timer) {
//        [_timer invalidate];
//        _timer = nil;
//    }
//}
//
//- (void)createTitleView {
//    [self.tbNavigationBar addSubview:self.titleView];
//    [self.titleView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.mas_equalTo(50);
//        make.top.bottom.mas_equalTo(0);
//        make.trailing.mas_equalTo(-100);
//    }];
//}
//
//- (void)createQuoteBottomSubviews {
//    [self.quoteBottomView addSubview:self.buyButton];
//    [self.buyButton mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.mas_equalTo(k_LeftOffset);
//        make.centerY.mas_equalTo(0);
//        make.height.mas_equalTo(44);
//    }];
//    [self.quoteBottomView addSubview:self.sellButton];
//    [self.sellButton mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.equalTo(self.buyButton.mas_trailing).offset(10);
//        make.centerY.equalTo(self.buyButton);
//        make.width.height.equalTo(self.buyButton);
//    }];
//    
//    [self.quoteBottomView addSubview:self.warningView];
//    [self.warningView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.equalTo(self.sellButton.mas_trailing).offset(10);
//        make.centerY.equalTo(self.sellButton);
//        make.width.height.mas_equalTo(44);
//    }];
//    
//    [self.quoteBottomView addSubview:self.moreView];
//    [self.moreView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.leading.equalTo(self.sellButton.mas_trailing).offset(10 + 44 + 10);
//        make.centerY.equalTo(self.sellButton);
//        make.width.height.mas_equalTo(44);
//        make.trailing.mas_equalTo(-k_LeftOffset);
//    }];
//    
//    [self.quoteBottomView addSubview:self.multiLegView];
//    [self.multiLegView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.edges.equalTo(self.moreView);
//    }];
//    self.multiLegView.hidden = YES;
//}
//
//- (void)updateQuoteBottomViewStatus {
//    self.warningView.hidden = self.currentDetailModel.optionItems != nil;
//    if ((self.currentDetailModel.optionItems != nil || [self.currentDetailModel isOption])) {
//        self.moreView.hidden = YES;
//        if ([self.currentDetailModel isOption]) {
//            self.multiLegView.hidden = NO;
//        }
//    }
//    else {
//        self.multiLegView.hidden = YES;
//        self.moreView.hidden = NO;
//    }
//}
//
//- (void)changeSubAccountButtonAction {
//    [self ptb_changeSubAccount];
//}
//
//- (void)titleButtonAction {
//    [self.view endEditing:YES];
//    if (!self.symbolList || self.symbolList.count == 0) {
//        return;
//    }
//    [self showStockList];
//}
//
//- (void)showStockList {
//    NSMutableArray *array = [NSMutableArray array];
//    for (TigerTradingSymbolDetailModel *model in self.symbolList) {
//        NSString *name = model.name;
//        [array tb_safeAddObject:name];
//    }
//    
//    NSArray *cellItems = [TBFloatPanelSelectViewController generateDefaultListItemsWithTitles:array];
//    for (int i = 0; i < cellItems.count; i++) {
//        TBStockSettingChoiceCellItem *cellItem = cellItems[i];
//        cellItem.tag = i;
//        cellItem.selected = [self.currentDetailModel.name isEqualToString:array[i]];
//        cellItem.titleFont = FONTO_NOADJUST(15);
//        cellItem.selectedTitleFont = BOLDFONTO_NOADJUST(15);
//        cellItem.bottomLineLeft = k_LeftOffset;
//        cellItem.bottomLineRight = k_LeftOffset;
//        BOOL isLast = (cellItem == [cellItems lastObject]);
//        cellItem.hasBottomLine = !isLast;
//    }
//    
//    NSString *title = TBResourcesLocalizedString(@"mobile_ios_common_select_stock", nil);
//    TBFloatPanelSelectViewController *vc = [TBFloatPanelSelectViewController showWithTitle:title subtitle:@"" listItems:cellItems comfirmBtnTitle:nil cancelBtnTitle:nil comfirmClickActionBlock:^(TBStockSettingChoiceCellItem *selectedItem) {
//            
//    } cancelClickActionBlock:^(UIButton *sender) {
//                    
//    }];
//    vc.dismissWhenDidSelected = YES;
//    @TB_weakify(self);
//    vc.selectedItemDidChangedBlock = ^(TBStockSettingChoiceCellItem * _Nonnull selectedItem) {
//        @TB_strongify(self);
//        TigerTradingSymbolDetailModel *model = self.symbolList[selectedItem.tag];
//        // 必须要有secType并符合对应协议才能正确跳转
//        NSDictionary *query = [model jumpQuery];
//        [self.detailVC changeStockWithQuery:query];
//        self.currentDetailModel = model;
//        [self updateQuoteBottomViewStatus];
//    };
//}
//
//- (void)tradeButtonAction:(UIButton *)button {
//    NSInteger action = 1;
//    if (button == self.sellButton) {
//        action = 2;
//    }
//    [self.detailVC gotoTradeTabWithAction:action];
//}
//
//// 新实现：弹出设置选项
//- (void)settingButtonAction {
//    [self.view endEditing:YES];
//    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"设置选项"
//                                                                   message:@"请选择要执行的操作"
//                                                            preferredStyle:UIAlertControllerStyleActionSheet];
//    
//    UIAlertAction *openSettings = [UIAlertAction actionWithTitle:@"跳转设置页"
//                                                           style:UIAlertActionStyleDefault
//                                                         handler:^(UIAlertAction * _Nonnull action) {
//        [TigerTradingTradeManager openTradeSettingsPageFromViewController:self];
//    }];
//    
//    UIAlertAction *refreshAction = [UIAlertAction actionWithTitle:@"刷新接口estimate-quantity"
//                                                            style:UIAlertActionStyleDefault
//                                                          handler:^(UIAlertAction * _Nonnull action) {
//        [self.detailVC reloadQuantityMaxAvaliableViewModel];
//    }];
//    
//    UIAlertAction *changeSubAccount = [UIAlertAction actionWithTitle:@"切换子账号"
//                                                            style:UIAlertActionStyleDefault
//                                                          handler:^(UIAlertAction * _Nonnull action) {
//        [self ptb_changeSubAccount];
//    }];
//    
//    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
//                                                           style:UIAlertActionStyleCancel
//                                                         handler:nil];
//    
//    [alert addAction:openSettings];
//    [alert addAction:refreshAction];
//    [alert addAction:changeSubAccount];
//    [alert addAction:cancelAction];
//    
//    [self presentViewController:alert animated:YES completion:nil];
//}
//
//- (void)watchlistButtonAction {
//    [self.detailVC clickWatchlistButton];
//}
//
//- (void)warningViewAction {
//    [self.detailVC openPriceAlertPage];
//}
//
//- (void)moreViewAction {
//    [self.detailVC openMoreFunctionPage];
//}
//
//- (void)multiLegViewAction {
//    [self.detailVC openMlegTradePage];
//}
//
//- (BOOL)hasTBNavigationBar {
//    return YES;
//}
//
//- (BOOL)autoGenerateBackBarButtonItem {
//    return YES;
//}
//
//- (BOOL)enableDragBack {
//    return YES;
//}
//
//#pragma mark - TBQuoteTradeCombinedViewControllerDelegate
//
///// 标的是否能够交易
//- (void)contractTradeAble:(BOOL)tradeAble {
//    NSLog(@"⭐️⭐️⭐️ tradeable:%d", tradeAble);
//}
//
//- (void)combinedViewControllerDidChangeTabIndex:(NSInteger)tabIndex {
//    if (tabIndex == 0) {
//        [self tb_setRightBarButtonViews:@[self.watchlistButton, self.changeSubAccountButton]];
//    }
//    else {
//        [self tb_setRightBarButtonViews:@[self.settingButton]];
//    }
//}
//
//- (void)combinedViewControllerDidUpdateProduct:(NSDictionary *)dict {
//    NSLog(@"⭐️⭐️combinedViewControllerDidUpdateProduct:%@", dict);
//}
//
//- (void)combinedViewControllerTitleUpdate:(NSString *)title {
//    self.titleView.title = title;
//}
//
//- (void)combinedPlaceOrderViewControllerStartRefresh {
//    
//}
//
//- (void)combinedViewControllerSubtitleUpdateWithTime:(NSString *)time attributedPrice:(NSAttributedString *)attributedPrice {
//    self.titleView.time = time;
//    [self.titleView setAttributedPrice:attributedPrice];
//}
//
//- (void)combinedViewControllerSubtitleShouldShowPrice:(BOOL)shouldShowPrice {
//    self.titleView.shouldShowPrice = shouldShowPrice;
//}
//
//- (void)combinedViewControllerSupportsTrade:(BOOL)supportTrade {
//    if (!supportTrade) {
//        self.quoteBottomView.hidden = YES;
//    }
//    else {
//        self.quoteBottomView.hidden = NO;
//    }
//}
//
//- (void)combinedViewControllerIsInWatchlist:(BOOL)isInWatchlist {
//    self.watchlistButton.selected = isInWatchlist;
//}
//
//#pragma mark - Property
//
//- (TB23SDKStockDetailTitleView *)titleView {
//    if (!_titleView) {
//        _titleView = [[TB23SDKStockDetailTitleView alloc] init];
//        [_titleView addTarget:self action:@selector(titleButtonAction) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _titleView;
//}
//
//- (UIButton *)buyButton {
//    if (!_buyButton) {
//        _buyButton = [UIButton buttonWithStyle:TBButtonStyleYellowBackground];
//        [_buyButton setTitle:TBResourcesLocalizedString(@"mobile_comm_common_buy_in", nil) forState:UIControlStateNormal];
//        [_buyButton addTarget:self action:@selector(tradeButtonAction:) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _buyButton;
//}
//
//- (UIButton *)sellButton {
//    if (!_sellButton) {
//        _sellButton = [UIButton buttonWithStyle:TBButtonStyleYellowBackground];
//        [_sellButton setTitle:TBResourcesLocalizedString(@"mobile_comm_common_sell_out", nil) forState:UIControlStateNormal];
//        [_sellButton addTarget:self action:@selector(tradeButtonAction:) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _sellButton;
//}
//
//- (UIButton *)settingButton {
//    if (!_settingButton) {
//        _settingButton = [UIButton buttonWithType:UIButtonTypeCustom];
//        _settingButton.frame = CGRectMake(0, 0, 40, 40);
//        [_settingButton setImage:[[UIImage colorImageNamed:@"icon_nav_setting"] tintedImage] forState:UIControlStateNormal];
//        [_settingButton addTarget:self action:@selector(settingButtonAction) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _settingButton;
//}
//
//- (UIButton *)changeSubAccountButton {
//    if (!_changeSubAccountButton) {
//        _changeSubAccountButton = [UIButton buttonWithType:UIButtonTypeCustom];
//        _changeSubAccountButton.frame = CGRectMake(0, 0, 40, 40);
//        [_changeSubAccountButton setImage:[[UIImage colorImageNamed:@"icon_nav_setting"] tintedImage] forState:UIControlStateNormal];
//        [_changeSubAccountButton addTarget:self action:@selector(changeSubAccountButtonAction) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _changeSubAccountButton;
//}
//
//
//- (UIButton *)watchlistButton {
//    if (!_watchlistButton) {
//        _watchlistButton = [UIButton buttonWithType:UIButtonTypeCustom];
//        _watchlistButton.frame = CGRectMake(0, 0, 40, 40);
//        [_watchlistButton setImage:[UIImage tb_themeImageNamed:@"menu_portfolio_unselected"] forState:UIControlStateNormal];
//        [_watchlistButton setImage:[UIImage tb_themeImageNamed:@"sdk_icon_content_watchlist_selected"] forState:UIControlStateSelected];
//        [_watchlistButton addTarget:self action:@selector(watchlistButtonAction) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _watchlistButton;
//}
//
//- (UILabel *)accountLabel {
//    if (!_accountLabel) {
//        _accountLabel = [[UILabel alloc] initWithFont:MEDFONTO(14) color:COLOR_TITLE];
//    }
//    return _accountLabel;
//}
//
//- (UILabel *)availableEELabel {
//    if (!_availableEELabel) {
//        _availableEELabel = [[UILabel alloc] initWithFont:MEDFONTO(14) color:COLOR_TITLE];
//    }
//    return _availableEELabel;
//}
//
//- (TB23SDKStockDetailBottomItemView *)warningView {
//    if (!_warningView) {
//        _warningView = [[TB23SDKStockDetailBottomItemView alloc] init];
//        _warningView.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_alert", nil);
//        _warningView.imageView.image = [UIImage tb_themeImageNamed:@"trade_warming_white"];
//        [_warningView addTarget:self action:@selector(warningViewAction) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _warningView;
//}
//
//- (TB23SDKStockDetailBottomItemView *)moreView {
//    if (!_moreView) {
//        _moreView = [[TB23SDKStockDetailBottomItemView alloc] init];
//        _moreView.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_more", nil);
//        _moreView.imageView.image = [UIImage tb_themeImageNamed:@"icon_stock_detail_bottom_bar_more"];
//        [_moreView addTarget:self action:@selector(moreViewAction) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _moreView;
//}
//
//- (TB23SDKStockDetailBottomItemView *)multiLegView {
//    if (!_multiLegView) {
//        _multiLegView = [[TB23SDKStockDetailBottomItemView alloc] init];
//        _multiLegView.titleLabel.text = TBResourcesLocalizedString(@"mobile_comm_common_mleg_trading", nil);
//        _multiLegView.imageView.image = [UIImage tb_themeImageNamed:@"icon_multi_legs"];
//        [_multiLegView addTarget:self action:@selector(multiLegViewAction) forControlEvents:UIControlEventTouchUpInside];
//    }
//    return _multiLegView;
//}
//
//- (UIView *)quoteBottomView {
//    if (!_quoteBottomView) {
//        _quoteBottomView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.tb_width, 64)];
//    }
//    return _quoteBottomView;
//}
//
//- (UIView *)customTradeCoverView {
//    if (!_customTradeCoverView) {
//        _customTradeCoverView = [[UIView alloc] init];
//        _customTradeCoverView.backgroundColor = [UIColor blueColor];
//    }
//    return _customTradeCoverView;
//}
//
//@end
