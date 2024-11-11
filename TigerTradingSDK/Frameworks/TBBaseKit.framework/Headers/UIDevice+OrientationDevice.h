//
//  UIDevice+OrientationDevice.h
//  Stock
//
//  Created by PXJ on 2020/6/2.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIDevice (OrientationDevice)

/**
 * @interfaceOrientation 输入要强制转屏的方向
 */
+ (void)switchNewOrientation:(UIInterfaceOrientation)interfaceOrientation;

@end
NS_ASSUME_NONNULL_END
