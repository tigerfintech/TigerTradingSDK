//
//  TBViewController+TBDataSource.m
//  TigerQuoteSDK
//
//  Created by wind on 2025/12/18.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBViewController+TBDataSource.h"
#import "TBCellModel.h"
#if !TB_PUBLIC_EXAMPLE
#import "TBTokenManangerViewController.h"
#endif
#import "TBFunctionController.h"
#if !TB_PUBLIC_EXAMPLE
#import "TBViewController+TBMockLogin.h"
#endif

#import "TBViewController+TBSettingDataSource.h"
#import "TBViewController+TBJumpVCDataSource.h"
#import "TBViewController+TBFunctionDataSource.h"
#import "TBViewController+TBFunctionDataSource.h"

#import <TigerTradingSDK/TigerTradingSDKSettingManager.h>
#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#if __has_include(<TigerTradingSDK/TigerQuoteSDKDebugViewController.h>)
#import <TigerTradingSDK/TigerQuoteSDKDebugViewController.h>
#endif
#import "TBAppDelegate.h"

@import TBUIKit;
@import TBBusinessSupportKit;
@import TBWebView;
@import TBAccountSystemKit;
@import TBBaseKit;

@implementation TBViewController (TBDataSource)

- (void)setupDataSource {
    [self setupMainDataSource];
    [self setupSettingDataSource];
    [self setupJumpVCDataSource];
    [self setupFunctionDataSource];
}

// 创建数据源
- (void)setupMainDataSource {
    TBCellModel *settingModel = [[TBCellModel alloc] initWithTitle:@"设置" action:^{
        TBFunctionController *vc = [[TBFunctionController alloc] init];
        vc.dataSource = self.settingDataSource;
        vc.sectionTitles = self.settingDataSourceTitles;
        [self presentViewController:vc animated:YES completion:nil];
    }];
    
    TBCellModel *modelColor = [[TBCellModel alloc] initWithTitle:@"切换涨跌色类型" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择涨跌色类型"
                                                                                 message:@"请选择一个涨跌颜色"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *redDownAction = [UIAlertAction actionWithTitle:@"使用绿（积极色）涨，红（消极色）跌"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeGreen];
        }];
        
        UIAlertAction *redUpAction = [UIAlertAction actionWithTitle:@"使用红（消极色）涨，绿（积极色）跌"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeRed];
        }];

        
        
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:redDownAction];
        [alertController addAction:redUpAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *detailColorModel = [[TBCellModel alloc] initWithTitle:@"切换积极||消极色对应的色值" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"选择涨跌色色值"
                                                                                 message:@"请选择一个涨跌颜色"
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *redDownAction = [UIAlertAction actionWithTitle:@"积极色：绿  消极色：红"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            TigerTradingCustomColorModel *quoteRiseColor = [[TigerTradingCustomColorModel alloc] init];
            quoteRiseColor.light_HexColor = @"0x27c77e";
            quoteRiseColor.dark_HexColor = @"0x27c77e";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteRiseColor
                                                    colorModel:quoteRiseColor];
            
            TigerTradingCustomColorModel *quoteFallColor = [[TigerTradingCustomColorModel alloc] init];
            quoteFallColor.light_HexColor = @"0xf25855";
            quoteFallColor.dark_HexColor = @"0xf25855";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteFallColor
                                                    colorModel:quoteFallColor];

            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeRed];

        }];
        
        UIAlertAction *redUpAction = [UIAlertAction actionWithTitle:@"积极色：红  消极色：绿"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            TigerTradingCustomColorModel *quoteRiseColor = [[TigerTradingCustomColorModel alloc] init];
            quoteRiseColor.light_HexColor = @"0xf25855";
            quoteRiseColor.dark_HexColor = @"0xf25855";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteRiseColor
                                                    colorModel:quoteRiseColor];
            
            TigerTradingCustomColorModel *quoteFallColor = [[TigerTradingCustomColorModel alloc] init];
            quoteFallColor.light_HexColor = @"0x27c77e";
            quoteFallColor.dark_HexColor = @"0x27c77e";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteFallColor
                                                    colorModel:quoteFallColor];

            [TigerTradingSDKSettingManager setTigerQuoteIncreaseColorType:TigerTradingSDKIncreaseColorTypeRed];

        }];

        UIAlertAction *orangeUpAction = [UIAlertAction actionWithTitle:@"积极色：蓝  消极色：紫"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            
            // 蓝色
            TigerTradingCustomColorModel *quoteRiseColor = [[TigerTradingCustomColorModel alloc] init];
            quoteRiseColor.light_HexColor = @"0x00b5ff";
            quoteRiseColor.dark_HexColor = @"0x00b5ff";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteRiseColor
                                                    colorModel:quoteRiseColor];
            // 紫色
            TigerTradingCustomColorModel *quoteFallColor = [[TigerTradingCustomColorModel alloc] init];
            quoteFallColor.light_HexColor = @"0xb366ff";
            quoteFallColor.dark_HexColor = @"0xb366ff";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteFallColor
                                                    colorModel:quoteFallColor];

                    }];
        UIAlertAction *orangeDownAction = [UIAlertAction actionWithTitle:@"积极色：紫色  消极色：蓝"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            
            // 紫色
            TigerTradingCustomColorModel *quoteFallColor = [[TigerTradingCustomColorModel alloc] init];
            quoteFallColor.light_HexColor = @"0xb366ff";
            quoteFallColor.dark_HexColor = @"0xb366ff";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteRiseColor
                                                    colorModel:quoteFallColor];
            
            // 蓝色
            TigerTradingCustomColorModel *quoteRiseColor = [[TigerTradingCustomColorModel alloc] init];
            quoteRiseColor.light_HexColor = @"0x00b5ff";
            quoteRiseColor.dark_HexColor = @"0x00b5ff";
            [TigerTradingSDKSettingManager setCustomerSDKColor:TigerTradingSDKColorTypeQuoteFallColor
                                                    colorModel:quoteRiseColor];
            
        }];
        
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:redDownAction];
        [alertController addAction:redUpAction];
        [alertController addAction:orangeUpAction];
        [alertController addAction:orangeDownAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];

