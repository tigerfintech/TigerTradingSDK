//
//  TBStockBusinessComponentService.h
//  TBServiceProtocolKit
//
//  Created by linbingjie on 2021/12/1.
//

#import <Foundation/Foundation.h>

@protocol TBStockDetailInfoDataSource;
@protocol TBStockDetailViewControllerDelegate;
@protocol TBStockDetailInfoDataSource;

NS_ASSUME_NONNULL_BEGIN

@class TBOptionChainRolloverModel;
@class TBOptionStrategyBuilderStrategyMoodModel;
@class TBIntroDigitalCurrencyModel;
@class TBOptionInfoDetailItem;
@class TBConstactTickManager;

@protocol TBStockBusinessComponentService <NSObject>

/// 点击行情 tab 事件
- (void)tbStockBusiness_quoteTabTapAction;

/// 获取自选分组
/// @param callBack 回调
- (void)tbStockBusiness_fetchWatchListGroupsWithCallBack:(nullable void(^)(void))callBack;

/// 清空股票别名
- (void)tbStockBusiness_clearAlias;

/// mini 走势图，支持股票，期权，期货，数据源和自选的一致
/// @param symbol symbol
/// @param symbol market
/// @param secType secType description
/// @param color color
/// @param needPreCloseLine 是否需要昨收线
- (UIView *)tbStockBusiness_thumbnailKlineViewWithSymbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType color:(UIColor *)color needPreCloseLine:(BOOL)needPreCloseLine;

/// 跳转新股申购
/// @param market 市场 US/HK
/// @param tabType 列表类型，详见TBIPOsTabType
- (void)tbStockBusiness_jumpIPOWithMarket:(nullable NSString *)market tabType:(NSInteger)tabType;

- (UIImage *)tbStockBusiness_getLabelImageWidthLabel:(NSString *)label;

//判断股票是否存在于自选列表中
//
- (BOOL)tbStockBusiness_isStockInWatchList:(NSString *)symbol;

// 添加或移除自选, 会带有底部弹窗提示
- (void)tbStockBusiness_addOrRemoveWatchListWithSymbol:(NSString *)symbol name:(NSString *)name market:(NSString *)market secType:(NSString *)secType shouldSelect:(BOOL)shouldSelect completion:(void (^)(BOOL selected))completion;

// 添加自选普通方法, 不会带有底部弹窗提示
- (void)tbStockBusiness_addToWatchListWithSymbol:(NSString *)symbol
                                            name:(NSString *)name
                                          market:(NSString *)market
                                         secType:(NSString *)secType
                                       successed:(void(^)(void))successed
                                          failed:( void(^)(NSError * error))failed;

/// 判断是否是H5 IPO？
- (BOOL)tbStockBusiness_isIPOPurchaseH5;

/// 处理IPO Action
/// @param actionType
- (void)tbStockBusiness_handleIPOsActionType:(NSInteger)actionType;

/// 自选股数量
- (NSInteger)tbStockBusiness_loadCacheWatchListStocksCount;

/// 删除自选股cache
- (void)tbStockBusiness_removeGroupCache;

// 添加自选埋点
- (void)tbStockBusiness_addWatchListSaTrack:(BOOL)isAdd actPage:(NSString *)actPage symbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

- (void)tbStockBusiness_stockRightAlertShowAlert;

/// 初始化TBQuoteTabViewController
- (UIViewController *)tbStockBusiness_initTBQuoteTabViewController;

/// 初始化TBDiscoverRootController
- (UIViewController *)tbStockBusiness_initTBDiscoverRootController;

/// TBTabBarIndexQuote时候触发quotevc跳转逻辑
/// @param quoteTab 目标quotetab
/// @param path 路径
- (void)tbStockBusiness_quoteTabGotoMarketTab:(UIViewController *)quoteTab
                                         path:(NSString *)path;

/// 获取合约完整盘口
/// @param symbols symbols
/// @param success success
/// @param failure failure
- (void)tbStockBusiness_fetchFuturesMarketPrice:(NSArray *)symbols
                                        success:(void(^)(NSDictionary * data))success
                                        failure:(void(^)(NSError *error))failure;

