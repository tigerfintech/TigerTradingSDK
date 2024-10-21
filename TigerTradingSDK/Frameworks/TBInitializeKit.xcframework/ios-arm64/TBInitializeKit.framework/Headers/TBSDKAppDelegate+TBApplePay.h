//
//  AppDelegate+TBApplePay.h
//  Stock
//
//  Created by 王昌阳 on 2021/9/7.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBSDKAppDelegate.h"
//#import <TBPayKit/TBApplePayManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSDKAppDelegate (TBApplePay)
//<
// TBPayDelegate
//>

- (void)setupApplePay;

- (void)removeTransactionObserver;

@end

NS_ASSUME_NONNULL_END
