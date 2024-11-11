//
//  TBPlaceOrderContractInfoConstants.h
//  Stock
//
//  Created by 王昌阳 on 2021/7/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBOmnibusFractionShareTradeMode NS_STRING_ENUM;

FOUNDATION_EXTERN TBOmnibusFractionShareTradeMode const TBOmnibusFractionShareTradeModeINTERNAL;///< Omnibus模式碎股回收
FOUNDATION_EXTERN TBOmnibusFractionShareTradeMode const TBOmnibusFractionShareTradeModeSGXUSM;///< 新加坡碎股新增 IRESS 上手回收

//合约所属交易所
typedef NSString *TBOmnibusContractExchange NS_STRING_ENUM;
FOUNDATION_EXTERN TBOmnibusContractExchange const TBOmnibusContractExchangeGrey; ///< Grey 交易所
FOUNDATION_EXTERN TBOmnibusContractExchange const TBOmnibusContractExchangeExpert; ///< Expert 交易所

@interface TBPlaceOrderContractInfoConstants : NSObject

@end

NS_ASSUME_NONNULL_END
