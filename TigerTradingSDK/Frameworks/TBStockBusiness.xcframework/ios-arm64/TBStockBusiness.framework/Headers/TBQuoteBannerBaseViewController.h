//
//  TBQuoteBannerBaseViewController.h
//  TBStockBusiness
//
//  Created by dulijun on 2021/10/13.
//
// 该类作为各个market行情vc 的basevc，用来处理是否显示行情顶部的开户引导banner。现在行情vc都继承自该类

#import <TBUIKit/TBListTableViewController.h>
#import "TBStockBusinessMacro.h"
#import <TBToolsKit/TBNSENumConstant.h>
@class TBQuoteOpenAccountGuideBannerView;

#define TBQUOTE_BANNER_HEIGHT 75.0 //行情顶部开户入金引导banner高度

NS_ASSUME_NONNULL_BEGIN

@interface TBQuoteBannerBaseViewController : TBListTableViewController

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *statisticsTypeStr;
@property (nonatomic, assign) BOOL isWatchListVC;//标记当前vc是否是自选（自选的bannerui样式特殊处理）
@property (nonatomic, assign) TBOpenAccountGuideSourceType openAccountGuideSourceType;//开户引导页的触发来源（用于上报埋点）
@property (nonatomic, assign) BOOL isHaveQuoteBanner;//是否有行情顶部开户入金banner（目前提供给子VC watchlist使用）
@property (nonatomic, strong) TBQuoteOpenAccountGuideBannerView *customerTableHeaderView;

//检查是否要隐藏或显示 行情开户引导banner
- (void)updateQuoteOpenAccountGuideBanner;

//关闭的时候更新布局
- (void)relayoutWhenClosed;

@end

NS_ASSUME_NONNULL_END
