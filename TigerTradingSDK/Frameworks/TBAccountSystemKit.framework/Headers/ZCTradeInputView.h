//
//  ZCTradeInputView.h
//  直销银行
//
//  Created by 塔利班 on 15/4/30.
//  Copyright (c) 2015年 联创智融. All rights reserved.
//  交易输入视图

#import <Foundation/Foundation.h>

static NSString *ZCTradeInputViewCancleButtonClick = @"ZCTradeInputViewCancleButtonClick";
static NSString *ZCTradeInputViewOkButtonClick = @"ZCTradeInputViewOkButtonClick";
static NSString *ZCTradeInputViewButtonTypeWithForgetClick = @"ZCTradeInputViewButtonTypeWithForgetClick";
static NSString *ZCTradeInputViewPwdKey = @"ZCTradeInputViewPwdKey";

#import <UIKit/UIKit.h>
#import "UIView+Extension.h"

@class ZCTradeInputView;

@protocol ZCTradeInputViewDelegate <NSObject>

@optional
/** 确定按钮点击 */
- (void)tradeInputView:(ZCTradeInputView *)tradeInputView okBtnClick:(UIButton *)okBtn;
/** 取消按钮点击 */
- (void)tradeInputView:(ZCTradeInputView *)tradeInputView cancleBtnClick:(UIButton *)cancleBtn;
//忘记密码
- (void)tradeInputView:(ZCTradeInputView *)tradeInputView forgetPassword:(UIButton *)forgetBtn;
@end

@interface ZCTradeInputView : UIView
/** 自定义显示的view */
@property (nonatomic, strong) UIView    * customView;
@property (nonatomic, weak) id<ZCTradeInputViewDelegate> delegate;
@property (nonatomic, assign) BOOL isShow;
- (void)clearAllNumbers;

@end
// 版权属于原作者
// http://code4app.com (cn) http://code4app.net (en)
// 发布代码于最专业的源码分享网站: Code4App.com
