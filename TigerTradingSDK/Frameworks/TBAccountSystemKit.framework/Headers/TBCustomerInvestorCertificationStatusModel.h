//
//  TBCustomerInvestorCertificationStatusModel.h
//  TBAccountSystemKit
//
//  Created by chenxin on 2023/8/30.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCustomerInvestorCertificationStatusModel : JSONModel

/* 认证类型
 investor: 合格投资人认证
 qi_investor：PRC 合格投资人认证
 pro_investor：专业投资人认证
 */
@property (nonatomic, copy) NSString *investorType;
/*
 状态
 UNSUBMIT    未提交
 PENDING    审核中
 REJECTED    已拒绝/被打回
 SUCCESS    认证成功
 EXPIRED    已过期
 */
@property (nonatomic, copy) NSString *status;
// 是否已认证
@property (nonatomic, assign) BOOL isCertified;
// 是否允许申请认证
@property (nonatomic, assign) BOOL allowApplication;

@end

NS_ASSUME_NONNULL_END
