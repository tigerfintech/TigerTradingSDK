//
//  TBCrossPlatformModel.h
//  Pods
//
//  Created by linbingjie on 2021/7/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// BEGIN - 以下string提供给 - (instancetype)initWithTargetAction:(nonnull NSString *)action params:(nullable NSDictionary *)params;的params去构造参数使用
// 预定义一些参数
// Action
static NSString *const kActionGOTO = @"kAction-GOTO"; // 跳转的action

// Params
static NSString *const kLink = @"kLinkUrl"; // 跳转传递的URL参数
static NSString *const kFromAD = @"kFromAD"; // RN fromAD参数
static NSString *const kFlutter_KEY_JumpAction = @"kFlutter_KEY_JumpAction"; // Flutter 触发对应跳转的事件的key

// END - 以上string提供给 - (instancetype)initWithTargetAction:(nonnull NSString *)action params:(nullable NSDictionary *)params;的params去构造参数使用


@interface TBCrossPlatformModel : NSObject

@property (nonatomic, copy, readonly) NSString *action;
@property (nonatomic, copy, readonly) NSDictionary *params;

/// 创建一个model供crossplatformservice触发
/// @param action 具体操作事件，在本类上面写个static定义一套action
/// @param params 参数
- (instancetype)initWithTargetAction:(nonnull NSString *)action params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
