//
//  TBAccountItemView.h
//  Stock
//
//  Created by ChenXin on 2017/5/17.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBAccountItemView : UIView

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, copy) NSString *iconTitle;///< 角标

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *valueLabel;
@property (nonatomic, strong) UIImageView *imageView;

@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *valueColor;

// 显示在图片右上角的提示Icon
@property (nonatomic, strong) UIImage *topRightImage;

@property (nonatomic, copy) NSDictionary *itemInfo;

// 用于埋点
@property (nonatomic, copy) NSString *trackComponent;
@property (nonatomic, copy) NSString *trackPage;

// 上下两行文字，下面的文字可变
- (instancetype)initWithTitle:(NSString *)title;

// isLeft=YES，左边图片，右边文字；否则上面图片，下面文字
- (instancetype)initWithImage:(UIImage *)image title:(NSString *)title isLeft:(BOOL)isLeft;

- (instancetype)initWithImage:(UIImage *)image imageSize:(CGSize)imageSize title:(NSString *)title isLeft:(BOOL)isLeft;

@end
