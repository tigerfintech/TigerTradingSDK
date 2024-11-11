//
//  TBPieChartLegendView.h
//  Stock
//
//  Created by WCP on 2018/1/29.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBPieChartLegendModel.h"
@interface TBPieChartLegendCell : UITableViewCell

- (void)updateTBPieChartLegendCell:(TBPieChartLegendModel *)model;

@end

@interface TBPieChartLegendView : UIView

@property(nonatomic, assign) double cellHeight;
- (void)updatePieChartLegendView:(NSArray <TBPieChartLegendModel *> *)data;
@end
