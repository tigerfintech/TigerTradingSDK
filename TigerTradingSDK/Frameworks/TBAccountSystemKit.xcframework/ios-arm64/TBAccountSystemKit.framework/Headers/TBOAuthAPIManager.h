//
//  TBOAuthAPIManager.h
//  Stock
//
//  Created by 马超 on 2017/6/22.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBCustomerInfoModel.h"
#import "TBOauthBindingModel.h"
#import "TBAuthUserInfoModel.h"
#import "TBAuthAccountStatusInfoModel.h"
#import <TBBaseKit/TBBaseUtility.h>
#import "TBCDPStatusModel.h"
@class TBOauthBindingModel;

// 检查accessToken是否有效接口
extern NSString * const kAuthCheckAccessTokenPath;

// 请求device/init接口成功通知，userInfo为返回的data
extern NSString * const TBAuthDeviceInitSuccessNotification;

@interface TBOAuthAPIManager : NSObject

DECLARE_SHARED_INSTANCE(TBOAuthAPIManager)

- (void)sendAuthSmsWithContent:(NSString *)content
                       success:(void (^)(id responseObject))success
                       failure:(void (^)(NSError *error))failure;

@property (nonatomic, copy) NSString *needNDAgreement; // nd转户签约url path

@property (nonatomic, assign) BOOL needFaceVerification; // 部分老用户信息校验可能不完整，需要添加人脸验证

@property (nonatomic, assign) BOOL needBankCardVerification; // 部分老用户信息校验可能不完整，需要添加银行卡验证

@property (nonatomic, assign) BOOL needShowPrivacy; // 旧版本用户需要同意隐私协议， 否则不允许其使用app

@property (nonatomic, assign) BOOL needShowAppReview; // 弹出app store 系统评价弹窗
@property (nonatomic, assign) BOOL needShowOtpAlert; // 新加坡用户弹出引导两步验证弹窗

@property (nonatomic, copy) NSString *location; // 根据ip判断的地区code
@property (nonatomic, copy) NSString *locationName; // 根据ip判断的国家地区名称
@property (nonatomic, copy) NSString *notifyContent; // 提示框内容
@property (nonatomic, copy) NSString *guestSalt; // 游客登录盐值

@property (nonatomic, copy) NSString *permissionLink; // 开通权限链接
@property (nonatomic, copy) NSString *digitalCurrencyLink; // 开通数字货币交易权限链接
@property (nonatomic, copy) NSString *marginLink; // 开通margin链接
@property (nonatomic, copy) NSDictionary *permissionLinks; // 开通权限链接集合
@property (nonatomic, copy) NSString *faAccountOpenUrl; // 开通FA账户链接

@property (nonatomic, assign) BOOL enableRoute; // 是否需要检查auth路由

@end

@interface TBOAuthAPIManager (status)

- (BOOL)enableAdvisorPost;

// 检查accessToken是否有效，accessToken不传使用当前账户token
- (void)checkAccessToken:(NSString *)accessToken
                 success:(void (^)(BOOL isSucc, NSInteger errorCode, NSString *errorDescription))success
                 failure:(void (^)(NSError *error))failure;

- (void)getV3AccountStatusWithAccessToken:(NSString *)accessToken
                               isChecking:(BOOL)isChecking
                                  success:(void (^)(TBAuthAccountStatusInfoModel *statusInfo))success
                                  failure:(void (^)(id obj, NSError *error))failure;

@end

@interface TBOAuthAPIManager (sns_status)

/**
 手机号或邮箱的三方状态
 
 接口地址: GET {oauth}/api/v4/auth/sns/snsbind/status
 
 @param parameters 已登录状态可不传，通过token判断
 @param success success
 @param failure failure
 */
- (void)getSnsStatusWithParameters:(NSString *)parameters
                           success:(void(^)(TBOauthBindingModel *responseObject))success
                           failure:(void(^)(NSError *error))failure;


/**
 账户(手机，邮箱)绑定第三方

 @param parameter 参数（openid，access_token:三方回调的token，user_name:twitter绑定特有的参数）
 @param success success
 @param failure failure
 */
- (void)bindNormalAccountWithOauthOs:(NSString *)oauth_os
                           parameter:(NSString *)parameter
                             success:(void(^)(id responseObject))success
                             failure:(void(^)(id errorInfo, NSError *error))failure;


/**
 第三方解绑

 @param oauth_os 三方平台
 @param success success
 @param failure failure
 */
- (void)unbindSnsWithOauthOs:(NSString *)oauth_os
                     success:(void(^)(id responseObject))success
                     failure:(void(^)(id errorCode, NSError *error))failure;

/**
 获取设备初始化信息 [打开app时访问]

 @param success success
 @param failure failure
 */
- (void)getAuthDeviceInit:(void(^)(id data))success failure:(void(^)(id errorCode, NSError *error))failure;


/////////////////////// 以下为auth升级的部分接口

/*
 665版本接口升级
 以前api/v4/auth/status
 
 拆分为 api/v1/user/info ，
 api/v2/account/status，
 api/v1/account/permission，
 api/v1/individual/account/process，
 /api/v1/individual/account/info 五个接口
 
 */


/**
获取用户相关信息
 
GET /api/v1/user/info ， 包含phone， email等信息
 
*/

- (void)getAuthUserInfoWithSuccess:(void (^)(TBAuthUserInfoModel *authUserInfoModel))success
                           failure:(void (^)(NSError *error))failure;

/**
 
 账户状态， 此接口为server升级的最新接口
 
 地址: GET /api/v3/account/status
 参数: 获取状态只需要token放入header即可
 
 @param success success
 @param failure failure
 */
- (void)getV3AuthAccountStatusWithSuccess:(void (^)(TBAuthAccountStatusInfoModel *statusInfo))success
                                  failure:(void (^)(id obj, NSError *error))failure;



/**
 获取用户安全设置信息
 
 GET /api/v1/user/settings ， 替换 overall_ib_auth, user_ib_auth, trade_auth_type等旧字段
 
 */


- (void)getAuthUserSettingsWithSuccess:(void (^)(TBAuthUserSettingsModel *authUserSettingsModel))success
                           failure:(void (^)(NSError *error))failure;

// 获取当前用户的账户待办通知
- (void)getNotificationCustomerWithSuccess:(void (^)(NSArray *dataArray))success
                                   failure:(void (^)(NSError *error))failure;

// 获取账号CDP申请状态
- (NSURLSessionTask *)getAuthUserCDPStatusWithAccountId:(NSString *_Nullable)accountId
                                                success:(void (^_Nullable)(TBCDPStatusModel * _Nullable authUserInfoModel))success
                                                failure:(void (^_Nullable)(NSError * _Nullable error))failure;
@end

