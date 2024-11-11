//
//  TBDataVaneModel.h
//  Stock
//
//  Created by yangfan on 2017/9/5.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@protocol NSString;
@protocol TBDataVaneItemModel;

@interface TBDataVaneItemModel : JSONModel

@property (nonatomic, copy) NSString                * forecast;
@property (nonatomic, copy) NSString                * actual;
@property (nonatomic, copy) NSString                * changeRate;
@property (nonatomic, copy) NSString                * date;

@end

@interface TBDataVaneModel : JSONModel

@property (nonatomic, copy) NSString                  * name;
@property (nonatomic, copy) NSArray<NSString>       * header;

@property (nonatomic, copy) NSArray<TBDataVaneItemModel>        * items;

//以下属性只用于展示，不用于数据的初始化
@property (nonatomic, copy) NSArray                 * chartHighlight; //十字架处于的位置

@end
