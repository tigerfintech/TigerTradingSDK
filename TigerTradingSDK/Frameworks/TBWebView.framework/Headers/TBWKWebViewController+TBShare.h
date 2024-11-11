//
//  TBWKWebViewController+TBShare.h
//  TBWebView
//
//  Created by chenxin on 2021/8/6.
//

#import "TBWKWebViewController.h"
#if __has_include(<TBShareKit/TBShareToolbar.h>)
#import <TBShareKit/TBShareToolbar.h> // for TBShareToolbarDelegate
#endif
NS_ASSUME_NONNULL_BEGIN
#if __has_include(<TBShareKit/TBShareToolbar.h>)
@interface TBWKWebViewController (TBShare) <TBShareToolbarDelegate, WKScriptMessageHandler>
#else
@interface TBWKWebViewController (TBShare) <WKScriptMessageHandler>
#endif
// 处理分享通知
- (void)handleShareBack:(NSNotification *)noti;

// 配置分享回调
- (void)configureShareCallbackWithDict:(NSDictionary *)dict;

// 根据网页内容配置分享信息
- (void)configureShareInfoWithURLString:(NSString *)urlString htmlString:(NSString *)htmlString;

// 点击分享按钮
- (void)shareButtonClicked;

@end

NS_ASSUME_NONNULL_END
