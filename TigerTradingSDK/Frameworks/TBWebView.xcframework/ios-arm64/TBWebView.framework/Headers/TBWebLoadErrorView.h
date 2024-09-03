//
//  TBWebLoadErrorView.h
//  TBWebView
//
//  Created by linbingjie on 2023/10/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWebLoadErrorView : UIView

- (void)updateErrorTitle:(NSString *)title
               urlString:(NSString *)errorUrl
             detailTitle:(NSMutableAttributedString *)attributeString
          retryBtnHidden:(BOOL)isRetryHidden;

@property (nonatomic, copy) void (^retryButtonActionBlock)(void);


@end

NS_ASSUME_NONNULL_END
