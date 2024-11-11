//
//  TBMQTTClientRequestManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/4/11.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBMQTTClientBaseManager.h"


NS_ASSUME_NONNULL_BEGIN

@interface TBMQTTClientRequestManager : TBMQTTClientBaseManager
//DECLARE_SHARED_INSTANCE(TBMQTTClientRequestManager);

+ (instancetype)sharedInstance;


@property (atomic, copy) void (^quoteMarketMessageHandler)(NSData* message, NSString* topic);
@property (atomic, copy) void (^quoteTradeMessageHandler)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^assetMessageHandler)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^positionMessageHandler)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^orderStatusMessageHandler)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^segmentFundsTransferMessageHandler)(NSData *message, NSString *topic);

@property (atomic, copy, nullable) void (^quoteUSLV2AskBidDepthMessageHandler)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^quoteFutruesLV2AskBidDepthMessageHandler)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^quoteOptionLV2AskBidDepthMessageHandler)(NSData *message, NSString *topic);
@property (atomic, copy) void (^hotUpgradeMessageHandle)(NSData *message, NSString *topic);
@property (atomic, copy) void (^logUploadMessageHandle)(NSData *message, NSString *topic);

@property (atomic, copy, nullable) void (^quoteHKQuoteGreyMarketMessageHandler)(NSData *message, NSString *topic);

@property (atomic, copy) void (^inAppPushMessageHandler)(NSData *message, NSString *topic);

@property (atomic, copy, nullable) void (^communityTransactionSharingHandler)(NSData *message, NSString *topic);

@property (atomic, copy, nullable) void (^preemptQoutePermission)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^quotePermissionChange)(NSData *message, NSString *topic);
@property (atomic, copy, nullable) void (^deviceKickedOut)(NSData *message, NSString *topic);
/// 期货报价墙
@property (atomic, copy) void (^quoteFutMarketHandler)(NSData *message, NSString *topic);

/// 市场页回调
@property (atomic, copy) void (^quoteMarketPageHandler)(NSData *message, NSString *topic);

/// 期权tab页回调
@property (atomic, copy) void (^optionMarketPageHandler)(NSData *message, NSString *topic);

/// 港股-经纪席位
/// 客户端订阅 quote/{{symbol}}/quote-broker-hk 主题
@property (atomic, copy, nullable) void (^quoteBrokerHKHandler)(NSData *message, NSString *topic);

/// 逐笔成交
/// 订阅主题：quote/{{symbol}}/tick
@property (atomic, copy, nullable) void (^quoteContractTickHandler)(NSData *message, NSString *topic);

// Omnibus交易持仓推送
@property (atomic, copy, nullable) void (^omnibusTradeAssetHandler)(NSData *message, NSString *topic); // 资产
@property (atomic, copy, nullable) void (^omnibusTradePositionHandler)(NSData *message, NSString *topic); // 持仓

@property (atomic, copy, nullable) void (^domainConfigHandler)(NSData *message, NSString *topic);

@property (atomic, copy, nullable) void (^personalizationConfigHandler)(NSData *message, NSString *topic);

@property (atomic, copy, nullable) void (^marketMaterialHandler)(NSData *message, NSString *topic);

@property (atomic, copy, nullable) void (^optionChainHandler)(NSData *message, NSString *topic);


@property (atomic, copy, nullable) void (^optionChainDictionaryHandler)(NSDictionary *dict, NSString *topic);


@end

NS_ASSUME_NONNULL_END
