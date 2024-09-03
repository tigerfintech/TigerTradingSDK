//
//  TBGradientLayerView.h
//  ViewColorGrad
//
//  Created by xw.long on 16/3/21.
//  Copyright © 2016年 xw.long. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TBGradientLayerView;

@protocol TBGradientLayerViewDelegate <NSObject>
-(void)gradientLayerAnimationStart:(TBGradientLayerView *)layer;
-(void)gradientLayerAnimationFinished:(TBGradientLayerView *)layer;
@end

@interface TBGradientLayerView : UIView

@property (nonatomic, strong) CAGradientLayer *colorLayer;
@property (nonatomic, strong) CABasicAnimation *basicAnimation;
@property (nonatomic, strong) NSTimer *timerAnimation;
@property (nonatomic, assign) BOOL showGradientLayer;
@property (nonatomic, assign) BOOL increaseColorRed;
@property (nonatomic, assign) BOOL canAnimation;

/// 是否只有一种背景色，明细数字背景色只有一种，没有渐变背景色
@property (nonatomic, assign) BOOL oneBackColor;
@property (nonatomic, strong) NSNumber *timeDuration;//动画间隔

@property (nonatomic, weak) id <TBGradientLayerViewDelegate>delegate;

- (void)reloadLayerConfigures;

@end
