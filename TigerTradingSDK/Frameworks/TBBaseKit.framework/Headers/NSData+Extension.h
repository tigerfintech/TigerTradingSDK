//
//  NSData+Extension.h
//  Stock
//
//  Created by WCP on 2018/10/18.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (Extension)

/**
 转UTF8格式

 @return UTF8格式String
 */
- (NSString *)UTF8String;

/**
 string转NSData，Base64编码
 
 @param base64String 需要转的string
 @return NSData数据
 */
- (id)initWithBase64String:(NSString *)base64String;

/**
 NSData转Base64编码的string

 @return Base64编码的string
 */
- (NSString *)base64EncodedString;

@end
