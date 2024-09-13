//
//  TBStockOptionPremiumDetailChartView.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/3.
//

#import <UIKit/UIKit.h>
#import "TBStockDetailOptionPremiumTypeEnum.h"

NS_ASSUME_NONNULL_BEGIN
 
@class TBRealTimeAssetChartView;

@interface TBStockOptionPremiumDetailChartView : UIView

@property (nonatomic, strong) TBRealTimeAssetChartView *chartView;

@property (nonatomic, assign) TBStockOptionPremiumDetailChartViewType type;

@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *displayDate;

@property (nonatomic, copy) NSString *displayTopHint;
@property (nonatomic, copy) NSString *displayBottomHint;

/// isLineUp 价格是否位于中线上方
- (void)updateMarkerPointAtIndex:(NSInteger)index y:(CGFloat)y isLineUp:(BOOL)isLineUp;

- (void)setMarkerHidden:(BOOL)isHidden;

@end

NS_ASSUME_NONNULL_END
