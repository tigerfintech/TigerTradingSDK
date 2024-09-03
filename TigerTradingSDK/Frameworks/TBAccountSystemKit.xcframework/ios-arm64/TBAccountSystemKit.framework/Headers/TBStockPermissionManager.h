//
//  TBStockPermissionManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/18.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBStockPermissionConstant.h"
#import <TBStockKit/TBStock.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBBaseKit/TBBaseUtility.h>

/*
 合约可交易状态:
 TBContractTradeTypeTradeAble : 可交易
 TBContractTradeTypeUnsupport : 不可交易
 TBContractTradeTypeNoPermission : 无权限
 */
typedef NS_ENUM(NSUInteger, TBContractTradeType) {
    TBContractTradeTypeTradeAble,
    TBContractTradeTypeUnsupport,
    TBContractTradeTypeNoPermission,
};


#define TBStockPermissionKit [TBStockPermissionManager sharedInstance]


NS_ASSUME_NONNULL_BEGIN
@class TBAuthAccountPermissionDataModel;
@interface TBStockPermissionManager : NSObject

DECLARE_SHARED_INSTANCE(TBStockPermissionManager);

- (void)updatePermissionModel:(TBAuthAccountPermissionDataModel *)model;
- (void)updatePermissionDict:(NSDictionary *)dict;

- (void)resetPermissions;

@property (nonatomic, strong) NSNumber *quotePermissionVersion;

/// 权限列表
@property (nonatomic, readonly) NSArray *tradePermission;
@property (nonatomic, readonly) NSArray *quotePermission;
@property (nonatomic, readonly) NSString *quoteType;
@property (nonatomic, readonly) NSString *userLocation;

/// 详情页展示权限icon
/// @param market 市场
/// @param secType secType
- (NSArray *)displayQuoteType:(NSString *)market secType:(NSString *)secType exchangeCode:(NSString *)exchangeCode;

- (BOOL)limitQuote:(NSString *)market secType:(NSString *)secType exchangeCode:(NSString *)exchangeCode;

/// A股行情权限
@property (nonatomic, readonly) TBStockQuotePromptType aStockQuoteType;
@property (nonatomic, readonly) BOOL hasCNQuotePermission;


/// 港股行情权限
@property (nonatomic, readonly) TBStockQuotePromptType hkStockQuoteType;
@property (nonatomic, readonly) BOOL hasHKL1QuotePermission;
@property (nonatomic, readonly) BOOL hasHKL2QuotePermission;
@property (nonatomic, readonly) BOOL hasHKQuotePermission; //L1或L2

/// 新加坡行情权限
@property (nonatomic, readonly) TBStockQuotePromptType siStockQuoteType;
@property (nonatomic, readonly) NSArray *siStockQuoteTypes;

@property (nonatomic, readonly) BOOL hasSIQuotePermission;
@property (nonatomic, readonly) BOOL hasSIL2QuotePermission;
@property (nonatomic, readonly) BOOL isSIQuoteDelayPermission;


/// 英股行情权限
@property (nonatomic, readonly) TBStockQuotePromptType ukStockQuoteType;
@property (nonatomic, readonly) BOOL hasUKQuotePermission;


/// 澳洲行情权限
@property (nonatomic, readonly) TBStockQuotePromptType auStockQuoteType;
@property (nonatomic, readonly) BOOL hasAUQuotePermission;
@property (nonatomic, readonly) BOOL hasAUBMPL2QuotePermission;
@property (nonatomic, readonly) BOOL hasAUL2QuotePermission;

/// 新西兰行情权限
@property (nonatomic, readonly) TBStockQuotePromptType nzStockQuoteType;
@property (nonatomic, readonly) BOOL hasNZQuotePermission;
@property (nonatomic, readonly) BOOL hasNZL2QuotePermission;

/// 以下权限存在L2和L1并列情况

/// 美股行情权限
@property (nonatomic, readonly) NSArray *usStockQuoteTypes;
@property (nonatomic, readonly) NSArray *usStockL2QuoteTypes;
@property (nonatomic, readonly) TBStockQuotePromptType usL1StockQuoteType;
@property (nonatomic, readonly) BOOL hasUSQuotePermission;
@property (nonatomic, readonly) BOOL hasUSL2QuotePermission;
@property (nonatomic, readonly) BOOL isUSQuoteDelayPermission;

@property (nonatomic, readonly) BOOL hasUSNBBOQuotePermission;
@property (nonatomic, readonly) BOOL hasUSArcaQuotePermission;
@property (nonatomic, readonly) BOOL hasUSTotalViewQuotePermission;

@property (nonatomic, readonly) TBStockQuotePromptType usOTCStockQuoteType;


/// 期权行情权限
@property (nonatomic, readonly) NSArray *optionStockQuoteTypes;
@property (nonatomic, readonly) TBStockQuotePromptType usOptionQuoteType;
@property (nonatomic, readonly) BOOL hasUSOptionQuotePermission;
@property (nonatomic, readonly) BOOL hasUSOptionL2QuotePermission;
@property (nonatomic, readonly) BOOL hasUSOptionQuoteArbitrarilyPermission;

/// 港股期权权限
@property (nonatomic, readonly) NSArray *optionHKStockQuoteTypes;
@property (nonatomic, readonly) TBStockQuotePromptType hkOptionQuoteType;
@property (nonatomic, readonly) BOOL hasHKOptionQuotePermission; //L1
@property (nonatomic, readonly) BOOL hasHKOptionL2QuotePermission;

