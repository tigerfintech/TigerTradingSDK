//
//  TB23SDKPlaceOrderCustomAccountDataViewController.h
//  TigerQuoteSDK
//
//  Created by chenxin on 2025/8/22.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TB23SDKPlaceOrderCustomAccountDataViewController : UIViewController

@property (nonatomic, weak) UIViewController *placeOrderAccountDataViewController;

@property (nonatomic, assign) BOOL subVCTableViewScrollDisabled; // 默认为NO

@property (nonatomic, copy) void(^updateContentHeightBlock)(CGFloat contentHeight);

- (CGFloat)contentHeight;

@end

NS_ASSUME_NONNULL_END
