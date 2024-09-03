//
//  TBFuturesContractDescriptionModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFuturesContractDescriptionModel : JSONModel

@property (copy, nonatomic) NSString *productAlias;             // 合约别名描述
@property (copy, nonatomic) NSString *productType;              // 合约类型描述
@property (copy, nonatomic) NSString *productScale;             // 合约精度描述
@property (copy, nonatomic) NSString *productPriceIncrement;    // 合约最小变动单位描述
@property (copy, nonatomic) NSString *productTradingMonth;      // 合约交易所月份描述
@property (copy, nonatomic) NSString *productExchangeUrl;       // 合约交易所连接
@property (copy, nonatomic) NSString *productTradingTime;       // 合约交易时段描述
@property (copy, nonatomic) NSString *productWorth;             // 合约价值描述

@end

NS_ASSUME_NONNULL_END
