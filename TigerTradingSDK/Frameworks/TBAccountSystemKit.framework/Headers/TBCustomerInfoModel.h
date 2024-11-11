//
//  TBCustomerInfoModel.h
//  TBAccountSystemKit
//
//  Created by linbingjie on 2021/4/21.
//

#import <TBBaseKit/JSONModel.h>
#import "TBAuthBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCustomerInfoModel : TBAuthBaseModel

@property (nonatomic, copy) NSDictionary *data;

@end


@interface TBAuthUserSettingsModel : JSONModel

@property (nonatomic, assign) BOOL otpEnable;
@property (nonatomic, assign) BOOL setSecurityQuestion;
@property (nonatomic, assign) BOOL ibSignatureEnable;
@property (nonatomic, assign) BOOL needModifyPassword;

@end

NS_ASSUME_NONNULL_END
