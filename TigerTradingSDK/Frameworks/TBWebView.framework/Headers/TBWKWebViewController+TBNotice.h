//
//  TBWKWebViewController+TBNotice.h
//  TBWebView
//
//  Created by chenxin on 2021/8/5.
//

#import "TBWKWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBWKWebViewController (TBNotice)

// 获取公告链接，原来的逻辑，先保留
- (void)netGetNewsDetailFromID:(NSString *)newsID;

// 下载公告文件，原来的逻辑，先保留
- (void)downloadPdf;
- (void)downloadPdfForUrlstr:(NSString *)pdfUrl;


@end

NS_ASSUME_NONNULL_END
