//
//  TBWealthPermissionHelper.h
//  TBTradeBusinessBaseKit
//
//  Created by wind on 2023/11/2.
//

#import <Foundation/Foundation.h>
#import <TBBusinessSupportKit/TBShortcutsModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWealthPermissionHelper : NSObject

#pragma mark - common
/// 获取用户财富权限信息,
+ (void)fetchCustomerTradeCheckWithSuccess:(void(^)(NSDictionary *data))success failure:(void(^)( NSError * _Nullable error))failure;

#pragma mark - 基金

extern NSString * const kFundMallCheckListRisk;
extern NSString * const kFundMallCheckListCKA;

/// 跳转基金风测页面
+ (void)gotoFundRiskAssessmentWebView;

/// 跳转基金开户页面
+ (void)gotoOpenFundAccountWebView;

/// 获取用户是否需要做 CKA
+ (void)fetchCkaStatusWithSuccess:(void (^)(BOOL needCkaReview))success failure:(void(^)(NSString * _Nullable message))failure;

/// 用户跳转 CKA 页面，目前只有 TBSG 用户需要
+ (void)gotoCkaReviewWebView;

/// 获取用户风测等级
+ (void)fetchFundScore:(void(^)(NSNumber *score))success failure:(void(^)(NSString * _Nullable message))failure;

// 交易基金检查项列表
// check_list 检查列表, 其中 fund_mall_test 代表风险等级测评, cka 代表 cka 测评
+ (void)fetchFundMallCheckListWithSuccess:(void(^)(NSArray * _Nullable checkList))success failure:(void(^)(NSString * _Nullable message))failure;

// 检查是否可以做风测
+ (BOOL)checkRiskAuthCertification;

#pragma mark - 高净值理财
/// 用户 PI 认证判断
+ (void)checkCustomerIsPI:(void(^)(BOOL isPI))completion;

/// PI 认证
/// - Parameters:
///   - open: 是否自动跳转认证页
+ (void)checkCustomerIsPIAutoOpenCertificationWeb:(BOOL)autoOpen completion:(void(^)(BOOL isPI))completion;

/// 跳转 PI 认证页面
+ (void)gotoPICertificationWeb;

/// 用户 AI 认证判断
+ (void)checkCustomerIsAI:(void(^)(BOOL isAI))completion;
/// 用户 AI 认证判断
/// - Parameters:
///   - open: 是否自动跳转认证页
+ (void)checkCustomerIsAIAutoOpenCertificationWeb:(BOOL)autoOpen completion:(void(^)(BOOL isAI))completion;

/// 跳转 AI 认证页面
+ (void)gotoAICertificationWeb;

/// 用户 TFNZ WI(wholesale_investor) 认证判断
+ (void)checkCustomerIsWI:(void(^)(BOOL isWI, BOOL wasWI))completion;

/// PI AI Wi URL地址
+ (NSString *)investorCertificationPathWithType:(TBAllAccountActionType)type;

/// PI认证前检查，不支持机构认证. 个人认证返回YES，其他NO，并弹toast
+ (BOOL)checkPIAuthCertification;

#pragma mark - fcn

/// 跳转 FCN 知识测评页面
+ (void)gotoFCNKnowledgeTestWebView;

@end

NS_ASSUME_NONNULL_END
