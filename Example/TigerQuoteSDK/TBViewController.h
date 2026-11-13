//
//  TBViewController.h
//  TigerQuoteSDK
//
//  Created by linbingjie on 08/08/2024.
//  Copyright (c) 2024 linbingjie. All rights reserved.
//

@import UIKit;

#import <TigerTradingSDK/TigerTradingQuoteManager.h>

@class TBCellModel;
@class TBSDKDelegateDebugViewController;

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString * _Nonnull const kTigerTradeLaunchConfig;

@interface TBViewController : UIViewController

@property (nonatomic, copy) NSArray<TBCellModel *> *dataSource;

@property (nonatomic, copy) NSArray<NSString *> *jumpVCDataSourceTitles;
@property (nonatomic, copy) NSDictionary<NSString *, NSArray<TBCellModel *> *> *jumpVCDataSource;

@property (nonatomic, copy) NSArray<NSString *> *functionDataSourceTitles;
@property (nonatomic, copy) NSDictionary<NSString *, NSArray<TBCellModel *> *> *functionDataSource;

@property (nonatomic, copy) NSArray<NSString *> *settingDataSourceTitles;
@property (nonatomic, copy) NSDictionary<NSString *, NSArray<TBCellModel *> *> *settingDataSource;

@property (nonatomic, copy) NSArray<NSString *> *testColorSwitchDataSourceTitles;
@property (nonatomic, copy) NSDictionary<NSString *, NSArray<TBCellModel *> *> *testColorSwitchDataSource;

@property (nonatomic, assign) BOOL isContinueSwitchAccount; // 是否继续执行原有SDK切换账号逻辑

@property (nonatomic, copy) NSString *homepageName; // 定义字符串属性
@property (nonatomic, copy) NSString *strBrandName; // 定义字符串属性

@property (nonatomic, assign) BOOL needDisplayOptionLapse;  // 期权行权页，是否展示放弃行权
@property (nonatomic, assign) BOOL needDisplayEarlyExercise; // 期权行权页，是否展示提前行权


/// 模拟 APP 行情权限，决定下单页买卖盘、深度摆盘的展示范围
/// 读写走 NSUserDefaults，选过之后重启 app 仍生效；没选过默认 Lv2
@property (nonatomic, assign) TigerTradingSDKQuoteType appQuoteType;

@property (nonatomic, assign) BOOL isTradeLongTermEffective;

@property (nonatomic, strong) TBSDKDelegateDebugViewController *delegateDebugVC;

- (void)openLoginVC;

- (void)login:(NSString *)authCode;

- (void)guestLogin;

@end

NS_ASSUME_NONNULL_END
