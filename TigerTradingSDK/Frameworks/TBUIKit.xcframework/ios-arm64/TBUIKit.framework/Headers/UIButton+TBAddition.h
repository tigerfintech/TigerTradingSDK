//
//  UIButton+TBAddition.h
//  Stock
//
//  Created by 董恭甫 on 2017/5/16.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TBButtonStyle) {
    TBButtonStyleBlackBackground, // 黑底黄字（白皮肤下白底橙字）
    TBButtonStyleYellowBackground, // 黄底黑字（白皮肤下橙底白字）
    TBButtonStyleGrayBackground,   // 灰底黑字 （白皮肤黑皮肤相同，一般为取消按钮）
    TBButtonStyleImageUpTextDown, // 上边图片下边文字（必须同时传入图片文字和字体才能生效）
    TBButtonStylePopCancel, // 弹框取消按钮
    TBButtonStylePopDone,    // 弹框确认按钮
};

typedef NS_ENUM(NSUInteger, TBButtonType) {
    TBButtonTypeUnknown,
    TBButtonTypeDefault,               // 默认的布局
    TBButtonTypeHorizontalImageTitle,  // 图片在左边，标题在右边
    TBButtonTypeHorizontalTitleImage,  // 图片在右边，标题在左边
    TBButtonTypeVerticalImageTitle,    // 图片在上边，标题在下边
    TBButtonTypeVerticalTitleImage,    // 图片在下边，标题在上边
};

@interface UIButton (TBAddition)

// 统一生成自定义样式按钮
+ (instancetype)buttonWithStyle:(TBButtonStyle)buttonStyle;
+ (instancetype)buttonWithStyle:(TBButtonStyle)buttonStyle title:(NSString *)title;
+ (instancetype)buttonWithStyle:(TBButtonStyle)buttonStyle title:(NSString *)title font:(UIFont *)font;
+ (instancetype)buttonWithStyle:(TBButtonStyle)buttonStyle title:(NSString *)title font:(UIFont *)font image:(UIImage *)image;

- (void)tb_centerVerticallyWithPadding:(float)padding;
- (void)tb_centerVertically;

- (void)tb_setSpaceBetweenImageAndTitle:(CGFloat)space;

// FIXME: 指定padding后image会变形, 解决后再开放这个方法
//- (void)tb_rightHorizontallyWithPadding:(float)padding;
- (void)tb_rightHorizontally;
- (void)tb_rightHorizontally_RightAligment:(float)padding;
- (void)tb_rightHorizontally_RightAligment;

/**
 重设edge，设置image、标题的位置。取得图片、文字都是normal状态下的
 
 @param type 图片、文字的排列方式
 @param margin 图片文字的间距，默认4
 @param state 要用来计算的图片、文字的按钮状态
 */
- (void)relayoutWithType:(TBButtonType)type margin:(CGFloat)margin state:(UIControlState)state;
- (void)relayoutWithType:(TBButtonType)type margin:(CGFloat)margin;
- (void)relayoutWithType:(TBButtonType)type;

- (void)blockEnable;

@end
