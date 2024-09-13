//
//  TBOptionLimitAlertViewController.h
//  Stock
//
//  Created by WCP on 2018/11/12.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionLimitAlertViewController : TBListTableViewController

@property (nonatomic, copy) NSDictionary *optionQuery;

@end

NS_ASSUME_NONNULL_END
