//
//  TBKeyedArchiverManager.h
//  Stock
//
//  Created by yangfan on 16/10/19.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <objc/NSObject.h>

#define TBKeyedArchiverKit [TBKeyedArchiverManager manager]
#define TBKeyedArchiverConfigKit [TBKeyedArchiverManager configArchiverManager]
#define TBKeyedArchiverTempKit [TBKeyedArchiverManager tempArchiverManager]

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"

@interface TBKeyedArchiverManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

//默认缓存，通常清理缓存不会直接清理的缓存(比如缓存用户关注列表以及点赞帖子列表)
+ (instancetype)manager;
//配置相关等一些重要缓存，不能自动一键清理（比如系统配置，设置）
+ (instancetype)configArchiverManager;
//临时缓存，清理缓存时需要一键清理
+ (instancetype)tempArchiverManager;

- (NSString *)pathForKey:(NSString *)key;

- (BOOL)archiveObject:(id)object forKey:(NSString *)key;

- (BOOL)archiveSyncObject:(id)object forKey:(NSString *)key;//同步存储

- (id)unarchiveObjectForKey:(NSString *)key;
//解档一个对象，如果归档中不存在这个对象，那么尝试从user defaults中读取相应的key
- (id)unarchiveObjectForKeyWithUD:(NSString *)key;

- (BOOL)removeObjectForKey:(NSString *)key;

- (NSError *)removeAllCache;

//深复制一个对象
+ (nullable id)copyObject:(nonnull id)object;

@end

@interface TBArchiverAtomic : NSObject

+ (instancetype)manager;

- (void)archiveObject:(id)object forFile:(NSString *)file;

- (void)archiveSyncObject:(id)object forFile:(NSString *)file;

@end

#pragma clang diagnostic pop
