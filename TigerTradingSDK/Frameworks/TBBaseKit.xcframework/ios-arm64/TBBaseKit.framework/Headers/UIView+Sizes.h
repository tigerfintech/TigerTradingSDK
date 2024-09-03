//
// Copyright 2009-2010 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

@interface UIView (Sizes)

/**
 * Shortcut for frame.origin.x.
 *
 * Sets frame.origin.x = left
 */
@property (nonatomic) CGFloat left;

/**
 * Shortcut for frame.origin.y
 *
 * Sets frame.origin.y = top
 */
@property (nonatomic) CGFloat top;

/**
 * Shortcut for frame.origin.x + frame.size.width
 *
 * Sets frame.origin.x = right - frame.size.width
 */
@property (nonatomic) CGFloat right;

/**
 * Shortcut for frame.origin.y + frame.size.height
 *
 * Sets frame.origin.y = bottom - frame.size.height
 */
@property (nonatomic) CGFloat bottom;

/**
 * Shortcut for frame.size.width
 *
 * Sets frame.size.width = width
 */
@property (nonatomic) CGFloat width;

/**
 * Shortcut for frame.size.height
 *
 * Sets frame.size.height = height
 */
@property (nonatomic) CGFloat height;

/**
 * Shortcut for center.x
 *
 * Sets center.x = centerX
 */
@property (nonatomic) CGFloat centerX;

/**
 * Shortcut for center.y
 *
 * Sets center.y = centerY
 */
@property (nonatomic) CGFloat centerY;

/**
 * Return the x coordinate on the screen.
 */
@property (nonatomic, readonly) CGFloat ttScreenX;

/**
 * Return the y coordinate on the screen.
 */
@property (nonatomic, readonly) CGFloat ttScreenY;

/**
 * Return the x coordinate on the screen, taking into account scroll views.
 */
@property (nonatomic, readonly) CGFloat screenViewX;

/**
 * Return the y coordinate on the screen, taking into account scroll views.
 */
@property (nonatomic, readonly) CGFloat screenViewY;

/**
 * Return the view frame on the screen, taking into account scroll views.
 */
@property (nonatomic, readonly) CGRect screenFrame;

/**
 * Shortcut for frame.origin
 */
@property (nonatomic) CGPoint origin;

/**
 * Shortcut for frame.size
 */
@property (nonatomic) CGSize size;

/**
 * Finds the first descendant view (including this view) that is a member of a particular class.
 */
- (UIView*)descendantOrSelfWithClass:(Class)cls;

/**
 * Finds the first ancestor view (including this view) that is a member of a particular class.
 */
- (UIView*)ancestorOrSelfWithClass:(Class)cls;

/**
 * Removes all subviews.
 */
- (void)removeAllSubviews;

/**
 * The view controller whose view contains this view.
 */
- (UIViewController*)viewController;

- (UIImage *)imageFromView;
- (UIImage *)imageFromViewWithLowResolution;
- (UIImage *)imageFromBlurView;
- (UIImage *)imageFromViewInRect:(CGRect)rect;
- (UIImage *)imageFromViewWithLowResolutionInRect:(CGRect)rect;

- (CGRect)convertFrameToWindow:(UIWindow *)window;

- (CGRect)expandedFrame:(CGRect)originalFrame withVerticalOffset:(CGFloat)offset;
- (CGRect)expandedFrame:(CGRect)originalFrame withHorizontalOffset:(CGFloat)offset;
- (CGRect)expandedFrame:(CGRect)originalFrame withOffset:(CGFloat)offset;

- (UIView*)viewForAnimation;

- (void)sizeToFitSize:(CGSize)size;

- (void)tb_sizeToFit;


/**
 关键帧背景动画

 @param colors 背景颜色 values ex：@[(id)backColor.CGColor, (id)COLOR_BACKGROUND_DARK.CGColor];
 @param duration 动画时长
 */
- (void)keyBackColorAnimationWithColors:(NSArray*)colors duration:(CGFloat)duration;

/**
 浮层

 @param rect 浮层显示react
 @param isDrawCircle 是否绘制圆形
 */
+ (UIView *)maskGuideViewWithRect:(CGRect)rect drawCircle:(BOOL)isDrawCircle;

+ (CGFloat)safeAreaTop;

+ (CGFloat)safeAreaBottom;

/**
 CABasicAnimation 旋转动画

 @param view 要旋转的视图
 @param fromValue 起始值
 @param toValue 终点值
 */
+ (void)animationTransformRotationWith:(UIView *)view fromValue:(double)fromValue toValue:(double)toValue;

- (void)showInWindowWithDuration:(NSTimeInterval)duration animate:(void (^)(void))animate;
- (void)showInWindowWithDuration:(NSTimeInterval)duration animate:(void (^)(void))animate completion:(void (^)(BOOL finish))completion;
- (void)hideWithDuration:(NSTimeInterval)duration animate:(void (^)(void))animate;
@end
