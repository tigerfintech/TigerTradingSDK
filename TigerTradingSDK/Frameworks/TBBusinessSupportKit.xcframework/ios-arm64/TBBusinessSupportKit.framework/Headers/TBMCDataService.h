//
//  TBMCDataService.h
//  TBMessageCenter
//
//  Created by swordzhou on 2021/7/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TBMCDataService : NSObject

/*
 * TigerTrade TradeUP通用
 * 获取所有分类最新一条消息
 */
- (void)fetchMessageColumnList:(void(^)(NSArray *groups, id responseObject))completion
                       failure:(void(^)(NSError *error))failure;

/**
 * TigerTrade TradeUP通用
 * 获取所有分类未读消息个数
 */
- (void)fetchUnreadMessageCount:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

/**
 * TigerTrade TradeUP通用
 * 获取某一分类消息列表
 * @param columnId 消息分类columnId
 * @param pageNumber 页码
 */
- (void)fetchGroupMessages:(NSInteger)columnId pageNumber:(NSInteger)pageNumber sucess:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

/**
 * TigerTrade TradeUP通用
 * 将消息全部标记为已读
 */
- (void)updateReadAllMessage:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

/**
 * TigerTrade TradeUP通用
 * 将某一类消息标记为已读
 * @param columnId 消息分类columnId
 */
- (void)updateMessageToReadedStatus:(NSInteger)columnId
                            success:(void(^)(id responseObject))success
                            failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