/// 是否含有逐笔、买卖档位
/// @param market market description
/// @param secType secType description
/// @param specialCase specialCase description
- (BOOL)tbStockBusiness_hasTickData:(NSString * _Nullable)market
                            secType:(NSString * _Nullable)secType
                       exchangeCode:(NSString * _Nullable)exchangeCode
                        specialCase:(BOOL)specialCase;

- (BOOL)tbStockBusiness_hasAskBidCell:(NSString * _Nullable)market
                              secType:(NSString * _Nullable)secType
                         exchangeCode:(NSString *_Nullable)exchangeCode
                          specialCase:(BOOL)specialCase;

- (NSDictionary *)tbStockBusiness_getMarketTimeZoneMap;

- (NSDictionary *)tbStockBusiness_getMarketTimeZoneDesMap;

- (id)tbStockBusiness_tradeAnalysisDetailAction:(NSString *)segType;

/** 满足基础权限，请求期权产品推荐banner接口，获取当前标的是否在白名单内
 */
- (void)tbStockBusiness_getOptonsProductRecommendBannerWithSymbol:(NSString *)symbol
                                                           market:(NSString *)market
                                                          secType:(NSString *)secType
                                                         callback:(void(^)(BOOL))callback;
/**
 限制保证金账户下单提示
 */
- (UIViewController *_Nullable)tbStockBusiness_limitMarginTradePromptWithParams:(NSDictionary * _Nullable)params;

/**
 逐笔、买卖五档 or 买卖十档是否展开
 */
- (BOOL)tbStockBusiness_levelDetailWithMarket:(NSString * _Nullable)market;


- (id)tbStockBusiness_getStockOptionsRecommendCellItemWithSymbol:(NSString *)symbol
                                                       topMargin:(CGFloat)top
                                                    bottomMargin:(CGFloat)bottom
                                                      cellHeight:(CGFloat)height;


/**
 是否有碎股交易能力，下面条件都满足
 */
- (BOOL)tbStockBusiness_hasFractionalShareTradeAbilityWithMarket:(NSString *)market
                                                         secType:(NSString *)secType;

/**
 是否有窝轮交易权限
 */
- (BOOL)tbStockBusiness_canTradeHKWarTOPT;

/// 请求所有种类的K线、分时图数据
- (void)tbStockBusiness_fetchLineData:(NSString *)symbol
                               market:(NSString *)market
                              secType:(NSString *)secType
                             lineType:(NSInteger)lineType
                               params:(NSDictionary *)params
                              success:(void(^)(NSInteger lineType, NSArray *items, id responseObject))success
                              failure:(void(^)(NSError *error))failure;


/**
 批量的获取合约完整信息
 */
- (id)tbStockBusiness_fetchContractsInfoWithContractCodes:(NSArray <NSString *> *)contractCodes;

/**
 获取打包好的合约信息，包括交易时间段、保证金、交易时间(如果是主连合约的话会有)
 */
- (id)tbStockBusiness_fetchPackingContractInfoWithContractCode:(NSString *)contractCode;


/// 直接push跳转指定市场页
/// @param quoteTab 目标quotetab
/// @param path 路径
- (void)tbStockBusiness_gotoMarketPageWithPath:(NSString *)path
                            fromViewController:(UIViewController *)fromViewController;

- (void)tbStockBusiness_gotoDiscoverSubPageVC:(UIViewController *)selectedVC
                                        index:(NSInteger)index;

- (void)tbStockBusiness_fetchIsEnableHKStockLevel0;

/// 跳转IPO页面
/// @param tabType tab类型
/// @param userInfo userinfo
- (void)tbStockBusiness_gotoIPOPage:(NSInteger)tabType userInfo:(nullable NSDictionary *)userInfo;

- (void)tbStockBusiness_fetchAllStockPriceAlert;

- (void)tbStockBusiness_showOptionPermissionAlert;

/// 拉取股票别名
- (void)tbStockBusiness_fetchStockAlias;

- (void)tbStockBusiness_stockDetailHKStockLevelSwitch:(void (^)(BOOL))sucess;

- (void)tbStockBusiness_fetchStockOptionDetails:(NSArray *)items
                                         market:(NSString *)market
                              addInterestTarget:(BOOL)addInterestTarget
                                       hashCode:(NSString *)hashCode
                                        success:(void (^)(id))success
                                        failure:(void (^)(NSError * nullable))failure;
