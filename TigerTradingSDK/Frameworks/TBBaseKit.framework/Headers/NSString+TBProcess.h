//
//  StringUtil.h
//  Peter Steinberger
//

#import <UIKit/UIKit.h>
//#import "TBConstantString.h"

@interface NSString (TBProcess)

- (NSString *)trimmedString;
- (NSString *)htmlDecodedString;
- (NSString *)htmlEncodedString;

- (NSString *)spac32FromString;//过来字符串，统一编码160字符为32位空格字符‘ ’。

// 去掉字符串中所有空白字符
- (NSString *)stringByDeletingWhitespaceCharacters;

@end

@interface NSString  (RangeAvoidance)

- (BOOL) hasSubstring:(NSString*)substring;
- (NSString*) substringAfterSubstring:(NSString*)substring;

//Note: -isCaseInsensitiveLike is probably a better alternitive if it's avalible.
- (BOOL) isEqualToStringIgnoringCase:(NSString*)otherString;

@end

@interface NSString (IndempotentPercentEscapes)

#pragma mark long_add 2015.9.28
- (CGRect)txtFrameWith:(UIFont *)font andMaxWidth:(CGFloat)maxW;
- (CGRect)txtFrameWith:(UIFont *)font lineSpacing:(CGFloat)spacing andMaxWidth:(CGFloat)maxW;
- (CGRect)getTextFrame:(UIFont *)font andMaxWidth:(CGFloat)maxW;
- (BOOL) validateMobile;
- (NSString *)htmlConDelete;
@end

@interface NSString (OpenAccountCheck)

- (NSString *)stringByRemovingHtmlTag;

// 是密码支持的字符: a-z、A-Z、0-9和常用英文标点符号
- (BOOL)tb_isSupportedPasswordChar;

- (BOOL)tb_isPureNumber;
- (BOOL)tb_isPureLetter;
- (BOOL)tb_isPureCharacter;
- (BOOL)tb_isPureFuturesPrice;

// 是否是纯字母或数字（包含小数点+-）
- (BOOL)tb_isPureNumberOrLetter;
- (BOOL)tb_isLegalObjectWithPattern:(NSString *)pattern;

@end

@interface NSString (TBAddition)

/**
 小数去除末位无效零问题

 @param floatValue 浮点型数据
 @return 去掉无效零后字符串
 */
+ (NSString *)changeFloatWithFloat:(CGFloat)floatValue;

/**
 小数去除末位无效零问题

 @param stringFloat 浮点型字符串
 @return 去掉无效零后字符串
 */
+ (NSString *)changeFloatWithString:(NSString *)stringFloat;

/// 正则匹配字符串子集
/// @param pattern pattern description
- (NSString *)matchResultWithPattern:(NSString *)pattern;

- (NSString *)tb_toSpelling;

@end
