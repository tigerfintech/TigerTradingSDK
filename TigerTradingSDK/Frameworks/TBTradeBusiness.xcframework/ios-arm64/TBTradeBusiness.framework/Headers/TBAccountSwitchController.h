//
//  TBAccountSwitchController.h
//  Stock
//
//  Created by 马超 on 2017/6/27.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBAccountSystemKit/TBTradeAccountManager.h>

@interface TBAccountSwitchController : TBListTableViewController

@property (nonatomic, copy) void (^changeAccountTypeBlock)(TBTradeAccountSwitchResultType type);

+ (void)floatingShow;

/// doubleCheckDisable： 选中账户后是否禁用二次确认
+ (void)floatingShowWithDoubleCheckDisable:(BOOL)doubleCheckDisable;
+ (void)floatingShowWithDoubleCheckDisable:(BOOL)doubleCheckDisable arriveFrom:(NSString *)arriveFrom;

/// 账户切换时，不带虚拟账户信息。（用于IPO列表页，顶部切换账户使用）
+ (void)floatingShowWithoutVirtualAccountWithBlock:(nullable void (^)(TBTradeAccountSwitchResultType))changeAccountTypeBlock;

@end
