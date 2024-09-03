//
//  TBLinkMessageConfirm.h
//  Stock
//
//  Created by dulijun on 2021/8/25.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBCommonConfirmView.h"
#import <TBBaseKit/TBLanguageManager.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBLinkMessageConfirm : TBCommonConfirmView

/// 文本弹框。支持link 点击 （样式，可参考登录注册时，未勾选同意服务协议 时点登录，弹出的 “服务协议与隐私政策” 弹框）
/// @param title 标题
/// @param message 内容
/// @param messageColor 内容颜色
/// @param linkColor 内容中可点击的链接文字的颜色
/// @param urlLinks  link对应的字符串和url 。如 : @{TBLocalizedString(@"《社区服务协议》", nil) : @"url1", TBLocalizedString(@"《产品使用许可协议》", nil) : @"url2",  TBLocalizedString(@"《隐私政策》", nil) : @"url3"}
/// @param clickLinkBlock 点击链接文字的回调
- (instancetype)initWithTitle:(nullable NSString *)title message:(nullable NSString *)message messageColor:(UIColor *)messageColor linkColor:(UIColor *)linkColor urlLinks:(NSDictionary *)urlLinks clickLinkBlock:(void (^)( NSURL *url))clickLinkBlock;
- (void)showConfirm;
@end

NS_ASSUME_NONNULL_END
