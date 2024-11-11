//
//  TBTextLinkAlertController.h
//  Stock
//
//  Created by 董恭甫 on 2017/8/18.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBBaseViewController.h"
#import <TBUIKit/TTTAttributedLabel.h>

@interface TBTextLinkAlertController : TBBaseViewController

// UI
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) TTTAttributedLabel *attributedLabel;
@property (nonatomic, strong) UIButton *leftButton;
@property (nonatomic, strong) UIButton *rightButton;
@property (nonatomic, strong) UIButton *centerButton;

@property (nonatomic, copy) NSDictionary *params;///< 额外参数

// out
@property (nonatomic, assign, readonly) CGFloat height;
@property (nonatomic, assign, readonly) BOOL isLeft;
@property (nonatomic, assign, readonly) BOOL isRight;

@property (nonatomic, copy) NSString *titleString;
@property (nonatomic, copy) NSString *textString;
@property (nonatomic, copy) NSDictionary *links;
@property (nonatomic, copy) NSString *leftButtonTitle;
@property (nonatomic, copy) NSString *rightButtonTitle;
@property (nonatomic, copy) NSString *centerButtonTitle;

@property (nonatomic, assign) BOOL quickOrderPresent;  //!< 快捷下单
@property (nonatomic, copy) NSString *webURL;     //!< 需要跳转的链接
// TODO: init方法和对应的TB://链接

@property (nonatomic, copy) void (^willSelectLink)(void);
@property (nonatomic, copy) void (^selectConfirmBlock)(void);

@end
