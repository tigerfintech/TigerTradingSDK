//
//  TBMQTTClientRequestManager+TBPBTopics.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/9/28.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBMQTTClientRequestManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBMQTTClientRequestManager (TBPBTopics)
#pragma mark --- 长连接订阅

/// 订阅深度
/// @param symbol <#symbol description#>
/// @param market <#market description#>
/// @param quoteType <#quoteType description#>
/// @param usePB <#usePB description#>
/// @param callBack <#callBack description#>
- (void)subscribeQuoteDepth:(NSString *)symbol market:(NSString *)market quoteType:(NSString *)quoteType usePB:(BOOL)usePB callBack:(void(^)(NSData *message, NSString *topic))callBack;
- (void)unsubscribeQuoteDepth:(NSString *)symbol market:(NSString *)market quoteType:(NSString *)quoteType usePB:(BOOL)usePB;

/// 美股深度
/// @param symbol <#symbol description#>
/// @param quoteType <#quoteType description#>
/// @param usePB <#usePB description#>
/// @param callBack <#callBack description#>
- (void)subscribeUSQuoteDepth:(NSString *)symbol quoteType:(NSString *)quoteType usePB:(BOOL)usePB callBack:(void(^)(NSData *message, NSString *topic))callBack;
- (void)unsubscribeUSQuoteDepth:(NSString *)symbol quoteType:(NSString *)quoteType usePB:(BOOL)usePB;

/// 期权深度
/// @param symbol <#symbol description#>
/// @param usePB <#usePB description#>
/// @param market <#market description#>
/// @param callBack <#callBack description#>
- (void)subscribeOptionL2:(NSString *)symbol usePB:(BOOL)usePB market:(NSString *)market callBack:(nonnull void (^)(NSData * _Nonnull, NSString * _Nonnull))callBack;
- (void)unsubscribeOptionL2:(NSString *)symbol usePB:(BOOL)usePB market:(NSString *)market;

/// 期货L2
/// @param symbol <#symbol description#>
/// @param usePB <#usePB description#>
/// @param callBack <#callBack description#>
- (void)subscribeFutLv2Quote:(NSString *)symbol usePB:(BOOL)usePB callBack:(nonnull void (^)(NSData * _Nonnull, NSString * _Nonnull))callBack;
- (void)unsubscribeFutLv2Quote:(NSString *)symbol usePB:(BOOL)usePB;


/// 港股暗盘行情订阅/取消订阅
/// @param symbol <#symbol description#>
/// @param callBack <#callBack description#>
- (void)subscribeQuoteGreyHK:(NSString *)symbol usePB:(BOOL)usePB callBack:(void (^)(NSData* message, NSString* topic))callBack;
- (void)unsubscribeQuoteGreyHK:(NSString *)symbol usePB:(BOOL)usePB;

//主设备切换
- (void)subscribePreemptQoutePermission:(void (^)(NSData* message, NSString* topic))callBack;
- (void)unsubscribePreemptQoutePermission;

//行情权限变更
- (void)subscribeQuotePermissionChange:(void (^)(NSData* message, NSString* topic))callBack;
- (void)unsubscribeQuotePermissionChange;

- (void)subscribeQuoteBrokerHK:(NSString *)symbol callBack:(void (^)(NSData* message, NSString* topic))callBack;
- (void)unsubscribeQuoteBrokerHK:(NSString *)symbol;



/// 逐笔成交
/// @param symbol <#symbol description#>
/// @param callBack <#callBack description#>
- (void)subscribeQuoteTick:(NSString *)symbol secType:(NSString *)secType callBack:(void (^)(NSData* message, NSString* topic))callBack;
- (void)unsubscribeQuoteTick:(NSString *)symbol secType:(NSString *)secType;

- (void)subscribeOptionChain:(NSString *)optionSymbol callBack:(void (^)(NSData* message, NSString* topic))callBack;
- (void)unsubscribeOptionChain:(NSString *)optionSymbol;
- (void)subscribeOptionChain:(NSString *)optionSymbol dictionaryCallBack:(void (^)(NSDictionary *dict, NSString *topic))callBack;

// Omnibus交易持仓推送
// 因为现有代码是分别有资产和持仓manager, 所以拆成两个订阅方法
- (void)subscribeOmnibusTradeAssetWithAccountId:(NSString *)accountId callback:(void (^)(NSData *message, NSString *topic))callback;
- (void)subscribeOmnibusTradePositionWithAccountId:(NSString *)accountId callback:(void (^)(NSData *message, NSString *topic))callback;
- (void)unsubscribeOmnibusTradeAssetWithAccountId:(NSString *)accountId;
- (void)unsubscribeOmnibusTradePositionWithAccountId:(NSString *)accountId;

// 订阅 被踢出登录
- (void)subscribeDeviceKickedOut:(void (^)(NSData* message, NSString* topic))callBack;
// 取消订阅 被踢出登录
- (void)unsubscribeDeviceKickedOut;

// 订阅域名配置
- (void)subscribeDomainConfig:(void (^)(NSData *message, NSString *topic))callback;
- (void)unsubscribeDomainConfig;

// 用户个性化配置
- (void)subscribePersonalizationConfig:(void (^)(NSData *message, NSString *topic))callback;
- (void)unSubscribePersonalizationConfig;

// 营销物料
- (void)subscribeMarketMaterialWithUUID:(NSString *)uuid callback:(void (^)(NSData *message, NSString *topic))callback;
- (void)unsubscribeMarketMaterialWithUUID:(NSString *)uuid;

@end

NS_ASSUME_NONNULL_END
