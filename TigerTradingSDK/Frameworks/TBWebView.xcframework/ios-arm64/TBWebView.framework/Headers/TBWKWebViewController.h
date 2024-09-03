//
//  TBWKWebViewController.h
//  Stock
//
//  Created by linbingjie on 2020/1/21.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//
@import TBUIKit;
#import "TBWebViewDebugToolbar.h"
#import "TBWebViewProgressView.h"
#import <TBShareKit/TBShareKit.h>
#import <TBUIKit/TBBaseViewController.h>
#import <TBThirdParty/DWKWebView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBWebViewControllerDelegate;

static NSString *const kDownloadFileHandler = @"downloadFileHandler";
extern NSString *const kTBQuitWebViewNotification;
extern NSString *const kTBNotifyMyInfoResultNotification;

@interface TBWKWebViewController : TBBaseViewController

@property (nonatomic, weak, class) id<TBWebViewControllerDelegate> delegate;

// 通过openURLAction传进来的参数
@property (nonatomic, copy) NSDictionary *queryDict;

@property (nonatomic, copy) NSString *url;

// 部分三方网站添加UserScript会导致加载失败，指定不添加
@property (nonatomic, assign) BOOL noUserScript;

@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSString *newsID; // 港股公告用
@property (nonatomic, copy) NSString *pdfUrl; // 公告pdf链接

// 期权测试跳转相关数据
@property (nonatomic, copy) NSDictionary *optionQueryDictionary;

@property (nonatomic, strong) TBShareInfoModel *shareInfo; // 分享信息
@property (nonatomic, assign) BOOL shareInfoByTigerBridge; // 根据h5中TigerBridge的回调设置分享信息
@property (nonatomic, copy) NSString *shareSuccessCallback; // 分享成功回调，通知html页面
@property (nonatomic, copy) NSString *shareFailCallback; // 分享失败回调，包括取消分享
@property (nonatomic, copy) NSString *adCode; // 活动代码，用于埋点
@property (nonatomic, assign) BOOL showRateAppAfterShare; // 分享完弹出评分弹窗

// 唤起 webview controller 的对象
// 目前暂时用于检查如果是 TBSecurityInterceptor, 说明是安全验证网页, 在退出时调用取消检查
@property (nonatomic, weak) id caller;

// 是否隐藏导航栏
@property (nonatomic, assign) BOOL headerBarHidden;
@property (nonatomic, assign) BOOL bounces; // default YES. if YES, bounces past edge of content and back again
@property (nonatomic, strong) TBWebViewDebugToolbar *debugToolbar;
@property (nonatomic, strong) DWKWebView *webView;
@property (nonatomic, strong) NSURLRequest *requestWebViewLoaded;
@property (nonatomic, strong) TBWebViewProgressView   *loadingProgressView;

// addURLParams 和 handleNormalRequest 需要顺序调用，这个方法提供给预加载页面使用, 其他页面不要直接使用这两个方法
+ (void)addURLParams:(NSMutableURLRequest *)request;
+ (NSString *)handleNormalRequest:(NSMutableURLRequest *)request;


- (void)addRequestAdditionParams:(NSMutableURLRequest *)request;

// 处理分享回调
- (void)handleShareCallback:(NSString *)callback parameters:(nullable NSDictionary *)parameters;

@property (nonatomic, assign) BOOL enableFileShare; // 能否分享

@property (nonatomic, copy, class) NSString * _Nullable loginOpenURL;
@property (nonatomic, copy, class) NSDictionary * _Nullable loginOpenParams;

// 在当前web页加载新的链接，用于跳出app再跳回等场景
- (void)loadNewLink:(NSString *)newLink;

@end

@protocol TBWebViewControllerDelegate <NSObject>

@optional

// 打开webView时的特殊处理，比如港股公告
- (void)webViewController:(TBWKWebViewController *)webViewController willOpenWithQuery:(NSDictionary *)query;

// 处理准备加载的情况，默认返回YES，如果有跳到原生页面等其他操作则返回NO
- (BOOL)webViewController:(TBWKWebViewController *)webViewController shouldStartNavigationWithRequest:(NSURLRequest *)request;

// 处理开始加载的情况
- (void)webViewControllerDidStartNavigation:(TBWKWebViewController *)webViewController;

// 处理加载失败的情况
- (void)webViewController:(TBWKWebViewController *)webViewController didFailNavigationWithError:(NSError *)error;

// 处理加载成功的情况
- (void)webViewControllerDidFinishNavigation:(TBWKWebViewController *)webViewController;

// 即将消失
- (void)webViewControllerWillDismiss:(TBWKWebViewController *)webViewController;

// 点击客服按钮
- (void)handleCustomServiceButtonClicked:(NSString *)page;

@end

NS_ASSUME_NONNULL_END
