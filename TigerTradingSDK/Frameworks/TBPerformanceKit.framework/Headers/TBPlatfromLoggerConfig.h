//
//  TBPlatfromLoggerConfig.h
//  TBPlatformLogger
//
//  Created by JustLee on 2021/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlatfromLoggerConfig : NSObject

@property (nonatomic, assign) BOOL useLogan;

/// deviceId，未设置deviceId取uuid
@property (nonatomic, copy) NSString *deviceId;

/// 用户uuid
@property (nonatomic, copy) NSString *uuid;

/// 平台id
@property (nonatomic, copy) NSString *platformId;           //TigerBrokers TradeUP

/// 缓存日期的时区id
@property (nonatomic, copy) NSString *localIdentifier;

@property (nonatomic, copy) NSString *tzName;

/// 上传host
@property (nonatomic, copy) NSString *hostURL;

/// 需要在日志拼接的额外信息
@property (nonatomic, copy) NSDictionary *loggerUserInfo;

/// 日志加密key
@property (nonatomic, copy) NSString *secretKey;
/// 加密初始化向量
@property (nonatomic, copy) NSString *iv;

+ (instancetype)defaultConfig;

/// 使用uuid初始化
/// @param uuid uuid description
/// @param hostURL 上传host
/// 默认缓存时区为美东时区
+ (TBPlatfromLoggerConfig *)logerDataWithUUID:(NSString *)uuid uploadHostURL:(NSString *)hostURL;

/// 初始化方法添加zoneId
/// @param uuid uuid description
/// @param hostURL hostURL description
/// @param zoneId zoneId description
+ (TBPlatfromLoggerConfig *)logerDataWithUUID:(NSString *)uuid uploadHostURL:(NSString *)hostURL specificCacheTimeZoneId:(NSString *)zoneId;


@end

NS_ASSUME_NONNULL_END
