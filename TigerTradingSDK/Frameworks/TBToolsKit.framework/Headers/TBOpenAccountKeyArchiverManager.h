//
//  TBOpenAccountKeyArchiverManager.h
//  Stock
//
//  Created by 马超 on 2018/1/9.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBOpenAccountKeyArchiverManager : NSObject

+ (instancetype)manager;

- (NSString *)pathForKey:(NSString *)key;

- (BOOL)archiveObject:(id)object forKey:(NSString *)key;

- (id)unarchiveObjectForKey:(NSString *)key;

- (BOOL)removeObjectForKey:(NSString *)key;

- (NSError *)removeAllCache;

@end
