//
//  TBGuideTipsView.h
//  Stock
//
//  Created by WCP on 2019/3/5.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,TBGuideBubbleViewDirection) {
    TBMaskViewDirectionBottomArrowRight,             // 位于view的下方，箭头靠右
    TBMaskViewDirectionBottomArrowUp,                // 位于view的下方，箭头靠上，居右边
    TBMaskViewDirectionUpArrowDown,                  // 位于view的上方，箭头靠上
    TBMaskViewDirectionBottomArrowUpCenter,          // 位于view的下方，箭头靠上，居中
    TBMaskViewDirectionArrowLeft,                    // 位于view的上方，箭头靠左
    TBMaskUpViewArrowDirectionDownArrowLocationRight,// 位于view上方,箭头指下，箭头位置靠右
    TBMaskViewDirectionBottomArrowUpLeft,                // 位于view的下方，箭头靠上，居左边
};

NS_ASSUME_NONNULL_BEGIN

@interface TBGuideBubbleView : UIView

@end

@interface TBGuideTipsView : UIView

@property (nonatomic, strong) UIImageView *gestureImageView;            //!< 箭头
@property (nonatomic, strong) TBGuideBubbleView *bubbleView;

@property (nonatomic, assign, readonly) BOOL isShowing;

@property (nonatomic, copy) NSString *viewKey;

@property (nonatomic, assign) BOOL needRemoveFromSuperView;

@property (nonatomic, copy) void (^finished)(void);

- (void)updateGesturesImageView:(NSString *)imageName;

/**
 引导手势在文字左边

 @param imageName 图片名称
 */
- (void)updateGesturesImageViewLeft:(NSString *)imageName;

/**
 引导手势在文字上边

 @param imageName 图片名称
 */
- (void)updateGesturesImageViewTop:(NSString *)imageName;

/**
 引导手势在文字右边

 @param imageName 图片名称
 */
- (void)updateGesturesImageViewRight:(NSString *)imageName;

/**
 行情页面下单时可自由拖动查看

 @param topView 要展示的view
 @param title 标题
 @param viewKey 标记当前View是否显示过的Key
 */
+ (void)showStockDetailCanScrollInMakingOrderTop:(UIView *)topView title:(NSString *)title viewKey:(NSString *)viewKey;

/**
 股票详情页点击盘口价格快捷输入

 @param rightView 要显示的view
 @param title 标题
 @param viewKey 标记当前View是否显示过的Key
 */
+ (void)showStockTapePriceItemRight:(UIView *)rightView title:(NSString *)title viewKey:(NSString *)viewKey;

+ (void)showCenterDownViewArrowUp:(UIView *)downView title:(NSString *)title viewKey:(NSString *)viewKey offset:(CGFloat)offset topOffset:(CGFloat)topOffset;

/**
 显示在downView的下方，箭头靠上,靠右

 @param downView 要显示的view
 @param title 标题
 @param viewKey 标记当前View是否显示过的Key
 */
+ (void)showDownViewArrowUp:(UIView *)downView title:(NSString *)title viewKey:(NSString *)viewKey;

/**
 显示在upView的上方，箭头靠下,居中
 
 @param upView 要显示的view
 @param title 标题
 @param viewKey 记当前View是否显示过的Key
 @param height 引导与upView的距离
 */
+ (void)showUpViewArrowDown:(UIView *)upView title:(NSString *)title viewKey:(NSString *)viewKey height:(float)height;

// 添加一个回调
+ (void)showUpViewArrowDown:(UIView *)upView title:(NSString *)title viewKey:(NSString *)viewKey height:(float)height finished:(void (^)(void))finished;

/**
 显示在upView的上方，箭头靠下，居左
 
 @param upView 要显示的view
 @param title 标题
 @param viewKey 记当前View是否显示过的Key
 @param height 引导与upView的距离
 @param leftOffsetX 距离左侧的offset
 */
+ (void)showUpViewArrowDown:(UIView *)upView title:(NSString *)title viewKey:(NSString *)viewKey height:(float)height leftOffsetX:(CGFloat)leftOffsetX finished:(void (^)(void))finished;

/// 显示在upView的上方，箭头靠下,居中
/// @param upView 要显示的view
/// @param title 标题
/// @param viewKey 记当前View是否显示过的Key
/// @param height 引导与upView的距离
/// @param needRemove 消失时是否至 nil
+ (void)showUpViewArrowDown:(UIView *)upView title:(NSString *)title viewKey:(NSString *)viewKey height:(float)height needRemove:(BOOL)needRemove;

/**
 显示在upView的上方，箭头靠下,居中

 @param upView 要显示的view
 @param title 标题
 @param viewKey 记当前View是否显示过的Key
 */
+ (void)showUpViewArrowDown:(UIView *)upView title:(NSString *)title viewKey:(NSString *)viewKey;


/**
 显示在downView的下方，箭头靠右，靠右
 
 @param downView 要显示的View
 */
+ (void)showCenterViewArrowRight:(UIView *)centerView title:(NSString *)title viewKey:(NSString *)viewKey;

/**
 显示在centerView的下方，箭头靠左，靠左
 
 @param centerView 要显示的View
 */
+ (void)showCenterViewArrowLeft:(UIView *)centerView title:(NSString *)title viewKey:(NSString *)viewKey bubbleWidth: (CGFloat)bubbleWidth bubbleHeight: (CGFloat)bubbleHeight offsetX:(CGFloat)offsetX;

/**
 显示在downView的下方，靠右
 
 @param downView 要显示的View
 @param gestureImageName 手势image
 */
+ (void)showCenterViewArrowRight:(UIView *)centerView title:(NSString *)title viewKey:(NSString *)viewKey gestureView:(nullable NSString *)gestureImageName;

+ (void)showCenterViewArrowRight:(UIView *)centerView title:(NSString *)title viewKey:(NSString *)viewKey gestureView:(nullable NSString *)gestureImageName offsetX:(CGFloat)offsetX;

///  显示在centerView的左边，箭头靠右
/// @param centerView 需要z提示的View
/// @param title 提示语
/// @param viewKey key
+ (void)showCenterViewLeftArrowRight:(UIView *)centerView title:(NSString *)title viewKey:(NSString *)viewKey offsetX:(double)offsetX;

/// 期权链锁定
/// @param targetView <#targetView description#>
+ (void)optionChainLock:(UIView *)targetView;


+ (void)showUpViewArrowDirectionDownArrowLocationRight:(UIView *)upView title:(NSString *)title viewKey:(NSString *)viewKey height:(float)height;

+ (void)hide;

/// 添加一个回调
/// @param centerView centerView description
/// @param title title description
/// @param viewKey viewKey description
/// @param finished finished description
+ (void)showTipsWithSuperView:(UIView *)centerView title:(NSString *)title viewKey:(NSString *)viewKey position:(TBGuideBubbleViewDirection)position finished:(void (^)(void))finished;

/**
 用户引导图

 @param viewKey view的唯一值
 @return 是否已经显示过
 */
+ (BOOL)getUserGuideOnlyShowOnceView:(NSString *)viewKey;

/**
 设置用户引导图 是否已经显示过

 @param viewKey view的唯一值
 @param value 是否已经显示过
 */
+ (void)setUserGuideOnlyShowOnceView:(NSString *)viewKey value:(BOOL)value;


/**
 设置DBS数字货币入金提示 是否已经显示过

 @param viewKey view的唯一值
 */
+ (void)setDBSDepositGuideOnlyShowOnceView:(UIView *)centerView title:(NSString *)title viewKey:(NSString *)viewKey;

@end

NS_ASSUME_NONNULL_END
