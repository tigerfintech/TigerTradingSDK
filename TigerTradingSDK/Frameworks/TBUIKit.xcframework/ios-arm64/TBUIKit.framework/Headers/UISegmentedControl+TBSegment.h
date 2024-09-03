//
//  UISegmentedControl+TBSegment.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/5/14.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kSegmentHeight30 32
#define kSegmentHeight25 26


NS_ASSUME_NONNULL_BEGIN

@interface UISegmentedControl (TBSegment)

/// 字号跟随系统设置改变
- (void)setSegmentCustomUI;

/// 字号不跟随系统设置改变
- (void)setSegmentCustomUI_NOAdjustFont;

@end

NS_ASSUME_NONNULL_END