// 回调字典
- (void)tbStockBusiness_fetchStockInfoDetail:(NSString *)symbol
                                      market:(NSString *)market
                                     secType:(NSString *)secType
                                     success:(void(^)(NSDictionary *data))success
                                     failure:(void(^)(NSError *error))failure;
// 回调代理
- (void)tbStockBusiness_fetchStockInfoDetail:(NSString *)symbol
                                      market:(NSString *)market
                                     secType:(NSString *)secType
                             successDelegate:(void(^)(id delegate))success
                                     failure:(void(^)(NSError *error))failure;

- (void)tbStockBusiness_fetchMlegInfoDetail:(nullable NSString *)stockSymbol
                                  contracts:(NSArray <NSDictionary *> *)contracts
                                    success:(void(^)(id<TBStockDetailViewControllerDelegate> delegate))success
                                    failure:(void(^)(NSError *error))failure;

/// 判断标的是否可交易
- (void)tbStockBusiness_fetchContractTradeAble:(NSString *)symbol
                                        market:(NSString *)market
                                       secType:(NSString *)secType
                                       success:(void(^)(BOOL tradeable, id secInfo))success
                                       failure:(void(^)(NSError *error))failure;

///  获取碎股行情
- (void)tbStockBusiness_fetchUniteShareInfoDetail:(NSString *)symbol
                                           market:(NSString *)market
                                          success:(void(^)(id itemModel))success
                                          failure:(void(^)(NSError *error))failure;

/** 获取组合期权深度
 */
- (void)tbStockBusiness_fetchMLegOptionDepth:(nullable NSString *)stockSymbol
                                   stockSize:(nullable NSNumber *)stockSize
                              stockDirection:(nullable NSString *)stockDirection
                                   contracts:(NSArray <NSDictionary *> *)contracts
                                     success:(void (^)(id responseObject))success
                                     failure:(void (^)(NSError * nullable))failure;

/// 请求暗盘行情
- (void)tbStockBusiness_fetchStockInfoGreyMarketDetail:(NSString *)symbol
                                                market:(NSString *)market
                                               success:(void (^)(id))success
                                               failure:(void (^)(NSError *))failure;


/// 请求股票公司行动展示
- (void)tbStockBusiness_fetchStockDetailFundamentalActions:(NSString *)symbol
                                                    market:(NSString *)market
                                                   success:(void (^)(id))success
                                                   failure:(void (^)(NSError *))failure;

@optional

- (id)tbStockBusiness_getTopRecommendCellItemWithDict:(NSDictionary *)dict;
- (id)tbStockBusiness_getTopRecommendCellItemWithDict:(NSDictionary *)dict showClose:(BOOL)showClose;

- (NSString *)tbStockBusiness_getAliasWithSymbol:(NSString *)symbol;

/// 获取自选标签图标数组
- (NSArray<UIImage *> *)tbStockBusiness_getWatchListLabelArrayWithItem:(id)item;

- (void)tbStockBusiness_addStocksToWatchList:(NSArray *)stocks
                                     groupId:(NSInteger)groupId
                                   successed:(void(^)(void))successed
                                      failed:(void(^)(NSError * _Nullable error))failed;

- (void)tbStockBusiness_fetchStocksDetailInfo:(NSArray *)stockSymbols
                                    brifeMode:(BOOL)brifeMode
                                   isLiteMode:(BOOL)isLiteMode
                                    needDelay:(BOOL)needDelay
                                refreshOptFut:(BOOL)refreshOptFut successed:(void(^)(id _Nullable result))successed
                                       failed:(void(^)(NSError * _Nullable error))failed;

- (UIView *)tbStockBusiness_getStockDetailNewPostKlineViewWithSymbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType items:(NSArray *)items preClose:(CGFloat)preClose;

- (void)tbStockBusiness_setUpKlineViewWithSymbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

- (void)tbStockBusiness_createKlinePostHandleActionForCell:(id)cell object:(id)item info:(id)info;

- (UIViewController *)tbStockBusiness_getHourTradingVCWithMarketType:(NSString *)marketType
                                                              symbol:(NSString *)symbol
                                                              market:(NSString *)market;

- (void)tbStockBusiness_startStockDetailHourTradingTimerWithVC:(UIViewController *)vc;

- (void)tbStockBusiness_stopStockDetailHourTradingTimerWithVC:(UIViewController *)vc;

