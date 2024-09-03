//
//  TBStockTransactionKeyBoardView.h
//  Stock
//
//  Created by luopengfei on 2018/7/23.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBBaseKit/NSString+TBProcess.h>

#define KeyboardViewHeight 210

@class TBStockFutureTextField;
@interface TBStockTransactionKeyBoardView : UIView
/**
 键盘上面的辅助视图
 */
@property (retain, nonatomic) UIView *assistantView;

/**
 键盘上面显示信息的label
 */
@property (copy, nonatomic) NSString *assistantInfo;
@property (copy, nonatomic) NSAttributedString *assistantAttributeInfo;

@property (nonatomic, copy) void (^keyBoardHiddenClicked)(BOOL);
@property (nonatomic, copy) void (^keyBoardOKClicked)(void);
@property (nonatomic, copy) dispatch_block_t changePriceInputTypeBlock;

@property (nonatomic, copy) dispatch_block_t dotBtnClickedBlock;///< 点击小数点按钮

@property (nonatomic, weak) UIView *customInputView;///<  自定义 输入选项 引用，默认不显示，supportChangeInputOption 控制
@property (nonatomic, assign) BOOL supportChangeInputOption;///< 是否支持自定义输入选项（1、2、3... 数字区域键盘，是否可以改为其他键盘）

/**
 小数点位置按键的类型
 */
@property (assign, nonatomic) NSInteger dotKeyType;

/// 隐藏按钮负数设置
@property (nonatomic, assign) NSInteger hideKeyType;

@property (nonatomic, copy) NSString *customOkBtnTitle;///< 自定义 确定按钮的文案

@property (nonatomic, assign) BOOL isNegativeSignEnable; ///< 正则支持负数校验，eg: -0.01, 能通过正则校验

- (void)resetHiddenButtonSelectedStatus;

- (void)resetOkBtnTitle;

/**
 绑定到键盘上的输入框
 */
@property (weak, nonatomic) TBStockFutureTextField *textField;

@end
