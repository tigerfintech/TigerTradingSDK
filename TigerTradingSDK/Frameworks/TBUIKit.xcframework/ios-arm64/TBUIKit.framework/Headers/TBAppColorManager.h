//
//  TBAppColorManager.h
//  Stock
//
//  Created by ChenXin on 2018/1/5.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import "TBCommonAppColor.h"

@interface TBAppColorManager : NSObject

// 默认皮肤（不应用智能皮肤时）
@property (nonatomic, assign) TBAppColorStyle defaultAppColorStyle;

// 临时强制白皮肤，用于分享截图等
@property (nonatomic, assign) BOOL forceWhiteStyle;

// 临时强制黑皮肤，用于 esop H5
@property (nonatomic, assign) BOOL forceDarkStyle;

/// 自动跟随系统主题设置
@property (nonatomic, assign) BOOL followSystemAppearance;

// 是否开启智能换肤
@property (nonatomic, assign) BOOL shouldChangeAppColorSmartly;

// 智能换肤可选颜色，当前为蓝色和黑色
@property (nonatomic, copy) NSArray *nightAppColorStyles;

// 智能换肤当前选中颜色，默认蓝色
@property (nonatomic, assign) TBAppColorStyle nightAppColorStyle;

// 智能换肤时段，默认23:00-08:00
@property (nonatomic, copy) NSString *smartTimePeriod;

DECLARE_SHARED_INSTANCE(TBAppColorManager)

// 当前皮肤
- (TBAppColorStyle)currentAppColorStyle;

// 供RN百科使用，返回值：black,blue,white
- (NSString *)currentThemeName;

// 皮肤名称
+ (NSArray *)skinNames;
+ (NSString *)currentSkinName;

//tabBar 出现的时候，检查是否需要展示切换皮肤弹框
- (void)checkNeedShowAlert;

@end

@interface NSDate (TBTimePeriod)

// 当前日期是否在时段内
- (BOOL)tb_isInTimePeriod:(NSString *)timePeriod;

@end
