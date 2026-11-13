//
//  TBViewController.m
//  TigerQuoteSDK
//
//  Created by linbingjie on 08/08/2024.
//  Copyright (c) 2024 linbingjie. All rights reserved.
//

#import "TBViewController.h"
#import "TBViewController+TBInternal.h"
#import "TBViewController+TBQuoteManagerDelegate.h"
#import "TBViewController+TBTradeManagerDelegate.h"
#import "TBCellModel.h"
#import "TBDemoQuoteProvider.h"

#import <TigerTradingSDK/TigerTradingSDKSettingManager.h>
#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import <TigerTradingSDK/TigerTradingSDKModel.h>
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <TigerTradingSDK/TigerTradingShareManager.h>

@import TigerTradingSDK;
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    #import <TigerTradingSDK/TigerQuoteDebugMananger.h>
#endif


#import <TBBaseKit/TBStringUtility.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>

#import "TB23SDKStockDetailViewController.h"

#import <TBBaseKit/TBServiceManager.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBBaseKit/UIDevice+OrientationDevice.h>
#import <TBAccountSystemKit/TBAccountUtils+TBTrade.h>
#import <TBAccountSystemKit/TBStockPermissionConstant.h>
#if !TB_PUBLIC_EXAMPLE
#import "TBViewController+TBMockLogin.h"
#endif

#import <TBUIKit/MBProgressHUD+Wrapper.h>
#import <TBToolsKit/TBSupportUtility.h>
#import <TBAccountSystemKit/TBAuthUtils.h>
#import <TBBusinessSupportKit/TBShortcutsModel.h>

#import "TBFunctionController.h"
#import "TBModuleViewController.h"
#import "TBOptionDetailViewController.h"
#import "TBPositionTabViewController.h"
#import "TBOrderModuleVC.h"
#import "TBSDKShareViewController.h"
#import "TBSDKAccountPortfolioRatioShareCardView.h"
#import "TBSDKAccountProfitShareCardView.h"
#import "TBSDKOrderShareCardView.h"

#import "TBSDKPositionShareCardView.h"
#import <TBTradeBusinessBaseKit/TBTradeAPIPositionModel.h>
#import <TBTradeBusinessBaseKit/TBTradeAPIOrderModel.h>
#import <TBTradeBusinessBaseKit/TBTradeAssetTodayPnLShareInfoModel.h>

@import TBToolsKit;
@import TBUIKit;
@import TBBaseKit;
@import ChartKLineView;
@import TBBusinessSupportKit;
#import <TBWebView/TBWKWebViewController.h>
#import <TBWebView/TBWKWebViewController+TBDebugTool.h>
#import "TBOptionChainPageViewController.h"
#import "TBOptionPageViewController.h"
#import <TBPerformanceKit/TBQuickClickManager.h>
#import <UserNotifications/UserNotifications.h>
#import "TBViewController+TBDataSource.h"

@import TBToolsKit;
@import TBUIKit;
@import TBBaseKit;
@import TBBusinessSupportKit;


NSString * const kTigerTradeLaunchConfig = @"kTigerTradeLaunchConfig";

@interface TBViewController ()
<
 UITableViewDelegate,
 UITableViewDataSource,
 TigerTradingSDKDelegate,
 TigerTradingSDKSettingDelegate,
 TigerTradingShareDelegate
>

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, assign) BOOL isAbleToShowTokenExpired; // 是否能显示token过期

@property (nonatomic, strong) NSMutableSet<NSString *> *watchlistSet;

@end

@implementation TBViewController

