//
//  TBTigerBrokersUtil.h
//  Stock
//
//  Created by zhengzhiwen on 2021/6/10.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// 测试那边提的需求，要求开户相关图片压缩到1M以下上传
#define kMaxImageDataLength 1*1024*1024

@class TBTradeAPIOrderItemModel;

typedef NS_ENUM(NSUInteger, TBAppIconBadgeNumberSyncMode) {
    TBSyncDegressionMode,   // 递减模式，每次点击已读，递减一次
    TBSyncClearMode,        // 清空模式，清空全部角标
};

NS_ASSUME_NONNULL_BEGIN

@interface TBTigerBrokersUtil : NSObject

+ (NSString *)getUserDefaultPhoneKey:(NSString *)key;

/**
  获取用户uuid+拼接TouchID

 @return uuid+拼接TouchID
 */
+ (NSString *)getUserDefaultUUIDAppendTouchID;

/**
 设置用户是否展示过期信息
 key : hasShow YES/NO date: 展示日期
 @param hasShowFuturesPastDue 用户过期货过期
 */
+ (void)setHasShowFuturesPastDue:(NSDictionary *)hasShowFuturesPastDue;

/**
 获取用户是否展示过期货过期提示信息

 @return 期货过期
 */
+ (NSDictionary *)hasShowFuturesPastDue;

//

// 模拟盘比赛中小红点提示
+ (BOOL)getVirtualGameDotStatus;

// 买卖交易打点
+ (void)setVirtualGameDotStatus:(BOOL)virtualGameDotStatus;

+ (void)setLastUnreadMessageTime:(NSTimeInterval)lastTime;

//是更烦显示搜索提示界面
+ (BOOL)showSearchHintView;

+ (void)setShowSearchHintView:(BOOL)show;

//
////同步角标数量到服务器，isClear表示是否清空
//+ (void)syncAppIconBadgeNumberToServer:(TBAppIconBadgeNumberSyncMode)syncMode completed:(void(^)(BOOL isFinished))completed;

/**
 保存选股条件

 @param requestData 服务端请求数据
 @param showData 显示用的
 @param name 选股器的名称
 @return 是否保存成功
 */
+ (BOOL)addFilterStockConditionToPlistData:(NSDictionary *)requestData showData:(NSMutableArray *)showData name:(NSString *)name;

/**
 检查同名选股器是否已经存在

 @param name 选股器名称
 @return 是否存在
 */
+ (BOOL)checkCurrentRecordHasExistName:(NSString *)name;

/**
 修改选股条件的

 @param index 需要修改的记录条数
 @param name 新的名称
 @return 是否修改成功
 */
+ (BOOL)modifyCurrentIndexRecord:(NSInteger)index newName:(NSString *)name;

/**
 删除当前选中的一条记录

 @param index 当前哪一条
 @return 是否删除成功
 */
+ (BOOL)deleteCurrentIndexRecord:(NSInteger)index;

/**
  获取所有的数据

 @return 保存起来的所有选股条件
 */
+ (NSMutableArray *)getCurrentFilterStockData;

// 获取交易引导状态
+ (void)fetchTradeGuideStatusWithSuccess:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

// 跳转财报季页
+ (void)gotoTradingSeasonPage;

@end

NS_ASSUME_NONNULL_END
