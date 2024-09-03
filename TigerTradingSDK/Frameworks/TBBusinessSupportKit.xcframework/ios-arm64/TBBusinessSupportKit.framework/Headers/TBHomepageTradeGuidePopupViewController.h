//
//  TBHomepageTradeGuidePopupViewController.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/7.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBToolsKIT/TBStreamPublicPopupModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomepageTradeGuidePopupViewController : TBListTableViewController

/*
 首页弹窗与个股页区别：
 首页弹窗点击任务按钮，展示股票列表，点击股票，跳转个股页直接开始引导流程；
 个股页点击任务按钮，开始引导流程。
 */

// 首页交易引导弹窗
+ (void)showHomePagePopupForNewUserPlaceorderWithData:(TBStreamPublicPopupMaterialModel *)data;

// 个股页交易引导弹窗
+ (void)showStockDetailPopupForNewUserPlaceorderWithData:(TBStreamPublicPopupMaterialModel *)data symbol:(NSString *)symbol;

@end

NS_ASSUME_NONNULL_END
