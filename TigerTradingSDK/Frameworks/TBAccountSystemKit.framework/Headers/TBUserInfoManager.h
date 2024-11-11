//
//  TBUserInfoManager.h
//  TBAccountSystemKit
//
//  Created by 骆鹏飞 on 2021/4/25.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>
#import "TBOAuthStatusModel.h"
#import "TBAuthUserInfoModel.h"
#import "TBCustomerAccountProcessModel.h"
#import "TBAuthAccountStatusInfoModel.h"
#import <TBAccountSystemKit/TBOpenAccountCustomerProfileModel.h>
#import "TBCDPStatusModel.h"
@import ReactiveObjC;

#pragma mark - Omnibus
#define OMNIBUS     [TBUserInfoManager isOmnibusTrade]

#pragma mark - IB
#define IBTrade              [TBUserInfoManager isIBTrade]

#pragma mark - ND
#define NDTrade              [TBUserInfoManager currentAccountIsND]

#pragma mark - Virtual
#define VIRTUALTRADE        [TBUserInfoManager isVirtualTradeAccount]

#pragma mark - Contra
#define TBCurrentAccountIsContra        [[TBUserInfoManager sharedInstance] currentAccountIsContra]

NS_ASSUME_NONNULL_BEGIN

// 未开户或正在开户
extern NSString * const TBOpenAcountStatusUnaccount;
// 开户
extern NSString * const TBOpenAcountStatusOpened;
// 入金
extern NSString * const TBOpenAcountStatusFunded;

// 开通Contra账户
extern NSString * const kTBAccountNatureContraAccount;


@class TBAuthAccountPermissionDataModel;
@class TBAuthAccountStatusInfoModel;
@class TBCustomerProfileDataModel;
@class TBCustomerAccountInfoDataModel;
@class TBAccountUpgradeMarginDataModel;


@interface TBUserInfoManager : NSObject

DECLARE_SHARED_INSTANCE(TBUserInfoManager)

/*
 * 个人账户信息相关
 * 来源:
 * 1、api/v2/account/status
 * 2、api/v1/individual/account/info 接口+1结果merge
 * 3、读取缓存：USER_DEFAULT_USER_DATA
 * 使用比较广泛
 */
//TODO TBKiwi 待删除： 现在还剩TBToolsKit库中有一处调用
@property (nonatomic, strong) TBOAuthStatusModel *_Nullable statusModel;

@property (nonatomic, strong) TBAuthAccountPermissionDataModel *accountPermissionModel;

/*
 * 个人账户信息相关
 * 来源:
 * 1、api/v3/account/status
 * 2、读取缓存：通过TBKeyedArchiverManager，key： TBAccountStatusDataArchiveKey
 */
@property (nonatomic, strong, nullable) TBAuthAccountStatusInfoModel *statusModel_V3; // 账户状态model

@property (nonatomic, strong, nullable) TBCustomerProfileDataModel *customerProfileModel; // 基本资料
@property (nonatomic, strong, nullable) TBOpenAccountVerificationStatusModel *verificationStatusModel; // 个人信息验证状态
@property (nonatomic, copy) NSDictionary *customerInfo; // 开户资料, 暂时没用到, 取姓名用customerProfileModel
@property (nonatomic, strong, nullable) TBCustomerAccountInfoDataModel *accountInfoModel; // 账户信息
@property (nonatomic, strong, nullable) TBCustomerAccountProcessDataModel *accountProcessModel; // 当前账户开户进度, 以当前customerId为key查询accountProcessModels

@property (nonatomic, readonly) RACSignal<TBCDPStatusModel *> *cdpStatusSignal; // cdp是否开通等信息

/*
 * 个人信息相关
 * 来源：api/v1/user/info
 * 使用属性：uuid,phone,email, emailActive
 */
@property (nonatomic, strong) TBAuthUserInfoModel *_Nullable userInfoModel;

