//
//  TBStockDetailCombinedViewController.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/12/23.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBProductBaseViewController.h"
#import <TBTradeBusinessBaseKit/TBPlaceOrderContactInfoDataSource.h>
#import <TBTradeBusinessBaseKit/TBStockDetailOrderPositionHttpManager.h>
#import <TBUIKit/TBRefreshView.h>
#import <TBStockBusinessBaseKit/TBStockDetailTradeManager.h>
#if __has_include("TBStockDetailOptionChainViewController.h")
#import "TBStockDetailOptionChainViewController.h"
#endif
//#import "TBHKStockDarkDiskQuoteViewController.h"
#import "TBStockDetailBottomTabBarView.h"

@class TBStockDetailBottomTabBar;
//@class TBAStockBarView;
@class TBStockDetailTradeManager;
@class TBRefreshView;
@class LOTAnimationView;
@class TBSegmentedPageViewController;
@class MZFormSheetPresentationViewController;
@class TBStockDetailOrderPositionHttpManager;
@class TBStockDetailQuoteViewController;
@class TBStockDetailEmptyViewController;
@class TBInputConfirmView;
@class TBSelectAndAddConfirmView;
@class TBFutruesCombineModel;
@class TBStockDetailOpenAccountGuideView;
@class TBHKOpenIPOModel;
@class TBPageTraceHelper;
//@class TBUSStockIPOTimeLineQuoteViewController;

#import <TBStockKit/TBStock.h>
#import <TBStockKit/NSString+TBStock.h>



#import <TBStockBusinessBaseKit/TBStockDetailViewControllerDelegate.h>


//#import "TBWatchListGroupManager.h"
//#import "TBGroupStockManagerViewController.h"

#import <TBStockBusinessBaseKit/TBStockInfoDetailModel.h>
#import <TBThirdParty/Lottie.h>
#import <TBUIKit/JXCategoryTitleView.h>
#import <TBThirdParty/JXPagerSmoothView.h>
#import "TBStockDetailHeaderViewController.h"
#import "TBStockDetailTitleView.h"
#import "TBStockDetailFrameViewController.h"

#import "TBStockDetailMarqueeView.h"



/*
 V80 个股页改版vc
 文档/PRD：https://tigertech.feishu.cn/docs/doccnIMYWIGx4kkie7MJnCzOQ78
 设计稿：
 
 */

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailCombinedViewController : TBBaseViewController <TBStockDetailOrderPositionHttpManagerDelegate, TBRefreshViewDelegate, JXPagerSmoothViewDataSource>
/**
 *  股票代码，必须传
 */
@property (nonatomic, copy) NSString * _Nullable symbol;

/**
 *  股票名称，可不传
 */
@property (nonatomic, copy) NSString * _Nullable nameCN;

/**
 *  股票市场，必须传，如果没有传会使用[NSString getStockMarketFromSymbol:_symbol]判断市场
 */
@property (nonatomic, copy) NSString * _Nullable market;

/**
 股票类型。
 期货必传，否则按股票处理。。。。。。
 */
@property (nonatomic, copy) NSString * _Nullable secType;

/// 为行情添加埋点，用于优化股票搜索
@property (nonatomic, copy) NSString * _Nullable sid;
@property (nonatomic, strong) NSNumber * _Nullable searchIndex;



/**
 *  是否为指数：目前根据[TBStock isIndexSymbol:_symbol]进行判断
 * V6.4.8 server跟A股一样加个字段  "symbolType": "index",  有这个字段且值是index就表示指数
 */
@property (nonatomic, assign, getter=isIndex) BOOL index; // 是否为指数

@property (nonatomic, assign, getter=isFirstLoad) BOOL firstLoad; // 是否为第一次加载

@property (nonatomic, assign) BOOL scrollToPositionOrderModule;

/// 是否加入自选
@property (nonatomic, assign) BOOL isWithinWatchList;

@property (nonatomic, assign) BOOL isETF;


@property (nonatomic, strong) TBStockDetailBottomTabBar * _Nullable bottomTabBar;
@property (nonatomic, strong) UIView * _Nullable bottomTabBarBackView;


//@property (nonatomic, strong) TBAStockBarView * _Nullable titleView;
@property (nonatomic, strong) TBStockDetailTitleView *detailTitleView;

@property (nonatomic, strong) id<TBStockDetailViewControllerDelegate> _Nullable delegate;

//@property (nonatomic, assign) BOOL isAHBrief;
@property (nonatomic, copy) NSString * _Nullable fromMarket;

