//
//  TBUserInfoManager+AccountStatus.h
//  TBAccountSystemKit
//
//  Created by dulijun on 2021/7/26.
//

#import "TBUserInfoManager.h"
#import <TBAccountSystemKit/TBCustomerAccountInfoModel.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TBAccountStatusCondition) {
    TBAccountStatusConditionNone, // 没有一个满足条件
    TBAccountStatusConditionOne, // 至少有一个满足条件
    TBAccountStatusConditionTwo, // 至少有两个满足条件
    TBAccountStatusConditionAll // 全部满足条件
};

@interface TBUserInfoManager (AccountStatus)

#pragma mark - Permission

#pragma mark - AccountInfo/AccountList

+ (NSArray<id<TBAccountInfo>> *)actualAccountList;
+ (NSArray<id<TBAccountInfo>> *)virtualAccountList;

// customerId对应的实盘账户信息
+ (id<TBAccountInfo>)actualAccountInfoWithCustomerId:(NSString *)customerId;

// private: 特定类型/条件的accountList(实盘): license, status, accountType
// private: 特定类型/条件的accountList(实盘): [license, status, accountType, hasTradePermission]

+ (id<TBAccountInfo>)currentActualAccountInfo DEPRECATED_MSG_ATTRIBUTE("use instance method:- (id<TBAccountInfo>)currentActualAccountInfo");
- (id<TBAccountInfo>)currentActualAccountInfo;

+ (id<TBAccountInfo>)currentVirtualAccountInfo DEPRECATED_MSG_ATTRIBUTE("use instance method:- (id<TBAccountInfo>)currentVirtualAccountInfo");
- (id<TBAccountInfo>)currentVirtualAccountInfo;

+ (id<TBAccountInfo>)currentAccountInfo DEPRECATED_MSG_ATTRIBUTE("use instance method:- (id<TBAccountInfo>)currentAccountInfo");
- (id<TBAccountInfo>)currentAccountInfo;

// 当前账户属性, 对应 TBAccountInfo 协议
+ (NSString *)currentAccountLicense; // 实盘
+ (NSString *)currentAccountStatus; // 实盘
+ (NSString *)currentAccountCustomerId; // 实盘

/**
 * 获取当前账户的accountId，注意:已兼容TradeUP ibaccount，返回类型是NSString
 * 不一定是纯数字
 * @return 当前账户的accountId
 */
+ (NSString *)currentAccountAccountId; // 实盘+模拟
+ (NSString *)currentAccountAccountType; // 实盘
+ (BOOL)currentAccountDisplayed; // 模拟; 实盘认为总是返回YES
+ (BOOL)currentAccountHasTradePermission; // 实盘

//private
//+ (NSString *)account(accountid/customerid, property)
//+ (NSString *)account(account_type, property)

//license, 定义一组快捷方法 license==TBNZ/TBSG等

// 一组里有一个property==xxx的
// 一组里没有property==xxx
// 一组里全部property==xxx

// 实盘当前账户状态, 确认是实盘后再使用
+ (BOOL)currentAccountStatusIsUnaccount; // UNACCOUNT
+ (BOOL)currentAccountStatusIsOpened; // OPENED
+ (BOOL)currentAccountStatusIsFunded; // FUNDED
+ (BOOL)currentAccountStatusIsOpenedOrFunded; // OPENED+FUNDED

// 实盘各账户状态, 确认是实盘后再使用
// TODO: 未实现, 还没用到
//+ (BOOL)accountStatusIsUnaccount:(id<TBAccountInfo>)account; // UNACCOUNT
//+ (BOOL)accountStatusIsOpened:(id<TBAccountInfo>)account; // OPENED
//+ (BOOL)accountStatusIsFunded:(id<TBAccountInfo>)account; // FUNDED
//+ (BOOL)accountStatusHasOpened:(id<TBAccountInfo>)account; // OPENED+FUNDED

