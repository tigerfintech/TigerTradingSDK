//
//  NSArray+TBDataAssignment.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/1/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray<ObjectType> (TBDataAssignment)

/**
 *  获取指定index的object，如果index越界，返回nil
 */
- (ObjectType)tb_safeObjectAtIndex:(NSUInteger)index;

/**
 *  获取指定ranage的array
 */
- (NSArray <ObjectType>*)tb_safeSubarrayWithRange:(NSRange)range;


- (NSUInteger)tb_safeIndexOfObject:(ObjectType)object;

@end

@interface NSMutableArray<ObjectType> (TBDataAssignment)
/**
 *  添加object至数组尾部，如果anObject为nil，则此操作被忽略
 */
- (void)tb_safeAddObject:(ObjectType)anObject;
/**
 *  删除指定index的object，如果index越界，则忽略此操作
 */
- (void)tb_safeRemoveObjectAtIndex:(NSUInteger)index;
/**
 *  删除指定object，如果anObject为nil,则此操作被忽略
 */
- (void)tb_safeRemoveObject:(ObjectType)anObject;
/**
 *  批量删除数组,如果数组对象为nil,忽略此操作
 */
- (void)tb_safeRemoveObjectsInArray:(NSArray<ObjectType> *)array;
/**
 *  插入object至数组指定index，如果anObject为nil或index越界，则此操作被忽略
 */
- (void)tb_safeInsertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
/**
 *  在指定index替换anObject，如果anObject为nil或index越界，则此操作被忽略
 */
- (void)tb_safeReplaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;
/**
 *  批量插入数组,如果数组对象为nil,忽略此操作
 */
- (void)tb_safeAddObjectsFromArray:(NSArray<ObjectType> *)array;

@end
NS_ASSUME_NONNULL_END
