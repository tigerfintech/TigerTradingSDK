//
//  TBVerifyDefines.h
//  Pods
//
//  Created by chenxin on 2021/8/26.
//

#ifndef TBVerifyDefines_h
#define TBVerifyDefines_h

// 验证方式
typedef NS_ENUM(NSUInteger, TBVerifyMethodType) {
    TBVerifyMethodTypeNone,
    TBVerifyMethodTypeOTP,
    TBVerifyMethodTypeSMS,
    TBVerifyMethodTypeEmail,
};

// 验证场景
typedef NS_ENUM(NSUInteger, TBVerifyProcessType) {
    TBVerifyProcessTypeNone,
    TBVerifyProcessTypeSignup,
    TBVerifyProcessTypeFastSignin,
    TBVerifyProcessTypeModifyPhone,
    TBVerifyProcessTypeModifyEmail,
    TBVerifyProcessTypeModifyLoginPassword,
    TBVerifyProcessTypeModifyTradePassword,
    TBVerifyProcessTypeResetLoginPassword,
    TBVerifyProcessTypeResetTradePassword,
    TBVerifyProcessTypeBindPhone,
    TBVerifyProcessTypeBindEmail,
    TBVerifyProcessTypeAccountManage,
    TBVerifyProcessTypeInternalFundsTransfer,
    TBVerifyProcessTypeInternalPositionTransfer,
    TBVerifyProcessTypeWithdrawal,
    TBVerifyProcessTypeIPOSubscription, ///< IPO申购
    TBVerifyProcessTypeSnsBindUser, ///< 三方登录后，绑定手机、邮箱
    TBVerifyProcessTypeRealName, // 实名认证
};

#endif /* TBVerifyDefines_h */
