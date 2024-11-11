//
//  TBVerificationStatusView.h
//  Stock
//
//  Created by chenxin on 2018/10/18.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TBVerificationStatus) {
    TBVerificationStatusUnverified, // 未认证
    TBVerificationStatusReviewing,  // 审核中
    TBVerificationStatusVerified,   // 已通过
    TBVerificationStatusRejected,   // 拒绝
    TBVerificationStatusInvalid,   // 验证失败
};

@interface TBVerificationStatusView : UIView

// 设置状态，使用状态对应的默认文本和颜色
@property (nonatomic, assign) TBVerificationStatus status;

// 如果需要自定义文本或颜色，通过以下两个属性设置
@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) UIColor *color;

@end
