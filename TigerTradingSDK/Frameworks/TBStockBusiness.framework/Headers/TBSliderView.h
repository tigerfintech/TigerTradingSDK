//
//  TBSliderView.h
//  Stock
//
//  Created by JustLee on 2020/9/25.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NSString *(^TBSliderValueFormatter)(double value);

@protocol TBSliderDelegate <NSObject>

@optional
- (void)customtSliderValueChanged:(UISlider *)sender;
- (void)customSliderEndChange:(UISlider *)sender;
- (void)customSliderBeginChange:(UISlider *)sender;

@end

@interface TBSliderView : UIView

@property (nonatomic, weak) id<TBSliderDelegate> delegate;

@property (nonatomic, assign) double value;

@property (nonatomic, assign) double maxValue;

@property (nonatomic, assign) double minValue;

- (void)setValue:(double)value animated:(BOOL)animated;

@property (nonatomic, copy) TBSliderValueFormatter valueFormatter;

@end
