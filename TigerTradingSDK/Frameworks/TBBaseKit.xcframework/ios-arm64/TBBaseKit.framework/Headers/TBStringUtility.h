//
//  TBStringUtility.h
//  TBBaseKit
//
//  Created by zhengzhiwen on 2021/6/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStringUtility : NSObject

// 字符里是否含有非英文字符
+ (BOOL)hasNonEnglishCharacter:(NSString *)text;

// md5
+ (NSString *)getMd5String:(NSString *)input;

// 跟 9:30 的 minutes offset
+ (NSInteger)minitesOffset:(NSString *)target;

// 跟 0:00 的minutes offset.
+ (NSInteger)minitesOffsetZero:(NSString *)target;

// 下个月
+ (NSString *)nextMonth:(NSString *)dateString;

// 字符串截取
+ (NSString*)subStringLength:(NSInteger)length string:(NSString *)string;

// 英文消息转中文
+ (NSString *)transferEngMsg2Chn:(NSString *)msg;

/**
 字符串截取

 @param length 截取字符串长度
 @param string 被截取字符串
 @param hasSuff 是否需要后缀‘.’
 @return 截取后字符串
 */
+ (NSString *)subStringLength:(NSInteger)length string:(NSString *)string hasSuff:(BOOL)hasSuff;
+ (int)countTheStrLength:(NSString *)strtemp;

// 获取text 在font下的 rect size
+ (CGSize)getStringRectWithFont:(NSString *)text withFont:(UIFont *)font;

//转换使用,作为分隔符
//数组转换成字符串
+ (NSString *)convertStringFromArray:(NSArray *)array;

//字符串转换成数组
+ (NSArray *)convertArrayFromString:(NSString *)string;

//检查邮箱格式
+ (BOOL)isCorrectEmail:(NSString *)email;

// !十进制分隔符
+ (NSString *)decimalSeparator;

/**
  获取string的高度

 @param string string
 @param lineSpacing 行间距
 @param font 自读
 @param width 宽度
 @return 高度
 */
+ (CGFloat)getString:(NSString *)string lineSpacing:(CGFloat)lineSpacing font:(UIFont*)font width:(CGFloat)width ;

+ (NSDate *)dateWithString:(NSString *)dateString formatString:(NSString *)formatString timeZone:(NSTimeZone *)timeZone locale:(NSLocale *)locale;

/// 判断字符串是否为非法字符串
/// @param string <#string description#>
+ (BOOL)isInvalidString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
