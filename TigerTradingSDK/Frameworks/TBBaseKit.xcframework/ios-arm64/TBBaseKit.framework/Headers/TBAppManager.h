//
//  TBAppManager.h
//  Stock
//
//  Created by chenxin on 2021/11/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 海外包 bundleId
#define BUNDLEID_TIGERTRADE_APPSTORE            @"com.tigerbrokers.usstock"
#define BUNDLEID_TIGERTRADE_INHOUSE             @"com.tigerbrokers.Stock"

// 国内包 bundleId
#define BUNDLEID_TIGERTRADELITE_APPSTORE      @"com.tradingfront.tigertrade"
#define BUNDLEID_TIGERTRADELITE_INHOUSE       @"com.tigerbrokers.TigerTradeLite"

// TBMS包 bundleId
#define BUNDLEID_TBMS_APPSTORE            @"com.itiger.TigerStocks"

// iPad版 bundleId
#define BUNDLEID_TIGERTRADEHD_APPSTORE            @"com.tigerbrokers.tigertradehd"

// TradeUP bundleId
#define BUNDLEID_TRADEUP_APPSTORE            @"com.itradeup.ustradeup"
#define BUNDLEID_TRADEUP_INHOUSE             @"com.tigerbrokers.stockglobal.inhouse"

// TTWLA bundleId
#define BUNDLEID_TTWLA_APPSTORE            @"com.tigerbrokers.ttwla"

// TTWLA_ND bundleId
#define BUNDLEID_TTWLA_ND_APPSTORE            @"com.tigerbrokers.ttwland"

#define TBAppIsLiteVersion  [TBAppManager isTigerTradeLite]

#define TBAppIsTigerTrade  [TBAppManager isTigerTrade]

#define TBAppIsTigerTradeMS  [TBAppManager isTigerTradeMS]

/*
 ⚠️ TBIsTradeUP和TBIsTigerTrade之前是用来区分工程是TradeUP还是TigerTrade，
 后续TradeUP直接作为TT壳工程的target，这两个宏的含义变为区分App
 */
#define TBIsTradeUP ([TBAppManager isTradeUP])
// TBIsTigerTrade包含非TradeUP的App，如果要区分不同版本，单独使用TBAppIsXXX宏
#define TBIsTigerTrade (!TBIsTradeUP)

// 是否是白标App
#define TBIsWhiteLabelApp ([TBAppManager isWhiteLabelApp])

// appName，用于服务端区分App
#define APPNAME                     [TBAppManager appName]
// App显示名称，用于关于页
#define TIGERBROKERS_APP_NAME       [TBAppManager appDisplayName]
// Apple ID
#define TIGERBROKERS_APP_ID         [TBAppManager appId]

#define TTANDTUP_BUNDLE_ASSERT(strAssertMessage)  [TBAppManager onlyTTAndTUPBundleAssert:(strAssertMessage)]

#define TBIsCMBSDK [TBAppManager isCMBSDK]
#define TBIsTBSDK [TBAppManager isTBSDK]


// 应用类型，用于测试包切换（暂时无法切换TradeUP）
typedef NS_ENUM(NSUInteger, TBAppType) {
    TBAppTypeTigerTrade,
    TBAppTypeTigerTradeLite,
    TBAppTypeTigerTradeMS,
    TBAppTypeTTWLA,
    TBAppTypeTTWLA_ND,
    TBAppTypeTradeUP, // TradeUP要在最后，否则测试包切换完App重新启动可能崩溃
};

@interface TBAppManager : NSObject

+ (TBAppType)appType;
+ (void)setDebugAppType:(TBAppType)appType;

// 是否是TigerTrade版，通过bundleId区分，只能在主App使用，Widget无效
+ (BOOL)isTigerTrade;

// 是否是Lite版，通过bundleId区分，只能在主App使用，Widget无效
+ (BOOL)isTigerTradeLite;

// 是否是TBMS版，通过bundleId区分
+ (BOOL)isTigerTradeMS;

// 是否是TradeUP版，通过bundleId区分，只能在主App使用，Widget无效
+ (BOOL)isTradeUP;

// 是否是TTWLA App
+ (BOOL)isTTWLA;

// 是否是TTWLA_ND App
+ (BOOL)isTTWLA_ND;

// 是否是白标App（对外给加盟公司提供的App）
+ (BOOL)isWhiteLabelApp;

// 是否是iPad版
+ (BOOL)isTigerTradeHD;

/// 是否为CMB SDK
+ (BOOL)isCMBSDK;

/// 是否为CMB SDK
+ (BOOL)isTBSDK;

// appName，用于服务端区分App
+ (NSString *)appName;

// App显示名称，用于关于页
+ (NSString *)appDisplayName;

// Apple ID
+ (NSString *)appId;

// 是否为主工程运行, 用来区别主工程运行, 和各个业务pod独立运行.
// 例如如果是TigerTrade 返回yes, 如果是TBStockbusiness或者communityBusiness返回NO
+ (BOOL)isMainProjectBuild;

/// 仅在tt tup壳工程编译项目触发assert（内部通过bundle判断项目类型）
/// @param assertMessage 崩溃信息
+ (void)onlyTTAndTUPBundleAssert:(NSString *)assertMessage;

@end

NS_ASSUME_NONNULL_END
