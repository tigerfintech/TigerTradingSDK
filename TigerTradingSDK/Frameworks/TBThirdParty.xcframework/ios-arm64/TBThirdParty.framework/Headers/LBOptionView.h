//
//  LBOptionView.h
//  test
//
//  Created by dengweihao on 2017/8/17.
//  Copyright © 2017年 dengweihao. All rights reserved.
//

#import <UIKit/UIKit.h>
@class LBPhotoBrowserManager;

@interface LBOptionView : UIView

@property (nonatomic , strong)UIImage *image;

+ (instancetype)showOptionViewWithBrowserManager:(LBPhotoBrowserManager *)browserManager;
+ (instancetype)showOptionViewWithCurrentCellImage:(UIImage *)image browserManager:(LBPhotoBrowserManager *)browserManager;

@end
