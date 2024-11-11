//
//  TBStockBriefQuoteManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/8/11.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*
 股票列表行情行情管理，支持短连接轮询&长连接推送
 基本和TBStockManager里的方法是一致的，主要之前TBStockManager回调是数组，查找复杂度O(n)，这里改为字典，查找复杂度为O(1)；
 为了快速完成临时需求，内部只实现了一部分方法
 */

typedef void(^QuoteListSuccessedCallBack)(id result);
typedef void(^QuoteListFailedBlock)(NSError * _Nullable error) ;


@interface TBStockBriefQuoteManager : NSObject

@property (nonatomic, strong, readonly) NSMutableDictionary *quoteDict;

// 长连接订阅未实现
- (void)subscribeQuoteList:(NSArray *)symbols;
- (void)unsubscribeQuoteList:(NSArray *)symbols;

/// 6S 轮询
- (void)enableTimer;
- (void)disableTime;

- (void)fetchStocksDetailInfo:(NSArray *)stockSymbols brifeMode:(BOOL)brifeMode isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay successed:(QuoteListSuccessedCallBack)successed failed:(QuoteListFailedBlock)failed;

+ (void)fetchStocksDetailInfo:(NSArray *)stockSymbols brifeMode:(BOOL)brifeMode isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay successed:(QuoteListSuccessedCallBack)successed failed:(QuoteListFailedBlock)failed;

+ (void)fetchStocksDetailInfo:(NSArray *)stockSymbols brifeMode:(BOOL)brifeMode isLiteMode:(BOOL)isLiteMode needDelay:(BOOL)needDelay refreshOptFut:(BOOL)refreshOptFut successed:(QuoteListSuccessedCallBack)successed failed:(QuoteListFailedBlock)failed;

@property (nonatomic, copy) void(^quoteListCallback)(NSDictionary *quoteCallBack);

@end

NS_ASSUME_NONNULL_END