#if !TB_PUBLIC_EXAMPLE && __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    TBCellModel *modelServer = [self internalNetworkMenuItem];
#endif
    
    TBCellModel *networkModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@切换线上服务器", [self fetch930Title]] action:^{
        if (IS_TEST_ENV) {
            // 2是线上环境
            [MBProgressHUD showHint:@"当前不是线上环境，需要切换线上服务器才能切换UAT || PROD-ITFS" hide:2];
            return;
        }
        
        NSString *msg = [self fetchCurrentNetworkDescription];
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"切换线上服务器"
                                                                                 message:msg
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        
        UIAlertAction *changeSTAGINGlAction = [UIAlertAction actionWithTitle:@"切换成STAGING"
                                                                   style:UIAlertActionStyleDefault
                                                             handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKManager setupNetWorkEnvironment:TigerTradingSDKNetWork_STAGING];
            [MBProgressHUD showHint:[self fetchCurrentNetworkDescription] hide:2];
            [self saveEnvironmentConfig:TigerTradingSDKNetWork_STAGING];
        }];

        
        UIAlertAction *changeUATlAction = [UIAlertAction actionWithTitle:@"切换成UAT"
                                                                   style:UIAlertActionStyleDefault
                                                             handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKManager setupNetWorkEnvironment:TigerTradingSDKNetWork_UAT];
            [MBProgressHUD showHint:[self fetchCurrentNetworkDescription] hide:2];
            [self saveEnvironmentConfig:TigerTradingSDKNetWork_UAT];
        }];
        
        UIAlertAction *changePRODAction = [UIAlertAction actionWithTitle:@"切换成PROD-ITFS"
                                                               style:UIAlertActionStyleDefault
                                                             handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKManager setupNetWorkEnvironment:TigerTradingSDKNetWork_PRODITFS];
            [MBProgressHUD showHint:[self fetchCurrentNetworkDescription] hide:2];
            [self saveEnvironmentConfig:TigerTradingSDKNetWork_PRODITFS];
        }];
        
        UIAlertAction *changeUATITFSAction = [UIAlertAction actionWithTitle:@"切换成UAT-ITFS"
                                                               style:UIAlertActionStyleDefault
                                                             handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKManager setupNetWorkEnvironment:TigerTradingSDKNetWork_UAT_ITFS];
            [MBProgressHUD showHint:[self fetchCurrentNetworkDescription] hide:2];
            [self saveEnvironmentConfig:TigerTradingSDKNetWork_UAT_ITFS];
        }];
        
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        
        [alertController addAction:changeSTAGINGlAction];
        [alertController addAction:changeUATlAction];
        [alertController addAction:changePRODAction];
        [alertController addAction:changeUATITFSAction];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];

    }];

