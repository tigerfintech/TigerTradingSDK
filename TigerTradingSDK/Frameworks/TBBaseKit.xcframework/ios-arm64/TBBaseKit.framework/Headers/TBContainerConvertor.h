//
//  TBContainerConvertor.h
//  StockGlobal
//
//  Created by linbingjie on 2019/11/27.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBContainerConvertor : NSObject

// 从字典中获取数据
+ (NSString *)tbStringWithDictionary:(NSDictionary *)dict forKey:(id)key;
+ (NSString *)tbNonnullStringWithDictionary:(NSDictionary *)dict forKey:(id)key;
+ (NSNumber *)tbNumberWithDictionary:(NSDictionary *)dict forKey:(id)key;
+ (NSDictionary *)tbDictWithDictionary:(NSDictionary *)dict forkey:(id)key;
+ (NSArray *)tbArrayWithDictionary:(NSDictionary *)dict forkey:(id)key;

// 从数组中获取数据
+ (NSString *)tbStringWithArray:(NSArray *)array atIndex:(NSInteger)index;
+ (NSNumber *)tbNumberWithArray:(NSArray *)array atIndex:(NSInteger)index;
+ (NSDictionary *)tbDictWithArray:(NSArray *)array atIndex:(NSInteger)index;
+ (NSArray *)tbArrayWithArray:(NSArray *)array atIndex:(NSInteger)index;

// 判断是否是array，dictionary
+ (NSArray *)tbArrayWithObject:(id)array;
+ (NSDictionary *)tbDictWithObject:(id)dict;

@end

NS_ASSUME_NONNULL_END
