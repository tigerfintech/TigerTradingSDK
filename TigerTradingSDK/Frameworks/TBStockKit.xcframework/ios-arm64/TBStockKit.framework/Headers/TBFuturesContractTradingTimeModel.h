//
//  TBFuturesContractTradingTimeModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>
#import "TBFuturesDefinetions.h"

/*
 
 合约交易时间段，因为期货的交易时间的碎片化，所以时间段是一段一段的
 
 */


NS_ASSUME_NONNULL_BEGIN

@interface TBFuturesContractTradingTimeModel : TBBaseModel

@property (copy, nonatomic) NSString *contractCode;
@property (copy, nonatomic) NSString *contractId;

@property (copy, nonatomic) NSString *holidayName;          // 假期英文名，股票端名称用这个
//@property (copy, nonatomic) NSString *holidayNameCN;        // 假期中文名
@property (assign, nonatomic) NSTimeInterval holidayBeginTime;     // 假期开始时间
@property (assign, nonatomic) NSTimeInterval holidayEndTime;       // 假期结束时间

@property (copy, nonatomic) NSArray <NSArray <NSNumber *> *> *currentTradingTime;  // 当前交易时段
@property (copy, nonatomic) NSArray <NSArray <NSNumber *> *> *currentBiddingTime;  // 当前竞价时段



// 辅助的计算方法，用于计算指定时间内合约的交易状态
// time 毫秒级时间，如果为0，则返回当前的时间的合约的交易状态
- (TBContractTradingState)tradingStateForTime:(NSTimeInterval)time;


@end

NS_ASSUME_NONNULL_END
