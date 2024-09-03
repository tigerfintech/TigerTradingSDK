//
//  TBToolsKitComponentService.h
//  Pods
//
//  Created by linbingjie on 2023/1/17.
//

#ifndef TBToolsKitComponentService_h
#define TBToolsKitComponentService_h

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBToolsKitComponentService <NSObject>

- (NSString *)tbTools_getUserDefaultKey:(NSString *)key;

/// setter方法（内部做了key的长度校验）
- (void)tbTools_setUserDefaultObject:(nullable id)object forKey:(NSString *)key;

/// 获取key对应的object
- (id)tbTools_getUserDefaultObjectForKey:(NSString *)key
                            defaultValue:(nullable id)value;

/// track方法
/// - Parameters:
///   - event: 事件
///   - propertieDict: 参数
///   - extraMessage: 额外信息
- (void)tbTools_track:(NSString *)event
       withProperties:(NSDictionary *)propertieDict
         extraMessage:(nullable NSDictionary *)extraMessage;

/// 获取topVC
/// 底层组件之间无依赖时候可以使用这个
- (UIViewController *)tbTools_getTopVC;

- (void)tbTools_saveLastPageString:(NSString *)pageString;

/// 获取viewController对应的page值
/// @param viewController 要获取的目标VC
- (NSString *)tbTools_pageStringForViewController:(UIViewController *)viewController;

- (NSString *)tbTools_arriveFromStringForViewController:(UIViewController *)viewController;

/// 归档与解档
- (void)tbTools_archiveObject:(id)object forKey:(NSString *)key;
- (id)tbTools_unarchiveObjectForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END

#endif /* TBToolsKitComponentService_h */
