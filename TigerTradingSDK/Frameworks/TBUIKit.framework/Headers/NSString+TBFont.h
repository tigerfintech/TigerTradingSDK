//
//  NSString+TBFont.h
//  ACETelPrompt
//
//  Created by linbingjie on 2021/4/9.
//

#import <Foundation/Foundation.h>
#import "TBFont.h"
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TBFont)
/**
 将字符串中数字高亮
 */
-(NSMutableAttributedString*)attributedStringColor:(UIColor *)color numHighlightedColor:(UIColor *)highLighted;
- (NSMutableAttributedString *)attributedStringColor:(UIColor *)color font:(UIFont *)font  numFont:(UIFont *)numFont;

-(NSMutableAttributedString*)attributedStringColor:(UIColor *)color numHighlightedColor:(UIColor *)highLighted font:(UIFont *)font numFont:(UIFont *)numFont;

- (UIFont *)tbFontSize:(float)size;

- (UIFont *)tbBoldFontSize:(float)size;

- (UIFont *)tbCharacterFont:(UIFont *)font  numFont:(UIFont *)numFont;
@end

NS_ASSUME_NONNULL_END