@property (nonatomic, copy) NSDictionary *permissionLinks; // 开通权限链接集合
@property (nonatomic, copy) NSString *marginLink; // 开通margin链接

@property (nonatomic, copy) NSString *depositLink; // 入金链接（目前只有TradeUP使用）
@property (nonatomic, copy) NSString *withdrawLink;//出金链接(TradeUp使用)

// 开户进度model, 因为存在查看其它账户进度的场景, 所以以customerId为key保存为字典
@property (nonatomic, strong, nullable) NSMutableDictionary *accountProcessModels;

// 增加一个get/set对应账户的开户进度model的方法
- (TBCustomerAccountProcessDataModel *)accountProcessModelForCustomer:(NSString *)customerId;
- (void)setAccountProcessModel:(TBCustomerAccountProcessDataModel *)accountProcessModel forCustomer:(NSString *)customerId;


@property (nonatomic, assign) BOOL hasTradePassword;

/// 是否有交易密码，忽略入金判断
- (BOOL)hasTradePasswordIgnoringDepositCheck;

/// 是否做过行情问卷
@property (nonatomic, assign) BOOL doQuestionnaire;
/// 是否是专业用户
@property (nonatomic, assign) BOOL isProfessional;
@property (nonatomic, assign) BOOL isShouldDoQuestionnaire;

// TODO: 这四个方法替换成新方法
+ (BOOL)isIBTrade; // TODO: ib是fd+nd, 且tradeup另有一套
+ (BOOL)isOmnibusTrade; // TODO: 这个方法表示bs+vir类型, 所以有很多omnibus && !vir的判断, 需要改成新方法, 工作量估计比较大

/**
 * 是否是综合账户 （TT同isOmnibusTrade，TUP通过clearing判断）
 * TUP 中判断非当前账户是否是OMNI账户，需要通过clearing属性判断
 * 这里带入参数用来判断非当前账户是否是OMNI(marsco)账户
 */
+ (BOOL)isOmnibusTradeWithClearing:(NSString *)clearing;

+ (BOOL)isVirtualTradeAccount; // TODO: 有两个地方在用旧方法, 要跟着改
+ (BOOL)isNDTrade; // TODO: TBToolsKit在用, 需要一起改成新类型

/// 上手是否有碎股交易能力
@property (nonatomic, assign, class) BOOL hasFractionalShareAbility;

@property (nonatomic, assign, class) BOOL hasUSBtcETFAbility;

@property (nonatomic, assign, class) BOOL hasHKBtcETFAbility;

/// 定投能力
@property (nonatomic, assign, class) BOOL hasRsp;

/// Syep入口是否可见
@property (nonatomic, assign, class) BOOL hasSyepAbility;

/// 期权组合权限
@property (nonatomic, assign, class) BOOL optionComboAbility;

/// 组合期权
@property (nonatomic, assign, class) BOOL optionMultiLegsAbility;

/// 4腿期权
@property (nonatomic, assign, class) BOOL optionFourLegsAbility;

/*
 * 当前账户是否支持国债能力，主要根据牌照、账户类型、App类型等，主要用于一些入口显示与否逻辑
 * 注意这里不是权限判断，当前账户是否存在国债交易权限通过TBStockPermissionManager里的treasuryTradeAble判断
 */
+ (BOOL)treasuryAbility;

//权限
+ (BOOL)hasStockTradePermission;

// 是否要跳转个人信息验证
+ (BOOL)needJumpPersonalInformationVerification;

+ (BOOL)hasOpenOmnibusPermission;

- (void)cleanStautsModel;

/**
获取用户fd，nd是否能够cash升级margin
 */

- (void)getGlobalAccountUpgradeMarginWithSuccess:(void(^)(TBAccountUpgradeMarginDataModel *model))success
                                         failure:(void(^)(NSError *error))failure;

/**
 获取fd,nd跳转开通期权交易交易链接
 */

+ (NSString *)getGlobalAccountOpenOptionsWebLink;

