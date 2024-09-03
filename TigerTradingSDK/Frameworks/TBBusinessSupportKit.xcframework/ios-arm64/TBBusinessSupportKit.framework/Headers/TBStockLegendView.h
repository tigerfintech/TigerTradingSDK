//
//  TBStockLegendView.h
//  Stock
//
//  Created by luopengfei on 2018/3/21.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 绘制图例类型

 - TBStockLegendFormNone: 无
 - TBStockLegendFormSquare: 方
 - TBStockLegendFormCircle: 圆，根据业务需要，目前只实现了这一个
 - TBStockLegendFormLine: 线
 */
typedef NS_ENUM(NSUInteger, TBStockLegendForm) {
    TBStockLegendFormNone,
    TBStockLegendFormSquare,
    TBStockLegendFormCircle,
    TBStockLegendFormLine,
};

/**
 绘制图例方向

 - TBStockLegendOrientationHorizontal: 水平
 - TBStockLegendOrientationVertical: 竖直
 */
typedef NS_ENUM(NSUInteger, TBStockLegendOrientation) {
    TBStockLegendOrientationHorizontal,
    TBStockLegendOrientationVertical,
};

/**
 
 股票图例，charts内部图例支持不是太友好，这里重新定义
 
 */
@interface TBStockLegendView : UIView

@property (nonatomic, copy) NSArray *titles;
@property (nonatomic, copy) NSArray *colors;
@property (nonatomic, copy) NSArray *icons;
@property (nonatomic, copy) NSArray *forms;
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;

/**
 绘制图例类型
 */
@property (nonatomic, assign) TBStockLegendForm form;

/**
 绘制图例方向
 */
@property (nonatomic, assign) TBStockLegendOrientation orientation;

- (void)reloadData;

@end

