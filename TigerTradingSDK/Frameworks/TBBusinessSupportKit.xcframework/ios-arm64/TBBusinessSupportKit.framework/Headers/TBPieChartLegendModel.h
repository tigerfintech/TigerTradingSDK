//
//  TBPieChartLegendModel.h
//  Stock
//
//  Created by WCP on 2018/1/29.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
@protocol TBPieChartLegendModel;

@interface TBPieChartLegendModel : JSONModel

@property (nonatomic, strong) UIColor *dotColor;
@property (nonatomic, copy) NSString *dotName;
@property (nonatomic, copy) UIColor *dotNameColor;
@property (nonatomic, copy) NSString *dotSupplementDescription;
@property (nonatomic, strong) UIColor *dotSupplementColor;
@property (nonatomic, copy) NSString *dotDetailDescription;
@property (nonatomic, strong) UIColor *dotDetailColor;
@property (nonatomic, assign) BOOL englishNextLine;  //英文换行
@end
