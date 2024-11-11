//
//  TBOmnibusAnalysisAssetItemAllocationModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAnalysisAssetItemAllocationModel : JSONModel

@property (nonatomic, copy) NSString *type;

@property (nonatomic, strong) NSNumber *value;                  // 资产值
@property (nonatomic, strong) NSNumber *unrealizedPnlByFifo;    // 未实现盈亏FIFO
@property (nonatomic, strong) NSNumber *unrealizedPnlByAverage; // 未实现盈亏平均
@property (nonatomic, strong) NSNumber *totalPositionPnl;       // 持仓盈亏
@property (nonatomic, strong) NSNumber *totalPnl;               // VAULT累计盈亏(从账本获取)

- (NSString *)typeDescForPortfolio;
- (NSString *)typeDesc;
- (UIColor *)typeColor;

+ (NSString *)typeDescForPortfolio:(NSString *)type;

- (NSNumber *)unrealizedPnl:(BOOL)averageCost;

@end

@protocol TBOmnibusAnalysisAssetItemAllocationModel;
@interface TBOmnibusAnalysisAssetAllocationModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusAnalysisAssetItemAllocationModel> *data;

@end

NS_ASSUME_NONNULL_END
