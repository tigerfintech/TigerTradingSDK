//
//  TBBaseViewController.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBNavigationBar.h"
#import "UIViewController+Navigation.h"
#import "TTHeader.h"
#import "TBNetworkStatusPromptView.h"

// 显示在 view 最上层的标记 tag，防止在 viewViewAppear 后被导航栏盖住
static NSInteger kTopViewTag = 9999;

/*
 网络状态变化时发通知，由当前页面发出，只针对当前页面。
 应该只在变正常和变不稳定两种状态时发出，断网由AFNetworkReachabilityManager负责
 */
extern NSString * const kTBNetworkStatusDidChangeNotification;
// 网络状态变化通知`userInfo`包含key为`kTBNetworkStatusNotificationStatusItem`的`NSNumber`对象，代表`TBNetworkStatusType`枚举值
extern NSString * const kTBNetworkStatusNotificationStatusItem;
// 网络状态条显示通知
extern NSString * const kTBNetworkStatusPromptDidShowNotification;
// 网络状态条隐藏通知
extern NSString * const kTBNetworkStatusPromptDidHideNotification;

@interface TBNavigationBarItem : UINavigationItem

@property (nonatomic, strong) UIColor *titleColor;

@end

@interface TBBaseViewController : UIViewController

@property (nonatomic, strong, readonly) UIButton *autoBackButton;


@property (nonatomic, strong) TBNavigationBar* tbNavigationBar;
@property (nonatomic, strong) UIView *statusBarBackgroundView;

// 是否应用模拟盘颜色，设为YES后，导航栏会使用模拟盘背景色，应在vc初始化方法中设置
@property (nonatomic, assign) BOOL applyVirtualAccountColorIfNeeded;

// 是否使用灰色nav颜色，设置为YES后，导航栏会使用灰色背景色。适配8.0中页面卡片带radius的情况
@property (nonatomic, assign) BOOL applyGrayNavColorIfNeeded;

//是否透明navigationbar
@property (nonatomic, assign) BOOL applyTransparentBarIfNeeded;

/// 子类可以设置navTitleColor （eg, applyTransparentBarIfNeeded == YES时，设置不同navTitle颜色）
@property (nonatomic, strong, nullable) UIColor *navTitleColor;
/// nav背景图，默认nil (外界带入), applyTransparentBarIfNeeded==YES时生效
@property (nonatomic, strong, nullable) UIImage *navBackgroundImage;
/// nav背景图View
@property (nonatomic, strong, readonly, nullable) UIImageView *navBackgroundImageView;

- (BOOL)hasTBNavigationBar;
- (CGFloat)tbNavigationBarHeight;
- (void)changeNavBarColor;

@property (nonatomic, readonly) TBNavigationBarItem *tbNavigationItem;
@property (nonatomic, assign) BOOL willDismiss;


/**
 *  临时保存push消息的内容. 放在.h供子类使用
 */
@property (nonatomic, copy) NSDictionary *remoteNotificationPayload;

- (UINavigationItem *)fetchNavigationItem;

- (void)changeAppColorStyle;

- (void)appLanguageDidChange;

- (void) setTitle:(NSString *)title withImage:(UIImage *)image;

/**
 截屏监听
 */
- (void)didReceivedScreenShotNotification:(NSNotification *)noti;

#pragma mark- 统计需求
// 页面物品ID
@property (nonatomic, assign) NSInteger pageId;
@property (nonatomic, copy) NSString *pageIdString;
// 来源页面ID
@property (nonatomic, assign) NSInteger referPage;
@property (nonatomic, copy) NSString *referPageString;
// 子页面ID
@property (nonatomic, assign) NSInteger subPage;
// 来源子页面ID
@property (nonatomic, assign) NSInteger referSubPage;
// 页面物品ID
@property (nonatomic, copy) NSString  * itemId;
// 是否统计显示过的数据
@property (nonatomic, assign) BOOL      enableReportShow;
// 已经查看过的项列表
@property (nonatomic, strong) NSMutableSet<NSString *>  * displayedSet;

@property (nonatomic, assign) BOOL      fromAD; //通过开屏广告打开

/// 用于神策数据, 从哪里打开当前页, arriveFrom有值优先使用, 无值再取referPage（注意：该arriveFrom埋点为appBehavior旧埋点方案，并且旧方案还在使用，所以该字段相关仍要保留、不做修改）
@property (nonatomic, copy) NSString *arriveFrom;

// 是否忽略 enterPage 统计事件（作为子页面时可以忽略）默认不忽略 return NO;
@property (nonatomic, assign) BOOL shouldIgnoreEnterPage;

- (void)reportWillDisplayCell:(id)object;

- (instancetype)initWithNavigatorURL:(NSURL *)URL query:(NSDictionary *)query;

#pragma mark - 神策统计的eventId

@property (nonatomic, copy) NSString *sa_eventId;

#pragma mark - 神策埋点 基本参数
@property (nonatomic, copy) NSString *saPage; //当前页面
@property (nonatomic, copy) NSString *saArriveFrom; //来源页面
// 当前页是否记录page，默认记录，某些容器vc需设置不记录
@property (nonatomic, assign) BOOL shouldRecordLastPage;

/*
 当VC作为A页面的来源页面时，A页面在取arriveFrom来源页面时 ，会用到该方法来返回来源页面对象。
 默认情况下，该值返回VC self本身，即该VC就是下个页面的arriveFrom页面；
 特殊情况，复杂页面（TBSegmentedPageViewController、TBContentBaseViewController）作为来源页面，如果arriveFrom想要找到的是子页面，要重写这个方法来返回对应的子页面
 */
- (UIViewController *)saTargetViewcontroller;

/**
 * 自动创建返回按钮的icon，默认使用common_back
 * 有的页面导航栏时黄色的返回按钮是黄色的
 */
- (UIImage *)backButtonImage;

#pragma mark - 网络状态

// 是否展示网络状态提示，默认不展示
@property (nonatomic, assign) BOOL shouldShowNetworkStatusPrompt;

// 网络状态提示条，需在子类中布局（因为可能会被swift类继承，如果父类用Mansory布局，子类用snp布局会有冲突）
@property (nonatomic, strong) TBNetworkStatusPromptView *networkStatusPromptView;

// 更新网络状态，子类重写更新布局，需调用父类方法
- (void)updateNetworkStatus;

- (BOOL)enableNetworkUnstableAutoCheck;

- (void)checkNetworkStabilityWithCompletion:(void(^)(BOOL isSuccess))completion;

@end




