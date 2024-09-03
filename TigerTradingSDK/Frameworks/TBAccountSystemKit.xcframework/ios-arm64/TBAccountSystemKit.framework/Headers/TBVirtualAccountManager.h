//
//  TBVirtualAccountManager.h
//  Stock
//
//  Created by 马超 on 2017/12/26.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TBCustomerVirtualAccountModel.h"

@class TBCustomerVirtualAccountModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBVirtualAccountManager : NSObject

+ (instancetype)sharedManager;

@property (nonatomic, strong, readonly) TBCustomerAvailableVirtualAccountDataModel *accountsDataModel;

@property (nonatomic, readonly, strong) TBCustomerVirtualAccountModel *defaultAccount;
@property (nonatomic, readonly, assign) BOOL isVirtualAccountOpen;
@property (nonatomic, readonly, copy) NSString *defaultAccountId; // 默认模拟账户id
@property (nonatomic, readonly, copy) NSString *currentVirtualAccountId; // 当前模拟账户id

- (TBCustomerVirtualAccountModel *)virtualAccountWithId:(NSString *)accountId;

#pragma mark - 接口方法

/// 用户创建虚拟帐户
- (void)openVirtualAccountSuccess:(nullable void (^)(TBCustomerVirtualAccountModel *model))success failure:(nullable void (^)(NSString * _Nullable errorMessage))failure;
- (void)openVirtualAccountWithTemplate:(NSInteger)templateId success:(nullable void (^)(TBCustomerVirtualAccountModel *model))success failure:(nullable void (^)(NSString * _Nullable errorMessage))failure;

/// 用户重置虚拟帐户
- (void)resetVirtualAccountSuccess:(nullable void (^)(NSString *accountId))success failure:(nullable void (^)(NSString * _Nullable errorMessage))failure;

///  获取用户重置帐户历史记录
- (void)getResetHistorySuccess:(nullable void (^)(id responseObject))success
                       failure:(nullable void (^)(NSString * _Nullable errorMessage))failure;

/// 用户获取可以切换的虚拟帐户
- (void)getAvailableVirtualAccountSuccess:(nullable void (^)(TBCustomerAvailableVirtualAccountDataModel *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 切换虚拟帐户
/// POST {itiger}/api/v1/account/trade/set
/// https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=10878983
- (void)setVirtualTradeAccount:(NSString *)accountId success:(nullable void (^)(id responseObject))success failure:(nullable void (^)(id errorInfo, NSError *error))failure;

/// 过期账户确认(关闭虚拟账户)
- (void)expireDefaultVirtualAccountSuccess:(nullable void(^)(void))success failure:(nullable void(^)(NSString *errorMsg))failure;
- (void)expireVirtualAccount:(NSString *)accountId success:(nullable void(^)(void))success failure:(nullable void(^)(NSString *errorMsg))failure;

/// 激活并切换到模拟账户
/// @param success 成功的回调
/// @param failure 失败的回调
/// @param progress 进度文案提示
- (void)activateAndSwitchVirtualAccountSuccess:(dispatch_block_t)success failure:(void(^)(NSString *errorMsg))failure progress:(void(^)(NSString *progressTips))progress;


/// 模拟账户：升级现金账户到保证金账户，并切换对应的资产
- (void)upgradeAndSwitchVirtualAccountSuccess:(dispatch_block_t)success failure:(void(^)(NSString *errorMsg))failure progress:(void(^)(NSString *progressTips))progress;

#pragma mark -



#pragma mark -

// 模拟账户初始资产
@property (nonatomic, assign, readonly) NSInteger defaultTotalAsset;

// 默认模拟账户是否已经过期
@property (nonatomic, assign, readonly) BOOL defaultAccountExpired;

// 退出登录时要清除单例数据，否则游客登录进入还使用旧的数据
- (void)clearData;

/**
 通过account code获取当前的模拟盘名称

 @param code account code
 @return 通过account code获取当前的模拟盘名称
 */
- (NSString *)virtualAccountNameWithCode:(NSString *)code;

/**
 通过account code获取当前模拟盘是否支持期货交易
 
 @param code account code
 @return 通过account code是否支持期货交易
 */
- (BOOL)virtualAccountSupportFutureWithCode:(NSString *)code;

/**
 获取当前模拟盘是否支持标的市场交易

 @param market 市场
 @param secType 类型
 @param accountCode accountCode description
 @return return value description
 */
- (BOOL)isVirtualAccountTradableWithMarket:(NSString *)market secType:(NSString *)secType code:(NSString *)accountCode;
- (BOOL)isCurrentVirtualAccountTradableWithMarket:(NSString *)market secType:(NSString *)secType;


// 当前模拟账户是否可以重置资产
- (BOOL)isCurrentVirtualAccountResettable;

// 当前模拟账户是否可交易（炒股大赛比赛时间开始之前不可交易）
- (BOOL)isCurrentVirtualAccountTradable;

// 是否是默认账户，判断 defaultAccountId == currentVirtualAccountId
- (BOOL)isDefaultAccount;

/**
 过期账号的过期时间

 @param accountCode 可以为nil，为nil，取当前z模拟账号
 @return  过期账号的过期时间
 */
- (NSString *)currentVirtualAccountExpiredTime:(NSNumber *)accountCode;

// 当前模拟账户分析入口链接（炒股大赛用）
- (NSString *)currentVirtualAccountMyselfURLString;

// 当前模拟账户比赛入口链接（炒股大赛用）
- (NSString *)currentVirtualAccountRankURLString;

// 获取对应模拟账户的交易权限
- (NSArray *)virtualAccountTradePermissionWithAccountId:(NSString *)accountId;

- (TBCustomerVirtualAccountModel *)currentVirtualAccountInfo;

@end

NS_ASSUME_NONNULL_END
