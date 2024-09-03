//
//  TBFloatingPanelBtoomDetailView.h
//  TBUIKit
//
//  Created by linbingjie on 2023/7/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


typedef void(^CheckboxButtonBlock)(UIButton *sender, BOOL isSelected);// 定义checkboxButtonBlock类型
typedef void(^CheckboxMessageBlock)(UILabel *sender);// 定义checkboxMessageBlock类型
typedef void(^ComfirmClickActionBlock)(UIButton *sender);// 定义comfirmClickActionBlock类型
typedef void(^CancelClickActionBlock)(UIButton *sender);// 定义cancelClickActionBlock类型

@interface TBFloatingPanelBtoomDetailView : UIView

@property (nonatomic, copy) CheckboxButtonBlock checkboxButtonBlock; // checkbox的勾选按钮点击事件
@property (nonatomic, copy) CheckboxMessageBlock checkboxMessageBlock; // checkbox 文案点击事件
@property (nonatomic, copy) ComfirmClickActionBlock comfirmClickActionBlock; // 确认按钮block
@property (nonatomic, copy) CancelClickActionBlock cancelClickActionBlock;  // 取消按钮block


- (void)configBtnComfirmTitle:(NSString *)title comfirmHidden:(BOOL)isComfirmHidden;

- (void)configBtnCancelTitle:(NSString *)title cancelHidden:(BOOL)isCancelHidden;
- (void)configBtnCancelTitle:(NSString *)title cancelHidden:(BOOL)isCancelHidden borderHidden:(BOOL)isBorderHidden;
- (void)configCancelButtonBorderHidden:(BOOL)isBorderHidden;

- (void)configConfirmButtonEnableStatus:(BOOL)enable;

- (void)configConfirmButtonStyle:(BOOL)grayStyle;

- (void)configBottomViewBackgroundColor:(UIColor *)color;

/// check按钮相关配置 （默认未选中）
/// - Parameters:
///   - title: 显示文案  最多3行
///   - isCheckHidden: 是否隐藏
- (void)configLblCheckTitle:(NSString *)title
                checkHidden:(BOOL)isCheckHidden;

/// check按钮相关配置 （默认未选中）
/// - Parameters:
///   - title: 显示文案  最多3行
///   - isCheckSeledted: 设置check选中状态
///   - isCheckHidden: 是否隐藏
- (void)configLblCheckTitle:(NSString *)title
              checkSeledted:(BOOL)isCheckSeledted
                checkHidden:(BOOL)isCheckHidden;

- (void)configLblCheckAttributedTitle:(NSAttributedString *)attributedTitle
                        checkSeledted:(BOOL)isCheckSeledted
                          checkHidden:(BOOL)isCheckHidden;

// 获取这个view的高度
- (NSInteger)fetchTotalBottomViewHeight;
// 获取checkbox的选中状态
- (BOOL)fetchCheckBoxSelected;



@end

NS_ASSUME_NONNULL_END
