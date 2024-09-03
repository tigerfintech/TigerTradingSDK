//
//  ZCTradeView.h
//  直销银行
//
//  Created by 塔利班 on 15/4/30.
//  Copyright (c) 2015年 联创智融. All rights reserved.
//  交易密码视图\负责整个项目的交易密码输入

#import <UIKit/UIKit.h>

@class ZCTradeKeyboard;

@protocol ZCTradeViewDelegate <NSObject>

@optional
/** 输入完成点击确定按钮 */
- (void)finish:(NSString *)pwd;

- (void)cancel;

@end

@interface ZCTradeView : UIView

@property (nonatomic, weak) id<ZCTradeViewDelegate> delegate;

/** 自定义显示的view */
@property (nonatomic, strong) UIView    * customView;
/** 完成的回调block */
@property (nonatomic, copy) void (^finish) (NSString *passWord);

/** 快速创建 */
+ (instancetype)tradeView;

/** 弹出 */
- (void)show;
- (void)showInView:(UIView *)view;
- (UIView *)getInputView;

/** 消失 */
- (void)dismiss;

- (void)clear;

- (void)shake;

@end
// 版权属于原作者
// http://code4app.com (cn) http://code4app.net (en)
// 发布代码于最专业的源码分享网站: Code4App.com
