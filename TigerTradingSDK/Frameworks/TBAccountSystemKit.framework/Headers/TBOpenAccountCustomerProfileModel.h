//
//  TBOpenAccountCustomerProfileModel.h
//  Stock
//
//  Created by charming on 2019/8/23.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import "TBAuthBaseModel.h"


@class TBCustomerProfileDataModel;

@interface TBCustomerProfileModel : TBAuthBaseModel

@property (nonatomic, strong) TBCustomerProfileDataModel *data;

@end

@interface TBCustomerProfileDataModel : JSONModel

@property (nonatomic, copy) NSString *realName;
@property (nonatomic, copy) NSString *realNameEn;
@property (nonatomic, copy) NSString *firstName;
@property (nonatomic, copy) NSString *lastName;
@property (nonatomic, copy) NSString *middleInitial;

@end

@interface TBOpenAccountVerificationStatusModel : JSONModel

/*
 https://apidocs.tigerfintech.com/repository/1?branch=master&type=api&uri=apis%2Fweb%2FWeb接口.json#/operations/get--api-v1-verification-status
 xxx_status 状态枚举

 取值    说明
 -1    不需要做，不展示
 0    未提交
 1    审核中
 2    成功
 3    拒绝
 */
@property (nonatomic, strong) NSNumber *faceStatus; // 人脸校验状态
@property (nonatomic, strong) NSNumber *bankCardStatus; //银行卡验证状态
@property (nonatomic, strong) NSNumber *addressStatus; // 地址验证状态
@property (nonatomic, strong) NSNumber *verificationStatus; // 总状态

// 是否需要验证：verificationStatus != -1 && verificationStatus != 2
- (BOOL)needVerify;

@end


#pragma mark -

@interface TBOpenAccountSingpassInfoModel : JSONModel

@property (nonatomic, copy) NSString *real_name_en;
@property (nonatomic, copy) NSString *company;
@property (nonatomic, copy) NSString *marital_status;
@property (nonatomic, copy) NSString *home_postal;
@property (nonatomic, copy) NSString *real_name;
@property (nonatomic, copy) NSString *id_no;
@property (nonatomic, copy) NSString *birthday;
@property (nonatomic, copy) NSString *id_type;
@property (nonatomic, copy) NSString *home_address;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, assign) NSInteger gender;

@end
