//
//  TUPUtils+Animation.h
//  StockGlobal
//
//  Created by wind on 2020/3/26.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBCardAnimation.h"

// VC使用这个动画效果的话，需要注意 present 出来的 VC，在展示和消失时有自己的动画，需要禁止。不然影响这里的动画效果。

@interface TBAnimation : NSObject<CAAnimationDelegate>

@end

@interface TBCardAnimation: NSObject

/// 底部展示卡片动画
/// @param card 要弹出的卡片视图
/// @param bgView 背景视图
/// @param removedOnCompletion 动画结束，是否移除
/// @param completion 动画完成回调
+ (void)showBottomCardAnimationWithCard:(UIView *)card bgView:(UIView *)bgView removedOnCompletion:(BOOL)removedOnCompletion completion:(void(^)(void))completion;

+ (void)showBottomCardAnimationWithCard:(UIView *)card bgView:(UIView *)bgView completion:(void(^)(void))completion;

/// 底部收起卡片动画
/// @param card 卡片视图
/// @param bgView 背景视图
/// @param removedOnCompletion 动画结束，是否移除
/// @param completion 动画完成回调
+ (void)dismissBottomCardAnimationWithCard:(UIView *)card bgView:(UIView *)bgView removedOnCompletion:(BOOL)removedOnCompletion completion:(void(^)(void))completion;

+ (void)dismissBottomCardAnimationWithCard:(UIView *)card bgView:(UIView *)bgView completion:(void(^)(void))completion;

@end
