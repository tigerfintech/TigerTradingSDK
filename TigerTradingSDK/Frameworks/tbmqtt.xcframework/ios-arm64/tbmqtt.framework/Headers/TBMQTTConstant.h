//
//  TBMQTTConstant.h
//  tbmqtt
//
//  Created by 骆鹏飞 on 2020/10/27.
//

#import <Foundation/Foundation.h>

#define MQTTTextValid(text) ((text == nil || ![text isKindOfClass:[NSString class]] || [text isEqualToString:@""]) ? NO : YES)

// 长连接推送的json数据的key
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyAskPrice;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyAskSize;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyBidPrice;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyBidSize;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyHourTradingTag;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyHourTradingLatestPrice;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyHourTradingLatestTime;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyHourTradingPreClose;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyHourTradingVolume;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyLatestPrice;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyLatestTime;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyPreClose;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeySymbol;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyTimestamp;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyType;

UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyMinute;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyMinuteVolume;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyMinuteTimeStamp;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyMinuteAvg;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyMinuteLatestPrice;

UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientAppStockHotUpgradeTopic;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyAmount;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyHigh;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyLow;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyVolume;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestManagerJsonKeyOpen;



UIKIT_EXTERN NSString * _Nullable const TBMQTTClientRequestDetailQuote;
UIKIT_EXTERN NSString * _Nullable const TBMQTTClientRequestDetailQuoteDepth;
UIKIT_EXTERN NSString * _Nonnull const TBMQTTClientRequestSimpleQuote;
UIKIT_EXTERN NSString * _Nullable const TBMQTTClientRequestFUTLv2Quote;
UIKIT_EXTERN NSString * _Nullable const TBMQTTClientRequestOptionLv2Quote;
UIKIT_EXTERN NSString * _Nullable const TBMQTTClientRequestHKGreyQuote;

/// 断开连接
UIKIT_EXTERN NSNotificationName _Nonnull TBMQTTDisconnectNotification;
/// 连接
UIKIT_EXTERN NSNotificationName _Nonnull TBMQTTConnectNotification;
UIKIT_EXTERN NSNotificationName _Nonnull TBMQTTNoAccessTokenNotification;
