//
//  TBStockChartMarkerView.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/5/15.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBBaseKit/JSONModel.h>

typedef NS_ENUM(NSUInteger, TBStockChartMarkerType) {
    TBStockChartMarkerTypeSquare,
    TBStockChartMarkerTypeLine,
    TBStockChartMarkerTypeCircle,
};
NS_ASSUME_NONNULL_BEGIN
#define kMarkerCellHeight 20

@interface TBStockChartMarkerModel : JSONModel

- (instancetype)initWithLegendColor:(UIColor *)color title:(NSString *)title value:(NSString *)value;
- (instancetype)initWithLegendColor:(UIColor *)color title:(NSString *)title value:(NSString *)value valueColor:(UIColor *)valueColor;

- (instancetype)initWithLegendIcon:(UIImage *)iconImage title:(NSString *)title value:(NSString *)value;

- (instancetype)initWithLegendColor:(UIColor *)color title:(NSString *)title value:(NSString *)value markerType:(TBStockChartMarkerType)markerType;

@property (nonatomic, strong) UIColor *legendColor;
@property (nonatomic, strong) UIColor *valueColor;

@property (nonatomic, strong) UIImage *legendIcon;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *value;

@property (nonatomic, assign) TBStockChartMarkerType markerType;


@end


@interface TBStockChartMarkerView : UIView

@property (nonatomic, copy) NSArray<TBStockChartMarkerModel *> *markers;

@end

NS_ASSUME_NONNULL_END
