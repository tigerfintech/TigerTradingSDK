//
//  TBViewController+TBJumpVCDataSource.m
//  TigerQuoteSDK
//
//  Created by wind on 2025/12/18.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import "TBViewController+TBJumpVCDataSource.h"
#import "TBCellModel.h"
#import "TBViewController+TBDataSource.h"
#import "TBSubOrderFilterViewController.h"
#import "TBTradeSecuritiesDemoViewController.h"
#import "TBUserAccountPageViewController.h"
#import "TBSubMarketIndicesViewController.h"
#import "TBDemoQuoteTabViewController.h"
#import "TBSDKAllFunctionViewController.h"
#import "TB23SDKStockDetailViewController.h"
#import "TBOptionChainPageViewController.h"
#import "TBOptionPageViewController.h"
#import "TBOptionDetailViewController.h"
#import "TBModuleViewController.h"
#import "TBPositionTabViewController.h"
#import "TBOrderModuleVC.h"

#if __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    #import <TigerTradingSDK/TigerQuoteDebugMananger.h>
#endif

#import <TigerTradingSDK/TigerTradingSDKSettingManager.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <TigerTradingSDK/TigerTradingSDKManager.h>
#if !TB_PUBLIC_EXAMPLE
#import "TBViewController+TBInternalTestActions.h"
#endif

@import TBStockKit;
@import TBUIKit;
@import TBToolsKit;

@implementation TBViewController (TBJumpVCDataSource)

// 跳转页面Model配置项
- (void)setupJumpVCDataSource {
    TBCellModel *subOrderModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@订单嵌套页", [self fetch23Title:YES]] action:^{
        
        TBSubOrderFilterViewController *vc = [[TBSubOrderFilterViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:nav animated:YES completion:nil];
        }
        
    }];
    
    TBCellModel *subConditionOrderModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@ 条件订单嵌套页", [self fetch23Title:YES]] action:^{
        
        TBSubOrderFilterViewController *vc = [[TBSubOrderFilterViewController alloc] init];
        vc.isConditionOrder = YES;
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:nav animated:YES completion:nil];
        }
        
    }];
    
#if !TB_PUBLIC_EXAMPLE
    TBCellModel *webModel = [self internalWebDebugMenuItem];
#endif

    TBCellModel *fundingDetailModel = [[TBCellModel alloc] initWithTitle:@"跳转资产明细" action:^{
        [TigerTradingTradeManager openFundingDetailPageFromViewController:self];
    }];
    
    TBCellModel *assetsDetailModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@跳转用户资产详情页面", [self fetch23Title:NO]] action:^{
#if __has_include(<TigerTradingSDK/TigerTradingTradeManager.h>)
        [TigerTradingTradeManager openUserAccountPageFromViewController:self];
#endif
    }];
    
    TBCellModel *subtradeSecuritiesModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@持仓嵌套页面", [self fetch23Title:YES]] action:^{
        
        TBTradeSecuritiesDemoViewController *vc = [[TBTradeSecuritiesDemoViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:nav animated:YES completion:nil];
        }
    }];
    
    
    TBCellModel *subUserAccountPageModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@资产嵌套页面", [self fetch23Title:YES]] action:^{
        
        TBUserAccountPageViewController *vc = [[TBUserAccountPageViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:nav animated:YES completion:nil];
        }
    }];
    
    TBCellModel *usMarketIndicesModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@US市场指数", [self fetch23Title:YES]] action:^{
        
        TBSubMarketIndicesViewController *vc = [[TBSubMarketIndicesViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:nav animated:YES completion:nil];
        }
    }];
    
    TBCellModel *subMarketModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@跳转市场页", [self fetch23Title:YES]] action:^{
        TBDemoQuoteTabViewController *vc = [[TBDemoQuoteTabViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        
        
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:nav animated:YES completion:nil];
        }
        
    }];
    
    TBCellModel *subMoreVCModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@更多页面（提供数据源）", [self fetch23Title:NO]] action:^{
        TBSDKAllFunctionViewController *vc = [[TBSDKAllFunctionViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        
        if (self.navigationController) {
            [self.navigationController pushViewController:vc animated:YES];
        }
        else {
            [self presentViewController:nav animated:YES completion:nil];
        }
        
    }];
    
    TBCellModel *netModel = [[TBCellModel alloc] initWithTitle:@"网页测速" action:^{
        [TigerTradingSDKManager openNetworkInspectorPageFromViewController:self];
    }];
    
    TBCellModel *searchModel = [[TBCellModel alloc] initWithTitle:@"打开搜索页面" action:^{
        [TigerTradingSDKManager openSearchViewController:self];
    }];
    
    TBCellModel *orderlListModel = [[TBCellModel alloc] initWithTitle:@"跳转订单列表" action:^{
        NSLog(@"Tapped on Item 4");
        // 实现对应的逻辑
        [TigerTradingTradeManager openOrderListViewController: self];
    }];
    
    TBCellModel *detailModel = [[TBCellModel alloc] initWithTitle:@"跳转Apple 详情页" action:^{
        NSLog(@"Tapped on Item 5");
#if __has_include(<TigerTradingSDK/TigerTradingQuoteManager.h>)
        [TigerTradingQuoteManager openStockDetailPageWithSymbol:@"AAPL" market:@"US" fromViewController:self];
#endif
        
    }];
    
    TBCellModel *detail23Model = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@ 跳转Apple详情页",[self fetch23Title:NO]] action:^{
        NSMutableDictionary *query = [NSMutableDictionary dictionary];
        [query setValue:@"AAPL" forKey:@"symbol"];
        [query setValue:@"US" forKey:@"market"];
        [query setValue:SEC_TYPE_STK forKey:@"secType"];
        
