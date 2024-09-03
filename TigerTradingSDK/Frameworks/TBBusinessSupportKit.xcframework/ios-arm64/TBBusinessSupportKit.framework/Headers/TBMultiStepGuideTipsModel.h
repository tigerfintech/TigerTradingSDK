//
//  TBMultiStepGuideTipsModel.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/14.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TBPlaceOrderTipsType) {
    TBPlaceOrderTipsStepTypeNormal, // 镂空引导
    TBPlaceOrderTipsStepTypeAnimation, // 动画
};

NS_ASSUME_NONNULL_BEGIN

@interface TBMultiStepGuideTipsModel : NSObject

@property (nonatomic, copy) NSString *title; // 标题
@property (nonatomic, assign) CGRect hollowRect; // 镂空范围
@property (nonatomic, assign) CGRect actionRect; // 镂空可点击范围（如果没值，则取hollowRect）
@property (nonatomic, strong) void(^actionBlock)(void); // 点击镂空部分回调
@property (nonatomic, strong) void(^closeOptionActionBlock)(void);// 关闭的埋点

@property (nonatomic, copy) NSString *postName; // 发送的通知name（通过通知触发原来业务逻辑）
@property (nonatomic, assign) TBPlaceOrderTipsType stepType; //引导类型（普通引导，动画）

@property (nonatomic, copy) NSString *additionContent; // 附加标题 (1.如果是动画，为动画filename；2.如果是普通引导，则为虚线旁文字说明)
@property (nonatomic, assign) CGRect additionRect; // 附加镂空 （1.如果是动画，为动画frame；2.如果是普通引导，则为虚线框frame）

@end

NS_ASSUME_NONNULL_END
