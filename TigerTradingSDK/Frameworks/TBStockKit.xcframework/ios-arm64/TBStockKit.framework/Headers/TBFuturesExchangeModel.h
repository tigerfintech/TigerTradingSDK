//
//  TBFuturesExchangeModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/4.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>


/*
 
 交易所对象
 
 */


NS_ASSUME_NONNULL_BEGIN

@class TBFuturesContractModel;

@interface TBFuturesExchangeModel : TBBaseModel

@property (copy, nonatomic) NSString *exchangeCode;     // 交易所code
@property (copy, nonatomic) NSString *exchangeId;       // 交易所id
@property (copy, nonatomic) NSString *name;             // 交易所英文名
@property (copy, nonatomic) NSString *abbreviation;     // 交易所简称
@property (copy, nonatomic) NSString *zoneId;           // 区域id
@property (copy, nonatomic) NSString *zone;             // 时区英文
@property (copy, nonatomic) NSString *zoneName;           // 时区名称
@property (copy, nonatomic) NSString *securityType;     // 交易所所属类型
@property (copy, nonatomic) NSString *status;           // 状态
@property (copy, nonatomic) NSString *code;             //  ？？？？？？
@property (assign, nonatomic) NSInteger weight;         // 权重


@property (copy, nonatomic) NSArray <TBFuturesContractModel *> *hots; // 交易所下热门列表

@end

NS_ASSUME_NONNULL_END