- (TBDemoQuoteProvider *)quoteProvider {
    if (!_quoteProvider) {
        @TB_weakify(self);
        _quoteProvider = [[TBDemoQuoteProvider alloc] initWithQuoteTypeProvider:^TigerTradingSDKQuoteType{
            @TB_strongify(self);
            return self ? self.appQuoteType : TigerTradingSDKQuoteTypeUSStockLv2;
        }];
    }
    return _quoteProvider;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    self.watchlistSet = [[NSMutableSet alloc] init];
    
    NSString *appname = [NSString stringWithFormat:@"当前使用:%@",APPNAME];
    [MBProgressHUD showHint:appname hide:1];

    
    
    if (self.navigationController) {
        self.navigationController.navigationItem.title = @"demo 页面";
    }
        
    self.isContinueSwitchAccount = YES;
    self.needDisplayOptionLapse = YES;
    self.needDisplayEarlyExercise = YES;
    self.isTradeLongTermEffective = YES; //使用默认 token
    
    // 初始化数据源
    [self setupDataSource];
    
    // 初始化TableView
    [self setupTableView];
    
    TigerTradingSDKManager.delegate = self;
    TigerTradingSDKSettingManager.delegate = self;
    TigerTradingQuoteManager.delegate = self;
    TigerTradingTradeManager.delegate = self;
//    TigerTradingShareManager.delegate = self;
    
    self.isAbleToShowTokenExpired = YES;
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(tradePriceermissionChange:)
                                                 name:[TigerTradingTradeManager fetchTradePermissionChangeNotificationKey]
                                               object:nil];
}


- (void)tradePriceermissionChange:(NSNotification *)notification {
    NSLog(@"%@", notification);
    NSLog(@"%@", notification);
}

- (void)tokenExpiredExpectedLogoutSDK {
    if (TBIsTradeUP) {
        [TigerTradingSDKManager removeAllViewController:YES];
        [MBProgressHUD showHint:@"USA:token过期 && 退出SDK页面" hide:1];
    }
    else {
        [MBProgressHUD showHint:@"HK:token过期" hide:1];
    }
}

#pragma mark - TigerTradingSDKDelegate
/// 合约添加/删除自选
/// - Parameters:
///   - symbol: 合约symbol
///   - market: 合约所属市场
///   - secType: 合约类型：e.g STK(正股),OPT(期权)
///   - completion: 添加结果回调
- (void)requestAddOrRemoveWatchlists:(NSArray<TigerTradingWatchListItemChangeModel *> *)array completion:(void (^)(BOOL, NSNumber * _Nonnull, NSString * _Nonnull))completion {
    NSMutableString *str = [NSMutableString string];
    [str appendFormat:@"业务可自定义自选增删后的逻辑\n"];
    [str appendString:@"\n------------------------\n"];
    [array enumerateObjectsUsingBlock:^(TigerTradingWatchListItemChangeModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        // 拼接每个属性到字符串中
        [str appendFormat:@"添加自选: %@\n", obj.isADD_Notification ? @"YES" : @"NO"];
        [str appendFormat:@"symbol: %@\n", obj.symbol];
        [str appendFormat:@"secType: %@\n", obj.secType];
        [str appendFormat:@"market: %@\n", obj.market];
        [str appendFormat:@"nameCN: %@\n", obj.nameCN];
        
        // 如果需要分隔符，可以在这里添加
        [str appendString:@"\n------------------------\n"];
        
        
        // 更新容器
        if (obj.isADD_Notification) {
            [self.watchlistSet addObject:obj.symbol];
        } else {
            [self.watchlistSet removeObject:obj.symbol];
        }

    }];
    
    NSLog(@"⭐️ ⭐️ 合约 添加/删除自选");
    NSLog(@"⭐️ %@", str);

    if (completion) {
        completion(YES,@(0),@"sss");
    }
}


/// 合约是否在自选列表
/// - Parameters:
///   - symbol: 合约symbol
///   - market: 合约所属市场
///   - secType: 合约类型：e.g STK(正股),OPT(期权)
- (BOOL)requestContractIsInWatchlist:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType {
    NSLog(@"⭐️ ❎ 合约 在自选列表");
    NSLog(@"⭐️ symbol:%@,market:%@,secType:%@",symbol,market,secType);
//    BOOL type = NO;
    
    @synchronized (self.watchlistSet) {
        BOOL isInWatchlist = [self.watchlistSet containsObject:symbol];
        NSLog(@"⭐️ 合约 %@ %@ %@ %@",
              isInWatchlist ? @"在自选列表" : @"不在自选列表",
              symbol, market, secType);
        return isInWatchlist;
    }

}


