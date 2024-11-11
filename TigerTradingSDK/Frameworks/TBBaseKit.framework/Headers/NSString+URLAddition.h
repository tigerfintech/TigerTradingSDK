//
//  NSString+URLAddition.h
//  TBBaseKit
//
//  Created by zhengzhiwen on 2021/6/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (URLAddition)

- (NSString *)tb_stringByAddingParameterKey:(NSString *)key value:(NSString *)value;

// 检查URL字符串, 如果没有 invite 参数, 添加邀请码
- (NSString *)tb_stringByAddingInviteCodeIfNeeded:(NSString *)inviteCode;
// 检查URL字符串, 如果没有 share 参数, 添加分享平台
- (NSString *)tb_stringByAddingShareTypeIfNeeded:(NSString *)shareType;
// 检查URL字符串, 如果没有 feature 参数, 添加 feature
- (NSString *)tb_stringByAddingFeatureTypeIfNeeded:(NSString *)feature;

- (NSString *)tb_stringByAddingShareUtmSource:(NSString *)utmSource;

//是否是url
- (BOOL)isURL;

//从字符串中获取所有的url
- (NSArray*)getURLFromStr;

@end

NS_ASSUME_NONNULL_END
