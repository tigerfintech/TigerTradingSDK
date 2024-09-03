//
//  TBMessageBox.h
//  Stock
//
//  Created by yangfan on 2019/5/29.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBCommonConfirmView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBMessageBox : TBCommonConfirmView

@property (nonatomic, copy) NSString * message;

- (instancetype)initWithTitle:(nullable NSString *)title message:(nullable NSString *)message;

// 确认、取消 上下排列
- (instancetype)initVerticalStyleWithTitle:(nullable NSString *)title message:(nullable NSString *)message;

- (instancetype)initWithTitle:(nullable NSString *)title attributedMessage:(nullable NSAttributedString *)attributedMessage;

- (instancetype)initWithTitle:(nullable NSString *)title attributedString:(nullable NSAttributedString *)attributedString;

@end

NS_ASSUME_NONNULL_END
