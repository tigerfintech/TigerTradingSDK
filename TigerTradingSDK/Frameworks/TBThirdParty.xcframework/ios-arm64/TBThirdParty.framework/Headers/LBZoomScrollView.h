//
//  LBZoomScrollView.h
//  test
//
//  Created by dengweihao on 2017/3/15.
//  Copyright © 2017年 dengweihao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LBTapDetectingImageView.h"
@class LBScrollViewStatusModel, LBPhotoBrowserManager;
@interface LBZoomScrollView : UIScrollView

@property (nonatomic , strong)LBScrollViewStatusModel *model;

@property (nonatomic , weak)LBTapDetectingImageView *imageView;

@property (nonatomic , assign)BOOL imageViewIsMoving;

@property (nonatomic, weak) LBPhotoBrowserManager *browserManager;

@property (nonatomic, copy) void (^gifImageDownLoadFinishBlock)(void);
@property (nonatomic, copy) void (^imageViewWillDismissBlock)(void);
@property (nonatomic, copy) void (^imageViewDidDismissBlock)(void);

- (void)handlesingleTap:(CGPoint)touchPoint;
- (void)handleDoubleTap:(CGPoint)touchPoint;
- (void)startPopAnimationWithModel:(LBScrollViewStatusModel *)model completionBlock:(void(^)(void))completion;

@end
