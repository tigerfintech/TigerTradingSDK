//
//  TBTransactionTipView.h
//  Stock
//
//  Created by mashanli on 2022/5/30.
//  Copyright © 2022 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBTransactionBubbleView : UIView

- (void)updateViewWithTitle:(NSString *)title;

@end


@interface TBTransactionTipView : UIView

// 添加一个回调
+ (void)showUpViewArrowDown:(UIView *)upView title:(NSString *)title viewKey:(NSString *)viewKey height:(float)height finished:(void (^)(void))finished;

+ (void)removeGuideView;

@end
