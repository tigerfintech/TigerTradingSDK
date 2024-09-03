//
//  TBStockSettingChoiceCellItem.h
//  Stock
//
//  Created by ChenXin on 16/12/10.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import "TBStockSettingBasicCellItem.h"

/// K线图样式枚举
typedef NS_ENUM(NSUInteger, TBStockKLineStyle) {
    TBStockKLineStyleEmpty,     // 空心蜡烛图
    TBStockKLineStyleSolid,     // 实心蜡烛图
    TBStockKLineStyleTick,      // 美国线
    TBStockKLineStyleLine,      // 折线图
};


@interface TBStockSettingChoiceCellItem : TBStockSettingBasicCellItem

@property (nonatomic, assign) BOOL upDown;
@property (nonatomic, assign)TBStockKLineStyle style;
@property (nonatomic, assign) BOOL dotStyle;    // 圆心选中

@property (nonatomic, assign) BOOL disableState; // 是否是不可用状态
@property (nonatomic, assign) BOOL isUserInteractionEnabledOnDisableState; // 不可以状态是否可交互

//允许外界赋值image
@property (nonatomic, copy) NSString *normalImageName;
@property (nonatomic, copy) NSString *selectedImageName;

@end

@interface TBStockSettingChoiceCell : TBStockSettingBasicCell

@property (nonatomic, strong) UIButton *choiceButton;

@end
