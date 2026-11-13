//
//  TB23SDKStockDetailTitleView.h
//  TigerQuoteSDK_Example
//
//  Created by chenxin on 2025/9/12.
//  Copyright © 2025 linbingjie. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TB23SDKStockDetailTitleView : UIControl

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *time;

@property (nonatomic, assign) BOOL shouldShowPrice;

- (void)setAttributedPrice:(NSAttributedString *)attributedPrice;

@end

NS_ASSUME_NONNULL_END
