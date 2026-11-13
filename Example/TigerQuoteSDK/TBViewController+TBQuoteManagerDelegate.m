//
//  TBViewController+TBQuoteManagerDelegate.m
//  TigerQuoteSDK
//

#import "TBViewController+TBQuoteManagerDelegate.h"
#if !TB_PUBLIC_EXAMPLE
#import "TBViewController+TBInternalTestActions.h"
#endif
#import "TBViewController+TBInternal.h"
#import "TBDemoCustomHomeModule.h"
#import "TBDemoNewsListViewController.h"
#import "TBDemoQuoteProvider.h"

#import <TBBaseKit/TBAPPFunctionConfigManager.h>
#import <TBBaseKit/TBServiceManager+TBPerformanceService.h>
#import <TBToolsKit/TBSupportUtility.h>
#import <TBUIKit/MBProgressHUD+Wrapper.h>

#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    #import <TigerTradingSDK/TigerQuoteDebugMananger.h>
#endif

@import TBBaseKit;

static NSString * const kTBDemoAppQuoteTypeKey = @"TBDemo_appQuoteType";

@implementation TBViewController (TBQuoteManagerDelegate)

#pragma mark - TigerTradingQuoteDelegate

- (void)quotePermissionChange {
    TBLogCode(@"行情权限变更");
}

#pragma mark - 首页自定义模块 Demo

- (NSArray<TigerTradingSDKHomeModuleItem *> *)customHomePageModules {
    if (!self.customHomeModule) {
        self.customHomeModule = [[TBDemoCustomHomeModule alloc] init];
    }
    return @[[self.customHomeModule currentItem]];
}

#pragma mark - 个股详情页自定义 tab Demo

- (NSArray<TigerTradingSDKStockDetailTabItem *> *)customStockDetailTabsForMarket:(NSString *)market
                                                                          symbol:(NSString *)symbol
                                                                         secType:(NSString *)secType {
    // 演示:为美股/港股 STK 注入两个自定义 tab,锚点分别是图表之后、期权之后
    if (!([market isEqualToString:@"US"] || [market isEqualToString:@"HK"]) || ![secType isEqualToString:@"STK"]) {
        return nil;
    }

    UIViewController *researchVC = [[UIViewController alloc] init];
    researchVC.view.backgroundColor = [UIColor systemTealColor];
    UILabel *researchLabel = [[UILabel alloc] init];
    researchLabel.text = [NSString stringWithFormat:@"研究 %@(host)", symbol];
    researchLabel.textColor = [UIColor whiteColor];
    [researchLabel sizeToFit];
    researchLabel.center = CGPointMake(180, 200);
    [researchVC.view addSubview:researchLabel];

    // 资讯 tab:内嵌 UITableView + 上拉加载。用 provider block 让 SDK 每次都拿到最新的
    // tableView 和 contentSize,避免 loadMore 后总高度过时。
    TBDemoNewsListViewController *newsVC = [[TBDemoNewsListViewController alloc] init];

    TigerTradingSDKStockDetailTabItem *item1 = [[TigerTradingSDKStockDetailTabItem alloc] init];
    item1.identifier = @"CUSTOM_RESEARCH";
    item1.title = @"研究";
    item1.viewController = researchVC;
    // listScrollView / contentHeight 是可选字段;此处 host vc 内没有 UITableView,留空即可。
    // 真实接入时把 host vc 自己的 self.tableView 赋给 item.listScrollView,
    // contentHeight 填总内容高度,SDK 即可联动嵌套滚动。
//    item1.insertAfterIdentifier = kTigerTradingSDKStockDetailTabIdentifierChart;

    TigerTradingSDKStockDetailTabItem *item2 = [[TigerTradingSDKStockDetailTabItem alloc] init];
    item2.identifier = @"CUSTOM_NEWS";
    item2.title = @"资讯";
    item2.viewController = newsVC;
    __weak TBDemoNewsListViewController *weakNews = newsVC;
    item2.listScrollViewProvider = ^UIScrollView * _Nullable{
        return weakNews.newsTable;
    };
    item2.contentHeightProvider = ^CGFloat{
        return weakNews.newsTable.contentSize.height;
    };
//    item2.insertAfterIdentifier = kTigerTradingSDKStockDetailTabIdentifierOption;

    return @[item1, item2];
}

