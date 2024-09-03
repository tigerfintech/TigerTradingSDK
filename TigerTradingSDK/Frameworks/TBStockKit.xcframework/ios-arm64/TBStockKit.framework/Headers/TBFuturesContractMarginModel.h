//
//  TBFuturesContractMarginModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>


/*
 
 合约的保证金
 
 */


NS_ASSUME_NONNULL_BEGIN


@class TBDecimal;

@interface TBFuturesContractMarginModel : TBBaseModel


@property (nonatomic, copy) NSString *contractCode;
@property (nonatomic, copy) NSString *contractId;   // 合约id，主要是在批量获取的时候有

@property (retain, nonatomic) TBDecimal *intradayInitialMargin;        // 日内初始保证金
@property (retain, nonatomic) TBDecimal *intradayMaintenanceMargin;    // 日内维持保证金
@property (retain, nonatomic) TBDecimal *overnightInitialMargin;       // 隔夜初始保证金
@property (retain, nonatomic) TBDecimal *overnightMaintenanceMargin;   // 隔夜维持保证金
@property (copy, nonatomic) NSString *discountStartTime;                // 优惠时段开始时间
@property (copy, nonatomic) NSString *discountEndTime;                  // 优惠时段结束时间

#pragma mark - helper
#pragma mark -

/**
 所有偏移中最大的偏移量
 */
@property (assign, nonatomic, readonly) NSInteger maxOffset;

@end

NS_ASSUME_NONNULL_END
