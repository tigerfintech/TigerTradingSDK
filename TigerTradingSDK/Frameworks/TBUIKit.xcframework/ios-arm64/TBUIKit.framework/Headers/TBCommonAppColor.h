//
//  TBCommonAppColor.h
//  Stock
//
//  Created by ChenXin on 16/11/22.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TBAppColorStyle) {
    TBAppColorStyleBlack,   // 黑金皮肤
    TBAppColorStyleBlue,    // 深色皮肤
    TBAppColorStyleWhite,   // 浅色皮肤
    TBAppColorStyleInvalid,
};

extern NSString *const NOTIFICATION_KEY_CHANGE_APPCOLORSTYLE;

@interface TBCommonAppColor : NSObject

+ (TBAppColorStyle)appColorStyle;

+ (UIStatusBarStyle)preferredStatusBarStyle;

+ (UIColor *)colorWithHexString:(NSString *)hexString;

+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

//根据当前皮肤，从传入的颜色数组中返回对应颜色
+ (UIColor *)colorFromArray:(NSArray *)colorArray;

//根据多个色值返回颜色，balck,blue,white分别表示，黑色，蓝色，白色皮肤
+ (UIColor *)colorFromBlack:(int)black blue:(int)blue white:(int)white;

//根据多个色值返回颜色,Dark表示深色皮肤
+ (UIColor *)colorFromDark:(int)dark white:(int)white;

//根据多个色值返回颜色,Dark表示深色皮肤，并可设置透明度
+ (UIColor *)colorFromDark:(int)dark withAlpha:(CGFloat)darkAlpha white:(int)white withAlpha:(CGFloat)whiteAlpha;

// 对应颜色规范b5
+ (UIColor *)greenColor;

// 对应颜色规范b6
+ (UIColor *)redColor;

+ (UIColor *)makeOrderRedColor;
+ (UIColor *)makeOrderGreenColor;

+ (UIColor *)makeOrderRedHighLightColor;

+ (UIColor *)makeOrderGreenHighLightColor;
+ (UIColor *)makeOrderUnenableRedColor;
+ (UIColor *)makeOrderUnenableGreenColor;

+ (UIColor *)makeOrderPlaceOrderBgColor;
/**
 股价变动为0颜色
 */
+ (UIColor *)zeroChangePriceColor;

+ (UIColor *)tintColor;


#pragma mark - 6.5.9 全新颜色规范，替换完成后可完全删除之前的颜色

//品牌通用色（当前黄色）
+ (UIColor *)themeColorB4;
//图表蓝色(B5）
+ (UIColor *)themeColorB5;
//涨跌绿(B6）
+ (UIColor *)themeColorB6;
//涨跌红(B7）
+ (UIColor *)themeColorB7;
//常用背景色值(A1)，包括VC.view背景色，UITableView背景色，UITableViewCell背景色
+ (UIColor *)themeColorA1;
//通知横条背景色值(A2)
+ (UIColor *)themeColorA2;
//分隔线色值(A3)
+ (UIColor *)themeColorA3;
//分栏条色值(A4)
+ (UIColor *)themeColorA4;
//小卡片色值(A5)
+ (UIColor *)themeColorA5;
//卡片色值(A6)
+ (UIColor *)themeColorA6;
+ (UIColor *)themeColorA13;

// Tab控件选中背景色
+ (UIColor *)tabSelectedBackgroundColor;

+ (UIColor *)navBarBackgroundColor;

+ (UIColor *)navBarBottomLineColor;

+ (UIColor *)virtualAcountBackgroundColor;

+ (UIColor *)virtualAcountTextColor;

#pragma mark - 6.5.9 新规范文字颜色
//主文字色值(B1)
+ (UIColor *)themeColorB1;
//二级文字色值(B2)
+ (UIColor *)themeColorB2;
//三级文字色值(B3)
+ (UIColor *)themeColorB3;

+ (UIColor *)yellowTextColor;

+ (UIColor *)orangeColor;

+ (UIColor *)klineBlueColor;

+ (UIColor *)klineDarkBlueColor;

+ (UIColor *)klineOrangeColor;

// 图表数据颜色，lineNumber值为1-4
+ (UIColor *)chartDataColor:(NSInteger)lineNumber;

#pragma mark - 6.5.9 新版新增的图表及外链颜色，之前已经定义过的颜色则直接进行了修改

//图表紫色
+ (UIColor *)purpleColor;
//图表红色
+ (UIColor *)chartRedColor;
//图表黄色
+ (UIColor *)chartYellowColor;
//链接点击后的颜色
+ (UIColor *)linkClickedColor;
//链接颜色
+ (UIColor *)linkColor;

#pragma mark - 6.5.9 新规范特殊文字颜色

/**
 主题特殊颜色样式1，分组的卡片颜色 (0x262732,0x262732,0xFFFFFF)
 
 @return spicial color
 */
+ (UIColor *)themeColorS1;

/**
 主题特殊颜色样式2，点赞后文字颜色 (0x2C2E3B,0x2C2E3B,0xF8CC00)
 
 @return spicial color
 */
+ (UIColor *)themeColorS2;

+ (UIColor *)placeHolderColor;

+ (UIColor *)timeLineDotColor;

/// MBProgressHUD 文本和背景色
+ (UIColor *)hudTextColor;
+ (UIColor *)hudBackColor;

// 快捷下单 键盘背景色
+ (UIColor *)quickOrderKeyboardBackground;

+ (UIColor *)quickOrderKeyboardButtonNormalBackground;

+ (UIColor *)quickOrderKeyboardButtonHighLightBackground;

//头部切换栏颜色
+ (UIColor *)segmentBackgroundColor;
+ (UIColor *)segmentNormalTextColor;
+ (UIColor *)segmentSeletedTextColor;

+ (UIColor *)getDisableIncreaseColor;
+ (UIColor *)getDisableDecreaseColor;

@end
