//
//  TBPlaceOrderGuideManager.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/16.
//

#import <Foundation/Foundation.h>
#import "TBPlaceOrderGuideTipsView.h"
#import <TBToolsKIT/TBStreamPublicPopupModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderGuideManager : NSObject
DECLARE_SHARED_INSTANCE(TBPlaceOrderGuideManager);

// 设置当前关联的物料
+ (void)setCurrentData:(TBStreamPublicPopupMaterialModel *)data;
// 当前关联的物料
+ (TBStreamPublicPopupMaterialModel *)currentData;

// 当前是否处在引导流程中（不是指的是否显示guide view，由于别的因素可能会打断引导，虽然view不显示了，依然是处在引导流程中）
+ (BOOL)isInGuide;

// 展示引导tip
+ (void)showTip:(TBMultiStepGuideTipsModel *)tip;

// 展示引导tip 多个
+ (void)showTips:(NSArray *)tipsArray;

// 标识当前的下单流程为引导下单
+ (void)start;

// 标识引导下单已结束
+ (void)finish;

// 禁用当前浮窗（的物料）
+ (void)forbiddenCurrentPopup;

@end

NS_ASSUME_NONNULL_END
