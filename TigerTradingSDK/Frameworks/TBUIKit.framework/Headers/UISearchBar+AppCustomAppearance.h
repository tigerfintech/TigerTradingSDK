//
//  UISearchBar+AppCustomAppearance.h
//  Stock
//
//  Created by yangfan on 2019/7/31.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UISearchBar+CustomAppearance.h"

NS_ASSUME_NONNULL_BEGIN

@interface UISearchBar(AppCustomAppearance)

- (void)applyThemeStyle:(NSString *)placeholder;

- (void)applyRspSearchStyle:(NSString *)placeholder;

- (void)applyRspHomePageSearchStyle:(NSString *)placeholder;

/// UI新规范，superView BG A1下的search的UI设置
- (void)applyThemeStyleSuperViewBGA1:(NSString *)placeholder;
/// UI新规范，superView BG A4下的search的UI设置
- (void)applyThemeStyleSuperViewBGA4:(NSString *)placeholder;

@end

NS_ASSUME_NONNULL_END
