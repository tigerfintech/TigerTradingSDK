//
//  UIButton+TBActionBlock.h
//  TBUIKit
//
//  Created by dulijun on 2023/5/31.
//

#import <UIKit/UIKit.h>

typedef void(^TBButtonActionBlock)(UIButton* _Nullable button);

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (TBActionBlock)

@property (nonatomic, copy) TBButtonActionBlock actionBlock;

/**
 button 添加点击block事件
 @param action 点击事件回调
 */
- (void)addAction:(TBButtonActionBlock)action;


/**
 button 添加点击block事件
 @param controlEvents 点击的方式
 @param action 点击事件回调
 */
- (void)addControlEvents:(UIControlEvents)controlEvents action:(TBButtonActionBlock)action;

@end

NS_ASSUME_NONNULL_END
