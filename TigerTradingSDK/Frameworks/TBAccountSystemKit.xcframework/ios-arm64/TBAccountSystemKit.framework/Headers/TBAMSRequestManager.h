//
//  TBAMSRequestManager.h
//  Stock
//
//  Created by donggongfu on 2021/8/13.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

// model
#import <TBAccountSystemKit/TBAuthAccountPermissionModel.h> // for TBAuthAccountPermissionDataModel
#import <TBAccountSystemKit/TBOpenAccountCustomerProfileModel.h> // for TBCustomerProfileDataModel
#import <TBAccountSystemKit/TBCustomerAccountInfoModel.h> // for TBCustomerAccountInfoDataModel
#import <TBAccountSystemKit/TBCustomerAccountProcessModel.h> // for TBCustomerAccountProcessDataModel

NS_ASSUME_NONNULL_BEGIN

/// 业务层角度对AMS重要接口的封装. 简化参数, 保存数据, *请求后续操作*, 提供回调.
@interface TBAMSRequestManager : NSObject

DECLARE_SHARED_INSTANCE(TBAMSRequestManager)

#pragma mark - Auth

#pragma mark - Auth Tesseract

- (void)requestAccountPermissionSuccess:(nullable void (^)(TBAuthAccountPermissionDataModel *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 请求行情权限
/// @param success success description
/// @param failure failure description
- (void)requestQuotePermissionSuccess:(nullable void (^)(TBAuthAccountPermissionDataModel *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

#pragma mark - Customer

- (void)requestIndividualCustomerProfileSuccess:(nullable void (^)(TBCustomerProfileDataModel *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

// 未使用. app只用到资料中的姓名, 用customer/profile接口代替
- (void)requestIndividualCustomerInfoSuccess:(nullable void (^)(NSDictionary *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

- (void)requestIndividualAccountInfoSuccess:(nullable void (^)(TBCustomerAccountInfoDataModel * _Nullable model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

#pragma mark - 开户进度
/// 获取当前账户的开户进度
/// @param success 成功回调
/// @param failure 失败回调
- (void)requestIndividualAccountProcessSuccess:(nullable void (^)(TBCustomerAccountProcessDataModel * _Nonnull))success failure:(nullable void (^)(NSError * _Nullable))failure;
/// 获取账户的开户进度
/// @param accountType 账户类型 bs fd nd virtual
/// @param customerId 账户customerId
/// @param license 牌照（因为omnibus账户获取开户进度时，host需要特殊处理license信息）
/// @param telCode 电话区号（未开户时用于server判断开户跳web还是原生） 
/// @param success 成功回调
/// @param failure 失败回调
- (void)requestIndividualAccountProcessWithAccountType:(NSString *)accountType customerId:(NSString *)customerId  license:(NSString *)license success:(void (^)(TBCustomerAccountProcessDataModel * _Nonnull model))success failure:(void (^)(NSError * _Nullable error))failure;
- (void)requestIndividualAccountProcessWithAccountType:(NSString *)accountType
                                            customerId:(NSString *)customerId
                                               license:(NSString *)license
                                               telCode:(nullable NSString *)telCode
                                               success:(void (^)(TBCustomerAccountProcessDataModel * _Nonnull model))success
                                               failure:(void (^)(NSError * _Nullable error))failure;

@end

NS_ASSUME_NONNULL_END