//        UIViewController *vc = [[TB23SDKStockDetailViewController alloc] initWithNavigatorURL:nil query:query];
        
//        TBNavigationController *nav = [[TBNavigationController alloc] initWithRootViewController:vc];
//        [self tbPresentViewController:nav animated:YES completion:nil isPushStyle:YES];
//        [[TBNavigator navigator] setRootViewController:vc];
    }];
    
    TBCellModel *optionTSLAChainModel = [[TBCellModel alloc] initWithTitle:@"【期权】TSLA期权链列表页面" action:^{
        TigerTradingOptionChainModel *model = [[TigerTradingOptionChainModel alloc] init];
        model.symbol = @"TSLA";
        model.market = @"US";
        model.optionSymbol = @"TSLA";
        model.hiddenNavBar = YES;
        model.isIndex = NO;
        
        NSMutableString *str = [NSMutableString string];
        [str appendFormat:@"期权链参数"];
        // 拼接每个属性到字符串中
        [str appendFormat:@"symbol: %@\n", model.symbol];
        [str appendFormat:@"market: %@\n", model.market];
        [str appendFormat:@"optionSymbol: %@\n", model.optionSymbol];
        [str appendFormat:@"hiddenNavBar: %d\n", model.hiddenNavBar];
        [str appendFormat:@"isIndex: %d\n", model.isIndex];
        
        // 如果需要分隔符，可以在这里添加
        [str appendString:@"\n------------------------\n"];
        
        [MBProgressHUD showHint:str hide:3];
        
        UIViewController *vc = [TigerTradingQuoteManager optionChainViewController:model fromViewController:self];
        vc.modalPresentationStyle = UIModalPresentationPageSheet;
        [self presentViewController:vc animated:YES completion:nil];
    }];
    
    TBCellModel *optionListTSLAChainModel = [[TBCellModel alloc] initWithTitle:@"【期权】sub TSLA期权链列表页面" action:^{
        TBOptionChainPageViewController *vc = [[TBOptionChainPageViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        [self presentViewController:nav animated:YES completion:nil];
    }];
    
    TBCellModel *openChainSettingcModel = [[TBCellModel alloc] initWithTitle:@"【期权】期权链设置页面" action:^{
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"跳转期权链设置页面"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"列表样式跳转"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingQuoteManager setOptionChainDisplayType:TigerTradingSDKOptionChainDisplayTypeList];
            [TigerTradingQuoteManager openOptionChainSettingPageFromViewController:self];
            
        }];
        
        UIAlertAction *confirmTAction = [UIAlertAction actionWithTitle:@"T样式跳转"
                                                                 style:UIAlertActionStyleDefault
                                                               handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingQuoteManager setOptionChainDisplayType:TigerTradingSDKOptionChainDisplayTypeTypeT];
            [TigerTradingQuoteManager openOptionChainSettingPageFromViewController:self];
            
        }];
        
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
        }];
        
        [alertController addAction:confirmAction];
        [alertController addAction:confirmTAction];
        [alertController addAction:cancelAction];
        [[TBSupportUtility getTopVC]  presentViewController:alertController animated:YES completion:nil];
        
    }];
    
    TBCellModel *optModel = [[TBCellModel alloc] initWithTitle:@"【期权】跳转期权频道页" action:^{
        [TigerTradingQuoteManager openoptionPageControllerFromViewController:self];
    }];
    
    TBCellModel *subOPTModel = [[TBCellModel alloc] initWithTitle:@"【期权】sub期权频道页" action:^{
        TBOptionPageViewController *vc = [[TBOptionPageViewController alloc] init];
        vc.modalPresentationStyle = UIModalPresentationPageSheet;
        [[TBSupportUtility getTopVC] presentViewController:vc animated:YES completion:nil];
    }];
    
    TBCellModel *optionDetailTSLAModel = [[TBCellModel alloc] initWithTitle:@"【期权】TSLA期权详情页" action:^{
        [TigerTradingQuoteManager openOptionDetailPageWithSymbol:@"TSLA" right:@"PUT" strike:@"475.0" expiry:@(1768539600000) market:@"US" fromViewController:self];
    }];
    
    TBCellModel *optionDetailModuleModel = [[TBCellModel alloc] initWithTitle:@"【期权】详情页模块化" action:^{
        TBOptionDetailViewController *vc = [[TBOptionDetailViewController alloc] init];
        vc.optionSymbol = @"TSLA 20260116 475.0 PUT";
        [self presentViewController:vc animated:YES completion:nil];
    }];
    
    TBCellModel *optionPlaceOrderModel = [[TBCellModel alloc] initWithTitle:@"【期权】单腿期权下单" action:^{
        TBTigerTradingOrderBasicInfoModel *infoModel = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:@"US" secType:@"OPT" symbol:@"AAPL 20260116 220.0 CALL"];
        [TigerTradingTradeManager openPlaceOrderPageWithPreCheck:infoModel action:@"CLOSE" fromViewController:self];
    }];
    
    TBCellModel *openCombineOption = [[TBCellModel alloc] initWithTitle:@"【组合期权】详情页" action:^{
        NSArray *legsInfoArr = @[@{@"strike": @"270.0", @"symbol": @"AAPL", @"expiry": @"20261218", @"size": @1, @"direction": @"sell", @"right": @"put"},
                                 @{@"strike": @"275.0", @"symbol": @"AAPL", @"expiry": @"20261218", @"size": @1, @"direction": @"buy", @"right": @"put"}];
        [TigerTradingQuoteManager openCombinationOptionDetailPageWithLegs:legsInfoArr fromViewController:self];
    }];
    
    TBCellModel *combineOptionDetailModuleModel = [[TBCellModel alloc] initWithTitle:@"【组合期权】详情页模块化" action:^{
        NSArray *legsInfoArr = @[@{@"strike": @"270.0", @"symbol": @"AAPL", @"expiry": @"20261218", @"size": @1, @"direction": @"sell", @"right": @"put"},
                                 @{@"strike": @"275.0", @"symbol": @"AAPL", @"expiry": @"20261218", @"size": @1, @"direction": @"buy", @"right": @"put"}];
        TBOptionDetailViewController *detailVC = [[TBOptionDetailViewController alloc] init];
        detailVC.isCombine = YES;
        detailVC.legsInfoArr = legsInfoArr;
        [self presentViewController:detailVC animated:YES completion:nil];
    }];
    
    TBCellModel *combineOptionPlaceOrderModuleModel = [[TBCellModel alloc] initWithTitle:@"【组合期权】下单页面" action:^{
        //        AAPL 20250815 222.5 C S 1|AAPL 20250815 227.5 C B 1
        TBTigerTradingOrderBasicInfoModel *legModel1 = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:MARKET_US secType:SEC_TYPE_OPT symbol:@"AAPL 20261218 270.0 PUT" action:@"SELL" ratio:@1];
        TBTigerTradingOrderBasicInfoModel *legModel2 = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:MARKET_US secType:SEC_TYPE_OPT symbol:@"AAPL 20261218 275.0 PUT" action:@"BUY" ratio:@1];
        [TigerTradingTradeManager openMLegsPlaceOrderPageWithPreCheck:TBOptionCombinationStrategyTypeIronButterfly mLegs:@[legModel1, legModel2] fromViewController:self];
    }];
    
    TBCellModel *combineOptionPositionAddModuleModel = [[TBCellModel alloc] initWithTitle:@"【组合期权】持仓加仓" action:^{
        //        AAPL 20250815 222.5 C S 1|AAPL 20250815 227.5 C B 1
        TBTigerTradingOrderBasicInfoModel *legModel1 = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:MARKET_US secType:SEC_TYPE_OPT symbol:@"AAPL 20261218 270.0 PUT" action:@"SELL" ratio:@1];
        TBTigerTradingOrderBasicInfoModel *legModel2 = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:MARKET_US secType:SEC_TYPE_OPT symbol:@"AAPL 20261218 275.0 PUT" action:@"BUY" ratio:@1];
        
        [TigerTradingTradeManager addMLegsPosition:@[legModel1, legModel2] fromViewController:self];
    }];
    
    TBCellModel *combineOptionPositionCloseModuleModel = [[TBCellModel alloc] initWithTitle:@"【组合期权】持仓平仓" action:^{
        //        AAPL 20250815 222.5 C S 1|AAPL 20250815 227.5 C B 1
        TBTigerTradingOrderBasicInfoModel *legModel1 = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:MARKET_US secType:SEC_TYPE_OPT symbol:@"AAPL 20261218 270.0 PUT" action:@"SELL" ratio:@1];
        TBTigerTradingOrderBasicInfoModel *legModel2 = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:MARKET_US secType:SEC_TYPE_OPT symbol:@"AAPL 20261218 275.0 PUT" action:@"BUY" ratio:@1];
        
        [TigerTradingTradeManager closeMLegsPosition:@[legModel1, legModel2] fromViewController:self];
    }];
    
    TBCellModel *exchangeModel = [[TBCellModel alloc] initWithTitle:@"跳转换汇频道页" action:^{
        [TigerTradingQuoteManager openExchangeControllerFromViewController:self];
    }];
    
    TBCellModel *moduleModel = [[TBCellModel alloc] initWithTitle:@"模块化" action:^{
        TBModuleViewController *vc = [[TBModuleViewController alloc] init];
        [self presentViewController:vc animated:YES completion:nil];
        
    }];
    
    TBCellModel *thumbNailModel = [[TBCellModel alloc] initWithTitle:@"获取缩略图" action:^{
        TigerTradingWatchListThumbNailModel *optThumbNailModel = [[TigerTradingWatchListThumbNailModel alloc] init];
        optThumbNailModel.symbol = @"AMZN";
        optThumbNailModel.market = @"US";
        optThumbNailModel.secType = @"STK";
        
        TigerTradingWatchListThumbNailModel *sktThumbNailModel = [[TigerTradingWatchListThumbNailModel alloc] init];
        sktThumbNailModel.symbol = @"AMZN 20241227 225.0 PUT";
        sktThumbNailModel.market = @"US";
        sktThumbNailModel.secType = @"OPT";
        [TigerTradingQuoteManager fetchWatchlistThumbnail:@[optThumbNailModel,sktThumbNailModel] successed:^(id responseObject) {
            NSError *error;
            NSData *jsonData = [NSJSONSerialization dataWithJSONObject:responseObject options:NSJSONWritingPrettyPrinted error:&error];
            NSString *dictionaryString;
            if (!error) {
                dictionaryString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            }
            else {
                dictionaryString = @"无法解析字典";
            }
            
            // 创建一个 UIAlertController
            UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"缩略图"
                                                                                     message:dictionaryString
                                                                              preferredStyle:UIAlertControllerStyleAlert];
            
            // 添加确认按钮
            UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                    style:UIAlertActionStyleDefault
                                                                  handler:^(UIAlertAction * _Nonnull action) {
                // 确认按钮点击事件
                NSLog(@"用户点击了确认");
            }];
            [alertController addAction:confirmAction];
            // 显示弹窗
            [self presentViewController:alertController animated:YES completion:nil];
            
        } failed:nil];
    }];
    
    TBCellModel *labelModel = [[TBCellModel alloc] initWithTitle:@"获取自选标签" action:^{
        TigerTradingWatchListThumbNailModel *optThumbNailModel = [[TigerTradingWatchListThumbNailModel alloc] init];
        optThumbNailModel.symbol = @"NVDA";
        optThumbNailModel.market = @"US";
        optThumbNailModel.secType = @"STK";
        
        TigerTradingWatchListThumbNailModel *sktThumbNailModel = [[TigerTradingWatchListThumbNailModel alloc] init];
        sktThumbNailModel.symbol = @"NVDA 20250926 175.0 PUT";
        sktThumbNailModel.market = @"US";
        sktThumbNailModel.secType = @"OPT";
        
        TigerTradingWatchListThumbNailModel *sktThumbNailMode2 = [[TigerTradingWatchListThumbNailModel alloc] init];
        sktThumbNailMode2.symbol = @"AAPL";
        sktThumbNailMode2.market = @"US";
        sktThumbNailMode2.secType = @"STK";
        
        [TigerTradingQuoteManager fetchWatchlistLabel:@[optThumbNailModel, sktThumbNailModel, sktThumbNailMode2] successed:^(id responseObject) {
            
            // 创建一个 UIAlertController
            UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"标签信息"
                                                                                     message:[NSString stringWithFormat:@"%@", responseObject]
                                                                              preferredStyle:UIAlertControllerStyleAlert];
            
            // 添加确认按钮
            UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                    style:UIAlertActionStyleDefault
                                                                  handler:^(UIAlertAction * _Nonnull action) {
                // 确认按钮点击事件
                NSLog(@"用户点击了确认");
            }];
            [alertController addAction:confirmAction];
            [self presentViewController:alertController animated:YES completion:nil];
            
        } failed:nil];
    }];
    
    TBCellModel *optionExerciseModel = [[TBCellModel alloc] initWithTitle:@"跳转期权行权" action:^{
        [TigerTradingQuoteManager openOptionExercisePage:self];
    }];

    TBCellModel *optionScreenerModel = [[TBCellModel alloc] initWithTitle:@"【期权】期权筛选器" action:^{
        [TigerTradingQuoteManager openOptionScreenerPage:self];
    }];
    
    TBCellModel *positionTabModel = [[TBCellModel alloc] initWithTitle:@"持仓" action:^{
        UIViewController *vc = [[TBPositionTabViewController alloc] init];
        vc.modalPresentationStyle = UIModalPresentationPageSheet;
        [self presentViewController:vc animated:YES completion:nil];
    }];
    
    TBCellModel *orderDetailModel = [[TBCellModel alloc] initWithTitle:@"订单详情页" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"跳转订单详情页"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        // 添加输入框
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入订单 id";
        }];
        // 添加确认按钮
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            UITextField *textField = alertController.textFields.firstObject;
            if (textField.text.length > 0) {
                [TigerTradingTradeManager openOrderDetailPage:textField.text fromViewController:self];
            }
        }];
        // 添加取消按钮
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:nil];
        
        // 显示 alert
        [alertController addAction:confirmAction];
        [alertController addAction:cancelAction];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *modifyOrderModel = [[TBCellModel alloc] initWithTitle:@"改单页面" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"跳转改单页面"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        // 添加输入框
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入订单 id";
        }];
        // 添加确认按钮
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            UITextField *textField = alertController.textFields.firstObject;
            if (textField.text.length > 0) {
                [TigerTradingTradeManager openModifyOrderPage:textField.text fromViewController:self];
            }
        }];
        // 添加取消按钮
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:nil];
        
        // 显示 alert
        [alertController addAction:confirmAction];
        [alertController addAction:cancelAction];
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *stockPlaceOrderModel = [[TBCellModel alloc] initWithTitle:@"跳转个股下单" action:^{
        TBTigerTradingOrderBasicInfoModel *infoModel = [TBTigerTradingOrderBasicInfoModel orderModelWithMarket:@"US" secType:@"STK" symbol:@"AAPL"];
        [TigerTradingTradeManager openPlaceOrderPageWithPreCheck:infoModel action:@"BUY" fromViewController:self];
    }];
    
    
    TBCellModel *questionnaireModel = [[TBCellModel alloc] initWithTitle:@"跳转认证页面" action:^{
        [TigerTradingQuoteManager openMarketSubscriptionQuestionnairePageFromViewController:self];
    }];
    
    TBCellModel *corporateActionsModel = [[TBCellModel alloc] initWithTitle:@"打开公司行动页面" action:^{
        [TigerTradingQuoteManager openCorporateActionsPageFromViewController:self];
    }];
    
    TBCellModel *orderModel = [[TBCellModel alloc] initWithTitle:@"订单列表模块" action:^{
        TBOrderModuleVC *orderVC = [[TBOrderModuleVC alloc] init];
        [self.navigationController pushViewController:orderVC animated:YES];
    }];
    
