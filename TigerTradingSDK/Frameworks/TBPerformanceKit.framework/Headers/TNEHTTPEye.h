//
//  TNEHTTPEye.h
//  TigerNetworkEye
//
//  Created by 骆朋飞 on 2017/5/28.
//  Refactored by donggongfu on 2021/12/29
//  Copyright © 2021 Tiger Brokers. All rights reserved.
//

#import <Foundation/Foundation.h>

// TNE debug log 标志位, 打开显示控制台log
#define TNETBLogDebugFlag 0

NS_ASSUME_NONNULL_BEGIN

// 设置类常量, udkey

// Constants
extern const NSUInteger TNESaveRequestMaxCount;

// UserDefaultKeys
extern NSString *const TNEHTTPEyeEnabledKey;
extern NSString *const TNEHTTPEyeFlowCountKey;


@protocol TNEHTTPModelManagerDelegate;

@interface TNEHTTPEye : NSURLProtocol

/**
 *  open or close HTTP/HTTPS monitor
 *
 *  @param enabled
 */
+ (void)setEnabled:(BOOL)enabled;

/**
 *  display HTTP/HTTPS monitor state
 *
 *  @return HTTP/HTTPS monitor state
 */
+ (NSNumber *)isEnabled;

+ (void)setDelegate:(id<TNEHTTPModelManagerDelegate>)delegate;
+ (id<TNEHTTPModelManagerDelegate>)delegate;

/// 流量
+ (double)flowCount;

@end

NS_ASSUME_NONNULL_END