/*
 选中VC的标题:有此参数会根据OC反射机制，查找对应的类，最后定位到对应的tab；
 如：query传pageSelectedTitle=期权，则进入详情页定位在期权tab（如果存在期权）
 @"行情": @"TBStockDetailQuoteViewController",
 @"期权": @"TBStockDetailOptionChainViewController",
 @"资讯": @"TBStockDetailNewsViewController",
 @"新帖":@"TBStockDetailNewPostViewController",
 @"分析":@"TBStockDetailBottomAnalysisViewController",
 @"公司": @"TBStockDetailCompanyViewController",
 */

/*
 子VC的参数，不建议在个股页解析这个参数，可以直接通过遍历赋值给具体业务VC，内部参数由各业务VC定义。在query中的key为subParams
 */
@property (nonatomic, copy) NSDictionary * _Nullable subVCParams;

/// 交易相关
@property (nonatomic, strong) TBStockDetailTradeManager * _Nullable detailTradeManager;
@property (nonatomic, assign) TBTradeType tradeType;

/**
 *  轮询K线数据的定时器
 */
@property (nonatomic, strong) NSTimer * _Nullable refreshTimer;

/// 订单持仓
@property (nonatomic, strong) NSTimer * _Nullable positionOrderTimer;

@property (nonatomic, strong) TBRefreshView * _Nullable refreshView;

@property (nonatomic, strong) TBStockDetailMarqueeView * _Nullable marqueeView;


@property (nonatomic, strong) NSMutableArray * _Nullable positionMArray;
@property (nonatomic, strong) NSMutableArray * _Nullable orderAMarray;
@property (nonatomic, strong) NSMutableArray * _Nullable todayCompleteOrderArray;


@property (nonatomic, strong) LOTAnimationView * _Nullable activityView;
@property (nonatomic, strong) UIButton * _Nullable alertButton;

@property (nonatomic, assign) NSTimeInterval lastUpdateTime;

/**
 个股是否可交易。
 
 目前交易品种不可交易情况：
 1、未注册：详情页中交易按钮灰色，点击后toast提示“需要开户入金后才可交易”
 2、未开户：详情页中交易按钮灰色，点击后toast提示“需要开户入金后才可交易”
 3、开户未入金：详情页中交易按钮灰色，点击后toast提示“需要开户入金后才可交易”
 4、IB账号： A股部分非沪港通、深港通标的
 5、OMNIBUS账号：根据server 返回是否可进行交易进行判断是否可进行交易（TBStockDetailShortMarginModel tradeable字段）
 */
@property (nonatomic, readonly) BOOL tradeable;
@property (nonatomic, assign, readonly) BOOL   defaultTradeAble;

@property (nonatomic, assign, readonly) BOOL contractSupportFractionalShare; // 合约是否支持碎股

@property (nonatomic, assign, readonly) BOOL contractMonetaryOrderSupported; // 是否支持按金额下单

@property (nonatomic, assign, readonly) BOOL isSupportRsp; // 是否支持定投

@property (nonatomic, assign, readonly) BOOL isSupportCdp; // 是否支持CDP

@property (nonatomic, weak)  MZFormSheetPresentationViewController * _Nullable speedOrderPresentVC;

@property (nonatomic, readonly) UIViewController * _Nullable speedModeViewController;

@property (nonatomic, readonly) UIViewController * _Nullable modifyModeViewController;

@property (nonatomic, strong) NSNumber * _Nullable limitPrice;

@property (nonatomic, copy) NSString * _Nullable shortMarginErrorMessage;

//@property (nonatomic, copy) NSString * _Nullable currentBottomIndexSymbol;


//@property (nonatomic, assign) BOOL isSpreadIndex;

@property (nonatomic, assign) BOOL isBarShowPrice;

@property (nonatomic) BOOL isFreshing;

@property (nonatomic, assign) NSInteger currentPageIndex;
@property (nonatomic, copy) NSString *stockTabName; // 适用于gpt跳转的tabName

@property (nonatomic, strong) TBStockDetailOrderPositionHttpManager * _Nullable positionOrderRequest;



//用户界面跳转关系关联，
@property (nonatomic, copy) NSString * _Nullable relationStrForPriceWarning;

@property (nonatomic, strong) TBStockDetailQuoteViewController * _Nullable detailQuoteVC;
#if __has_include("TBStockDetailOptionChainViewController.h")
@property (nonatomic, strong) TBStockDetailOptionChainViewController * _Nullable optionChainVC;
#endif
@property (nonatomic, assign) BOOL optionChainNoData;
//@property (nonatomic, strong) TBStockDetailEmptyViewController * _Nullable emptyQuoteVC;

/// 更多标的
@property (nonatomic, copy) NSArray * _Nullable cellItemsArray;

@property (nonatomic, assign, getter=isShowingMoreVC) BOOL showingMoreVC;

