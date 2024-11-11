//
//  UITextField+Helper.h
//  Stock
//
//  Created by xw.long on 15/10/27.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (Helper)


- (void)limitTextLength:(int)length;

- (UILabel *)placeholderTextLabel;

- (void)setPlaceholderFont:(UIFont *)font;

- (void)setPlaceholderTextColor:(UIColor *)color;

- (void)shakeAnimationForView;

@end
