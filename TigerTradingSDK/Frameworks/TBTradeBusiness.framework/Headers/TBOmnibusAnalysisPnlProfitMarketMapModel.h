//
//  TBOmnibusAnalysisPnlProfitMarketMapModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>
#import "TBOmnibusAnalysisPnlAmericaExchangeModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAnalysisPnlProfitMarketMapModel : JSONModel

@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *AMERICA_EXCHANGE;   //!< 美国期货
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *ASIA_EXCHANGE;      //!< 亚洲期货
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *US_STK;             //!< 美股正股
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *US_OPT;             //!< 美股期权
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *HK_OPT;             //!< 港股期权
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *HK_STK;             //!< 港股正股
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *AU_STK;             //!< 澳股正股
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *SI_STK;             //!< 新加坡股正股
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *CN_STK;             //!< 沪深正股
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *WAR_IOPT;           //!< 窝轮牛熊证
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *CC;                 //!< 数字货币
@property (nonatomic, strong) TBOmnibusAnalysisPnlAmericaExchangeModel *OTHER;              //!< 其他

@end

NS_ASSUME_NONNULL_END
