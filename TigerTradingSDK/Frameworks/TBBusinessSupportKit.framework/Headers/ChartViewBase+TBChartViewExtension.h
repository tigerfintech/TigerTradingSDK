//
//  ChartView+TBChartViewExtension.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/5/16.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#define kLegendFormSize 6.0

@import ChartKLineView;

NS_ASSUME_NONNULL_BEGIN

@interface ChartViewBase (TBChartViewExtension)
- (void)legendEnabled:(BOOL)enabled;
@end

NS_ASSUME_NONNULL_END
