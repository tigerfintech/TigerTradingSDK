//
//  TBCustomModuleDelegate.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import "TBOperationsModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBCustomModuleDelegate <NSObject>

@optional

/**
 清除缓存
 */
- (void)tb_ClearCache;

// 各组件注册相应的 url 到 map 中
- (NSDictionary *)tb_componentURLMap;


/// 登录注册成功之后会触发的方法
/// @param model 参数
- (void)tb_operationsAfterLoginOrRegister:(TBOperationsModel *)model;

/// 清空用户数据
/// @param virtualAccountIncluded 模拟盘是否需要清空
/// @param clearAccountData 是否清空账户数据
- (void)tb_cleanUserDataIncludingVirtualAccount:(BOOL)virtualAccountIncluded clearAccountData:(BOOL)clearAccountData;

//退出登录
- (void)tb_logout;

@end

NS_ASSUME_NONNULL_END
