//
//  TBViewController+TBSettingDataSource.m
//  TigerQuoteSDK
//
//  Created by wind on 2025/12/18.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBViewController+TBSettingDataSource.h"
#if !TB_PUBLIC_EXAMPLE
#import "TBViewController+TBInternalTestActions.h"
#endif
#import "TBCellModel.h"
#import "TBFunctionController.h"

#import <TigerTradingSDK/TigerTradingSDKSettingManager.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
#import <TigerTradingSDK/TigerQuoteDebugMananger.h>
#import "TBSDKDelegateDebugViewController.h"
#endif

#import <UserNotifications/UserNotifications.h>

@import TBUIKit;
@import TBBaseKit;


@implementation TBViewController (TBSettingDataSource)

// 设置配置项
- (void)setupSettingDataSource {
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    if (!self.delegateDebugVC) {
        self.delegateDebugVC = [[TBSDKDelegateDebugViewController alloc] init];
        TigerQuoteDebugMananger.debugDelegate = self.delegateDebugVC;
    }
#endif
    
    TBCellModel *changeColorModel = [[TBCellModel alloc] initWithTitle:@"切换皮肤" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择皮肤"
                                                                                 message:@"请选择一个皮肤样式"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *whiteSkinAction = [UIAlertAction actionWithTitle:@"使用浅色皮肤"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            // 处理选择白皮肤的逻辑
            [TigerTradingSDKSettingManager setAppColorStyle:TigerTradingSDKAppearTypeLight];
        }];
        UIAlertAction *blackSkinAction = [UIAlertAction actionWithTitle:@"使用深色皮肤"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            // 处理选择黑皮肤的逻辑
            [TigerTradingSDKSettingManager setAppColorStyle:TigerTradingSDKAppearTypeDark];
        }];
        UIAlertAction *autoAction = [UIAlertAction actionWithTitle:@"跟随系统"
                                                             style:UIAlertActionStyleDefault
                                                           handler:^(UIAlertAction * _Nonnull action) {
            // 跟随系统
            [TigerTradingSDKSettingManager setAppColorStyle:TigerTradingSDKAppearTypeAuto];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:whiteSkinAction];
        [alertController addAction:blackSkinAction];
        [alertController addAction:autoAction];
        [alertController addAction:cancelAction];
        
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *langModel = [[TBCellModel alloc] initWithTitle:@"切换语言" action:^{
        
        //AppleLanguages 控制剪切板这些设置，要重启 app 才生效
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择语言"
                                                                                 message:@"请选择语言"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *autoAction = [UIAlertAction actionWithTitle:@"Auto"
                                                             style:UIAlertActionStyleDefault
                                                           handler:^(UIAlertAction * _Nonnull action) {
            NSLog(@"选择了自动");
            [[NSUserDefaults standardUserDefaults] removeObjectForKey:@"AppleLanguages"];
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeAuto];
        }];
        UIAlertAction *enAction = [UIAlertAction actionWithTitle:@"English"
                                                           style:UIAlertActionStyleDefault
                                                         handler:^(UIAlertAction * _Nonnull action) {
            [[NSUserDefaults standardUserDefaults] setObject:@[@"en"] forKey:@"AppleLanguages"];
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeEnglish];
        }];
        
        UIAlertAction *zhHansAction = [UIAlertAction actionWithTitle:@"简体中文"
                                                               style:UIAlertActionStyleDefault
                                                             handler:^(UIAlertAction * _Nonnull action) {
            [[NSUserDefaults standardUserDefaults] setObject:@[@"zh-Hans"] forKey:@"AppleLanguages"];
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeZhHans];
        }];
        UIAlertAction *zhHantAction = [UIAlertAction actionWithTitle:@"繁体中文"
                                                               style:UIAlertActionStyleDefault
                                                             handler:^(UIAlertAction * _Nonnull action) {
            [[NSUserDefaults standardUserDefaults] setObject:@[@"zh-Hant"] forKey:@"AppleLanguages"];
            [TigerTradingSDKSettingManager setTigerQuoteLanguage:TigerTradingLanguageTypeZhHant];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:autoAction];
        [alertController addAction:enAction];
        [alertController addAction:zhHansAction];
        [alertController addAction:zhHantAction];
        [alertController addAction:cancelAction];
        
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *symbolUPDownModel = [[TBCellModel alloc] initWithTitle:@"切换symbol位置" action:^{
        BOOL isSymbolFirst = [TigerTradingSDKSettingManager currentSymbolFirstEnable];
        NSString *str = @"当前设置:symbol在上";
        if (!isSymbolFirst) {
            str = @"当前设置:symbol在下";
        }
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"切换symbol上下位置"
                                                                                 message:str
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *whiteSkinAction = [UIAlertAction actionWithTitle:@"Symbol在上"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setSymbolFirstEnable:YES];
            [MBProgressHUD showHint:@"切换成symbol在上" hide:2];
        }];
        UIAlertAction *blackSkinAction = [UIAlertAction actionWithTitle:@"Symbol在下"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setSymbolFirstEnable:NO];
            [MBProgressHUD showHint:@"切换成symbol在下" hide:2];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:whiteSkinAction];
        [alertController addAction:blackSkinAction];
        [alertController addAction:cancelAction];
        
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *fontNameModel = [[TBCellModel alloc] initWithTitle:@"切换字体" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择字体"
                                                                                 message:@"请选择一个字体"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *oriFontAction = [UIAlertAction actionWithTitle:@"使用SDK自带字体"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setCustomerSDKMediumFontName:nil];
            [TigerTradingSDKSettingManager setCustomerSDKRegularFontName:nil];
        }];
        UIAlertAction *newFontAction = [UIAlertAction actionWithTitle:@"使用自定义字体"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setCustomerSDKMediumFontName:@"Merriweather-Bold"];
            [TigerTradingSDKSettingManager setCustomerSDKRegularFontName:@"Merriweather-Regular"];
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:oriFontAction];
        [alertController addAction:newFontAction];
        [alertController addAction:cancelAction];
        
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *watchlistModel = [[TBCellModel alloc] initWithTitle:@"客户维护自选" action:^{
        NSString *style = @"SDK维护";
        if ([TBAPPFunctionConfigManager sharedInstance].debug_watchlistMode == TBSDKWatchlistModeEnabled) {
            style = @"客户维护(每次重启重置)";
        }
        NSString *message = [NSString stringWithFormat:@"自选为：%@", style];
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"切换自选"
                                                                                 message:message
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        UIAlertAction *action1 = [UIAlertAction actionWithTitle:@"SDK维护"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            [TBAPPFunctionConfigManager sharedInstance].debug_watchlistMode = TBSDKWatchlistModeDisabled;
        }];
        UIAlertAction *action2 = [UIAlertAction actionWithTitle:@"客户维护"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            [TBAPPFunctionConfigManager sharedInstance].debug_watchlistMode = TBSDKWatchlistModeEnabled;
        }];
        
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消"
                                                         style:UIAlertActionStyleCancel
                                                       handler:^(UIAlertAction * _Nonnull action) {
        }];
        
        [alertController addAction:action1];
        [alertController addAction:action2];
        [alertController addAction:cancel];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *openPushModel = [[TBCellModel alloc] initWithTitle:@"开启推送" action:^{
        UNUserNotificationCenter *notiCenter = [UNUserNotificationCenter currentNotificationCenter];
        [notiCenter requestAuthorizationWithOptions:UNAuthorizationOptionAlert | UNAuthorizationOptionBadge | UNAuthorizationOptionSound completionHandler:^(BOOL granted, NSError * _Nullable error) {
            if (granted) {
                
            }
        }];
    }];
    
    
    TBCellModel *changeProLiteModel = [[TBCellModel alloc] initWithTitle:@"pro/lite 切换" action:^{
        TTURLAction *action = [[TTURLAction actionWithURLPath:@"TB://proLiteSwitchPage"] applyAnimated:YES];
        [[TBNavigator navigator] openURLAction:action];
    }];
    
    TBCellModel *stockDetailStyleModel = [[TBCellModel alloc] initWithTitle:@"切换个股页样式（仅针对23SDK生效）" action:^{
        NSString *key = @"notUseQuoteTradeCombinedStyle";
        NSString *style = @"23样式";
        if ([[NSUserDefaults standardUserDefaults] boolForKey:key]) {
            style = @"默认样式";
        }
        NSString *message = [NSString stringWithFormat:@"当前样式为：%@", style];
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"切换个股页样式（重启生效）"
                                                                                 message:message
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        UIAlertAction *action1 = [UIAlertAction actionWithTitle:@"23样式"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            [[NSUserDefaults standardUserDefaults] setObject:@(NO) forKey:key];
        }];
        UIAlertAction *action2 = [UIAlertAction actionWithTitle:@"默认样式"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            [[NSUserDefaults standardUserDefaults] setObject:@(YES) forKey:key];
        }];
        
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消"
                                                         style:UIAlertActionStyleCancel
                                                       handler:^(UIAlertAction * _Nonnull action) {
        }];
        
        [alertController addAction:action1];
        [alertController addAction:action2];
        [alertController addAction:cancel];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    
    TBCellModel *configOpenAccountImage = [[TBCellModel alloc] initWithTitle:@"配置首页开户背景图" action:^{
        UIImage *image = [UIImage tb_imageNamed:@"bubble_guide_down_left_horizen"];
        [TigerTradingQuoteManager configOpenAccountimage:image];
    }];
    
    TBCellModel *accountSwithcModel = [[TBCellModel alloc] initWithTitle:@"切换账号执行原有逻辑" action:^{
        self.isContinueSwitchAccount = !self.isContinueSwitchAccount;
        NSString *str = self.isContinueSwitchAccount?@"点击切换账号\n执行业务自定义逻辑\n继续原有切换逻辑":@"点击切换账号\n执行业务自定义逻辑";
        [MBProgressHUD showHint:str hide:3];
    }];
    
    TBCellModel *homepageNameModel = [[TBCellModel alloc] initWithTitle:@"首页证券账号改名" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"修改首页证券账号名称"
                                                                                 message:@"请输入新的名称"
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        // 添加输入框
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入名称";
        }];
        
        // 添加确认按钮
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            UITextField *textField = alertController.textFields.firstObject;
            if (textField.text.length > 0) {
                self.homepageName = textField.text;
                NSLog(@"修改后的 homepageName: %@", self.homepageName);
            }
        }];
        
        // 添加取消按钮
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:nil];
        
        [alertController addAction:confirmAction];
        [alertController addAction:cancelAction];
        
        // 弹出输入框
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *brandNameModel = [[TBCellModel alloc] initWithTitle:@"品牌名改名" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"修改品牌名名称"
                                                                                 message:@"请输入新的名称"
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        // 添加输入框
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入名称";
        }];
        
        // 添加确认按钮
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            UITextField *textField = alertController.textFields.firstObject;
            if (textField.text.length > 0) {
                self.strBrandName = textField.text;
                NSLog(@"修改后的 homepageName: %@", self.strBrandName);
            }
        }];
        
        // 添加取消按钮
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:nil];
        
        [alertController addAction:confirmAction];
        [alertController addAction:cancelAction];
        
        // 弹出输入框
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *updateTradePermissionModel = [[TBCellModel alloc] initWithTitle:@"主动刷新交易权限" action:^{
        [TigerTradingTradeManager updateCurrentTradePermissionsWithCompletion:^(BOOL success, BOOL deposited, NSError * _Nullable error) {
            NSString *hint = [NSString stringWithFormat:@"刷新%@，已入金：%@%@",
                              success ? @"成功" : @"失败",
                              deposited ? @"是" : @"否",
                              error ? [NSString stringWithFormat:@"，%@", error.localizedDescription] : @""];
            [MBProgressHUD showHint:hint hide:3];
        }];
    }];
    
    TBCellModel *tradeDotsEnableModel = [[TBCellModel alloc] initWithTitle:@"设置买卖打点" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"买卖打点"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *openAction = [UIAlertAction actionWithTitle:@"开"
                                                             style:UIAlertActionStyleDefault
                                                           handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingQuoteManager setQuoteTradeDotsEnable:YES];
        }];
        UIAlertAction *closeAction = [UIAlertAction actionWithTitle:@"关"
                                                              style:UIAlertActionStyleDefault
                                                            handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingQuoteManager setQuoteTradeDotsEnable:NO];
        }];
        
        [alertController addAction:openAction];
        [alertController addAction:closeAction];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *positionCostType = [[TBCellModel alloc] initWithTitle:@"持仓成本算法" action:^{
        NSDictionary *map = @{@"Average": @(TBPositionCostTypeAverage),
                              @"FIFO": @(TBPositionCostTypeFIFO),
                              @"Diluted": @(TBPositionCostTypeDiluted)};
        
        NSDictionary *map2 = @{@(TBPositionCostTypeAverage): @"Average",
                               @(TBPositionCostTypeFIFO): @"FIFO",
                               @(TBPositionCostTypeDiluted): @"Diluted"};
        
        TBPositionCostType currentType = [TigerTradingTradeManager positionCostType];
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"持仓成本算法"
                                                                                 message:map2[@(currentType)]
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        UIAlertAction *Average = [UIAlertAction actionWithTitle:@"Average"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingTradeManager setPositionCostType:TBPositionCostTypeAverage];
        }];
        
        UIAlertAction *FIFO = [UIAlertAction actionWithTitle:@"FIFO"
                                                       style:UIAlertActionStyleDefault
                                                     handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingTradeManager setPositionCostType:TBPositionCostTypeFIFO];
        }];
        
        UIAlertAction *Diluted = [UIAlertAction actionWithTitle:@"Diluted"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingTradeManager setPositionCostType:TBPositionCostTypeDiluted];
        }];
        
        [alertController addAction:Average];
        [alertController addAction:FIFO];
        [alertController addAction:Diluted];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *testColorSwitchModel = [[TBCellModel alloc] initWithTitle:@"测试颜色切换功能" action:^{
        TBFunctionController *vc = [[TBFunctionController alloc] init];
        vc.sectionTitles = self.testColorSwitchDataSourceTitles;
        vc.dataSource = self.testColorSwitchDataSource;
        [self presentViewController:vc animated:YES completion:nil];
    }];
    
    TBCellModel *displayOptionLapseModel = [[TBCellModel alloc] initWithTitle:@"期权行权页面，是否展示放弃行权" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"是否展示放弃行权"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        UIAlertAction *confirm = [UIAlertAction actionWithTitle:@"是"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            self.needDisplayOptionLapse = YES;
        }];
        
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"否"
                                                         style:UIAlertActionStyleDefault
                                                       handler:^(UIAlertAction * _Nonnull action) {
            self.needDisplayOptionLapse = NO;
        }];
        
        
        
        [alertController addAction:confirm];
        [alertController addAction:cancel];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *displayEarlyExerciseModel = [[TBCellModel alloc] initWithTitle:@"期权行权页面，是否展示提前行权" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"是否展示提前行权"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        UIAlertAction *confirm = [UIAlertAction actionWithTitle:@"是"
                                                          style:UIAlertActionStyleDefault
                                                        handler:^(UIAlertAction * _Nonnull action) {
            self.needDisplayEarlyExercise = YES;
        }];
        
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"否"
                                                         style:UIAlertActionStyleDefault
                                                       handler:^(UIAlertAction * _Nonnull action) {
            self.needDisplayEarlyExercise = NO;
        }];
        
        
        
        [alertController addAction:confirm];
        [alertController addAction:cancel];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
