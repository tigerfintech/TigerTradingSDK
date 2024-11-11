//
//  TBWatchlistDataManager.h
//  TBStockBusiness
//
//  Created by wind on 2023/3/9.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>
#import "TBStockManager.h"
#import <TBToolsKit/TBWatchListDisplayItem.h>

#import <TBStockBusiness/TBWatchListGroupManager.h>

@class TBWatchListViewModel;
@class TBWatchListDataController;
@class TBWatchListDisplayItem;
@class TBWatchListTableCellItem;
@class TBStockIndicesManager;
NS_ASSUME_NONNULL_BEGIN

@protocol TBWatchlistIndexDelegate <NSObject>

- (void)enableSubcribeIndicesAllTopic:(BOOL)enable;
- (void)stockDetailBottomIndexInfoArray:(NSArray *)indexArray;

@end

@protocol TBWatchlistSocketDelegate <NSObject>

@required
- (void)updatePushPrice:(NSData *)data;
- (void)updatePushPriceDict:(NSDictionary *)dict;
- (void)updatePushGreyMarket:(NSData *)data;
- (NSArray <TBWatchListTableCellItem*> *)watchlistItems;

@end

@protocol TBWatchlistPageStatusDelegate <NSObject>

- (BOOL)isWatchlistShow;
- (BOOL)watchlistIsLandscape;
- (BOOL)isWatchlistRefreshing;
- (void)setWatchlistRefreshing:(BOOL)refreshing;

@end

@protocol TBWatchlistViewDelegate <NSObject>

- (UIWindow*)managerWindow;
- (void)portraitResetLastLastColumnMaskViewHeightIfNeed:(NSInteger)selectedCount withItemCount:(NSInteger)itemCount;
- (NSArray<NSIndexPath *> *)visibleCells;
- (void)reloadTable;
- (void)alertAndRemoveExpireOption:(NSArray *)expiredOptions;
- (void)showHint:(NSString *)message;
- (void)updateMenuCount;

@end

@protocol TBWatchlistFetchDelegate <NSObject>

@required
- (void)handleNetworkCommonResult;
- (void)setWatchlistItems:(NSArray *)items;
- (void)applySectionHeader;
- (void)updateMenuCount;
- (void)setTableFooterViewIfNeeded;
- (void)reloadWatchListWithFetchThumbnaimAll: (BOOL)fetchThumbnailAll;
- (void)groupMenuControllerRefreshGroups;
- (void)groupMenuControllerFetchWatchListGroups;
- (void)thumbnailTimerUpdate;
- (void)updateShouldUpdateNewPriceValue;

@end

@interface TBWatchlistDataManager : NSObject

+ (TBWatchlistDataManager *)sharedInstance;
@property (nonatomic, strong) TBWatchListViewModel *viewModel;

@property (nonatomic, assign) TBWatchListMarketType  marketType;         //市场类型
//当前选中的分组
@property (nonatomic, strong, nullable) TBWatchListGroup *selectedGroup;
@property (nonatomic, strong) NSMutableArray              * subscribeGreyArray; //存放已经订阅的暗盘数据
//竖屏第三列
@property (nonatomic, strong) TBWatchListDisplayItem *portraitLastItem;
@property (nonatomic, weak) NSTimer                       * portraitDetailTimer;//竖屏下切换
@property (nonatomic, assign) int portraitLastRow;
@property (nonatomic, assign)BOOL startPortraitDetailInfo;

@property (nonatomic, assign) BOOL saTrackWatchListCount;///< 是否上报过自选股数量
@property (nonatomic, assign) BOOL                          isFirstDetectExpireOptions;
@property (nonatomic, assign) BOOL                          firstTimeRunIn;     //是否第一次打开自选列表
@property (nonatomic, assign) BOOL                          hasDisappeared;     //是否退出过当前界面

//timer
@property (nonatomic, weak) NSTimer                       * taskTimer;
@property (nonatomic, weak) NSTimer                       * thumbnailTaskTimer;
@property (nonatomic, weak) NSTimer                       * updatePriceTimer;
@property (nonatomic, assign) BOOL isCurrentLandscape;

@property (nonatomic, weak) id<TBWatchlistSocketDelegate, TBWatchlistFetchDelegate, TBWatchlistViewDelegate, TBWatchlistPageStatusDelegate> delegate;

@property (nonatomic, weak) id<TBWatchlistIndexDelegate> indexDelegate;

+ (void)resetDataManager;

