//
//  TBAlertHelp.h
//  Stock
//
//  Created by dull grass on 2019/6/10.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAlertHelp : NSObject

/**
 展示弹框，只有确认按钮"知道了",没有回调

 @param title 标题
 @param content 内容
 */
+ (void)showMessageOnlyKnowTitle:(nullable NSString *)title content:(nullable NSString *)content;

/**
 展示弹框，标题为提示，Ok按钮为确认，有回调
 
 @param content 内容
 @param buttonBlock 确认按钮回调
 */
+ (void)showMessageAlertMakeSureContent:(nullable NSString *)content cancelTitle:(nullable NSString *)cancelTitle okbuttonBlock:(nullable void(^)(void)) buttonBlock;

/**
 展示弹框，只有确认按钮，没有回调

 @param title 标题
 @param content 内容
 @param okTitle 确认按钮标题
 */
+ (void)showMessageTitle:(nullable NSString *)title content:(nullable NSString *)content okButton:(nullable NSString *)okTitle;

 /**
 展示弹框，只有确认按钮，没有回调
 
 @param title 标题
 @param content 内容
 @param okTitle 确认按钮标题
 @param cancelTitle 取消按钮标题
 @param buttonBlock 确认按钮回调
 */
+ (void)showMessageBoxTitle:(nullable NSString *)title content:(nullable NSString *)content okButtonTitle:(nullable NSString *)okTitle cancelTitle:(nullable NSString *)cancelTitle okbuttonBlock:(nullable void(^)(void)) buttonBlock;

/**
 展示弹框，有取消和确认按钮，有确认按钮的回调，没有标题

 @param content 内容
 @param okTitle 确认按钮标题
 @param cancelTitle 取消按钮标题
 @param buttonBlock 确认按钮回调
 */
+ (void)showMessageBox:(nullable NSString *)content okButtonTitle:(nullable NSString *)okTitle cancelTitle:(nullable NSString *)cancelTitle okbuttonBlock:(nullable void(^)(void)) buttonBlock;

/// 展示弹框，有取消和确认按钮
/// @param title 标题
/// @param content 内容
/// @param enableCloseButton 是否允许
/// @param okTitle 确认按钮
/// @param cancelTitle 取消
/// @param buttonBlock 确认回调
/// @param dismissBlock 取消回调
+ (void)showMessageTitle:(nullable NSString *)title content:(nullable NSString *)content enableCloseButton:(BOOL)enableCloseButton okButtonTitle:(nullable NSString *)okTitle cancelTitle:(nullable NSString *)cancelTitle buttonBlock:(nullable void(^)(void)) buttonBlock dismissBlock:(nullable void(^)(void)) dismissBlock;

/**
 展示富文本

 @param title 标题
 @param content 内容
 @param links 需要点击 特殊处理的内容
 @param enableCloseButton 是否有X
 @param okTitle 确认按钮标题
 @param buttonBlock 确认按钮回调
 @param linkBlock url链接
 */
+ (void)showAttributeMessageTitle:(nullable NSString *)title content:(nullable NSString *)content links:(nullable NSDictionary *)links enableCloseButton:(BOOL)enableCloseButton okButtonTitle:(nullable NSString *)okTitle buttonBlock:(nullable void(^)(void)) buttonBlock linkBlock:(nullable void(^)(NSURL *url)) linkBlock;


/// 展示富文本内容
/// @param title 标题
/// @param attributedContent 富文本
+ (void)showAttributeMessageTitle:(nullable NSString *)title attributedContent:(nullable NSAttributedString *)attributedContent;

