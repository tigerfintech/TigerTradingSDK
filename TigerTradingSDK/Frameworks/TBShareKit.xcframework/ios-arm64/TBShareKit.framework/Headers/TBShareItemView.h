//
//  TBShareItemView.h
//  Stock
//
//  Created by ChenXin on 2017/5/26.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBBaseKit/TBPhoneUtility.h>

#define kShareItemViewWidth (MIN(SCREEN_WIDTH, SCREEN_HEIGHT) * 45 / 375)

@interface TBShareItemView : UIView

@property (nonatomic, strong) UIImageView *imageView;

- (instancetype)initWithImage:(UIImage *)image title:(NSString *)title score:(NSString *)score;

- (instancetype)initWithImage:(UIImage *)image title:(NSString *)title;

@end
