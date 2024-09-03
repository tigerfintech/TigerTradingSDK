//
//  NSDictionary+TBKNetwork.h
//  TigerBrokersKit
//
//  Created by donggf on 2018/8/21.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (TBKNetwork)

/**
 字符串前面是没有问号的，如果用于POST，那就不用加问号，如果用于GET，就要加个问号

 @param isForSignature <#isForSignature description#>
 @return <#return value description#>
 */
- (NSString *)tbk_urlParamsStringSignature:(BOOL)isForSignature;

/**
 字典变json
 */
- (NSString *)tbk_jsonString;

/**
 转义参数

 @param isForSignature <#isForSignature description#>
 @return <#return value description#>
 */
- (NSArray *)tbk_transformedUrlParamsArraySignature:(BOOL)isForSignature;

- (NSString *)tbk_transformToUrlParamString;

@end