#pragma mark - 金刚区自定义入口 Demo

/// Demo 用:画一个 22x22 的「资讯」图标(内置项图标也是 22x22)。
/// 不用 SF Symbol 是因为 systemImageNamed: / imageWithTintColor: 都要 iOS 13,
/// 而本 target 的 deployment target 是 12。
static UIImage *TBDemoShortcutIcon(UIColor *backgroundColor) {
    CGSize size = CGSizeMake(22, 22);
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:size];
    return [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        [backgroundColor setFill];
        [[UIBezierPath bezierPathWithRoundedRect:CGRectMake(0, 0, size.width, size.height)
                                   cornerRadius:5] fill];
        [[UIColor whiteColor] setFill];
        for (NSInteger i = 0; i < 3; i++) {
            [[UIBezierPath bezierPathWithRect:CGRectMake(5, 6 + i * 5, 12, 2)] fill];
        }
    }];
}

/// 内置项外观 Demo：设置页可单独开关，其他快捷功能继续使用默认配置。
- (nullable TigerTradingShortcutFunctionModel *)customConfigForShortcutType:(TigerTradingSDKTransformersType)type {
    if (type != TigerTradingSDKTransformersTypeOrder) {
        return nil;
    }
    TigerTradingShortcutFunctionModel *config = [[TigerTradingShortcutFunctionModel alloc] init];
    // 宿主自行本地化自定义标题；图标按深浅色配置分别提供。
    config.functionName = @"自定义名称";
    config.functionImage = TBDemoShortcutIcon([UIColor blueColor]);
    config.functionImageDark = TBDemoShortcutIcon([UIColor orangeColor]);
    return config;
}

- (void)customShortcutFunctionsWithCompletion:(void (^)(NSArray<TigerTradingShortcutFunctionModel *> * _Nullable))completion {
    if (!completion) {
        return;
    }
    // 这里刻意延迟 1s 再回调,用来演示异步链路:内置项先渲染出来,自定义项后到并把
    // 模块高度撑开。真实接入时如果数据本来就在本地,直接同步调用 completion 即可,
    // 金刚区第一帧就是完整的。
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        TigerTradingShortcutFunctionModel *news = [[TigerTradingShortcutFunctionModel alloc] init];
        news.functionName = @"新闻资讯";
        // 深浅色各给一张:SDK 切主题时不会重新问宿主要数据,直接在这两张之间切。
        // 这里刻意用差别明显的底色,切皮肤时肉眼就能确认换图生效了。
        news.functionImage = TBDemoShortcutIcon([UIColor colorWithRed:0.85 green:0.28 blue:0.24 alpha:1.0]);
        news.functionImageDark = TBDemoShortcutIcon([UIColor colorWithRed:1.0 green:0.72 blue:0.30 alpha:1.0]);
        news.functionBlock = ^(UIViewController *fromVC) {
            TBDemoNewsListViewController *newsVC = [[TBDemoNewsListViewController alloc] init];
            newsVC.title = @"新闻资讯";
            // fromVC 是 SDK 首页 VC,导航栈归 SDK 管,所以用 SDK 提供的跳转 API 而不是自己 push
            // (它会在栈可用时 push、否则用 TBNavigationController 包一层 present)。
            // 注意不要长期持有 fromVC。
            //
            // ⚠️ SDK 环境下系统导航栏是关闭的,宿主页面要自己画标题栏 + 返回按钮,
            // 返回调 -tbDismissViewControllerAnimated:(自动 pop 或 dismiss)。
            // 实现见 TBDemoNewsListViewController.m 的 setupTopBar / backAction。
            [TigerTradingQuoteManager pushOrPresentCustomViewController:newsVC fromViewController:fromVC];
        };
        completion(@[news]);
    });
}

