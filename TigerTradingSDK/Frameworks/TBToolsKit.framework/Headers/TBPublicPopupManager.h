//
//  TBPublicPopupManager.h
//  Stock
//
//  Created by chenxin on 2020/5/26.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@class TBStreamPublicPopupMaterialModel;

// 管理弹窗物料展示逻辑
@interface TBPublicPopupManager : NSObject

DECLARE_SHARED_INSTANCE(TBPublicPopupManager)

// 显示启动弹窗，可能在行情tab或者首页tab
- (void)showAppLoadedPopupIfNeedAtTabIndex:(NSInteger)tabIndex isRealTime:(BOOL)isRealTime success:(void(^)(id materialModel))success;

// 显示引导下单弹窗，默认首页（可能在行情tab或者首页tab）
- (void)showHomepagePlaceOrderPopupIfNeedAtTabIndex:(NSInteger)tabIndex success:(void(^)(id materialModel))success;

// 显示任务完成弹窗，默认首页（可能在行情tab或者首页tab）
- (void)showHomepageTaskCompletePopupIfNeedAtTabIndex:(NSInteger)tabIndex success:(void(^)(id materialModel))success;

/// TigerVault 首页显示弹框
- (void)showTigerVaultDetailPopupIfNeedAtVC:(NSString *)VCClass Success:(void(^)(id materialModel))success;

/// 显示底部浮动条
/// @param materialModel 物料model
/// @param isLive 是否是直播
/// @param view 显示在哪个view上
/// @param bottomOffset 距离view底部的偏移，根据设计如果页面底部有tabBar或工具栏，要据其顶部再加10，否则为SAFEAREA_BOTTOM_HEIGHT+25
+ (void)showBottomToastWithMaterial:(TBStreamPublicPopupMaterialModel *)materialModel
                             isLive:(BOOL)isLive
                             inView:(UIView *)view
                       bottomOffset:(CGFloat)bottomOffset;

@end

NS_ASSUME_NONNULL_END
