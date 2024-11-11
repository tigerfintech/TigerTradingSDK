//
//  TBStockHeatMapView.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/1.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBStockHeatMapModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockHeatMapView : UIView
@property (nonatomic, copy) NSArray<TBStockHeatMapItemModel> *heatMapModels;

@property (nonatomic, assign) BOOL showChangeRatio;
@property (nonatomic, assign, getter=isLegendEnable) BOOL legendEnable;

@property (nonatomic, assign, getter=isScaleEnable) BOOL scaleEnable;

@property (nonatomic, copy) NSString *market;



@end

NS_ASSUME_NONNULL_END
