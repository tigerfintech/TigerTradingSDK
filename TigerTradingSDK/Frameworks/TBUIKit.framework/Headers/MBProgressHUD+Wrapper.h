//
//
//  Stock
//
//  Created by yangfan on 2017/3/14.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <MBProgressHUD/MBProgressHUD.h>

@interface MBProgressHUD (Wrapper)

+ (void)showHint:(NSString *)hint hide:(CGFloat)delay;
+ (void)showLoading:(BOOL)show;
+ (MBProgressHUD *)showLoading:(BOOL)show hide:(CGFloat)delay;
+ (void)showLoading:(BOOL)show hideDelay:(CGFloat)delay;
+ (MBProgressHUD *)showLoading:(BOOL)show hintString:(NSString *)hintString;
+ (MBProgressHUD *)showLoading:(BOOL)show hintString:(NSString *)hintString hide:(CGFloat)delay;
+ (void)showMBPAlertView:(NSString *)alertInfo withSecond:(NSTimeInterval)second;

- (void)tbHudStyle;

@end
