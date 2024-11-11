//
//  TBUserDefaultsManager.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/4/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBUserDefaultsManager : NSObject

#pragma mark - 默认的userdefault（没有对key进行额外的md5uuid拼接）
/// setter方法（内部做了key的长度校验）
+ (void)setUserDefaultObject:(nullable id)object forKey:(NSString *)key;
/// 获取key对应的bool值
+ (BOOL)getUserDefaultBoolForKey:(NSString *)key defaultValue:(BOOL)value;
/// 获取key对应的object
+ (id)getUserDefaultObjectForKey:(NSString *)key defaultValue:(nullable id)value;
+ (void)removeDefaultObjectForKey:(NSString *)key;
#pragma mark - MD5UUID后的key的userdefault方法
/*
 获取userDefault里以“uuid(md5)+key”为key存储的值，
 将原来以“uuid(明文)+key”为key存储的值转换为以“uuid(md5)+key”为key存储
 */
+ (id)getUserDefaultValueWithUUIDAppendKey:(NSString *)key;
/// key拼接上md5后的uuid并返回
+ (NSString *)getUserDefaultKey:(NSString *)key;
/// 获取key（内部拼接了MD5的uuid）对应的value
+ (NSString *)getValueWithkey:(NSString *)key;
/// 获取key（内部拼接了MD5uuid）对应的value
+ (NSNumber *)getValueWithAppendKey:(NSString *)key;
/// setter方法（内部做了key的长度校验， key拼接了md5的uuid）
+ (void)setUserDefaultValue:(id)value forKey:(NSString *)key;
+ (void)removeValueForKey:(NSString *)key;
/// setter方法（内部做了key的长度校验， key拼接了MD5的uuid）
+ (void)setValueWithAppendKey:(NSString *)key value:(NSInteger)value;

@end

NS_ASSUME_NONNULL_END
