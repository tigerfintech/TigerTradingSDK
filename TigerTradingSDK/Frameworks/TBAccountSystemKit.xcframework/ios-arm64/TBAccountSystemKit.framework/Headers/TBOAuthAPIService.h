//
//  TBOAuthAPIServer.h
//  TBAccountSystemKit
//
//  Created by linbingjie on 2021/2/4.
//

#import <Foundation/Foundation.h>

#import "TBAuthUserInfoModel.h"
#import "TBAuthAccountPermissionModel.h"


NS_ASSUME_NONNULL_BEGIN

@interface TBOAuthAPIService : NSObject

/// 获取目标accesstoken用户的相关信息  api/v1/user/info
///
/// tiger trade:
/// 暂无使用
///
/// tradeup:
/// TUSOAuthManager   requestUserInfoWithAccessToken
///
/// @param accessToken 目标用户accesstoken
+ (void)getAuthUserInfoWithAccessToken:(NSString * __nullable)accessToken
                               success:(void (^)(TBAuthUserInfoModel *authUserInfoModel, id response))success
                               failure:(void (^)(NSError *error))failure;

/// 刷新token  api/v1/auth/refresh
/// 国内外项目都维护了一套接口没返回就不继续请求的逻辑，这部分需要业务自己去实现
///
/// tigertrade
/// TBUtils+User + (void)refreshToken:(UIViewController *)baseVC successed:(void(^)(BOOL success))successed
///
/// tradeup
/// TUSOAuthManager  refreshAccessToken
///
/// @param refreshToken 当前token
/// @param queue 是否需要放在queue里
///
+ (void)refershToken:(NSString *)refreshToken
         needInQueue:(nullable NSOperationQueue *)queue
             success:(void (^)(id response))success
             failure:(void (^)(NSError *error))failure;

// 获取免核身凭证ticket
+ (void)getAuthTicketWithCompletion:(void(^)(NSString * _Nullable ticket))completion;

@end

@interface TBOAuthAPIService (Tesseract)

+ (void)getAccountPermissionWithAccountType:(NSString *)accountType customerOrAccountId:(NSString *)customerOrAccountId success:(nullable void (^)(TBAuthAccountPermissionModel *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 请求行情权限，用户级别，与账户类型无关
/// @param success success description
/// @param failure failure description
+ (void)getAccountQuotePermission:(void (^)(TBAuthAccountPermissionModel * _Nonnull))success failure:(void (^)(NSError * _Nullable))failure;

@end

NS_ASSUME_NONNULL_END
