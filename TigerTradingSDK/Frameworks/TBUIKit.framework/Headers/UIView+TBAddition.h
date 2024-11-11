//
//  UIView+TBAddition.h
//  TBBaseUtils
//
//  Created by chenxin on 2021/1/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (TBAddition)

@property (nonatomic, strong) UIView *tb_redDotView;

- (void) addLineToTop;

- (void) addLineToBottom;

- (void) addLineToBottom:(CGFloat)x width:(CGFloat)width;

- (void) addLineToBottomWithColor:(UIColor *)color;

- (void) addLineToPoint:(CGPoint)point;

// 添加虚线方法
- (void)drawLineOfDashByCAShapeLayer:(UIView *)lineView lineLength:(int)lineLength lineSpacing:(int)lineSpacing lineColor:(UIColor *)lineColor lineDirection:(BOOL)isHorizonal;

// 添加红点，point为红点origin，width默认为6
- (void)tb_addRedDotWithPoint:(CGPoint)point;
- (void)tb_addRedDotWithPoint:(CGPoint)point width:(CGFloat)width;
// 移除红点
- (void)tb_removeRedDot;

- (void)showHint:(NSString *)hint hide:(CGFloat)delay enableBackgroundUserAction:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
