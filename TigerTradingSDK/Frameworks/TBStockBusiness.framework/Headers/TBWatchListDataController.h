//
//  TBWatchListDataController.h
//  Stock
//
//  Created by zhengzhiwen on 2020/9/4.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TBWatchListGroup;
#import <TBStockBusinessBaseKit/TBStockListHelper.h>
#import <TBAccountSystemKit/TBLoginType.h>
//#import "TBStockMarketUntil.h"
#import "TBStockManager.h"


NS_ASSUME_NONNULL_BEGIN

extern NSString * const GUEST_WATCH_LIST_ADD_DEFAULT_STOCKS;
extern NSString * const kGUEST_WATCH_LIST_RECOMMEND_SYMBOLS;

@protocol TBWatchListDataControllerProtocol<NSObject>

- (void)portraitResetLastLastColumnMaskViewHeightIfNeed:(NSInteger)selectedCount withItemCount:(NSInteger)itemCount;
- (void)updateCellWithCorporation;
- (void)updateCellWithThumbnail; // 更新缩略图
- (void)refreshPosition;

@end

@class TBWatchListDisplayItem;
@class TBWatchListTableCellItem;
@class TBStockMarketWatchListNoticeModel;
@interface TBWatchListDataController : NSObject

@property (nonatomic, assign) NSInteger thumbnailState;
@property (nonatomic, assign) TBLoginType loginType;

@property (nonatomic, weak) id<TBWatchListDataControllerProtocol> delegate;

@property (nonatomic, strong) NSMutableArray *watchlistArray;
@property (nonatomic, strong) NSMutableArray *customGroupStocks;    //存放分组自选股
@property (nonatomic, strong) NSMutableArray *systemExceptAllGroupStocks; //存放系统下非所有的某个分组的股票
@property (nonatomic, strong) NSMutableArray *positionStockArray;
@property (nonatomic, strong) NSMutableArray *subscribeArray;     //存放已经订阅的股票
@property (nonatomic, strong) NSMutableArray *subscribeIndicesArray;//存放订阅的大盘指数
@property (nonatomic, strong) NSMutableArray *watchListIndicesArray;
@property (nonatomic, strong) NSMutableDictionary *groupWatchLists;    //全部自定义分组的股票

@property (nonatomic, copy) NSDictionary *corporationDic; // 公司行动
@property (nonatomic, copy) NSDictionary *thumbnailDic; // 缩略图
@property (nonatomic, strong) TBStockMarketWatchListNoticeModel *noticeModel;

@property (nonatomic,   copy) NSString *optionBriefsHash;   //如果optionBriefsHash的值与上一次的值一致，那么服务器将不会返回新的期权价格信息，只有optionBriefsHash值发生改变（置空），才能获取到新的数据
@property (nonatomic,   copy) NSString *hkOptionBriefsHash;

@property (nonatomic, strong) NSRecursiveLock *watchListLock;
@property (nonatomic, strong) NSRecursiveLock *databaseLock;   //数据库锁
@property (nonatomic, strong) NSRecursiveLock *watchListIndicesLock;  //大盘指数自选锁
@property (nonatomic, assign) BOOL isBriefLast; //上一次行情请求的是否是brief模式
//持仓信息是否初始化，初始化之后才请求持仓行情。为初始化直接请求参数symbols为空，容易覆盖实际的持仓信息。
@property (nonatomic, assign) BOOL positionHasInit;


//配置
@property (nonatomic, copy) NSDictionary *marketHash;

- (void)setupData;
- (void)refreshDefaultItems;

- (int)lastRowWhenFirstLoad;

- (void)loadFastExperienceWatchList;
- (NSMutableArray *)updateWatchlistWithUpdatedData:(NSArray *)updatedStocks cache:(NSArray *)cacheArray liteMode:(BOOL)liteMode;

- (void)fillDataWithQuery:(NSDictionary *)query;


- (NSMutableArray *)getCacheWatchlistArray;
- (void)setCacheWatchlistArray:(NSArray *)watchlist;

- (void)loadWatchlistCaches;
- (void)updatePositionGroupCount;
- (BOOL)topFastExperienceItem:(TBWatchListTableCellItem *)item;
- (BOOL)endFastExperienceItem:(TBWatchListTableCellItem *)item;

- (BOOL)isLoginGuest;
- (void)fetchWatchlistCorporateAction;

- (NSArray <NSNumber *> *)getServerGroupIdsWithStocks;

/** 获取自选市场缩略图
 
 注意：批量请求接口有限制
 - 股票、期权（港股、美股）、期货单类目每次最多20只
 */
- (void)fetchWatchlistThumbnail: (NSArray *)watchList;

- (void)setupNotifications;

- (void)updateDataAfterRemove:(TBWatchListGroup *)selectedGroup items:(NSArray *)items;
- (NSArray *)dataForCurrentGroup:(TBWatchListGroup *)selectedGroup;

- (NSDictionary *)zhToCodeDictionary;
- (NSDictionary *)marketTypeMap;
- (void)loadWatchlistStocks:(NSArray *)cacheArray;
- (NSMutableArray *)getCacheGroupStockArray;
- (NSArray *)cacheCustomGroupStockArrayWithGroupId:(NSInteger)groupId;


//获取除持仓外的自选列表。
- (void)fetchWatchListPositionListSuccess:(SuccessedBlock _Nullable)successed failed:(FailedBlock)failed;

- (NSArray *)stockArrayAfterFetchWhenMarketTypeNormal:(NSInteger)groupId stocks:(NSArray *)stocks;
- (NSArray *)stockArrayAfterFetchWhenMarketTypeNotNormal:(NSInteger)groupId stocks:(NSArray *)stocks;

- (void)updateStockPriceToDataBase:(NSArray <TBWatchListTableCellItem *> *)stockArray;
- (void)updateNormalStocksPriceToDataBase:(NSArray <TBWatchListTableCellItem *> *)stockArray;
- (NSArray *)allStocksExceptPositionForUpdateGroupMenu:(TBWatchListMarketType)marketType;

//数据去重
- (NSArray<TBWatchListTableCellItem *> *)distinct:(NSArray<TBWatchListTableCellItem *> *)items;

//更新loginType, tradeUp里需要
- (void)updateLoginType;


@end

NS_ASSUME_NONNULL_END
