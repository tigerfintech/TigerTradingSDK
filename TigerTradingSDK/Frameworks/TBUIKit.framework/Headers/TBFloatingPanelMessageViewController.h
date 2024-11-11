//
//  TBFloatingPanelMessageViewController.h
//  TBUIKit
//
//  Created by linbingjie on 2023/7/31.
//

#import <TBUIKit/TBFloatingPanelBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class TBFloatingPanel;

typedef void(^TBTextAction)(UIView *containerView, NSAttributedString *text, NSRange range, CGRect rect, TBFloatingPanel *floatingPanel);


@interface TBFloatingPanelMessageViewController : TBFloatingPanelBaseViewController

/// alert （string）
/// ⭐️如果传入的按钮文案为nil，就隐藏该按钮⭐️
/// - Parameters:
///   - title: 标题
///   - secTitle: 副标题
///   - detailTitle: 详情文案
///   - comfirmBtnTitle: 确认按钮
///   - cancelBtnTitle: 取消按钮
///   - comfirmClickActionBlock: 确认按钮点击事件
///   - cancelClickActionBlock: 取消按钮点击事件
+ (TBFloatingPanelMessageViewController *)showWithTitle:(nullable NSString *)title
                                               subtitle:(nullable NSString *)secTitle
                                          detailMessage:(nullable NSString *)detailTitle
                                        comfirmBtnTitle:(nullable NSString *)comfirmBtnTitle
                                         cancelBtnTitle:(nullable NSString *)cancelBtnTitle
                                comfirmClickActionBlock:(nullable ComfirmClickActionBlock)comfirmClickActionBlock
                                 cancelClickActionBlock:(nullable CancelClickActionBlock)cancelClickActionBlock;

/// alert （attributestring）
/// ⭐️如果传入的按钮文案为nil，就隐藏该按钮⭐️
/// - Parameters:
///   - title: 标题
///   - secTitle: 副标题
///   - detailTitle: 详情文案  (⭐️富文本样式)
///   - comfirmBtnTitle: 确认按钮
///   - cancelBtnTitle: 取消按钮
///   - comfirmClickActionBlock: 确认按钮点击事件
///   - cancelClickActionBlock: 取消按钮点击事件
+ (TBFloatingPanelMessageViewController *)showWithTitle:(nullable NSString *)title
                                               subtitle:(nullable NSString *)secTitle
                                 attributeDetailMessage:(nullable NSMutableAttributedString *)detailTitle
                                        comfirmBtnTitle:(nullable NSString *)comfirmBtnTitle
                                         cancelBtnTitle:(nullable NSString *)cancelBtnTitle
                                comfirmClickActionBlock:(nullable ComfirmClickActionBlock)comfirmClickActionBlock
                                 cancelClickActionBlock:(nullable CancelClickActionBlock)cancelClickActionBlock;



/// alert (checkbox)
+ (TBFloatingPanelMessageViewController *)showWithTitle:(nullable NSString *)title
                                               subtitle:(nullable NSString *)secTitle
                                          detailMessage:(nullable NSString *)detailTitle
                                           checkMessage:(nonnull NSString *)checkMessage
                                        comfirmBtnTitle:(nullable NSString *)comfirmBtnTitle
                                         cancelBtnTitle:(nullable NSString *)cancelBtnTitle
                                   defaultCheckSelected:(BOOL)isCheckSelected
                                    checkboxButtonBlock:(CheckboxButtonBlock)checkboxButtonBlock
                                   checkboxMessageBlock:(nullable CheckboxMessageBlock)checkboxMessageBlock
                                comfirmClickActionBlock:(ComfirmClickActionBlock)comfirmClickActionBlock
                                 cancelClickActionBlock:(CancelClickActionBlock)cancelClickActionBlock;

+ (TBFloatingPanelMessageViewController *)showWithTitle:(nullable NSString *)title
                                               subtitle:(nullable NSString *)secTitle
                                          detailMessage:(nullable NSString *)detailTitle
                                           attributedCheckMessage:(nonnull NSAttributedString *)attributedCheckMessage
                                        comfirmBtnTitle:(nullable NSString *)comfirmBtnTitle
                                         cancelBtnTitle:(nullable NSString *)cancelBtnTitle
                                   defaultCheckSelected:(BOOL)isCheckSelected
                                    checkboxButtonBlock:(CheckboxButtonBlock)checkboxButtonBlock
                                   checkboxMessageBlock:(nullable CheckboxMessageBlock)checkboxMessageBlock
                                comfirmClickActionBlock:(ComfirmClickActionBlock)comfirmClickActionBlock
                                 cancelClickActionBlock:(CancelClickActionBlock)cancelClickActionBlock;

+ (TBFloatingPanelMessageViewController *)showWithTitle:(nullable NSString *)title
                                               subtitle:(nullable NSString *)secTitle
                                          detailMessage:(nullable NSMutableAttributedString *)detailTitle
                                               parentVC:(nullable UIViewController *)parentVC
                                           checkMessage:(nullable NSString *)checkMessage
                                        comfirmBtnTitle:(nullable NSString *)comfirmBtnTitle
                                         cancelBtnTitle:(nullable NSString *)cancelBtnTitle
                                   defaultComfirmHidden:(BOOL)isComfirmHidden
                                    defaultCancelHidden:(BOOL)isCancelHidden
                                   defaultCheckSelected:(BOOL)isCheckSelected
                                     defaultCheckHidden:(BOOL)isCheckHidden
                                    checkboxButtonBlock:(nullable CheckboxButtonBlock)checkboxButtonBlock
                                   checkboxMessageBlock:(nullable CheckboxMessageBlock)checkboxMessageBlock
                                comfirmClickActionBlock:(nullable ComfirmClickActionBlock)comfirmClickActionBlock
                                 cancelClickActionBlock:(nullable CancelClickActionBlock)cancelClickActionBlock;

// 在detailmessage内部找到 linkString， 改成linkUI和添加点击效果
- (void)configDetailMessageLink:(NSString *)linkString tapAction:(TBTextAction)clickAction;

- (TBFloatingPanel *)fetchFloatingPanel;

@end

NS_ASSUME_NONNULL_END
