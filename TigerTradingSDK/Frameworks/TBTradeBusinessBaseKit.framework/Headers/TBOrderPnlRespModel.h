//
//  TBOrderPnlRespModel.h
//  TBTradeBusinessBaseKit
//
//  Created by dulijun on 2024/4/2.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBOrderPnlRespModel<NSObject>
@end

@interface TBOrderPnlRespModel : JSONModel

@property (nonatomic, strong, nullable) NSNumber <Optional> *realizedPnlPercent;             //平仓单FIFO已实现盈亏率
@property (nonatomic, strong, nullable) NSNumber <Optional> *realizedPnlByAveragePercent;    //平仓单AVG已实现盈亏率
@property (nonatomic, strong, nullable) NSNumber <Optional> *openRealizedPnlPercent;         //开仓单FIFO已实现盈亏率
@property (nonatomic, strong, nullable) NSNumber <Optional> *openUnrealizedPnlPercent;       //开仓单FIFO未实现盈亏率

@end

NS_ASSUME_NONNULL_END
