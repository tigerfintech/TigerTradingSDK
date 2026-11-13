//
//  TBSDKDelegateDebugViewController.m
//  TigerQuoteSDK
//

#import "TBSDKDelegateDebugViewController.h"
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
#import <TBBaseKit/TBAppManager.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>

typedef NS_ENUM(NSUInteger, TBSDKDelegateDebugItemType) {
    TBSDKDelegateDebugItemTypeSelectorSwitch,
    TBSDKDelegateDebugItemTypeQuotePermission,
};

/// 每一行的数据模型
@interface TBSDKDelegateDebugItem : NSObject
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *selectorName;
@property (nonatomic, assign) TBSDKDelegateDebugItemType type;
/// 用户从未配置过时使用的默认值。YES = 默认强制 NO(模拟宿主未实现),NO = 默认放行(走宿主实现)
@property (nonatomic, assign) BOOL defaultForceNo;
+ (instancetype)itemWithTitle:(NSString *)title selectorName:(NSString *)selectorName;
+ (instancetype)itemWithTitle:(NSString *)title selectorName:(NSString *)selectorName defaultForceNo:(BOOL)defaultForceNo;
+ (instancetype)quotePermissionItem;
@end

@implementation TBSDKDelegateDebugItem

+ (instancetype)itemWithTitle:(NSString *)title selectorName:(NSString *)selectorName {
    return [self itemWithTitle:title selectorName:selectorName defaultForceNo:YES];
}

+ (instancetype)itemWithTitle:(NSString *)title selectorName:(NSString *)selectorName defaultForceNo:(BOOL)defaultForceNo {
    TBSDKDelegateDebugItem *item = [[TBSDKDelegateDebugItem alloc] init];
    item.title = title;
    item.selectorName = selectorName;
    item.type = TBSDKDelegateDebugItemTypeSelectorSwitch;
    item.defaultForceNo = defaultForceNo;
    return item;
}

+ (instancetype)quotePermissionItem {
    TBSDKDelegateDebugItem *item = [[TBSDKDelegateDebugItem alloc] init];
    item.title = @"宿主行情权限";
    item.type = TBSDKDelegateDebugItemTypeQuotePermission;
    return item;
}

@end


@interface TBSDKDelegateDebugViewController ()
@property (nonatomic, strong) NSArray<TBSDKDelegateDebugItem *> *allItems;
@property (nonatomic, strong) NSArray<TBSDKDelegateDebugItem *> *items;
@property (nonatomic, strong) NSMutableSet<NSString *> *forceNoSelectors;
@property (nonatomic, assign) TigerTradingSDKQuoteType hostQuoteType;
@property (nonatomic, copy) void (^hostQuoteTypeChangeHandler)(TigerTradingSDKQuoteType quoteType);
@end

static NSString * const kForceNoSelectorsKey = @"TBSDKDelegateDebug_forceNoSelectors";
static NSString * const kHasUserConfigKey = @"TBSDKDelegateDebug_hasUserConfig";
static NSString * const kTBSDKDelegateDebugCellIdentifier = @"TBSDKDelegateDebugCell";

@implementation TBSDKDelegateDebugViewController

- (instancetype)init {
    self = [super initWithStyle:UITableViewStyleInsetGrouped];
    if (self) {
        _allItems = [self buildItems];
        _items = _allItems;
        _forceNoSelectors = [self loadForceNoSelectors];
    }
    return self;
}

/// 读缓存;用户从未配置过则使用每一个 item 的 defaultForceNo
- (NSMutableSet<NSString *> *)loadForceNoSelectors {
    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
    if ([ud boolForKey:kHasUserConfigKey]) {
        NSArray *cached = [ud arrayForKey:kForceNoSelectorsKey];
        return [NSMutableSet setWithArray:cached ?: @[]];
    }
    NSMutableSet<NSString *> *defaults = [NSMutableSet set];
    for (TBSDKDelegateDebugItem *item in self.allItems) {
        if (item.defaultForceNo) {
            [defaults addObject:item.selectorName];
        }
    }
    return defaults;
}

- (void)saveForceNoSelectors {
    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
    [ud setBool:YES forKey:kHasUserConfigKey];
    [ud setObject:self.forceNoSelectors.allObjects forKey:kForceNoSelectorsKey];
    [ud synchronize];
}

