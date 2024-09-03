//
//  UIButton+TouchArea.h
//  Stock
//
//  Created by zhengzhiwen on 2021/2/3.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (TouchArea)

- (UIEdgeInsets)touchArea;
- (void)setTouchArea:(UIEdgeInsets)area;

@end

NS_ASSUME_NONNULL_END