/// 这个api没用
/// 查询合约是否在持仓
/// - Parameters:
///   - symbol: 合约symbol
///   - market: 合约市场
///   - secType: 合约类型：e.g STK(正股),OPT(期权)
- (BOOL)requestContractIsInPosition:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType {
    NSLog(@"⭐️ 查询合约是否在持仓requestContractIsInPosition");
    NSLog(@"⭐️ symbol:%@,market:%@,secType:%@",symbol,market,secType);
    
    BOOL type = NO;
    return type;
}

- (BOOL)enableConfigNetworkInspector {
    if (TBIsEWBSDK) {
        return NO;
    }
    return YES;
}


- (void)requestAppLoginWithCompletion:(nonnull void (^)(BOOL, NSError *))completion {
    [MBProgressHUD showHint:@"调起客户登录页面" hide:1.5];
}

//- (void)sdkViewDidAppear:(UIViewController *)controller {
//    NSString *hint = [NSString stringWithFormat:@"打开页面: %@", NSStringFromClass([controller class])];
//    [MBProgressHUD showHint:hint hide:1.5];
//}

//- (void)sdkViewDidDisappear:(UIViewController *)controller {
//    NSString *hint = [NSString stringWithFormat:@"退出页面: %@", NSStringFromClass([controller class])];
//    [MBProgressHUD showHint:hint hide:1.5];
//}

- (void)deviceKickedOut {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"设备被登出"
                                                                             message:nil
                                                                      preferredStyle:UIAlertControllerStyleAlert];

    UIAlertAction *action = [UIAlertAction actionWithTitle:@"确定"
                                                              style:UIAlertActionStyleDefault
                                                            handler:^(UIAlertAction * _Nonnull action) {
        [TigerTradingSDKManager sdkLogout];
        [self backToHome];
    }];
    
    [alertController addAction:action];
    [[TBSupportUtility getTopVC] presentViewController:alertController animated:YES completion:nil];
}

- (void)backToHome {
    // 根窗口
    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    UINavigationController *rootNav = (UINavigationController *)window.rootViewController;

    // 确保根控制器就是 UINavigationController
    if (![rootNav isKindOfClass:[UINavigationController class]]) {
        return;
    }

    // 先 dismiss 所有模态页面，再 pop 回首页
    [rootNav dismissViewControllerAnimated:NO completion:^{
        // pop 回导航栈第一个控制器（TBViewController）
        [rootNav popToRootViewControllerAnimated:YES];
    }];
}

#pragma mark - TigerTradingSDKSettingDelegate
- (BOOL)isFunctionEnable:(TTSDKFunctionType)function {
    if (function == TTSDKFunctionTypeMultiLegsOptions) {
        return YES;
    } else if (function == TTSDKFunctionTypeUSFractionShares) {
        return YES;
    }
    else if (function == TTSDKFunctionTypeHKWarrants) {
        return YES;
    }
    
    return YES;
}

//- (void)optionDetailInvestorQualificationActionWithFromVC:(UIViewController *)fromVC {
//    [MBProgressHUD showHint:@"客户自定义期权详情页专业投资者认证事件" hide:1.5];
//}

//- (NSString *)homePageCustomTitle {
//    return @"自定义首页标题";
//}


//- (void)watchListChanged:(NSArray <TigerTradingWatchListItemChangeModel *>*)array {
//    
//    NSMutableString *str = [NSMutableString string];
//    [str appendFormat:@"业务可自定义自选增删后的逻辑\n"];
//    [str appendString:@"\n------------------------\n"];
//    [array enumerateObjectsUsingBlock:^(TigerTradingWatchListItemChangeModel * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//        // 拼接每个属性到字符串中
//        [str appendFormat:@"添加自选: %@\n", obj.isADD_Notification ? @"YES" : @"NO"];
//        [str appendFormat:@"symbol: %@\n", obj.symbol];
//        [str appendFormat:@"secType: %@\n", obj.secType];
//        [str appendFormat:@"market: %@\n", obj.market];
//        [str appendFormat:@"nameCN: %@\n", obj.nameCN];
//        
//        // 如果需要分隔符，可以在这里添加
//        [str appendString:@"\n------------------------\n"];
//    }];
//    
//    NSLog(@"⭐️ ☀️ 自选增删");
//    NSLog(@"⭐️ %@", str);
////    [MBProgressHUD showHint:str hide:5];
//}

