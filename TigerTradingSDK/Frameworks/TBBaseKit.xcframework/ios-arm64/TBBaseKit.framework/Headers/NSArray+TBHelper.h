//
//  NSArray+FTFHelper.h
//  Future
//
//  Created by JyHu on 2017/2/24.
//  Copyright © 2017年 JyHu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (TBHelper)

/**
 map方法，类似于swift、python中的map，对数组中的每个对象都调用map进行转换，然后将所有转换后的数据转换成一个数据
 
 NSArray *nums = @[@(1), @(2), @(3), @(4), @(5)];
 NSArray *mapNums = [nums map:^id(id obj){
                        return [obj integerValue] * 2;
                    }];
 
 // 这时mapNums中的数据会变成    2 4 6 8 10
 
 */
- (NSArray *)map:(id (^)(id obj))map;

- (NSArray *)mapI:(id (^)(id obj, NSUInteger ind))map;

- (NSArray *)flatMap:(id (^)(id obj))flatMap;

+ (NSArray *)mapNumber:(NSUInteger)num map:(id (^)(NSUInteger index))map;

- (NSArray *)filter:(BOOL (^)(id obj, NSInteger ind))filter;

- (NSArray *)next:(void (^)(NSArray *array))next;

- (id)checkExistsWithBlock:(BOOL (^)(id obj))block;

/**
 类似于python中的reduce
 比如要计算从1加到5
 NSArray *nums = @[@(1), @(2), @(3), @(4), @(5)];
 NSNumber *res = [nums reduce:^id(id obj1, id obj2){
                        return @([obj1 integerValue] + [obj2 integerValue]);
                    }];
 
 这时候res的值会是15
 
 */
- (id)reduce:(id (^)(id obj1, id obj2))reduce;

- (instancetype)removeObjectsFromIndex:(NSUInteger)index;

- (instancetype)replaceObjectForIndex:(NSUInteger)index withObject:(id)object;

- (instancetype)replaceObjectsFromIndex:(NSUInteger)index withObjects:(NSArray *)objects;

+ (NSArray *)randomArrayWithCount:(NSUInteger)count;

/**
 * 获取最大公约数
 * - 最小值：1
 * - 数组内容要求NSNumber类型，非Number时返回1
 * - 大于1，说明可公约
 */
- (NSInteger)tb_gcdValue;

@end
