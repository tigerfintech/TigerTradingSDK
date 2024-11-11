//
//  TBNewerGiftFloatingView.h
//  Stock
//
//  Created by charming on 2020/11/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBNewerGiftFloatingView : UIView

@property (nonatomic, copy) NSString *jumpUrl;
// 是否在同一天展示，用于判断点击关闭按钮后，当天不再展示，第二天才可以展示
+ (BOOL)showGiftViewInSameDate;

- (void)animationMoveOutOfScreen;

- (void)animationMoveIntoScreen;

@end

NS_ASSUME_NONNULL_END