#if !TB_PUBLIC_EXAMPLE && __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
    TBCellModel *switchModel = [self internalSwitchAccountDebugMenuItem];
#endif

    TBCellModel *marketModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@跳转行情市场页", [self fetch23Title:NO]] action:^{
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"跳转的市场"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            // 处理取消逻辑
            NSLog(@"选择了取消");
        }];
        UIAlertAction *usConfirmAction = [UIAlertAction actionWithTitle:@"US"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingQuoteManager openQuotePageViewControllerWithMarket:TigerTradingMarketUS fromViewController:self];
        }];
        UIAlertAction *hkConfirmAction = [UIAlertAction actionWithTitle:@"HK"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingQuoteManager openQuotePageViewControllerWithMarket:TigerTradingMarketHK fromViewController:self];
        }];
        UIAlertAction *sgConfirmAction = [UIAlertAction actionWithTitle:@"SG"
                                                                  style:UIAlertActionStyleDefault
                                                                handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingQuoteManager openQuotePageViewControllerWithMarket:TigerTradingMarketSG fromViewController:self];
        }];
        [alertController addAction:cancelAction];
        [alertController addAction:usConfirmAction];
        [alertController addAction:hkConfirmAction];
        [alertController addAction:sgConfirmAction];
        [self presentViewController:alertController animated:YES completion:nil];
    }];

    TBCellModel *futuresMarketModel = [[TBCellModel alloc] initWithTitle:@"跳转期货市场页" action:^{
        [TigerTradingQuoteManager openFuturesMarketPageFromViewController:self];
    }];

