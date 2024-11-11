//
//  TBLoginManager.h
//  Stock
//
//  Created by liwt on 15/2/28.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBLoginAccountModel.h"
#import <TBBaseKit/TBBaseUtility.h>

@interface TBLoginManager : NSObject

@property (atomic, assign) BOOL isInLoginProcess;//已弹出登录页，在登录流程中
@property (atomic, assign) BOOL isLoginNow;
@property (atomic, assign) BOOL isRefreshNow;
@property (atomic, assign) BOOL hasInitTabBarVC;
@property (atomic, assign) BOOL agreementAgree;//登录注册页，是否已选同意协议
@property (atomic, assign) BOOL isAutoGuestLogin;// 是否是游客自动登录
@property (atomic, assign) BOOL shouldEnterOpenAccountOrThirdPartyBinding; // (登录注册之后)是否需要进入开户流程或者三方账号绑定流程
@property (atomic, assign) BOOL shouldTabBarChangetoOpenAccountTab; // (登录注册之后)是否tabbar要切到开户tab。（新注册用户需要）

DECLARE_SHARED_INSTANCE(TBLoginManager);

@property (nonatomic, strong, readonly) TBLoginAccountModel *currentLoginAccount;

- (NSArray<TBLoginAccountModel *> *)loginAccounts;

- (void)updateCurrentLoginAccountWithModel:(TBLoginAccountModel *)model;

- (void)removeLoginAccountWithIndexArray:(NSArray *)indexArray;

// 切换登录账号
- (void)switchToLoginAccount:(TBLoginAccountModel *)model
                     success:(void (^)(void))success
                     failure:(void (^)(NSString *errorMsg))failure;

- (void)fetchNewLoginAccountInfo;

// 刷新token
- (void)refreshTokenWithSuccess:(void (^)(BOOL isSucc))success
                        failure:(void (^)(NSError *error))failure;

// 检查accessToken有效期，在过期之前主动刷新
- (void)checkAccessTokenValid;

/// 是否支持游客模式登录 （915客户端去掉游客登录入口）
+ (BOOL)isGuestModeEnabled;

@end
