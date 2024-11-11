//
//  TBNewOptionChainViewController.h
//  Stock
//
//  Created by liwt on 1/25/16.
//  Copyright © 2016 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
#import <TBStockBusinessBaseKit/TBOptionDatePickerView.h>
#import "TBDoubleRollView.h"

@class TBOptionExpiryItemModel;
@class TBStockDetailCorporationModel;
@class TBOptionChainExpireModel;
@class TBOptionStockModel;
@class TBOptionDatePickerView;
@class TBOptionCallPutChoiceView;
@class TBRefreshNormalHeader;
@class TBStockInfoDetailItemModel;
@class TBOptionChainModel;
@class TBOptionChainBottomView;
@class TBOptionChainShoppingViewController;
@class TBOptionStrategyBuilderStrategyModel;
@class TBMultiOptionChainExpiryModel;
@class TBMultiOptionChainModel;
@class TBMultiOptionChainItemModel;
@class TBMultiOptionExpiryWidthModel;

@import TBUIKit;
#import "TBDoubleRollView.h"
#import <MJRefresh/MJRefresh.h>
#import "TBShoppingFloatingPanelLayout.h"
#import "TBOptionChainBottomView.h"

@protocol TBNewOptionChainViewControllerDelegate <NSObject>

- (void)optionChainDidSelectOption:(NSDictionary *)option;

@end


@interface TBNewOptionChainViewController : TBListTableViewController < TBOptionDatePickerViewDelegate>

@property (nonatomic, copy) NSString *arriveFrom;
@property (nonatomic, assign) CGFloat splitWidth;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *optionSymbol;
@property (nonatomic, copy) NSString *symbolCN;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *right; // 从下单进入期权链, 锁定了 right
@property (nonatomic, copy) NSString *rolloverStrike; //rollover传入的strike
@property (nonatomic, strong) NSNumber *rolloverExpiry; //rollover传入的expiry
@property (nonatomic, assign) BOOL isRolloverDefault; //rollover默认展期
@property (nonatomic, assign) BOOL hasShownRolloverToast;//展示过rollover toast

@property (nonatomic, assign) CGPoint currentScrollViewContentOffset;

@property (nonatomic, assign) BOOL hiddenNavBar;
@property (nonatomic, assign) BOOL itemScrollEnable; // 默认是YES
//
@property (nonatomic, copy) NSString *currentSelectedOptionType;
@property (nonatomic, assign) BOOL isTOptionMode;

@property (nonatomic, strong) TBStockDetailCorporationModel *corporationModel;
@property (nonatomic, strong) TBOptionChainExpireModel *chainModel; // default(data+expiry)
@property (nonatomic, strong) TBDoubleRollView *doubleRollView;
@property (nonatomic, strong) TBOptionStockModel  *stockInfoItem;
@property (nonatomic, assign) NSInteger callSeparateRow;
@property (nonatomic, assign) NSInteger putSeparateRow;
@property (nonatomic, assign) BOOL isIndex;

@property (nonatomic, strong) TBOptionCallPutChoiceView *callPutChoiceView;
@property (nonatomic, strong) UILabel *expriyDateLabel;
@property (nonatomic, strong) TBOptionDatePickerView *datePickerView;

@property (nonatomic, strong, readonly) NSTimer *refreshTimer;

@property(nonatomic, strong) TBOptionChainModel *optionModel;

@property (nonatomic, weak) id<TBNewOptionChainViewControllerDelegate> delegate;