// 所有特定类型的账户未开户(UNACCOUNT)
+ (BOOL)allAccountsStatusUnaccount:(NSString *)accountType; // UNACCOUNT
// 所有特定类型的账户未入金(!FUNDED)
+ (BOOL)allAccountsStatusNotFunded:(NSString *)accountType; // FUNDED
// 所有特定类型的账户没有交易权限
// 或至少有一个特定类型的账户有交易权限
//+ (BOOL)allAccountsNoTradePermission:(NSString *)accountType;

+ (NSString *)currentCustomerId;

#pragma mark - Other Fields

//当前交易账户类型 ('fd'/'bs'/'nd'/'virtual')
+ (NSString *)currentAccountType DEPRECATED_MSG_ATTRIBUTE("use instance method:- (NSString *)currentAccountType");
- (NSString *)currentAccountType;

+ (BOOL)currentAccountIsFD;
+ (BOOL)currentAccountIsND;
+ (BOOL)currentAccountIsBS;

+ (BOOL)currentAccountIsVirtual DEPRECATED_MSG_ATTRIBUTE("use instance method:- (BOOL)currentAccountIsVirtual");
- (BOOL)currentAccountIsVirtual;

+ (BOOL)currentAccountIsLinkFA;
+ (NSString *)currentAccountAliasFA;
+ (TBAccountRelationType)currentAccountRelevanceRelation;
+ (BOOL)currentAccountRelevanceRelationIsCustomer;

+ (BOOL)currentAccountIsContra DEPRECATED_MSG_ATTRIBUTE("use instance method:- (BOOL)currentAccountIsContra or Macro:TBCurrentAccountIsContra");
- (BOOL)currentAccountIsContra;

//当前账户是否绑定CDP
- (BOOL)currentAccountIsCDP;

// 当前账户的accountNature
+ (NSString *)currentAccountNature;
// 接口返回的实盘账户列表中是否有Contra账户
+ (BOOL)hasContraAccount;
// 接口返回的Contra账户状态，值为nil（没有）；unaccount（提交审核）；opened或者funded
+ (NSString *)contraAccountStatus;
// Contra账户是否已入金
+ (BOOL)isContraAccountFunded;
// 是否能开Contra账户：availableAccounts包含contra_account
+ (BOOL)canOpenContraAccount;
// 是否可以展示Contra账户：hasContraAccount=YES或者canOpenContraAccount=YES
+ (BOOL)canShowContraAccount;

// 当前是机构账号
+ (BOOL)currentAccountIsInstitution;

// location

// hkQuoteType

// 是否签过ETF免责声明
+ (BOOL)signEtfDisclaimer;

// 是否显示虚拟账户占位
+ (BOOL)displayVirtualAccount;

#pragma mark - individual/account/info Fields

+ (NSString *)currentAccountCapabilities;
+ (BOOL)currentAccountIsCash;
+ (BOOL)currentAccountIsMargin;

// 返回值ib/nd/bs, 其中ib表示fd
+ (NSArray<NSString *> *)availableAccountTypes;

+ (NSArray<TBAvailableAccountModel *> *)availableAccounts;

+ (BOOL)BSisAvailable;

+ (NSString *)currentAccountRegion;

/**
 * 判断当前是否是一人多户(实盘)
 * TradeUP直接返回NO
 */
+ (BOOL)hasMulitpleOmnibusAccount;

#pragma mark -

//账户状态数据
+ (TBAuthAccountStatusInfoModel *)accountStatusInfo;

#pragma mark - TODO: 处理账户关闭状态
//当前账户的状态是否是注销
+(BOOL)currentAccountStatusIsClosed;

//当前账户是否审核中
+(BOOL)currentAccountStatusIsAuditing;

#pragma mark -

//邮箱是否激活
+ (BOOL)emailActive;

//电话国际区号
+ (NSString *)telephoneCode;

// 获取fd,nd跳转升级保证金账户链接
+ (NSString *)globalAccountUpgradeMarginWebLink;

//是否有账户满足给定的accountType和status
+ (BOOL)hasAccountWithAccountType:(NSString *)accountType fitStatus:(NSString *)status;

//当前账户是否满足 accountType 和 status
+ (BOOL)currentAccountIsAccountType:(NSString *)accountType status:(NSString *)status;

