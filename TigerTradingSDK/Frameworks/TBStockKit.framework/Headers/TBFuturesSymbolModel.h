//
//  TBFuturesSymbolModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/10.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFuturesSymbolModel : TBBaseModel

@property (copy, nonatomic) NSString *symbolCode;     // 交易所code
@property (copy, nonatomic) NSString *exchangeId;       // 交易所id
@property (copy, nonatomic) NSString *name;             // 交易所英文名
@property (copy, nonatomic) NSString *symbolId;

@end

NS_ASSUME_NONNULL_END
