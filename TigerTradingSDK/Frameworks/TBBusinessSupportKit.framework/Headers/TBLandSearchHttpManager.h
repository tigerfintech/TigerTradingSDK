//
//  TBLandSearchHttpManager.h
//  Stock
//
//  Created by Pengfei_Luo on 16/10/13.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TBLandSearchWatchListType) {
    TBLandSearchWatchListTypeADDSuccess,
    TBLandSearchWatchListTypeADDFailure,
    TBLandSearchWatchListTypeRemoveSuccess,
    TBLandSearchWatchListTypeRemoveFailure,
    TBLandSearchWatchListTypeNone,
};

/// MARK- 展示类型：自选，搜索，搜索历史
typedef NS_ENUM(NSUInteger, TBSearchViewDisplayType) {
    TBSearchViewDisplayTypeWatchList, // default
    TBSearchViewDisplayTypeSearchHistory,
    TBSearchViewDisplayTypeSearchResult,
};

@protocol TBLandSearchHttpManagerDelegate;
@class TBStockLandSearchModel;
@interface TBLandSearchHttpManager : NSObject
@property (nonatomic, weak) id<TBLandSearchHttpManagerDelegate> delegate;

@property (nonatomic, copy) NSArray *detailCompareArray;
/**
 获取自选列表：
 有两种模式：
 1.处于分屏标的切换模式，排出期权：market为^USOPT
 2.叠加功能，需要返回当前市场对应的自选列表market：US,CN,HK

 @param market 市场string
 */
- (void)loadWatchListWithMarket:(NSString *)market;

/// 获取所有自选
- (void)fetchAllWatchListSymbol;

/**
 从服务器获取搜索

 @param searchStr 搜索字符串
 */
- (void)searchFromServer:(NSString *)searchStr isTrade:(BOOL)isTrade;

- (void)searchFromServer:(NSString *)searchStr isTrade:(BOOL)isTrade bizFilter:(NSArray *)bizFilter;

/// 定投创建页面搜索定投标的
/// @param searchStr 搜索字符串
- (void)searchRspSymbolsFromServer:(NSString *)searchStr;


/// 搜索历史
- (NSArray *)loadSearchStockHistory;

- (void)watchlistMananer:(TBStockLandSearchModel *)model;

@end

@protocol TBLandSearchHttpManagerDelegate <NSObject>

@optional
- (void)getWatchListStockArray:(NSArray *)watchList isRequestError:(BOOL)isError;

- (void)getSearchResultStockArray:(NSArray *)searchArray isRequestError:(BOOL)isError;

- (void)showTastWithWatchListManagerType:(TBLandSearchWatchListType )type tastStr:(NSString *)tastStr;

@end
