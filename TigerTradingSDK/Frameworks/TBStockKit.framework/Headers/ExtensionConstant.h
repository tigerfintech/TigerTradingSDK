//
//  ExtensionConstant.h
//  Stock
//
//  Created by yangfan on 2019/8/7.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#ifndef ExtensionConstant_h
#define ExtensionConstant_h

#import <NotificationCenter/NCWidgetController.h>
//存储在group中的唯一标识
#define GROUP_TIGERBROKERS_STOCK    [[NSBundle mainBundle] objectForInfoDictionaryKey:@"TBAppGroupName"]

static NSString *GROUP_ACCESS_TOKEN                                                     = @"group.accessToken";
static NSString *GROUP_WATCHLIST                                                        = @"group.watchlist";
static NSString *GROUP_WATCHLIST_SYMBOLS                                                = @"group.watchlist.symbols";

static NSString *GROUP_WATCHLIST_GROUP                                                = @"group.watchlist.group";


static NSString *GROUP_MARKETINDICES                                                    = @"group.marketIndices";
static NSString *GROUP_LANGUAGE                                                         = @"group.language";
static NSString *GROUP_SERVER                                                           = @"group.server";
static NSString *GROUP_COMMON                                                           = @"group.common";
static NSString *GROUP_CRYPTOS                                                           = @"group.cryptos";

static NSString *USER_DEFAULT_KEY_TOKEN_TYPE                        = @"userDefaultKeyTokenType";                  //不绑定,每次删除

//
static NSString *USER_DEFAULT_KEY_INCREASE_COLOR_SETTING                                      = @"increaseColorSetting";                        // phone绑定

//设置widget是否包含内容，如果没有内容，那么将会隐藏widget
#define SetAllWidgetsHasContent(flag) SetWidgetHasContent(@"WidgetWatchList",flag);SetWidgetHasContent(@"WidgetStockIndices",flag);SetWidgetHasContent(@"WidgetCorpAction",flag);SetWidgetHasContent(@"TBWatchListWidgetExtension",flag);SetWidgetHasContent(@"TBWatchListHandler",flag);

//设置指定widget是否包含内容
#define SetWidgetHasContent(name,flag) [[NCWidgetController widgetController] setHasContent:flag forWidgetWithBundleIdentifier:[@"com.tigerbrokers.Stock." stringByAppendingString:name]]

//同步token到widget
#define SynchTokenTypeToWidget(token) @try {[[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setValue:token forKey:USER_DEFAULT_KEY_TOKEN_TYPE];SetAllWidgetsHasContent(YES);} @catch (NSException *exception) { }
#define SynchAccessTokenToWidget(token) @try {[[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setValue:token forKey:GROUP_ACCESS_TOKEN];SetAllWidgetsHasContent(YES);} @catch (NSException *exception) { }
//获取token
#define MainAppTokenType [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:USER_DEFAULT_KEY_TOKEN_TYPE]
#define MainAppAccessToken [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_ACCESS_TOKEN]

// 同步自选分组
#define SynchWatchListGroupToWidget(array) @try { [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setValue:array forKey:GROUP_WATCHLIST_GROUP];} @catch (NSException *exception) { }
//获取自选分组
#define MainAppWatchListGroup [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_WATCHLIST_GROUP]


//同步自选到widget
#define SynchWatchListToWidget(stocks) \
@try { NSArray * extensionConst_H_TopStocks = stocks.count > 10 ? [stocks subarrayWithRange:NSMakeRange(0, 10)] : stocks; \
[[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setValue:extensionConst_H_TopStocks forKey:GROUP_WATCHLIST]; \
} @catch (NSException *exception) { }
//获取自选
#define MainAppWatchList [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_WATCHLIST]
//获取所有市场的指数
#define MainAppAllMarketIndices ([[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_MARKETINDICES] ?: @{})
//获取某市场的全部指数
#define MainAppMarketIndices(market) [MainAppAllMarketIndices objectForKey:market]
//同步市场指数到widget
#define SynchMarketIndicesToWidget(market,indices) \
@try { if(TextValid(market) && indices) { NSMutableDictionary * tmp_groupMarketIndicesDict = [MainAppAllMarketIndices mutableCopy]; tmp_groupMarketIndicesDict[market] = indices; [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setObject:tmp_groupMarketIndicesDict forKey:GROUP_MARKETINDICES];} \
} @catch (NSException *exception) { }
//同步全部自选的symbol到widget
#define SynchWatchListSymbolsToWidget(array) @try { [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setValue:array forKey:GROUP_WATCHLIST_SYMBOLS];} @catch (NSException *exception) { }
//获取全部自选的symbol
#define MainAppWatchListSymbols [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_WATCHLIST_SYMBOLS]
//同步语言
#define SynchLanguageToWidget(language) @try {[[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setValue:@(language) forKey:GROUP_LANGUAGE];} @catch (NSException *exception) { }
//获取主app语言
#define MainAppLanguage [[[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_LANGUAGE] integerValue]

//同步公共内容
#define SynchCommonDictToWidget(common) @try {[[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setObject:common forKey:GROUP_COMMON];} @catch (NSException *exception) { }
//获取同步公共内容
#define MainAppCommonDict [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_COMMON]

//同步虚拟货币信息
#define SynchCryptosDictToWidget(common) @try {[[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] setObject:common forKey:GROUP_CRYPTOS];} @catch (NSException *exception) { }

//获取虚拟货币信息
#define MainAppCryptosDict [[[NSUserDefaults alloc] initWithSuiteName:GROUP_TIGERBROKERS_STOCK] objectForKey:GROUP_CRYPTOS]


#endif /* ExtensionConstant_h */