#if !TB_PUBLIC_EXAMPLE
    TBCellModel *tradeTokenModel = [self defaultTradeTokenMenuItem];
#endif


    
    TBCellModel *versionModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"SDK版本号:%@", [TigerTradingSDKManager sdkVersion]] action:^{
        NSString *strVersion = [TigerTradingSDKManager sdkVersion];
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"版本号"
                                                                                 message:strVersion
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        [alertController addAction:cancelAction];

        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
#if !TB_PUBLIC_EXAMPLE
    TBCellModel *tokenModel = [[TBCellModel alloc] initWithTitle:@"保存Token" action:^{
        TBTokenManangerViewController *vc = [[TBTokenManangerViewController alloc] init];
//        if (self.navigationController) {
//            [self.navigationController pushViewController:vc animated:YES];
//        }
//        else {
            [self presentViewController:vc animated:YES completion:nil];
//        }
//        [self presentViewController:vc animated:YES completion:nil];
    }];
#endif
    
    NSString *loginTitle = @"游客登录";
#if !TB_PUBLIC_EXAMPLE
    loginTitle = @"⭐️登录";
#endif
    
    TBCellModel *commonLoginModel = [[TBCellModel alloc] initWithTitle:loginTitle action:^{
        [self openLoginVC];
    }];
    
    TBCellModel *commonLogoutModel = [[TBCellModel alloc] initWithTitle:@"登出" action:^{
        [TigerTradingSDKManager sdkLogout];
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(10 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            [TigerTradingSDKManager sdkLogout];
//        });
        
//        [TigerTradingQuoteManager subscribeQuote:@[@"TSLA",@"AAPL",@"00700"] callBack:^(NSDictionary * _Nonnull dic) {
//            NSLog(@"zzw:%@",dic);
//        }];
    }];
    
    TBCellModel *gotoAllFunciton = [[TBCellModel alloc] initWithTitle:@"跳转全部功能页面" action:^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            // 保证金账户升级
//            [TBService(TBTradeBusinessComponentService) tbTradeBusiness_AllAccountHelperHandleAccountAction:TBAllAccountActionTypeUpgradeToMargin];
            
            // 分红记录
            [TBService(TBTradeBusinessComponentService) tbTradeBusiness_AllAccountHelperHandleAccountAction:TBAllAccountActionTypeDividentHistory];
        });
    }];
    

     
    TBCellModel *homepageModel = [[TBCellModel alloc] initWithTitle:@"⭐️跳转首页" action:^{
        NSLog(@"Tapped on Item 4");
        
        [TBAppDelegate updateUserInfoConfig];
        // 实现对应的逻辑
        [TigerTradingSDKManager openHomePageViewController: self];
        
    }];
        
