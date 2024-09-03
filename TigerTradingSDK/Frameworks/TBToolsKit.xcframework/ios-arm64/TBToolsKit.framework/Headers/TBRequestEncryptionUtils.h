//
//  TBRequestEncryptionUtils.h
//  Stock
//
//  Created by chenxin on 2021/5/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBRequestEncryptionUtils : NSObject

// 对请求进行加密处理
+ (NSURLRequest *)encryptedRequestWithRequest:(NSURLRequest *)request;

// 对响应进行解密处理
+ (id)decryptedResponseObjectWithResponseObject:(id)responseObject;

// query转换成字典（不解码）
+ (NSDictionary *)dictionaryWithQuery:(NSString *)query;

// 字典转换成key升序的query字符串
+ (NSString *)sortedQueryStringWithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