///组合期权
@property (nonatomic, strong) TBOptionChainBottomView *bottomView;//底部栏
@property (nonatomic, copy) NSArray<TBOptionStrategyBuilderStrategyModel *> *strategies;//策略列表
@property (nonatomic, copy) NSString *strategy;//当前策略key，行情用
@property (nonatomic, copy) NSString *strategyKey;//当前策略key，交易用
@property (nonatomic, copy) NSString *strategyName;//当前策略key，枚举值见TBOptionChainUtils
@property (nonatomic, strong) TBMultiOptionChainModel *multiModel;//组合model(全部)
@property (nonatomic, strong) TBMultiOptionChainExpiryModel *multiExpiryModel;//组合model(某天)
@property (nonatomic, copy) NSArray<NSArray<TBMultiOptionChainItemModel *> *> *multiData; //组合当前选中日期的数据
@property (nonatomic, copy) NSArray<NSArray <NSArray *>*> *multiDataSource; //组合期权计算的数据
@property (nonatomic, strong) NSNumber *currentStrikeWidth;//当前价差
@property (nonatomic, strong) NSNumber *defaultStrikeWidth;//默认价差
@property (nonatomic, copy) NSArray<NSNumber *> *strikeWidth;//价差列表

@property (nonatomic, strong) TBMultiOptionExpiryWidthModel *defaultExpiryWidth;//默认日期差
@property (nonatomic, strong) TBMultiOptionExpiryWidthModel *currentExpiryWidth; //当前日期差
@property (nonatomic, copy) NSArray<TBMultiOptionExpiryWidthModel *> *expiryWidth;//日期差列表

@property (nonatomic, copy) NSArray<NSNumber *> *expires;//当前到期日列表，可包含1或2个日期
@property (nonatomic, strong) TBOptionExpiryItemModel *currentExpiry;//当前到期日，如果有多个日期，则指代首个
@property (nonatomic, strong) NSNumber *chainIV;//组合当期IV

@property (nonatomic, strong) NSOperationQueue *sdkCalculateQueue; //SDK 计算数值的队列
@property (nonatomic, assign) NSInteger calculationCount; //SDK 计算次数

@property (nonatomic, strong) FloatingPanelController *shoppingPanel;//购物车浮层
@property (nonatomic, strong) TBShoppingFloatingPanelLayout *shoppingLayout;
@property (nonatomic, assign) CGFloat halfStateSurfaceViewY;
@property(nonatomic, strong) TBOptionChainShoppingViewController *shoppingVC;//购物车
@property (nonatomic, assign) BOOL isEmptyOptionData;
@property (nonatomic, copy) NSString *currentTopic;

@property (nonatomic, strong) void(^optionNoData)(void);
@property (nonatomic, strong) void(^optionExpiryChanged)(void);
@property (nonatomic, copy) void(^viewDidLoadBlock)(void);
@property (nonatomic, copy) void(^rolloverBlock)(TBTableViewCellItem *item, NSString *errorMsg);

/// 期权长连接推送列表全部数据缓存
@property (nonatomic, strong) NSMutableDictionary *pairOptionMDict;

/// 期权长连接推送列表单数据缓存
@property (nonatomic, strong) NSMutableDictionary *singleOptionMDict;

/// 单选状态下选中的期权所在indexPath, 用于UI相关的修改
@property (nonatomic, strong) NSIndexPath *singleSelectedIndexPath;

/// 多选状态下选中的期权indexPath的集合, 区分call/put, 用于UI相关的修改
@property (nonatomic, copy) NSDictionary<NSString *, NSMutableSet *> *multipleSelectedIndexPath;

- (NSArray<NSArray<NSNumber *> *> *)openAndCloseTimeList;

@property (nonatomic, strong) NSMutableDictionary *leftOptionChainDataDic;
@property (nonatomic, strong) NSMutableDictionary *rightOptionChainDataDic;

- (void)handleStrategy:(TBStockBottomBarEventType)type;//底部栏事件处理
- (BOOL)hasBottom;
- (void)updateBottomView;
- (void)updateShopPanelState;

- (void)unsubscribeOptionChain:(BOOL)resetTopic;

- (void)fetchOptionMarketData:(BOOL)showLoading;
- (void)fetchExpiryOptionData:(BOOL)showLoading;

// 离现价最近的镂空位置用于组合期权引导
- (CGRect )hollowFrameWithNearestToStrike;

-(void)jumpOptionPickStrategy;

- (void)jumpSettingPage;

-(void)refreshButtonPressed;

- (void)applyOptionMarketHeader:(BOOL)scrollToStrike;

//来源于持仓的展期
- (BOOL)isRollover;

@end
