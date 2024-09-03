//
//  TBFuturesProductPriceConfigsModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBDecimal;

@interface TBFuturesProductPriceConfigsModel : JSONModel

@property (retain, nonatomic) TBDecimal *priceLowerLimit;          // 价格范围下限
@property (retain, nonatomic) TBDecimal *priceUpperLimit;          // 价格范围上限
@property (retain, nonatomic) TBDecimal *displayPriceIncrement;    // 客户端展示最小变动单位

@end

NS_ASSUME_NONNULL_END
