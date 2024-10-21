//
//  TBStockManager.h
//  Stock
//
//  Created by yangfan on 17/1/17.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBStockBusinessBaseKit/TBStockDetailUtils.h>
//#import "TBStockMarketUntil.h"

@class TBWatchListParamObject;

typedef void(^SuccessedBlock)(void);
typedef void(^SuccessedWithResultBlock)(id result);
typedef void(^SuccessedWithResultAndStringBlock)(id result,NSString * string);
typedef void(^FailedBlock)(NSError * error) ;

@class TBWatchListGroup;
@interface TBStockManager : NSObject

@property (nonatomic, assign ,readonly) BOOL            enableHKStockLevel0;     //是否启用Level0合规性要求，Level0开关
//持仓列表
@property (nonatomic, copy ,readonly) NSArray       * positionArray;
//全部自选列表
@property (nonatomic, copy ,readonly) NSArray       * watchlistArray;

@property (nonatomic, copy ,readonly) NSArray       * usWatchlistSymbolArray;

@property (nonatomic, copy ,readonly) NSArray       * hkWatchlistSymbolArray;

//快速登录自选列表
@property (nonatomic, copy ,readonly) NSArray       * fastWatchlistArray;

+ (instancetype)manager;

//判断股票是否存在于自选列表中
- (BOOL)isStockInWatchList:(NSString *)symbol;
//该接口综合了addStockToWatchList以及removeStockFromWatchList的功能
- (void)addOrRemoveStockFromWatchList:(TBWatchListParamObject *)stock isAdd:(BOOL)isAdd successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

- (void)addStockToWatchList:(TBWatchListParamObject *)stock successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

- (void)addStocksToWatchList:(NSArray<TBWatchListParamObject *> *)stocks successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

//添加自选股到指定自选分组
- (void)addStocksToWatchList:(NSArray<TBWatchListParamObject *> *)stocks groupId:(NSInteger)groupId successed:(SuccessedBlock)successed failed:(FailedBlock)failed;
//添加自选股到指定自选分组(同时支持多个分组)
- (void)addStocksToWatchList:(NSArray<TBWatchListParamObject *> *)stocks groups:(NSArray<NSNumber *> *)groups successed:(SuccessedBlock)successed failed:(FailedBlock)failed;
- (void)addFavoriteStocksToWatchList:(NSArray *)stocks successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

- (void)removeStockFromWatchList:(TBWatchListParamObject *)stock successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

- (void)removeStocksFromWatchList:(NSArray *)stocks successed:(SuccessedBlock)successed failed:(FailedBlock)failed;
//从指定自选分组删除自选股
- (void)removeStocksFromWatchList:(NSArray *)stocks groupId:(NSInteger)groupId successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

/// 从各个分组删除自选股
- (void)removeStockFromGroup:(NSString *)symbol groupIds:(NSArray <NSNumber *> *)groupIds successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

- (void)updateWatchList:(NSArray *)stocks group:(TBWatchListGroup *)group successed:(SuccessedBlock)successed failed:(FailedBlock)failed;

- (void)fetchIsEnableHKStockLevel0;

//获取用户创建的分组股票
- (void)fetchWatchListStocksWithGroupId:(NSInteger)groupId successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
//获取任意的分组或者市场股票
- (void)fetchWatchListStocksWithMarket:(NSString *)marketName groupId:(NSInteger)groupId isLiteMode:(BOOL)isLiteMode successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

//获取指定股票的价格信息,以下的接口必须传入 [{@"symbol":@"AAPL"}]类似的包含字典的数组
- (void)fetchStocksBrifeInfo:(NSArray *)stockSymbols isLiteMode:(BOOL)isLiteMode successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
- (void)fetchStocksBrifeInfo:(NSArray *)stockSymbols isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
- (void)fetchOnlyForWatchListStocksDetailInfo:(NSArray *)stockSymbols brifeMode:(BOOL)brifeMode isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
/////////////////////////////////////////////////////////////////////////////////////
//只用于自选 683修改自选列表获取期权期货的数据的接口，将多种获取数据接口改为一种方式
- (void)fetchOnlyForWatchListStocksWithMarket:(NSString *)marketName groupId:(NSInteger)groupId isLiteMode:(BOOL)isLiteMode successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
- (void)fetchOnlyForWatchListStocksBrifeInfo:(NSArray *)stockSymbols isLiteMode:(BOOL)isLiteMode successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
- (void)fetchOnlyForWatchListVisibleStocksBrifeInfo:(NSArray *)stockSymbols needDelay:(BOOL)needDelay successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
- (void)fetchOnlyForWatchListStocksBrifeInfo:(NSArray *)stockSymbols isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
- (void)fetchOnlyForWatchListStockInfoDetail:(NSArray *)stockSymbols isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

