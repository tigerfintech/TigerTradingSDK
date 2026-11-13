//
//  TBViewController+TBTradeManagerDelegate.m
//  TigerQuoteSDK
//

#import "TBViewController+TBTradeManagerDelegate.h"
#import "TBExampleConfig.h"
#if !TB_PUBLIC_EXAMPLE
#import "TBInternalExampleConfig.h"
#endif
#import "TB23SDKPlaceOrderCustomAccountDataViewController.h"
#import "TBDemoQuoteTabViewController.h"

#import <TBBaseKit/TBServiceManager+TBPerformanceService.h>
#import <TBToolsKit/TBSupportUtility.h>
#import <TBUIKit/MBProgressHUD+Wrapper.h>

@implementation TBViewController (TBTradeManagerDelegate)

#pragma mark - TigerTradingTradeDelegate

// Legacy/demo callback retained for compatibility with earlier SDK integrations.
- (void)openMarketDataStoreFromViewController:(UIViewController *)fromVC {
    [MBProgressHUD showHint:@"跳转 SDK 行情购买页面" hide:3];
}

- (BOOL)disableHomePageAssetPolling {
    return YES;
}

- (BOOL)disableHomePagePositionPolling {
    return YES;
}

- (NSString *)getCustomString:(TTSDKStringCustomType)type {
    if (type == TTSDKStringCustomTypeTotalAssetTips) {
        return @"表示首页资产卡片说明文案";
    } else {
        return @"未知来源";
    }
}

- (BOOL)displayOptionLapse {
    return self.needDisplayOptionLapse;
}

- (BOOL)displayEarlyExercise {
    return self.needDisplayEarlyExercise;
}

- (void)assetModuleDetailAction {
    [MBProgressHUD showHint:@"业务自己执行跳转逻辑" hide:3];
}

- (void)checkIPOApplyEntryQualificationWithSymbol:(NSString *)symbol
                                           market:(NSString *)market
                                       completion:(void (^)(BOOL))completion {
    NSString *message = [NSString stringWithFormat:@"symbol: %@\nmarket: %@\n\n宿主 App 在此完成协议/声明签署和 Broker API 上传后,回调 completion 决定是否继续 SDK 内的申购流程。", symbol ?: @"", market ?: @""];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"IPO 申购资格预检"
                                                                             message:message
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                           style:UIAlertActionStyleCancel
                                                         handler:^(UIAlertAction * _Nonnull action) {
        if (completion) {
            completion(NO);
        }
    }];
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"完成"
                                                            style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * _Nonnull action) {
        if (completion) {
            completion(YES);
        }
    }];
    [alertController addAction:cancelAction];
    [alertController addAction:confirmAction];
    [[TBSupportUtility getTopVC] presentViewController:alertController animated:YES completion:nil];
}

- (void)uploadIPOUserProfileWithMarket:(NSString *)market
                                symbol:(NSString *)symbol
                            completion:(void (^)(BOOL))completion {
    NSString *message = [NSString stringWithFormat:@"market: %@\nsymbol: %@\n\n宿主 App 在此调用 Broker API 上传用户身份证件,完成后 completion(YES) 触发 SDK 重试本次 IPO 申购提交。", market ?: @"", symbol ?: @""];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"IPO 身份证件上传"
                                                                             message:message
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                           style:UIAlertActionStyleCancel
                                                         handler:^(UIAlertAction * _Nonnull action) {
        if (completion) {
            completion(NO);
        }
    }];
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"上传成功"
                                                            style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * _Nonnull action) {
        if (completion) {
            completion(YES);
        }
    }];
    [alertController addAction:cancelAction];
    [alertController addAction:confirmAction];
    [[TBSupportUtility getTopVC] presentViewController:alertController animated:YES completion:nil];
}

//- (void)deposit {
//    [MBProgressHUD showHint:@"业务自己执行入金逻辑" hide:3];
//}

- (BOOL)updateTradePemissionAlertAction:(UIViewController *)viewcontroller
                             permission:(NSString *)permission
                             completion:(void (^ _Nullable)(BOOL))completion {
    NSString *permissionMessage = [NSString stringWithFormat:@"缺少了%@权限", permission];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"客户自定义开通权限"
                                                                             message:permissionMessage
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:[UIAlertAction actionWithTitle:@"继续提交"
                                                            style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * _Nonnull action) {
        if (completion) {
            completion(YES);
        }
    }]];
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确定"
                                                            style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * _Nonnull action) {
        if (completion) {
            completion(NO);
        }
    }];
    [alertController addAction:confirmAction];
    [viewcontroller presentViewController:alertController animated:YES completion:nil];

    return YES;
}

