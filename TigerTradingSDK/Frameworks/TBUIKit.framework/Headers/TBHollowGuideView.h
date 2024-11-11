//
//  TBHollowGuideView.h
//  TBUIKit
//
//  Created by chenxin on 2023/10/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBHollowGuideBubbleArrowDirection) {
    TBHollowGuideBubbleArrowDown,
    TBHollowGuideBubbleArrowUp,
};

@interface TBHollowGuideBubbleView : UIView

@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIImageView *arrowView;
@property (nonatomic, strong) UIButton *closeButton;

- (instancetype)initWithArrowDirection:(TBHollowGuideBubbleArrowDirection)arrowDirection;

@end

@interface TBHollowGuideView : UIView

/*
 在keyWindow上显示气泡+镂空的引导，气泡在镂空位置上方
 title 气泡标题
 hollowFrame 镂空范围，需要在外部使用convertFrameToWindow方法转换坐标
 hasNextStep 是否有下一步（如果没有下一步点击镂空位置会触发closeBlock回调）
 closeBlock 点击关闭按钮的回调，用于设置引导不再隐藏
 */
+ (TBHollowGuideView *)showWithTopTitle:(NSString *)title
                            hollowFrame:(CGRect)hollowFrame
                            hasNextStep:(BOOL)hasNextStep
                             closeBlock:(void (^)(void))closeBlock;

/*
 在keyWindow上显示气泡+镂空的引导，气泡在镂空位置下方
 title 气泡标题
 hollowFrame 镂空范围，需要在外部使用convertFrameToWindow方法转换坐标
 hasNextStep 是否有下一步（如果没有下一步点击镂空位置会触发closeBlock回调）
 closeBlock 点击关闭按钮的回调，用于设置引导不再隐藏
 */
+ (TBHollowGuideView *)showWithBottomTitle:(NSString *)title
                               hollowFrame:(CGRect)hollowFrame
                               hasNextStep:(BOOL)hasNextStep
                                closeBlock:(void (^)(void))closeBlock;

/*
 在keyWindow上显示气泡+镂空的引导，上下两个气泡，共同指向一个镂空位置
 topTitle 上方气泡标题
 bottomTitle 下方气泡标题
 topArrowCenterX 上方气泡箭头位置
 bottomArrowCenterX 下方气泡箭头位置
 hollowFrame 镂空范围，需要在外部使用convertFrameToWindow方法转换坐标
 hasNextStep 是否有下一步（如果没有下一步点击镂空位置会触发closeBlock回调）
 closeBlock 点击关闭按钮的回调，用于设置引导不再隐藏
 */
+ (TBHollowGuideView *)showWithTopTitle:(NSString *)topTitle
                            bottomTitle:(NSString *)bottomTitle
                        topArrowCenterX:(CGFloat)topArrowCenterX
                     bottomArrowCenterX:(CGFloat)bottomArrowCenterX
                            hollowFrame:(CGRect)hollowFrame
                            hasNextStep:(BOOL)hasNextStep
                             closeBlock:(void (^)(void))closeBlock;

@end

NS_ASSUME_NONNULL_END
