//
//  TBShortcutsModel.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/9/15.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

typedef NS_ENUM(NSUInteger, TBAllAccountActionType) {
    TBAllAccountActionTypeDeposit,          // 存入资金
    TBAllAccountActionTypeTransferPrimeAccount,//转综合账户
    TBAllAccountActionTypeWithdraw,         // 提取资金
    TBAllAccountActionTypeExchange,         // 货币兑换
    TBAllAccountActionTypeDepositHistory,   // 出入金记录
    TBAllAccountActionTypeDividentHistory,  // 总分红记录
    TBAllAccountActionTypeIPO,              // 新股申购
    TBAllAccountActionTypeBank,             // 银行卡
    TBAllAccountActionTypeReset,            // 模拟账户重置资产
    TBAllAccountActionTypeOddlots,          // 碎股卖出
    TBAllAccountActionTypeOddlotsPermission,          // 碎股权限
    TBAllAccountActionTypeBill,             // 账单查询
    TBAllAccountActionTypeApply,            // 申请供股
    TBAllAccountActionTypeInterest,         // 应计利息
    TBAllAccountActionTypeAction,           // 公司行动
    TBAllAccountActionTypePositionTransfer, // 仓位转移
    TBAllAccountActionTypePledge,           // 质押融资
    TBAllAccountActionTypeBankAccount,      // 银行账户
    TBAllAccountActionTypePlaceOrder,       // 交易(下单)
    TBAllAccountActionTypeOrder,            // 订单
    TBAllAccountActionTypeAnalysis,         // 分析
    TBAllAccountActionTypeAccount,          // 账户
    TBAllAccountActionTypeMore,             // 更多
    TBAllAccountActionTypeTransferFunds,    // 资金划转
    TBAllAccountActionTypeLive,             // 实盘
    TBAllAccountActionTypeCollege,          // 学院
    TBAllAccountActionTypeAward,            // 奖励
    TBAllAccountActionTypeFund,             // 基金
    TBAllAccountActionTypeCashPlus,         // 闲钱管家
    TBAllAccountActionTypeChangeTradePwd,    // 修改交易密码
    TBAllAccountActionTypePI,    // 专业投资者
    TBAllAccountActionTypeAI,    // 合格投资者认证
    TBAllAccountActionTypeWI,    // 合格投资者认证
    TBAllAccountActionTypeFundingDetail,      // 资金明细
    TBAllAccountActionTypeAccountInfoSettings, //账户设置
    TBAllAccountActionTypeDailyBill,           //marsco日账单
    TBAllAccountActionTypeTrustedPerson,       //授信联系人
    TBAllAccountActionTypeTaxFile,             //税务文件,
    TBAllAccountActionTypeUpgradeToMargin,     //升级保证金账户
    TBAllAccountActionTypeTwoStepVerification,
    TBAllAccountActionTypeFaceID,
    TBAllAccountActionTypeTouchID,
    TBAllAccountActionTypeOptionApply,
    TBAllAccountActionTypeOptionUpgrade,      //TradeUP marsco 账号期权等级升级
    TBAllAccountActionTypeSYEP,  //股票收益计划
    TBAllAccountActionTypeOptionList,            // 期权榜单 - 907 修改为期权
    TBAllAccountActionTypeOpenAccount,            // 提示开户
    TBAllAccountActionTypeLiveDeposit,            // 提示入金
    TBAllAccountActionTypeStockList,            // 热门股单

    TBAllAccountActionTypeFundProfitDetail,     // 收益明细(基金)
    TBAllAccountActionTypeFundTradeRecords,     // 交易记录(基金)
    TBAllAccountActionTypeFundMyRSP,            // 我的定投(基金)
    TBAllAccountActionTypeFundGoalPlan,         // 目标计划(基金)
    TBAllAccountActionTypeFundBuyingPowerIntro, // 购买力介绍 H5(基金)
    TBAllAccountActionTypeOrderApproval,        // 综合账户FA订单审批
    TBAllAccountActionTypeAccountAnalysis,      // 盈亏分析-账户分析
    TBAllAccountActionTypeStockPNLList,         // 盈亏分析-个股盈亏列表
    TBAllAccountActionTypeStockRSP,             // 股票定投
    TBAllAccountActionTypeStockWatchList,       // 行情-自选列表
    TBAllAccountActionTypeOptionPricingPlan,    // 期权阶梯收费入口
    TBAllAccountActionTypeFeeStructure,         // 费率结构
    TBAllAccountActionTypeTrade,                // lite 版 交易
    TBAllAccountActionTypeTransferBetweenAccount, // bs 账户间转账 https://tigertech.feishu.cn/wiki/wikcnbuIkSF1qSfol2yK1K0f7Ac
    TBAllAccountActionTypeFundRisk,             // 风险等级
    TBAllAccountActionTypeNotes,                // 票据
    TBAllAccountActionTypeNotesFCNKnowledgeTest,// 票据知识测评
    TBAllAccountActionTypeOptionExercise,       // 期权行权
    TBAllAccountActionTypeCreditLimit,          // 额度管理
    TBAllAccountActionTypeTradingSeason,          // 财报季
    TBAllAccountActionTypePortfolioRSP,          // 组合定投
};

