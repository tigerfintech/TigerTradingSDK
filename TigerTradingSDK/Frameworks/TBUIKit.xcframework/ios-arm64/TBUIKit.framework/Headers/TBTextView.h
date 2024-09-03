//
//  TBTextView.h
//  Stock
//
//  Created by ChenXin on 17/2/24.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBTextView : UITextView

@property (nonatomic, copy) NSString *placeholder;

@property (nonatomic, strong) UIColor *placeholderColor;

@property (nonatomic, strong) UILabel *placeholderLabel;

@property (nonatomic, assign) NSInteger maxLength;//最大输入字符串长度

@property (nonatomic, copy) void(^handleOverLimitBlock)(void);//超过输入限制回调

@end
