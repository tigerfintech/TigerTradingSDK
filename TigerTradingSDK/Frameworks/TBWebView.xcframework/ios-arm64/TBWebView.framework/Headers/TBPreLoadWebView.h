//
//  TBPreLoadWebView.h
//  TBWebView
//
//  Created by linbingjie on 2023/10/12.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPreLoadWebView : UIView

- (void)loadRequest:(NSString *)strURL;
@end

NS_ASSUME_NONNULL_END
