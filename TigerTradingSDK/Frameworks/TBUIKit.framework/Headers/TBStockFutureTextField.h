//
//  TBStockFutureTextField.h
//  Stock
//
//  Created by luopengfei on 2018/7/23.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBStockTransactionKeyBoardView.h"

typedef NS_ENUM(NSUInteger, TBKeyboardKeyType) {
    TBKeyboardKeyTypeUnknown   = 0,
    TBKeyboardKeyTypeNumber    = 1,
    TBKeyboardKeyTypeDot       = 2,
    TBKeyboardKeyTypeDelete    = 3,
    TBKeyboardKeyTypeHide      = 4,
};

typedef NS_ENUM(NSUInteger, TBCustomKeyboardType) {
    TBSystemKeyboardType,
    TBCustomKeyboardTypePriceInput,
    TBCustomKeyboardTypeCount,
    TBCustomKeyboardTypeChangeableCount,
    TBCustomKeyboardTypeUSFracChangeableCount,
    TBCustomKeyboardTypeTradersPassword,
    
};

typedef NS_ENUM(NSUInteger, TBDotKeyType) {
    TBDotKeyTypeDisable,
    TBDotKeyTypeDot,
    TBDotKeyTypeInterest,
    TBDotKeyTypeHidden,
    TBDotKeyTypeCountDot,
    TBDotKeyTypeCountNoDot,

};

typedef NS_ENUM(NSUInteger, TBHideKeyType) {
    TBHideKeyTypeHide = 0,
    TBHideKeyTypeMinus = 1,
    TBHideKeyTypeDown = 2, ///< 向下箭头
};

@protocol TBKeyboardDeletage <NSObject, UITextFieldDelegate>

@optional

/**
 键盘上按钮点击事件的代理方法
 
 @param textField 当前的输入框
 @param keyType 键盘上按键的类型
 @param value 按钮点击后的值，如果是删除、enter、增加、减少会是nil
 @return 是否可以把内容添加到输入框
 */
- (BOOL)textField:(UITextField *)textField clickKeyboardWithKeyType:(TBKeyboardKeyType)keyType value:(NSString *)value;

/**
 输入框内的内容改变以后，交易相关的自定义键盘使用
 
 @param textField 当前的输入框
 */
- (void)textFieldTextDidChanged:(UITextField *)textField;

- (NSString *)displayPriceFromNum:(NSNumber *)number;
/**
 * 是否需要将显示的字符串转化为数值, 期货有用到
 */
- (BOOL)shouldConvertFromDisplayStringToPriceNum:(NSString *)string textField:(UITextField *)textField;;

- (NSNumber *)priceNumFromDisplayString:(NSString *)string;
/**
 * 是否需要将数值转换为显示的字符串, 期货有用到
 */
- (BOOL)shouldConvertFromPriceNumToDisplayString:(NSString *)string textField:(UITextField *)textField;;

/**
 * 输入过程中，textField.text里的某些特殊字符替换成空串
 * @return 需要被替换成空串的字符串数组
 */
- (NSArray *)occurrencesOfStringShouldBeRepacedWithEmpetyString:(UITextField *)textField;



/**
 用于计算的最新价，主要解决期货显示对手价、市价、排队机价、最新价，用户点击+-初始计算价格
 */
@property (nonatomic, strong) NSNumber *calLatestPrice;

@end

/**
 键盘上按钮点击事件的block方法
 
 @param textField 当前的输入框
 @param keyType 键盘上按键的类型
 @param value 按钮点击后的值，如果是删除、enter、增加、减少会是nil
 @return 是否可以把内容添加到输入框
 */
typedef BOOL (^TBKeyboardClickedBlock) (UITextField *textField, TBKeyboardKeyType keyType, NSString *value);

@interface TBStockFutureTextField : UITextField {
    TBStockTransactionKeyBoardView *_keyboardView;
}

/**
 自定义输入源键盘的类型
 */
@property (assign, nonatomic) TBCustomKeyboardType customKeyboardType;
/**
 最大文本长度
 */
@property (assign, nonatomic) NSInteger maxLength;

/**
 键盘上按钮点击的事件代理
 */
@property (weak, nonatomic) id<TBKeyboardDeletage> priceKeyboardDelegate;

/**
 键盘按钮的点击事件回调
 */
@property (copy, nonatomic) TBKeyboardClickedBlock keyboardClickedBlock;

@property (nonatomic, copy) void (^keyBoardHiddenClicked)(BOOL);
@property (nonatomic, copy) void (^keyBoardOKClicked)(void);
@property (nonatomic, copy) dispatch_block_t changePriceInputTypeBlock;

#pragma mark - 价格、手数输入键盘相关
#pragma mark -

/**
 键盘上面显示信息
 */
@property (copy, nonatomic) NSString *assistantInfo;
@property (copy, nonatomic) NSAttributedString *assistantAttributeInfo;

/**
 键盘上面的辅助视图
 */
@property (retain, nonatomic) UIView *keyboardAssistantView;

/**
 小数点位置按键的类型
 */
@property (assign, nonatomic) TBDotKeyType dotKeyType;

/**
 输入框的默认内容，当输入框文本为空时显示的
 */
@property (retain, nonatomic) NSString *defaultValue;

/// 隐藏按钮的类型
@property (nonatomic, assign) TBHideKeyType hideKeyType;

@property (assign, nonatomic, readonly) NSRange selectedTextNSRange;

@property (nonatomic, strong) NSNumberFormatter *formatter;

@property (nonatomic, assign) BOOL supprtCustomInputView;///< 是否支持自定义输入区域
@property (nonatomic, strong) UIView *customInputView;///< 是否支持自定义输入区域
@property (nonatomic, assign) BOOL isOptionVirtual;///是否为期权模拟交易

@property (nonatomic, strong, readonly)TBStockTransactionKeyBoardView *keyboardView;

@property (nonatomic, assign) BOOL isNegativeSignEnable; ///< 正则支持负数校验，eg: -0.01, 能通过正则校验

- (void)makeOffset:(NSInteger)offset;

@end
