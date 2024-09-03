//
//  TBModuleManager.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import "TBBaseUtility.h"
#import "TBModuleDelegate.h"

NS_ASSUME_NONNULL_BEGIN

//   modules的类名必须以TB开头LifeCycleModule结尾
@interface TBModuleManager : NSObject <UIApplicationDelegate, TBCustomModuleDelegate>

DECLARE_SHARED_INSTANCE(TBModuleManager);

// 须在+load方法中执行注册，否则会影响排序结果
+ (void)registerModuleClass:(NSString *)moduleClass
                     config:(NSDictionary *)initParams
                   priority:(NSInteger)priority;

/// 通过plist 获取配置文件
/// @param path 目标plist路径
- (void)loadModulesWithPlistConfigFilePath:(NSString *)path;


/// 添加实现TBModuleDelegate的对象到观察队列中
/// @param moduleObject 对象
/// @param params 参数
/// @param priority 优先级
- (void)addModuleObject:(id<TBModuleDelegate> __nonnull)moduleObject
                 params:(NSDictionary * __nullable)params
               priority:(NSNumber * __nullable)priority;

/// 从观察队列中移除对象
/// @param moduleObject 目标对象
- (void)removeModuleObject:(id<TBModuleDelegate> __nonnull)moduleObject;

- (NSArray<id<TBModuleDelegate>> *)allModules;

- (NSDictionary *)allComponentURLMap;

@end

NS_ASSUME_NONNULL_END
