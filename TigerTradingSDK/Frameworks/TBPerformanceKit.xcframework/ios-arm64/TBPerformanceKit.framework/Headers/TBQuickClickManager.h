//
//  TBQuickClickManager.h
//  StockGlobal
//
//  Created by linbingjie on 2020/5/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

/*
 // 1s内连续点击的话会进入return func 内
 if (ISQUICKCLICKACTION(1)) {
     return;
 }
 */
#define ISQUICKCLICKACTION(interval)  [[TBQuickClickManager sharedInstance] isQuickClickAction:interval]

@interface TBQuickClickManager : NSObject

DECLARE_SHARED_INSTANCE(TBQuickClickManager)

- (BOOL)isQuickClickAction:(NSTimeInterval)interval;

@end

NS_ASSUME_NONNULL_END
