//
//  Stock.h
//  TBBaseUtils
//
//  Created by zhengzhiwen on 2021/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSUInteger, TBStockQuotePromptType){
    TBStockQuotePromptTypeAStockNull, // A股无行情
    TBStockQuotePromptTypeAStockLV0, // A股不自动刷新行情
    TBStockQuotePromptTypeAStockLV1, // A股自动刷新行情
    TBStockQuotePromptTypeUKStockLv0, // 伦敦行情LV0
    TBStockQuotePromptTypeUKStockLv1, // 伦敦行情LV1
    TBStockQuotePromptTypeFuturesQuetoLV0, // 期货LV0
    TBStockQuotePromptTypeFuturesQuetoLV1, // 期货LV1
    TBStockQuotePromptTypeFuturesQuetoLV1Delay, // 期货LV1
    TBStockQuotePromptTypeFuturesQuetoLV1Limited, // 期货LV1抢占
    TBStockQuotePromptTypeFuturesQuetoLV1Plus, // 期货LV1 Plus
    TBStockQuotePromptTypeFuturesQuetoLV2, // 期货行情权限，从上向下依次对应：lv0,lv1,lv1+,lv2(应该没有)
    TBStockQuotePromptTypeFuturesQuetoLV2Limit,
    TBStockQuotePromptTypeHKStockLv0, // 港股LVO
    TBStockQuotePromptTypeHKStockLv1, // 港股LV1
    TBStockQuotePromptTypeSimpleHKStockLv2, // 港股Level2轻享版报价
    TBStockQuotePromptTypeHKStockLv2, // 港股LV2
    TBStockQuotePromptTypeHKStockLv2Limit, // 受限的港股LV2用户
    TBStockQuotePromptTypeHKStockLV2Down, // 多端登录受限LV2
    TBStockQuotePromptTypeHKOptionLv0, // 港股期权LVO
    TBStockQuotePromptTypeHKOptionLv1, // 港股期权LV1
    TBStockQuotePromptTypeHKOptionLv1Limit, // 港股期权LV受限
    TBStockQuotePromptTypeHKOptionLv2, // 港股期权Level2
    TBStockQuotePromptTypeHKOptionLv2Limit, // 港股期权LV2受限
    TBStockQuotePromptTypeUSStockLimited, // 受限美股LV2
    TBStockQuotePromptTypeUSStockLv0, // 美股LV0
    TBStockQuotePromptTypeUSStockLv1, // 美股LV1，注册用户即送LV1，即LVN1行情权限
    TBStockQuotePromptTypeUSStockLv1Plus, // 美股LV1+,入金客户
    TBStockQuotePromptTypeUSStockLv2Openbook, // 美股LV2Openbook
    TBStockQuotePromptTypeUSStockLv2Arca, // 美股LV2Arca
    TBStockQuotePromptTypeUSStockLv2Totalview, // 美股LV2Totalview
    TBStockQuotePromptTypeUSStockLv2ArcaLimited, // 美股LV2Arca多端登录
    TBStockQuotePromptTypeUSStockLv2TotalviewLimited, // 美股LV2Totalview多端登录
    TBStockQuotePromptTypeUSStockLv2BlueOcean, // 美股夜盘
    TBStockQuotePromptTypeUSOTCStockLv0, // 美股OTCLV0
    TBStockQuotePromptTypeUSOTCStockLv1, // 美股OTCLV1
    TBStockQuotePromptTypeUSOTCStockLv2, // 美股OTCLV2
    TBStockQuotePromptTypeUSStockOptionQuetoLV2Limited, // 期权LV2抢占
    TBStockQuotePromptTypeUSStockOptionQuetoLV1Limited, // 期权LV1抢占
    TBStockQuotePromptTypeOptionUnShortAble, // 期权不允许做空
    TBStockQuotePromptTypeUnableTrade,                  // 通用不可交易，区别于A股
    TBStockQuotePromptTypeUSStockOptionQuetoLV1, // 期权LV1
    TBStockQuotePromptTypeUSStockOptionQuetoLV2, //
    TBStockQuotePromptTypeAUStockLv0, // 澳大利亚行情LV0，手动刷新
    TBStockQuotePromptTypeAUStockLv2, // 澳大利亚行情LV2 高级行情
    TBStockQuotePromptTypeAUStockLv2Limit, // 澳大利亚行情LV2抢占
    TBStockQuotePromptTypeNZStockLv0, // 新西兰行情LV0，手动刷新
    TBStockQuotePromptTypeNZStockLv2, // 新西兰行情LV2 高级行情
    TBStockQuotePromptTypeSIStockLv1, // 新加坡行情LV1
    TBStockQuotePromptTypeSIStockLv1Delay, // 新加坡行情LV1延迟行情
    TBStockQuotePromptTypeSIStockLv2, // 新加坡行情LV2
    TBStockQuotePromptTypeSIStockLv2Limit, // 新加坡行情LV2抢占
    TBStockQuotePromptTypeDigitalCurrencyLv1,//数字货币lv1
    TBStockQuotePromptTypeDigitalCurrencyLv2,//数字货币lv2
    TBStockQuotePromptTypeCryptoCurrencyPI,     //加密货币PI only
    TBStockQuotePromptTypeUSStockUnShortAble, // 美股不允许做空提示
    TBStockQuotePromptTypeHKStockUnShortAble, // 港股不允许做空
    TBStockQuotePromptTypeBondUnShortAble, // 国债不允许做空
    TBStockQuotePromptTypeAStockUnShortAble,  // A股不允许做空
    TBStockQuotePromptTypeAStockIBTrade,      // 4.4 A股通，通过IB账号可进行交易
    TBStockQuotePromptTypeAStockIBSell,       // 4.4 A股通，通过IB账号卖出:有持仓，但是ib已经不支持买入
    TBStockQuotePromptTypeAStockIBUnableTrade, // 4.8 A股通，通过IB账号不可进行交易
    TBStockQuotePromptTypeStockSplit, // 拆股
    TBStockQuotePromptTypeStockJoin,   // 合股
    TBStockQuotePromptTypeShortMargin, // 融资融券提示
    TBStockQuotePromptTypeNone,
    TBStockQuotePromptTypeClosePosition, //只可平仓
    TBStockQuotePromptTypeTrade,         // 通用可交易，区别于A股
    TBStockQuotePromptTypeUSMarscoStockOptionLV1, // TUP marsco 牌照期权等级1
    TBStockQuotePromptTypeUSMarscoStockOptionLV2, // TUP marsco 牌照期权等级2
    TBStockQuotePromptTypeUSMarscoStockOptionLV3, // TUP marsco 牌照期权等级3
    TBStockQuotePromptTypeUSMarscoStockOptionLV4, // TUP marsco 牌照期权等级4
    TBStockQuotePromptTypeFractionalShare, // 碎股图标
    TBStockQuotePromptTypeContra, // contra图标
    TBStockQuotePromptTypeOvernight, // 夜盘图标
};


