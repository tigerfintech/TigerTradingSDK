//
//  TBTradeAccountListViewController.h
//  Stock
//
//  Created by 王昌阳 on 2020/8/19.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//  交易Tab-账户列表

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeAccountListViewController : TBListTableViewController

+ (void)showTradeAccountList;

/// 点击账号设置按钮后，浮窗展示账号列表页
+ (void)showTradeAccountListWithFloatingShowAccountSetting;

@end

NS_ASSUME_NONNULL_END
