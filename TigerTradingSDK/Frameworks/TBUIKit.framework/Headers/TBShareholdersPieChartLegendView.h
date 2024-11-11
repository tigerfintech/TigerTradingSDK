//
//  TBShareholdersPieChartLegendView.h
//  Stock
//
//  Created by JustLee on 2019/3/13.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_ENUM(NSUInteger, TBLegendViewType) {
    TBLegendViewShareholdersPieChartType,    //!<
    TBLegendViewBullBearType,                //!<  认证牛熊概况
};
@class TBShareholdersPieChartLegendModel;

@interface TBShareholdersPieChartLegendCell : UITableViewCell

- (void)updateTBPieChartLegendCell:(TBShareholdersPieChartLegendModel *)model;

@end

@interface TBShareholdersPieChartLegendView : UIView

- (void)updatePieChartLegendView:(NSArray <TBShareholdersPieChartLegendModel *> *)data;
@end

@interface TBShareholdersPieChartLegendModel : NSObject

@property (nonatomic, strong) UIColor *legendColor;
@property (nonatomic, copy) NSString *legendTitle;
@property (nonatomic, strong) UIColor *legendTitleColor;
@property (nonatomic, strong) UIFont *legendTitleFont;
@property (nonatomic, copy) NSString *legendDescription;
@property (nonatomic, assign) TBLegendViewType legendViewType;
@end
