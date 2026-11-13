//
//  TBViewController+TBFunctionDataSource.m
//  TigerQuoteSDK
//
//  Created by wind on 2025/12/19.
//

#import "TBViewController+TBFunctionDataSource.h"
#import "TBViewController+TBDataSource.h"
#import "TBCellModel.h"
#if !TB_PUBLIC_EXAMPLE
#import "TBImagePickerComparisonDemoViewController.h"
#endif

#import <TigerTradingSDK/TigerTradingSDKSettingManager.h>
#import <TigerTradingSDK/TigerTradingSDKManager.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>
#import <TigerTradingSDK/TigerTradingPriceFormatter.h>
#import <TigerTradingSDK/TigerTradingTradeManager.h>
#import <TigerTradingSDK/TigerQuoteDebugMananger.h>

@import TBUIKit;
@import TBToolsKit;

@implementation TBViewController (TBFunctionDataSource)

- (void)setupFunctionDataSource {
    TBCellModel *tradeAssetHiddenModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@ 持仓资产小眼睛开关", [self fetch23Title:YES]] action:^{
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:[NSString stringWithFormat:@"持仓小眼睛显示状态:%d", [TigerTradingTradeManager fetchTradeAccountAssetVisible]]
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        [alertController addAction:[UIAlertAction actionWithTitle:@"切换状态？" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingTradeManager updateTradeAccountAssetShowVisibleStatus:![TigerTradingTradeManager fetchTradeAccountAssetVisible]];
        }]];
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
        }];
        [alertController addAction:cancelAction];
        [[TBSupportUtility getTopVC]  presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *tradeTokenRefershModel = [[TBCellModel alloc] initWithTitle:[NSString stringWithFormat:@"%@主动更新tradeAuthorization",[self fetch930Title]] action:^{
        
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"更新tradeAuthorization"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        // 添加输入框
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入需要校验的tradeAuthorization";
        }];
        
        // 添加确认按钮
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            UITextField *textField = alertController.textFields.firstObject;
            if (textField.text.length > 0) {
                [TigerTradingTradeManager refreshTradeAuthorization:textField.text success:^(id  _Nonnull responseObject) {
                    NSString *errorCode = responseObject[@"errorCode"];
                    if ([errorCode isEqualToString:@"SUCCESS"]) {
                        [MBProgressHUD showHint:[NSString stringWithFormat:@"新的tradeAuthorization\n%@",textField.text] hide:2];
                    }
                    
                } failure:^(NSError * _Nonnull error) {
                    [MBProgressHUD showHint:[NSString stringWithFormat:@"error:%@",error.description] hide:2];
                }];
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
    
    TBCellModel *loadHoldingsModel = [[TBCellModel alloc] initWithTitle:@"拉取持仓数据" action:^{
        [TigerTradingTradeManager loadHoldings];
    }];
    
    TBCellModel *hasOption = [[TBCellModel alloc] initWithTitle:@"判断正股标的下是否有期权" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"输入正股 symbol"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        // 添加输入框
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            
        }];
        // 添加确认按钮
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确认"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            UITextField *textField = alertController.textFields.firstObject;
            if (textField.text.length > 0) {
                [TigerTradingQuoteManager checkOptionsForSymbol:@"AAPL" success:^(BOOL hasOptionChain) {
                    [MBProgressHUD showHint:(hasOptionChain ? @"有期权" : @"没有期权") hide:2];
                } failure:^(NSError * _Nonnull error) {
                    [MBProgressHUD showHint:[NSString stringWithFormat:@"请求错误 %@", error] hide:2];
                }];
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
    
    TBCellModel *lastLoadAssetsModel = [[TBCellModel alloc] initWithTitle:@"拉取资金数据" action:^{
        [TigerTradingTradeManager loadAssetsSuccess:^(TigerTradingAssetInfoModel * _Nonnull asset) {
            
        } failure:^(NSInteger ret, NSString * _Nonnull status, NSString * _Nonnull message, NSError * _Nonnull error) {
            
        }];
    }];
    
    TBCellModel *permissionModel = [[TBCellModel alloc] initWithTitle:@"是否是实时行情权限" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"请先登录，然后输入市场和品种"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入市场";
        }];
        [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.placeholder = @"请输入品种";
        }];
        
        UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确定"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            
            UITextField *textField = alertController.textFields.firstObject;
            NSString *market = textField.text;
            UITextField *secTypeTextField = alertController.textFields[1];
            NSString *secType = secTypeTextField.text;
            
            BOOL isRealTime = [TigerTradingQuoteManager isRealtimeQuoteForMarket:market secType:secType];
            NSString *tipString = [NSString stringWithFormat:@"%@实时行情权限", isRealTime ? @"是" : @"不是"];
            [MBProgressHUD showHint:tipString hide:1.5];
        }];
        
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                               style:UIAlertActionStyleCancel
                                                             handler:^(UIAlertAction * _Nonnull action) {
            
        }];
        [alertController addAction:cancelAction];
        [alertController addAction:confirmAction];
        
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
    TBCellModel *positionExpiryModel = [[TBCellModel alloc] initWithTitle:@"期权是否过期" action:^{
        //        BOOL isExpiry = [TigerTradingQuoteManager isOptionExpiryWithSecType:@"OPT" symbol:@"AAPL 20250708 202.5 PUT"];
        BOOL isExpiry = [TigerTradingQuoteManager isOptionExpiryWithSecType:@"MLEG" symbol:@"AAPL 20250814 165.0 C B 1|AAPL 20250813 155.0 C S 10"];
    }];
    
    TBCellModel *logModel = [[TBCellModel alloc] initWithTitle:@"分享日志" action:^{
        [TigerTradingSDKManager shareDebugLogFileSuccess:nil failure:nil];
    }];
    