/// TUP marsco 期权权限等级
@property (nonatomic, assign) BOOL  hasMarscoLVOptionPermission;   // 是否下发了 marsco lv 的期权等级信息
@property (nonatomic, readonly) TBStockQuotePromptType usMarscoOptionTradeLV;
@property (nonatomic, readonly) NSString *marscoTradePermission;

#pragma mark --- 期货行情权限处理
/// 期货行情权限
//@property (nonatomic, readonly) NSArray *futuresStockQuoteTypes;

/// 根据交易所判断当前交易所用户购买权限
/// @param exchangeCode 交易所
- (TBStockQuotePromptType)futuresPermission:(NSString *)exchangeCode;
//@property (nonatomic, readonly) TBStockQuotePromptType futuresL1QuoteType;
//@property (nonatomic, readonly) TBStockQuotePromptType futuresL2QuoteType;

//@property (nonatomic, readonly) BOOL hasFuturesQuotePermission;
- (BOOL)hasFuturesQuotePermission:(NSString *)exchangeCode;

- (BOOL)futuresIsLV2Quote:(NSString *)exchangeCode;
//@property (nonatomic, readonly) BOOL futuresIsLV2Quote;


//数字货币权限
@property (nonatomic, readonly) TBStockQuotePromptType digiccyCurrencyQuoteType;
@property (nonatomic, readonly) BOOL hasSICryptoQuotePermission;
@property (nonatomic, readonly) BOOL hasDBSDigiccyLv2QuotePermission;

/// HK数字货币权限
@property (nonatomic, readonly) BOOL hasHKCryptoQuotePermission;

/// 通用数字货币权限
@property (nonatomic, readonly) BOOL hasCryptoQuotePermission;

// 闲钱3.0 auto-sweep权限
@property (nonatomic, readonly) BOOL hasFundAutoSweepPermission;


/// 交易权限判断
/// cn股票交易权限
@property (nonatomic, readonly) BOOL cnStockTradeAble;

/// 伦敦股票交易权限
@property (nonatomic, readonly) BOOL ukStockTradeAble;

/// 港股股票交易权限
@property (nonatomic, readonly) BOOL hkStockTradeAble;

/// 美股股票交易权限
@property (nonatomic, readonly) BOOL usStockTradeAble;

/// 美股期权交易权限
@property (nonatomic, readonly) BOOL usOptionTradeAble;

/// 期货交易权限
@property (nonatomic, readonly) BOOL futuresTradeAble;

/// 美股碎股交易权限
@property (nonatomic, readonly) BOOL usFracShareTradeAble;

/// 数字货币交易权限
@property (nonatomic, readonly) BOOL digitalcurrencyTradeAble;

/// 澳洲股票交易权限
@property (nonatomic, readonly) BOOL auStockTradeAble;

/// 新西兰股票交易权限
@property (nonatomic, readonly) BOOL nzStockTradeAble;

/// 新加坡股票交易权限
@property (nonatomic, readonly) BOOL sgStockTradeAble;

/// 标准账号OTC
@property (nonatomic, readonly) BOOL usStockOTCTradeAble;


/// 综合账户新加坡DLC交易
@property (nonatomic, readonly) BOOL sgDLCTradeAble;

/// 数字货币交易权限
@property (nonatomic, readonly) BOOL digiFuturesTradeAble;

/// 是否开通syep权限
@property (nonatomic, readonly) BOOL syepAble;

/// 港股暗盘交易权限
@property (nonatomic, readonly) BOOL hkGreyTradeable;

/// TBHK是否有窝轮和牛熊证的交易权限(仅用于TBHK, 窝轮和牛熊证的权限总是一起出现)
@property (nonatomic, readonly) BOOL hkWarrantsAndIoptTradable;

/// fcn交易权限
@property (nonatomic, readonly) BOOL fcnTradeAble;

/// 国债交易权限
@property (nonatomic, readonly) BOOL treasuryTradeAble;

/// 数字货币etc美股交易权限
@property (nonatomic, readonly) BOOL usBtcETFTradeAble;

/// 数字货币etc港股交易权限
@property (nonatomic, readonly) BOOL hkBtcETFTradeAble;

/// cfd交易权限
@property (nonatomic, readonly) BOOL cfdTradeAble;


@end



/// 请求permission接口
@interface TBStockPermissionManager (NetWorkManager)
/*
 登录状态下, 需要在 header 添加 Authorization 的 access_token, 获取用户级别的配置
 */
+ (void)fetchUserPermission:(nullable void (^)(TBAuthAccountPermissionDataModel *permissionModel))success failure:(nullable void (^)(NSError *error))failure;

//行情抢占
- (void)subscribeQuotePermission;
- (void)unsubscribeQuotePermission;

+ (void)limitedQuotePrompt:(BOOL)prompt;

@end


/*
 权限判断
 */
@interface TBStockPermissionManager (PermissionJudgment)

//- (void)shouldUpdateToken:(NSArray *)permission oldPermisson:(NSArray *)oldPermisson;

/*
 新旧权限差异判断
 如果新权限有limit
 目前权限变化提示有两种：
 1、多端登录降级
 2、港股L2非大陆不能使用
 */
- (void)permissionChanged:(NSArray *)permission oldPermisson:(NSArray *)oldPermission;


- (BOOL)arrayIsEqual:(NSArray *)array1 array:(NSArray *)array2;

@end

NS_ASSUME_NONNULL_END