- (void)requestTradePassword:(UIViewController *)viewcontroller tradeInfo:(NSDictionary *)tradeInfo orderInfo:(NSDictionary *)orderInfo completion:(void (^)(NSDictionary *info))completion {
    TBExampleConfig *exampleConfig = [[TBExampleConfig alloc] init];
#if !TB_PUBLIC_EXAMPLE
    exampleConfig = [[TBInternalExampleConfig alloc] init];
#endif
    NSString *defaultAuthorization = [exampleConfig defaultTradeAuthorization];


//    if ([TBAppManager is23SDK]) {
//        // 23 没有鉴权 直接tradeAuthorization 不赋值
//        if (completion) {
//            completion(@{@"isSucc": @(YES), @"message": @"交易密码正确"});
//        }
//        return;
//    }

    if (self.isTradeLongTermEffective && defaultAuthorization.length > 0) {
        if (completion) {
            NSString *str = defaultAuthorization;
            completion(@{@"tradeAuthorization": str, @"isSucc": @(YES), @"message": @"交易密码正确"});
        }
        return;
    }

    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"请输入交易密码"
                                                                             message:[tradeInfo description]
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"请输入交易密码";
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消"
                                                           style:UIAlertActionStyleCancel
                                                         handler:^(UIAlertAction * _Nonnull action) {
        // 处理取消逻辑
        TBLogCode(@"选择了取消");
        if (completion) {
            completion(@{@"isSucc": @(NO), @"message": @"用户取消输入交易密码"});
        }
    }];
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"确定"
                                                            style:UIAlertActionStyleDefault
                                                          handler:^(UIAlertAction * _Nonnull action) {
        UITextField *textField = alertController.textFields.firstObject;
        if (textField.text.length == 0) {
            completion(@{@"isSucc": @(NO), @"message": @"用户输入交易密码长度为0"});
            return;
        }
        if (completion) {
            NSString *str = [exampleConfig tradeAuthorizationForInput:textField.text];
            completion(@{@"tradeAuthorization": str, @"isSucc": @(YES), @"message": @"交易密码正确"});
        }
    }];
    [alertController addAction:cancelAction];
    [alertController addAction:confirmAction];
    [viewcontroller presentViewController:alertController animated:YES completion:nil];
}

- (void)didClickTradeButton:(TigerTradingTradeButtonActionModel *)tradeModel success:(void (^)(BOOL))success failure:(void (^)(NSError * _Nonnull))failure {

    [MBProgressHUD showLoading:YES hintString:@"客户业务逻辑（1s）"];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [MBProgressHUD showLoading:NO];

        NSMutableString *str = [NSMutableString string];
        [str appendFormat:@"下单相关信息\n"];
        // 拼接每个属性到字符串中

        if (tradeModel.tradeType == 0) {
            [str appendFormat:@"交易类型: 买"];
        }
        else if (tradeModel.tradeType == 1) {
            [str appendFormat:@"交易类型: 卖"];
        }
        else if (tradeModel.tradeType == 2) {
            [str appendFormat:@"交易类型: 平"];
        }
        [str appendFormat:@"\n"];

        [str appendFormat:@"symbol: %@\n", tradeModel.symbol];
        [str appendFormat:@"market: %@\n", tradeModel.market];
        [str appendFormat:@"secType: %@\n", tradeModel.secType];
        [str appendFormat:@"isETF: %d\n", tradeModel.isETF];

        UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"客户实现下单逻辑"
                                                                                 message:[str copy]
                                                                          preferredStyle:UIAlertControllerStyleActionSheet];
        UIAlertAction *sureAction = [UIAlertAction actionWithTitle:@"校验成功"
                                                             style:UIAlertActionStyleDefault
                                                           handler:^(UIAlertAction * _Nonnull action) {
            if (success) {
                success(YES);
            }
        }];
        UIAlertAction *failureAction = [UIAlertAction actionWithTitle:@"校验失败"
                                                                style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * _Nonnull action) {
            if (failure) {
                failure(nil);
            }
        }];

        UIAlertAction *failureGOTOMarketAction = [UIAlertAction actionWithTitle:@"失败(无导航栏自定义复杂市场页面)"
                                                                          style:UIAlertActionStyleDefault
                                                                        handler:^(UIAlertAction * _Nonnull action) {
            if (failure) {
                failure(nil);
            }

            TBDemoQuoteTabViewController *vc = [[TBDemoQuoteTabViewController alloc] init];
            vc.modalPresentationStyle = UIModalPresentationFullScreen;
            [[TBSupportUtility getTopVC] presentViewController:vc animated:YES completion:nil];
        }];

        UIAlertAction *failureGOTONAVMarketAction = [UIAlertAction actionWithTitle:@"失败(有导航栏自定义复杂市场页面)"
                                                                             style:UIAlertActionStyleDefault
                                                                           handler:^(UIAlertAction * _Nonnull action) {
            if (failure) {
                failure(nil);
            }

            TBDemoQuoteTabViewController *vc = [[TBDemoQuoteTabViewController alloc] init];
            UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
            nav.modalPresentationStyle = UIModalPresentationFullScreen;
            [[TBSupportUtility getTopVC] presentViewController:nav animated:YES completion:nil];

            // 创建自定义返回按钮
            UIBarButtonItem *backButton = [[UIBarButtonItem alloc] initWithTitle:@"返回"
                                                                           style:UIBarButtonItemStylePlain
                                                                          target:self
                                                                          action:@selector(dismissQuoteTabViewController)];

            // 设置返回按钮到导航栏
            vc.navigationItem.leftBarButtonItem = backButton;
        }];

        [alertController addAction:sureAction];
        [alertController addAction:failureAction];
        [alertController addAction:failureGOTOMarketAction];
        [alertController addAction:failureGOTONAVMarketAction];

        [[TBSupportUtility getTopVC] presentViewController:alertController animated:YES completion:nil];
    });
}

