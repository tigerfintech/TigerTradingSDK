//
//  TBRoundRectButton.h
//  TBUIKit
//
//  Created by chenxin on 2024/5/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 圆角按钮，可设置标题边距，提供block回调
 cornerRadius默认为4
 */

typedef NS_ENUM(NSUInteger, TBRoundRectButtonStyle) {
    TBRoundRectButtonStyleBorder, // 带边框，边框颜色默认为B3，标题颜色默认为B1
    TBRoundRectButtonStyleYellow, // 黄色背景，标题颜色默认为B32
};

@interface TBRoundRectButton : UIControl

@property (nonatomic, assign) TBRoundRectButtonStyle style;

// 点击回调
@property (nonatomic, strong) void(^touchUpInsideBlock)(void);

// 设置标题
- (void)setTitle:(NSString *)title;

// 设置标题字体，默认为MEDFONTO(14)
- (void)setTitleFont:(UIFont *)titleFont;

// 设置标题颜色
- (void)setTitleColor:(UIColor *)titleColor;

// 设置标题边距，默认为上下4，左右12
- (void)setTitleEdgeInsets:(UIEdgeInsets)titleEdgeInsets;

@end

NS_ASSUME_NONNULL_END