- (NSString *)tbStockBusiness_mktValueWithAHStockSecInfo:(id)secInfo title:(NSString *)title;

- (BOOL)tbStockBusiness_stockIsInTradeTime:(NSArray *)openAndCloseTimeList
                                    market:(NSString *)market;

- (BOOL)tbStockBusiness_getWeeklyOptions;

/** 格式化价格区间
 */
- (NSString *)tbStockBusiness_formatPriceWithMin:(NSNumber *)minPrice
                                             max:(NSNumber *)maxPrice
                                        currency:(nullable NSString  *)currency;
/** 格式化量区间
 */

- (NSString *)tbStockBusiness_formatVolumeCountWithMin:(NSNumber *)min
                                                   max:(NSNumber *)max
                                              currency:(nullable NSString  *)currency;

- (BOOL)tbStockBusiness_watchlistIsItemsDefault;
- (void)tbStockBusiness_watchlistSetItemsDefault:(BOOL)defa;

/// 获取TradingStatus
- (NSNumber *)tbStockBusiness_fetchTradingStatusWithVC:(UIViewController *)vc;

//指标说明文案
- (void)tbStockBusiness_indicatorBtnAction:(NSString *)market
                                   secType:(NSString *)secType;


- (void)tbStockBusiness_presentOptionStrategyAnalysisVCWithItem:(id)item
                                                       legModel:(id)model
                                                         amount:(double)amount
                                                      netSpread:(NSNumber *)spread
                                                    netQuantity:(NSNumber *)quantity
                                                       fromType:(NSString *)fromType;

//标准化价格字符串输出
- (NSString *)tbStockBusiness_watchlistCellGetPriceString:(id)cellItem;
//标准化涨跌幅字符串输出
- (NSString *)tbStockBusiness_watchlistCellGetChangeRateString:(id)cellItem;

//获取某个主题行情分页数据（自定义筛选分页数据）
- (void)tbStockBusiness_fetchStockListWithFilterConditions:(NSDictionary *)params
                                                 urlParams:(NSDictionary *)urlParams
                                                    succss:(void(^)(NSArray * result,NSInteger page,NSInteger totalPage,NSInteger totalCount))successed
                                                    failed:(void(^)(NSError * _Nullable error))failed;

- (void)tbStockBusiness_fetchStocksBrifeInfo:(NSArray *)stockSymbols
                                  isLiteMode:(BOOL)isLiteMode
                                   successed:(void(^)(id _Nullable result))successed
                                      failed:(void(^)(NSError * _Nullable error))failed;

- (UIView *)tbStockBusiness_getStockPeriodKLineViewSelected:(void(^)(NSInteger lineType, NSNumber *limitCount))selectedBlock
                                                   loadMore:(void(^)(void))loadBlock;

// 配置K线图方法(废弃, 用下面的以secInfo为参数的方法)
- (void)tbStockBusiness_updateStockPeriodKLineViewWithView:(UIView *)klineView symbol:(NSString *)symbol secType:(NSString *)secType market:(NSString *)market;

// 配置K线图方法
- (void)tbStockBusiness_updateStockPeriodKLineViewWithView:(UIView *)klineView
                                                   secInfo:(id<TBStockDetailInfoDataSource>)secInfo
                                        longPressSuperview:(UIView *)longPressSuperview;

// 期货用
- (void)tbStockBusiness_updateStockPeriodKLineViewWithView:(UIView *)klineView
                                                     model:(id)model;


- (void)tbStockBusiness_updateLineDataWithView:(UIView *)klineView
                                          data:(NSDictionary *)responseObject
                                         items:(NSArray *)items
                                      lineType:(NSInteger)type
                                      preClose:(double)preClose
                                     timeStamp:(NSArray *)timeStamp
                                 contractModel:(id)model;

- (NSInteger)tbStockBusiness_getStockPeriodKLineTypeWithView:(UIView *)klineView;

- (UIView *)tbStockBusiness_getTradeOmnibusAnalysisChartView;

- (void)tbStockBusiness_updateTradeOmnibusAnalysisChartWithView:(UIView *)view
                                                       delegate:(id)delegate
                                                     candleData:(NSArray *)klineItems
                                                    periodsData:(NSArray *)periodsItems;

- (BOOL)tbStockBusiness_isAllowDetailBottomShowIndexNotification;

