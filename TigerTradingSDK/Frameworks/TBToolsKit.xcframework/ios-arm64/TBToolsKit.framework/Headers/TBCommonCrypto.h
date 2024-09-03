//
//  TBCommonCrypto.h
//  Stock
//
//  Created by chenxin on 2021/5/18.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonCrypto : NSObject

/**
 *  HmacSHA256加密
 *
 *  @param content 要加密的文本
 *  @param key 秘钥
 *
 *  @return 加密后的数据
 */
+ (NSData *)hmacWithContent:(NSString *)content key:(NSString *)key;

/**
 *  md5加密
 *  @param content 要加密的文本
 *
 *  @return 加密后的字符串
 */
+ (NSString *)md5StringWithString:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