/// 在这里注册需要调试的代理方法，新增一个方法只需加一行
- (NSArray<TBSDKDelegateDebugItem *> *)buildItems {
    return @[
        [TBSDKDelegateDebugItem itemWithTitle:@"入金 (deposit)"
                                selectorName:NSStringFromSelector(@selector(deposit))],
        [TBSDKDelegateDebugItem itemWithTitle:@"入金/资金划转 (onOpenDepositPage:)"
                                selectorName:NSStringFromSelector(@selector(onOpenDepositPage:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"改单 (modifyOrder:callback:)"
                                selectorName:NSStringFromSelector(@selector(modifyOrder:callback:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"撤单 (cancelOrder:callback:)"
                                selectorName:NSStringFromSelector(@selector(cancelOrder:callback:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"跳转期权详情页 (openCustomOptionDetailPageWithQuery:fromVC:)"
                                selectorName:NSStringFromSelector(@selector(openCustomOptionDetailPageWithQuery:fromVC:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"跳转组合期权详情页 (openCustomCombinationOptionDetailPageWithQuery:fromVC:)"
                                selectorName:NSStringFromSelector(@selector(openCustomCombinationOptionDetailPageWithQuery:fromVC:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"跳转个股详情页 (openCustomStockDetailPageWithQuery:fromVC:)"
                                selectorName:NSStringFromSelector(@selector(openCustomStockDetailPageWithQuery:fromVC:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"SYEP 操作 (syepAction:)"
                                selectorName:NSStringFromSelector(@selector(syepAction:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"行情权限订阅跳转 (gotoQuotePermissionSubscription:params:successed:failed:)"
                                selectorName:NSStringFromSelector(@selector(gotoQuotePermissionSubscription:params:successed:failed:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"金刚区跳转拦截 (homepageTransformersClickAction:block:)"
                                selectorName:NSStringFromSelector(@selector(homepageTransformersClickAction:block:))],
        //ITFS SDK 默认执行 didClickTradeButton:success:failure: 协议
        [TBSDKDelegateDebugItem itemWithTitle:@"点击交易按钮 (didClickTradeButton:success:failure:)"
                                selectorName:NSStringFromSelector(@selector(didClickTradeButton:success:failure:))
                              defaultForceNo:NO],
        [TBSDKDelegateDebugItem itemWithTitle:@"跳转开通交易权限 (updateTradePemissionAlertAction:permission:completion:)"
                                selectorName:NSStringFromSelector(@selector(updateTradePemissionAlertAction:permission:completion:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"首页自定义模块 (customHomePageModules)"
                                selectorName:NSStringFromSelector(@selector(customHomePageModules))],
        [TBSDKDelegateDebugItem itemWithTitle:@"个股页自定义 tab (customStockDetailTabsForMarket:symbol:secType:)"
                                selectorName:NSStringFromSelector(@selector(customStockDetailTabsForMarket:symbol:secType:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"金刚区自定义 icon 展示"
                                selectorName:NSStringFromSelector(@selector(customConfigForShortcutType:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"金刚区自定义入口 (customShortcutFunctionsWithCompletion:)"
                                selectorName:NSStringFromSelector(@selector(customShortcutFunctionsWithCompletion:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"IPO 申购资格预检 (checkIPOApplyEntryQualificationWithSymbol:market:completion:)"
                                selectorName:NSStringFromSelector(@selector(checkIPOApplyEntryQualificationWithSymbol:market:completion:))
                               defaultForceNo:NO],
        [TBSDKDelegateDebugItem itemWithTitle:@"IPO 身份证件上传 (uploadIPOUserProfileWithMarket:symbol:completion:)"
                                selectorName:NSStringFromSelector(@selector(uploadIPOUserProfileWithMarket:symbol:completion:))
                               defaultForceNo:NO],
        [TBSDKDelegateDebugItem itemWithTitle:@"使用宿主行情"
                                selectorName:NSStringFromSelector(@selector(useMainAppQuoteInfoAtComponent:))],
        [TBSDKDelegateDebugItem itemWithTitle:@"使用长连接推送"
                                selectorName:NSStringFromSelector(@selector(subscribeQuoteInfo:component:callback:))
                              defaultForceNo:NO],
    ];
}

- (TBSDKDelegateDebugItem *)itemForSelector:(SEL)selector {
    NSString *selectorName = NSStringFromSelector(selector);
    for (TBSDKDelegateDebugItem *item in self.allItems) {
        if ([item.selectorName isEqualToString:selectorName]) {
            return item;
        }
    }
    return nil;
}

- (void)showAllDelegateSettings {
    self.hostQuoteTypeChangeHandler = nil;
    self.items = self.allItems;
    self.title = @"客户自定义实现开关";
    if (self.isViewLoaded) {
        [self.tableView reloadData];
    }
}

- (void)showHostQuoteSettingsWithQuoteType:(TigerTradingSDKQuoteType)quoteType
                             changeHandler:(void (^)(TigerTradingSDKQuoteType quoteType))changeHandler {
    self.hostQuoteType = quoteType;
    self.hostQuoteTypeChangeHandler = changeHandler;
    self.items = @[
        [self itemForSelector:@selector(useMainAppQuoteInfoAtComponent:)],
        [TBSDKDelegateDebugItem quotePermissionItem],
        [self itemForSelector:@selector(subscribeQuoteInfo:component:callback:)],
    ];
    self.title = @"宿主自定义行情";
    if (self.isViewLoaded) {
        [self.tableView reloadData];
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    if (self.title.length == 0) {
        self.title = @"客户自定义实现开关";
    }
}

#pragma mark - TigerQuoteDebugDelegate

- (BOOL)tbSDK_shouldForceNoForSelector:(SEL)selector {
    return [self.forceNoSelectors containsObject:NSStringFromSelector(selector)];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.items.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kTBSDKDelegateDebugCellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1
                                      reuseIdentifier:kTBSDKDelegateDebugCellIdentifier];
    }

    TBSDKDelegateDebugItem *item = self.items[indexPath.row];
    cell.textLabel.text = item.title;
    cell.detailTextLabel.text = nil;
    cell.accessoryView = nil;
    cell.accessoryType = UITableViewCellAccessoryNone;

    if (item.type == TBSDKDelegateDebugItemTypeQuotePermission) {
        cell.detailTextLabel.text = [self titleForQuoteType:self.hostQuoteType];
        cell.selectionStyle = UITableViewCellSelectionStyleDefault;
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    } else {
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        UISwitch *sw = [[UISwitch alloc] init];
        // ON = 走原始检测流程，OFF = 强制未实现（返回 NO）
        sw.on = ![self.forceNoSelectors containsObject:item.selectorName];
        sw.tag = indexPath.row;
        [sw addTarget:self action:@selector(switchChanged:) forControlEvents:UIControlEventValueChanged];
        cell.accessoryView = sw;
    }

    return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    TBSDKDelegateDebugItem *item = self.items[indexPath.row];
    if (item.type == TBSDKDelegateDebugItemTypeQuotePermission) {
        [self showQuoteTypeSelector];
    }
}

#pragma mark - Action

- (void)switchChanged:(UISwitch *)sender {
    TBSDKDelegateDebugItem *item = self.items[sender.tag];
    if (sender.isOn) {
        [self.forceNoSelectors removeObject:item.selectorName];
    } else {
        [self.forceNoSelectors addObject:item.selectorName];
    }
    [self saveForceNoSelectors];
}

- (void)showQuoteTypeSelector {
    NSString *message = [NSString stringWithFormat:@"当前：%@", [self titleForQuoteType:self.hostQuoteType]];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择宿主行情权限"
                                                                             message:message
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    @TB_weakify(self);
    UIAlertAction *delayAction = [UIAlertAction actionWithTitle:@"Delay"
                                                         style:UIAlertActionStyleDefault
                                                       handler:^(UIAlertAction *action) {
        @TB_strongify(self);
        [self updateHostQuoteType:TigerTradingSDKQuoteTypeUSStockDelay];
    }];
    UIAlertAction *lv1Action = [UIAlertAction actionWithTitle:@"Lv1"
                                                       style:UIAlertActionStyleDefault
                                                     handler:^(UIAlertAction *action) {
        @TB_strongify(self);
        [self updateHostQuoteType:TigerTradingSDKQuoteTypeUSStockLv1];
    }];
    UIAlertAction *lv2Action = [UIAlertAction actionWithTitle:@"Lv2"
                                                       style:UIAlertActionStyleDefault
                                                     handler:^(UIAlertAction *action) {
        @TB_strongify(self);
        [self updateHostQuoteType:TigerTradingSDKQuoteTypeUSStockLv2];
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                          style:UIAlertActionStyleCancel
                                                        handler:nil];
    [alertController addAction:delayAction];
    [alertController addAction:lv1Action];
    [alertController addAction:lv2Action];
    [alertController addAction:cancelAction];
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)updateHostQuoteType:(TigerTradingSDKQuoteType)quoteType {
    self.hostQuoteType = quoteType;
    if (self.hostQuoteTypeChangeHandler) {
        self.hostQuoteTypeChangeHandler(quoteType);
    }
    [self.tableView reloadData];
}

- (NSString *)titleForQuoteType:(TigerTradingSDKQuoteType)quoteType {
    switch (quoteType) {
        case TigerTradingSDKQuoteTypeUSStockDelay:
            return @"Delay";
        case TigerTradingSDKQuoteTypeUSStockLv1:
            return @"Lv1";
        case TigerTradingSDKQuoteTypeUSStockLv2:
            return @"Lv2";
    }
    return @"Lv2";
}

@end

#endif
