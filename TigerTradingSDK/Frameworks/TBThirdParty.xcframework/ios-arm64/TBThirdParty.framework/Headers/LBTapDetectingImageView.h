//
//  LBTapDetectingImageView.h
//  test
//
//  Created by dengweihao on 2017/3/16.
//  Copyright © 2017年 dengweihao. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <FLAnimatedImage/FLAnimatedImageView.h>
#import <TBThirdParty/FLAnimatedImageView+WebCache.h>

@class LBPhotoBrowserManager;
@interface LBTapDetectingImageView : FLAnimatedImageView

@property (nonatomic, weak) LBPhotoBrowserManager *browserManager;

@end

