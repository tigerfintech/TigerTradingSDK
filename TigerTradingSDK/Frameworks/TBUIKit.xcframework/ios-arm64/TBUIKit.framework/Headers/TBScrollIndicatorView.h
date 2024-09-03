//
//  TBScrollIndicatorView.h
//  TBUIKit
//
//  Created by chenxin on 2024/4/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBScrollIndicatorDirection) {
    TBScrollIndicatorDirectionVertical,
    TBScrollIndicatorDirectionHorizontal,
};

/*
 自定义滚动条
 */
@interface TBScrollIndicatorView : UIView

@property (nonatomic, assign) TBScrollIndicatorDirection direction;

@property (nonatomic, strong) UIColor *backgroundColor;

@property (nonatomic, strong) UIColor *foregroundColor;

@property (nonatomic, assign) CGFloat cornerRadius;

/*
 根据scrollView的contentOffset、contentSize和宽高更新滚动条
 */
- (void)updateIndicatorWithScrollView:(UIScrollView *)scrollView;

@end

NS_ASSUME_NONNULL_END
