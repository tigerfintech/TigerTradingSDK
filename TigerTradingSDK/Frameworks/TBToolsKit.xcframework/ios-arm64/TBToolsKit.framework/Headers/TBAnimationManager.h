//
//  TBAnimationManager.h
//  Stock
//
//  Created by dulijun on 2019/6/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^TbCommunityAnimationCompletionBlock)(BOOL animationFinished);

#define kTBAnimationMineTabNewbieGiftViewTag (20000)
#define kTBAnimationPersonCenterLevelViewTag (50)

@interface TBAnimationManager : NSObject

DECLARE_SHARED_INSTANCE(TBAnimationManager);

#pragma mark - 社区-点赞
/*
 添加到inView上，
 位置居中，
 大小用默认的
 */
- (void)addPraiseAnimationToView:(UIView *)inView completion:(TbCommunityAnimationCompletionBlock)completionBlock;

/*
 添加到inView上，
 位置、大小自定义
 */
- (void)addPraiseAnimationWithFrame:(CGRect)animationFrame ToView:(UIView *)inView completion:(TbCommunityAnimationCompletionBlock)completionBlock;

/*
 添加到inView上，
 大小自定义,
 center与inView上的子视图某个子视图相同
 */
- (void)addPraiseAnimationToView:(UIView *)inView WithSize:(CGSize)animationSize centerEqualToView:(UIView *)centerView completion:(TbCommunityAnimationCompletionBlock)completionBlock;
//带桃心效果，目前只用在帖子详情页
- (void)addPraiseWithHeartAnimationWithFrame:(CGRect)animationFrame ToView:(UIView *)inView completion:(TbCommunityAnimationCompletionBlock)completionBlock;

#pragma mark - tabbar点击动画
- (void)addNewbieGiftToView:(UIView *)inView;


/// 我的页面 等级图标添加动画
/// @param inView 展示等级的控件
- (void)addAnimationWithLevel:(NSNumber *)level ToView:(UIView *)inView isSvip:(BOOL)isSvip;


/// 我的页面签到图标添加动画
/// @param inView 被添加动画的view
- (void)addPersonCenterSignAnimationToView:(UIView *)inView completion:(TbCommunityAnimationCompletionBlock)completionBlock;

#pragma mark - others通用
- (void)addLottieAnimationWithFrame:(CGRect)animationFrame jsonName:(NSString *)jsonName ToView:(UIView *)inView completion:(TbCommunityAnimationCompletionBlock)completionBlock;


@end

NS_ASSUME_NONNULL_END
