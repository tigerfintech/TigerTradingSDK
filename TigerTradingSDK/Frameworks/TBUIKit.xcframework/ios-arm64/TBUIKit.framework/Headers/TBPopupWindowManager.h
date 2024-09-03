//
//  TBPopupWindowManager.h
//  Stock
//
//  Created by ChenXin on 2017/6/15.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

@interface TBPopupWindowManager : NSObject

DECLARE_SHARED_INSTANCE(TBPopupWindowManager)

- (void)showViewController:(UIViewController *)viewController;
- (void)showViewController:(UIViewController *)viewController level:(UIWindowLevel)level;

- (void)dismiss;

@end
