//
//  TBBaseModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/6.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBModelArchiveDelegate

@optional

/**
 解档的时候，对于新旧版本的一些默认参数的设置的处理
 
 如果在新版本添加了一些属性，在解档的时候，就会没有默认值，特别是对于基本数据类型如BOOL、Int等，不好判定，所以加了这个代理方法
 只需要在需要归档解档的model里实现一下这个方法，根据方法里的属性名称去返回默认值即可
 
 @param propertyName 需要兼容的属性名称
 @param cls 这个属性所在的类，因为归档、解档的时候是类递归往上去做的，所以这个参数可能不是当前的类
 @return 对于这个属性的默认值
 */
- (id)defaultValueForUnarchiveUnContainsProperty:(NSString *)propertyName ofClass:(Class)cls;

@end



@interface TBBaseModel : JSONModel <TBModelArchiveDelegate>

@property (nonatomic, strong) NSNumber *ret;

@end

NS_ASSUME_NONNULL_END