/// 关联了企业号的相关参数
//@property (nonatomic, assign) BOOL hasRelatedCompany;
//@property (nonatomic, assign) BOOL hasRelatedCompanyRed; ///< 外部按钮是否已经展示过红点
//@property (nonatomic, assign) BOOL hasRelatedCompanyButtonRed; ///< 展开项是否已经展示过红点
//@property (nonatomic, assign) BOOL isCompanyVIP; ///< 是否是企业vip
@property (nonatomic, assign) int64_t relatedCompanyUserId;
@property (nonatomic, strong) UIButton * _Nullable redButton;
@property (nonatomic, copy) NSString * _Nullable keyOfRelatedCompany;
@property (nonatomic, copy) NSString * _Nullable keyOfRelatedCompanyButton;

@property (nonatomic, copy) NSString * _Nullable defaultSelectTargetIndexTitle;///< 是否默认展示 tab 标题
@property (nonatomic, copy) NSString * _Nullable defaultSelectTargetSubIndexTitle;///< 二级 tab 标题，现用于 新帖 tab 下的 投票 页
/// 请求股票行情
- (void)fetchStockInfoDetail:(BOOL)isLoop;

//- (void)fetchStockDetailBottomIndexInfo;

/// 新帖tab的小红点相关
@property (strong, nonatomic) UIView * _Nullable redView; // 用于个股新帖小红点的显示

- (void)fetchNewTopPostTime; // 请求最新一条精选帖时间 判断小红点是否隐藏

#pragma mark --- 股票分组管理
@property (nonatomic, strong) TBInputConfirmView          * _Nullable groupCreateConfirmView;
@property (nonatomic, strong) TBSelectAndAddConfirmView   * _Nullable groupOptionsView;
- (void)showCreateGroupView;
- (void)showSelectGroupView;

- (void)fetchStockInfoDetailMarginInfo;

- (void)fetchStockPositionOrder;

@property (nonatomic, strong) TBFutruesCombineModel * _Nullable futuresModel;

- (void)updateBottomTabBar;

/**
 关注企业号的网络请求
 添加自选时 检查该标的是否关联了企业号 如果有 则关注该企业号
 */
- (void)netFocusCompany;

- (void)dissmissSpeedVCCompletion:(void (^ __nullable)(void))completion;

//开户引导

@property (nonatomic, strong) TBStockDetailOpenAccountGuideView * _Nullable openAccountGuideView;

- (void)updateOptionStatus:(NSInteger)index;
- (void)hiddenBottomViewIfNeed;

/// 存储订单支持类型/有效期/保证金等信息
@property (nonatomic, strong) id<TBPlaceOrderContactInfoDataSource> _Nullable contractInfo;
- (void)invalidateRefreshTimer;

- (void)sa_log_stockEventName:(NSString *_Nullable)name ipoEventName:(NSString *_Nullable)ipoName eventParam1:(NSString *_Nullable)param;

- (BOOL)autoRefreshPermission;

/// IPO 模型
@property (nonatomic, strong) TBHKOpenIPOModel * _Nullable openIPOModel;

@property (nonatomic, strong) TBStockDetailFrameViewController *frameVC;
//@property (nonatomic, strong) JXPagerSmoothView *pagerView;
//@property (nonatomic, strong) JXCategoryTitleView *categoryView;



//@property (nonatomic, strong) TBUSStockIPOTimeLineQuoteViewController * usIPOTimeLineVC;

//@property (nonatomic, strong) TBHKStockDarkDiskQuoteViewController * _Nullable darkVC;

@property (nonatomic, strong) TBStockDetailHeaderViewController * _Nullable headerVC;

@property (nonatomic, strong) TBPageTraceHelper *pageTrace;

- (void)resetHeaderVC;
- (void)resetDelegate;

@property (nonatomic, strong, nullable) NSArray<__kindof UIViewController *> *viewControllers;
@property (nonatomic, strong, nullable) NSArray<__kindof UIViewController *> *communityViewControllers;
@property (nonatomic, assign) BOOL hasStarInvestorData;//是否有交易分享数据
- (BOOL)hasOption;

- (void)updateMarqueeViewStatus:(BOOL)limited;

/// 处理bottomBar点击事件方法，目前只用到TBStockBottomBarEventTypeTrade
- (void)handleBottomBarActionWithType:(TBStockBottomBarEventType)type info:(NSString *)info sender:(UIView *)sender;

- (BOOL)isSpecialCondition;

- (void)generateQuoteVC;

- (void)updateFCNTabIfNeed;

- (void)handleStarInvestorTab;

@end

NS_ASSUME_NONNULL_END