//获取屏幕可见的股票价格信息,needDelay表示是否添加hkDelay参数
- (void)fetchVisibleStocksBrifeInfo:(NSArray *)stockSymbols needDelay:(BOOL)needDelay successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
//获取期权的价格信息
- (void)fetchOptionsInfo:(NSArray *)options hashValue:(NSString *)hashValue successed:(SuccessedWithResultAndStringBlock)successed failed:(FailedBlock)failed;
- (void)fetchHKOptionsInfo:(NSArray *)options hashValue:(NSString *)hashValue successed:(SuccessedWithResultAndStringBlock)successed failed:(FailedBlock)failed;
//获取期货的价格信息
- (void)fetchFuturesPriceInfo:(NSArray *)options successed:(SuccessedWithResultAndStringBlock)successed failed:(FailedBlock)failed;
//获取数据风向标
//- (void)fetchDataVane:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
//获取全市场股票行情详情，相比fetchStocksBrifeInfo接口添加了更多返回数据项
- (void)fetchStockInfoDetail:(NSArray *)stockSymbols isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

/// 获取全市场股票行情详情 包括了期权期货数据 需要返回时 refreshOptFut = YES 即可
- (void)fetchStocksDetailInfo:(NSArray *)stockSymbols brifeMode:(BOOL)brifeMode isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay refreshOptFut:(BOOL)refreshOptFut successed:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

/**
 获取公司行动数据
 */
- (void)fetchCorporateActionInfo:(NSArray *)stocks success:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

/** 获取自选市场缩略图
 
 注意：批量请求接口有限制
 - 股票、期权（港股、美股）、期货单类目每次最多20只
 */
- (void)fetchWatchlistThumbnail:(NSArray *)stocks success:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

/**
 会首先返回缓存数据
 */
- (void)fetchWatchlistThumbnailWithCache:(NSArray *)stocks success:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

/**
 获取全球市场休市状态
 
 @param successed 成功
 @param failed 失败
 */
//- (void)fetchStockGlobalClosedStatusSuccess:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;

//获取所有自选symbol
- (NSArray <NSString *> *)allSymbols;

/**
 3.18 自选提醒
 请求方法：/market/notice
 是否需要登录：是
 HTTP请求方式：GET
 
 输入参数:
 
 region    String    国家地区（CHN、USA）


 @param successed <#successed description#>
 @param failed <#failed description#>
 */
- (void)fetchStockMarketNoticeSuccess:(SuccessedWithResultBlock)successed failed:(FailedBlock)failed;
//获取某个主题行情分页总数（自定义筛选）
- (void)fetchStockCountWithFilterConditions:(NSDictionary *)params succss:(void(^)(NSArray * result,NSInteger page,NSInteger totalPage,NSInteger totalCount))successed failed:(FailedBlock)failed;
//获取某个主题行情分页数据（自定义筛选分页数据）
- (void)fetchStockListWithFilterConditions:(NSDictionary *)params urlParams:(NSDictionary *)urlParams  succss:(void(^)(NSArray * result,NSInteger page,NSInteger totalPage,NSInteger totalCount))successed failed:(FailedBlock)failed;

#pragma mark - 与数据库相关接口

//从数据库读取本地缓存的持仓列表
- (NSArray *)loadCachePositionStocks;
//从数据库读取本地缓存的自选列表（已登录用户）
- (NSArray *)loadCacheWatchListStocks;
- (NSArray *)loadIndicesWatchList;
//保存自选到数据库
- (void)saveWatchlistToDatabase:(NSArray *)stocks;
- (void)saveIndicesWatchlistToDatabase:(NSArray *)indices;//保存自选大盘数据
//保存自选到快速体验数据库
- (void)saveFastExperienceWatchlistToDatabase:(NSArray *)stocks;
//删除快速登录下自选列表中的某支股票
-(void)deleteFastExperienceWatchListById:(NSString *)symbol;
//添加自选到快速登录自选列表
-(void)addFastExperienceWatchList:(NSDictionary *)watchListData;


/// 自选埋点
/// @param isAdd 记录用户是否为添加/取消标的的自选状态
/// @param actPage 记录添加自选的页面名称：标的详情页/交易/搜索（顶部）/搜索（添加股票历史记录）/搜索（标的详情页）/热力股票（发现热门）/周期涨跌榜（发现机会）/热门标签（发现机会）/新用户引导
/// @param symbol 标的代码
/// @param market 标的市场
/// @param secType 标的类型
+ (void)addWatchListSaTrack:(BOOL)isAdd actPage:(NSString *)actPage symbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;

/// 查询某市场下的自选标的列表
/// @param market 市场
/// @param secTypes 交易品种：1、secTypes 为 nil 时，不区分 secType；2、secType 不为 nil 时，区分 secType
- (NSArray<NSString *> *)watchlistSymbolArrayMarket:(NSString *)market secTypes:(nullable NSArray<NSString *> *)secTypes;

@end