#if !TB_PUBLIC_EXAMPLE
    TBCellModel *cmbModel = [[TBCellModel alloc] initWithTitle:@"AuthCode流程登录" action:^{
        [self openMockAuthCodeLogin];
    }];
#endif

    TBCellModel *authorizationModel = [[TBCellModel alloc] initWithTitle:@"Authorization登录" action:^{
        NSString *appName = [TigerTradingSDKManager currentAppName];
        NSString *tenantId = [TBAppManager tenantId];

        NSString *alertTitle = @"当前配置确认";
        NSString *alertMessage = [NSString stringWithFormat:
            @"AppName：%@\nTenantId：%@",
            appName ?: @"-",
            tenantId ?: @"-"
        ];
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:alertTitle
                                                                                 message:alertMessage
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入Authorization";
        }];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
            
        }];
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确定"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            UITextField *textField = alertController.textFields.firstObject;
            if (textField.text.length > 0) {
                NSString *Authorization = textField.text;
                
                // 登录
                [self login:Authorization];
            }
        }];
        [alertController addAction:cancelAction];
        [alertController addAction:confirmAction];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *tradePermissionModel = [[TBCellModel alloc] initWithTitle:@"usOTC交易权限缺失" action:^{
        [TBAccountUtils showOpenTradePemissionAlert:usOTCTrade];
    }];

    NSArray *switchColorNames = @[@"红",@"橙", @"黄", @"绿", @"青", @"蓝",@"紫",@"棕"];
    NSMutableArray *baseColorArr = [NSMutableArray array];
    NSMutableArray *textColorArr = [NSMutableArray array];

    TBCellModel *resetColorSwitchModel = [[TBCellModel alloc] initWithTitle:@"重置颜色为TT色值" action:^{
        [TigerTradingSDKSettingManager resetAllCustomColor];
        [MBProgressHUD showHint:@"色值重置回tt色值" hide:3];
    }];

    for (int i = 0; i < 8; i++) {
        TBCellModel *colorItemModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"将颜色A%d替换为%@色", i, switchColorNames[i]] action:^{
            NSBundle *bundle = [NSBundle mainBundle];
            NSString *path = [bundle pathForResource:@"TigerTradeSDKColor" ofType:@"plist"];
            NSDictionary *dic = [[NSDictionary alloc] initWithContentsOfFile:path];
            NSMutableDictionary *tempDic = [NSMutableDictionary dictionaryWithDictionary:dic];
            switch (i) {
                case 0:tempDic[@"A0"] = @[@{@"colors":@"#FF0000"}, @{@"colors":@"#FF0000"}];break;
                case 1:tempDic[@"TB_Background_GlobalFG"] = @[@{@"colors":@"#FF8800"}, @{@"colors":@"#FF8800"}];break;
                case 2:tempDic[@"TB_Background_ListClick"] = @[@{@"colors":@"#FFF700"}, @{@"colors":@"#FFF700"}];break;
                case 3:tempDic[@"TB_Border_Divider"] = @[@{@"colors":@"#11FF00"}, @{@"colors":@"#11FF00"}];break;
                case 4:tempDic[@"TB_Background_GlobalBG"] = @[@{@"colors":@"#00F2FF"}, @{@"colors":@"#00F2FF"},];break;
                case 5:tempDic[@"TB_Background_GrayCard"] = @[@{@"colors":@"#001aff"}, @{@"colors":@"#001aff"},];break;
                case 6:tempDic[@"A6"] = @[@{@"colors":@"#8000ff"}, @{@"colors":@"#8000ff"}];break;
                case 7:tempDic[@"A7"] = @[@{@"colors":@"#895129"}, @{@"colors":@"#895129"}];break;
                default:break;
            }
            [TigerTradingSDKSettingManager setCustomerSDKColorPlistDictionary:tempDic];
        }];
        [baseColorArr addObject:colorItemModel];
    }

    switchColorNames = @[@"一级文字颜色:红",@"二级文字颜色:橙", @"三级文字颜色:黄", @"链接色:青"];
    for (int i = 0; i < switchColorNames.count; i++) {
        TBCellModel *colorItemModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@",switchColorNames[i]] action:^{
            NSBundle *bundle = [NSBundle mainBundle];
            NSString *path = [bundle pathForResource:@"TigerTradeSDKColor" ofType:@"plist"];
            NSDictionary *dic = [[NSDictionary alloc] initWithContentsOfFile:path];
            NSMutableDictionary *tempDic = [NSMutableDictionary dictionaryWithDictionary:dic];
            switch (i) {
                case 0:tempDic[@"TB_BaseColor_Primary"] = @[@{@"colors":@"#FF0000"}, @{@"colors":@"#FF0000"}];break;
                case 1:tempDic[@"TB_BaseColor_Secondary"] = @[@{@"colors":@"#FF8800"}, @{@"colors":@"#FF8800"}];break;
                case 2:tempDic[@"TB_BaseColor_Tertiary"] = @[@{@"colors":@"#FFF700"}, @{@"colors":@"#FFF700"}];break;
                case 3:tempDic[@"TB_BaseColor_Link"] = @[@{@"colors":@"#00F2FF"}, @{@"colors":@"#00F2FF"}];break;
                default:break;
            }
            [TigerTradingSDKSettingManager setCustomerSDKColorPlistDictionary:tempDic];
        }];
        [textColorArr addObject:colorItemModel];
    }
    self.testColorSwitchDataSourceTitles = @[@"重置", @"基础色 (A0-A7)", @"文字/链接色"];
    self.testColorSwitchDataSource = @{
        @"重置": @[resetColorSwitchModel],
        @"基础色 (A0-A7)": [baseColorArr copy],
        @"文字/链接色": [textColorArr copy],
    };

    TBCellModel *jumpModel = [[TBCellModel alloc] initWithTitle:@"跳转合集" action:^{
        TBFunctionController *vc = [[TBFunctionController alloc] init];
        vc.sectionTitles = self.jumpVCDataSourceTitles;
        vc.dataSource = self.jumpVCDataSource;
        [self presentViewController:vc animated:YES completion:nil];
    }];
    
    TBCellModel *functionModel = [[TBCellModel alloc] initWithTitle:@"方法合集" action:^{
        TBFunctionController *vc = [[TBFunctionController alloc] init];
        vc.sectionTitles = self.functionDataSourceTitles;
        vc.dataSource = self.functionDataSource;
        [self presentViewController:vc animated:YES completion:nil];
    }];

