//
//  UINavigationBar+Custom.h
//  Stock
//
//  Created by ChenXin on 17/2/9.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationBar (Custom)

//设置导航栏标题样式
- (void)tb_setNavBarTitleStyle:(UIColor *)tintColor textAttributes:(NSDictionary *)textAttributes;

//隐藏导航栏底部线条
- (void)tb_hidesBottomLine;

@end