- (BOOL)tbStockBusiness_isAllowHangqingAnimationLayer;

- (BOOL)tbStockBusiness_isAllowHangqingSmartSorting;

- (BOOL)tbStockBusiness_isAllowClickLastColumnSwitchDisplayItem;

- (BOOL)tbStockBusiness_isAllowItemBGView;

- (BOOL)tbStockBusiness_isDisplayOptionPosition;

- (BOOL)tbStockBusiness_isAllowItemListMenu;

- (NSDictionary *)tbStockBusiness_nonNullDictionary:(NSDictionary *)dictionary;

- (NSInteger)tbStockBusiness_getWatchlistDisplayMode;

- (NSArray *)tbStockBusiness_getWatchlistPortraitItems;

- (BOOL)tbStockBusiness_getEnableHKStockLevel0;

/// 期权链统计数据
- (BOOL)tbStockBusiness_optionStatistics;
- (void)tbStockBusiness_setOptionStatistics:(BOOL)optionStatistics;

/// 周权标记
- (BOOL)tbStockBusiness_weeklyMark;
- (void)tbStockBusiness_setWeeklyMark:(BOOL)weeklyMark;

/// 隐藏公司行动后期权
- (BOOL)tbStockBusiness_hideUnstandardOption;
- (void)tbStockBusiness_setHideUnstandardOption:(BOOL)hideUnstandardOption;

/// 浏览布局: 0 列表, 1 T型
- (NSNumber *)tbStockBusiness_optionChainStyle;
- (void)tbStockBusiness_setOptionChainStyle:(NSNumber *)optionChainStyle;

/// 股票名称备注
- (BOOL)tbStockBusiness_stockAlias;
- (void)tbStockBusiness_setStockAlias:(BOOL)stockAlias;

/// 趋势线: 0 unselected, 1 selected
- (NSNumber *)tbStockBusiness_trendLine;
- (void)tbStockBusiness_setTrendLine:(NSNumber *)trendLine;

/// 筹码分布
- (BOOL)tbStockBusiness_positionCost;
- (void)tbStockBusiness_setPositionCost:(BOOL)positionCost;

/// 除复权: BEFORE 前复权, NO 不复权, AFTER 后复权
- (NSString *)tbStockBusiness_priceAdjustment;
- (void)tbStockBusiness_setPriceAdjustment:(NSString *)priceAdjustment;

/// 公司行动
- (BOOL)tbStockBusiness_companyAction;
- (void)tbStockBusiness_setCompanyAction:(BOOL)companyAction;

/// 买卖打点
- (BOOL)tbStockBusiness_buySellPoint;
- (void)tbStockBusiness_setBuySellPoint:(BOOL)buySellPoint;

/// 跳空缺口
- (BOOL)tbStockBusiness_jumpGap;
- (void)tbStockBusiness_setJumpGap:(BOOL)jumpGap;

/// 持仓成本
- (BOOL)tbStockBusiness_holdCost;
- (void)tbStockBusiness_setHoldCost:(BOOL)holdCost;

/// 画线
- (BOOL)tbStockBusiness_drawLine;
- (void)tbStockBusiness_setDrawLine:(BOOL)drawLine;

/// 现价线
- (BOOL)tbStockBusiness_latestPriceLine;
- (void)tbStockBusiness_setLatestPriceLine:(BOOL)latestPriceLine;

/// 预警线
- (BOOL)tbStockBusiness_alertLine;
- (void)tbStockBusiness_setAlertLine:(BOOL)alertLine;
// 缺: 量价图, 神奇九转

- (void)tbStockBusiness_setAllowItemBGView:(BOOL)allow;

- (void)tbStockBusiness_setAllowClickLastColumnSwitchDisplayItem:(BOOL)allow;

- (void)tbStockBusiness_setAllowItemListMenu:(BOOL)allow;

//已经废弃，禁止使用这个方法
- (void)tbStockBusiness_tupRequestStockInfoDetailWithSymbol:(NSString *)symbol
                                                     market:(NSString *)market;

/**
 获取k线数据
 */
- (void)tbStockBusiness_fetchFuturesKLineData:(NSString *)symbol
                                       period:(NSInteger)period
                                        index:(NSInteger)index
                                       offset:(NSInteger)offset
                                      success:(void(^)(id itemModel))success
                                      failure:(void(^)(NSError *error))failure;