#if !TB_PUBLIC_EXAMPLE
    TBCellModel *imagePickerDemoModel = [[TBCellModel alloc] initWithTitle:@"图片选择器对比 (UIImagePicker / PHPicker / AJPhotoPicker)" action:^{
        TBImagePickerComparisonDemoViewController *vc = [[TBImagePickerComparisonDemoViewController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
    }];
#endif

    TBCellModel *resetDelegate = [[TBCellModel alloc] initWithTitle:@"设置代理对象" action:^{
        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"设置代理对象"
                                                                                 message:nil
                                                                          preferredStyle:UIAlertControllerStyleAlert];
        
        
        UIAlertAction *delegateAction = [UIAlertAction actionWithTitle:@"删除代理对象"
                                                                 style:UIAlertActionStyleDefault
                                                               handler:^(UIAlertAction * _Nonnull action) {
            
            TigerTradingSDKManager.delegate = nil;
            TigerTradingSDKSettingManager.delegate = nil;
            TigerTradingQuoteManager.delegate = nil;
            TigerTradingTradeManager.delegate = nil;
            
            [MBProgressHUD showHint:@"删除代理对象完成" hide:1.5];
        }];
        
        UIAlertAction *addAction = [UIAlertAction actionWithTitle:@"添加代理对象"
                                                            style:UIAlertActionStyleCancel
                                                          handler:^(UIAlertAction * _Nonnull action) {
            TigerTradingSDKManager.delegate = self;
            TigerTradingSDKSettingManager.delegate = self;
            TigerTradingQuoteManager.delegate = self;
            TigerTradingTradeManager.delegate = self;
            
            [MBProgressHUD showHint:@"添加代理对象完成" hide:1.5];
        }];
        
        [alertController addAction:delegateAction];
        [alertController addAction:addAction];
        
        [self presentViewController:alertController animated:YES completion:nil];
    }];
    
#if TTSDK_TEST
    TBCellModel *priceFormatModel = [[TBCellModel alloc] initWithTitle:@"通用价格格式化对比测试" action:^{
        NSString *symbol = @"ASTS";
        NSArray<NSString *> *symbols = @[symbol];
        NSNumber *samplePrice = @49.825;
        NSString *localRulePrice = [TigerTradingPriceFormatter formatPrice:samplePrice
                                                                    symbol:symbol
                                                                    market:TigerTradingMarketUS
                                                                   secType:@"STK"
                                                                  maxScale:nil];
        NSString *fixedScalePrice = [TigerTradingPriceFormatter formatPrice:@"49.825"
                                                                     symbol:symbol
                                                                     market:TigerTradingMarketUS
                                                                    secType:@"STK"
                                                                   maxScale:@3];

        void (^showReport)(NSString *) = ^(NSString *report) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"[Price format comparison]\n%@", report);
                UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"价格格式化对比"
                                                                               message:report
                                                                        preferredStyle:UIAlertControllerStyleAlert];
                [alert addAction:[UIAlertAction actionWithTitle:@"确定"
                                                         style:UIAlertActionStyleDefault
                                                       handler:nil]];
                [self presentViewController:alert animated:YES completion:nil];
            });
        };

        NSString *directFormatterResult = [NSString stringWithFormat:
                                           @"公开 formatter 固定样例\n"
                                            @"NSNumber 49.825，本地规则：%@ <%@>\n"
                                            @"NSString 49.825，maxScale=3：%@ <%@>",
                                           localRulePrice ?: @"<nil>",
                                           localRulePrice ? NSStringFromClass(localRulePrice.class) : @"nil",
                                           fixedScalePrice ?: @"<nil>",
                                           fixedScalePrice ? NSStringFromClass(fixedScalePrice.class) : @"nil"];

        // 原行情接口未登录时不会执行任何回调，需在创建 dispatch group 前结束本次网络测试。
        if (![TigerTradingSDKManager isUserLoggedIn]) {
            showReport([NSString stringWithFormat:@"%@\n\n请先登录，再测试 ASTS 实时接口。", directFormatterResult]);
            return;
        }

        dispatch_group_t group = dispatch_group_create();
        __block id rawResponse = nil;
        __block id formattedResponse = nil;
        __block NSString *rawFailure = nil;
        __block NSString *formattedFailure = nil;

        dispatch_group_enter(group);
        [TigerTradingQuoteManager fetchContractBriefInfo:symbols successed:^(id object) {
            rawResponse = object;
            dispatch_group_leave(group);
        } failed:^(NSError *error) {
            rawFailure = error.localizedDescription ?: @"failure callback (error=nil)";
            dispatch_group_leave(group);
        }];

        dispatch_group_enter(group);
        [TigerTradingQuoteManager fetchFormattedContractBriefInfo:symbols
                                                        successed:^(NSArray<NSDictionary *> *items) {
            formattedResponse = items;
            dispatch_group_leave(group);
        } failed:^(NSError *error) {
            formattedFailure = error.localizedDescription ?: @"failure callback (error=nil)";
            dispatch_group_leave(group);
        }];

        dispatch_group_notify(group, dispatch_get_main_queue(), ^{
            NSString *(^describeResponse)(id, NSString *) = ^NSString *(id response, NSString *failure) {
                if (failure.length > 0) {
                    return [@"error: " stringByAppendingString:failure];
                }
                if (![response isKindOfClass:NSArray.class]) {
                    return [NSString stringWithFormat:@"response=%@ <%@>",
                            response ?: @"<nil>",
                            response ? NSStringFromClass([response class]) : @"nil"];
                }

                id firstItem = [(NSArray *)response firstObject];
                if (![firstItem isKindOfClass:NSDictionary.class]) {
                    return [NSString stringWithFormat:@"firstItem=%@ <%@>",
                            firstItem ?: @"<nil>",
                            firstItem ? NSStringFromClass([firstItem class]) : @"nil"];
                }

                NSDictionary *item = (NSDictionary *)firstItem;
                NSMutableString *description = [NSMutableString string];
                NSArray<NSString *> *keys = @[@"symbol", @"market", @"secType", @"maxScale",
                                              @"latestPrice", @"preClose"];
                for (NSString *key in keys) {
                    id value = item[key];
                    [description appendFormat:@"%@ = %@ <%@>\n",
                     key,
                     value ?: @"<nil>",
                     value ? NSStringFromClass([value class]) : @"nil"];
                }

                id hourTradingValue = item[@"hourTrading"];
                if ([hourTradingValue isKindOfClass:NSDictionary.class]) {
                    NSDictionary *hourTrading = (NSDictionary *)hourTradingValue;
                    for (NSString *key in @[@"latestPrice", @"preClose"]) {
                        id value = hourTrading[key];
                        [description appendFormat:@"hourTrading.%@ = %@ <%@>\n",
                         key,
                         value ?: @"<nil>",
                         value ? NSStringFromClass([value class]) : @"nil"];
                    }
                } else {
                    [description appendFormat:@"hourTrading = %@ <%@>\n",
                     hourTradingValue ?: @"<nil>",
                     hourTradingValue ? NSStringFromClass([hourTradingValue class]) : @"nil"];
                }
                return description;
            };

            NSString *report = [NSString stringWithFormat:
                                @"%@\n\n"
                                 @"原始 fetchContractBriefInfo\n%@\n"
                                 @"格式化 fetchFormattedContractBriefInfo\n%@",
                                directFormatterResult,
                                describeResponse(rawResponse, rawFailure),
                                describeResponse(formattedResponse, formattedFailure)];
            showReport(report);
        });
    }];

    self.functionDataSourceTitles = @[@"通用"];
    self.functionDataSource = @{
        @"通用": @[
            priceFormatModel, // 通用价格格式化对比（ASTS 样例）
            tradeAssetHiddenModel, // 资产小眼睛开关
            tradeTokenRefershModel, // 主动更新交易token
            loadHoldingsModel,
            hasOption,
            lastLoadAssetsModel,
            permissionModel,
            positionExpiryModel,
            logModel,
#if !TB_PUBLIC_EXAMPLE
            imagePickerDemoModel,
#endif
            resetDelegate]
    };
#endif
}

@end