- (void)deposit {
    [MBProgressHUD showHint:@"用户自定义入金业务 deposit" hide:1.5];
}

- (BOOL)onOpenDepositPage {
    [MBProgressHUD showHint:@"用户自定义入金业务 onOpenDepositPage" hide:1.5];
    return NO;
}

- (void)onOpenDepositPage:(NSString *)segType {
    NSString *tipString = [NSString stringWithFormat:@"用户自定义入金业务 segType: %@", segType];
    [MBProgressHUD showHint:tipString hide:1.5];
    return;
}

- (UIViewController *)customViewControllerForPlaceOrderAccountDataViewController:(UIViewController *)placeOrderAccountDataViewController subVCScrollEnabled:(BOOL)scrollEnabled updateContentHeightBlock:(void(^)(CGFloat contentHeight))updateContentHeightBlock {
    TB23SDKPlaceOrderCustomAccountDataViewController *vc = [[TB23SDKPlaceOrderCustomAccountDataViewController alloc] init];
    vc.placeOrderAccountDataViewController = placeOrderAccountDataViewController;
    vc.updateContentHeightBlock = updateContentHeightBlock;
    vc.subVCTableViewScrollDisabled = scrollEnabled;
    return vc;
}

- (void)customViewControllerForPlaceOrderAccountDataViewControllerAfterReloadAction {
    TBLogCode(@"customViewControllerForPlaceOrderAccountDataViewControllerAfterReloadAction");
}

- (CGFloat)placeOrderCustomViewControllerContentHeight:(UIViewController *)customViewController {
    if (![customViewController isKindOfClass:[TB23SDKPlaceOrderCustomAccountDataViewController class]]) {
        return 0;
    }

    TB23SDKPlaceOrderCustomAccountDataViewController *sdkPlaceOrderDataVC = (TB23SDKPlaceOrderCustomAccountDataViewController *)customViewController;
    return [sdkPlaceOrderDataVC contentHeight];
}

//- (void)modifyOrder:(NSString *)orderId callback:(void(^)(BOOL proceed))callback {
//    [MBProgressHUD showHint:[NSString stringWithFormat:@"用户自定义跳转改单页面，订单id：%@", orderId] hide:1.5];
//    if (callback) {
//        callback(NO);
//    }
//}

//- (void)cancelOrder:(NSString *)orderId callback:(void(^)(BOOL proceed))callback {
//    [MBProgressHUD showHint:[NSString stringWithFormat:@"用户自定义取消订单逻辑，订单id：%@", orderId] hide:1.5];
//    if (callback) {
//        callback(NO);
//    }
//}

// 返回按钮的点击事件方法
- (void)dismissQuoteTabViewController {
    // Dismiss 当前视图控制器
    [[TBSupportUtility getTopVC] dismissViewControllerAnimated:YES completion:nil];
}

@end
