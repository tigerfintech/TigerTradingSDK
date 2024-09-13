//
//  TBOptionKLineTableViewCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/8/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBStockDetailBaseTableViewCell.h>

#import <TBUIKit/TBStockSettingChoiceCellItem.h>

@class TBKLineItem;
@class TBChartKLineView;
@class TBHKTenLevelDataView;
@class TBOptionDetailIVIndexModel;
@class TBChartKLineDataManager;
@class TBHKTenLevelDataView;

@import ChartKLineView;

@interface TBOptionKLineTableViewCell : TBStockDetailBaseTableViewCell

@property (nonatomic, strong) TBChartKLineView *chartKLineView;
@property (nonatomic, strong) TBHKTenLevelDataView *detailView;

//- (void)updateCellQuoteType;

@end

@interface TBOptionKLineTableViewCellItem : TBStockDetailBaseTableViewCellItem

/// 负责K线业务逻辑
@property (nonatomic, strong) TBChartKLineDataManager *chartDataManager;

@property (nonatomic, assign) TBLineType currentLineType;
@property (nonatomic, copy) NSString *dayType;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *combineSymbol;

@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, copy) NSArray <TBOptionDetailIVIndexModel *> *ivIndexArray;
@property (nonatomic, assign) BOOL zoomIVIndexScale;

- (void)updateChartWithData:(id)data;

#pragma mark - Temp

/// 周期枚举类型的集合, 由chartDataManager生成
@property (nonatomic, copy) NSArray *periodTypes;

/// 蜡烛图形态
@property (nonatomic, assign) TBStockKLineStyle lineStyle;

@end