- (BOOL)useMainAppQuoteInfoAtComponent:(TigerTradingSDKQuoteComponentType)componentType {
    // 是否真的走客户行情，由设置页「客户自定义实现开关」按代理方法统一控制
    return YES;
}

- (void)getQuoteInfo:(NSArray<TigerTradingContractInfoModel *> *)contracts callback:(void(^)(NSArray<TigerTradingContractQuoteModel *> *quotes))callback {
    if (callback) {
        callback([self.quoteProvider quotesForContracts:contracts]);
    }
}

- (void)subscribeQuoteInfo:(NSArray<TigerTradingContractInfoModel *> *)contracts
                 component:(TigerTradingSDKQuoteComponentType)component
                  callback:(void(^)(NSArray<TigerTradingContractQuoteModel *> *quotes))callback {
    [self.quoteProvider subscribeContracts:contracts component:component callback:callback];
}

- (void)unSubscribeQuoteInfo:(NSArray<TigerTradingContractInfoModel *> *)contracts
                   component:(TigerTradingSDKQuoteComponentType)component {
    [self.quoteProvider unsubscribeContracts:contracts component:component];
}

- (TigerTradingSDKQuoteType)checkAppQuoteType:(NSString *)market secType:(NSString *)secType {
    return self.appQuoteType;
}

#pragma mark - 模拟 APP 行情权限

- (TigerTradingSDKQuoteType)appQuoteType {
    NSNumber *cached = [[NSUserDefaults standardUserDefaults] objectForKey:kTBDemoAppQuoteTypeKey];
    if (cached == nil) {
        // 没选过时按最高权限，下单页买卖盘和深度都展示
        return TigerTradingSDKQuoteTypeUSStockLv2;
    }
    return (TigerTradingSDKQuoteType)cached.unsignedIntegerValue;
}

- (void)setAppQuoteType:(TigerTradingSDKQuoteType)appQuoteType {
    NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
    [ud setObject:@(appQuoteType) forKey:kTBDemoAppQuoteTypeKey];
    [ud synchronize];
}

//- (void)optionDetailInvestorQualificationActionWithFromVC:(UIViewController *)fromVC {
//    [MBProgressHUD showHint:@"客户自定义期权详情页专业投资者认证事件" hide:1.5];
//}

- (void)quotePermissionCustomerInfoBlock:(void (^)(TigerTradingProfessionalQuestionInfoModel * _Nonnull model))userInfoBlock {
    TigerTradingProfessionalQuestionInfoModel *model = [[TigerTradingProfessionalQuestionInfoModel alloc] init];

    if (TBIsTradeUP) {
        model.first_name = @"John";
        model.middle_initial = @"D";  // 中间名首字母
        model.birthday = @"1985-07-20";  // 生日格式通常是 MM/DD/YYYY
        model.id_no = @"123-45-6789";  // 示例社保号 (SSN)
    }
    else {
        model.realName = @"John Doe";
        model.legalResidenceCountry = @"USA";
        model.homeState = @"California";
        model.homeCity = @"Los Angeles";
        model.homeDistrict = @"Westside";
        model.homeAddress = @"123 Main St";
        model.employment = @"Employed";
        model.industry = @"Technology";
        model.position = @"Engineer";
        model.department = @"Engineering";
        model.companyName = @"Tech Corp";
        model.companyAddress = @"456 Tech Ave";
        model.selfEmployment = @"No";
        model.homeAddressFull = @"1234 Sunset Blvd, Los Angeles, CA 90026, US";
        model.answers = @{@"questionUseForPersonal": @(1),
                          @"questionUseForBusiness": @(0),
                          @"questionSECCFTCRegistered": @(1),
                          @"questionSecuritiesAgencyRegistered": @(0),
                          @"questionSimilarRegulatoryFunction": @(1),
                          @"questionProvideInvestmentAdvice": @(0),
                          @"questionAssetManager": @(1),
                          @"questionUseThirdPartyCapital": @(0),
                          @"questionTradeForEntity": @(1),
                          @"questionProfitSharing": @(0),
                          @"questionReceiveBenefitsForTrading": @(1),
                          @"questionRedistributeMarketData": @(0)};
    }

    if (userInfoBlock) {
        userInfoBlock(model);
    }
}

