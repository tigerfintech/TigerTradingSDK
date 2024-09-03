//
//  TBCustomerAPIManager.h
//  Stock
//
//  Created by charming on 2019/8/23.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBOpenAccountCustomerProfileModel.h"
#import "TBCustomerAccountProcessModel.h"
#import "TBCustomerInfoModel.h"
#import <TBAccountSystemKit/TBCustomerAccountInfoModel.h>
#import <TBAccountSystemKit/TBCustomerInvestorCertificationStatusModel.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBInvestorType;
extern TBInvestorType const kTBInvestorTypeAI;
extern TBInvestorType const kTBInvestorTypeQI;
extern TBInvestorType const kTBInvestorTypePI;
extern TBInvestorType const kTBInvestorTypeWI;

typedef NSString *TBInvestorStatus;
extern TBInvestorStatus const kTBInvestorStatusUnsubmit;
extern TBInvestorStatus const kTBInvestorStatusPending;
extern TBInvestorStatus const kTBInvestorStatusRejected;
extern TBInvestorStatus const kTBInvestorStatusSuccess;
extern TBInvestorStatus const kTBInvestorStatusExpired;
extern TBInvestorStatus const kTBInvestorStatusExited;

// 对应server 开户系统(Customer)
@interface TBCustomerAPIManager : NSObject

DECLARE_SHARED_INSTANCE(TBCustomerAPIManager)

// web有可能会跳转到原生的人脸识别界面，内存缓存web传过来的人脸验证下一步跳转的url。
@property (nonatomic, copy) NSString *faceVerifyResultUrl;

#pragma mark -

/// 获取客户开户资料
///
/// https://test-oauth.tigerfintech.com/ams/docs/Customer/index#req_5f34d71d2fe60b97e13caefe00000000
///
/// @note 未使用. app只用到资料中的姓名, 用customer/profile接口代替.
/// @param customerId customerId
/// @param success success
/// @param failure failure
- (void)getIndividualCustomerInfoWithId:(NSString *)customerId success:(nullable void (^)(TBCustomerInfoModel *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 获取用户基本资料
///
/// https://test-oauth.tigerfintech.com/ams/docs/Customer/index#req_5f33da3a2fe60b97e13caef000000000
///
/// @param customerId 开户受理过程中的ID
- (void)getIndividualCustomerProfileWithId:(nullable NSString *)customerId success:(nullable void (^)(TBCustomerProfileModel *model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 获取客户的账户信息
///
/// 账户信息是针对实盘的, 对模拟盘没意义, 模拟盘能用的只有available_account_types.
/// 但如果实盘没有customer_id, 对模拟盘请求该接口会返回错误, 此时不要给用户展示错误消息.
///
/// @param customerId 和accountId不能同时为空
/// @param accountId 和customerId不能同时为空
/// @param accountType 账户类型, 当通过accountId查询时需要
- (void)getIndividualAccountInfoWithCustomerId:(nullable NSString *)customerId accountId:(nullable NSString *)accountId type:(nullable NSString *)accountType success:(nullable void (^)(TBCustomerAccountInfoModel * _Nullable model))success failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 开户进度
/// https://test-oauth.tigerfintech.com/ams/docs/Customer/index?#req_c9ea67e2906b469f8214662d922c7881
/// 获取账户的开户进度 。（注意：omnibus账户获取开户进度时，host需要特殊处理license信息）
/// @param accountType 账户类型 bs fd nd virtual
/// @param customerId 账户customerId
/// @param license 牌照（只有是bs 时才需要）
/// @param telCode 电话区号（未开户时用于server判断开户跳web还是原生）
/// @param success 成功回调
/// @param failure 失败回调
- (void)getIndividualAccountProcessWithAccountType:(NSString *)accountType customerId:(NSString *)customerId license:(nullable NSString *)license success:(void (^)(TBCustomerAccountProcessModel *model))success failure:(void (^)(NSError *error))failure;
- (void)getIndividualAccountProcessWithAccountType:(NSString *)accountType customerId:(NSString *)customerId license:(nullable NSString *)license telCode:(nullable NSString *)telCode success:(void (^)(TBCustomerAccountProcessModel *model))success failure:(void (^)(NSError *error))failure;


#pragma mark -

/**
 获取用户人脸银行卡状态
 
 GET /api/v1/verification/status
 
 */
- (void)getCustomerVerificationStatusWithSuccess:(nullable void (^)(TBOpenAccountVerificationStatusModel *statusModel))success failure:(nullable void (^)(NSError *error))failure;

/*
 获取投资人认证状态
 customerId 客户id
 investorType  认证类型，多个以逗号分隔
                Allowed values:
                investor: 合格投资人认证
                qi_investor：PRC 合格投资人认证
                pro_investor：专业投资人认证
                wholesale_investor： TFNZ wholesale 认证
 */
- (void)getInvestorCertificationStatusWithCustomerId:(NSString *)customerId
                                       investorType:(NSString *)investorType
                                            success:(void (^)(NSArray<TBCustomerInvestorCertificationStatusModel *> *dataArray))success
                                            failure:(void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
