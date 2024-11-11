//
//  MZFormSheetPresentationViewController+MZStyle.h
//  Stock
//
//  Created by 王灵博 on 2020/8/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/MZFormSheetPresentationViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface MZFormSheetPresentationViewController (MZStyle)

- (void)setMZFormSheetStyle;

/** 设置formSheet背景色/圆角
 * - 圆角通过 layer.cornerRadius 方式来实现效果，不会截断view
 */
- (void)setMZFormSheetBackgroundAndCornerWithMaskedCorners;

- (void)addShadowForMZFormSheet;

- (void)hiddenCoverBackground;
@end

NS_ASSUME_NONNULL_END
