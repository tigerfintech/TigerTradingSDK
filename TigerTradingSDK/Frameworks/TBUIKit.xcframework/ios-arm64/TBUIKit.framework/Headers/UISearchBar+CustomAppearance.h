//
//  UISearchBar+CustomAppearance.h
//  Stock
//
//  Created by yangfan on 2018/4/12.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UISearchBar(CustomAppearance)

@property (nonatomic, strong) UIColor * textFieldBackgroundColor;

- (UITextField *)searchBarTextField;

- (void)setTextFieldFont:(UIFont *)font textColor:(UIColor *)color;

- (void)setPlaceholder:(NSString *)placeholder;

- (void)setPlaceholder:(NSString *)placeholder textColor:(UIColor *)color;

- (void)setPlaceholder:(NSString *)placeholder withFont:(UIFont *)font textColor:(UIColor *)color;

- (void)setTextFieldBackgroundColor:(UIColor *)color cornerRadius:(CGFloat)cornerRadius;

- (void)setSearchBarBackgroundColor:(UIColor *)color;

- (void)setSelectedRange:(NSRange)range;

@end
