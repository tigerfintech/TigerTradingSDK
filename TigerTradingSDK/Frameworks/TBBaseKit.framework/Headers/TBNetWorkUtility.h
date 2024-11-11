//
//  TBNetWorkUtility.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/2/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBNetWorkUtility : NSObject

//截取URL中的参数
+ (NSMutableDictionary *)getURLParameters:(NSString *)urlStr;

//将Dictionary转为URL类型参数
+ (NSString *)covertDictionaryToURLParameters:(NSDictionary *)dictionary;

// url encode 处理url里特殊字符编码
+ (NSString *)getUrlEncodeString:(NSString *)content;

// 从url query 里parse parameters.返回 参数pair
+ (NSDictionary*)queryDictionaryUsingEncoding:(NSString *)query encoding:(NSStringEncoding)encoding;

// 展示网络错误时的文案
+ (NSString *)getNetWorkingErrorHintText:(NSError *)error;

/**
 Omnibus从Error中提取错误信息

 @param error error
 @param errorKey errorKey
 @return 返回的用于展示的错误信息
 */
+ (NSString *)messageFromErrorObject:(NSError *)error errorKey:(NSString *)errorKey;

+ (NSString *)tbutilscovert_toString:(id)obj;

+ (NSDictionary *)tbutilscovert_toDictionaryOrNil:(id)obj;

+ (NSArray *)tbutilscovert_toArrayOrNil:(id)obj;

+ (NSString *)messageFromErrorObject:(NSError *)error defaultMessage:(nullable NSString *)message;


/**
 部分接口返回的状态码不是200，AFNetworking会序列化错误，如果无法从data里解析出message信息，
 调用getNetWorkingErrorHintText方法根据code设置message
 */
+ (NSString *)failureMsgWithError:(NSError *)error;

// 展示网络错误时的文案,针对股票行情合约接口
+ (NSString *)getNetWorkingErrorHintMessage:(NSError *)error;


@end

NS_ASSUME_NONNULL_END
