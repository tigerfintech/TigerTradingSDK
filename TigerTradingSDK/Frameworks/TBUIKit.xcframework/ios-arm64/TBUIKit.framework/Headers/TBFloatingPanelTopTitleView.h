//
//  TBFloatingPanelTopTitleView.h
//  TBUIKit
//
//  Created by linbingjie on 2023/7/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFloatingPanelTopTitleView : UIView

- (void)setupTitleString:(nullable NSString *)strTitle subTitleString:(nullable NSString *)subTitleString;

// 获取这个view的高度
- (NSInteger)fetchTotalViewHeight;

- (void)configTopViewBackgroundColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
