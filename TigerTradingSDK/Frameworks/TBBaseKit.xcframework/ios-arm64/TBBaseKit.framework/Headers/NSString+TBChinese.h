//
//  NSString+TBChinese.h
//  Stock
//
//  Created by Tiger on 2018/12/17.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_OPTIONS(NSUInteger, TBNSStringChineseType) {   // Chinese Type 中文字符类型
    TBNSStringChineseTypeCharacter              = 1 << 0, // Chinese Character 中文文字
    TBNSStringChineseTypePunctuation            = 1 << 1, // Chinese Punctuation 中文标点
    TBNSStringChineseTypeRadical                = 1 << 2, // Chinese Radical 中文部首
    TBNSStringChineseTypeStroke                 = 1 << 3, // Chinese Stroke 中文笔划
    TBNSStringChineseTypeIdeographicDescription = 1 << 4, // Chinese Ideographic Description 中文构字描述符
    TBNSStringChineseTypeAll = TBNSStringChineseTypeCharacter | TBNSStringChineseTypePunctuation | TBNSStringChineseTypeRadical | TBNSStringChineseTypeStroke | TBNSStringChineseTypeIdeographicDescription
};
@interface NSString (TBChinese)
/**
 Returns whether the receiver is a Chinese string(one-character) in the specified type.
 
 @param type The Chinese type. Pass 0 to specify all types.
 @return YES if the receiver is a Chinese string(one-character), otherwise NO.
 */
- (BOOL)tb_isChinese:(TBNSStringChineseType)type;
@end

NS_ASSUME_NONNULL_END
