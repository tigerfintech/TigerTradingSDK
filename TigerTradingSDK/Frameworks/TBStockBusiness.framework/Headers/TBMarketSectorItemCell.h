//
//  TBMarketSectorItemCell.h
//  Stock
//
//  Created by yangfan on 16/10/13.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TBCommonChartView;
#import <TBStockKit/TBFuturesContractModel.h>
#import "TBShadowUIConstant.h"
#import <TBUIKit/UIView+Shadow.h>

@interface TBMarketSectorItemCell : UICollectionViewCell

@property (nonatomic, strong) id             itemDetail;                    //展示内容数据

@property (nonatomic, copy) NSString     * market;                        //股指类型，区分美股或者A股，港股

@property (nonatomic, strong) UILabel      * titleLabel;                         //板块名称
@property (nonatomic, strong) UILabel      * priceLabel;                    //当前价格或者指数
@property (nonatomic, strong) UILabel      * changedLabel;                  //涨跌幅

@property (nonatomic, strong) UILabel      * countLabel;                    //今日股市分类板块总数

@property (nonatomic, strong) UILabel      * topStockNameLabel;                  //板块首位股票名称
@property (nonatomic, strong) UILabel      * topStockChangedLabel;          //板块首位股票涨跌幅

@property (nonatomic, strong) TBCommonChartView *trendView;

@property (nonatomic, assign) CGFloat superViewWidth;

+ (CGFloat)cellHeight;

+ (CGFloat)cellWidth;

@end

@interface TBMarketIndicesItemCell : TBMarketSectorItemCell

@end

@interface TBMarketCustomIndicesCell : TBMarketIndicesItemCell

@end

@interface TBMarketHotItemCell : TBMarketSectorItemCell

@end

@interface TBMarketHotIntustryItemCell : TBMarketHotItemCell

@end

@interface TBMarketETFItemCell : TBMarketSectorItemCell

@end

@interface TBMarketTodayItemCell : TBMarketSectorItemCell

@end

@interface TBMarketImportantIndicesItemCell : TBMarketSectorItemCell

@end

/// 港股 ETF专区, index ETF卡片样式cell
@interface TBQHKIndexETFCell : TBMarketSectorItemCell

@end