- (void)onQuoteSurveyDone:(NSDictionary *)response {
    NSString *info = [NSString stringWithFormat:@"用户认证状态更新，信息：%@", response];
    [MBProgressHUD showHint:info hide:5];
}

- (void)gotoQuotePermissionSubscription:(UIViewController *)fromViewController
                                 params:(NSDictionary *)params
                              successed:(void(^)(id))successed
                                 failed:(void(^)(NSError *))failed {

#if !TB_PUBLIC_EXAMPLE
    if ([self handleInternalQuotePermissionSubscriptionWithSuccess:successed]) {
        return;
    }
#endif

    [MBProgressHUD showLoading:YES hintString:@"客户进行权限变更逻辑（3s）"];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [MBProgressHUD showLoading:NO];

        if (successed) {
            successed(@"ss");
        }
    });
}

- (void)optionDetailCheckOptionChainWithMarket:(NSString *)market
                                        symbol:(NSString *)symbol
                                        fromVC:(UIViewController *)fromVC {
    [MBProgressHUD showHint:@"客户自定义期权链跳转" hide:1.5];
}

/// 首页金刚区点击事件
/// - Parameters:
///   - action: 对应的金刚区点击事件的key
///   - block: executeOriginMethod  YES 继续执行原来的跳转逻辑  NO 不继续执行原来逻辑
- (void)homepageTransformersClickAction:(TigerTradingSDKTransformersType)action
                                  block:(void(^)(BOOL executeOriginMethod))block
{
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    if ([TigerQuoteDebugMananger.debugDelegate respondsToSelector:@selector(tbSDK_shouldForceNoForSelector:)]
        && [TigerQuoteDebugMananger.debugDelegate tbSDK_shouldForceNoForSelector:@selector(homepageTransformersClickAction:block:)]) {
        if (block) {
            block(YES);
        }
        return;
    }
#endif
    NSString *strNotice = @"不属于提供客户进行拦截的跳转，直接执行原始逻辑";
    switch (action) {
        case TigerTradingSDKTransformersTypeUNKNOW:
            break;
        case TigerTradingSDKTransformersTypeExchange:
            strNotice = @"货币兑换跳转，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeOddlots:
            strNotice = @"碎股卖出跳转，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeAction:
            strNotice = @"公司行动跳转，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeOrder:
            strNotice = @"订单跳转，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeOptionList:
            strNotice = @"期权榜单跳转，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeTransferFunds:
            strNotice = @"资金划转跳转，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeOptionExercise:
            strNotice = @"期权行权，是否中断跳转操作？";
            break;
//        case TigerTradingSDKTransformersTypeChangeTradePwd:
//            strNotice = @"交易密码跳转，是否中断跳转操作？";
//            break;
//        case TigerTradingSDKTransformersTypeFeeStructure:
//            strNotice = @"费率结构跳转，是否中断跳转操作？";
//            break;
//        case TigerTradingSDKTransformersTypeSYEP:
//            strNotice = @"股票借贷跳转，是否中断跳转操作？";
//            break;
        case TigerTradingSDKTransformersTypeCashManager:
            strNotice = @"现金管理，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeGlobalETF:
            strNotice = @"全球 ETF，是否中断跳转操作？";
            break;
        case TigerTradingSDKTransformersTypeMoverShakers:
            strNotice = @"明星异动，是否中断跳转操作？";
            break;
        default:
            break;
    }

    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"金刚区点击跳转拦截"
                                                                             message:strNotice
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"执行原逻辑"
                                                            style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * _Nonnull action) {
        if (block) {
            block(YES);
        }
    }];

    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"中断跳转自定义逻辑"
                                                           style:UIAlertActionStyleCancel
                                                         handler:^(UIAlertAction * _Nonnull action) {
        if (block) {
            block(NO);
            [MBProgressHUD showHint:@"客户执行自定义逻辑，不进行原始的跳转" hide:3];
        }
    }];

    [alertController addAction:confirmAction];
    [alertController addAction:cancelAction];
    [[TBSupportUtility getTopVC] presentViewController:alertController animated:YES completion:nil];
}

