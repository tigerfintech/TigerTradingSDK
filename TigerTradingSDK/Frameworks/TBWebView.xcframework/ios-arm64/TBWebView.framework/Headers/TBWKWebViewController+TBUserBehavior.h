//
//  TBWKWebViewController+TBUserBehavior.h
//  TBWebView
//
//  Created by linbingjie on 2021/8/10.
//

#import "TBWKWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBWKWebViewController (TBUserBehavior)

@property (nonatomic, copy) NSString *saTrackEvent; // 神策统计事件名称
@property (nonatomic, copy, nullable) NSDictionary *saTrackProperties; // 神策统计事件属性

- (void)tb_userBehaviorWebViewWillAppear:(BOOL)animated;
- (void)tb_userBehaviorWebViewWillDisappear:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
