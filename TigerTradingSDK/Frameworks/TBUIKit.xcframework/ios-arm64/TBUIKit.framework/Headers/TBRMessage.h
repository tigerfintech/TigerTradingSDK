//
//  TBRMessage.h
//  Stock
//
//  Created by ChenXin on 2018/1/24.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RMessage.h"

#define kTBPopMessageDuration 8

@interface TBRMessage : NSObject

+ (void)showNotificationWithTitle:(NSString *)title
                         subtitle:(NSString *)subtitle;

+ (void)showNotificationWithTitle:(NSString *)title
                         subtitle:(NSString *)subtitle
                         callback:(void (^)(void))callback;

+ (void)showNotificationWithTitle:(NSString *)title
                         subtitle:(NSString *)subtitle
                            level:(RMessageLevel)level
                         callback:(void (^)(void))callback;

+ (void)showNotificationWithTitle:(NSString *)title
                         subtitle:(NSString *)subtitle
                        iconImage:(UIImage *)iconImage
                         duration:(NSTimeInterval)duration
                         callback:(void (^)(void))callback
                      buttonTitle:(NSString *)buttonTitle
                   buttonCallback:(void (^)(UIButton *button))buttonCallback;

+ (void)showStockAlertNotificationWithSymbol:(NSString *)symbol
                                       title:(NSString *)title
                                    subtitle:(NSString *)subtitle
                                   iconImage:(UIImage *)iconImage
                                    duration:(NSTimeInterval)duration
                                    callback:(void (^)(void))callback
                                 buttonTitle:(NSString *)buttonTitle
                              buttonCallback:(void (^)(UIButton *button))buttonCallback;
+ (void)showQuoteLVRecieve:(NSString *)title subtitle:(NSString *)subtitle iconImage:(UIImage *)iconImage duration:(NSTimeInterval)duration callback:(void (^)(void))callback;

+ (void)showCommunityUserLevelAlertWithMessage:(NSString *)message
                                      callback:(void (^)(void))callback;

+ (void)dismissAlert;

+ (void)preload;

@end