#if !TB_PUBLIC_EXAMPLE
    TBCellModel *languageAlertModel = [self internalLanguageDebugMenuItem];
#endif

#if TTSDK_TEST
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    @TB_weakify(self);
    TBCellModel *hostCustomQuoteModel = [[TBCellModel alloc] initWithTitle:@"宿主自定义行情" action:^{
        @TB_strongify(self);
        [self.delegateDebugVC showHostQuoteSettingsWithQuoteType:self.appQuoteType
                                                   changeHandler:^(TigerTradingSDKQuoteType quoteType) {
            @TB_strongify(self);
            self.appQuoteType = quoteType;
        }];
        [self.navigationController pushViewController:self.delegateDebugVC animated:YES];
    }];

    TBCellModel *delegateDebugModel = [[TBCellModel alloc] initWithTitle:@"客户自定义实现开关" action:^{
        [self.delegateDebugVC showAllDelegateSettings];
        [self.navigationController pushViewController:self.delegateDebugVC animated:YES];
    }];

#endif

    self.settingDataSourceTitles = @[@"通用", @"期权"];
    self.settingDataSource = @{
        @"通用": @[changeColorModel, // 切换皮肤
                 langModel, // 选择语言
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
                 hostCustomQuoteModel, // 宿主自定义行情
#endif
                 symbolUPDownModel, // 切换symbol位置
                 fontNameModel, // font切换
                 watchlistModel, // 切换自选维护
                 openPushModel, // 开启通知
                 changeProLiteModel, // pro/lite 切换
                 stockDetailStyleModel, // 个股页样式
                 configOpenAccountImage, // 替换首页开户背景图片
                 accountSwithcModel, // 切换账号后是否继续执行原有逻辑
                 homepageNameModel, // 首页证券账号改名
                 brandNameModel, // 品牌名改名
                 updateTradePermissionModel, // 主动刷新交易权限
                 tradeDotsEnableModel, // 买卖打点
                 positionCostType, //持仓成本算法
                 testColorSwitchModel, // 测试颜色替换
#if !TB_PUBLIC_EXAMPLE
                 languageAlertModel, // 内部多语言校验
#endif
#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
                 delegateDebugModel, // 代理实现调试
#endif
        ],
        @"期权": @[
            displayOptionLapseModel, // 是否展示放弃行权
            displayEarlyExerciseModel, // 是否展示提前行权
        ]};
#else
    self.settingDataSourceTitles = @[@"通用"];
    self.settingDataSource = @{
        @"通用": @[
            changeColorModel, // 切换皮肤
            langModel, // 选择语言
//            modelColor, // 涨跌色
            fontNameModel, // font切换
        ]
    };
#endif
}

@end