//- (void)syepAction:(TigerTradingSDKSYEPActionType)actionType {
//    if (actionType == 0) {
//        // 简介
//        [MBProgressHUD showHint:@"SYEP简介" hide:1];
//    }
//    else if (actionType == 1) {
//        // 加入
//        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"客户执行退出syep"
//                                                                                 message:nil
//                                                                          preferredStyle:UIAlertControllerStyleAlert];
//        [alertController addAction:[UIAlertAction actionWithTitle:@"加入SYEP[更新接口]"
//                                                                style:UIAlertActionStyleDefault
//                                                              handler:^(UIAlertAction * _Nonnull action) {
//            [TigerTradingQuoteManager refreshSyepPage];
//        }]];
//        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"取消"
//                                                                style:UIAlertActionStyleDefault
//                                                              handler:^(UIAlertAction * _Nonnull action) {
//        }];
//        [alertController addAction:confirmAction];
//        [[TBSupportUtility getTopVC] presentViewController:alertController animated:YES completion:nil];
//
//    }
//    else if (actionType == 2) {
//        // 退出
//        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"客户执行退出syep"
//                                                                                 message:nil
//                                                                          preferredStyle:UIAlertControllerStyleAlert];
//        [alertController addAction:[UIAlertAction actionWithTitle:@"退出SYEP[更新接口]"
//                                                                style:UIAlertActionStyleDefault
//                                                              handler:^(UIAlertAction * _Nonnull action) {
//            [TigerTradingQuoteManager refreshSyepPage];
//        }]];
//        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"取消"
//                                                                style:UIAlertActionStyleDefault
//                                                              handler:^(UIAlertAction * _Nonnull action) {
//        }];
//        [alertController addAction:confirmAction];
//        [[TBSupportUtility getTopVC] presentViewController:alertController animated:YES completion:nil];
//
//    }
//        
//}

#pragma mark - TigerTradingShareDelegate

- (void)shareWithInfo:(TBShareInfoModel *)infoModel
            platforms:(NSArray *)platforms
     inViewController:(UIViewController *)viewController
             delegate:(id<TBShareToolbarDelegate>)delegate
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate
{
    [TBSDKShareViewController shareWithInfo:infoModel
                        additionalPlatforms:platforms
                           inViewController:viewController
                        linkToolbarDelegate:delegate
                       imageToolbarDelegate:imageToolbarDelegate];
}

- (void)shareWithInfo:(TBShareInfoModel *)infoModel
  additionalPlatforms:(NSArray *)platforms
     inViewController:(UIViewController *)viewController
  linkToolbarDelegate:(id<TBShareToolbarDelegate>)linkToolbarDelegate
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate
    shareTypeDelegate:(id<TBShareTypeDelegate>)shareTypeDelegate
{
    [TBSDKShareViewController shareWithInfo:infoModel
                        additionalPlatforms:platforms
                           inViewController:viewController
                        linkToolbarDelegate:linkToolbarDelegate
                       imageToolbarDelegate:imageToolbarDelegate
                          shareTypeDelegate:shareTypeDelegate];
}

- (TBCardShareView *)accountPortfolioRatioShareCardViewWithData:(id)data shareType:(NSUInteger)shareType {
    TBSDKAccountPortfolioRatioShareCardView *portfolioRatioView = [[TBSDKAccountPortfolioRatioShareCardView alloc] init];
    portfolioRatioView.shareType = shareType;
    if ([data isKindOfClass:[TBTradeAssetTodayPnLShareInfoModel class]]) {
        portfolioRatioView.todayPnLInfoModel = data;
    }
    portfolioRatioView.isEditingDisabled = YES;
    return portfolioRatioView;
}