/*
 根据账户、标的类型等 预判标的是否可交易
 */
- (void)tbStockBusiness_contractTradeAble:(NSString *)symbol
                                   market:(NSString *)market
                                  secType:(NSString *)secType
                                  success:(void(^)(NSUInteger tradeType))success;

/// 获取当前默认周期
- (NSInteger)tbStockBusiness_commonSelectedLineTypeWithMarket:(NSString *)market
                                                      secType:(NSString *)secType;

/**
 取指定时间段请求K线图数据
 */
- (void)tbStockBusiness_fetchKlineWithType:(NSInteger)lineType
                                    symbol:(NSString *)symbol
                                    market:(NSString *)market
                                 beginTime:(NSTimeInterval)beginTime
                                   endTime:(NSTimeInterval)endTime
                                     limit:(NSInteger)limit;

- (void)tbStockBusiness_fetchLineData:(NSString *)symbol
                               market:(NSString *)market
                              secType:(NSString *)secType
                             lineType:(NSInteger)lineType
                               isLoop:(BOOL)isLoop
                           isDarkPool:(BOOL)isDarkPool
                               params:(nonnull NSDictionary *)params
                              success:(nonnull void (^)(NSInteger lineType, NSArray *items, id responseObject))success
                              failure:(nonnull void (^)(NSError *error))failure;

/// 请求更多历史K线数据
- (void)tbStockBusiness_fetchPreLineData:(NSString *)symbol
                                  market:(NSString *)market
                                 secType:(NSString *)secType
                                lineType:(NSInteger)lineType
                                  isLoop:(BOOL)isLoop
                                  params:(nonnull NSDictionary *)params
                                 success:(nonnull void (^)(NSInteger lineType, NSArray *items, id responseObject))success
                                 failure:(nonnull void (^)(NSError *error))failure;

- (void)tbStockBusiness_updateLineDataManagerWithExpiry:(NSNumber *)expiry
                                                  right:(NSString *)right
                                                 strike:(NSString *)strike;

/**
 获取合约简要盘口
 */
- (id)tbStockBusiness_fetchMarketBriefPriceWithContractCodes:(NSArray <NSString *> *)contractCodes;


/// 美股/期货深度数据订阅长连接
- (void)tbStockBusiness_subscribDepth:(NSString *)symbol
                               market:(NSString *)market
                              secType:(NSString *)secType
                         exchangeCode:(NSString *)exchangeCode
                            quoteType:(NSString *)quoteType
                           isDarkPool:(BOOL)isDarkPool
                          tickManager:(id)tickManager;

- (void)tbStockBusiness_subscribeQuoteTick:(NSString *)symbol
                                    market:(NSString *)market
                                   secType:(NSString *)secType
                              exchangeCode:(NSString *)exchangeCode
                               tickManager:(id)tickManager;

- (void)tbStockBusiness_unsubscribDepth:(NSString *)symbol
                                 market:(NSString *)market
                                secType:(NSString *)secType
                           exchangeCode:(NSString *)exchangeCode
                              quoteType:(NSString *)quoteType
                             isDarkPool:(BOOL)isDarkPool
                            tickManager:(id)tickManager;

- (void)tbStockBusiness_unsubscribeQuoteTick:(NSString *)symbol
                                      market:(NSString *)market
                                     secType:(NSString *)secType
                                exchangeCode:(NSString *)exchangeCode
                                 tickManager:(id)tickManager;

/// 深度/五档/十档
- (void)tbStockBusiness_fetchContractAskBid:(NSString *)symbol
                                     market:(NSString *)market
                                    secType:(NSString *)secType
                               exchangeCode:(NSString * _Nullable)exchangeCode
                                  quoteType:(NSString *)quoteType
                                 isDarkPool:(BOOL)isDarkPool
                                tickManager:(id)tickManager;

/// 分价
- (void)tbStockBusiness_fetchContractPriceList:(NSString *)symbol
                                        market:(NSString *)market
                                       secType:(NSString *)secType
                                        isLoop:(BOOL)isLoop
                                    isLoadMore:(BOOL)isLoadMore
                                    isDarkPool:(BOOL)isDarkPool
                                   tickManager:(id)tickManager;

/** 获取组合期权深度
 *
 */
