//
//  TBTwoFactorAuthPasswordViewController.h
//  Stock
//
//  Created by chenxin on 2021/12/7.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBTwoFactorAuthVerifyType) {
    TBTwoFactorAuthVerifyTypeDynamic,
    TBTwoFactorAuthVerifyTypeOpen,
    TBTwoFactorAuthVerifyTypeClose,
};

@interface TBTwoFactorAuthPasswordViewController : TBBaseViewController

@property (nonatomic, assign) TBTwoFactorAuthVerifyType verifyType;

@property (nonatomic, copy) NSString *titleString;
@property (nonatomic, copy) NSString *stepTitle;
@property (nonatomic, copy) NSString *message;

@property (nonatomic, copy) NSString *loginPassword;  // 登录密码，关闭时使用

@property (nonatomic, copy) NSString *linkCode; // 关闭两步验证时需要该字段（来源：h5签署协议页，会通过bridge回传linkCode，用于关闭接口）

@property (nonatomic, copy) void(^dynamicPasswordBlock)(NSString *password);

- (void)showDynamicErrorMessage:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
