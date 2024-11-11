//
//  TBTabBarViewController.h
//  Stock
//
//  Created by liwt on 15/1/3.
//  Refactored by donggf on 23/1/4.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTabBarBaseController.h>

@class TBTabItem;

@interface TBTabBarViewController : TBTabBarBaseController

@property (nonatomic,assign) BOOL isFromSuccessfulLogin;
@property (nonatomic,assign) BOOL isEmptyToken;

/// tab信息(key/title/image等)
/// tabItems和viewControllers属性通过 Dispatch Barrier 保证线程安全
/// 操作tab需要通过 reloadTab/insertTab/removeTab 方法
@property (nonatomic, copy, readonly) NSArray<TBTabItem *> *tabItems;

// tabbar动画相关
@property (nonatomic, copy, readonly) NSArray *tabBarButtonsArray; //数组中存放UITabBarButton
@property (nonatomic, strong) UIControl *lastTabBarView;//上次选中的时候添加动画的View
@property (nonatomic, strong) UIView *lastTabBarImageView;//上次选中的tab中图片view

// 重置所有页面，比如切换语言后
- (void)reset;

/// 跳转到某个tab
- (BOOL)selectTab:(NSString *)name;

// 检查是否显示新用户大礼包
- (void)checkShowNewbieGiftGuideWithReward:(BOOL)hasReward;
// 显示 我的 tab 显示新用户大礼包动画；用于测试
- (void)showNewbieGiftGuide;
// 隐藏 我的 tab 显示新用户大礼包动画；用于测试
- (void)hideNewbieGiftGuide;
// 开始加载
- (void)startLoad;

// 以下增删改tab的方法通过 Dispatch Barrier 保证线程安全

// 重新加载某个tab的vc和对应的tabBarItem, 可以只更新tabBarItem
- (void)reloadTab:(NSString *)name;
- (void)reloadTab:(NSString *)name withController:(BOOL)withController;

// 插入或删除tab, 一定是tabItem/controller/tabBarItem一起更新
- (void)insertTab:(NSString *)name atIndex:(NSUInteger)index;
- (void)removeTab:(NSString *)name atIndex:(NSUInteger)index;

@end
