//
//  TBMQTTHelper.h
//  MQTTClient
//
//  Created by 骆鹏飞 on 2020/10/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBMQTTHelperDataSource <NSObject>

@property (nonatomic, copy, readonly) NSString *accessToken;
@property (nonatomic, copy, readonly) NSString *uuid;
@property (nonatomic, copy, readonly) NSString *host;

/// 数字货币MQTT域名
@property (nonatomic, copy, readonly) NSString *cryptoCurrencyHost;

@property (nonatomic, assign, readonly) UInt32 port;

@property (nonatomic, assign, readonly) UInt32 cryptoPort;
@property (nonatomic, assign, readonly) BOOL usingSSL;
@property (nonatomic, assign, readonly) BOOL cryptoUsingSSL;


/// publishMQTT域名
@property (nonatomic, copy, readonly) NSString *publishHost;
@property (nonatomic, assign, readonly) UInt32 publishPort;
@property (nonatomic, assign, readonly) BOOL publishUsingSSL;
@property (nonatomic, assign, readonly) BOOL publishEnable;

@property (nonatomic, copy, readonly) NSString *clientID;
@property (nonatomic, copy, readonly) NSString *accountId;

@property (nonatomic, copy, readonly) NSString *appLang;
@property (nonatomic, copy, readonly) NSString *appVersion;

@property (nonatomic, assign, readonly) BOOL hasTestEnv;
@property (nonatomic, assign, readonly) BOOL needRgisterAccount;

@property (nonatomic, copy, readonly) NSDictionary *userProperties;

// 回调一些返回值，外部跟需要实现协议;
- (void)appHandleMarketOpenNotifation:(NSNumber *)serverTime;
- (void)saTrackAppBehaviorQuoteParam:(NSString *)type name:(NSString *)name param1:(NSString *)param1 param2:(NSString *)param2;

// 记录请求信息
- (void)recordMqttRequestString:(NSString *)string;

@end

@interface TBMQTTHelper : NSObject

@property (nonatomic, weak, class) id<TBMQTTHelperDataSource> dataSource;

+ (void)mqttDevelopLog:(NSString *)log;
+ (void)mqttDevelopLogNow:(NSString *)log;
@end

NS_ASSUME_NONNULL_END
