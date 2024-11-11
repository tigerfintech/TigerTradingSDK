//
//  TBNavigationBar.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBNavigationBar : UINavigationBar

@property (nonatomic, strong) UIView *bottomLineView;

@property (nonatomic, assign) BOOL bottomLineHidden;

// 设置背景透明，同时能响应底层view操作
@property (nonatomic, assign) BOOL backgroundViewTransparent;

- (void)changeAppColor;

@end
