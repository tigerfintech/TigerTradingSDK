//
//  TBServiceManager.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define TBServiceIMP(ServiceName,Protocol) \
id<Protocol> ServiceName = [[TBServiceManager sharedInstance] createService:@protocol(Protocol)]

#define TBService(Protocol) \
(id<Protocol>)[[TBServiceManager sharedInstance] createService:@protocol(Protocol)]

#define TBServiceRespond(Protocol, selector) \
[[TBServiceManager sharedInstance] serviceRespondToSelector:@protocol(Protocol) selector:selector]


#define TBServiceRegister(Protocol,serviceClass) \
[[TBServiceManager sharedInstance] registerService:@protocol(Protocol) implClass:serviceClass]

@interface TBServiceManager : NSObject

@property (nonatomic, assign) BOOL enableException; // 当输入的内容有问题的时候 配置YES触发崩溃  NO不触发崩溃

+ (instancetype)sharedInstance;

//注册
- (void)loadServiceWithPlistConfigFilePath:(NSString *)plistPath;

- (void)registerService:(Protocol *)service implClass:(Class)implClass;

//获取
- (id)createService:(Protocol *)service;

/*
 * 判断某个Protocol是否实现了selector
 * @param service 自定义的某个service
 * @param aSelector 某个方法的selector
 */
- (BOOL)serviceRespondToSelector:(Protocol *)service selector:(SEL)aSelector;

@end

NS_ASSUME_NONNULL_END