- (TBCardShareView *)accountProfitShareCardViewWithData:(id)data shareType:(NSUInteger)shareType {
    TBSDKAccountProfitShareCardView *profitView = [[TBSDKAccountProfitShareCardView alloc] init];
    profitView.shareType = shareType;
    if ([data isKindOfClass:[TBTradeAssetTodayPnLShareInfoModel class]]) {
        profitView.todayPnLInfoModel = data;
    }
    return profitView;
}

- (TBCardShareView *)orderShareCardViewWithData:(id)data shareType:(NSUInteger)shareType {
    TBSDKOrderShareCardView *cardView = [[TBSDKOrderShareCardView alloc] init];
    cardView.shareType = shareType;
    if ([data isKindOfClass:[TBTradeAPIPositionItemModel class]]) {
        cardView.tradePositionItem = data;
    }
    else if ([data isKindOfClass:[TBTradeAPIOrderItemModel class]]) {
        cardView.orderModel = data;
    }
    return cardView;
}

- (TBCardShareView *)positionShareCardViewWithData:(id)data
                                         shareType:(NSUInteger)shareType
                                    usePositionPnl:(BOOL)usePositionPnl {
    TBSDKPositionShareCardView *cardView = [[TBSDKPositionShareCardView alloc] init];
    cardView.shareType = shareType;
    cardView.usePositionPnl = usePositionPnl;
    if ([data isKindOfClass:[TBTradeAPIPositionItemModel class]]) {
        cardView.tradePositionItem = data;
    }
    return cardView;
}

#pragma mark - Life Cycle

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [UIDevice switchNewOrientation:UIInterfaceOrientationPortrait];
//    if (self.navigationController) {
//        [self.navigationController setNavigationBarHidden:NO animated:animated];
//    }
    
    
#if !TB_PUBLIC_EXAMPLE
    [self checkMockLoginEnvironment];
#endif
}

//
//- (void)viewWillLayoutSubviews {
//    [super viewWillLayoutSubviews];
//}
//
//- (void)viewWillDisappear:(BOOL)animated {
//    [super viewWillDisappear:animated];
//    if (self.navigationController) {
//        [self.navigationController setNavigationBarHidden:YES animated:animated];
//    }
//}

- (void)openLoginVC {
#if !TB_PUBLIC_EXAMPLE
    [self openMockLoginVC];
#else
    [self guestLogin];
#endif
}

- (void)guestLogin {
    [TigerTradingSDKManager guestLoginCallBack:^(BOOL isSuccess, NSNumber * _Nonnull code, NSString * _Nonnull message) {
        if (isSuccess) {
            [MBProgressHUD showHint:@"登录成功" hide:2];
        }
        else {
            [MBProgressHUD showHint:message hide:2];
        }
    }];
}


- (void)login:(NSString *)authCode {
    
    [TigerTradingSDKManager registerAutorizationCode:authCode callBack:^(BOOL isSucc, NSNumber * _Nonnull code, NSString * _Nonnull message) {
        if (isSucc) {
//            [TigerTradingSDKManager openHomePageViewController:self];
            [MBProgressHUD showHint:@"登录成功" hide:2];
        }
        else {
            [MBProgressHUD showHint:message hide:2];
        }
    }];
}

- (void)setupTableView {
    // 创建TableView
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
    // 注册Cell
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"Cell"];
    
    // 将TableView添加到视图中
    [self.view addSubview:self.tableView];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    // 获取对应的模型
    TBCellModel *model = self.dataSource[indexPath.row];
    cell.textLabel.text = model.title;
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 40;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    // 获取对应的模型
    TBCellModel *model = self.dataSource[indexPath.row];
    
    // 执行对应的点击事件
    if (model.action) {
        model.action();
    }
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}


@end