//    TBCellModel *homepageAssetModel = [[TBCellModel alloc] initWithTitle:@"切换账号执行原有逻辑" action:^{
//        TBHomePageAssetViewController
//    }];
//    TBCellModel *mLegOptionPlaceOrderModel = [[TBCellModel alloc] initWithTitle:@"跳转组合期权下单" action:^{
//        TBTigerTradingOrderBasicInfoModel *infoModel = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:@"US" secType:@"OPT" symbol:@"NVDA 20250307 114.0 CALL" action:@"SELL" ratio:@1];
//        TBTigerTradingOrderBasicInfoModel *info2Model = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:@"US" secType:@"OPT" symbol:@"NVDA 20250307 115.0 CALL" action:@"BUY" ratio:@1];
//        [TigerTradingTradeManager openMLegsPlaceOrderPage:TBOptionCombinationStrategyTypeVertical mLegs:@[infoModel, info2Model] fromViewController:self];
//    }];
    
#if !TB_PUBLIC_EXAMPLE
    TBCellModel *tupLoginVCModel = [self internalTUPLoginMenuItem];
#endif
    


#if __has_include(<TigerTradingSDK/TigerQuoteSDKDebugViewController.h>)
    TBCellModel *logExport = [[TBCellModel alloc] initWithTitle:@"日志" action:^{
        [TigerQuoteSDKDebugViewController presentFrom:[TBSupportUtility getTopVC]];
    }];
