//
//  TBCommonChartView.h
//  Stock
//
//  Created by luopengfei on 2018/6/21.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "TBStockLegendView.h"
#import "TBAxisValueFormatter.h"

@import ChartKLineView;
@class TBCombinedChartView;

/**
 绘制图表类型
 */
typedef NS_ENUM(NSUInteger, TBCommonChartType) {
    TBCommonChartTypeLine, // 线
    TBCommonChartTypeBar, // 柱
    TBCommonChartTypeScatter, // 散点图 ###未处理
    TBCommonChartTypeBubble, // 气泡图 ###未处理
};


/**
 图表绘制:
 目前支持：折线图、柱状图、散点图，以及三种图的组合形式
 */
@interface TBCommonChartView : UIView
@property (nonatomic, strong) CombinedChartData *chartData;
/**
 更新Chart数据源

 @param type 绘制类型
 @param dataSource 二维数组，每条数据为二维数组内element，可绘制多条线、多个柱状图、多个散点图
 @param xAxis X轴坐标
 */
- (void)updateCommonChart:(TBCommonChartType)type dataSource:(NSArray<NSArray<NSNumber*>*>*)dataSource xAxis:(NSArray<NSString*> *)xAxis;

/**
 更新组合图数据，支持多种类型图绘制

 @param dataSource 数据源 {<TBCommonChartType> : (NSArray<NSArray<NSNumber*>*>*)dataSource}
 @param xAxis x轴坐标
 */
- (void)updateCommonCombinedChart:(NSDictionary<NSNumber *, NSArray<NSArray<NSNumber*>*>*> *)dataSource xAxis:(NSArray<NSString*> *)xAxis;


/**
 是否绘制图例
 */
@property (nonatomic, assign, getter=isDrawLegendAbled) BOOL drawLegendAbled;

@property (nonatomic, assign) NSInteger xAxisLabelCount;

/**
 是否绘制Y轴坐标
 */
@property (nonatomic, assign, getter=isDrawYAxis) BOOL drawYAxis;
/**
 图例
 */
@property (nonatomic, readonly) TBStockLegendView *legendView;

/**
 是否需要补点，考虑数据只有一个的情况，
 1.柱状图补充五个空白的点
 2.折线图补充两个空白的点，并且绘制实心圆点做标注
 */
@property (nonatomic, assign, getter=isNeedFillPoint) BOOL needFillPoint;

/**
 补点的数量 只针对柱状图，默认5个
 */
@property (nonatomic, assign) NSInteger fillPointCount;

/**
 是否固定宽度
 */
@property (nonatomic, assign, getter=isFixedBarWidth) BOOL fixedBarWidth;

/**
 计算方法: 目前只针对单组数据 barWidth + barSpace(自适应) = 1
 exp: barWidth = 1,即柱子之间没有间隔，柱子真实宽度 = chart.ViewProtHanlder.width / maxEntryCountSet.entryCount
 */
@property (nonatomic, assign) double barWidth;

@property (nonatomic, assign) BOOL drawCirclesEnabled;

/**
 开放一个设置图标x轴最大数量属性，用于限制数据总是铺满图标的情况
 */
@property (nonatomic, assign) NSInteger xAxisMaxmum;

/**
 自定义无数据文案
 */
@property (nonatomic, copy) NSString *noDataText;

/**
 折线图是否绘制最大最小值
 */
@property (nonatomic, assign, getter = isDrawValueMaxMinOnly) BOOL drawValueMaxMinOnly;


@property (nonatomic, copy) NSArray<ChartLimitLine *> *limitLines;

@property (nonatomic, readonly) TBCombinedChartView *commonChartView;


/**
 线柱颜色
 */
@property (nonatomic, copy) NSArray *colors;


@property (nonatomic, copy) void (^commonChartViewSelectedIndex)(NSInteger index, CGPoint pt);
@property (nonatomic, copy) void (^commonChartViewDeselected)(void);


- (void)deselectedChart;

- (LineChartData *)p_updateLineChartData:(NSArray<NSArray<NSNumber *> *> *)dataSource;
- (BarChartData *)p_updateBarChartData:(NSArray<NSArray<NSNumber *> *> *)dataSource;
- (ScatterChartData *)p_updateScatterChartData:(NSArray<NSArray<NSNumber *> *> *)dataSource;
@end
