//
//  TBCacheManager.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/4/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCacheManager : NSObject

#pragma mark - WKWebView Clean Cache
+ (void)removeWebViewCookieAndCacheAll;
+ (void)removeWebViewCookieAndCacheForSite:(NSString *)siteName; // 清楚webview本地存数的cookie
+ (void)removeWKCacheData; // 清除WKWebView缓存数据

@end

NS_ASSUME_NONNULL_END