#endif

    
//    TBCellModel *tradeSecuritiesModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@跳转持仓页面", [self fetch23Title:NO]] action:^{
//#if __has_include(<TigerTradingSDK/TigerTradingTradeManager.h>)
//        [TigerTradingTradeManager openTradeSecuritiesPageFromViewController:self];
//#endif
//    }];

    
#if TTSDK_TEST
    self.dataSource = @[
        settingModel, // 设置功能
#if !TB_PUBLIC_EXAMPLE && __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
        modelServer, // 切换服务器
#endif
        networkModel, // prod-itfs  uat 切换
        commonLoginModel, // 登录 && 登出
#if !TB_PUBLIC_EXAMPLE
        tupLoginVCModel, //tup 登录
#endif
        commonLogoutModel, // 登出
        homepageModel, // 首页
        jumpModel, // 跳转合集
//        gotoAllFunciton, // 跳转全部功能页面
        functionModel, // 方法合集
#if __has_include(<TigerTradingSDK/TigerQuoteSDKDebugViewController.h>)
        logExport, // 日志导出
#endif
        resetColorSwitchModel, // 重置色值变换
        modelColor, // 涨跌色
        detailColorModel, // 具体积极色消极色色值
        authorizationModel,
#if !TB_PUBLIC_EXAMPLE
        tradeTokenModel, // 切换交易token认证
#endif
#if !TB_PUBLIC_EXAMPLE
        tokenModel, // 保存Token
#endif
#if !TB_PUBLIC_EXAMPLE
        cmbModel, //authcode登录
#endif
        
        versionModel, // SDK版本号
    ];
#else
    self.dataSource = @[
        settingModel, // 设置功能
        networkModel, // 环境切换
        homepageModel, // 首页
        commonLoginModel, // 登录 && 登出
        jumpModel, // 跳转合集
        versionModel, // SDK版本号
        modelColor // 涨跌色
    ];
    
#if !TB_PUBLIC_EXAMPLE
    [self performDefaultMockLogin];
#endif
#endif
}

- (NSString *)fetchCurrentNetworkDescription {
    NSString *uatMessage = @"当前使用UAT";
    NSString *prodMessage = @"当前使用prod-itfs";
    NSString *stagingMessage = @"当前使用Staging";
    NSString *uatItfsMessage = @"当前使用uat-itfs";
    
    NSString *msg;
    if ([TigerTradingSDKManager currentNetworkEnvironment] == 0) {
        msg = prodMessage;
    }
    else if ([TigerTradingSDKManager currentNetworkEnvironment] == 1) {
        msg = uatMessage;
    }
    else if ([TigerTradingSDKManager currentNetworkEnvironment] == 2) {
        msg = stagingMessage;
    }
    else if ([TigerTradingSDKManager currentNetworkEnvironment] == 3) {
        msg = uatItfsMessage;
    }
    else {
        msg = prodMessage;
    }
    return msg;
}

- (NSString *)fetch23Title:(BOOL)isSub {
#if DEBUG
    if (isSub) {
        return @"[23 sub]";
    }
    else {
        return @"[23]";
    }
#else
    return @"";
#endif
}

- (NSString *)fetch930Title {
#if DEBUG
    return @"[930]";
#else
    return @"";
#endif
}

- (void)saveEnvironmentConfig:(TigerTradingSDKNetWorkType)networkType {
    NSDictionary *config = [[NSUserDefaults standardUserDefaults] objectForKey:kTigerTradeLaunchConfig];
    NSMutableDictionary *multiConfig = config ? [config mutableCopy] : [[NSMutableDictionary alloc] init];
    [multiConfig setValue:@(networkType) forKey:@"environment"];
    [[NSUserDefaults standardUserDefaults] setObject:multiConfig forKey:kTigerTradeLaunchConfig];
    
    
}

@end
