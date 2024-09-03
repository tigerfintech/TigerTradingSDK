//
//  TBTwoFactorAuthManager.h
//  Stock
//
//  Created by yangfan on 2018/7/17.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
#import "TBTwoFactorAuthKey.h"
#import <TBUIKit/TBNavigator.h>

@interface TBTwoFactorAuthManager : TBObject

+ (instancetype)manager;

@property (nonatomic, strong) TBTwoFactorAuthKey *tfaKey;

/*
 如果之前未开启相机权限，保存二维码时会提示去设置中更改，改了权限会导致应用退出
 再次进入无法跳到开启成功页继续保存，先本地保存一下状态，下次进入判断是否要跳转
 */
@property (nonatomic, assign) BOOL needSaveQRCode;

- (void)gotoOpenSuccessPage;

// 打开老虎令牌App，如果无法打开返回NO
+ (BOOL)openTigerToken;

// 关联老虎令牌，如果可以关联返回YES，否则返回NO
+ (BOOL)linkTigerTokenWithKey:(TBTwoFactorAuthKey *)tfaKey;

// 关联老虎令牌，使用otpauth形式的链接
+ (BOOL)linkTigerTokenWithUrl:(NSString *)url;

// 网页关联链接
- (NSString *)tfaWebURLString;

// 打开重新关联web页
+ (void)openRelinkWebPage;

#pragma mark - TUP
// 为了出入金打开两步验证
@property (nonatomic, assign) BOOL openForFund;
// 开启两步验证成功后跳转（比如出入金）
@property (nonatomic, strong) TTURLAction *successAction;

@end
