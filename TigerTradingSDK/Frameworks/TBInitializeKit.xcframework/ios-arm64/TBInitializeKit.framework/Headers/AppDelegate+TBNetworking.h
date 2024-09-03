//
//  AppDelegate+TBNetworking.h
//  Stock
//
//  Created by chenxin on 2020/9/2.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "AppDelegate.h"
#import <TBNetworking/TBHttpRequestManager.h>
#import <TBPerformanceKit/TNEHTTPModelManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppDelegate (TBNetworking) <TBHttpRequestManagerDelegate, TNEHTTPModelManagerDelegate>

@property (nonatomic, strong) NSNumber *unsavedRequestCount; // 未保存的请求数

- (void)setupNetworking;

@end

NS_ASSUME_NONNULL_END
