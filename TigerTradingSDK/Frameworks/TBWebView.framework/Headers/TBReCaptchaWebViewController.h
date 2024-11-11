//
//  TBReCaptchaWebViewController.h
//  TBAccountSystemKit
//
//  Created by dulijun on 2022/6/7.
//

#import "TBWKWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBReCaptchaWebViewController : TBWKWebViewController

+ (void)showWebReCaptcha;
+ (BOOL)isShowingReCaptchaWebPage;//是否正在展示web验证页
+ (void)dismiss;

@end

NS_ASSUME_NONNULL_END
