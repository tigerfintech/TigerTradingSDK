//
//  TBStockDetailLiteHourView.h
//  Stock
//
//  Created by mashanli on 2024/4/13.
//  Copyright © 2024年 com.tigerbrokers. All rights reserved.
//

typedef NS_ENUM (NSInteger, TBStockDetailHourActionType){
    TBStockDetailHourActionTypeDefault,  //
    TBStockDetailHourActionTypeOpenAH, //AH展开
    TBStockDetailHourActionTypeCloseAH, //AH关闭
    TBStockDetailHourActionTypeOpenHour, //盘前盘后展开
    TBStockDetailHourActionTypeCloseHour, //盘前盘后关闭
    TBStockDetailHourActionTypeOpenOvernight, //夜盘展开
    TBStockDetailHourActionTypeCloseOvernight, //夜盘关闭
};

@interface TBStockDetailLiteHourView : UIView

@property (nonatomic, strong) UIImageView *hourTriangleView;
@property (nonatomic, strong) UILabel *hourChangeLabel;
@property (nonatomic, strong) UILabel *hourLabel;
@property (nonatomic, strong) UIImageView *hourImgView;

@end
