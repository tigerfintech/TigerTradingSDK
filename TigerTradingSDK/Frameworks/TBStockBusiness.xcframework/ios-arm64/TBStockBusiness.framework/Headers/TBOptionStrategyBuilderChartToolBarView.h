//
//  TBOptionStrategyBuilderChartToolBarView.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBuilderChartToolBarView : UIView

@property (nonatomic, copy) NSString *delta;
@property (nonatomic, copy) NSString *gamma;
@property (nonatomic, copy) NSString *theta;
@property (nonatomic, copy) NSString *vega;

@end

NS_ASSUME_NONNULL_END
