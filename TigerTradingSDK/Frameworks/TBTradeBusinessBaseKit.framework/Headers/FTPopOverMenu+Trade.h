//
//  FTPopOverMenu+Trade.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2022/4/28.
//

#import <TBUIKit/FTPopOverMenu.h>

NS_ASSUME_NONNULL_BEGIN

@interface FTPopOverMenu (Trade)

+ (void)showPopOverTradeTipsWithSender:(UIView *)sender
                                 title:(NSString *)title
                          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverTradeTipsWithSender:(UIView *)sender
                                 title:(NSString *)title
                       backgroundColor:(UIColor *)bgColor
                             textColor:(UIColor *)textColor
                           isBigCorner:(BOOL)isBigCorner
                        arrowDirection:(FTPopOverMenuArrowDirection)direction
                          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverTradeTipsWithSender:(UIView *)sender
                                 title:(NSString *)title
                       backgroundColor:(UIColor *)bgColor
                             textColor:(UIColor *)textColor
                              textFont:(UIFont *)textFont
                      selectedTextFont:(nullable UIFont *)selectedTextFont
                           isBigCorner:(BOOL)isBigCorner
                        arrowDirection:(FTPopOverMenuArrowDirection)direction
                          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverTradeTipsWithSender:(UIView *)sender
                                 title:(NSString *)title
                       backgroundColor:(UIColor *)bgColor
                             textColor:(UIColor *)textColor
                              textFont:(UIFont *)textFont
                      selectedTextFont:(nullable UIFont *)selectedTextFont
                           isBigCorner:(BOOL)isBigCorner
                             menuWidth:(CGFloat)menuWidth
                        arrowDirection:(FTPopOverMenuArrowDirection)direction
                          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showPopOverTradeTipsWithSender:(UIView *)sender
                                 title:(NSString *)title
                       backgroundColor:(UIColor *)bgColor
                             textColor:(UIColor *)textColor
                              textFont:(UIFont *)textFont
                              selectedTextFont:(nullable UIFont *)selectedTextFont
                           isBigCorner:(BOOL)isBigCorner
                             menuWidth:(CGFloat)menuWidth
                 tableHorizontalMargin:(CGFloat)tableHorizontalMargin
                        arrowDirection:(FTPopOverMenuArrowDirection)direction
                          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showSpeedMakeOrderBuyAndSellSetPopOverWithSender:(UIView *)sneder
                                                  titles:(NSArray *)titles
                                             titleColors:(NSArray *)titleColors
                                            currentIndex:(NSInteger)currentIndex
                                               doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                                            dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

+ (void)showChangeBriefOrderQuoteModePopOverWithSender:(UIView *)sneder
                                                titles:(NSArray *)titles
                                           titleColors:(NSArray *)titleColors
                                          currentIndex:(NSInteger)currentIndex
                                             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                                          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;


@end

NS_ASSUME_NONNULL_END
