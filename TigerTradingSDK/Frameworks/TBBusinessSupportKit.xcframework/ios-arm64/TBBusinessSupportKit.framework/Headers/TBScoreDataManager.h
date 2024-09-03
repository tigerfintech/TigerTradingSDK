//
//  TBScoreDataManager.h
//  Stock
//
//  Created by chenxin on 2019/6/28.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>

typedef NS_ENUM(NSUInteger, TBScoreTaskType) {
    TBScoreTaskTypeTweet,               // 发帖
    TBScoreTaskTypeComment,             // 发评论
    TBScoreTaskTypeUserLike,            // 点赞
    TBScoreTaskTypeReadArticle,         // 浏览文章
    TBScoreTaskTypeUserGetLike,         // 被点赞
    TBScoreTaskTypeShareStock,          // 分享个股
    TBScoreTaskTypeSharePosition,       // 分享持仓
    TBScoreTaskTypeWarmUpComment,   // 暖场评论
    TBScoreTaskTypeUserWarmUpLike,      // 暖场点赞
    TBScoreTaskTypeTrendTweet,          // 多空表态帖子
};

@interface TBScoreDataManager : NSObject

DECLARE_SHARED_INSTANCE(TBScoreDataManager)

// 获取每日任务列表, force表示是否强制更新
- (void)getDayTasks:(BOOL)force;

// 指定类型未完成任务的积分
- (NSNumber *)undoneTaskScoreWithType:(TBScoreTaskType)taskType;

// 更新未完成任务状态（更新本地状态同时请求接口获取最新状态）
- (void)updateUndoneTaskWithType:(TBScoreTaskType)taskType;

/*
 在当前页面显示积分任务提示，
 itemId用于区分重复请求
 目前只在社区模块提示
 内部判断实际上是否需要显示
 */
- (void)showTipsWithTaskType:(TBScoreTaskType)taskType
                      itemId:(id)itemId
            inViewController:(UIViewController *)viewController;

//当有发帖任务未完成时，在发帖页面提示用户的信息（200字积分双倍）
- (NSString *)getCreatePostTaskHint;

// 积分任务的跳转方法
+ (void)jumptoNativeMissonView:(NSString *)link;

// 任务列表是否含有某个任务
- (BOOL)hasTheTaskToday:(TBScoreTaskType)taskType;

@end
