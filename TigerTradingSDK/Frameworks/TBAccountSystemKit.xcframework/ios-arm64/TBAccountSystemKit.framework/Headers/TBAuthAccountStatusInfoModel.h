//
//  TBAuthAccountStatusInfoModel.h
//  Stock
//
//  Created by dulijun on 2021/7/8.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * TBAccountRelationType;
extern TBAccountRelationType const kTBAccountRelationTypeCustomer;     //DIY账户关联关系
extern TBAccountRelationType const kTBAccountRelationTypeClient;      //委托给FA账户关联关系

@protocol TBAccountInfo <NSObject>

@optional
- (NSString *)license; // TBNZ/TBSG等
- (NSString *)status; // 开户状态: UNACCOUNT(未开户), OPENED(开户), FUNDED(入金)
- (NSString *)cdpStatus;
- (void)setCdpStatus:(NSString *)cdpStatus;
- (NSString *)customerId; // 开户资料已提交后生成
- (NSString *)accountId; // 有交易权限后生成
- (NSString *)ibAccount; //IB 账户独有
- (NSString *)accountType; // fd/nd/bs/virtural
- (BOOL)isDisplayed; // 是否展示账户
- (BOOL)hasTradePermission; // 是否具有交易权限, 需要完成人脸/银行卡验证
- (BOOL)isLinkFA;
- (NSString *)accountAliasFA;
- (BOOL)isContraAccount;
- (NSString *)currentAccountNature;
- (BOOL)isLink;
- (TBAccountRelationType)relationType;

@end

/// 每个实盘账户model
@interface TBAuthAccountStatusActualItem : JSONModel <TBAccountInfo>

@property (nonatomic, copy) NSString *customerId;
@property (nonatomic, copy) NSString *accountId;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *accountType;
@property (nonatomic, copy) NSString *license;              // 牌照信息, 可空
@property (nonatomic, copy) NSString *ibAccount;            //IB 账户独有
@property (nonatomic, assign) BOOL isDisplayed;             //是否在账户列表展示
@property (nonatomic, assign) BOOL hasTradePermission;      // 是否支持基金超市、闲钱管家权限
@property (nonatomic, assign) BOOL isLinkFA;                //标识当前账户是否关联FA
@property (nonatomic, copy) NSString *accountAliasFA;       //FA 别名
@property (nonatomic, assign) BOOL isLink;                //是否关联了账号
@property (nonatomic, copy) TBAccountRelationType relationType;       //关联关系类型( CLIENT:委托给FA账户关联关系、CUSTOMER:DIY账户关联关系 ）

// Contra账户返回contra_account
@property (nonatomic, copy) NSString *accountNature;

@property (nonatomic, copy) NSString *cdpStatus;

@end

/// 每个虚拟盘账户model
@interface TBAuthAccountStatusVirtualItem : JSONModel <TBAccountInfo>

@property (nonatomic, copy) NSString *accountId;
@property (nonatomic, assign) BOOL isDisplayed;

@end

//所有实盘账户信息（列表、当前账户id）
@protocol TBAuthAccountStatusActualItem;
@interface TBAuthAccountStatusActualAccountModel : JSONModel

@property (nonatomic, copy) NSString *currentCustomerId;
@property (nonatomic, copy) NSArray <TBAuthAccountStatusActualItem>*accountList;

@end

//所有虚拟盘账户信息（列表、当前账户id）
@protocol TBAuthAccountStatusVirtualItem;
@interface TBAuthAccountStatusVirtualAccountModel : JSONModel

@property (nonatomic, copy) NSString *currentAccountId;
@property (nonatomic, copy) NSArray <TBAuthAccountStatusVirtualItem>*accountList;

@end


@interface TBAuthAccountStatusExternalModel : JSONModel

@property (nonatomic, strong) NSNumber *displayVirtualAccount;
@property (nonatomic, assign) BOOL signEtf;

@end


@protocol NSString;
@interface TBAuthAccountStatusDataInfoModel : JSONModel

@property (nonatomic, copy) NSArray <NSString>*tradePermission;
@property (nonatomic, copy) NSArray <NSString>*quotePermission;
@property (nonatomic, strong) TBAuthAccountStatusActualAccountModel *actualAccountInfo;
@property (nonatomic, strong) TBAuthAccountStatusVirtualAccountModel *virtualAccountInfo;
@property (nonatomic, copy) NSString *currentAccountType;//'fd'/'bs'/'nd'/'virtual'
@property (nonatomic, copy) NSString *location;
@property (nonatomic, copy) NSString *hkQuoteType; // 港股行情权限类型   枚举值: "unavailable", "buy", "coupon"

@property (nonatomic, copy) NSString *errorMessage;
@property (nonatomic, copy) NSString *errorDescription;
@property (nonatomic, assign) NSInteger errorCode;

@property (nonatomic, strong) TBAuthAccountStatusExternalModel *external;

@end

@interface TBAuthAccountStatusInfoModel : JSONModel

@property (nonatomic, strong) TBAuthAccountStatusDataInfoModel *dataModel;
@property (nonatomic, assign) BOOL isSucc;

//与给的statusInfo比较，所在账户是否是同一个账户
- (BOOL)isAccountEqualToAccountStatus:(TBAuthAccountStatusInfoModel *)statusInfo;

@end

NS_ASSUME_NONNULL_END