#if TTSDK_TEST
    self.jumpVCDataSourceTitles = @[@"通用", @"期权", @"23"];
    self.jumpVCDataSource = @{
        @"通用": @[
#if !TB_PUBLIC_EXAMPLE
            webModel, // 内部 Web 调试
#endif
            fundingDetailModel, // 跳转资金明细
            //        tradeSecuritiesModel, // 持仓页面
            netModel,
            searchModel,     // 搜索页面
            orderlListModel, //订单列表
            detailModel, // apple 详情页
            futuresMarketModel, // 跳转期货市场页
            exchangeModel, // 换汇
            moduleModel, // 模块化
            thumbNailModel, // 获取缩略图
            labelModel, // 获取标签
            
            positionTabModel, // 跳转持仓tab
            orderDetailModel, // 跳转订单详情页
            modifyOrderModel, // 跳转改单页面
            stockPlaceOrderModel, // 跳转下单页面
            
            questionnaireModel, //账户认证 web
            corporateActionsModel, // 公司行动 web
            orderModel,
    #if !TB_PUBLIC_EXAMPLE && __has_include(<TigerTradingSDK/TigerQuoteDebugMananger.h>)
            switchModel, // 账户切换
    #endif
        ],
        @"期权": @[
            optionTSLAChainModel, // TSLA期权链
            optionListTSLAChainModel, // 期权链列表页面
            openChainSettingcModel, // 期权链设置页面
            optModel, // 期权频道页
            subOPTModel, // sub期权频道页
            optionDetailTSLAModel, // TSLA 期权详情页
            optionDetailModuleModel, // 跳转期权详情模块化
            optionPlaceOrderModel, // 跳转单腿期权下单页
            openCombineOption, //组合期权页
            combineOptionDetailModuleModel,// 组合期权详情页，模块化
            combineOptionPlaceOrderModuleModel, // 组合期权，下单页
            combineOptionPositionAddModuleModel,  // 组合期权，持仓加仓
            combineOptionPositionCloseModuleModel, // 组合期权，持仓平仓
            optionExerciseModel, // 跳转期权行权
            optionScreenerModel, // 期权筛选器
            //        mLegOptionPlaceOrderModel, // 跳转组合期权下单页
        ],
        @"23": @[
            subOrderModel, // 订单嵌套页面
            detail23Model, // apple 详情页（23样式）
            subConditionOrderModel, // 条件订单嵌套页面
            assetsDetailModel, // 资产详情页
            subtradeSecuritiesModel, // 嵌套持仓详情页
            subUserAccountPageModel, // 嵌套资产详情页
            usMarketIndicesModel, // usa market 指数页面
            marketModel, // 跳转行情市场页
            subMarketModel, // 跳转市场行情页
            subMoreVCModel, // sub 跳转more 页面
        ]
    };
#else
    self.jumpVCDataSourceTitles = @[@"通用"];
    self.jumpVCDataSource = @{
        @"通用": @[
        detailModel, // apple 详情页
        marketModel, // 跳转行情市场页
        futuresMarketModel, // 跳转期货市场页
        searchModel,     // 搜索页面
        orderlListModel, //订单列表
        ]
    };
#endif
}

@end