// 返回bs账户列表
+ (NSArray<id<TBAccountInfo>> *)bsAccounts;

// 返回bs账户列表
+ (NSArray<id<TBAccountInfo>> *)ibAccounts;
#pragma mark - 目前是提供给（个人中心，点击闲钱管家，要自动切bs账户时）

//是否有ib账户开户或入金
+ (BOOL)hasIBAccountOpened;

//是否有综合账户入金
+ (BOOL)hasIBAccountDeposited;

//是否有综合账户开户或入金
+ (BOOL)hasBsAccountOpened;

// 是否有综合账户入了金
+ (BOOL)hasBsAccountDeposited;

//是否有bs是处于审核中
+ (BOOL)hasBSAccountWithStatusAuditing;

//所有处于审核中的bs账户
+ (NSArray *)allBSAccountWithStatusAuditing;

// 以下两个方法互为取反
// 有任意实盘账号已开户或入金
+ (BOOL)atLeastOneAccountStatusIsOpenOrFunded;
// 所有账号未开户
+ (BOOL)allAccountsStatusIsUnaccount;

// 至少有两个实盘账户已开户或入金
+ (BOOL)atLeastTowAccountStatusIsOpenOrFunded;

+ (BOOL)noAccountStatusIsFunded;
+ (BOOL)atLeastOneAccountStatusIsFunded;
+ (BOOL)atLeastOneAccountStatusIsOpened;

// 只有一个入金账户, 不能切换
+ (BOOL)onlyOneAccountStatusIsFunded;

/// 判断实盘列表中是否有多个指定的账户类型（比如：判断是否有多个综合账户，如果有多个综合账户的时候，账户列表展示的时候综合账户后边要加accountId的后缀）
/// @param accountType 目标账户类型
+ (BOOL)atLeastTwoAccountTypeIsType:(NSString *)accountType;

// 是否所有账户类型为accountType 状态都是status
+ (BOOL)isAllAccountWithAccountType:(NSString *)accountType fitToStatus:(NSString *)status;
// 返回账户类型为accountType、状态都是status 的账户
+ (NSArray<id<TBAccountInfo>> *)actualAccountsWithAccountType:(NSString *)accountType status:(NSString *)status;

// 所有账户都没有customerId(可理解为所有账户 没有开户、且没有处于审核中)
+ (BOOL)allAccountCustomerIdIsNil;

// 是否有其他账户可以切换（包含模拟）
+ (BOOL)hasOtherAccountCouldSwitch;

#pragma mark - 账户状态数据持久化

/// 把账户状态数据缓存到本地
/// @param statusModel 账户状态相关数据
+ (void)saveToCacheWithAccountStatus:(TBAuthAccountStatusInfoModel *)statusModel;
/// 从本地缓存读取 账户状态数据
- (void)fetchAccountStatusFromCache;
//清除[TBUserInfoManager sharedInstance].statusModel_V3对应的缓存数据
+ (void)clearAccountStatusCache;

#pragma mark - individual/account/process 开户进度接口相关方法

+ (NSString *)accountProcessStatus;
+ (NSString *)accountProcessStatusButtonText;
+ (NSString *)accountProcessStatusLink;

+ (NSDictionary *)accountProcessMissingFiles;
+ (NSNumber *)accountProcessOpenType;
+ (NSString *)accountProcessIdType;

+ (id)accountProcessValueForKeyPath:(NSString *)keyPath;

#pragma mark - 当前在用的场景：TBAllAccountViewController, TBOpenAccountGuideViewController .是否需要展示默认实盘的信息（如果当前是模拟盘，并且实盘都没有入金，则要展示实盘的开户进度（引导开户/入金））
/// 是否需要展示默认实盘的信息（如果当前是模拟盘，并且实盘都没有入金，则要展示实盘的开户进度（引导开户/入金））
+ (BOOL)isNeedShowDefaultAccountProcess;

/// 当前为模拟盘，且有实盘账户未入金，应该显示哪个实盘账户的信息
+ (id<TBAccountInfo>)defaultActualAccountInfo;

@end

NS_ASSUME_NONNULL_END
