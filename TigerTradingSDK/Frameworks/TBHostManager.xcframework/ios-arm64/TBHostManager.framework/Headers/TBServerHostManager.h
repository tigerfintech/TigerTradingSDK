//
//  TBServerHostManager.h
//  Stock
//
//  Created by chenxin on 2020/6/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import "TBHostIdentifiers.h"

NS_ASSUME_NONNULL_BEGIN

/*
 用于管理测试包自定义配置host
 */
@interface TBServerHostManager : NSObject

DECLARE_SHARED_INSTANCE(TBServerHostManager)

/// 是否使用QA环境
/// TODO: 考虑放到其他类, 比如和IS_TEST_ENV放在一起
@property (nonatomic, assign) BOOL useQAServer;



// 服务器名列表
+ (NSArray *)serverNameList;

// 服务器名对应的host
- (NSString *)hostForServerName:(NSString *)name isTest:(BOOL)isTest;

/*
 服务器名对应的host
 license如果传值，获取指定license对应的host；如果不传，获取当前交易账户license对应的host
 */
- (NSString *)hostForServerName:(NSString *)name license:(nullable NSString *)license isTest:(BOOL)isTest;

// 域名配置接口请求成功后设置host列表
- (void)setupHostList:(BOOL)forced;

// 重置host列表为默认值，并保存到本地
- (void)resetHostList:(BOOL)isTest;

// 更新某个host为手动填写值
- (void)updateHost:(NSString *)host forServerName:(NSString *)name isTest:(BOOL)isTest;

// 保存host列表到本地
- (void)saveHostList:(BOOL)isTest;

/// 是否使用Omnibus新版的交易长连接, 目前包括资产和持仓, 代替之前的长连接
/// 用NSNumber表示3态, nil无数据, @YES使用, @NO不使用
/// 该属性属于用户设置, 临时保存在这里, 以后需要从接口和TBHostManager移出放入合适的地方
@property (nonatomic, strong) NSNumber *omnibusTradePush;

@end

NS_ASSUME_NONNULL_END
