//
//  TBOmnibusAnalysisPnlAmericaExchangeModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAnalysisPnlAmericaExchangeModel : JSONModel

@property (nonatomic, copy) NSString *marketName;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, strong) NSNumber *pnl;
@property (nonatomic, strong) NSNumber *pnlPercentage;
@end

NS_ASSUME_NONNULL_END
