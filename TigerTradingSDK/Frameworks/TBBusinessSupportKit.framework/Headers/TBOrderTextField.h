//
//  TBOrderTextField.h
//  Stock
//
//  Created by donggongfu on 15/11/20.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBStockFutureTextField.h>

typedef NS_ENUM(NSInteger, TBOrderTextFieldContentAlignmentType) {
    TBOrderTextFieldContentAlignmentTypeDefault,    ///< - 输入框 +
    TBOrderTextFieldContentAlignmentTypeLeft,       ///< 输入框 - +
};

@interface TBOrderTextField : TBStockFutureTextField

@property (nonatomic, assign) double leftMinimumPriceVariation;/// 点击 - 号增加的单位
@property (nonatomic, assign) double rightMinimumPriceVariation;/// 点击 + 号增加的单位

@property (nonatomic, assign) double leftMinimumPriceValidateScale;/// 点击 - 号增校验单位，解决 美股碎股整数 +- 的问题
@property (nonatomic, assign) double rightMinimumPriceValidateScale;/// 点击 + 号校验的单位，解决 美股碎股整数 +- 的问题

//@property (nonatomic, assign) BOOL priceFormatter;

@property (nonatomic, copy) void (^stepBtnClickedBlock)(BOOL isPlus);

@property (nonatomic, copy) void (^becomeFirstResponderBlock)(void);

@property (nonatomic, copy) BOOL (^canResignFirstResponderBlock)(void);

@property (nonatomic, assign) TBOrderTextFieldContentAlignmentType contentAlignmentType;///< 对齐方式

@property (nonatomic, strong, readonly) UIButton *leftButton;
@property (nonatomic, strong, readonly) UIButton *rightButton;

@property (nonatomic, assign) BOOL isFromLongPress;                 ///< 是否是长按
@property (nonatomic, assign, readonly) BOOL isLeftButtonEvent;     ///< 是否左按钮点击事件
@property (nonatomic, assign, readonly) BOOL isRightButtonEvent;    ///< 是否右按钮点击事件

@property (nonatomic, copy) NSString *preffixText;///< 输入框内输入文案前的提示，有的话，则显示，nil 则不显示

@property (nonatomic, assign) BOOL disableFixMinimumFractionShareDigits;///< 禁止根据 最小变动单位来设置 formatter 的 minimum，美股碎股需求，有几位小数显示几位小数（不包括最后一位为0）; 默认 false

- (void)setPreffixTextLabelFont:(UIFont *)font;

- (void)setButtonTouchArea:(UIEdgeInsets)area isLeftBtn:(BOOL)isLeft;

@end

