//
//  NSDictionary+TBDataAssignment_m.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/1/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (TBDataAssignment)

/**
 *  防止某些未用json model 或者mantle 类接收的数据， 从server获取，使用非法key的情况
 */
- (id)tb_safeValueForKey:(NSString *)key;

@end

@interface NSMutableDictionary<KeyType, ObjectType>(TBDataAssignment)
/**
 *  向字典中添加值，如果object或者key为空则什么也不做
 */
- (void)tb_safeSetObject:(ObjectType)object forKey:(KeyType <NSCopying>)key;

@end

NS_ASSUME_NONNULL_END
