//
//  UILabel+Helper.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (Helper)

- (id) initWithFrame:(CGRect)frame size:(CGFloat)size;
- (id) initWithFrame:(CGRect)frame size:(CGFloat)size color:(UIColor *)color;
- (id) initWithFrame:(CGRect)frame font:(UIFont *)font color:(UIColor *)color;
- (id) initWithFont:(UIFont *)font color:(UIColor *)color;
- (id) initWithFrame:(CGRect)frame font:(UIFont *)font color:(UIColor *)color text:(NSString *)text;
+ (UILabel *)createLabelWithFont:(UIFont *)font
                   textAlignment:(NSTextAlignment)textAlignment
                       textColor:(UIColor *)textColor
                   lineBreakMode:(NSLineBreakMode)lineBreakMode
                   numberOfLines:(NSInteger)numberOfLines
                            text:(NSString *)text;

- (void)setText:(NSString *)text lineSpace:(CGFloat)lineSpace;
- (void)setText:(NSString *)text lineSpace:(CGFloat)lineSpace headIndent:(CGFloat)headIndent;
- (void)setText:(NSString *)text numberFont:(UIFont *)font;
- (void)setText:(NSString *)text numberFont:(UIFont *)font numTextColor:(UIColor *)color;
//适用于字母以及数字
- (void)setText:(NSString *)text asciiFont:(UIFont *)font;
- (void)setText:(NSString *)text lineSpace:(CGFloat)lineSpace headIndent:(CGFloat)headIndent numberFont:(UIFont *)font;

//两端对齐的文字
- (void)setAlignmentJustifiedText:(NSString *)text lineSpace:(CGFloat)lineSpace;
//获取文本高度
- (CGFloat)attributedStringHeight:(CGFloat)lineSpace;

- (CGFloat)attributedTextHeight:(CGFloat)maxWidth;

+ (CGFloat)heightForAttributedText:(NSString *)text font:(UIFont*)font lineSpace:(CGFloat)lineSpace maxWidth:(CGFloat)maxWidth;
+ (CGFloat)heightForAttributedText:(NSString *)text font:(UIFont*)font lineSpace:(CGFloat)lineSpace maxWidth:(CGFloat)maxWidth headIndent:(CGFloat)headIndent;
+ (CGFloat)heightForAttributedText:(NSString *)text font:(UIFont*)font lineSpace:(CGFloat)lineSpace maxWidth:(CGFloat)maxWidth headIndent:(CGFloat)headIndent numberOfLines:(CGFloat)numberOfLines;

+ (CGFloat)heightForAttributedText:(NSString *)text font:(UIFont*)font lineSpace:(CGFloat)lineSpace maxWidth:(CGFloat)maxWidth headIndent:(CGFloat)headIndent numberOfLines:(CGFloat)numberOfLines numberFont:(UIFont *)numberFont;

+ (CGFloat)heightForAttributedText:(NSString *)text fontSize:(NSInteger)fontSize lineSpace:(CGFloat)lineSpace maxWidth:(CGFloat)maxWidth;
+ (CGFloat)heightForAttributedText:(NSString *)text fontSize:(NSInteger)fontSize lineSpace:(CGFloat)lineSpace maxWidth:(CGFloat)maxWidth headIndent:(CGFloat)headIndent;

+ (CGFloat)singleLineHeight:(UIFont *)font;

- (void)alightLeftAndRightWithWidth:(CGFloat)labelWidth;


+ (NSArray *)linesOfString:(NSString *)contentText labelWidth:(CGFloat)labelWidth attributeSet:(nullable NSMutableAttributedString *)attStr fontSize:(CGFloat)fontSize;
@end


/// 文档：https://app.asana.com/0/1170963298546041/1171105037952795
@interface UILabel (Animation)

@property (nonatomic, strong) UIColor *animationColor;
@property (nonatomic, copy) NSString *preContent;

- (void)setAnimationContent:(NSString *)content;
- (void)setAnimationContent:(NSString *)content animationNeed:(BOOL)animationNeed;

@end
