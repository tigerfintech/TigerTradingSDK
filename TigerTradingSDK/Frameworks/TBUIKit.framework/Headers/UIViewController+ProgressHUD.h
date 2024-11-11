//
//  UIViewController+ProgressHUD.h
//  Stock
//
//  Created by chenxin on 2018/5/25.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (ProgressHUD)

- (void)showLoading;
- (void)hideLoading;


- (void)showLoading:(BOOL)animated;
- (void)hideLoading:(BOOL)animated;
- (void)showLoading:(BOOL)animated enableUserAction:(BOOL)enable;

- (void)showLoadingSuccess:(BOOL)animated hintString:(NSString *)hintString hide:(CGFloat)delay;
- (void)showLoadingSuccess:(BOOL)animated hintString:(NSString *)hintString hide:(CGFloat)delay enableUserAction:(BOOL)enable;
//
- (void)showLoadingFailure:(BOOL)animated;
- (void)showHint:(NSString *)hint hide:(CGFloat)delay;
- (void)showHint:(NSString *)hint hide:(CGFloat)delay enableBackgroundUserAction:(BOOL)enable;
- (void)showLoading:(BOOL)enableShow inView:(UIView *)view;
- (void)showLoadingInWindow:(BOOL)enableShow;


@end