- (void)tbStockBusiness_fetchMLegContractAskBid:(nullable NSString *)stockSymbol
                                      stockSize:(nullable NSNumber *)stockSize
                                 stockDirection:(nullable NSString *)stockDirection
                                      contracts:(NSArray <NSDictionary *> *)contracts
                                    tickManager:(id)tickManager;

/// 逐笔数据
- (void)tbStockBusiness_fetchContractTick:(NSString *)symbol
                                   market:(NSString *)market
                                  secType:(NSString *)secType
                                   isLoop:(BOOL)isLoop
                              refreshType:(NSInteger)refreshType
                               isDarkPool:(BOOL)isDarkPool
                              tickManager:(id)tickManager;

- (void)tbStockBusiness_updateTickManagerWithInfo:(id<TBStockDetailInfoDataSource>)secInfo
                                      tickManager:(TBConstactTickManager *)tickManager
                                         userInfo:(nullable NSDictionary *)userInfo;

- (NSString *)tbStockBusiness_getQuoteTypeWithTickManager:(id)tickManager;


- (id)tbStockBusiness_getTickManagerTicks:(void(^)(NSArray *ticksArray))ticksBlock
                                priceList:(void(^)(NSArray *priceLists))priceListBlock
                                   askBid:(void(^)(id askBidModel))askBidBlock;

- (UIView *)tbStockBusiness_getCreatePostKlineView;

- (NSString *)tbStockBusiness_getWatchlistChangeNotificationKey;

- (NSString *)tbStockBusiness_getStockColorSettingNotificationKey;

- (NSString *)tbStockBusiness_getRefreshViewShowNotificationKey;

- (NSString *)tbStockBusiness_getRefreshViewHideNotificationKey;

- (NSString *)tbStockBusiness_getNotificationKey_NOTIFICATION_KEY_GET_QUOTE_FREE_ARCALV2;

- (NSString *)tbStockBusiness_getNotificationKey_kNOTIFICATION_KEY_GET_FRACTIONAL_SHARE_PERMISSSION;

- (NSString *)tbStockBusiness_getNotificationKey_USER_DEFAULT_ALLOW_BOTTOMSHOWINDEX_NOTIFICATION;

- (NSString *)tbStockBusiness_getNotificationKey_USER_DEFAULT_KEY_THUMBNAIL_SHOW_ITEM;

- (NSString *)tbStockBusiness_getNotificationKey_USER_DEFAULT_KEY_HANGQING_ITEM_BGVIEW;

- (NSString *)tbStockBusiness_getNotificationKey_USER_DEFAULT_KEY_HANGQING_SWITCH_SORTING;

- (NSString *)tbStockBusiness_getNotificationKey_USER_DEFAULT_KEY_HANGQING_ANIMATION_LAYER;

- (NSString *)tbStockBusiness_getNotificationKey_USER_DEFAULT_KEY_HANGQING_SMART_SORTING;

- (NSString *)tbStockBusiness_getNotificationKey_USER_DEFAULT_KEY_OPTION_POSITION_DISPLAY;

- (NSDictionary *)tbStockBusiness_convertWatchlistCellItemToDict:(id)item;

- (id)tbStockBusiness_getWatchlistCellItemWithSymbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

- (id)tbStockBusiness_getWatchlistActionWithSymbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

- (id)tbStockBusiness_getWatchlistParamObjectWithSymbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType name:(NSString *)nameCN;

- (NSArray *)tbStockBusiness_getWatchlistSearchCellItemArray;

- (NSArray *)tbStockBusiness_getFastWatchlistArray;

- (NSArray *)tbStockBusiness_loadCacheWatchlistArray;

- (NSString *)tbStockBusiness_getSymbolWithStockDetailCombineVC:(UIViewController *)vc;

- (NSString *)tbStockBusiness_getSymbolWithStockDetailHorizontalVC:(UIViewController *)vc;

- (NSInteger)tbStockBusiness_getFrequencyTypeWithSymbol:(NSString *)symbol;

- (void)tbStockBusiness_updateStockPriceAlertFrequencyToOncePerDayWithSymbol:(NSString *)symbol market:(NSString *)market;

- (void)tbStockBusiness_fetchWatchlistThumbnail:(NSArray *)stocks success:(void(^)(id _Nullable result))successed failed:(void(^)(NSError * _Nullable error))failed;

