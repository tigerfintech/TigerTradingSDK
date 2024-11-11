//
//  TBNavigationController.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KKNavigationController.h"

@interface TBNavigationController : KKNavigationController
//@interface TBNavigationController : UINavigationController

@property (nonatomic, assign) UIViewAnimationTransition *transition;
@property (nonatomic, assign) BOOL dismissPresentedViewController;  //仅dismiss Presented ViewController存在的窗口，用于解决模态VC push VC后WebView打开ActionSheet的bug

- (UIViewController *)popViewControllerAnimated:(BOOL)animated;
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;

- (void ) presentViewController:(UIViewController *)viewControllerToPresent animated:(BOOL)flag completion:(void (^)(void))completion;
- (void) presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated;

- (void)normalDismissViewControllerWithoutAnimation;

@end

