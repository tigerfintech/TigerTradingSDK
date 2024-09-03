//
//  UIView+WaterMark.h
//  TBTestPro
//
//  Created by WCP on 2018/5/11.
//  Copyright © 2018年 WCP. All rights reserved.
//

#import <UIKit/UIKit.h>
#define waterMarkTag 10011001
@interface UIView (WaterMark)

/**
 对图片添加水印
 */
- (void)addsubWaterMark;

/**
 删除水印
 */
- (void)deletesubWaterMark;
@end
