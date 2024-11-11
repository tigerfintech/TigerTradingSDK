//
//  TBImpactFeedbackGenerator.h
//  Stock
//
//  Created by dulijun on 2019/7/29.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//


/*
 该震动功能要求：
 1.iOS10 及以上
 2.支持 Taptic Engine 机型 (iPhone 7 以及 iPhone 7 Plus，及以上).
 3.app 需要在前台运行
 4.系统 Haptics setting 需要开启 （设置-声音与触感-系统触感反馈）
 *************************************************************
 
 补充：
 若想不受系统限制，通过AudioServicesPlaySystemSound，也可实现轻柔的震动反馈
 // 普通短震，3D Touch 中 Peek 震动反馈
 AudioServicesPlaySystemSound(1519);
 // 普通短震，3D Touch 中 Pop 震动反馈
 AudioServicesPlaySystemSound(1520);
 // 连续三次短震
 AudioServicesPlaySystemSound(1521);
 但以上 ID 均未在 Apple 的 Documents 中描述。这是调用了一些私有一些属性 ,有风险。
 所以此方法作备选，暂不使用
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBImpactFeedbackStyle)
{
    TBImpactFeedbackStyleDefault,//默认为TBImpactFeedbackStyleLight
    TBImpactFeedbackStyleLight,//轻柔
    TBImpactFeedbackStyleMedium,//中
    TBImpactFeedbackStyleHeavy,//重
    TBImpactFeedbackStyleSelectionChange//选择状态改变，比如日期控件滑动
};

@interface TBImpactFeedbackGenerator : NSObject

+ (void)impactOccurred;//默认为TBImpactFeedbackStyleLight
+ (void)impactOccurredWithStyle:(TBImpactFeedbackStyle)style;

@end

NS_ASSUME_NONNULL_END
