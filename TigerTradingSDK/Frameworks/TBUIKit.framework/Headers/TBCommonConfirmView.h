//
//  TBCommonConfirmView.h
//  Stock
//
//  Created by yangfan on 2017/3/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TTTAttributedLabel.h>

#define ConfirmViewCloseButtonSelectedIndex -1
#define ConfirmViewCancelButtonSelectedIndex 0
#define ConfirmViewConfirmButtonSelectedIndex 1

#define     ConfirmViewDefaultViewWidth            300
#define     ConfirmViewViewPaddding                15
#define     ConfirmViewViewButtonHeight               36

#define ConfirmViewMaxHeight 480
#define ConfirmViewMaskTag 0xAF45
#define ConfirmViewCloseBtnTag 0xAF46

typedef enum : NSInteger{
    TBCommonButtonTypeCancel = 0,
    TBCommonButtonTypeOk,
    TBCommonButtonTypeClose,
}TBCommonButtonType;

@class TBCommonConfirmView;

@protocol TBCommonConfirmViewDelegate <NSObject>

@optional

- (void)confirmView:(TBCommonConfirmView *)confirmView didSelectedAtIndex:(NSInteger)index;

- (void)confirmViewWillDisappear:(TBCommonConfirmView *)confirmView;

@end

@interface TBCommonConfirmView : UIView <TTTAttributedLabelDelegate>

@property (nonatomic, copy) NSString        * title;
@property (nonatomic, strong) UIFont        * titleFont;
@property (nonatomic, strong) UIFont        * confirmTitleFont;
@property (nonatomic, strong) UIFont        * cancelTitleFont;

// 由于现金宝那边UI要求， 将title label改为接口， 方便进行自定义
@property (nonatomic, strong) UILabel       * titleLabel;

@property (nonatomic, copy) NSString        * subtitle;
@property (nonatomic, assign) BOOL isSubtitleAboveTitle;
@property (nonatomic, copy) NSString        * cancelTitle;
@property (nonatomic, copy) NSString        * confirmTitle;

//允许自定义的contentView
@property (nonatomic, strong) UIView        * contentView;
@property (nonatomic, strong) UIButton      * cancelButton;
@property (nonatomic, strong) UIButton      * confirmButton;
@property (nonatomic, strong) UIButton      * closeButton;

@property (nonatomic, assign) BOOL            enableCancelButton;           //是否显示取消按钮
@property (nonatomic, assign) BOOL            enableMaskView;
@property (nonatomic, assign) BOOL            enableCloseButton;            //显示关闭按钮，如果 显示，那么 点击maskView不会被关闭
@property (nonatomic, assign) BOOL            enableConfirmButtons;         //默认显示取消，确定按钮
@property (nonatomic, assign) BOOL            aboveKeyboard;                //是否覆盖键盘

@property (nonatomic, assign) BOOL            disableMaskView;         //!< 禁掉maskView的点击效果
@property (nonatomic, assign) BOOL            delayCallBack;           //!< 延迟回调
@property (nonatomic, assign) NSInteger       contentViewBottomPadding;     //不显示确定按钮时，content view的底部边距


/// 竖直排列确认取消按钮
@property (nonatomic, assign) BOOL            uprightConfirmCancel;
@property (nonatomic, assign) BOOL            cancelButtonBorderEnable;    //Default YES 

@property (nonatomic, copy) void(^selectedBlock)(TBCommonConfirmView * confirmView,NSInteger index);
@property (nonatomic, copy) void(^dismissBlock)(TBCommonConfirmView * confirmView);

@property (nonatomic, copy) void(^clickLinksBlock)(NSURL *url); //! url跳转链接

@property (nonatomic, copy) void (^maskViewBlock)(TBCommonConfirmView * confirmView);

@property (nonatomic, weak) id<TBCommonConfirmViewDelegate> delegate;

//子类需要自行初始化界面时调用
- (instancetype)initWithoutSetupViews;

- (instancetype)initWithTitle:(NSString *)title;

- (void)setupContentView;

// 判断另外一个弹窗是否正在显示
- (BOOL)hasAnotherViewInWindow;

- (void)showInWindow;

- (void)showInView:(UIView *)view;

- (void)setupCommonViews;

- (CGFloat)checkboxContentHeight;

- (void)dismiss;

//使用当前显示VC打开
- (void)present;
//使用传入的VC打开
- (void)present:(UIViewController *)viewController;

+ (CGFloat)width;

+ (void)removeAllInstances;

- (void)onTappedConfirmButton:(UIButton *)sender; // for override

@end
