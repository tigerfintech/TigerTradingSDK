//
//  TBWKWebViewController+TBDebugTool.h
//  Stock
//
//  Created by linbingjie on 2020/2/18.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBWKWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBWKWebViewController (TBDebugTool)
<
 TBWebViewDebugToolbarDelegate
>

/// 打开 debug 模式
- (void)tb_openDebugMode;

@end

NS_ASSUME_NONNULL_END
