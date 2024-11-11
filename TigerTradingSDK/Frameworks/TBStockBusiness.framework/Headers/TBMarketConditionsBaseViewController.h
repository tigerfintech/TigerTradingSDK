//
//  TBMarketConditionsBaseViewController.h
//  Stock
//
//  Created by 王灵博 on 2020/9/1.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBQuoteBannerBaseViewController.h"
@class TBRefreshNormalHeader;
#import <TBUIKit/JXCategoryListContainerView.h>

@interface TBMarketConditionsBaseViewController : TBQuoteBannerBaseViewController

@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, strong) NSMutableDictionary *requestParameters;
@property (nonatomic, strong) NSOperationQueue  *netQueue;
@property (nonatomic, assign) BOOL isShown;
@property (nonatomic, strong) TBRefreshNormalHeader *refreshHeader;
@property (nonatomic, strong) NSTimer               *refreshTimer;

// 名称代码互换处理方法
- (void)handleSymbolChangedAction;

@end