//显示一个带有关闭按钮的弹出框
+ (void)showMessageBox:(NSString *)message enableCloseButton:(BOOL)enableCloseButton buttonTitle:(NSString *)title buttonBlock:(void(^)(void)) buttonBlock;
+ (void)showMessageBox:(NSString *)message enableCloseButton:(BOOL)enableCloseButton buttonTitle:(NSString *)title buttonBlock:(nullable void(^)(void)) buttonBlock dismissBlock:(nullable void(^)(void)) dismissBlock;
//显示一个带有关闭按钮的弹出框
+ (void)showMessageBoxWithContentView:(UIView *)contentView enableCloseButton:(BOOL)enableCloseButton buttonTitle:(NSString *)title buttonBlock:(nullable void(^)(void)) buttonBlock;
+ (void)showMessageBoxWithContentView:(UIView *)contentView enableCloseButton:(BOOL)enableCloseButton buttonTitle:(NSString *)title buttonBlock:(nullable void(^)(void)) buttonBlock dismissBlock:(nullable void(^)(void)) dismissBlock;

+ (void)showMessageBoxWithContentView:(UIView *)contentView enableCloseButton:(BOOL)enableCloseButton okButton:(nullable NSString *)okTitle  cancelButton:(nullable NSString *)cancelTitle buttonBlock:(nullable void(^)(void)) buttonBlock dismissBlock:(nullable void(^)(void)) dismissBlock;


+ (void)showConfirmViewWithTitle:(nullable NSString *)title
                         content:(id)content
                           links:(nullable  NSDictionary *)links
                        checkbox:(BOOL)hasCheckbox
                    checkBoxText:(NSString *)checkBoxText
                     cancelTitle:(NSString * _Nullable)cancelTitle
                    confirmTitle:(NSString *)confirmTitle
                            link:(nullable void (^)(NSURL *URL))linkBlock
                         confirm:(nullable void (^)(BOOL selected))confirmBlock
                     cancelBlock:(nullable dispatch_block_t)cancelBlock;

+ (void)showConfirmViewWithTitle:(NSString *)title
                         content:(id)content
                     cancelTitle:(nullable NSString *)cancelTitle
                    confirmTitle:(NSString *)confirmTitle
                         confirm:(nullable dispatch_block_t)confirmBlock
                          cancel:(nullable dispatch_block_t)cancelBlock;

+ (void)showMessage:(NSString *)message
               link:(NSDictionary *)links
          linkBlock:(void(^)(NSURL *url))linkBlock
        cancelTitle:(NSString *)cancelTitle
        cancelBlock:(dispatch_block_t)cancelBlock
       confirmTitle:(NSString *)confirmTitle
       confirmBlock:(dispatch_block_t)confirmBlock;

+ (void)showMessage:(NSString *)message
        actionImage:(NSString *)actionImage
        actionTitle:(NSString *)actionTitle
      actionHandler:(dispatch_block_t)actionBlock
        cancelTitle:(NSString *)cancelTitle
        cancelBlock:(dispatch_block_t)cancelBlock
       confirmTitle:(NSString *)confirmTitle
       confirmBlock:(dispatch_block_t)confirmBlock;

+ (void)showVerticalMessageTitle:(nullable NSString *)title
                         content:(nullable NSString *)content
               enableCloseButton:(BOOL)enableCloseButton
                   okButtonTitle:(nullable NSString *)okTitle
                     cancelTitle:(nullable NSString *)cancelTitle
                     buttonBlock:(nullable void(^)(void))buttonBlock
                    dismissBlock:(nullable void(^)(void))dismissBlock;

+ (void)showVerticalMessageTitle:(nullable NSString *)title
                         content:(nullable NSString *)content
                        checkbox:(BOOL)hasCheckbox
                    checkBoxText:(NSString *)checkBoxText
               enableCloseButton:(BOOL)enableCloseButton
                   okButtonTitle:(nullable NSString *)okTitle
                     cancelTitle:(nullable NSString *)cancelTitle
                   checkBoxBlock:(nullable void(^)(BOOL selected))checkBoxBlock
                     buttonBlock:(nullable void(^)(void))buttonBlock
                    dismissBlock:(nullable void(^)(void))dismissBlock;

@end

NS_ASSUME_NONNULL_END