typedef NS_ENUM(NSInteger,TBTransferAccountsType) {
    TBTransferAccountsSecurityToFutures,       //!< 证券转期货
    TBTransferAccountsFuturesToSecurity,       //!< 期货转证券
};

typedef NS_ENUM(NSInteger,TBOmnibusCurrentAccountType) {
    TBOmnibusCurrentAccountTypeSecurity,        //!< 证券
    TBOmnibusCurrentAccountTypeFutures,         //!< 期货
    TBOmnibusCurrentAccountTypeDigitalCurrency, //!< 数字货币
    TBOmnibusCurrentAccountTypeFundMall,        //!< 基金超市
    TBOmnibusCurrentAccountTypeLinkFAFund,      //!< 综合账户关联FA独有
    TBOmnibusCurrentAccountTypeAggregated,      //!< 综合账户聚合类资产-首页使用
    TBOmnibusCurrentAccountTypePortfolio,       //!< 综合账户Portfoil
    TBOmnibusCurrentAccountTypeCFD,             //!< CFD
};

typedef NS_ENUM(NSInteger, TBSuccessType) {
    TBSuccessTypeExchange,     //!< 兑换
    TBSuccessTypePayBack,      //!< 一键还款
    TBSuccessTypeTransfer,     //!< 内部转账
};

typedef NS_ENUM(NSInteger, TBDoExerciseOriginalType) {
    TBDoExerciseOriginalTypeStockOption,            //!< 个股详情页进入
    TBDoExerciseOriginalTypeOptionDetail,           //!< 期权详情页进入
    TBDoExerciseOriginalTypeWarDetail,              //!< 窝轮详情页进入
    TBDoExerciseOriginalTypeStockOptionMakeOrder,   //!< 期权买入卖出进入
    TBDoExerciseOriginalTypeStockWarMakeOrder,      //!< 期权买入卖出进入
    TBDoExerciseOriginalTypeStockOptionMessage,     //!< 消息中心进入
};

typedef NS_ENUM(NSUInteger, TBDealWatchListItemType) {
    TBDealWatchListItemTypeADD = 0,
    TBDealWatchListItemTypeREMOVE
};

@interface TBStock : NSObject

+ (NSString *)getChineseNameWithMarket:(NSString *)market secType:(NSString *)secType;

// 是否在交易时间内
+ (BOOL)isWithinTradingHours:(NSString *)market;

+ (UIImage *)marketImageWithMarket:(NSString *)market secType:(NSString *)secType;

+ (UIImage *)marketImageWithMarket:(NSString *)market secType:(NSString *)secType secSubType:(nullable NSString *)secSubType;

+(BOOL)closeHKStockFiancePrompt;

+ (void)setFianceMarkKey:(NSString *)key isMarked:(BOOL)isMarked;

+ (BOOL)isStockFianceMarked:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