- (TBGroupEnumType)systemMarketType;

- (void)setupNotifications;

//初始化自选数据
- (void)setupMembers;
- (void)setupWatchlistData;
- (void)setupWatchlistConfig;

- (void)loacationGroupMarketType;//定位的不一定是系统分组

/// 获取股市动态数据
- (void)fetchStockMarketNoticeSuccess:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

//长链接
- (void)tbmqttSetup;
- (void)trySubscribeTopic:(BOOL)force;
- (void)subscribeTopicArray:(NSArray *)items;
//取消指定数组的长连接订阅
- (void)unsubscribeTopicArray:(NSArray *)items;

- (void)enableSubcribeAllTopic:(BOOL)enable;
- (void)subscribeTopicGreyMarketArray:(NSArray *)items;
- (void)enableSubcribeAllTopicGreyMarket:(BOOL)enable;
- (void)unsubscribeTopicGreyMarketArray:(NSArray *)items;

- (void)enableSubcribeDigitalTopic:(BOOL)enable;

- (void)subcribeInAppPush:(BOOL)enable;

- (void)applicationWillEnterForeground:(NSNotification *)notify;

//请求
- (void)fetchRecommendSymbolsIfNeed;
- (void)fetchRecommendSymbolsWithSuccess:(void(^)(NSArray*))success failure:(void(^)(NSError * _Nullable))failed;
- (void)fetchStockDetailInfo;
- (void)requestStockInfoAfterLastColumnChangeIfNeed;
- (void)fetchUserPositionInfo:(TBWatchListSortType )sortType showLoading:(BOOL)showLoading;
- (void)refreshPosition;
- (void)loadWatchlistStocks;
- (void)loadWatchlistCaches;
- (void)removeExpireOptionWatchlistWithItems:(NSArray *)items hiddenHint:(BOOL)isHiddenHint;
- (void)detectExpireOption;
- (void)fetchVisibleStocksBrifeInfo;
- (void)reloadDataWithGroupStocks;
- (void)fetchFastExperienceStocksBrifeInfo:(NSArray *)stocks showLoading:(BOOL)showLoading;
- (NSArray *)sortWatchListItems:(NSArray *)items byMarketType:(TBWatchListMarketType)marketType sortType:(TBWatchListSortType)sortType;
- (void)fetchWatchListOptionInfoFromWatchlistArray;
- (void)fetchWatchListFuturesInfoFromWatchlistArray;
- (void)fetchWatchListForexInfoFromWatchlistArray;
- (void)fetchWatchListBondInfoFromWatchlistArray;
//从自选列表中查找所有加密货币，然后获取最新信息
- (void)fetchWatchListCryptoInfoFromWatchlistArray;
- (void)fetchWatchListInfo:(BOOL)showLoading;
- (void)fetchWatchListInfo:(TBWatchListSortType )sortType marketType:(TBWatchListMarketType)marketType groupId:(NSInteger)groupId showLoading:(BOOL)showLoading;
- (void)fetchWatchListPositionList;
- (void)fetchStocksInfomation;
- (void)fetchAllWatchListIfNeeded;
- (void)fetchAllWatchListInfo:(void (^)(void))success failed:(void (^)(void))failed;
- (void)debug_log:(NSString *)log;

//数据处理
- (void)updateWatchlistItemsDisplayItemsWhenLandscapeMode:(NSArray *)watchlistItems;
- (void)updatePushFuturePrice:(TBWatchListTableCellItem *)item price:(NSString *)price preClose:(NSString *)preClose timestamp:(NSString *)timestamp;
- (void)updatePushStockPrice:(TBWatchListTableCellItem *)item price:(NSString *)price preClose:(NSString *)preClose timestamp:(NSString *)timestamp;
- (void)updateViewModelSortType;
- (TBWatchListMarketType)marketTypeWithGroup:(TBWatchListGroup *)group;
- (NSArray *)refreshSort;
- (void)setEnterTime;
- (BOOL)isFirstTimeLaunch;

//UI
- (BOOL)isShowBottomIndexView;

//定时器
- (void)initPortraitDetailTimerIfNeed;
- (void)setEnableTimers:(BOOL)enable;

//竖屏第三列
- (NSArray<TBWatchListDisplayItem *>  *)displayItems;

//糖果方法
+ (TBWatchListViewModel *)sugarViewModel;
+ (TBWatchListDataController *)sugarDataController;

@end

NS_ASSUME_NONNULL_END
