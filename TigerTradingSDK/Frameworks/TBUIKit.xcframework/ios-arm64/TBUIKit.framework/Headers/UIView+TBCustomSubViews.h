//
//  UIView+TBCustomSubViews.h
//  Stock
//
//  Created by JustLee on 2019/7/26.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (TBCustomSubViews)

@property (nonatomic, assign) CGPoint startPoint;

@property (nonatomic, strong) UIView *lastSubView;

- (__kindof UIView *)addTBCustomViewWithClass:(Class)cls requiredSize:(CGSize)size;

- (__kindof UIView *)addTBCustomViewWithClass:(Class)cls relatedItem:(UIView *)realatedItem requiredSize:(CGSize)size;

#pragma mark -- hor

- (__kindof UIView *)addHorizontalCustomViewWithClass:(Class)cls requiredSize:(CGSize)size horSpace:(CGFloat)horSpace;

- (__kindof UIView *)addHorizontalCustomViewWithClass:(Class)cls relatedItem:(UIView *)realatedItem requiredSize:(CGSize)size horSpace:(CGFloat)horSpace;

#pragma mark -- ver

- (__kindof UIView *)addVerticalCustomViewWithClass:(Class)cls requiredSize:(CGSize)size verSpace:(CGFloat)verSpace;

- (__kindof UIView *)addVerticalCustomViewWithClass:(Class)cls relatedItem:(UIView *)realatedItem requiredSize:(CGSize)size verSpace:(CGFloat)verSpace;

@end