/// 获取开通碎股交易权限连接权限
+ (NSString *)omniAccountOpenFracShareWebLink;

/// 开通澳洲交易权限链接
//+ (NSString *)omniAccountOpenAustraliaTradeWebLink;
/**
获取fd,nd跳转开通期货交易交易链接
*/
+ (NSString *)getGlobalAccountOpenFuturesWebLink;

/// 获取开通权限链接，目前支持期货、期权；
/// 如果需要添加新的权限类型，请在实现map里添加对应的类型及key
/// @{SEC_TYPE_FUT: @"fut",SEC_TYPE_OPT: @"opt",}
/// @param secType secType description
+ (NSString *)globalAccountOpenWebLink:(NSString *)secType;

/**
 获取fd,nd跳转升级保证金账户链接
 */

+ (NSString *)getGlobalAccountUpgradeMarginWebLink;


+ (void)gotoOpenAccountProcessFromWebForStockPermission;

/*
 如果说要统一的话，可以按照这个风格 https://www.tigersecurities.com/accounts/capability/{customerId}/{type}/{subtype}
 customerId为用户的customerid，type具体指是哪个大权限类型，subtype为子权限类型(该字段可以没有，比如说otc是个大的权限，otc还会分很多子类别)。
 上面这种链接来说，从长远来看，扩展性最强。 但是实际上也会遇到一些问题，就是比如说如果脱离用户信息，直接写出对应的业务链接就不可能了，因为带有customerid。之前有发邮件需求以及帮助中心直接放了链接，所以带有customerid被排斥。所以需要相关的地方做个配合升级。

 比如说修改后，
 期权链接是  https://www.tigersecurities.com/accounts/capability/123123123/perm/opt
 otc的美股交易 是  https://www.tigersecrities.com/accounts/capability/12312312/otc/us-stock
 */
/// 新规则连接开通地址（内部兼容旧版本）
/// @param permission 为具permissions里面的权限
+ (NSString *)accountOpenPermisson:(NSString *)permission;

/**
 * 根据secType获取风测或知识测评url
 * @param secType secType
 * @param isKnowledgeTest 是否是知识测评
 */
+ (NSString *)riskAssessmentUrlPath:(NSString *)secType isKnowledgeTest:(BOOL)isKnowledgeTest;

+ (NSString *)getSyepOpenWebLink;

+ (NSString *)getSyepCloseWebLink;

/// 当前账户是否入金
+ (BOOL)currentAccountDeposited;

@end


/// 用户开户相关状态
@interface TBUserInfoManager (TBAccountOpenStatus)

/**
 模拟盘获取账户开户状态

 @return 实盘账户开户状态
 */
+ (NSString *)accountOpenStatus;
/**
 模拟盘开户状态标题

 @return 模拟盘开户状态标题
 */
+ (NSString *)openAccountDotOpenStatusTitle;

//是否开户（包括开户入金注销）
+ (BOOL)ibOpened;
+ (BOOL)omnibusOpened;

// IB或者综合是否入金
+ (BOOL)ibDeposited;
+ (BOOL)omnibusDeposited;
/// 当前账号是否入金
+ (BOOL)deposited;

/**
 两个账户是否已经开户

 @return 两个账户是否已经开户
 */
+ (BOOL)bothAccountHasOpened;


/// 请求用户是否为专业用户
+ (void)fetchUserAccountProfessional;

- (void)unsubscribeDeviceKickedOut;

@end


/*
 整理未涉及属性或方法
 /// 上手是否有碎股交易能力
 @property (nonatomic, assign, class) BOOL hasFractionalShareAbility;
 // 根据需要请求用户信息（比如上次请求失败需要重试）
 - (void)requestUserInfoDataIfNeeded;

 
 新增：
 @property (nonatomic, copy) NSDictionary *permissionLinks; // 开通权限链接集合
 @property (nonatomic, copy) NSString *marginLink; // 开通margin链接

 */

NS_ASSUME_NONNULL_END
