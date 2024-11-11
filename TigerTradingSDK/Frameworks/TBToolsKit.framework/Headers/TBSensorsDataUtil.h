//
//  TBSensorsDataUtil.h
//  Stock
//
//  Created by DepthFirst on 2019/1/24.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSensorsDataUtil : NSObject

// 用户属性 （用于上报神策）
+ (NSString *)saGetUserStatus;

+ (NSString *)appBehaviorNameFromTodayId:(NSString *)todayId  market:(NSString *)market;

+ (NSString *)typeFromCommunityType:(NSInteger)communityType subType:(NSInteger)subType; // 用于统计内容消费
+ (NSString *)arriveFromStringFromPageId:(NSInteger)pageId;
+ (NSString *)stockDetailArriveFromStringFromPageId:(NSInteger)pageId;

+ (NSString *)typeFromCommunityType:(NSInteger)type; // 用于统计分享

/// 上一个页面的page值
+ (NSString *)lastPageString;
+ (void)saveLastPageString:(NSString *)pageString;

#pragma mark actionID
/*
 actionID使用场景：物料点击、活动入口点击，跳转h5页面时。生成ActionId后，上报点击事件埋点时携带，并且把该actionId当参数拼在跳转的h5 url中。
 */
// 生成actionId（对用户UUID+时间戳字符串进行MD5加密，生成唯一id）每次都生成新的值
+ (NSString *)createActionID;
// 先获取上次生成的actionID，如果没有则重新生成新值
+ (NSString *)getActionID;

/// 获取viewController对应的page值
/// @param viewController 要获取的目标VC
+ (NSString *)pageStringForViewController:(UIViewController *)viewController;
/// 获取VC的arriveFrom值，即来源页面
/// @param viewController 要获取的目标VC
+ (NSString *)arriveFromStringForViewController:(UIViewController *)viewController;

// helper，帮助特殊VC（比如：UITabBarController、TBContentBaseViewController）找到他们真正的topVC
+ (UIViewController *)detailTopVCFromViewController:(UIViewController *)sourceVC;

@end

NS_ASSUME_NONNULL_END
