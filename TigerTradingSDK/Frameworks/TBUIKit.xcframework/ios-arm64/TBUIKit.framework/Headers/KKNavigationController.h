//
//  KKNavigationController.h
//  TS
//
//  Created by Coneboy_K on 13-12-2.
//  Copyright (c) 2013年 Coneboy_K. All rights reserved. MIT
//  WELCOME TO MY BLOG  http://www.coneboy.com
//

#import <UIKit/UIKit.h>
#import <TBBaseKit/TBBaseKitUtil.h>

#define KEY_WINDOW  TBBaseKitUtil.tbGetKeyWindow
#define kkBackViewHeight [UIScreen mainScreen].bounds.size.height
#define kkBackViewWidth [UIScreen mainScreen].bounds.size.width



// 导航控制器相关通知
extern NSString *const TBNavigationDidPushNotification; // push
extern NSString *const TBNavigationDidPopNotification; // pop包括popTo
extern NSString *const TBNavigationPanBackBeginNotification; // 滑动返回开始
extern NSString *const TBNavigationPanBackEndedNotification; // 滑动返回结束

extern NSString *const TBNavigationPanGestureRecognizerKey; // 滑动返回开始通知传递手势参数的key

@interface KKNavigationController : UINavigationController
{
    CGFloat startBackViewX;
}

// 默认为特效开启
@property (nonatomic, assign) BOOL canDragBack;

@end
