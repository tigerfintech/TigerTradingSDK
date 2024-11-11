//
//  TBOmnibusAnalysisPnlModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import "TBOmnibusAnalysisStockPnlItemModel.h"
#import "TBOmnibusAnalysisPnlProfitMarketMapModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAnalysisPnlDataModel : JSONModel

@property (nonatomic, strong) NSNumber *amount;
@property (nonatomic, strong) NSNumber *profitSum;
@property (nonatomic, strong) NSNumber *lossSum;
@property (nonatomic, strong) NSNumber *breakEven;
@property (nonatomic, strong) NSNumber *tradeAmount;

@property (nonatomic, copy) NSArray <TBOmnibusAnalysisStockPnlItemModel> *profitTop;
@property (nonatomic, copy) NSArray <TBOmnibusAnalysisStockPnlItemModel> *lossTop;

@property (nonatomic, strong) TBOmnibusAnalysisPnlProfitMarketMapModel *profitMarketMap;

@end

@interface TBOmnibusAnalysisPnlModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusAnalysisPnlDataModel *data;

@end

NS_ASSUME_NONNULL_END
