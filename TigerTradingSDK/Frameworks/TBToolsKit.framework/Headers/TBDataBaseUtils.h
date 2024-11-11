//
//  TBDataBseUtil.h
//  Stock
//
//  Created by liwt on 15/1/8.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import "TBDataBaseUtils.h"
#import "TBDataBaseSchema.h"
#import <Foundation/Foundation.h>
#import <FMDB/FMDatabase.h>


@interface TBDataBaseUtils : NSObject{
    NSString *userId;
}

@property (nonatomic, readonly) NSString *userID;
@property (nonatomic, strong) FMDatabase *fmdb;

+ (instancetype)sharedInstance;


-(id)init;
-(void)createTable;

- (void)addPushMessage:(NSDictionary *)message;
// 获取push message 条数.
- (long) getPushMessageCount;
// 获取最久的50条
- (NSArray *)getPushMessageLimitBy50;
// 给服务器发送完回执后,从数据库中删除已发送的数据.
- (void)batchDeletePushMessage:(NSArray *)queryArray;
// 获取每条push message 的详情.
- (NSDictionary *)getPushMessageById:(NSString *)messsageId;
// 清除整个push message table.
- (void) clearPushMessageListData;

//
-(long) getWatchListCount;
-(BOOL) existInWatchList:(NSString *)symbol;
-(NSArray *)getWatchListAll;
-(NSArray *)getIndicesWatchListAll;
-(NSDictionary *)getWatchListById:(NSString *)symbol;
-(void)deleteWatchListById:(NSString *)symbol;
-(void)addWatchList:(NSDictionary *)watchListData;
-(void)clearWatchListData;
-(void)batchAddWatchList:(NSArray*)queryArray;
-(void)batchAddIndicesWatchList:(NSArray*)queryArray;
//更新自选价格到数据库
- (void)batchUpdateWatchListPrice:(NSArray*)stockArray;

//持仓
-(NSArray *)getPositionListAll;
-(void)batchAddPositionList:(NSArray *)queryArray;
-(void)clearPositionData;
//快速体验自选
-(NSArray *)getFastExperienceWatchListAll;
-(BOOL)existInFastExperienceWatchList:(NSString *)symbol;
-(NSDictionary *)getFastExperienceWatchListById:(NSString *)symbol;
-(void)deleteFastExperienceWatchListById:(NSString *)symbol;
-(void)addFastExperienceWatchList:(NSDictionary *)watchListData;
-(void)clearFastExperienceWatchListData;
-(void)batchAddFastExperienceWatchList:(NSArray *)queryArray;
//搜索股票部分
-(long) getSearchHistoryCount;
-(NSArray *)getSearchHistoryAllLimit10;
-(void)addSearchHistory:(NSDictionary *)searchHistoryData;
-(void)clearSearchHistoryData;

//-(BOOL) existInHistoryList:(NSString *)symbol;
//-(void) deleteHistoryById:(NSString *)symbol;
//获取搜索用户缓存
- (NSArray *)getSearchUserAllLimit10;
- (void)addSearchUserHistory:(NSDictionary *)dict;
- (void)clearSearchUserHistoryData;
//获取搜索帖子缓存
- (NSArray *)getSearchPostAllLimit10;
- (void)addSearchPostHistory:(NSDictionary *)dict;
- (void)clearSearchPostHistoryData;

//获取搜索委托缓存
- (NSArray *)getSearchFAAllLimit10;
- (void)addSearchFAHistory:(NSDictionary *)dict;
- (void)clearSearchFAHistoryData;

-(NSArray *)getMessageListAll;
-(void) addMessageList:(NSDictionary *)messageListData;
-(void) batchAddMessagehList:(NSArray*)messageArray;
-(void)clearAllMessageData;


- (void) addPostDraft:(NSDictionary *)postInfo;
- (NSDictionary *)getPostDraftByUser_symbol:(NSString *)user_symbol;
- (void) deletePostDraftByUser_symbol:(NSString *)user_symbol;

- (void) addStockPriceAlert:(NSDictionary *)priceAlertInfo;
- (void) addStockPriceAlertArr:(NSArray *)priceAlertInfoArr;
- (NSDictionary *)getPriceAlertByUser_symbol:(NSString *)user_symbol;
- (void) deletePriceAlertByUser_symbol:(NSString *)user_symbol;

// 获取个股讨论数缓存
- (NSDictionary *)getStockDiscussCount:(NSString *)symbol;
- (void)addStockDiscussCountHistory:(NSDictionary *)discussCountData;

@end