- (NSString *)configHomePageAccountName {
    // 不同语言自行处理映射
    return self.homepageName;
}

- (NSString *)configAppBrandName {
    return self.strBrandName;
}

- (BOOL)configCustomSwitchAccountAction {
    [MBProgressHUD showHint:@"业务执行自己的业务逻辑" hide:3];
    return self.isContinueSwitchAccount;
}

- (BOOL)showWatchlistButton {
    return YES;
}

#pragma mark - CustomCombina delegate

// 组合期权标的详情页跳转delegate
- (void)openCustomCombinationOptionDetailPageWithQuery:(NSDictionary *)query
                                                fromVC:(UIViewController *)fromVC {
    BOOL useQuoteTradeCombinedStyle = [TBAPPFunctionConfigManager sharedInstance].useQuoteTradeCombinedStyle;
    if (useQuoteTradeCombinedStyle) {
//        TB23SDKStockDetailViewController *vc = [[TB23SDKStockDetailViewController alloc] initWithNavigatorURL:nil query:query];
//        [TigerTradingQuoteManager pushOrPresentCustomViewController:vc fromViewController:fromVC];
    }
    else {
        NSArray *optionLegsInfoArr = query[@"optionItems"];
        [TigerTradingQuoteManager openCombinationOptionDetailPageWithLegs:optionLegsInfoArr fromViewController:fromVC];
    }
}

- (void)openCustomOptionDetailPageWithQuery:(NSDictionary *)query
                                     fromVC:(UIViewController *)fromVC {
    BOOL useQuoteTradeCombinedStyle = [TBAPPFunctionConfigManager sharedInstance].useQuoteTradeCombinedStyle;
    if (useQuoteTradeCombinedStyle) {
//        UIViewController *vc = [[TB23SDKStockDetailViewController alloc] initWithNavigatorURL:nil query:query];
//        [TigerTradingQuoteManager pushOrPresentCustomViewController:vc fromViewController:fromVC];
    }
    else {
        [TigerTradingQuoteManager openOptionDetailPageWithSymbol:query[@"symbol"]
                                                           right:query[@"right"]
                                                          strike:query[@"strike"]
                                                          expiry:query[@"expiry"]
                                                          market:query[@"market"]
                                              fromViewController:fromVC];
    }
}

- (void)openCustomStockDetailPageWithQuery:(NSDictionary *)query
                                    fromVC:(nullable UIViewController *)fromVC {
    BOOL useQuoteTradeCombinedStyle = [TBAPPFunctionConfigManager sharedInstance].useQuoteTradeCombinedStyle;
    if (useQuoteTradeCombinedStyle) {
//        UIViewController *vc = [[TB23SDKStockDetailViewController alloc] initWithNavigatorURL:nil query:query];
//        [TigerTradingQuoteManager pushOrPresentCustomViewController:vc fromViewController:fromVC];
    }
    else {
        [TigerTradingQuoteManager openStockDetailPageWithQuery:query fromViewController:fromVC];
    }
}

- (BOOL)openCustomPlaceOrderPageWithQuery:(NSDictionary *)query
                                   fromVC:(nullable UIViewController *)fromVC {
    if ([TBAPPFunctionConfigManager sharedInstance].useQuoteTradeCombinedStyle) {
        // 使用行情&交易嵌套样式跳转下单页要改成跳嵌套个股页并切换到交易tab
//        TB23SDKStockDetailViewController *vc = [[TB23SDKStockDetailViewController alloc] initWithNavigatorURL:nil query:query];
//        vc.shouldJumpToTradeTab = YES;
//        [TigerTradingQuoteManager pushOrPresentCustomViewController:vc fromViewController:fromVC];
        return YES;
    }
    return NO;
}

@end
