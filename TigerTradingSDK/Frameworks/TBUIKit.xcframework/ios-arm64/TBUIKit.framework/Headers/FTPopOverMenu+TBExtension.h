//
//  FTPopOverMenu+TBExtension.h
//  Stock
//
//  Created by luopengfei on 2019/3/22.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import "FTPopOverMenu.h"

NS_ASSUME_NONNULL_BEGIN

@interface FTPopOverMenu (TBExtension)

/**
 show method with sender, image resouce Array and configuration

 @param sender sender
 @param width width
 @param titles titles
 @param images images
 @param doneBlock doneBlock description
 @param dismissBlock dismissBlock description
 */
+ (void)showPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles images:(nullable NSArray *)images doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithStockSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender textColor:(UIColor *)selectedColor Width:(CGFloat)width titles:(NSArray *)titles currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles images:(NSArray * _Nullable)images currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles images:(NSArray *)images textAlignment:(NSTextAlignment)textAlignment doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                     dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender
                            width:(CGFloat)width
                           titles:(NSArray *)titles
                     currentIndex:(NSInteger)currentIndex
                           images:(nullable NSArray *)images
                    textAlignment:(NSTextAlignment)textAlignment
                  menuIconIsRight:(BOOL)menuIconIsRight
                        doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                     dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showWathListPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles images:(NSArray *)images iconSize:(CGFloat)iconSize  doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                     dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender textColor:(UIColor *)selectedColor arrowDirection:(FTPopOverMenuArrowDirection)arrowDirection Width:(CGFloat)width titles:(NSArray *)titles currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showStockDetailPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles images:(NSArray *)images currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showTradeTodayOrdersPopOverMenuWithSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles images:(nullable NSArray *)images currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;


+ (void)showNoSeparatorMenuWithStockSender:(UIView *)sender Width:(CGFloat)width titles:(NSArray *)titles currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverMenuWithSender:(UIView *)sender width:(CGFloat)width titles:(NSArray *)titles textColor:(UIColor *)textColor textFont:(UIFont *)textFont currentIndex:(NSInteger)currentIndex doneBlock:(FTPopOverMenuDoneBlock)doneBlock dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

// 显示引导气泡
+ (void)showPopOverTipsWithSender:(UIView *)sender
                        superView:(UIView *)superView
                            title:(NSString *)title
                     dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;
+ (void)showPopOverTipsWithSender:(UIView *)sender
                        superView:(UIView *)superView
                            title:(NSString *)title
                  dismissDuration:(NSTimeInterval)dismissDuration
                        doneBlock:(nullable FTPopOverMenuDoneBlock)doneBlock
                     dismissBlock:(nullable FTPopOverMenuDismissBlock)dismissBlock;
+ (void)showPopOverTipsWithSender:(UIView *)sender
                        superView:(UIView *)superView
                            title:(NSString *)title
                   arrowDirection:(FTPopOverMenuArrowDirection)arrowDirection
                  dismissDuration:(NSTimeInterval)dismissDuration
                        doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                     dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;
+ (void)showPopOverTipsWithSender:(UIView *)sender
                        superView:(UIView *)superView
                            title:(NSString *)title
                   arrowDirection:(FTPopOverMenuArrowDirection)arrowDirection
                  dismissDuration:(NSTimeInterval)dismissDuration
                     menuMaxWidth:(nullable NSNumber *)menuMaxWidth
                    textAlignment:(nullable NSNumber *)textAlignment
                        doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                     dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

@end

NS_ASSUME_NONNULL_END