typedef NS_ENUM(NSUInteger, TBAllAccountActionFromLocationType) {
    TBAllAccountActionFromLocationTypeAccount, ///< 账户页面
    TBAllAccountActionFromLocationTypeMore,    ///< 更多页面
    TBAllAccountActionFromLocationTypeTrade,   ///< 交易页面
    TBAllAccountActionFromLocationTypePortfolioLite,    ///< Lite持仓页
    TBAllAccountActionFromLocationTypePortfolioPro,    ///< Pro持仓页
    TBAllAccountActionFromLocationTypeHomePageShortcuts,    ///< 首页快捷功能模块
    TBAllAccountActionFromLocationTypeSearch,    ///< 搜索
};

NS_ASSUME_NONNULL_BEGIN


/**
 根据bff-name映射到tradeItem
 link: https://tigertech.feishu.cn/wiki/DDpWw4Y2ziQ3E1k6hGAcQzzenMb
 */
typedef NSString *TBPortfolioFunctionModuleProItemKey;

FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTrade;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOrder;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleProfitAndLoss;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleConvert;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTransactionCertificate;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAutoInvest;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleIPO;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleDeposit;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAccount;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleMoreFunction;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTransfer;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleIncomeDetail;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTradeRecord;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleMyAutoInvest;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTargetPlan;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleMaxPurchasingPower;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleRiskRanking;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTigerVault;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleWithdraw;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleStatements;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleSchool;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAcademy;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleHotList;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOptionList;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOpenAccount;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleActualDeposit;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleCompetition;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleNotes;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleFundsPnL;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleFunds;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleChangeTradingPassword;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleSyep;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModulePricingPlan;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleFeeStructure;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleBond;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleHKETF;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTradingSparks;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleMyFundsRsp;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOptTradingPermission;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleCurrencyExchange;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAccountTransfer;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleSharesTransferIn;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTransferHistory;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModulePledgeFinancing;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleBankAccount;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleFundDetails;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleCorporateActions;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAccuredInterest;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAnalysis;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleProInvestorCertification;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAccountSettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleAccInvestorCertification;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleFundsRsp;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleFractionalShares;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleDemoTrading;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleMarginTrading;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOddLotsSell;

FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleRiskRating;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleFCNTest;

FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleMarketDataStore;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleScreener;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOptionsChannel;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOptionsScreener;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleEarningsCalendar;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModulePrePostMarkets;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleMoverShakers;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleGlobalETF;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModulePriceAlert;

FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleThemeSettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleLangSettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleProLiteSettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleDefaultPage;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleHomeTabSettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTradeSettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleQuotesSettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleCommunitySettings;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleSecuritySettings;

FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTigerMembership;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleCampaignCenter;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleRewardsCenter;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTigerCoinsCenter;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleIdleCash;

// TradeUP
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTradeConfirmations;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOptTradingLv;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleUpgradeToMargin;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleDividendHistory;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTrustedContactPerson;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTaxDocuments;

// 环球账户独有配置
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTransferPrimeAccount;

// Contra
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleContraAccount; // Contra账户
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleCreditLimit; // 额度管理
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOutstandingPosition; // 待抵消持仓

/// FA-订单审批 (不在bff配置中）
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOrderApproval;
///link fa 用户 组合定投
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModulePortfolioRSP;

// DIGI (不在bff中）
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleDIGIDeposit;
FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleDIGIWithdraw;

FOUNDATION_EXPORT TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOptionExercise;

FOUNDATION_EXPORT  TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleOverNightMarkets;
FOUNDATION_EXPORT  TBPortfolioFunctionModuleProItemKey const kPortfolioFunctionModuleTradingSeason;

// 快捷功能
@interface TBShortcutsModel : JSONModel

@property (nonatomic, copy) NSString *imageName;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) TBAllAccountActionType actionType;

@end

NS_ASSUME_NONNULL_END
