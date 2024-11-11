//
//  TBUIKitComponentService.h
//  Pods
//
//  Created by linbingjie on 2023/1/9.
//

#ifndef TBUIKitComponentService_h
#define TBUIKitComponentService_h

NS_ASSUME_NONNULL_BEGIN

@protocol TBUIKitComponentService <NSObject>

/// 获取ZERO_PRICE_CELL_COLOR对应的颜色
- (UIColor *)tbUIKit_ZERO_PRICE_CELL_COLOR;

/// 通过TBResourcesImage获取图片资源
/// - Parameter name: 图片名字
- (UIImage *)tbUIKit_TBResourcesImage:(NSString *)name;

- (UIColor *)tbUIKit_INCREASE_PRICE_COLOR;
- (UIColor *)tbUIKit_DISCREASE_PRICE_COLOR;

- (UIColor *)tbUIKit_INCREASE_MAKEORDER_PRICE_COLOR;
- (UIColor *)tbUIKit_DISCREASE_MAKEORDER_PRICE_COLOR;

- (UIColor *)tbUIKit_DISCREASE_MAKEORDER_Hight_COLOR;
- (UIColor *)tbUIKit_INCREASE_MAKEORDER_HIGHT_COLOR;

- (UIColor *)tbUIKit_INCREASE_MAKEORDER_UNABLE_PRICE_COLOR;
- (UIColor *)tbUIKit_DISCREASE_MAKEORDER_UNABLE_PRICE_COLOR;


- (UIColor *)tbUIKit_ColorFromArray:(NSArray *)colorArray;

/// 判断当前app color 是否是白色的
- (BOOL)tbUIKit_currentAppColorStyleISWhite;

/// sd showhint
/// - Parameters:
///   - hint: detail message
///   - delay: delay
- (void)tbUIKit_showHint:(NSString *)hint hide:(CGFloat)delay;

//根据多个色值返回颜色,Dark表示深色皮肤，并可设置透明度
- (UIColor *)tbUIKit_colorFromDark:(int)dark
                         withAlpha:(CGFloat)darkAlpha
                             white:(int)white
                         withAlpha:(CGFloat)whiteAlpha;
@end

NS_ASSUME_NONNULL_END

#endif /* TBUIKitComponentService_h */