- (void)tbStockBusiness_deleteStockPriceAlertWithSymbol:(NSString *)symbol;

- (void)tbStockBusiness_deleteFastWatchlistWithSymbol:(NSString *)symbol;

- (void)tbStockBusiness_addFastWatchlistWithDict:(NSDictionary *)dict;

- (void)tbStockBusiness_gotoHKStockQuotePage;

- (void)tbStockBusiness_getIPOCount:(void(^)(BOOL hasNew, NSInteger newIPOCount))completion;

- (NSArray<NSString *> *)tbStockBusiness_symbolsInWatchlistForMarket:(NSString *)market
                                                            secTypes:(NSArray<NSString *> *)secTypes;
// 是否是支持碎股的symbol
- (BOOL)tbStockBusiness_isFractionalShareWithSymbol:(NSString *)symbol market:(NSString *)market;

- (NSString *)tbStockBusiness_NotificationKey_kTB_NOTIFICATION_TRADE_GUIDE_CLOSE;

- (NSString *)tbStockBusiness_NotificationKey_kTB_NOTIFICATION_STOCK_DETAIL_START_TRADE_GUIDE;

- (void)tbStockBusiness_getOptionStragegyTradeKeys:(void(^)(NSArray <NSString *> *))completion;

// 用户的关注的投资者列表
- (void)tbStockBusiness_gotoStarInvestorHeadListPage:(NSString *)userId;


// 跳转到盘前盘后榜
- (void)tbStockBusiness_gotoPrePostMarkets;

// 跳转到夜盘榜
- (void)tbStockBusiness_gotoOvernightMarkets;

/**
 * 跳转到期权频道页
 * @param userInfo 可选预留参数，如后期传递arriveFrom等参数
 */
- (void)tbStockBusiness_gotoOptionsHomePage:(nullable NSDictionary *)userInfo;

/**
 * 跳转到选股器首页
 * @param userInfo 可选预留参数，如后期传递arriveFrom等参数
 */
- (void)tbStockBusiness_gotoScreenerHomePage:(nullable NSDictionary *)userInfo;

/**
 * 跳转到港股ETF专区
 * @param userInfo 可选预留参数，如后期传递arriveFrom等参数
 */
- (void)tbStockBusiness_gotoHKEftPage:(nullable NSDictionary *)userInfo;


/**
 判断是否在自选里
 */
- (BOOL)isWithInWatchList:(NSString *)symbol;

/**
 * rollover 弹出期权链模块VC
 */
- (UIViewController *)tbStockBusiness_newOptionChainViewControllerWithModel:(TBOptionChainRolloverModel *)configModel
                                                          isRolloverDefault:(BOOL)isRolloverDefault
                                                                      block:(void(^)(TBOptionChainRolloverModel *))block;

/// 通过组合期权获取策略信息
- (void)tbStockBusiness_getStrategyByOptionWithParams:(NSDictionary *)params success:(void(^)(TBOptionStrategyBuilderStrategyMoodModel *model, NSString *error))success;


/// 获取币种介绍
- (void)tbStockBusiness_requestCryptoProfileWithSecType:(NSString *)secType
                                                 symbol:(NSString *)symbol
                                                success:(void(^)(TBIntroDigitalCurrencyModel *model))success
                                                failure:(void(^)(NSError *error))failure;

/// 是否包含数字货币行情权限
- (BOOL)tbStockBusiness_hasCryptoQuotePermission;

- (NSDictionary *)tbStockBusiness_allCryptos;
- (NSString *)tbStockBusiness_formatCrypto:(NSString *)symbol price:(NSNumber *)price;


/// 获取期权行情
- (void)tbStockBusiness_fetchOptionBriefOfSymbol:(NSString *)symbol
                                          expiry:(long long)expiry
                                          strike:(NSString *)strike
                                           right:(NSString *)right
                                          market:(NSString *)market
                                         success:(void (^)(TBOptionInfoDetailItem *detailItem))success
                                         failure:(void (^)(NSError * error))failure;

//旧期权，交易按钮点击时，需要弹窗提示
- (void)tbStockBusiness_checkOldOption:(BOOL)isOld
                          confirmBlock:(void (^)(void))confirmBlock
                           cancelBlock:(void (^)(void))cancelBlock;

@end

NS_ASSUME_NONNULL_END
