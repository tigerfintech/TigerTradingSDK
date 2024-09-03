//
//  TBUserBehaviorManager.h
//  Pods
//
//  Created by linbingjie on 2021/5/20.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TBBaseViewController.h>
#import <TBToolsKit/TBSensorsAnalyticsData.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *kTrackTimerStart = @"kTrackTimerStart"; // 开始记录时间
static NSString *kTrackTimerEnd = @"kTrackTimerEnd"; // 停止记录时间
static NSString *kExtraMessage_Action = @"kExtraMessage_Action"; // 额外参数的action的key

@interface TBUserBehaviorManager : NSObject

+ (void)track:(NSString *)event withProperties:(NSDictionary *)propertieDict extraMessage:(nullable NSDictionary *)extraMessage;
+ (void)track:(NSString *)event withProperties:(NSDictionary *)propertieDict privateParameters:(nullable NSDictionary *)privateDict extraMessage:(nullable NSDictionary *)extraMessage;
+ (void)trackTimerStart:(NSString *)event;
+ (void)trackTimerEnd:(NSString *)event withProperties:(NSDictionary *)propertyDict;

#pragma mark - 新规则埋点：component、actionType、page、arriveFrom、自定义属性（_COMPONENT）。

/// 埋点上报 （所有参数都自行控制）
/// @param event 事件名称
/// @param component 埋点元素名称（比如按钮名称、页面名称）
/// @param actionType action类型
/// @param page 埋点所在页面名称
/// @param arriveFrom 埋点所在页面的来源页面（可以理解为上一个页面）
/// @param extraMessage 自定义信息
+ (void)trackWithEvent:(NSString *)event component:(NSString *)component actionType:(NSString *)actionType page:(nullable NSString *)page arriveFrom:(nullable NSString *)arriveFrom  extraMessage:(nullable NSDictionary *)extraMessage;

/// page View埋点上报
/// @param viewController 埋点所在页面的实例对象（会自动处理component，arriveFrom值）
/// @param extraMessage 自定义信息
+ (void)trackPageViewWithViewController:(UIViewController *)viewController extraMessage:(nullable NSDictionary *)extraMessage;

/// action埋点上报
/// @param component 埋点触发元素名称（如：按钮、页面）
/// @param actionType action类型
/// @param viewController 埋点所在页面的实例对象（内部会自动添加page）
/// @param extraMessage 自定义信息
+ (void)trackActionWithComponent:(NSString *)component actionType:(NSString *)actionType ViewController:(UIViewController *)viewController extraMessage:(nullable NSDictionary *)extraMessage;

/// 用户属性埋点
+ (void)setPeopleProfile:(NSString *)profile content:(id)content;

#pragma mark - 接入嘉略管理平台后使用的埋点方法（推荐用下边的方法，通过对象传递参数）
/// 上报埋点
/// - Parameters:
///   - event: 事件名称
///   - component: 埋点元素名称（比如按钮名称、页面名称）
///   - actionType: action类型
///   - page: 埋点所在页面名称
///   - arriveFrom: 埋点所在页面的来源页面（可以理解为上一个页面）
///   - trackSign: 埋点标识（嘉略平台埋点需求中复制）
///   - requirementId: 需求ID（从嘉略平台埋点需求中复制）
///   - extraMessage: 自定义额外信息
+ (void)trackWithEvent:(NSString *)event component:(NSString *)component actionType:(NSString *)actionType page:(nullable NSString *)page arriveFrom:(nullable NSString *)arriveFrom extraMessage:(nullable NSDictionary *)extraMessage trackSign:(NSString *)trackSign requirementId:(NSNumber *)requirementId;


#pragma mark - public 含嘉略管理参数，from916

/// 上报埋点，事件为action点击
/// @param block 在block内配置你需要上报的属性，如：component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventActionClickWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;


/// 上报埋点，事件为action输入
/// @param block 在block内配置你需要上报的属性，如：component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventActionInputWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;


/// 上报埋点，事件为action长按
/// @param block 在block内配置你需要上报的属性，如：component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventActionLongPressWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;


/// 上报埋点，事件为action leave_page离开页面（不会上报页面停留时间。如果需要上报页面停留时长，去使用TBBaseViewController的trackEventActionLeavePageWithDurationWithProperties方法）
/// @param block 在block内配置你需要上报的属性，如：component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventActionLeavePageWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;

/// 上报埋点，事件为action-滑动
/// @param block 在block内配置你需要上报的属性，如：component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventActionSlideWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;


/// 上报埋点，事件为page_view
/// @param block 在block内配置你需要上报的属性，如：component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventPageViewWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;


/// 添加曝光元素标记，对应view曝光后会自动上报数据
/// @param block 在block内配置你需要上报的属性，如：曝光view、component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventImpressionWithProperties:(void(^)(TBSAExposureData *data))block;


#pragma mark 统计事件时长（start、end方法要成对出现）

/// 事件开始统计
/// @param event 事件名
/// 返回值 开始统计事件的id，结束时要使用
+ (NSString *)trackEventActionStartWithEvent:(NSString *)event;

/// 事件结束统计
/// @param block 在block内配置你需要上报的属性，如：startTimer（必须，来源：start方法的返回值）、 component、page、arriveFrom、自定义属性（可选）、track_sign、requirement_id
+ (void)trackEventActionEndWithProperties:(void(^)(TBSensorsAnalyticsData *data))block;

@end

NS_ASSUME_NONNULL_END
