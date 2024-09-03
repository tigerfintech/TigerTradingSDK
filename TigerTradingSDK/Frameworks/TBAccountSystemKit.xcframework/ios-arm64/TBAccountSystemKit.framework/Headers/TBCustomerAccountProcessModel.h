//
//  TBCustomerAccountProcessModel.h
//  Stock
//
//  Created by charming on 2019/8/27.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBAuthBaseModel.h"

// TODO: 账户状态定义在哪?
// 账户开户详细状态
// 未开户
extern NSString * const TBAcountProcessStatusUnaccount;
// 修改资料
extern NSString * const TBAcountProcessStatusInvalid;
// 已开户
extern NSString * const TBAcountProcessStatusOpened;
// 已入金
extern NSString * const TBAcountProcessStatusFunded;
// 已注销
extern NSString * const TBAcountProcessStatusClosed;
// 继续开户
extern NSString * const TBAcountProcessStatusContinue;
// 人脸识别
extern NSString * const TBAcountProcessStatusFace;
// 激活中
extern NSString * const TBAcountProcessStatusActivating;
// 审核中
extern NSString * const TBAcountProcessStatusAuditing;

extern NSString * const kAcountProcessMissingPictureId; // 第一证件
extern NSString * const kAcountProcessMissingPictureId2; // 第二证件
extern NSString * const kAcountProcessMissingProofOfAddress; // 地址证明
extern NSString * const kAcountProcessMissingSignature; // 签名
extern NSString * const kAcountProcessMissingAddressVerification; // 地址验证
extern NSString * const kAcountProcessMissingPhoneVerification; // 手机验证
extern NSString * const kAcountProcessMissingBankCardVerification; // 银行卡验证
extern NSString * const kAcountProcessMissingFaceVerification; // 人脸验证

#pragma mark -

@class TBCustomerAccountProcessDataModel;

@interface TBCustomerAccountProcessModel : TBAuthBaseModel

@property (nonatomic, strong) TBCustomerAccountProcessDataModel *data;

@end


@class TBCustomerAccountProcessMaterialInfoModel;
@class TBCustomerAccountProcessStatusModel;
@class TBCustomerAccountProcessVerificationStatusMode;

@class TBCustomerAccountProcessMaterialInfoWrongModel;
@class TBCustomerAccountProcessVerificationStatusMode;

@interface TBCustomerAccountProcessDataModel : JSONModel

@property (nonatomic, strong) TBCustomerAccountProcessStatusModel *status; // 开户状态, 包含状态, 展示文本, 跳转链接等

/*
 缺失资料
 MISSING.TYPE 枚举值    说明
 PICTURE_ID    第一证件图
 PICTURE_ID2    第二证件图
 PROOF_OF_ADDRESS    地址证明
 SIGNATURE    签名
 ADDRESS_VERIFICATION    地址验证
 PHONE_VERIFICATION    手机验证
 BANKCARD_VERIFICATION    银行卡验证
 FACE_VERIFICATION    人脸验证
 */
@property (nonatomic, copy) NSArray *missing;

@property (nonatomic, strong) NSNumber *openType; // 打开类型, H5或Native. 0: 原生, 非0: H5.

@end


@interface TBCustomerAccountProcessMaterialInfoModel : JSONModel

@property (nonatomic, strong) TBCustomerAccountProcessMaterialInfoWrongModel *wrongBasicProfile;
@property (nonatomic, strong) TBCustomerAccountProcessMaterialInfoWrongModel *wrongAssets;
@property (nonatomic, strong) TBCustomerAccountProcessMaterialInfoWrongModel *wrongWorkProfile;
@property (nonatomic, strong) TBCustomerAccountProcessMaterialInfoWrongModel *wrongProof;

@end


@interface TBCustomerAccountProcessMaterialInfoWrongModel : JSONModel

@property (nonatomic, copy) NSArray *accountIssues;
@property (nonatomic, copy) NSArray *fields;
@property (nonatomic, copy) NSArray *descriptions;
@property (nonatomic, copy) NSDictionary *fieldDescriptionMap; // 以fields中的值为key, descriptions中的值为value, 可以代替fields和descriptions.

@end


@interface TBCustomerAccountProcessStatusModel : JSONModel

/// 开户状态
///
/// UNACCOUNT 未开户
///
/// CONTINUE 继续开户
///
/// FACE 人脸识别(数据库中未存储此状态)
///
/// AUDITING 审核中
///
/// INVALID 资料打回
///
/// OPENED 已经开户成功(未入金)
///
/// FUNDED 已入金
///
/// CLOSED 账户已注销
///
/// ACTIVATING 激活中
@property (nonatomic, copy) NSString *status;

@property (nonatomic, copy) NSString *buttonText;
@property (nonatomic, copy) NSString *hintText;
@property (nonatomic, strong) NSNumber *stepCode;
@property (nonatomic, strong) NSNumber *stepCurrent;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSArray *step;

/*
 TBHK 入金状态
 UNSUBMIT    未提交
 CONTINUE    金额不足
 SUCCESS    入金认证成功
 */
@property (nonatomic, copy) NSString *fundVerifyStatus;

@end


@interface TBCustomerAccountProcessVerificationStatusMode : JSONModel

/// 总验证状态. -1 无需, 0 未提交, 1 验证中, 2 通过, 3 拒绝
@property (nonatomic, strong) NSNumber *verificationStatus;

/// 手机验证状态. -1 无需, 0 未提交, 1 验证中, 2 通过, 3 拒绝
@property (nonatomic, strong) NSNumber *phone_status;

/// 人脸验证状态. -1 无需, 0 未提交, 1 验证中, 2 通过, 3 拒绝
@property (nonatomic, strong) NSNumber *face_status;

/// 银行卡验证状态. -1 无需, 0 未提交, 1 验证中, 2 通过, 3 拒绝
@property (nonatomic, strong) NSNumber *bank_card_status;

/// 人脸无效原因(暂未使用)
@property (nonatomic, copy) NSString *face_invalid_reason;

/// 银行卡无效原因(暂未使用)
@property (nonatomic, copy) NSString *bank_card_invalid_reason;

@end
