//
//  TBFuturesDefinetions.h
//  Stock
//
//  Created by 胡金友 on 2018/7/5.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#ifndef TBFuturesDefinetions_h
#define TBFuturesDefinetions_h


typedef NS_ENUM(NSUInteger, TBContractTradingState) {
    TBContractTradingStateInTrading,       // 交易中
    TBContractTradingStateInBidding,       // 竞价中
    TBContractTradingStateOutofTrading,    // 已经收盘，不可交易
    TBContractTradingStateInHoliday,       // 在节假日中
};

/*
 合约的状态，根据第一通知日和最后交易日来算出来的
 */
typedef NS_ENUM(NSUInteger, TBContractState) {
    TBContractStateNormal,         // 正常状态
    TBContractStateWillExpire,     // 将要过期
    TBContractStateBetweenExpireAndSoldOut,    // 在第一通知日之后，最后交易日前七天之前
    TBContractStateWillSoldOut,    // 将要下架
    TBContractStateHadSoldOut,     // 已经下架
};

/**
 合约的状态，根据后台的status字段得出
 
 - TBContractStatusOnline: 存在
 - TBContractStatusExpiry: 已下架
 - TBContractStatusDeleted: 已被删除
 */
typedef NS_ENUM(NSUInteger, TBContractStatus) {
    TBContractStatusUnknown    = 1 << 0,
    TBContractStatusOnline     = 1 << 1,
    TBContractStatusExpiry     = 1 << 2,
    TBContractStatusDeleted    = 1 << 3,
};

typedef NS_ENUM(NSUInteger, TBQuotesDisplayType) {
    TBQuotesDisplayTypeSimple,     // 普通的合约价格
    TBQuotesDisplayTypeInterest,   // 利率合约价格
};



#endif /* TBFuturesDefinetions_h */
