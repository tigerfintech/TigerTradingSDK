//
//  TBAuthUserInfoModel.h
//  TBAccountSystemKit
//
//  Created by linbingjie on 2021/2/5.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAuthUserInfoModel : JSONModel

@property (nonatomic, strong) NSNumber *uuid;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *telCode;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, assign) BOOL emailActive;
@property (nonatomic, assign) BOOL hasTradePassword;
@property (nonatomic, copy) NSString *pid;
@property (nonatomic, copy) NSString *inviteCode;
@property (nonatomic, copy) NSString *signup_at;
@property (nonatomic, copy) NSString *uuidHash;

// 注销账号状态，"apply"/"revoking"/null.  申请中/撤销中/空
@property (nonatomic, copy) NSString *cancellationStatus;

@end

NS_ASSUME_NONNULL_END
