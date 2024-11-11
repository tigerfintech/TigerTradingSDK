//
//  TBWebViewComponentService.h
//  TBServiceProtocolKit
//
//  Created by chenxin on 2022/6/20.
//

#ifndef TBWebViewComponentService_h
#define TBWebViewComponentService_h

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBWebViewComponentService <NSObject>

- (NSString *)tbWeb_urlForWebPage:(UIViewController *)webViewController;

- (NSString *)tbWeb_inviteCodeFromWeb;

- (BOOL)tbWeb_shouldJumptoNative:(NSString *)linkUrl;

- (UIViewController *)tbWeb_getWebVCWithQuery:(NSDictionary *)dict;

// TBReCaptchaWebViewController 相关的事件
- (void)tbWeb_reCaptchaShowWebReCaptcha;
- (BOOL)tbWeb_reCaptchaISShowingReCaptchaWebPage;//是否正在展示web验证页
- (void)tbWeb_reCaptchaDismiss;
// TBReCaptchaWebViewController 相关的事件

- (void)tbWeb_preLoadURL:(NSString *)url;

@end

NS_ASSUME_NONNULL_END

#endif /* TBWebViewComponentService_h */
