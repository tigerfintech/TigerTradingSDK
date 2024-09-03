//
//  TBCustomerAccountInfoModel.h
//  TBAccountSystemKit
//
//  Created by linbingjie on 2021/4/21.
//

#import "TBAuthBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

@class TBCustomerAccountInfoDataModel;

@interface TBCustomerAccountInfoModel : TBAuthBaseModel

@property (nonatomic, strong) TBCustomerAccountInfoDataModel *data;

@end

@interface TBAvailableAccountModel : JSONModel

@property (nonatomic, copy) NSString *value; // 账户类型，比如bs
@property (nonatomic, copy) NSString *accountNature; // 账户用途，比如contra_account

// 以下字段目前没用
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *clearing;
@property (nonatomic, copy) NSString *license;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, assign) BOOL allowSingpass;

@end

@protocol TBAvailableAccountModel;

@interface TBCustomerAccountInfoDataModel : JSONModel

@property (nonatomic, copy) NSString *accountCapabilities; // CASH MARGIN
@property (nonatomic, copy) NSArray *availableAccountTypes; // 可开户列表，元素为string，例如"bs"
/*
 可开户列表，元素为dict
 {
    "name": '老虎综合账户',
    "value": 'bs',
    "clearing": '',
    "license": 'tbsg',
    "allow_singpass": allow_singpass,
    "source": source,
    "account_nature":'contra_account'// 账户用途
  }
 */
@property (nonatomic, copy) NSArray<TBAvailableAccountModel> *availableAccounts;

@property (nonatomic, copy) NSString *closeStatus; // 关闭账户状态 "PENDING"/"REVOKING"/"SUCCESS"/"REJECTED"/"REVOKE"/null. 申请中/撤销中/关闭成功/打回/撤销/空
@property (nonatomic, copy) NSString *region;

@property (nonatomic, copy) NSString *clearing; // 美国Marsco清算, clearing = marsco是marsco清算
@property (nonatomic, copy) NSString *ai_investor_status;

// 未使用 account_type = ib only
@property (nonatomic, copy) NSString *ib_username;
@property (nonatomic, copy) NSString *br_id; // marsco相关

//  category为Individual：个人，机构：STL, PropTrade, ESOP, FA, ET
@property (nonatomic, copy) NSString *category;

// hin - au账户用到
@property (nonatomic, copy)  NSString *hin;

// 国籍
@property (nonatomic, copy) NSString *country;

@end

NS_ASSUME_NONNULL_END
